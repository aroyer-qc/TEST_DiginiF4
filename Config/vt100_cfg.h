//-------------------------------------------------------------------------------------------------
//
//  File :  vt100_cfg.h
//
//-------------------------------------------------------------------------------------------------
//
// Copyright(c) 2021 Alain Royer.
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
// Define(s)
//-------------------------------------------------------------------------------------------------

#define VT100_STARTUP_MENU_CFG                  MenuMain

#define VT100_USE_COLOR                         DEF_ENABLED
#define VT100_USER_CALLBACK_INITIALIZE          DEF_DISABLED

// Only one of those define can be used or none of them
#define VT100_USE_STANDARD_MENU_STATIC_INFO     DEF_ENABLED             // VT100 Class provide its own header. then enable this if it is desire.
#define VT100_USE_USER_MENU_STATIC_INFO         DEF_DISABLED            // If user wish to create his own header or special formatting.

// TODO move label use by digini internal menu into digini lib_vt100_label.h
// in fact I should move every configuration for menu item and menu built-in Digini to the digini itself

#define VT100_USER_LABEL_LANGUAGE_DEF(X_VT100_USER_LBL_CFG) \
    X_VT100_USER_LBL_CFG( VT100_LBL_MENU_TITLE,                       "Test F4 Menu",                                             "Menu Test F4"                                               ) \
    X_VT100_USER_LBL_CFG( VT100_LBL_TEST,                             "Test",                                                     "Test"                                                       ) \
    X_VT100_USER_LBL_CFG( VT100_LBL_MISCELLEANEOUS,                   "Miscelleaneous",                                           "Divers"                                                     ) \
    X_VT100_USER_LBL_CFG( VT100_LBL_SYSTEM_SETTING,                   "System Settings",                                          "Configuration Syst\x8ame"                                   ) \
    X_VT100_USER_LBL_CFG( VT100_LBL_SYSTEM_SETTING_MENU,              "System Settings Menu",                                     "Menu Configuration Syst\x8ame"                              ) \
    X_VT100_USER_LBL_CFG( VT100_LBL_MISC_CONFIG_MENU,                 "Miscellaneous Configuration Menu",                         "Menu de Configuration Divers"                               ) \
    X_VT100_USER_LBL_CFG( VT100_LBL_TIME_AND_DATE,                    "Time and Date",                                            "Heure et Date"                                              ) \
    X_VT100_USER_LBL_CFG( VT100_LBL_TIME_AND_DATE_CONFIGURATION,      "Time and Date Configuration",                              "Configuration Heure et Date"                                ) \
    X_VT100_USER_LBL_CFG( VT100_LBL_SERIAL_NUMBER_SETTING,            "Setting Serial Number",                                    "Configurer Num\x82ro de S\x82rie"                           ) \
    X_VT100_USER_LBL_CFG( VT100_LBL_SELECT_LANGUAGE,                  "Toggle Language:",                                         "Basculer de Langage:"                                       ) \
    X_VT100_USER_LBL_CFG( VT100_LBL_LANGUAGE_SELECTION,               "Choose Language:  English ( )  French   ( )",              "Choisir Langage:  Anglais ( )  Fran\x87" "ais ( )"          ) \
    X_VT100_USER_LBL_CFG( VT100_LBL_TEMPERATURE_UNIT_SELECTION,       "Choose Temp Unit:      \xF8" "C ( )        \xF8" "F ( )",  "Choisir Unit\x82 Temp:    \xF8" "C ( )        \xF8" "F ( )" ) \


// Define the compare name (I did not find a way to get rid of those definition by the use of advanced macro)
#define COMPARE_MenuRedirection(x)      x
#define COMPARE_MenuBoot(x)    		    x
#define COMPARE_MenuSystemSetting(x)    x


#define COMPARE_MenuMain(x) 		    x
#define COMPARE_MenuInfo(x)    		    x
#define COMPARE_MenuStackUsage(x)       x
#define COMPARE_MenuNetwork(x)          x
#define COMPARE_MenuDebug(x)    	    x
#define COMPARE_MenuSD_Card(x)     	    x

//#define COMPARE_MenuTest(x)     	    x
//#define COMPARE_MenuSetting(x)	    x
//#define COMPARE_MenuSettingTime(x)    x

// Define here all the menu and sub menu you will use in the VT100 terminal
#define VT100_MENU_DEF(ENTRY)        \
                                                ENTRY(MenuMain           )  \
    IF_USE( LABEL_USE_PRODUCT_INFO,             ENTRY(MenuInfo           ) )\
    IF_USE( DIGINI_USE_STACKTISTIC,             ENTRY(MenuStackUsage     ) )\
    IF_USE( DIGINI_USE_STATIC_MEMORY_ALLOC,     ENTRY(MenuMemoryPool     ) )\
    IF_USE( DIGINI_USE_DEBUG_IN_CONSOLE,        ENTRY(MenuDebug          ) )\
    IF_USE( DIGINI_USE_ETHERNET,                ENTRY(MenuNetwork        ) )\
    IF_USE( DIGINI_DEBUG_SDCARD_INFO_ON_VT100,  ENTRY(MenuSD_Card        ) )\
                                                ENTRY(MenuSystemSetting  )  \

// Those are not used at this time
#define VT100_MENU_DEF_NU(ENTRY)\
                                 ENTRY(MenuSetting        )  \
                                 ENTRY(MenuSetMisc        )  \
                                 ENTRY(MenuTest1          )  \

// Define here all the callback you will use in the VT100 terminal
#define VT100_CALLBACK(ENTRY)\
                                               ENTRY(CALLBACK_MenuMain           )  \
    IF_USE( LABEL_USE_PRODUCT_INFO,            ENTRY(CALLBACK_ProductInformation ) )\
    IF_USE( DIGINI_USE_STACKTISTIC,            ENTRY(CALLBACK_StackUsage         ) )\
    IF_USE( DIGINI_USE_STATIC_MEMORY_ALLOC,    ENTRY(CALLBACK_MemoryPool         ) )\
    IF_USE( DIGINI_USE_DEBUG_IN_CONSOLE,       ENTRY(CALLBACK_DebugLevelSetting  ) )\
    IF_USE( DIGINI_USE_ETHERNET,               ENTRY(CALLBACK_NetworkInfo        ) )\
    IF_USE( DIGINI_DEBUG_SDCARD_INFO_ON_VT100, ENTRY(CALLBACK_SD_CardInformation ) )\
                                               ENTRY(CALLBACK_SystemSetting      )  \

//                                               ENTRY(CALLBACK_TimeDateCfg        )  
//                                               ENTRY(CALLBACK_InputReading       )  

// Here you define how you will navigate in the menu tree and action associated with them                            1st item of a menu                       1st item
//                                                  Menu   Member Of            Item ID                              CALLBACK for refresh                     Navigate to this menu on <ESC>    Label ID
//                                                                              on first if CALLBACK_None there is
//                                                                              no refresh. All other items are      all other. Navigate to this menu         all other. Navigate to the menu
//                                                                              items processing services.
#define VT100_MENU_TREE_DEF(ENTRY, MENU) \
\
                                            ENTRY  (MENU,  MenuMain,            ID_MAIN_TITLE,                       CALLBACK_None,                           VT100_MENU_NONE,                  VT100_LBL_MAIN_MENU                             )  \
    IF_USE( LABEL_USE_PRODUCT_INFO,         ENTRY  (MENU,  MenuMain,            ID_INFO_DISPLAY,                     CALLBACK_ProductInformation,             MenuInfo,                         VT100_LBL_SYSTEM_INFO                           ) )\
    IF_USE( DIGINI_USE_STACKTISTIC,         ENTRY  (MENU,  MenuMain,            ID_STACK_DISPLAY,                    CALLBACK_None,                           MenuStackUsage,                   VT100_LBL_STACKTISTIC                           ) )\
    IF_USE( DIGINI_USE_DEBUG_IN_CONSOLE,    ENTRY  (MENU,  MenuMain,            ID_DEBUG_MENU,                       CALLBACK_None,                           MenuDebug,                        VT100_LBL_DEBUG                                 ) )\
    IF_USE( DIGINI_USE_STATIC_MEMORY_ALLOC, ENTRY  (MENU,  MenuMain,            ID_MEMORY_POOL_MENU,                 CALLBACK_None,                           MenuMemoryPool,                   VT100_LBL_MEMORY_POOL_STAT                      ) )\
    IF_USE( DIGINI_USE_ETHERNET,            ENTRY  (MENU,  MenuMain,            ID_NETWORK_INFO,                     CALLBACK_None,                           MenuNetwork,                      LBL_NETWORK_INFO                                ) )\
                                            ENTRY  (MENU,  MenuMain,            ID_SYSTEM_SETTING_MENU,              CALLBACK_None,                           MenuSystemSetting,                VT100_LBL_SYSTEM_SETTING                        )  \
\
    IF_USE( LABEL_USE_PRODUCT_INFO,         ENTRY  (MENU,  MenuInfo,            ID_INFO_SYSTEM,                      CALLBACK_ProductInformation,             MenuMain,                         VT100_LBL_SYSTEM_INFO                           ) )\
\
    IF_USE( DIGINI_USE_STACKTISTIC,         ENTRY  (MENU,  MenuStackUsage,      ID_INFO_DISPLAY,                     CALLBACK_StackUsage,                     MenuMain,                         VT100_LBL_STACKTISTIC                           ) )\
\
    IF_USE( DIGINI_USE_STATIC_MEMORY_ALLOC, ENTRY  (MENU,  MenuMemoryPool,      ID_MEM_POOL_STATS,                   CALLBACK_MemoryPool,                     MenuMain,                         VT100_LBL_MEMORY_POOL_STAT                      ) )\
\
                                            ENTRY  (MENU,  MenuSystemSetting,   ID_SYSTEM_SETTING,                   CALLBACK_SystemSetting,                  MenuMain,                         VT100_LBL_SYSTEM_SETTING                        )  \
                                            ENTRY  (MENU,  MenuSystemSetting,   ID_SYSTEM_LANGUAGE,                  CALLBACK_SystemSetting,                  MenuSystemSetting,                VT100_LBL_LANGUAGE_SELECTION                    )  \
                                            ENTRY  (MENU,  MenuSystemSetting,   ID_MISC_SERIAL_NUMBER,               CALLBACK_SystemSetting,                  MenuSystemSetting,                VT100_LBL_SERIAL_NUMBER_SETTING                 )  \
                                            ENTRY  (MENU,  MenuSystemSetting,   ID_MISC_TEMPERATURE_UNIT,            CALLBACK_SystemSetting,                  MenuSystemSetting,                VT100_LBL_TEMPERATURE_UNIT_SELECTION            )  \
                                            ENTRY  (MENU,  MenuSystemSetting,   ID_MISC_SAVE,                        CALLBACK_SystemSetting,                  MenuSystemSetting,                VT100_LBL_SAVE_CONFIGURATION                    )  \
\
    IF_USE( DIGINI_USE_DEBUG_IN_CONSOLE, \
                                            ENTRY  (MENU,  MenuDebug,           ID_DEBUG_TITLE,                      CALLBACK_DebugLevelSetting,              MenuMain,                         VT100_LBL_DEBUG_MENU                            )  \
                                            ENTRY  (MENU,  MenuDebug,           ID_DBG_LVL_0,                        CALLBACK_DebugLevelSetting,              MenuDebug,                        LBL_DEBUG_LEVEL_1                               )  \
                                            ENTRY  (MENU,  MenuDebug,           ID_DBG_LVL_1,                        CALLBACK_DebugLevelSetting,              MenuDebug,                        LBL_DEBUG_LEVEL_2                               )  \
                                            ENTRY  (MENU,  MenuDebug,           ID_DBG_LVL_2,                        CALLBACK_DebugLevelSetting,              MenuDebug,                        LBL_DEBUG_LEVEL_3                               )  \
                                            ENTRY  (MENU,  MenuDebug,           ID_DBG_LVL_3,                        CALLBACK_DebugLevelSetting,              MenuDebug,                        LBL_DEBUG_LEVEL_4                               )  \
                                            ENTRY  (MENU,  MenuDebug,           ID_DBG_LVL_4,                        CALLBACK_DebugLevelSetting,              MenuDebug,                        LBL_DEBUG_LEVEL_5                               )  \
                                            ENTRY  (MENU,  MenuDebug,           ID_DBG_LVL_5,                        CALLBACK_DebugLevelSetting,              MenuDebug,                        LBL_DEBUG_LEVEL_6                               )  \
                                            ENTRY  (MENU,  MenuDebug,           ID_DBG_LVL_6,                        CALLBACK_DebugLevelSetting,              MenuDebug,                        LBL_DEBUG_LEVEL_7                               )  \
                                            ENTRY  (MENU,  MenuDebug,           ID_DBG_LVL_7,                        CALLBACK_DebugLevelSetting,              MenuDebug,                        LBL_DEBUG_LEVEL_8                               )  \
                                            ENTRY  (MENU,  MenuDebug,           ID_DBG_LVL_8,                        CALLBACK_DebugLevelSetting,              MenuDebug,                        LBL_DEBUG_LEVEL_9                               )  \
                                            ENTRY  (MENU,  MenuDebug,           ID_DBG_LVL_9,                        CALLBACK_DebugLevelSetting,              MenuDebug,                        LBL_DEBUG_LEVEL_10                              )  \
                                            ENTRY  (MENU,  MenuDebug,           ID_DBG_LVL_A,                        CALLBACK_DebugLevelSetting,              MenuDebug,                        LBL_DEBUG_LEVEL_11                              )  \
                                            ENTRY  (MENU,  MenuDebug,           ID_DBG_LVL_B,                        CALLBACK_DebugLevelSetting,              MenuDebug,                        LBL_DEBUG_LEVEL_12                              )  \
                                            ENTRY  (MENU,  MenuDebug,           ID_DBG_LVL_C,                        CALLBACK_DebugLevelSetting,              MenuDebug,                        LBL_DEBUG_LEVEL_13                              )  \
                                            ENTRY  (MENU,  MenuDebug,           ID_DBG_LVL_D,                        CALLBACK_DebugLevelSetting,              MenuDebug,                        LBL_DEBUG_LEVEL_14                              )  \
                                            ENTRY  (MENU,  MenuDebug,           ID_DBG_LVL_E,                        CALLBACK_DebugLevelSetting,              MenuDebug,                        LBL_DEBUG_LEVEL_15                              )  \
                                            ENTRY  (MENU,  MenuDebug,           ID_DBG_LVL_F,                        CALLBACK_DebugLevelSetting,              MenuDebug,                        LBL_DEBUG_LEVEL_16                              )  \
    ) \
\
    IF_USE( DIGINI_USE_ETHERNET,            ENTRY  (MENU,  MenuNetwork,         ID_NETWORK_INFO,                     CALLBACK_NetworkInfo,                    MenuMain,                         LBL_NETWORK_INFO                                ) )\
\

// ------------------------------------------------------------------------------------------------------------------

#define NOT_USED\
                                 ENTRY  (MENU,  MenuMain,          ID_TEST_MENU,                       CALLBACK_None,                         MenuTest1,                        VT100_LBL_TEST                                  )  \
                                 ENTRY  (MENU,  MenuMain,          ID_SETTING_MENU,                    CALLBACK_None,                         MenuSetting,                      VT100_LBL_SYSTEM_SETTING                        )  \
                                 ENTRY  (MENU,  MenuBoot,          ID_TEST_MENU,                       CALLBACK_None,                         MenuTest1,                        VT100_LBL_TEST                                  )  \
                                 ENTRY  (MENU,  MenuBoot,          ID_SETTING_MENU,                    CALLBACK_None,                         MenuSetting,                      VT100_LBL_SYSTEM_SETTING                        )  \
\
                                 ENTRY  (MENU,  MenuSetMisc,       ID_MISC_TITLE,                      CALLBACK_None,                         MenuSetting,                      VT100_LBL_MISC_CONFIG_MENU                      ) \
                                 ENTRY  (MENU,  MenuSetMisc,       ID_MISC_OPT1,                       CALLBACK_MiscCfg,                      MenuSetMisc,                      VT100_LBL_BLANK                                 ) \
                                 ENTRY  (MENU,  MenuSetMisc,       ID_MISC_OPT2,                       CALLBACK_MiscCfg,                      MenuSetMisc,                      VT100_LBL_BLANK                                 ) \
                                 ENTRY  (MENU,  MenuSetMisc,       ID_MISC_SERIAL_NUMBER,              CALLBACK_MiscCfg,                      MenuSetMisc,                      VT100_LBL_SERIAL_NUMBER_SETTING                 ) \
                                 ENTRY  (MENU,  MenuSetMisc,       ID_MISC_SAVE,                       CALLBACK_MiscCfg,                      MenuSetMisc,                      VT100_LBL_BLANK                                 ) \
\
		                         ENTRY  (MENU,  MenuSettingTime,   ID_TIME_DATE_TITLE,                 CALLBACK_None,                         MenuSetting,                      VT100_LBL_TIME_AND_DATE_CONFIGURATION           ) \
                                 ENTRY  (MENU,  MenuSettingTime,   ID_HOUR,                            CALLBACK_TimeDateCfg,                  MenuSettingTime,                  LBL_MINUTE                                      ) \
                                 ENTRY  (MENU,  MenuSettingTime,   ID_SECOND,                          CALLBACK_TimeDateCfg,                  MenuSettingTime,                  LBL_SECOND                                      ) \
                                 ENTRY  (MENU,  MenuSettingTime,   ID_DAY,                             CALLBACK_TimeDateCfg,                  MenuSettingTime,                  LBL_MONTH                                       ) \
                                 ENTRY  (MENU,  MenuSettingTime,   ID_YEAR,                            CALLBACK_TimeDateCfg,                  MenuSettingTime,                  LBL_YEAR                                        ) \
                                 ENTRY  (MENU,  MenuSettingTime,   ID_TIME_DATE_SAVE,                  CALLBACK_TimeDateCfg,                  MenuSettingTime,                  VT100_LBL_BLANK                                 ) \
\
                                 ENTRY  (MENU,  MenuSetting,       ID_SETTING_TITLE,                   CALLBACK_None,                         MenuMain,                         VT100_LBL_SYSTEM_SETTING_MENU                   ) \
                                 ENTRY  (MENU,  MenuSetting,       ID_MISC_MENU,                       CALLBACK_None,                         MenuSetMisc,                      VT100_LBL_MISCELLEANEOUS                        ) \
                                 ENTRY  (MENU,  MenuSetting,       ID_TIME_MENU,                       CALLBACK_None,                         MenuSettingTime,                  VT100_LBL_TIME_AND_DATE                         ) \

// ------------------------------------------------------------------------------------------------------------------
























