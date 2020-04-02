
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
public:
    AccidentPublisher(string MsgTopic):Publisher(MsgTopic)
    {
        Init ();
    }

    ~AccidentPublisher() 
    {
        Shutdown ();
    }

    int PublishMsg(char *TimeStamp, char *Route, char *Vehicle, int StopNumber)
    {
        int Ret = RT_FAIL;
        Accident *AccMsg = NULL;
        DDS_InstanceHandle_t InstanceHdl = DDS_HANDLE_NIL;

        AccidentDataWriter *AccWriter = (AccidentDataWriter *)m_Writer;
        if (AccWriter == NULL)
        {
            return RT_FAIL;
        }

        /* Create data sample for writing */
        AccMsg = AccidentTypeSupport::create_data();
        if (AccMsg == NULL) 
        {
            fprintf(stderr, "AccidentTypeSupport::create_data error\n");
            return RT_FAIL;
        }

        strncpy (AccMsg->timestamp, TimeStamp, ACC_BUF_LEN);
        strncpy (AccMsg->route, Route, ACC_BUF_LEN);
        strncpy (AccMsg->vehicle, Vehicle, ACC_BUF_LEN);
        AccMsg->stopNumber  = StopNumber;
        
        /* For a data type that has a key, if the same instance is going to be
           written multiple times, initialize the key here
           and register the keyed instance prior to writing */       
        // instance_handle = Position_writer->register_instance(*instance);
        
        Ret = AccWriter->write(*AccMsg, InstanceHdl);
        if (Ret != DDS_RETCODE_OK) 
        {
            fprintf(stderr, "write error %d\n", Ret);
        }
        else
        {
            cout<<"----------------------------------------------------------\r\n";
            cout<<"AccidentMessage:";
            AccidentTypeSupport::print_data(AccMsg); 
        }
        
        /* Delete data sample */
        if (AccidentTypeSupport::delete_data(AccMsg) != DDS_RETCODE_OK) 
        {
            fprintf(stderr, "AccidentTypeSupport::delete_data error \n");
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
