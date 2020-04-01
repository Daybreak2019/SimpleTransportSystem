

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from accident.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef accident_63819894_h
#define accident_63819894_h

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_cpp_h
#include "ndds/ndds_cpp.h"
#endif
#include "rti/xcdr/Interpreter.hpp"
#else
#include "ndds_standalone_type.h"
#endif

extern "C" {

    extern const char *AccidentTYPENAME;

}

struct AccidentSeq;
#ifndef NDDS_STANDALONE_TYPE
class AccidentTypeSupport;
class AccidentDataWriter;
class AccidentDataReader;
#endif
class Accident 
{
  public:
    typedef struct AccidentSeq Seq;
    #ifndef NDDS_STANDALONE_TYPE
    typedef AccidentTypeSupport TypeSupport;
    typedef AccidentDataWriter DataWriter;
    typedef AccidentDataReader DataReader;
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
NDDSUSERDllExport DDS_TypeCode* Accident_get_typecode(void); /* Type code */
NDDSUSERDllExport RTIXCdrTypePlugin *Accident_get_type_plugin_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *Accident_get_sample_access_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *Accident_get_sample_seq_access_info(void);
#endif

DDS_SEQUENCE(AccidentSeq, Accident);

NDDSUSERDllExport
RTIBool Accident_initialize(
    Accident* self);

NDDSUSERDllExport
RTIBool Accident_initialize_ex(
    Accident* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool Accident_initialize_w_params(
    Accident* self,
    const struct DDS_TypeAllocationParams_t * allocParams);  

NDDSUSERDllExport
RTIBool Accident_finalize_w_return(
    Accident* self);

NDDSUSERDllExport
void Accident_finalize(
    Accident* self);

NDDSUSERDllExport
void Accident_finalize_ex(
    Accident* self,RTIBool deletePointers);

NDDSUSERDllExport
void Accident_finalize_w_params(
    Accident* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void Accident_finalize_optional_members(
    Accident* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool Accident_copy(
    Accident* dst,
    const Accident* src);

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
        struct type_code<Accident> {
            static const RTIXCdrTypeCode * get();
        };

    } 
}

#endif

#endif /* accident */

