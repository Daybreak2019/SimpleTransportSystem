//#############################################################################
//# Author: Wen Li
//# Date  : 3/31/2020
//# Description: simulate a vehicle runs on a route
//##############################################################################
#include "pubthread.h"

bool PubThread::IsThreeRound ()
{
    int RoundNum = m_Vehicle->GetRoundNum ();
    if (RoundNum == 0 || RoundNum%3)
    {
        return false;
    }

    return true;
}


bool PubThread::IsAccHappen (int Stop)
{
    int VehRoundTimes = m_Vehicle->GetStopNum (Stop);
    if (VehRoundTimes != 0 && !(VehRoundTimes%m_AccProb))
    {
        return true;
    }
    
    return false;
}

int PubThread::SendAccMsg (RealTimeInfo *RtInfo)
{
    int Ret;

    Ret = m_AccPublisher->PublishMsg ((char*)GetTime ().c_str(), m_Route->GetRouteName(),
                                      m_Vehicle->GetBusName (), RtInfo->StopNumber);
    return Ret;
}


bool PubThread::IsBrkHappen (int Stop)
{
    int VehRoundTimes = m_Vehicle->GetStopNum (Stop);

    if (VehRoundTimes != 0 && !(VehRoundTimes%m_BrkProb))
    {
        return true;
    }
    
    return false;
}

int PubThread::SendBrkMsg (RealTimeInfo *RtInfo)
{
    int Ret;

    Ret = m_BrkPublisher->PublishMsg ((char*)GetTime ().c_str(), m_Route->GetRouteName(),
                                      m_Vehicle->GetBusName (), RtInfo->StopNumber);
    return Ret;
}


bool PubThread::IsLightTrafic (int Stop)
{
    int VehRoundTimes = m_Vehicle->GetStopNum (Stop);
    
    if (VehRoundTimes != 0 && !(VehRoundTimes%m_LgtProb))
    {
        return true;
    }
    
    return false;
}

bool PubThread::IsHeavyTrafic (int Stop)
{
    int VehRoundTimes = m_Vehicle->GetStopNum (Stop);

    //printf ("[%s]IsHeavyTrafic: m_HavProb = %d, VehRoundTimes = %d\r\n", 
    //        m_Vehicle->GetBusName (), m_HavProb, VehRoundTimes);
    if (VehRoundTimes != 0 && !(VehRoundTimes%m_HavProb))
    {
        return true;
    }
    
    return false;
}


int PubThread::SendPosMsg (RealTimeInfo *RtInfo)
{
    int Ret;

    Ret = m_PosPublisher->PublishMsg ((char*)GetTime ().c_str(), m_Route->GetRouteName(), m_Vehicle->GetBusName (), 
                                      RtInfo->TrafficConditions, RtInfo->FillInRatio, RtInfo->StopNumber,
                                      m_Route->GetStopNum (), RtInfo->TimeBetweenStops);
    return Ret;
}

Vehicle* PubThread::AllotVehicle ()
{
    Vehicle *NewBus;
    while (!(NewBus = m_Route->AllotBus ()))
    {
        DDS_Duration_t TransPeriod = {1, 0};
        NDDSUtility::sleep(TransPeriod);
    }

    return NewBus;
}


void PubThread::Start ()
{
    int CurStop = 1;
    int StopNum = m_Route->GetStopNum ();   
    float TimeBtStops = m_Route->GetTimeBtStops ();
    RealTimeInfo RtInfo;    

    while (CurStop <= StopNum)
    {  
        /*-------------------------------------------------*/
        /*   Between stops, simulate Light/Heavy traffic   */
        /*-------------------------------------------------*/
        if (IsLightTrafic (CurStop))
        {
            RtInfo.TimeBetweenStops  = m_Route->GetTimeBtStops () * (1 - 0.25);
            RtInfo.TrafficConditions = (char*)"Light traffic";
        }
        else if (IsHeavyTrafic (CurStop))
        {
            RtInfo.TimeBetweenStops = m_Route->GetTimeBtStops () * (1 + 0.5);
            RtInfo.TrafficConditions = (char*)"Heavy traffic";
        }
        else
        {
            /* Normal time: Time between stops */
            RtInfo.TimeBetweenStops = m_Route->GetTimeBtStops ();
            RtInfo.TrafficConditions = (char*)"Normal traffic";
        }

        int Second = (int)RtInfo.TimeBetweenStops;
        int NanSecond = (RtInfo.TimeBetweenStops-Second) * SEC_TO_NSEC;
        DDS_Duration_t TransPeriod = {Second, NanSecond};
        NDDSUtility::sleep(TransPeriod);


        /*-------------------------------------------------*/
        /*        when reach a stop, simulate ACC/BRK      */
        /*-------------------------------------------------*/
        if (CurStop == StopNum)
        {
            /* move to the first stop */
            CurStop = 1;

            /* increase the round number*/
            m_Vehicle->IncRoundNum ();
        }
        else
        {
            CurStop += 1;
        }
        m_Vehicle->IncStopNum (CurStop);
        
        
        RtInfo.StopNumber  = CurStop;
        RtInfo.FillInRatio = m_Vehicle->GetFillinRatio ();
        
        if (IsBrkHappen (CurStop))
        {
            /* publish breakdown msg */
            SendBrkMsg (&RtInfo);

            /* remove the bus from the route */
            m_Route->SetBusStatus (m_Vehicle, VEHICLE_ST_BRK);

            /* wait for 15 second, and */
            DDS_Duration_t TransPeriod = {15, 0};
            NDDSUtility::sleep(TransPeriod);

            /* allot fail, loop waiting */
            Vehicle *NewBus = AllotVehicle ();
            printf ("===> %s breakdown on %s, changing %s to %s on %s \r\n",
                    m_Vehicle->GetBusName (), m_Route->GetRouteName (),
                    m_Vehicle->GetBusName (), NewBus->GetBusName (), m_Route->GetRouteName ());
            m_Vehicle = NewBus;
        }
        else if (IsAccHappen (CurStop))
        {
            m_Route->SetBusStatus (m_Vehicle, VEHICLE_ST_ACC);
            
            /* publish accident msg */
            SendAccMsg (&RtInfo);

            /* wait for 10 second to fix */
            DDS_Duration_t TransPeriod = {10, 0};
            NDDSUtility::sleep(TransPeriod);
            m_Route->SetBusStatus (m_Vehicle, VEHICLE_ST_USE);
        }
        else if (IsThreeRound ())
        {
            /* allot a new bus then remove current bus from the route */
            Vehicle *NewBus = AllotVehicle ();

            m_Vehicle->ResetRoundNum ();
            m_Route->SetBusStatus (m_Vehicle, VEHICLE_ST_IDLE);
            printf ("===> %s 3 round on %s, changing %s to %s on %s \r\n",
                    m_Vehicle->GetBusName (), m_Route->GetRouteName (),
                    m_Vehicle->GetBusName (), NewBus->GetBusName (), m_Route->GetRouteName ());
            
            m_Vehicle = NewBus;            
        }

        /* publish position msg */
        SendPosMsg (&RtInfo);
    }
}



