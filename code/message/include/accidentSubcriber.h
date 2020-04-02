
//#############################################################################
//# Author: Wen Li
//# Date  : 4/01/2020
//# Description: accident message subsriber
//##############################################################################

#ifndef _ACCIDENTSUBSCRIBER_H_
#define _ACCIDENTSUBSCRIBER_H_
#include "subscriber.h"
#include "accident.h"
#include "accidentSupport.h"

class AccidentSubscriber:public Subscriber
{  
public:
    AccidentSubscriber(string MsgTopic, DDSDataReaderListener *DdsListener):\
                            Subscriber(MsgTopic, DdsListener)
    {
        Init ();
    }

    ~AccidentSubscriber() 
    {
        Shutdown ();
    }

  
protected:  
    char* RegMsgType (DDSDomainParticipant *Participant)
    {
        char *TypeName = (char *)AccidentTypeSupport::get_type_name();
        int Ret = AccidentTypeSupport::register_type(m_Participant, TypeName);
        if (Ret != DDS_RETCODE_OK) 
        {
            fprintf(stderr, "register_type error %d\n", Ret);
            return NULL;
        }

        return TypeName;
    }
};

#endif
