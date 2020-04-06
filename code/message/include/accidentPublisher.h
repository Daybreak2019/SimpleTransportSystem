
//#############################################################################
//# Author: Wen Li
//# Date  : 4/01/2020
//# Description: accident message publisher
//##############################################################################

#ifndef _ACCIDENTPUBLISHER_H_
#define _ACCIDENTPUBLISHER_H_
#include "publisher.h"
#include "accident.h"
#include "accidentSupport.h"


class AccidentPublisher:public Publisher
{
private:
    Accident *m_AccMsg;
    
public:
    AccidentPublisher(string MsgTopic):Publisher(MsgTopic)
    {
        m_AccMsg = AccidentTypeSupport::create_data();
        assert (m_AccMsg != NULL);
        
        Init ();
    }

    ~AccidentPublisher() 
    {
        if (m_AccMsg)
        {
            AccidentTypeSupport::delete_data(m_AccMsg);
        }
        
        Shutdown ();
    }

    int PublishMsg(char *TimeStamp, char *Route, char *Vehicle, int StopNumber)
    {
        int Ret = RT_FAIL;
        DDS_InstanceHandle_t InstanceHdl = DDS_HANDLE_NIL;

        AccidentDataWriter *AccWriter = (AccidentDataWriter *)m_Writer;
        if (AccWriter == NULL)
        {
            return RT_FAIL;
        }

        strncpy (m_AccMsg->timestamp, TimeStamp, ACC_BUF_LEN);
        strncpy (m_AccMsg->route, Route, ACC_BUF_LEN);
        strncpy (m_AccMsg->vehicle, Vehicle, ACC_BUF_LEN);
        m_AccMsg->stopNumber  = StopNumber;
        
        /* For a data type that has a key, if the same instance is going to be
           written multiple times, initialize the key here
           and register the keyed instance prior to writing */       
        // instance_handle = Position_writer->register_instance(*instance);
        
        Ret = AccWriter->write(*m_AccMsg, InstanceHdl);
        if (Ret != DDS_RETCODE_OK) 
        {
            fprintf(stderr, "write error %d\n", Ret);
        }
        else
        {
            printf ("%s published a accident message at stop%d on the route %s at %s\r\n",
                    m_AccMsg->vehicle, m_AccMsg->stopNumber, m_AccMsg->route, m_AccMsg->timestamp);
        }
        

        return Ret;
    }

protected:
    int InitWriter (DDSDataWriter *DdsWriter)
    {
        m_Writer = AccidentDataWriter::narrow(DdsWriter);
        if (m_Writer == NULL) 
        {
            fprintf(stderr, "DataWriter narrow error\n");
            return RT_FAIL;
        }

        return RT_SUCCESS;
    }
    
    char* RegMsgType (DDSDomainParticipant *Participant)
    {
        char *TypeName = (char *)AccidentTypeSupport::get_type_name();
        int Ret = AccidentTypeSupport::register_type(Participant, TypeName);
        if (Ret != DDS_RETCODE_OK) 
        {
            fprintf(stderr, "register_type error %d\n", Ret);
            return NULL;
        }

        return TypeName;
    }
};

#endif
