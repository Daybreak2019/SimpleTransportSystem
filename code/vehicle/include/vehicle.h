
//#############################################################################
//# Author: Wen Li
//# Date  : 3/31/2020
//# Description: class define for vehicle
//##############################################################################

#ifndef _VEHICLE_H_
#define _VEHICLE_H_
#include "macro.h"

using namespace std;

class Vehicle
{
private:
    string m_BusName;
    int m_Status;
    int m_BrkTime;
    int m_RoundNum;

    map<int, int> m_Stop2Times;
    
public:
    Vehicle(string &BusName)
    {
        m_BusName = BusName;
        m_Status  = VEHICLE_ST_IDLE;
        m_BrkTime = 0;
        m_RoundNum = 0;
    }

    ~Vehicle() 
    {
        
    }


private:



public:
    inline char* GetBusName ()
    {
        return (char*)m_BusName.c_str();
    }

    inline int GetBrkTime ()
    {
        return m_BrkTime;
    }

    inline void SetStatus (int Status)
    {
        m_Status = Status;
        if (Status == VEHICLE_ST_BRK)
        {
            /* record the breakdown time */
            m_BrkTime = time (0);
        }
        else if (Status == VEHICLE_ST_IDLE)
        {
            m_BrkTime = 0;
        }
    }

    inline int GetStatus ()
    {
        return m_Status;
    }

    inline int GetFillinRatio ()
    {
        return (random () %101);
    }

    inline void IncRoundNum ()
    {
        m_RoundNum++;
    }

    inline int GetRoundNum ()
    {
        return m_RoundNum;
    }

    inline void ResetRoundNum ()
    {
        m_RoundNum = 0;
    }

    inline void IncStopNum (int Stop)
    {
        if (m_Stop2Times.find (Stop) == m_Stop2Times.end())
        {
            m_Stop2Times[Stop] = 1;
        }
        else
        {
            m_Stop2Times[Stop]++;;
        }
        //cout<<m_BusName<<": Stop"<<Stop<<" "<<m_Stop2Times[Stop]<<" times\n";
    }

    inline int GetStopNum (int Stop)
    {
        if (m_Stop2Times.find (Stop) == m_Stop2Times.end())
        {
            return 0;
        }
        else
        {
            return m_Stop2Times[Stop];
        }
    }


};

#endif
