//#############################################################################
//# Author: Wen Li
//# Date  : 4/02/2020
//# Description: simulate a operator
//##############################################################################
#include "operator.h"

void Operator::StartAccListen ()
{  
    m_AccSubscriber = new AccidentSubscriber (string(MESSAGE_TOPIC_ACCIDENT),
                                              new AccidentListener(this));
    assert (m_AccSubscriber != NULL);

    return;
}

void Operator::StartBrkListen ()
{
    m_PosSubscriber = new PositionSubscriber (string(MESSAGE_TOPIC_POSITION),
                                              new PositionListener(this));
    assert (m_PosSubscriber != NULL);
    return;
}

void Operator::StartPosListen ()
{
    m_BrkSubscriber = new BreakownSubscriber (string(MESSAGE_TOPIC_BREAKDOWN),
                                              new BreakdownListener(this));
    assert (m_BrkSubscriber != NULL);
    return;
}


void Operator::PosMsgProc (Position *PosMsg)
{
    printf ("[%s]%s: %s arrived at stop%d of %s\r\n", 
             PosMsg->timestamp, "Operator",
             PosMsg->vehicle, PosMsg->stopNumber, PosMsg->route);
    return;
}


void Operator::AccMsgProc (Accident *AccMsg)
{
    printf ("[%s]%s: %s occur accident at stop%d of %s\r\n", 
            AccMsg->timestamp, "Operator",
            AccMsg->vehicle, AccMsg->stopNumber, AccMsg->route);
    
    return;
}

void Operator::BrkMsgProc (Breakdown *BrkMsg)
{
    printf ("[%s]%s: %s breakdown at stop%d of %s\r\n", 
            BrkMsg->timestamp, "Operator",
            BrkMsg->vehicle, BrkMsg->stopNumber, BrkMsg->route);
    
    return;
}


