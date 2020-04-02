
//#############################################################################
//# Author: Wen Li
//# Date  : 4/01/2020
//# Description: message read listener
//##############################################################################

#ifndef _LISTENER_H_
#define _LISTENER_H_
#include "macro.h"
#include "ndds/ndds_cpp.h"

using namespace std;

class ReadListener : public DDSDataReaderListener 
{
  public:
    virtual void on_requested_deadline_missed(
        DDSDataReader* /*reader*/,
        const DDS_RequestedDeadlineMissedStatus& /*status*/) {}

    virtual void on_requested_incompatible_qos(
        DDSDataReader* /*reader*/,
        const DDS_RequestedIncompatibleQosStatus& /*status*/) {}

    virtual void on_sample_rejected(
        DDSDataReader* /*reader*/,
        const DDS_SampleRejectedStatus& /*status*/) {}

    virtual void on_liveliness_changed(
        DDSDataReader* /*reader*/,
        const DDS_LivelinessChangedStatus& /*status*/) {}

    virtual void on_sample_lost(
        DDSDataReader* /*reader*/,
        const DDS_SampleLostStatus& /*status*/) {}

    virtual void on_subscription_matched(
        DDSDataReader* /*reader*/,
        const DDS_SubscriptionMatchedStatus& /*status*/) {}
	
    virtual void on_data_available(DDSDataReader* reader)
    {
        return;
    }
};

#endif
