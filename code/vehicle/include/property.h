
//#############################################################################
//# Author: Wen Li
//# Date  : 3/31/2020
//# Description: property read
//##############################################################################

#ifndef _PROPERTY_H_
#define _PROPERTY_H_
#include "macro.h"

using namespace std;


struct RouteInfo
{
    vector<string> Buses;
    string Name;
    int Stops;
    float StopTimes;
};

typedef map<string, RouteInfo*> T_RoutesMap;

class Property
{
private:
    string m_Path;
	
	int m_NumRoutes;
    int m_NumVehicles;
    int m_NumBackupVehicles;
    T_RoutesMap m_Routes;

public:
    Property(string Path="pub.properties")
    {
        m_Path = Path;
        Read ();
    }

    ~Property() 
    {
        for (T_RoutesMap::iterator it = m_Routes.begin(); it != m_Routes.end(); it++)
        {
            delete it->second;
        }       
    }

    inline map<string, RouteInfo*>::iterator Begin ()
    {
        return m_Routes.begin();
    }

    inline map<string, RouteInfo*>::iterator End ()
    {
        return m_Routes.end();
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

    inline void Dump ()
    {
        printf ("===================================================\r\n");
        printf ("=             pub.properties information          =\r\n");
        printf ("===================================================\r\n");
        printf ("numRoutes   = %d\r\n", m_NumRoutes);
        printf ("numVehicles = %d\r\n", m_NumVehicles);
        printf ("numInitialBackupVehicles = %d\r\n", m_NumBackupVehicles);

        int Index = 1;
        for (T_RoutesMap::iterator it = m_Routes.begin(); it != m_Routes.end(); it++)
        {
            
            RouteInfo* R = it->second;
            cout<<"Route"<<Index<<": (Name:"<<R->Name<<", Stops:"<<R->Stops<<", StopsTime:"\
                <<R->StopTimes<<", Buses:";
            for (vector<string>::iterator bit = R->Buses.begin(); bit != R->Buses.end(); bit++)
            {
                cout<<*bit<<", ";
            }
            cout<<endl;
        }
        printf ("===================================================\r\n\r\n");
        
    }

private:
    inline void ReadLine (char* Line)
    {
        bool KeyFlag = true;
        char Key[64] = {0};
        char Val[32] = {0};
        int KeyLen = 0;
        int ValLen = 0;

        while (*Line != 0)
        {
            switch (*Line)
            {
                case '#':
                {
                    break;
                }
                case '=':
                {
                    KeyFlag = false;
                    break;
                }
                default:
                {
                    if (KeyFlag)
                    {
                        Key[KeyLen++] = *Line;
                    }
                    else
                    {
                        Val[ValLen++] = *Line;
                    } 
            
                    break;
                }      
            }

            Line++;
        }

        if (Key[0] == 0 || Val[0] == 0)
        {
            return;
        }

        if (strcmp (Key, "numRoutes") == 0)
        {
            m_NumRoutes = atoi (Val);
        }
        else if (strcmp (Key, "numVehicles") == 0)
        {
            m_NumVehicles = atoi (Val);
        }
        else if (strcmp (Key, "numInitialBackupVehicles") == 0)
        {
            m_NumBackupVehicles = atoi (Val);
        }
        else if (strncmp (Key, "route", sizeof("route")-1) == 0 &&
                 strlen (Key) < (sizeof("route")+4))
        {
            RouteInfo* R = new RouteInfo();
            R->Name = string (Val);
            m_Routes[Key] = R;
        }
        else
        {
            for (T_RoutesMap::iterator it = m_Routes.begin(); it != m_Routes.end(); it++)
            {
                if (strstr (Key, it->first.c_str()) != NULL)
                {
                    RouteInfo* R = it->second;
                    if (strstr (Key, "numStops") != NULL)
                    {
                        R->Stops = atoi (Val);
                    }
                    else if (strstr (Key, "TimeBetweenStops") != NULL)
                    {
                        R->StopTimes = atof (Val);
                    }
                    else
                    {
                        R->Buses.push_back (Val);
                    }
                }
            }
        }
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
            "route2Vehicle4=Bus24",

            "NULL"
    	};

        int Index = 0;
        while (Default[Index] != "NULL")
        {
            
            ReadLine ((char*)Default[Index].c_str());

            Index++;
        }
        
    }

    inline void Read ()
    {
        char Buf[128];
        FILE *pF = fopen (m_Path.c_str(), "r");
        if (pF == NULL)
        {
            ReadDefault ();
            return;
        }

        while (!feof(pF))
        {
            memset (Buf, 0, sizeof(Buf));
            fgets (Buf, sizeof(Buf), pF);

            int Len = strlen(Buf);
            if (Len < 2)
            {
                continue;
            }
            
            if (Buf[Len-2] == '\r')
            {
                Buf[Len-2] = 0;
            }
            else if (Buf[Len-1] == '\n')
            {
                Buf[Len-1] = 0;
            }

            ReadLine (Buf);
        }

        fclose (pF);
    }


};

#endif
