
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
	string m_Route;
    int m_CurStop;
    int m_Attr;
    
public:
    Vehicle(string &BusName, string &Route)
    {
        m_BusName = BusName;
		m_Route   = Route;
        m_CurStop = 0;
        m_Attr    = VEHICLE_NORMAL;
    }

    ~Vehicle() 
    {
        
    }


private:



public:
    inline void SetAttr (int Attr)
    {
        assert (Attr == VEHICLE_NORMAL || Attr == VEHICLE_BACKUP);
        m_Attr = Attr;
    }
    
    void Start ();




};

#endif
