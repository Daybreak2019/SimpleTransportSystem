
//#############################################################################
//# Author: Wen Li
//# Date  : 4/02/2020
//# Description: repesent a operator
//##############################################################################

#ifndef _PASSANGER_H_
#define _PASSANGER_H_
#include "macro.h"
#include "positionSubcriber.h"
#include "accidentSubcriber.h"
#include "breakdownSubcriber.h"
#include "optlistener.h"


using namespace std;

class Operator
{
private:

    AccidentSubscriber *m_AccSubscriber;
    PositionSubscriber *m_PosSubscriber;
    BreakownSubscriber *m_BrkSubscriber;
    
public:
    Operator()
    {
        printf ("%-12s %-12s %-8s %-8s  %-8s %-8s %-16s %-8s %-16s\r\n",
                "MessageType", "Route", "Vehicle", "Traffic", "Stop#",
                "#Stops", "TimeBetweenStops", "Fill%", "TimeStamp");
    }

    ~Operator() 
    {
        if (m_AccSubscriber)
        {
            delete m_AccSubscriber;
        }

        if (m_PosSubscriber)
        {
            delete m_PosSubscriber;
        }

        if (m_BrkSubscriber)
        {
            delete m_BrkSubscriber;
        }    
    }
    
public:
    
    void StartAccListen ();
    void StartBrkListen ();
    void StartPosListen ();

    void PosMsgProc (Position *PosMsg);
    void AccMsgProc (Accident *AccMsg);
    void BrkMsgProc (Breakdown *BrkMsg);

};

#endif
