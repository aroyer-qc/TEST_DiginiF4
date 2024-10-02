//-------------------------------------------------------------------------------------------------
//
//  File : database_cfg.h
//
//-------------------------------------------------------------------------------------------------
//
// Copyright(c) 2020 Alain Royer.
// Email: aroyer.qc@gmail.com
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software
// and associated documentation files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
// INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
// AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
//-------------------------------------------------------------------------------------------------

#pragma once

//-------------------------------------------------------------------------------------------------
// Include file(s)
//-------------------------------------------------------------------------------------------------

#include "./Digini/Digini/inc/lib_label.h"
//#include "project_def.h"
//#include "./Digini/Digini/inc/lib_typedef.h"

//-------------------------------------------------------------------------------------------------
// Define(s)

//-------------------------------------------------------------------------------------------------

//....Items SubQTY              is TYPE Variable [][THIS]
//....Items QTY                 is TYPE Variable [THIS][]
//....Item Size                 Memory space reserve for the record

// There is 20 uint32_t backup register in the STM32F4
// Make sure the count are 20 register or less
// Size is fix at sizeof(uint32_t)
//                  Enum ID                 Items QTY,  Items SubQTY
#define BKPREG_DBASE_DEF(X_BKPREG_DBASE) \
    X_BKPREG_DBASE( TEST2,                  1,          1             )   \
    X_BKPREG_DBASE( TEST3,                  1,          1             )   \
    X_BKPREG_DBASE( TEST4,                  1,          1             )   \
    X_BKPREG_DBASE( TEST5,                  4,          4             )   \

/*
//                  Enum ID                  Driver,         Items QTY,        Items SubQTY     Item Size
#define EEPROM_DBASE_DEF(X_EEPROM_DBASE) \
    X_EEPROM_DBASE( SYSTEM_LANGUAGE,         myE2_Setting,   1,                1,               sizeof(Language_e)         ) \
    X_EEPROM_DBASE( SYSTEM_SERIAL_NUMBER,    myE2_Setting,   1,                1,               sizeof(OEM_SERIAL_NUMBER)  ) \
    X_EEPROM_DBASE( SYSTEM_DEBUG_LEVEL,      myE2_Setting,   1,                1,               sizeof(SystemDebugLevel_e) ) \
    X_EEPROM_DBASE( SYSTEM_TEMPERATURE_UNIT, myE2_Setting,   1,                1,               sizeof(TempUnit_e)         ) \
*/
//                Enum ID                 Items QTY,       Items SubQTY        Item Size               Get/Set Callback
#define HARD_DBASE_DEF(X_HARD_DBASE) \
    X_HARD_DBASE( REC_TIME,               1,               1,                  sizeof(Time_t),          AccessTime)              \
    X_HARD_DBASE( REC_DATE,               1,               1,                  sizeof(Date_t),          AccessDate)              \
    X_HARD_DBASE( REC_TIME_FORMAT,        1,               1,                  sizeof(TimeFormat_e),    AccessTimeFormat)        \

// FOR static location RAM BASE You must define RAM_BASE_ADDRESS and give address of your database of the RAM Region here (Ex. &ByteArray_Ram[x]
// FOR dynamic location RAM_BASE_ADDRESS is declare nullptr, you must then call set address to setup your dynamic RAM BASE location
//#define RAM_BASE_ADDRESS   nullptr

extern const TempUnit_e T_Unit;
extern const SystemDebugLevel_e DebugLvl;
extern const Language_e Lang;

//               Enum ID                    Item Address                     Items QTY,        Items SubQTY       Item Size
#define ROM_DBASE_DEF(X_ROM_DBASE) \
    X_ROM_DBASE( MODEL_NAME_TEXT,           &OEM_MODEL_NAME[0],              1,                1,                 sizeof(OEM_MODEL_NAME)              ) \
    X_ROM_DBASE( SERIAL_NUMBER_TEXT,        &OEM_SERIAL_NUMBER[0],           1,                1,                 sizeof(OEM_SERIAL_NUMBER)           ) \
    X_ROM_DBASE( FIRMWARE_NAME_TEXT,        &OUR_FIRMWARE_NAME[0],           1,                1,                 sizeof(OUR_FIRMWARE_NAME)           ) \
    X_ROM_DBASE( FIRMWARE_VERSION_TEXT,     &OUR_FIRMWARE_VERSION[0],        1,                1,                 sizeof(OUR_FIRMWARE_VERSION)        ) \
    X_ROM_DBASE( FW_DIGINI_NAME_TEXT,       &OUR_FIRMWARE_DIGINI_NAME[0],    1,                1,                 sizeof(OUR_FIRMWARE_DIGINI_NAME)    ) \
    X_ROM_DBASE( FW_DIGINI_VERSION_TEXT,    &OUR_FIRMWARE_DIGINI_VERSION[0], 1,                1,                 sizeof(OUR_FIRMWARE_DIGINI_VERSION) ) \
/* no eeprom at this time so we force the value */ \
    X_ROM_DBASE( SYSTEM_LANGUAGE,           &Lang,                           1,                1,                 sizeof(Language_e)                  ) \
    X_ROM_DBASE( SYSTEM_TEMPERATURE_UNIT,   &T_Unit,                         1,                1,                 sizeof(TempUnit_e)                  ) \
    X_ROM_DBASE( SYSTEM_DEBUG_LEVEL,        &DebugLvl,                       1,                1,                 sizeof(SystemDebugLevel_e)          ) \


