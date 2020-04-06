//#############################################################################
//# Author: Wen Li
//# Date  : 3/31/2020
//# Description: common macro define
//##############################################################################
#ifndef _MACRO_H_
#define _MACRO_H_ 
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <iostream>
#include <assert.h>


#define RT_SUCCESS          (0)
#define RT_FAIL             (1)


/////////////////////////////////////////////////////////////////////////////////
#define KNRM  "\x1B[1;0m"
#define KRED  "\x1B[1;31m"
#define KYEL  "\x1B[1;33m"
#define KBLU  "\x1B[1;34m"

#define ErrMsg(msg)   (std::string(KRED) + std::string(msg) + std::string(KNRM))
#define WarnMsg(msg)  (std::string(KYEL) + std::string(msg) + std::string(KNRM))
#define LightMsg(msg) (std::string(KBLU) + std::string(msg) + std::string(KNRM))
/////////////////////////////////////////////////////////////////////////////////

#define VEHICLE_ROUND_TIMES      (3)

#define VEHICLE_ST_IDLE          (0)
#define VEHICLE_ST_USE           (1)
#define VEHICLE_ST_ACC           (2)
#define VEHICLE_ST_BRK           (3)
#define VEHICLE_ST_DEAD          (4)


#define VEHICLE_BRK_TIME         (20)


#define SEC_TO_NSEC              (1000000000)


#define MESSAGE_TOPIC_ACCIDENT   ("P3564_EECS_WenLi: PT/ALR/ACC")
#define MESSAGE_TOPIC_POSITION   ("P3564_EECS_WenLi: PT/POS")
#define MESSAGE_TOPIC_BREAKDOWN  ("P3564_EECS_WenLi: PT/ALR/BRK")



#endif
