
//#############################################################################
//# Author: Wen Li
//# Date  : 4/01/2020
//# Description: class define for simulator for ACC/BRK, LIGHT/WEIGHT TRAFFIC
//##############################################################################

#ifndef _SIMULATOR_H_
#define _SIMULATOR_H_
#include "macro.h"
#include "route.h"


using namespace std;

class Simulator
{
private:
    vector<Route> *m_RouteSet;

    
public:
    Vehicle(vector<Route> *RouteSet)
    {
        m_RouteSet = RouteSet;
    }

    ~Vehicle() 
    {
        
    }


private:

    inline void Init ()
    {
    }

public:
    inline void SetAttr (int Attr)
    {
        assert (Attr == VEHICLE_NORMAL || Attr == VEHICLE_BACKUP);
        m_Attr = Attr;
    }

    inline int GetAttr ()
    {
        return m_Attr;
    }

    inline void SetStatus (int Status)
    {
        m_Status = Status;
    }

    inline int GetStatus ()
    {
        return m_Status;
    }

    inline int GetFillinRatio ()
    {
        return (random () %101);
    }


};

#endif
