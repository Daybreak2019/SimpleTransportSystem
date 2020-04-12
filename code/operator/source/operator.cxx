//#############################################################################
//# Author: Wen Li
//# Date  : 4/02/2020
//# Description: simulate a operator
//##############################################################################
#include "operator.h"


/*"MessageType", "Route", "Vehicle", "Traffic", "Stop#","#Stops", "TimeBetweenStops", "Fill%", "TimeStamp"); */
void Operator::PosMsgProc (Position *PosMsg)
{
    printf ("%-12s %-12s %-8s %-8s  %-8d %-8d %-16.2f %-8d %-16s\r\n",
            "Position",
            PosMsg->route, PosMsg->vehicle, PosMsg->trafficConditions, PosMsg->stopNumber,
            PosMsg->numStops, PosMsg->timeBetweenStops, PosMsg->fillInRatio, PosMsg->timestamp);
    return;
}


void Operator::AccMsgProc (Accident *AccMsg)
{
    printf ("%-12s %-12s %-8s %-8s  %-8d %-8s %-16s %-8s %-16s\r\n",
            "Accident",
            AccMsg->route, AccMsg->vehicle, " ", AccMsg->stopNumber,
            " ", " ", " ", AccMsg->timestamp);
    
    return;
}

void Operator::BrkMsgProc (Breakdown *BrkMsg)
{
    printf ("%-12s %-12s %-8s %-8s  %-8d %-8s %-16s %-8s %-16s\r\n",
            "Breakdown",
            BrkMsg->route, BrkMsg->vehicle, " ", BrkMsg->stopNumber,
            " ", " ", " ", BrkMsg->timestamp);
    
    return;
}


