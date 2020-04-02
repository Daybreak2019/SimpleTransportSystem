//#############################################################################
//# Author: Wen Li
//# Date  : 4/01/2020
//# Description: main entry of passanger
//##############################################################################
#include "passanger.h"


void *AccListenerThread (void *Arg)
{
    Passanger *P = (Passanger *)Arg;
    P->StartAccListen ();

    while (1);  
}

void *PosListenerThread (void *Arg)
{
    Passanger *P = (Passanger *)Arg;
    P->StartPosListen ();

    while (1);  
}

void *BrkListenerThread (void *Arg)
{
   Passanger *P = (Passanger *)Arg;
   P->StartBrkListen (); 

    while (1);  
}


int main(int argc, char *argv[])
{
    int Ret;
    pthread_t Tid;

    if (argc < 5)
    {
        printf ("passanger <passanger-name> <route> <start-stop> <end-stop> \r\n");
        return 0;
    }

    Passanger* P = new Passanger(string(argv[1]), string(argv[2]), atoi(argv[3]), atoi(argv[4]));
    assert (P != NULL);

    Ret = pthread_create(&Tid, NULL, AccListenerThread, P);
    assert (Ret == 0);

    Ret = pthread_create(&Tid, NULL, PosListenerThread, P);
    assert (Ret == 0);

    Ret = pthread_create(&Tid, NULL, BrkListenerThread, P);
    assert (Ret == 0);

    while (1);

    return 0;
}

