
//#############################################################################
//# Author: Wen Li
//# Date  : 4/02/2020
//# Description: repesent a operator
//##############################################################################

#ifndef _PASSANGER_H_
#define _PASSANGER_H_
#include "application.h"


using namespace std;

class Operator:public Application
{   
public:
    Operator()
    {
        printf ("%-12s %-12s %-8s %-8s  %-8s %-8s %-16s %-8s %-16s\r\n",
                "MessageType", "Route", "Vehicle", "Traffic", "Stop#",
                "#Stops", "TimeBetweenStops", "Fill%", "TimeStamp");
    }

    ~Operator() 
    {
    
    }
    
public:

    void PosMsgProc (Position *PosMsg);
    void AccMsgProc (Accident *AccMsg);
    void BrkMsgProc (Breakdown *BrkMsg);

};

#endif
