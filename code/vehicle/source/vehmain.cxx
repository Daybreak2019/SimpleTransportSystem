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


void *PubthreadProc (void* Arg)
{
    PubThread *PubThr = (PubThread *)Arg;
    PubThr->Start ();

    return NULL;
}

void PubLauncher (vector<Route> &RtSet)
{
    int Ret;
    pthread_t Tid;
    vector<PubThread *> PubThreadSet;

    for (vector<Route>::iterator It = RtSet.begin(); It != RtSet.end(); It++)
    {
        Route *R = &(*It);

        for (vector<Vehicle>::iterator bIt = R->BusBegin (); bIt != R->BusEnd (); bIt++)
        {
            Vehicle *Bus = &(*bIt);
            if (Bus->GetAttr () == VEHICLE_ATTR_BACKUP)
            {
                continue;
            }

            cout<<R->GetRouteName ()<<", "<<Bus->GetBusName ()<<endl;
            
            PubThread *PubThr = new PubThread (Bus, R);
            assert (PubThr != NULL);
            
            Ret = pthread_create(&Tid, NULL, PubthreadProc, PubThr);
            assert (Ret == 0);

            PubThreadSet.push_back (PubThr);
        }
    }
    
    while (1);
}

int main(int argc, char *argv[])
{
    SetQos (4096);
    
    /* Rread pub.properties */
    Property Pro ("../pub.properties");
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
    PubLauncher (RtSet);

    return 0;
}

