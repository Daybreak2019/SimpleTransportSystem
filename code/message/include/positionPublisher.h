
//#############################################################################
//# Author: Wen Li
//# Date  : 4/01/2020
//# Description: accident message publisher
//##############################################################################

#ifndef _POSITIONPUBLISHER_H_
#define _POSITIONPUBLISHER_H_
#include "publisher.h"
#include "position.h"
#include "positionSupport.h"



class PositionPublisher:public Publisher
{ 
private:
    Position *m_PosMsg;
    
public:
    PositionPublisher(string MsgTopic):Publisher(MsgTopic)
    {
        m_PosMsg = PositionTypeSupport::create_data();
        assert (m_PosMsg != NULL);
        
        Init ();
    }

    ~PositionPublisher() 
    {
        if (m_PosMsg)
        {
            PositionTypeSupport::delete_data(m_PosMsg);
        }
        
        Shutdown ();        
    }

    int PublishMsg(char *TimeStamp, char *Route, char *Vehicle,
                      char *TrafficCon, int FillInRatio, int StopNumber, 
                      int NumStops, float TimeBetweenStops)
    {
        int Ret = RT_FAIL;   
        DDS_InstanceHandle_t InstanceHdl = DDS_HANDLE_NIL;

        PositionDataWriter *PosWriter = (PositionDataWriter *)m_Writer;
        if (PosWriter == NULL)
        {
            return RT_FAIL;
        }

        strncpy (m_PosMsg->timestamp, TimeStamp, POS_BUF_LEN);
        strncpy (m_PosMsg->route, Route, POS_BUF_LEN);
        strncpy (m_PosMsg->vehicle, Vehicle, POS_BUF_LEN);
        strncpy (m_PosMsg->trafficConditions, TrafficCon, POS_BUF_LEN);
        m_PosMsg->fillInRatio = FillInRatio;
        m_PosMsg->stopNumber  = StopNumber;
        m_PosMsg->numStops    = NumStops;
        m_PosMsg->timeBetweenStops = TimeBetweenStops;

        Ret = PosWriter->write(*m_PosMsg, InstanceHdl);
        if (Ret != DDS_RETCODE_OK) 
        {
            fprintf(stderr, "write error %d\n", Ret);
        }
        else
        {
            printf ("%s published a position message at stop%d on the route %s at %s\r\n",
                    m_PosMsg->vehicle, m_PosMsg->stopNumber, m_PosMsg->route, m_PosMsg->timestamp);
        }

        return Ret;
    }


protected:
    int InitWriter (DDSDataWriter *DdsWriter)
    {
        m_Writer = PositionDataWriter::narrow(DdsWriter);
        if (m_Writer == NULL) 
        {
            fprintf(stderr, "DataWriter narrow error\n");
            return RT_FAIL;
        }

        return RT_SUCCESS;
    }
    
    char* RegMsgType (DDSDomainParticipant *Participant)
    {
        char *TypeName = (char *)PositionTypeSupport::get_type_name();
        int Ret = PositionTypeSupport::register_type(Participant, TypeName);
        if (Ret != DDS_RETCODE_OK) 
        {
            fprintf(stderr, "register_type error %d\n", Ret);
            return NULL;
        }

        return TypeName;
    }
};

#endif
