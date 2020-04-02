//#############################################################################
//# Author: Wen Li
//# Date  : 3/31/2020
//# Description: main entry of vehicle entity
//##############################################################################
#include "vehicle.h"
#include "property.h"
#include "route.h"

int main(int argc, char *argv[])
{
    Property Pro ("../pub.properties");
    Pro.Dump ();

    vector<Route> RtSet;
    for (T_RoutesMap::iterator It = Pro.Begin (); It != Pro.End (); It++)
    {
        RouteInfo *RtInfo = It->second;
        RtSet.push_back (Route (RtInfo->Name, Pro.GetNumVehicles (), 
                         Pro.GetNumBackupVehicles (), RtInfo->Stops, 
                         RtInfo->StopTimes, RtInfo->Buses));
    }

    return 0;
}

