

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from position.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_cpp_h
#include "ndds/ndds_cpp.h"
#endif
#ifndef dds_c_log_impl_h              
#include "dds_c/dds_c_log_impl.h"                                
#endif 
#ifndef dds_c_log_infrastructure_h                      
#include "dds_c/dds_c_infrastructure_impl.h"       
#endif 

#ifndef cdr_type_h
#include "cdr/cdr_type.h"
#endif    

#ifndef osapi_heap_h
#include "osapi/osapi_heap.h" 
#endif
#else
#include "ndds_standalone_type.h"
#endif

#include "position.h"

#ifndef NDDS_STANDALONE_TYPE
#include "positionPlugin.h"
#endif

#include <new>

/* ========================================================================= */
const char *PositionTYPENAME = "Position";

#ifndef NDDS_STANDALONE_TYPE
DDS_TypeCode* Position_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode Position_g_tc_timestamp_string = DDS_INITIALIZE_STRING_TYPECODE(((POS_BUF_LEN)));
    static DDS_TypeCode Position_g_tc_route_string = DDS_INITIALIZE_STRING_TYPECODE(((POS_BUF_LEN)));
    static DDS_TypeCode Position_g_tc_vehicle_string = DDS_INITIALIZE_STRING_TYPECODE(((POS_BUF_LEN)));
    static DDS_TypeCode Position_g_tc_trafficConditions_string = DDS_INITIALIZE_STRING_TYPECODE(((POS_BUF_LEN)));

    static DDS_TypeCode_Member Position_g_tc_members[8]=
    {

        {
            (char *)"timestamp",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"route",/* Member name */
            {
                1,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"vehicle",/* Member name */
            {
                2,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"trafficConditions",/* Member name */
            {
                3,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"stopNumber",/* Member name */
            {
                4,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"numStops",/* Member name */
            {
                5,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"fillInRatio",/* Member name */
            {
                6,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"timeBetweenStops",/* Member name */
            {
                7,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode Position_g_tc =
    {{
            DDS_TK_STRUCT, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"Position", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            8, /* Number of members */
            Position_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for Position*/

    if (is_initialized) {
        return &Position_g_tc;
    }

    Position_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    Position_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&Position_g_tc_timestamp_string;
    Position_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&Position_g_tc_route_string;
    Position_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&Position_g_tc_vehicle_string;
    Position_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&Position_g_tc_trafficConditions_string;
    Position_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long_w_new;
    Position_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long_w_new;
    Position_g_tc_members[6]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long_w_new;
    Position_g_tc_members[7]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float_w_new;

    /* Initialize the values for member annotations. */
    Position_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
    Position_g_tc_members[0]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

    Position_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
    Position_g_tc_members[1]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

    Position_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
    Position_g_tc_members[2]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

    Position_g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
    Position_g_tc_members[3]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

    Position_g_tc_members[4]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
    Position_g_tc_members[4]._annotations._defaultValue._u.long_value = 0;
    Position_g_tc_members[4]._annotations._minValue._d = RTI_XCDR_TK_LONG;
    Position_g_tc_members[4]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
    Position_g_tc_members[4]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
    Position_g_tc_members[4]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

    Position_g_tc_members[5]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
    Position_g_tc_members[5]._annotations._defaultValue._u.long_value = 0;
    Position_g_tc_members[5]._annotations._minValue._d = RTI_XCDR_TK_LONG;
    Position_g_tc_members[5]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
    Position_g_tc_members[5]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
    Position_g_tc_members[5]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

    Position_g_tc_members[6]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
    Position_g_tc_members[6]._annotations._defaultValue._u.long_value = 0;
    Position_g_tc_members[6]._annotations._minValue._d = RTI_XCDR_TK_LONG;
    Position_g_tc_members[6]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
    Position_g_tc_members[6]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
    Position_g_tc_members[6]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

    Position_g_tc_members[7]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
    Position_g_tc_members[7]._annotations._defaultValue._u.float_value = 0.0f;
    Position_g_tc_members[7]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
    Position_g_tc_members[7]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
    Position_g_tc_members[7]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
    Position_g_tc_members[7]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

    Position_g_tc._data._sampleAccessInfo =
    Position_get_sample_access_info();
    Position_g_tc._data._typePlugin =
    Position_get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &Position_g_tc;
}

#define TSeq PositionSeq
#define T Position
#include "dds_cpp/generic/dds_cpp_data_TInterpreterSupport.gen"
#undef T
#undef TSeq

RTIXCdrSampleAccessInfo *Position_get_sample_seq_access_info()
{
    static RTIXCdrSampleAccessInfo Position_g_seqSampleAccessInfo = {
        RTI_XCDR_TYPE_BINDING_CPP, \
        {sizeof(PositionSeq),0,0,0}, \
        RTI_XCDR_FALSE, \
        DDS_Sequence_get_member_value_pointer, \
        PositionSeq_set_member_element_count, \
        NULL, \
        NULL, \
        NULL \
    };

    return &Position_g_seqSampleAccessInfo;
}

RTIXCdrSampleAccessInfo *Position_get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    Position *sample;

    static RTIXCdrMemberAccessInfo Position_g_memberAccessInfos[8] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo Position_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &Position_g_sampleAccessInfo;
    }

    RTIXCdrHeap_allocateStruct(
        &sample, 
        Position);
    if (sample == NULL) {
        return NULL;
    }

    Position_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->timestamp - (char *)sample);

    Position_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->route - (char *)sample);

    Position_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->vehicle - (char *)sample);

    Position_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->trafficConditions - (char *)sample);

    Position_g_memberAccessInfos[4].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->stopNumber - (char *)sample);

    Position_g_memberAccessInfos[5].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->numStops - (char *)sample);

    Position_g_memberAccessInfos[6].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->fillInRatio - (char *)sample);

    Position_g_memberAccessInfos[7].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->timeBetweenStops - (char *)sample);

    Position_g_sampleAccessInfo.memberAccessInfos = 
    Position_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(Position);

        if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
            Position_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrUnsignedLong_MAX;
        } else {
            Position_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    Position_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
    RTI_XCDR_TRUE;

    Position_g_sampleAccessInfo.getMemberValuePointerFcn = 
    Position_get_member_value_pointer;

    Position_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_CPP ;

    RTIXCdrHeap_freeStruct(sample);
    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &Position_g_sampleAccessInfo;
}

RTIXCdrTypePlugin *Position_get_type_plugin_info()
{
    static RTIXCdrTypePlugin Position_g_typePlugin = 
    {
        NULL, /* serialize */
        NULL, /* serialize_key */
        NULL, /* deserialize_sample */
        NULL, /* deserialize_key_sample */
        NULL, /* skip */
        NULL, /* get_serialized_sample_size */
        NULL, /* get_serialized_sample_max_size_ex */
        NULL, /* get_serialized_key_max_size_ex */
        NULL, /* get_serialized_sample_min_size */
        NULL, /* serialized_sample_to_key */
        (RTIXCdrTypePluginInitializeSampleFunction) 
        Position_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        Position_finalize_w_return,
        NULL
    };

    return &Position_g_typePlugin;
}
#endif

RTIBool Position_initialize(
    Position* sample) {
    return Position_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool Position_initialize_ex(
    Position* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return Position_initialize_w_params(
        sample,&allocParams);

}

RTIBool Position_initialize_w_params(
    Position* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    if (allocParams->allocate_memory) {
        sample->timestamp = DDS_String_alloc(((POS_BUF_LEN)));
        RTICdrType_copyStringEx(
            &sample->timestamp,
            "",
            ((POS_BUF_LEN)),
            RTI_FALSE);
        if (sample->timestamp == NULL) {
            return RTI_FALSE;
        }
    } else {
        if (sample->timestamp != NULL) {
            RTICdrType_copyStringEx(
                &sample->timestamp,
                "",
                ((POS_BUF_LEN)),
                RTI_FALSE);
            if (sample->timestamp == NULL) {
                return RTI_FALSE;
            }
        }
    }

    if (allocParams->allocate_memory) {
        sample->route = DDS_String_alloc(((POS_BUF_LEN)));
        RTICdrType_copyStringEx(
            &sample->route,
            "",
            ((POS_BUF_LEN)),
            RTI_FALSE);
        if (sample->route == NULL) {
            return RTI_FALSE;
        }
    } else {
        if (sample->route != NULL) {
            RTICdrType_copyStringEx(
                &sample->route,
                "",
                ((POS_BUF_LEN)),
                RTI_FALSE);
            if (sample->route == NULL) {
                return RTI_FALSE;
            }
        }
    }

    if (allocParams->allocate_memory) {
        sample->vehicle = DDS_String_alloc(((POS_BUF_LEN)));
        RTICdrType_copyStringEx(
            &sample->vehicle,
            "",
            ((POS_BUF_LEN)),
            RTI_FALSE);
        if (sample->vehicle == NULL) {
            return RTI_FALSE;
        }
    } else {
        if (sample->vehicle != NULL) {
            RTICdrType_copyStringEx(
                &sample->vehicle,
                "",
                ((POS_BUF_LEN)),
                RTI_FALSE);
            if (sample->vehicle == NULL) {
                return RTI_FALSE;
            }
        }
    }

    if (allocParams->allocate_memory) {
        sample->trafficConditions = DDS_String_alloc(((POS_BUF_LEN)));
        RTICdrType_copyStringEx(
            &sample->trafficConditions,
            "",
            ((POS_BUF_LEN)),
            RTI_FALSE);
        if (sample->trafficConditions == NULL) {
            return RTI_FALSE;
        }
    } else {
        if (sample->trafficConditions != NULL) {
            RTICdrType_copyStringEx(
                &sample->trafficConditions,
                "",
                ((POS_BUF_LEN)),
                RTI_FALSE);
            if (sample->trafficConditions == NULL) {
                return RTI_FALSE;
            }
        }
    }

    sample->stopNumber = 0;

    sample->numStops = 0;

    sample->fillInRatio = 0;

    sample->timeBetweenStops = 0.0f;

    return RTI_TRUE;
}

RTIBool Position_finalize_w_return(
    Position* sample)
{
    Position_finalize_ex(sample, RTI_TRUE);

    return RTI_TRUE;
}

void Position_finalize(
    Position* sample)
{

    Position_finalize_ex(sample,RTI_TRUE);
}

void Position_finalize_ex(
    Position* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    Position_finalize_w_params(
        sample,&deallocParams);
}

void Position_finalize_w_params(
    Position* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

    if (sample->timestamp != NULL) {
        DDS_String_free(sample->timestamp);
        sample->timestamp=NULL;

    }
    if (sample->route != NULL) {
        DDS_String_free(sample->route);
        sample->route=NULL;

    }
    if (sample->vehicle != NULL) {
        DDS_String_free(sample->vehicle);
        sample->vehicle=NULL;

    }
    if (sample->trafficConditions != NULL) {
        DDS_String_free(sample->trafficConditions);
        sample->trafficConditions=NULL;

    }

}

void Position_finalize_optional_members(
    Position* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

}

RTIBool Position_copy(
    Position* dst,
    const Position* src)
{
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        if (!RTICdrType_copyStringEx (
            &dst->timestamp, src->timestamp, 
            ((POS_BUF_LEN)) + 1, RTI_FALSE)){
            return RTI_FALSE;
        }
        if (!RTICdrType_copyStringEx (
            &dst->route, src->route, 
            ((POS_BUF_LEN)) + 1, RTI_FALSE)){
            return RTI_FALSE;
        }
        if (!RTICdrType_copyStringEx (
            &dst->vehicle, src->vehicle, 
            ((POS_BUF_LEN)) + 1, RTI_FALSE)){
            return RTI_FALSE;
        }
        if (!RTICdrType_copyStringEx (
            &dst->trafficConditions, src->trafficConditions, 
            ((POS_BUF_LEN)) + 1, RTI_FALSE)){
            return RTI_FALSE;
        }
        if (!RTICdrType_copyLong (
            &dst->stopNumber, &src->stopNumber)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyLong (
            &dst->numStops, &src->numStops)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyLong (
            &dst->fillInRatio, &src->fillInRatio)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyFloat (
            &dst->timeBetweenStops, &src->timeBetweenStops)) { 
            return RTI_FALSE;
        }

        return RTI_TRUE;

    } catch (const std::bad_alloc&) {
        return RTI_FALSE;
    }
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'Position' sequence class.
*/
#define T Position
#define TSeq PositionSeq

#define T_initialize_w_params Position_initialize_w_params

#define T_finalize_w_params   Position_finalize_w_params
#define T_copy       Position_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#include "dds_cpp_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params

#undef T_initialize_w_params

#undef TSeq
#undef T

#ifndef NDDS_STANDALONE_TYPE
namespace rti { 
    namespace xcdr {
        const RTIXCdrTypeCode * type_code<Position>::get() 
        {
            return (const RTIXCdrTypeCode *) Position_get_typecode();
        }

    } 
}
#endif
