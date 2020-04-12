//#############################################################################
//# Author: Wen Li
//# Date  : 4/01/2020
//# Description: main entry of passanger
//##############################################################################
#include "passanger.h"
#include "breakdownSubcriber.h"
#include "accidentSubcriber.h"
#include "positionSubcriber.h"

void *AccListenerThread (void *Arg)
{
    Passanger *P = (Passanger *)Arg;
    
    AccidentSubscriber AccSub (string(MESSAGE_TOPIC_ACCIDENT), new AccidentListener(P));

    while (1);  
}

void *PosListenerThread (void *Arg)
{
    Passanger *P = (Passanger *)Arg;

    PositionSubscriber PosSub (string(MESSAGE_TOPIC_POSITION), new PositionListener(P));

    while (1);  
}

void *BrkListenerThread (void *Arg)
{
   Passanger *P = (Passanger *)Arg;

   BreakownSubscriber BekSub (string(MESSAGE_TOPIC_BREAKDOWN), new BreakdownListener(P));

    while (1);  
}


// hard encode
bool Check (string Route, int StartStop,  int EndStop)
{
    if (Route != "Express1" && Route != "Express2")
    {
        return false;
    }

    if (Route == "Express1")
    {
        if (StartStop <= 0 || StartStop > 4 || EndStop <= 0 || EndStop > 4)
        {
            return false;
        }
    }

    if (Route == "Express2")
    {
        if (StartStop <= 0 || StartStop > 6 || EndStop <= 0 || EndStop > 6)
        {
            return false;
        }
    }

    return true;
}


int main(int argc, char *argv[])
{
    int Ret;
    pthread_t Tid;

    if (argc < 5)
    {
        printf ("passanger <passanger-name> <route> <start-stop> <end-stop> \r\n");
        printf ("range: route-Express1[1,4], route-Express2[1-6]");
        return 0;
    }

    string Name  = string(argv[1]);
    string Route = string(argv[2]);
    int Start = atoi(argv[3]);
    int End   = atoi(argv[4]);
    if (!Check (Route, Start, End))
    {
        printf ("passanger <passanger-name> <route> <start-stop> <end-stop> \r\n");
        printf ("range: route-Express1[1,4], route-Express2[1-6]");
        return 0;
    }
    

    Passanger P(Name, Route, Start, End);

    Ret = pthread_create(&Tid, NULL, AccListenerThread, &P);
    assert (Ret == 0);

    Ret = pthread_create(&Tid, NULL, PosListenerThread, &P);
    assert (Ret == 0);

    Ret = pthread_create(&Tid, NULL, BrkListenerThread, &P);
    assert (Ret == 0);

    while (1);

    return 0;
}

