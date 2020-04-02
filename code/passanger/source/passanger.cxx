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




