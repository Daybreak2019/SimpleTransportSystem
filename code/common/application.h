
//#############################################################################
//# Author: Wen Li
//# Date  : 4/01/2020
//# Description: message read listener and basic class for application
//##############################################################################

#ifndef _APPLICATION_H_
#define _APPLICATION_H_
#include "macro.h"
#include "ndds/ndds_cpp.h"
#include "listener.h"
#include "breakdownSupport.h"
#include "accidentSupport.h"
#include "positionSupport.h"


using namespace std;

class Application 
{
public:
    virtual void PosMsgProc (Position *PosMsg) = 0;
    virtual void AccMsgProc (Accident *PosMsg) = 0;
    virtual void BrkMsgProc (Breakdown *PosMsg) = 0;
};

class PositionListener : public ReadListener 
{
private:
    Application *m_Application;
    
public:
    PositionListener (Application *App)
    {
        m_Application = App;
    }
    
    virtual void on_data_available(DDSDataReader* reader)
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
    
            m_Application->PosMsgProc (&data_seq[i]); 
        }
    
        retcode = Position_reader->return_loan(data_seq, info_seq);
        if (retcode != DDS_RETCODE_OK) 
        {
            fprintf(stderr, "return loan error %d\n", retcode);
        }
    }
};

class BreakdownListener : public ReadListener 
{
private:
    Application *m_Application;

public:
    BreakdownListener (Application *App)
    {
        m_Application = App;
    }
    
    virtual void on_data_available(DDSDataReader* reader)
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

            m_Application->BrkMsgProc (&data_seq[i]);
        }
        
        retcode = Breakdown_reader->return_loan(data_seq, info_seq);
        if (retcode != DDS_RETCODE_OK) 
        {
            fprintf(stderr, "return loan error %d\n", retcode);
        }
        
        return;

    }
};


class AccidentListener : public ReadListener 
{
private:
    Application *m_Application;

public:
    AccidentListener (Application *App)
    {
        m_Application = App;
    }
    
    virtual void on_data_available(DDSDataReader* reader)
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
            
            m_Application->AccMsgProc (&data_seq[i]);
        }

        retcode = Accident_reader->return_loan(data_seq, info_seq);
        if (retcode != DDS_RETCODE_OK)
        {
            fprintf(stderr, "return loan error %d\n", retcode);
        }
    }
};

#endif
