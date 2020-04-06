//#############################################################################
//# Author: Wen Li
//# Date  : 3/31/2020
//# Description: main entry of vehicle entity
//##############################################################################
#include "property.h"
#include "pubthread.h"

static void SetQos (int MaxObjects)
{
    DDS_DomainParticipantFactoryQos factoryQoS;
    DDSTheParticipantFactory->get_qos(factoryQoS);
    
    cout<<"====>read resource_limits.max_objects_per_thread = "
        <<factoryQoS.resource_limits.max_objects_per_thread<<endl;
        
    factoryQoS.resource_limits.max_objects_per_thread = MaxObjects;
    DDSTheParticipantFactory->set_qos(factoryQoS);

    cout<<"====>write resource_limits.max_objects_per_thread = "
        <<factoryQoS.resource_limits.max_objects_per_thread<<endl;

    return;
}

inline string GetTime (time_t time)
{
    char Buf[64];
    strftime(Buf, sizeof(Buf), "%m/%d/%Y %X", localtime(&time));
    return string (Buf);
}

void *BusRepairthread (void* Arg)
{
    vector<Route> *RtSet = (vector<Route> *)Arg;

    while (1)
    {
        int VehDeadNum = 0;
        int VehNum = 0;
        for (vector<Route>::iterator It = RtSet->begin(); It != RtSet->end(); It++)
        {
            Route *R = &(*It);

            VehNum += R->GetBusNum ();
            for (vector<Vehicle>::iterator bIt = R->BusBegin (); bIt != R->BusEnd (); bIt++)
            {
                Vehicle *Bus = &(*bIt);
                
                if (Bus->GetStatus () == VEHICLE_ST_DEAD)
                {
                    VehDeadNum++;
                }
                
                if (Bus->GetStatus () != VEHICLE_ST_BRK)
                {
                    continue;
                }
                
                int CurTime = time (0);
                int BrkTime = Bus->GetBrkTime ();
                if (CurTime-BrkTime >= VEHICLE_BRK_TIME)
                {
                    R->SetBusStatus (Bus, VEHICLE_ST_IDLE);

                    printf ("%s:%s added to backup list. BrkTime:%s, FixedTime:%s\r\n",
                            R->GetRouteName (), Bus->GetBusName (),
                            GetTime ((time_t)BrkTime).c_str(), GetTime((time_t)CurTime).c_str());
                }
            }         
        }

        if (VehDeadNum == VehNum)
        {
            printf ("BusRepairthread exit....\r\n");
            break;
        }

        sleep (1);
    }

    return NULL;
}



void *PubthreadProc (void* Arg)
{
    PubThread *PubThr = (PubThread *)Arg;
    PubThr->Start ();

    return NULL;
}

void PubLauncher (vector<Route> &RtSet, float AccRate, float BrkRate, 
                     float HavRate, float LgtRate)
{
    int Ret;
    int BusIndex;
    pthread_t Tid;
    vector<PubThread *> PubThreadSet;

    cout<<"Lanching publishers...\r\n";
    for (vector<Route>::iterator It = RtSet.begin(); It != RtSet.end(); It++)
    {
        Route *R = &(*It);

        BusIndex = R->GetBusNum ();
        while (BusIndex > 0)
        {
            Vehicle *Bus = R->AllotBus ();
            if (Bus == NULL)
            {
                break;
            }
        
            PubThread *PubThr = new PubThread (Bus, R, AccRate, BrkRate, HavRate, LgtRate);
            assert (PubThr != NULL);
            
            Ret = pthread_create(&Tid, NULL, PubthreadProc, PubThr);
            assert (Ret == 0);

            PubThreadSet.push_back (PubThr);
            BusIndex--;
        }
    }

    //Ret = pthread_create(&Tid, NULL, BusRepairthread, );
    //assert (Ret == 0);  
    //while (1);

    cout<<"All buses have started. Waiting for them to terminate...\r\n";
    BusRepairthread (&RtSet);

    return;
}

void Help ()
{
    printf("************************************************\r\n");
    printf("*                help information              *\r\n");
    printf("************************************************\r\n"); 
    printf("-a: <Accident Probability[0-1]> \r\n");
    printf("-b  <Breakdown Probability[0-1]> \r\n");
    printf("-h: <Heavy Traffic Probability[0-1]> \r\n");
    printf("-l: <Light Traffic Probability[0-1]> \r\n");
    printf("************************************************\r\n\r\n");

    return;
}


int main(int argc, char *argv[])
{
    char ch;
    float BrkRate = 0;
    float AccRate = 0;
    float HavRate = 0;
    float LgtRate = 0;

    while((ch = getopt(argc, argv, "b:a:h:l:H")) != -1)
    {
        switch(ch)
        {
            case 'a':
            {
                AccRate = atof(optarg);
                break;
            }
            case 'b':
            {
                BrkRate = atof(optarg);
                break;
            }
            case 'h':
            {
                HavRate = atof(optarg);
                break;
            }
            case 'l':
            {
                LgtRate = atof(optarg);
                break;
            }
            case 'H':
            {
                Help ();
                return 0;
            }
            default:
            {
                break;
            }
        }
    }
    
    SetQos (4096);
    
    /* Rread pub.properties */
    Property Pro ("pub.properties");
    Pro.Dump ();

    /* Init Route information */
    vector<Route> RtSet;
    for (T_RoutesMap::iterator It = Pro.Begin (); It != Pro.End (); It++)
    {
        RouteInfo *RtInfo = It->second;
        RtSet.push_back (Route (RtInfo->Name, Pro.GetNumVehicles (), 
                                Pro.GetNumBackupVehicles (), RtInfo->Stops, 
                                RtInfo->StopTimes, RtInfo->Buses
                                )
                         );
    }


    /* start pubthread */
    PubLauncher (RtSet, AccRate, BrkRate, HavRate, LgtRate);

    return 0;
}

