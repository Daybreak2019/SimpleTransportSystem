
//#############################################################################
//# Author: Wen Li
//# Date  : 4/01/2020
//# Description: repesent a passanger
//##############################################################################

#ifndef _PASSANGER_H_
#define _PASSANGER_H_
#include "macro.h"
#include "positionSubcriber.h"
#include "accidentSubcriber.h"
#include "breakdownSubcriber.h"
#include "msglistener.h"


using namespace std;

class Passanger
{
private:
    string m_Name;
    string m_Route;
    string m_Bus;
    int    m_StartStop;
    int    m_EndStop;
    
    AccidentSubscriber *m_AccSubscriber;
    PositionSubscriber *m_PosSubscriber;
    BreakownSubscriber *m_BrkSubscriber;
    
public:
    Passanger(string Name, string Route, int StartStop,   int EndStop)
    {
        m_Name      = Name;
        m_Route     = Route;
        m_Bus       = "";
        m_StartStop = StartStop;
        m_EndStop   = EndStop;
    }

    ~Passanger() 
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

    inline string GetName ()
    {
        return m_Name;
    }
    
    inline int GetStartStop ()
    {
        return m_StartStop;
    }

    inline int GetEndStop ()
    {
        return m_EndStop;
    }
};

#endif
