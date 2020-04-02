
//#############################################################################
//# Author: Wen Li
//# Date  : 3/31/2020
//# Description: route define
//##############################################################################

#ifndef _ROUTE_H_
#define _ROUTE_H_
#include "macro.h"
#include "vehicle.h"


using namespace std;


class Route
{
private:
	string m_RouteName;
    int m_NumVehicles;
    int m_NumBkVehicles;
	int m_NumStops;
	float m_TimeBtnStops;
	vector<Vehicle> m_Buses;

public:
	Route(string &RouteName, 
           int NumVehicles,
           int NumBkVehicles,
           int NumStops, 
           float TimeBtnStops, 
           vector<string> & Buses)
    {
        assert (Buses.size() != 0);
        
        m_RouteName     = RouteName;
        m_NumVehicles   = NumVehicles;
        m_NumBkVehicles = NumBkVehicles;
		m_NumStops      = NumStops;
		m_TimeBtnStops  = TimeBtnStops;

        //cout<<m_RouteName<<", "<<m_NumStops<<", "<<m_TimeBtnStops<<", (";
        for (vector<string>::iterator It = Buses.begin(); It != Buses.end(); It++)
        {
            m_Buses.push_back (Vehicle(*It));
            //cout<<*It<<" ";
        }
        //cout<<")"<<endl;

        /* the last bus is set to backup */
        m_Buses[m_Buses.size()-1].SetAttr (VEHICLE_ATTR_BACKUP);
    }

    ~Route() 
    {
        
    }

    inline vector<Vehicle>::iterator BusBegin ()
    {
        return m_Buses.begin();
    }

    inline vector<Vehicle>::iterator BusEnd ()
    {
        return m_Buses.end();
    }

    inline char* GetRouteName ()
    {
        return (char*)m_RouteName.c_str();
    }

    inline int GetStopNum ()
    {
        return m_NumStops;
    }

    inline float GetTimeBtStops ()
    {
        return m_TimeBtnStops;
    }

    inline Vehicle* AllotBus ()
    {
        for (vector<Vehicle>::iterator It = m_Buses.begin(); It != m_Buses.end(); It++)
        {
            Vehicle *Bus = &(*It);
            if (Bus->GetAttr () == VEHICLE_ATTR_BACKUP)
            {
                Bus->SetAttr (VEHICLE_ATTR_USE);
                return Bus;
            }
        }

        return NULL;
    }

    inline void ReleaseBus (Vehicle* Bus)
    {
        Bus->SetAttr (int VEHICLE_ATTR_BACKUP);

        return;
    }
};


#endif
