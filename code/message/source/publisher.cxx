//#############################################################################
//# Author: Wen Li
//# Date  : 4/01/2020
//# Description: message publisher
//##############################################################################
#include "publisher.h"

inline int Publisher::Shutdown(  )
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

    /* RTI Connext provides finalize_instance() method on
        domain participant factory for people who want to release memory used
        by the participant factory. Uncomment the following block of code for
        clean destruction of the singleton. */
    /*

    retcode = DDSDomainParticipantFactory::finalize_instance();
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "finalize_instance error %d\n", retcode);
        status = RT_FAIL;
    }
    */

    return status;
}

DDSDomainParticipant* Publisher::GetParticipant ()
{
    if (m_Participant != NULL)
    {
        return m_Participant;
    }

    /* To customize participant QoS, use the configuration file USER_QOS_PROFILES.xml */
    m_Participant = DDSTheParticipantFactory->create_participant(0, DDS_PARTICIPANT_QOS_DEFAULT, 
                                                                 NULL /* listener */, DDS_STATUS_MASK_NONE);
    assert (m_Participant != NULL);

    return m_Participant;    
}

int Publisher::Init ()
{
    DDSDomainParticipant *participant = NULL;
    DDSPublisher *publisher = NULL;
    DDSTopic *topic = NULL;
    DDSDataWriter *writer = NULL;
    const char *type_name = NULL;

    do
    {  
        participant = GetParticipant ();
    
        /* To customize publisher QoS, use 
        the configuration file USER_QOS_PROFILES.xml */
        publisher = participant->create_publisher(DDS_PUBLISHER_QOS_DEFAULT, 
                                                  NULL /* listener */, DDS_STATUS_MASK_NONE);
        if (publisher == NULL) 
        {
            fprintf(stderr, "create_publisher error\n");
            break;
        }
    
        /* Register type before creating topic */
        type_name = RegMsgType (participant);
        if (type_name == NULL)
        {
            fprintf(stderr, "RegMsgType error\n");
            break;
        }
           
        /* To customize topic QoS, use 
        the configuration file USER_QOS_PROFILES.xml */
        topic = participant->create_topic(m_MsgTopic.c_str(), type_name, DDS_TOPIC_QOS_DEFAULT,
                                          NULL /* listener */, DDS_STATUS_MASK_NONE);
        if (topic == NULL) 
        {
            fprintf(stderr, "create_topic error\n");
            break;
        }
    
        /* To customize data writer QoS, use he configuration file USER_QOS_PROFILES.xml */
        writer = publisher->create_datawriter(topic, DDS_DATAWRITER_QOS_DEFAULT,
                                              NULL /* listener */, DDS_STATUS_MASK_NONE);
        if (writer == NULL) 
        {
            fprintf(stderr, "create_datawriter error\n");
            break;
        }

        /* Init msg writer */
        if (InitWriter (writer) == RT_FAIL)
        {
            fprintf(stderr, "InitWriter error\n");
            break;
        }

        return RT_SUCCESS;

    }while (0);


    return RT_FAIL; 
}



