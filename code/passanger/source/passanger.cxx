//#############################################################################
//# Author: Wen Li
//# Date  : 4/01/2020
//# Description: simulate a passanger
//##############################################################################
#include "passanger.h"

void Passanger::StartAccListen ()
{  
    m_AccSubscriber = new AccidentSubscriber (string(MESSAGE_TOPIC_ACCIDENT),
                                              new AccidentListener(this));
    assert (m_AccSubscriber != NULL);

    return;
}

void Passanger::StartBrkListen ()
{
    m_PosSubscriber = new PositionSubscriber (string(MESSAGE_TOPIC_POSITION),
                                              new PositionListener(this));
    assert (m_PosSubscriber != NULL);
    return;
}

void Passanger::StartPosListen ()
{
    m_BrkSubscriber = new BreakownSubscriber (string(MESSAGE_TOPIC_BREAKDOWN),
                                              new BreakdownListener(this));
    assert (m_BrkSubscriber != NULL);
    return;
}


void Passanger::PosMsgProc (Position *PosMsg)
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
            printf ("[%s]%s: arrived at stop%d on %s of %s\r\n", 
                    PosMsg->timestamp, m_Name.c_str(),
                    PosMsg->stopNumber, PosMsg->vehicle, PosMsg->route);
            /* exit */
            exit (0);
        }
        else if (m_StartStop == PosMsg->stopNumber)
        {
            m_Bus = string(PosMsg->vehicle);
            printf ("[%s]%s: gets on %s at stop%d of %s\r\n", 
                    PosMsg->timestamp, m_Name.c_str(),
                    PosMsg->vehicle, PosMsg->stopNumber, PosMsg->route);
        }
        else
        {
            printf ("[%s]%s: %s passes stop%d of %s\r\n", 
                    PosMsg->timestamp, m_Name.c_str(),
                    PosMsg->vehicle, PosMsg->stopNumber, PosMsg->route);
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
            printf ("[%s]%s: %s passes stop%d of %s\r\n", 
                    PosMsg->timestamp, m_Name.c_str(),
                    PosMsg->vehicle, PosMsg->stopNumber, PosMsg->route);
        }
        else
        {
            printf ("[%s]%s: arrived at stop%d on %s of %s\r\n", 
                    PosMsg->timestamp, m_Name.c_str(),
                    PosMsg->stopNumber, PosMsg->vehicle, PosMsg->route);
            /* exit */
            exit (0);
        }
    }

    return;
}


void Passanger::AccMsgProc (Accident *AccMsg)
{
    /* 1. check the route expected */
    if (!IsWantedRoute (string(AccMsg->route)))
    {
        return;
    }
    
    if (m_Bus == "")
    {
        printf ("[%s]%s: %s occur accident at stop%d of %s\r\n", 
                AccMsg->timestamp, m_Name.c_str(),
                AccMsg->vehicle, AccMsg->stopNumber, AccMsg->route);
    }
    else
    {
        /* on a bus, only receive the message with the bus */
        if (!IsBoaredBus(string(AccMsg->vehicle)))
        {
            return;
        }

        printf ("[%s]%s: %s occur accident at stop%d of %s, waiting for fixing...\r\n", 
                AccMsg->timestamp, m_Name.c_str(),
                AccMsg->vehicle, AccMsg->stopNumber, AccMsg->route);
    }
    
    return;
}

void Passanger::BrkMsgProc (Breakdown *BrkMsg)
{
    /* 1. check the route expected */
    if (!IsWantedRoute (string(BrkMsg->route)))
    {
        return;
    }

    if (m_Bus == "")
    {
        printf ("[%s]%s: %s breakdown at stop%d of %s\r\n", 
                BrkMsg->timestamp, m_Name.c_str(),
                BrkMsg->vehicle, BrkMsg->stopNumber, BrkMsg->route);
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

        printf ("[%s]%s: %s breakdown at stop%d of %s, waiting for another bus...\r\n", 
                BrkMsg->timestamp, m_Name.c_str(),
                BrkMsg->vehicle, BrkMsg->stopNumber, BrkMsg->route);
    }

    
    return;
}

