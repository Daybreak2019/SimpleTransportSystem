
/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from breakdown.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#include "breakdownSupport.h"
#include "breakdownPlugin.h"

#ifndef dds_c_log_impl_h              
#include "dds_c/dds_c_log_impl.h"                                
#endif        

/* ========================================================================= */
/**
<<IMPLEMENTATION>>

Defines:   TData,
TDataWriter,
TDataReader,
TTypeSupport

Configure and implement 'Breakdown' support classes.

Note: Only the #defined classes get defined
*/

/* ----------------------------------------------------------------- */
/* DDSDataWriter
*/

/**
<<IMPLEMENTATION >>

Defines:   TDataWriter, TData
*/

/* Requires */
#define TTYPENAME   BreakdownTYPENAME

/* Defines */
#define TDataWriter BreakdownDataWriter
#define TData       Breakdown

#define ENABLE_TDATAWRITER_DATA_CONSTRUCTOR_METHODS
#include "dds_cpp/generic/dds_cpp_data_TDataWriter.gen"
#undef ENABLE_TDATAWRITER_DATA_CONSTRUCTOR_METHODS

#undef TDataWriter
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* DDSDataReader
*/

/**
<<IMPLEMENTATION >>

Defines:   TDataReader, TDataSeq, TData
*/

/* Requires */
#define TTYPENAME   BreakdownTYPENAME

/* Defines */
#define TDataReader BreakdownDataReader
#define TDataSeq    BreakdownSeq
#define TData       Breakdown

#define ENABLE_TDATAREADER_DATA_CONSISTENCY_CHECK_METHOD
#include "dds_cpp/generic/dds_cpp_data_TDataReader.gen"
#undef ENABLE_TDATAREADER_DATA_CONSISTENCY_CHECK_METHOD

#undef TDataReader
#undef TDataSeq
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* TypeSupport

<<IMPLEMENTATION >>

Requires:  TTYPENAME,
TPlugin_new
TPlugin_delete
Defines:   TTypeSupport, TData, TDataReader, TDataWriter
*/

/* Requires */
#define TTYPENAME    BreakdownTYPENAME
#define TPlugin_new  BreakdownPlugin_new
#define TPlugin_delete  BreakdownPlugin_delete

/* Defines */
#define TTypeSupport BreakdownTypeSupport
#define TData        Breakdown
#define TDataReader  BreakdownDataReader
#define TDataWriter  BreakdownDataWriter
#define TGENERATE_SER_CODE
#ifndef NDDS_STANDALONE_TYPE
#define TGENERATE_TYPECODE
#endif

#include "dds_cpp/generic/dds_cpp_data_TTypeSupport.gen"

#undef TTypeSupport
#undef TData
#undef TDataReader
#undef TDataWriter
#ifndef NDDS_STANDALONE_TYPE
#undef TGENERATE_TYPECODE
#endif
#undef TGENERATE_SER_CODE
#undef TTYPENAME
#undef TPlugin_new
#undef TPlugin_delete

