

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from position.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef position_32923552_h
#define position_32923552_h

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_cpp_h
#include "ndds/ndds_cpp.h"
#endif
#include "rti/xcdr/Interpreter.hpp"
#else
#include "ndds_standalone_type.h"
#endif

extern "C" {

    extern const char *PositionTYPENAME;

}

struct PositionSeq;
#ifndef NDDS_STANDALONE_TYPE
class PositionTypeSupport;
class PositionDataWriter;
class PositionDataReader;
#endif
class Position 
{
  public:
    typedef struct PositionSeq Seq;
    #ifndef NDDS_STANDALONE_TYPE
    typedef PositionTypeSupport TypeSupport;
    typedef PositionDataWriter DataWriter;
    typedef PositionDataReader DataReader;
    #endif

    DDS_Char *   timestamp ;
    DDS_Char *   route ;
    DDS_Char *   vehicle ;
    DDS_Long   stopNumber ;
    DDS_Long   numStops ;
    DDS_Long   timeBetweenStops ;
    DDS_Char *   trafficConditions ;
    DDS_Long   fillInRatio ;

};
#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#ifndef NDDS_STANDALONE_TYPE
NDDSUSERDllExport DDS_TypeCode* Position_get_typecode(void); /* Type code */
NDDSUSERDllExport RTIXCdrTypePlugin *Position_get_type_plugin_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *Position_get_sample_access_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *Position_get_sample_seq_access_info(void);
#endif

DDS_SEQUENCE(PositionSeq, Position);

NDDSUSERDllExport
RTIBool Position_initialize(
    Position* self);

NDDSUSERDllExport
RTIBool Position_initialize_ex(
    Position* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool Position_initialize_w_params(
    Position* self,
    const struct DDS_TypeAllocationParams_t * allocParams);  

NDDSUSERDllExport
RTIBool Position_finalize_w_return(
    Position* self);

NDDSUSERDllExport
void Position_finalize(
    Position* self);

NDDSUSERDllExport
void Position_finalize_ex(
    Position* self,RTIBool deletePointers);

NDDSUSERDllExport
void Position_finalize_w_params(
    Position* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void Position_finalize_optional_members(
    Position* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool Position_copy(
    Position* dst,
    const Position* src);

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
        struct type_code<Position> {
            static const RTIXCdrTypeCode * get();
        };

    } 
}

#endif

#endif /* position */

