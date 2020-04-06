
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

    pthread_mutex_t m_Mutex;

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

        int Index = 0;
        for (vector<string>::iterator It = Buses.begin(); It != Buses.end(); It++)
        {
            m_Buses.push_back (Vehicle(*It));
            
            Index++;
            if (Index == m_NumVehicles+1)
            {
                printf ("Add vehicle%s to backup for route %s.\r\n", It->c_str(), m_RouteName.c_str());
            }
        }

        pthread_mutex_init(&m_Mutex, NULL);
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
    
    inline int GetBusNum ()
    {
        return m_NumVehicles;
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

    inline void SetBusStatus (Vehicle *Bus, int Status)
    {
        pthread_mutex_lock(&m_Mutex);
        for (vector<Vehicle>::iterator It = m_Buses.begin(); It != m_Buses.end(); It++)
        {
            Vehicle * CurBus= &(*It);
            if (CurBus == Bus)
            {
                CurBus->SetStatus (Status);
                //printf ("====> set %s status %d \r\n", CurBus->GetBusName (), Status);
                break;
            }
        }
        pthread_mutex_unlock(&m_Mutex);

        return;
    }

    inline Vehicle* AllotBus ()
    {
        Vehicle *AltBus = NULL;
        
        pthread_mutex_lock(&m_Mutex);
        for (vector<Vehicle>::iterator It = m_Buses.begin(); It != m_Buses.end(); It++)
        {
            Vehicle *Bus = &(*It);
            if (Bus->GetStatus () == VEHICLE_ST_IDLE)
            {
                Bus->SetStatus (VEHICLE_ST_USE);
                AltBus = Bus;
                break;
            }
        }
        pthread_mutex_unlock(&m_Mutex);

        return AltBus;
    }
};


#endif
