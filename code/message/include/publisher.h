
//#############################################################################
//# Author: Wen Li
//# Date  : 4/01/2020
//# Description: message publisher
//##############################################################################

#ifndef _PUBLISHER_H_
#define _PUBLISHER_H_
#include "macro.h"
#include "ndds/ndds_cpp.h"

using namespace std;

class Publisher
{
protected:
    void *m_Writer;
    string m_MsgTopic;
    DDSDomainParticipant *m_Participant;
    
public:
    Publisher(string MsgTopic)
    {
        m_Writer = NULL;
        m_MsgTopic = MsgTopic;
        m_Participant = NULL;
    }

    ~Publisher() 
    {
        
    }
private:
    DDSDomainParticipant* GetParticipant ();

protected:
    int Init ();
    int Shutdown();
    
    virtual int InitWriter (DDSDataWriter *DdsWriter) = 0;
    virtual char* RegMsgType (DDSDomainParticipant *Participant) = 0;
};

#endif
