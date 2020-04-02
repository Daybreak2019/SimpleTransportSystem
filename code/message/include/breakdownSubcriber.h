
//#############################################################################
//# Author: Wen Li
//# Date  : 4/01/2020
//# Description: accident message subscriber
//##############################################################################

#ifndef _BREAKDOWNSUBSCRIBER_H_
#define _BREAKDOWNSUBSCRIBER_H_
#include "subscriber.h"
#include "breakdown.h"
#include "breakdownSupport.h"


class BreakownSubscriber:public Subscriber
{
public:
    BreakownSubscriber(string MsgTopic, DDSDataReaderListener *DdsListener):\
                            Subscriber(MsgTopic, DdsListener)
    {
        Init ();
    }

    ~BreakownSubscriber() 
    {
        Shutdown ();        
    }

protected:
  
    char* RegMsgType (DDSDomainParticipant *Participant)
    {
        char *TypeName = (char *)BreakdownTypeSupport::get_type_name();
        int Ret = BreakdownTypeSupport::register_type(m_Participant, TypeName);
        if (Ret != DDS_RETCODE_OK) 
        {
            fprintf(stderr, "register_type error %d\n", Ret);
            return NULL;
        }

        return TypeName;
    }
};

#endif
