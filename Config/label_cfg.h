//-------------------------------------------------------------------------------------------------
//
//  File :  label_cfg.h
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
// Define(s)
//-------------------------------------------------------------------------------------------------

// Notes some default label exist in the file "lib_label.h", some of them can be enable/disable in this configuratio

#define     LABEL_USE_DATE                      DEF_ENABLED
#define     LABEL_USE_TIME                      DEF_ENABLED
#define     LABEL_USE_PRODUCT_INFO              DEF_ENABLED
#define     LABEL_USE_DECIMAL_KEY               DEF_DISABLED            // Enable label 0-9 and dot, del, sign, sign inversion
#define     LABEL_USE_HEXADECIMAL_KEY           DEF_DISABLED            // Enable label A-F

// That is completely wrong here !! most of it is not used!!!

#define LABEL_LANGUAGE_DEF(X_LBL_CFG) \

#if 0

    X_LBL_CFG( LBL_TEST_MENU,             "    Test Menu\r\n",                                                                                         "    Menu Des Tests\r\n"                ) \
    X_LBL_CFG( LBL_TEST_OPT1,             "LED Control\r\n",                                                                                           "Contrôle LEDs\r\n"                     ) \
    X_LBL_CFG( LBL_TEST_OPT2,             "poutine Control\r\n",                                                                                       "Contrôle Poutine\r\n"                  ) \
    X_LBL_CFG( LBL_TEST_OPT4,             "Input Reading And Sensor\r\n",                                                                              "Lecture D'Entrée et Capteur"           ) \
    X_LBL_CFG( LBL_TEST_OPT5,             "Bluetooth\r\n",                                                                                             nullptr                                 ) \
\
    X_LBL_CFG( LBL_LED_MENU,              "    LED Control Menu\r\n",                                                                                  "    Menu Contrôle LEDs\r\n"            ) \
    X_LBL_CFG( LBL_LED_OPT1,              "Toggle LED Status          ( )\r\n",                                                                        "Basculer LED Statut\r\n"               ) \
    X_LBL_CFG( LBL_LED_OPT2,              "Toggle LED Power           ( )\r\n",                                                                        "Basculer LED Power\r\n"                ) \
    X_LBL_CFG( LBL_LED_OPT3,              "Toggle LED Bluetooth       ( )\r\n",                                                                        "Basculer LED Bluetooth\r\n"            ) \
\
    X_LBL_CFG( LBL_SETTING_MENU,          "    System Settings Menu\r\n",                                                                              "    Menu Réglage Système\r\n"          ) \
    X_LBL_CFG( LBL_SETTING_OPT1,          "Time and Date\r\n",                                                                                         "Heure et Date\r\n"                     ) \
\

#endif

//-------------------------------------------------------------------------------------------------
