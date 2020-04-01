
//#############################################################################
//# Author: Wen Li
//# Date  : 3/31/2020
//# Description: property read
//##############################################################################

#ifndef _PROPERTY_H_
#define _PROPERTY_H_
#include "macro.h"

using namespace std;

class Property
{
private:
    string m_Path;
	
	int m_NumRoutes;
    int m_NumVehicles;
    int m_NumBackupVehicles;

public:
    Property(string Path="pub.properties")
    {
        m_Path = Path;
    }

    ~Property() 
    {
        
    }

    inline int GetNumRoutes ()
    {
        return m_NumRoutes;
    }

    inline int GetNumVehicles ()
    {
        return m_NumVehicles;
    }

    inline int GetNumBackupVehicles ()
    {
        return m_NumBackupVehicles;
    }

    inline void ReadDefault ()
    {
        string Default[] = 
    	{
    		"numRoutes=2",
            "numVehicles=3",
            "numInitialBackupVehicles=1",
            
            "route1=Express1",
            "route2=Express2",

            "route1numStops=4",
            "route1TimeBetweenStops=2",
            "route1Vehicle1=Bus11",
            "route1Vehicle2=Bus12",
            "route1Vehicle3=Bus13",
            "route1Vehicle4=Bus14",

            "route2numStops=6",
            "route2TimeBetweenStops=3",
            "route2Vehicle1=Bus21",
            "route2Vehicle2=Bus22",
            "route2Vehicle3=Bus23",
            "route2Vehicle4=Bus24"
    	};
        
    }

    inline void Read ()
    {
        
        FILE *pF = fopen (m_Path.c_str(), "r");
        if (pF == NULL)
        {
            ReadDefault ();
            return;
        }

        while (!feof(pF))
        {
        }
    }


};

#endif
