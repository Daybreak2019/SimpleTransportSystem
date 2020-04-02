
//#############################################################################
//# Author: Wen Li
//# Date  : 4/01/2020
//# Description: three message listener
//##############################################################################

#ifndef _MSGLISTENER_H_
#define _MSGLISTENER_H_
#include "listener.h"
#include "breakdownSupport.h"
#include "accidentSupport.h"
#include "positionSupport.h"


using namespace std;

class Passanger;

class PositionListener : public ReadListener 
{
private:
    Passanger *m_Passanger;
    
public:
    PositionListener (Passanger *P)
    {
        m_Passanger = P;
    }
    
    virtual void on_data_available(DDSDataReader* reader);
};

class BreakdownListener : public ReadListener 
{
private:
    Passanger *m_Passanger;

public:
    BreakdownListener (Passanger *P)
    {
        m_Passanger = P;
    }
    
    virtual void on_data_available(DDSDataReader* reader);
};


class AccidentListener : public ReadListener 
{
private:
    Passanger *m_Passanger;

public:
    AccidentListener (Passanger *P)
    {
        m_Passanger = P;
    }
    
    virtual void on_data_available(DDSDataReader* reader);
};

#endif
