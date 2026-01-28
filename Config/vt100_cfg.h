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

#define VT100_SCREEN_WIDTH						132

#define VT100_STARTUP_MENU_CFG                  MenuMain                // User can choose another menu startup entry for VT100.
#define VT100_MENU_MAIN_FALLBACK_CFG            VT100_MENU_NONE         // if you change the VT100_STARTUP_MENU_CFG to other menu, put the name of the menu here. Otherwisweit will exit the VT100 menu system.
#define VT100_USE_COLOR                         DEF_ENABLED
#define VT100_USER_CALLBACK_INITIALIZE          DEF_DISABLED
#define VT100_USE_LOG_WINDOW                    DEF_ENABLED

// Only one of those define can be used or none of them
#define VT100_USE_STANDARD_MENU_STATIC_INFO     DEF_ENABLED             // VT100 Class provide its own header. then enable this if it is desire.
#define VT100_USE_USER_MENU_STATIC_INFO         DEF_DISABLED            // If user wish to create his own header or special formatting.

// Configuration option in menu system, choose the one you want
#define VT100_USE_LANGUAGE_SELECTION            DEF_ENABLED
#define VT100_USE_TEMPERATURE_SELECTION         DEF_ENABLED
#define VT100_USE_SERIAL_NUMBER_SETTING         DEF_ENABLED
#define VT100_USE_TIME_AND_DATE_SETTING         DEF_ENABLED

// TODO move label use by digini internal menu into digini lib_vt100_label.h
// in fact I should move every configuration for menu item and menu built-in Digini to the digini itself

#define VT100_USER_LABEL_LANGUAGE_DEF(X_VT100_USER_LBL_CFG) \
    X_VT100_USER_LBL_CFG( VT100_LBL_MENU_TITLE,                       "Test F4 Menu",                                             "Menu Test F4"                                               ) \
    X_VT100_USER_LBL_CFG( VT100_LBL_TEST,                             "Test",                                                     "Test"                                                       ) \
    X_VT100_USER_LBL_CFG( VT100_LBL_MISCELLEANEOUS,                   "Miscelleaneous",                                           "Divers"                                                     ) \
    X_VT100_USER_LBL_CFG( VT100_LBL_SYSTEM_SETTING,                   "System Settings",                                          "Configuration Syst\x8ame"                                   ) \
    X_VT100_USER_LBL_CFG( VT100_LBL_SYSTEM_SETTING_MENU,              "System Settings Menu",                                     "Menu Configuration Syst\x8ame"                              ) \
    X_VT100_USER_LBL_CFG( VT100_LBL_MISC_CONFIG_MENU,                 "Miscellaneous Configuration Menu",                         "Menu de Configuration Divers"                               ) \


// Define the compare name (I did not find a way to get rid of those definition by the use of advanced macro)
// example #define COMPARE_MenuSystemSetting(x)    x

// Define here all the menu and sub menu you will use in the VT100 terminal
#define VT100_USER_MENU_DEF(ENTRY) \
//Example    ENTRY(MenuSystemSetting  )

// Define here all the callback you will use in the VT100 terminal
#define VT100_USER_CALLBACK(ENTRY) \
// example   ENTRY(CALLBACK_SystemSetting )

// Here you define how you will navigate in the menu tree and action associated with them                            1st item of a menu                       1st item
//                                                  Menu   Member Of            Item ID                              CALLBACK for refresh                     Navigate to this menu on <ESC>    Label ID
//                                                                              on first if CALLBACK_None there is
//                                                                              no refresh. All other items are      all other. Navigate to this menu         all other. Navigate to the menu
//                                                                              items processing services.
#define VT100_USER_MENU_TREE_DEF(ENTRY, MENU) \
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
		                         ENTRY  (MENU,  MenuSettingTime,   ID_TIME_DATE_TITLE,                 CALLBACK_None,                         MenuSetting,                      VT100_LBL_TIME_AND_DATE_CONFIG                  ) \
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
























