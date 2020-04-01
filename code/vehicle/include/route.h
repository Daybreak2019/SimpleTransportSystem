
//#############################################################################
//# Author: Wen Li
//# Date  : 3/31/2020
//# Description: route define
//##############################################################################

#ifndef _ROUTE_H_
#define _ROUTE_H_
#include "macro.h"

using namespace std;

class Route
{
private:
	string m_RouteName;
	int m_NumStops;
	float m_TimeBtnStops;
	set<string> m_Buses;

public：
	Route(string &RouteName, int NumStops, float TimeBtnStops)
    {
        m_RouteName = RouteName;
		m_NumStops  = NumStops;
		m_TimeBtnStops = TimeBtnStops;
    }

    ~Route() 
    {
        
    }
	
	inline void AddBus (string Bus)
	{
		m_Buses.insert (Bus);
	}
	
	inline void RemoveBus (string Bus)
	{
		m_Buses.earse (Bus);
	}
};


#endif
