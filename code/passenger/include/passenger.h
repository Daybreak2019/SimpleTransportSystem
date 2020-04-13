
//#############################################################################
//# Author: Wen Li
//# Date  : 4/01/2020
//# Description: repesent a passanger
//##############################################################################

#ifndef _PASSENGER_H_
#define _PASSENGER_H_
#include "application.h"

using namespace std;

class Passenger:public AppSubscriber
{
private:
    string m_Name;
    string m_Route;
    string m_Bus;
    int    m_StartStop;
    int    m_EndStop;
    int    m_NumStop;
    
public:
    Passenger(string Name, string Route, int StartStop,   int EndStop)
    {
        m_Name      = Name;
        m_Route     = Route;
        m_Bus       = "";
        m_StartStop = StartStop;
        m_EndStop   = EndStop;

        cout<<"Waiting for the bus...\r\n";
    }

    ~Passenger() 
    {
  
    }
    
public:
    
    void PosMsgProc (Position *PosMsg);
    void AccMsgProc (Accident *PosMsg);
    void BrkMsgProc (Breakdown *PosMsg);


private:
    inline bool IsWantedRoute (string CurRoute)
    {
        return (bool)(m_Route == CurRoute);
    }

    
    inline bool IsBoaredBus (string CurBus)
    {
        return (bool)(m_Bus == CurBus);
    }

    inline string LeftStop (int CurStop)
    {
        char LeftS[32];
        
        int Left = ((m_EndStop + m_NumStop) - CurStop)%m_NumStop;
        if (Left > 1)
        {
            sprintf (LeftS, "%d stops left", Left);
        }
        else
        {
            sprintf (LeftS, "%d stop left", Left);
        }

        return string(LeftS);
    }
};

#endif
