
//#############################################################################
//# Author: Wen Li
//# Date  : 3/31/2020
//# Description: repesent a vehicle on a route
//##############################################################################

#ifndef _PUBTHREAD_H_
#define _PUBTHREAD_H_
#include "macro.h"
#include "route.h"
#include "vehicle.h"
#include "breakdownPublisher.h"
#include "positionPublisher.h"
#include "accidentPublisher.h"


using namespace std;

struct RealTimeInfo
{
   int StopNumber;
   float TimeBetweenStops;

   char* TrafficConditions;
   int FillInRatio;
};

class PubThread
{
private:
    Vehicle *m_Vehicle;    
	Route *m_Route;      
    int m_CurStop;
    
    int m_AccProb;
    int m_BrkProb;

    int m_HavProb;
    int m_LgtProb;

    PositionPublisher *m_PosPublisher;
    BreakownPublisher *m_BrkPublisher;
    AccidentPublisher *m_AccPublisher;
    
public:
    PubThread(Vehicle *Bus, Route *Rt, 
                float AccProb, float BrkProb,
                float HavProb, float LgtProb)
    {
        m_Vehicle = Bus;
		m_Route   = Rt;        
        m_CurStop = 0;
        
        if (AccProb > 0.0001 && AccProb <= 1.0)
        {
            m_AccProb = 1/AccProb;
        }
        else
        {
            m_AccProb = 1/0.1;
        }

        if (BrkProb > 0.0001 && BrkProb <= 1.0)
        {
            m_BrkProb = 1/BrkProb;
        }
        else
        {
            m_BrkProb = 1/0.05;
        }

        if (HavProb > 0.0001 && HavProb <= 1.0)
        {
            m_HavProb = 1/HavProb;
        }
        else
        {
            m_HavProb = 1/0.1;
        }

        if (LgtProb > 0.0001 && LgtProb <= 1.0)
        {
            m_LgtProb = 1/LgtProb;
        }
        else
        {
            m_LgtProb = 1/0.25;
        }

        m_PosPublisher = new PositionPublisher (string(MESSAGE_TOPIC_POSITION));
        assert (m_PosPublisher != NULL);

        m_BrkPublisher = new BreakownPublisher (string(MESSAGE_TOPIC_BREAKDOWN));
        assert (m_BrkPublisher != NULL);

        m_AccPublisher = new AccidentPublisher (string(MESSAGE_TOPIC_ACCIDENT));
        assert (m_AccPublisher != NULL);
    }

    ~PubThread() 
    {
        if (m_PosPublisher)
        {
            delete m_PosPublisher;
            m_PosPublisher = NULL;
        }

        if (m_BrkPublisher)
        {
            delete m_BrkPublisher;
            m_BrkPublisher = NULL;
        }

        if (m_AccPublisher)
        {
            delete m_AccPublisher;
            m_AccPublisher = NULL;
        }     
    }


private:

    inline string GetTime ()
    {
        char Buf[64];
        time_t CurTime = time(NULL);

        strftime(Buf, sizeof(Buf), "%m/%d/%Y %X", localtime(&CurTime));

        return string (Buf);
    }

    bool IsThreeRound ();

    bool IsAccHappen (int Stop);
    int SendAccMsg (RealTimeInfo *RtInfo);
    
    bool IsBrkHappen (int Stop);
    int SendBrkMsg (RealTimeInfo *RtInfo);
    
    bool IsLightTrafic (int Stop);
    bool IsHeavyTrafic (int Stop);

    Vehicle* AllotVehicle ();

    int SendPosMsg (RealTimeInfo *RtInfo);

public:
    
    void Start ();




};

#endif
