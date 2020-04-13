//#############################################################################
//# Author: Wen Li
//# Date  : 4/01/2020
//# Description: simulate a passanger
//##############################################################################
#include "passenger.h"


void Passenger::PosMsgProc (Position *PosMsg)
{
    /* 1. check the route expected */
    if (!IsWantedRoute (string(PosMsg->route)))
    {
        return;
    }

    /* 2. right route, check if the passanger is on the bus */
    if (m_Bus == "")
    {
        if (m_StartStop == m_EndStop && m_EndStop == PosMsg->stopNumber)
        {
            /* the bus breakdown at the end stop */
            printf ("%s arriving at destination by %s at %s\r\n", 
                    m_Name.c_str(), PosMsg->vehicle, PosMsg->timestamp);
            /* exit */
            exit (0);
        }
        else if (m_StartStop == PosMsg->stopNumber)
        {
            m_Bus = string(PosMsg->vehicle);
            m_NumStop = PosMsg->numStops;
            
            printf ("%s getting on %s at stop%d, at %s, %s, %s\r\n", 
                    m_Name.c_str(), PosMsg->vehicle, PosMsg->stopNumber,
                    PosMsg->timestamp, PosMsg->trafficConditions, LeftStop(PosMsg->stopNumber).c_str());
        }
        else
        {
            printf ("......%s arriving at stop #%d, at %s, %s\r\n", 
                    PosMsg->vehicle, PosMsg->stopNumber,
                    PosMsg->timestamp, PosMsg->trafficConditions);
        }
    }
    else
    {
        /* on a bus, only receive the message with the bus */
        if (!IsBoaredBus(string(PosMsg->vehicle)))
        {
            return;
        }

        /* the same bus, check if arriving at dst stop */
        if (m_EndStop != PosMsg->stopNumber)
        {
            printf ("%s on %s arriving at stop #%d, at %s, %s, %s\r\n", 
                    m_Name.c_str(), PosMsg->vehicle, PosMsg->stopNumber,
                    PosMsg->timestamp, PosMsg->trafficConditions, LeftStop(PosMsg->stopNumber).c_str());
        }
        else
        {
            printf ("%s arriving at destination by %s at %s\r\n", 
                    m_Name.c_str(), PosMsg->vehicle, PosMsg->timestamp);
            /* exit */
            exit (0);
        }
    }

    return;
}


void Passenger::AccMsgProc (Accident *AccMsg)
{
    /* 1. check the route expected */
    if (!IsWantedRoute (string(AccMsg->route)))
    {
        return;
    }
    
    if (m_Bus == "")
    {
        printf ("......%s arriving at stop #%d, at %s, accident.\r\n", 
                AccMsg->vehicle, AccMsg->stopNumber, AccMsg->timestamp);
    }
    else
    {
        /* on a bus, only receive the message with the bus */
        if (!IsBoaredBus(string(AccMsg->vehicle)))
        {
            return;
        }

        printf ("%s on %s arriving at stop #%d, at %s, accident, %s\r\n", 
                m_Name.c_str(), AccMsg->vehicle, 
                AccMsg->stopNumber, AccMsg->timestamp, LeftStop(AccMsg->stopNumber).c_str());
    }
    
    return;
}

void Passenger::BrkMsgProc (Breakdown *BrkMsg)
{
    /* 1. check the route expected */
    if (!IsWantedRoute (string(BrkMsg->route)))
    {
        return;
    }

    if (m_Bus == "")
    {
        printf ("......%s arriving at stop #%d, at %s, accident.\r\n", 
                BrkMsg->vehicle, BrkMsg->stopNumber, BrkMsg->timestamp);
    }
    else
    {
        /* on a bus, only receive the message with the bus */
        if (!IsBoaredBus(string(BrkMsg->vehicle)))
        {
            return;
        }

        /* set the bus invalid and change the startstop */
        m_Bus = "";
        m_StartStop = BrkMsg->stopNumber;

        printf ("%s on %s arriving at stop #%d, at %s, breakdown, %s\r\n", 
                m_Name.c_str(), BrkMsg->vehicle, 
                BrkMsg->stopNumber, BrkMsg->timestamp, LeftStop(BrkMsg->stopNumber).c_str());
    }

    
    return;
}

