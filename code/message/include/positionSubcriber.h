
//#############################################################################
//# Author: Wen Li
//# Date  : 4/01/2020
//# Description: accident message subscriber
//##############################################################################

#ifndef _POSITIONSUBSCRIBER_H_
#define _POSITIONSUBSCRIBER_H_
#include "subscriber.h"
#include "position.h"
#include "positionSupport.h"


class PositionSubscriber:public Subscriber
{ 
public:
    PositionSubscriber(string MsgTopic, DDSDataReaderListener *DdsListener):\
                            Subscriber(MsgTopic, DdsListener)
    {
        Init ();
    }

    ~PositionSubscriber() 
    {      
        Shutdown ();        
    }
   

protected:
    
    char* RegMsgType (DDSDomainParticipant *Participant)
    {
        char *TypeName = (char *)PositionTypeSupport::get_type_name();
        int Ret = PositionTypeSupport::register_type(m_Participant, TypeName);
        if (Ret != DDS_RETCODE_OK) 
        {
            fprintf(stderr, "register_type error %d\n", Ret);
            return NULL;
        }

        return TypeName;
    }
};

#endif
