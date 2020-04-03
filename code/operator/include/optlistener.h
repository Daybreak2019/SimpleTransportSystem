
//#############################################################################
//# Author: Wen Li
//# Date  : 4/02/2020
//# Description: three message listener for operator
//##############################################################################

#ifndef _OPTLISTENER_H_
#define _OPTLISTENER_H_
#include "listener.h"
#include "breakdownSupport.h"
#include "accidentSupport.h"
#include "positionSupport.h"

using namespace std;
class Operator;

class PositionListener : public ReadListener 
{
private:
    Operator *m_Operator;
    
public:
    PositionListener (Operator *Opt)
    {
        m_Operator = Opt;
    }
    
    virtual void on_data_available(DDSDataReader* reader);
};

class BreakdownListener : public ReadListener 
{
private:
    Operator *m_Operator;

public:
    BreakdownListener (Operator *Opt)
    {
        m_Operator = Opt;
    }
    
    virtual void on_data_available(DDSDataReader* reader);
};


class AccidentListener : public ReadListener 
{
private:
    Operator *m_Operator;

public:
    AccidentListener (Operator *Opt)
    {
        m_Operator = Opt;
    }
    
    virtual void on_data_available(DDSDataReader* reader);
};

#endif
