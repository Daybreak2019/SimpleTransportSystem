//#############################################################################
//# Author: Wen Li
//# Date  : 4/02/2020
//# Description: main entry of operator
//##############################################################################
#include "operator.h"
#include "breakdownSubcriber.h"
#include "accidentSubcriber.h"
#include "positionSubcriber.h"


void *AccListenerThread (void *Arg)
{
    Operator *Opt = (Operator *)Arg;
    
    AccidentSubscriber AccSub(string(MESSAGE_TOPIC_ACCIDENT), new AccidentListener(Opt));

    while (1);  
}

void *PosListenerThread (void *Arg)
{
    Operator *Opt = (Operator *)Arg;

    PositionSubscriber PosSub (string(MESSAGE_TOPIC_POSITION), new PositionListener(Opt));

    while (1);  
}

void *BrkListenerThread (void *Arg)
{
   Operator *Opt = (Operator *)Arg;

   BreakownSubscriber BrkSub(string(MESSAGE_TOPIC_BREAKDOWN), new BreakdownListener(Opt));

    while (1);  
}


int main(int argc, char *argv[])
{
    int Ret;
    pthread_t Tid;

    Operator Opt;

    Ret = pthread_create(&Tid, NULL, AccListenerThread, &Opt);
    assert (Ret == 0);

    Ret = pthread_create(&Tid, NULL, PosListenerThread, &Opt);
    assert (Ret == 0);

    Ret = pthread_create(&Tid, NULL, BrkListenerThread, &Opt);
    assert (Ret == 0);

    while (1);

    return 0;
}

