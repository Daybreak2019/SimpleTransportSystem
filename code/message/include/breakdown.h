

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from breakdown.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef breakdown_1458270261_h
#define breakdown_1458270261_h

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_cpp_h
#include "ndds/ndds_cpp.h"
#endif
#include "rti/xcdr/Interpreter.hpp"
#else
#include "ndds_standalone_type.h"
#endif

extern "C" {

    extern const char *BreakdownTYPENAME;

}

struct BreakdownSeq;
#ifndef NDDS_STANDALONE_TYPE
class BreakdownTypeSupport;
class BreakdownDataWriter;
class BreakdownDataReader;
#endif
class Breakdown 
{
  public:
    typedef struct BreakdownSeq Seq;
    #ifndef NDDS_STANDALONE_TYPE
    typedef BreakdownTypeSupport TypeSupport;
    typedef BreakdownDataWriter DataWriter;
    typedef BreakdownDataReader DataReader;
    #endif

    DDS_Char *   timestamp ;
    DDS_Char *   route ;
    DDS_Char *   vehicle ;
    DDS_Long   stopNumber ;

};
#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#ifndef NDDS_STANDALONE_TYPE
NDDSUSERDllExport DDS_TypeCode* Breakdown_get_typecode(void); /* Type code */
NDDSUSERDllExport RTIXCdrTypePlugin *Breakdown_get_type_plugin_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *Breakdown_get_sample_access_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *Breakdown_get_sample_seq_access_info(void);
#endif

DDS_SEQUENCE(BreakdownSeq, Breakdown);

NDDSUSERDllExport
RTIBool Breakdown_initialize(
    Breakdown* self);

NDDSUSERDllExport
RTIBool Breakdown_initialize_ex(
    Breakdown* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool Breakdown_initialize_w_params(
    Breakdown* self,
    const struct DDS_TypeAllocationParams_t * allocParams);  

NDDSUSERDllExport
RTIBool Breakdown_finalize_w_return(
    Breakdown* self);

NDDSUSERDllExport
void Breakdown_finalize(
    Breakdown* self);

NDDSUSERDllExport
void Breakdown_finalize_ex(
    Breakdown* self,RTIBool deletePointers);

NDDSUSERDllExport
void Breakdown_finalize_w_params(
    Breakdown* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void Breakdown_finalize_optional_members(
    Breakdown* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool Breakdown_copy(
    Breakdown* dst,
    const Breakdown* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#ifndef NDDS_STANDALONE_TYPE
namespace rti { 
    namespace xcdr {
        template <>
        struct type_code<Breakdown> {
            static const RTIXCdrTypeCode * get();
        };

    } 
}

#endif

#endif /* breakdown */

