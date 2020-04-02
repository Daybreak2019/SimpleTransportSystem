
//#############################################################################
//# Author: Wen Li
//# Date  : 4/01/2020
//# Description: message subscriber
//##############################################################################

#ifndef _SUBSCRIBER_H_
#define _SUBSCRIBER_H_
#include "macro.h"
#include "ndds/ndds_cpp.h"

using namespace std;

class Subscriber
{
protected:
    string m_MsgTopic;
    DDSDomainParticipant *m_Participant;
    DDSDataReaderListener *m_DdsListener;
    
public:
    Subscriber(string MsgTopic, DDSDataReaderListener *DdsListener)
    {
        m_MsgTopic = MsgTopic;
        m_DdsListener = DdsListener;
    }

    ~Subscriber() 
    {
        if (m_DdsListener)
        {
            delete m_DdsListener;
        }     
    }

protected:
    int Init ();
    int Shutdown();
    
    virtual char* RegMsgType (DDSDomainParticipant *Participant) = 0;
};

#endif
