
//#############################################################################
//# Author: Wen Li
//# Date  : 4/01/2020
//# Description: accident message publisher
//##############################################################################

#ifndef _BREAKDOWNPUBLISHER_H_
#define _BREAKDOWNPUBLISHER_H_
#include "publisher.h"
#include "breakdown.h"
#include "breakdownSupport.h"


class BreakownPublisher:public Publisher
{
private:
    Breakdown *m_BrkMsg;
    
public:
    BreakownPublisher(string MsgTopic):Publisher(MsgTopic)
    {
        m_BrkMsg = BreakdownTypeSupport::create_data();
        assert (m_BrkMsg != NULL);
        
        Init ();
    }

    ~BreakownPublisher() 
    {
        if (m_BrkMsg)
        {
            BreakdownTypeSupport::delete_data(m_BrkMsg);
        }
        
        Shutdown ();        
    }

    int PublishMsg(char *TimeStamp, char *Route, char *Vehicle, int StopNumber)
    {
        int Ret = RT_FAIL;
        DDS_InstanceHandle_t InstanceHdl = DDS_HANDLE_NIL;

        BreakdownDataWriter *BkWriter = (BreakdownDataWriter *)m_Writer;
        if (BkWriter == NULL)
        {
            return RT_FAIL;
        }

        /* Create data sample for writing */
        strncpy (m_BrkMsg->timestamp, TimeStamp, BRK_BUF_LEN);
        strncpy (m_BrkMsg->route, Route, BRK_BUF_LEN);
        strncpy (m_BrkMsg->vehicle, Vehicle, BRK_BUF_LEN);
        m_BrkMsg->stopNumber  = StopNumber;
        
        /* For a data type that has a key, if the same instance is going to be
           written multiple times, initialize the key here
           and register the keyed instance prior to writing */       
        // instance_handle = Position_writer->register_instance(*instance);       
        Ret = BkWriter->write(*m_BrkMsg, InstanceHdl);
        if (Ret != DDS_RETCODE_OK) 
        {
            fprintf(stderr, "write error %d\n", Ret);
        }
        else
        {
            printf ("%s published a breakdown message at stop%d on the route %s at %s\r\n",
                    m_BrkMsg->vehicle, m_BrkMsg->stopNumber, m_BrkMsg->route, m_BrkMsg->timestamp);
        }

        return Ret;
    }

protected:
    int InitWriter (DDSDataWriter *DdsWriter)
    {
        m_Writer = BreakdownDataWriter::narrow(DdsWriter);
        if (m_Writer == NULL) 
        {
            fprintf(stderr, "DataWriter narrow error\n");
            return RT_FAIL;
        }

        return RT_SUCCESS;
    }
    
    char* RegMsgType (DDSDomainParticipant *Participant)
    {
        char *TypeName = (char *)BreakdownTypeSupport::get_type_name();
        int Ret = BreakdownTypeSupport::register_type(Participant, TypeName);
        if (Ret != DDS_RETCODE_OK) 
        {
            fprintf(stderr, "register_type error %d\n", Ret);
            return NULL;
        }

        return TypeName;
    }
};

#endif
