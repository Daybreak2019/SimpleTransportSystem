//#############################################################################
//# Author: Wen Li
//# Date  : 4/01/2020
//# Description: message subscriber
//##############################################################################
#include "subscriber.h"

int Subscriber::Shutdown()
{
    DDS_ReturnCode_t retcode;
    int status = RT_SUCCESS;

    if (m_Participant == NULL)
    {
        return RT_FAIL;
    }

    retcode = m_Participant->delete_contained_entities();
    if (retcode != DDS_RETCODE_OK) 
    {
        fprintf(stderr, "delete_contained_entities error %d\n", retcode);
        status = RT_FAIL;
    }

    retcode = DDSTheParticipantFactory->delete_participant(m_Participant);
    if (retcode != DDS_RETCODE_OK) 
    {
        fprintf(stderr, "delete_participant error %d\n", retcode);
        status = RT_FAIL;
    }

    return status;
}


int Subscriber::Init ()
{
    DDSDomainParticipant *participant = NULL;
    DDSSubscriber *subscriber = NULL;
    DDSTopic *topic = NULL;
    DDS_ReturnCode_t retcode;
    const char *type_name = NULL;
    DDSDataReader *reader = NULL;


    do
    {
        /* To customize the participant QoS, use the configuration file USER_QOS_PROFILES.xml */
        participant = DDSTheParticipantFactory->create_participant(0, DDS_PARTICIPANT_QOS_DEFAULT, 
                                                                   NULL /* listener */, DDS_STATUS_MASK_NONE);
        if (participant == NULL) 
        {
            fprintf(stderr, "create_participant error\n");
            break;
        }
        m_Participant = participant;

        /* To customize the subscriber QoS, use the configuration file USER_QOS_PROFILES.xml */
        subscriber = participant->create_subscriber(DDS_SUBSCRIBER_QOS_DEFAULT, NULL /* listener */, DDS_STATUS_MASK_NONE);
        if (subscriber == NULL) 
        {
            fprintf(stderr, "create_subscriber error\n");
            break;
        }

        /* Register the type before creating the topic */
        type_name = RegMsgType (participant);
        if (type_name == NULL)
        {
            break;
        }

        /* To customize the topic QoS, use the configuration file USER_QOS_PROFILES.xml */
        topic = participant->create_topic(m_MsgTopic.c_str(), type_name, DDS_TOPIC_QOS_DEFAULT, NULL /* listener */,
                                          DDS_STATUS_MASK_NONE);
        if (topic == NULL) 
        {
            fprintf(stderr, "create_topic error\n");
            break;
        }


        /* To customize the data reader QoS, use the configuration file USER_QOS_PROFILES.xml */
        reader = subscriber->create_datareader(topic, DDS_DATAREADER_QOS_DEFAULT, 
                                               m_DdsListener, DDS_STATUS_MASK_ALL);
        if (reader == NULL) 
        {
            fprintf(stderr, "create_datareader error\n");
            return RT_FAIL;
        }

        return RT_SUCCESS;
    }while (0);

    return RT_FAIL; 
}



