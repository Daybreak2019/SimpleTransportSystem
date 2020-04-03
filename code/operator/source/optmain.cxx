//#############################################################################
//# Author: Wen Li
//# Date  : 4/02/2020
//# Description: main entry of operator
//##############################################################################
#include "operator.h"


void *AccListenerThread (void *Arg)
{
    Operator *Opt = (Operator *)Arg;
    Opt->StartAccListen ();

    while (1);  
}

void *PosListenerThread (void *Arg)
{
    Operator *Opt = (Operator *)Arg;
    Opt->StartPosListen ();

    while (1);  
}

void *BrkListenerThread (void *Arg)
{
   Operator *Opt = (Operator *)Arg;
   Opt->StartBrkListen (); 

    while (1);  
}


int main(int argc, char *argv[])
{
    int Ret;
    pthread_t Tid;

    Operator *Opt = new Operator();
    assert (Opt != NULL);

    Ret = pthread_create(&Tid, NULL, AccListenerThread, Opt);
    assert (Ret == 0);

    Ret = pthread_create(&Tid, NULL, PosListenerThread, Opt);
    assert (Ret == 0);

    Ret = pthread_create(&Tid, NULL, BrkListenerThread, Opt);
    assert (Ret == 0);

    while (1);

    return 0;
}

