//#############################################################################
//# Author: Wen Li
//# Date  : 4/01/2020
//# Description: three message listener
//##############################################################################
#include "passanger.h"

void BreakdownListener::on_data_available(DDSDataReader* reader)
{
    BreakdownDataReader *Breakdown_reader = NULL;
    BreakdownSeq data_seq;
    DDS_SampleInfoSeq info_seq;
    DDS_ReturnCode_t retcode;
    int i;
    
    Breakdown_reader = BreakdownDataReader::narrow(reader);
    if (Breakdown_reader == NULL) 
    {
        fprintf(stderr, "DataReader narrow error\n");
        return;
    }
    
    retcode = Breakdown_reader->take(data_seq, info_seq, DDS_LENGTH_UNLIMITED,
                                    DDS_ANY_SAMPLE_STATE, DDS_ANY_VIEW_STATE, DDS_ANY_INSTANCE_STATE);
    
    if (retcode == DDS_RETCODE_NO_DATA) 
    {
        return;
    } 
    else if (retcode != DDS_RETCODE_OK) 
    {
        fprintf(stderr, "take error %d\n", retcode);
        return;
    }
    
    /* start to read message */
    for (i = 0; i < data_seq.length(); ++i) 
    {
        if (!info_seq[i].valid_data) 
        {
            continue;
        }

        m_Passanger->BrkMsgProc (&data_seq[i]);
        //cout<<"==>Breakdown Message:"<<endl;
        //BreakdownTypeSupport::print_data(&data_seq[i]);
    }
    
    retcode = Breakdown_reader->return_loan(data_seq, info_seq);
    if (retcode != DDS_RETCODE_OK) 
    {
        fprintf(stderr, "return loan error %d\n", retcode);
    }
    
    return;

}


void AccidentListener::on_data_available(DDSDataReader* reader)
{
    AccidentDataReader *Accident_reader = NULL;
    AccidentSeq data_seq;
    DDS_SampleInfoSeq info_seq;
    DDS_ReturnCode_t retcode;
    int i;

    Accident_reader = AccidentDataReader::narrow(reader);
    if (Accident_reader == NULL) 
    {
        fprintf(stderr, "DataReader narrow error\n");
        return;
    }

    retcode = Accident_reader->take(data_seq, info_seq, DDS_LENGTH_UNLIMITED,
                                    DDS_ANY_SAMPLE_STATE, DDS_ANY_VIEW_STATE, DDS_ANY_INSTANCE_STATE);
    if (retcode == DDS_RETCODE_NO_DATA)
    {
        return;
    }
    else if (retcode != DDS_RETCODE_OK)
    {
        fprintf(stderr, "take error %d\n", retcode);
        return;
    }

    for (i = 0; i < data_seq.length(); ++i) 
    {
        if (!info_seq[i].valid_data) 
        {
            continue;            
        }

        m_Passanger->AccMsgProc (&data_seq[i]);
    }

    retcode = Accident_reader->return_loan(data_seq, info_seq);
    if (retcode != DDS_RETCODE_OK)
    {
        fprintf(stderr, "return loan error %d\n", retcode);
    }
}


void PositionListener::on_data_available(DDSDataReader* reader)
{
    PositionDataReader *Position_reader = NULL;
    PositionSeq data_seq;
    DDS_SampleInfoSeq info_seq;
    DDS_ReturnCode_t retcode;
    int i;

    Position_reader = PositionDataReader::narrow(reader);
    if (Position_reader == NULL) 
    {
        fprintf(stderr, "DataReader narrow error\n");
        return;
    }

    retcode = Position_reader->take(data_seq, info_seq, DDS_LENGTH_UNLIMITED,
                                    DDS_ANY_SAMPLE_STATE, DDS_ANY_VIEW_STATE, DDS_ANY_INSTANCE_STATE);
    if (retcode == DDS_RETCODE_NO_DATA) 
    {
        return;
    } 
    else if (retcode != DDS_RETCODE_OK) 
    {
        fprintf(stderr, "take error %d\n", retcode);
        return;
    }

    for (i = 0; i < data_seq.length(); ++i) 
    {
        if (!info_seq[i].valid_data) 
        {
            continue;            
        }

        m_Passanger->PosMsgProc (&data_seq[i]);
    }

    retcode = Position_reader->return_loan(data_seq, info_seq);
    if (retcode != DDS_RETCODE_OK) 
    {
        fprintf(stderr, "return loan error %d\n", retcode);
    }
}



