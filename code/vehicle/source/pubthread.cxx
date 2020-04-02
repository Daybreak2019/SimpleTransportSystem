//#############################################################################
//# Author: Wen Li
//# Date  : 3/31/2020
//# Description: simulate a vehicle runs on a route
//##############################################################################
#include "pubthread.h"

//PositionPublisher* PubThread::m_PosPublisher = new PositionPublisher (string(MESSAGE_TOPIC_POSITION));
//BreakownPublisher* PubThread::m_BrkPublisher = new BreakownPublisher (string(MESSAGE_TOPIC_BREAKDOWN));
//AccidentPublisher* PubThread::m_AccPublisher = new AccidentPublisher (string(MESSAGE_TOPIC_ACCIDENT));

bool PubThread::IsAccHappen ()
{
    return false;
}

int PubThread::SendAccMsg (RealTimeInfo *RtInfo)
{
    return RT_SUCCESS;
}


bool PubThread::IsBrkHappen ()
{
    return false;
}

int PubThread::SendBrkMsg (RealTimeInfo *RtInfo)
{
    return RT_SUCCESS;
}


bool PubThread::IsLightTrafic ()
{
    return false;
}

bool PubThread::IsHeavyTrafic ()
{
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
        if (IsLightTrafic ())
        {
            RtInfo.TimeBetweenStops  = m_Route->GetTimeBtStops () * (1 - 0.25);
            RtInfo.TrafficConditions = (char*)"Light traffic";
        }
        else if (IsHeavyTrafic ())
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

        DDS_Duration_t TransPeriod = {RtInfo.TimeBetweenStops, 0};
        NDDSUtility::sleep(TransPeriod);


        /*-------------------------------------------------*/
        /*        when reach a stop, simulate ACC/BRK      */
        /*-------------------------------------------------*/
        CurStop = (CurStop == StopNum)?(1):(CurStop+1);
        
        RtInfo.StopNumber  = CurStop;
        RtInfo.FillInRatio = m_Vehicle->GetFillinRatio ();
        
        if (IsBrkHappen ())
        {
            /* publish breakdown msg */
            SendBrkMsg (&RtInfo);
        }
        else if (IsAccHappen ())
        {
            /* publish accident msg */
            SendAccMsg (&RtInfo);
        }
        else
        {
            /* publish position msg */
            SendPosMsg (&RtInfo);
        }
    }
}



