
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

    PositionPublisher *m_PosPublisher;
    BreakownPublisher *m_BrkPublisher;
    AccidentPublisher *m_AccPublisher;
    
public:
    PubThread(Vehicle *Bus, Route *Rt, int StartStop=0)
    {
        m_Vehicle = Bus;
		m_Route   = Rt;
        m_CurStop = StartStop;

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

    inline void RemoveBus ()
    {
        m_Route->ReleaseBus (m_Vehicle);
        m_Vehicle = NULL;
    }

    inline bool AddBus (string &BusName)
    {
        m_Vehicle = m_Route->AllotBus ();
        if (m_Vehicle == NULL)
        {
            return false;
        }
        
        return true;
    }

    inline string GetTime ()
    {
        char Buf[64];
        time_t CurTime = time(NULL);

        strftime(Buf, sizeof(Buf), "%m/%d/%Y %X", localtime(&CurTime));

        return string (Buf);
    }

    bool IsAccHappen ();
    int SendAccMsg (RealTimeInfo *RtInfo);
    
    bool IsBrkHappen ();
    int SendBrkMsg (RealTimeInfo *RtInfo);
    
    bool IsLightTrafic ();
    bool IsHeavyTrafic ();

    int SendPosMsg (RealTimeInfo *RtInfo);

public:
    
    void Start ();




};

#endif
