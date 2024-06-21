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

// Notes some default label exist in the file "lib_label.h"

#define     LABEL_USE_TIME_AND_DATE             DEF_ENABLED
#define     LABEL_USE_PRODUCT_INFO              DEF_ENABLED

#define LABEL_LANGUAGE_DEF(X_LBL_CFG) \
    X_LBL_CFG( LBL_OK,                    "Ok",                                                                                                        nullptr                                 ) \
    X_LBL_CFG( LBL_PERCENT,               "%2d",                                                                                                       nullptr                                 ) \
    X_LBL_CFG( LBL_1,                     "1",                                                                                                         nullptr                                 ) \
    X_LBL_CFG( LBL_2,                     "2",                                                                                                         nullptr                                 ) \
    X_LBL_CFG( LBL_3,                     "3",                                                                                                         nullptr                                 ) \
    X_LBL_CFG( LBL_4,                     "4",                                                                                                         nullptr                                 ) \
    X_LBL_CFG( LBL_5,                     "5",                                                                                                         nullptr                                 ) \
    X_LBL_CFG( LBL_6,                     "6",                                                                                                         nullptr                                 ) \
    X_LBL_CFG( LBL_7,                     "7",                                                                                                         nullptr                                 ) \
    X_LBL_CFG( LBL_8,                     "8",                                                                                                         nullptr                                 ) \
    X_LBL_CFG( LBL_9,                     "9",                                                                                                         nullptr                                 ) \
    X_LBL_CFG( LBL_0,                     "0",                                                                                                         nullptr                                 ) \
    X_LBL_CFG( LBL_DOT,                   ".",                                                                                                         nullptr                                 ) \
    X_LBL_CFG( LBL_SIGN,                  "-",                                                                                                         nullptr                                 ) \
\
    X_LBL_CFG( LBL_NOT_ACTIVE,            " NO ACT ",                                                                                                  nullptr                                 ) \
    X_LBL_CFG( LBL_ACTIVE,                " ACTIVE ",                                                                                                  nullptr                                 ) \
    X_LBL_CFG( LBL_INACTIVE,              " ------ ",                                                                                                  nullptr                                 ) \
    X_LBL_CFG( LBL_OPENED,                " OPENED ",                                                                                                  " OUVERT "                              ) \
    X_LBL_CFG( LBL_CLOSED,                " CLOSED ",                                                                                                  " FERMÉ  "                              ) \
    X_LBL_CFG( LBL_LOCK,                  "  LOCK  ",                                                                                                  "  VERROUILLÉ  "                        ) \
    X_LBL_CFG( LBL_UNLOCK,                " UNLOCK ",                                                                                                  " DÉVERROUILLÉ "                        ) \
    X_LBL_CFG( LBL_CTRL_ON,               "On ",                                                                                                       nullptr                                 ) \
    X_LBL_CFG( LBL_CTRL_OFF,              "Off",                                                                                                       nullptr                                 ) \
    X_LBL_CFG( LBL_CTRL_LOCK,             "Lock  ",                                                                                                    "vérouillé  "                           ) \
    X_LBL_CFG( LBL_CTRL_UNLOCK,           "Unlock",                                                                                                    "déverouillé"                           ) \
    X_LBL_CFG( LBL_LOW,                   " Low ",                                                                                                     " Bas  "                                ) \
    X_LBL_CFG( LBL_HIGH,                  " High ",                                                                                                    " Haut "                                ) \
    X_LBL_CFG( LBL_INPUT,                 "Input",                                                                                                     "Entrée"                                ) \
    X_LBL_CFG( LBL_MILLISEC,              "mSec",                                                                                                      nullptr                                 ) \
    X_LBL_CFG( LBL_CYCLE,                 "Cycle",                                                                                                     nullptr                                 ) \
    X_LBL_CFG( LBL_VOLTS,                 "Volts",                                                                                                     nullptr                                 ) \
\
    X_LBL_CFG( LBL_MENU_TITLE,            "                                        Console Menu                                                \r\n",  "                                        Menu Console                                                \r\n") \
    X_LBL_CFG( LBL_MENU_TITLE_LINE_2,     "                                     Product/Project Name                                           \r\n",  "                                    Produit/Nom de Projet                                           \r\n") \
    X_LBL_CFG( LBL_STATUS,                "Status :\r\n",                                                                                              "Statut :\r\n"                          ) \
    X_LBL_CFG( LBL_CFG_OPT_BLANK,         "\r\n",                                                                                                      nullptr) \
\
    X_LBL_CFG( LBL_MAIN_MENU,             "    Main Menu\r\n",                                                                                         "    Menu Principal\r\n"                ) \
    X_LBL_CFG( LBL_MAIN_OPT1,             "Display System Information\r\n",                                                                            "Informations Système"                  ) \
    X_LBL_CFG( LBL_MAIN_OPT2,             "Debug\r\n",                                                                                                 "Déboguage"                             ) \
    X_LBL_CFG( LBL_MAIN_OPT3,             "System Settings\r\n",                                                                                       "Réglage Système"                       ) \
    X_LBL_CFG( LBL_MAIN_OPT4,             "Test 1\r\n",                                                                                                nullptr                                 ) \
    X_LBL_CFG( LBL_MAIN_OPT5,             "Test 2\r\n",                                                                                                nullptr                                 ) \
\
    X_LBL_CFG( LBL_PRODUCT_INFO,          "Display Systems Information\r\n\r\n",                                                                       "Afficher Informations Système\r\n\r\n" ) \
    X_LBL_CFG( LBL_PRODUCT_NAME,          "  Product Name:          %s\r\n",                                                                           "  Nom du Produit:             %s\r\n"  ) \
    X_LBL_CFG( LBL_APP_VERSION,           "  Firmware Version:      %s\r\n",                                                                           "  Version uLogiciel:          %s\r\n"  ) \
    X_LBL_CFG( LBL_FW_RELEASE_DATE,       "  Firmware Release Date: %s, %s\r\n",                                                                       "  Date de Relâche uLogiciel:  %s\r\n"  ) \
    X_LBL_CFG( LBL_BOOT_VERSION,          "  Bootloader Version:    %s\r\n",                                                                           "  Version Bootloader:         %s\r\n"  ) \
    X_LBL_CFG( LBL_HARDWARE_VERSION,      "  Hardware Version:      %s\r\n",                                                                           "  Version du matériel:        %s\r\n"  ) \
    X_LBL_CFG( LBL_PRODUCT_SERIAL,        "  Serial Number:         ",                                                                                 "  Numéro de Série:            "        ) \
    X_LBL_CFG( LBL_UPTIME,                "\r\n  Uptime (D:HH:MM:SS)\r\n",                                                                             "\r\n  Temps Actif (D:HH:MM:SS\r\n"     ) \
    X_LBL_CFG( LBL_GMT_TIME,              "  GMT Time:\r\n",                                                                                           "  Heure GMT:\r\n"                      ) \
\
    X_LBL_CFG( LBL_DEBUG_MENU,            "    Debug Menu\r\n",                                                                                        "    Menu Déboguage\r\n"                ) \
    X_LBL_CFG( LBL_DEBUG_OPT1,            "level 1 - System Status       ( )\r\n",                                                                     "Statut du Système\r\n"                 ) \
    X_LBL_CFG( LBL_DEBUG_OPT2,            "Level 2 - System Action       ( )\r\n",                                                                     "Action sur Système\r\n"                ) \
    X_LBL_CFG( LBL_DEBUG_OPT3,            "Level 3 - System Sanity       ( )\r\n",                                                                     "Sanité du Système\r\n"                 ) \
    X_LBL_CFG( LBL_DEBUG_OPT4,            "Level 4 - Comm Status         ( )\r\n",                                                                     "Statut Communication\r\n"              ) \
    X_LBL_CFG( LBL_DEBUG_OPT5,            "Level 5 - Generic Status      ( )\r\n",                                                                     "Statut Générique\r\n"                  ) \
    X_LBL_CFG( LBL_DEBUG_OPT6,            "Level 6 - Task X Info         ( )\r\n",                                                                     "Info Task X\r\n"                       ) \
    X_LBL_CFG( LBL_DEBUG_OPT7,            "Level 7 - Task Y Info         ( )\r\n",                                                                     "Info Task Y\r\n"                       ) \
    X_LBL_CFG( LBL_DEBUG_OPT8,            "Level 8 - Task Z Info         ( )\r\n",                                                                     "Info Task Z\r\n"                       ) \
\
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
    X_LBL_CFG( LBL_SETTING_OPT2,          "Miscelleaneous\r\n",                                                                                        "Divers\r\n"                            ) \
    X_LBL_CFG( LBL_MISC_CFG_MENU,         "Miscelleaneous 2\r\n",                                                                                      "Divers 2\r\n"                          ) \
\
    X_LBL_CFG( LBL_TIME_CFG_MENU,         "    Time and Date Configuration\r\n",                                                                       "    Configuration Heure et date\r\n"   ) \
    X_LBL_CFG( LBL_TIME_CFG_OPT1,         "Hour\r\n",                                                                                                  "Heure\r\n"                             ) \
    X_LBL_CFG( LBL_TIME_CFG_OPT2,         "Minute\r\n",                                                                                                nullptr                                 ) \
    X_LBL_CFG( LBL_TIME_CFG_OPT3,         "Second\r\n",                                                                                                "Seconde\r\n"                           ) \
    X_LBL_CFG( LBL_TIME_CFG_OPT4,         "Day\r\n",                                                                                                   "Jour\r\n"                              ) \
    X_LBL_CFG( LBL_TIME_CFG_OPT5,         "Month\r\n",                                                                                                 "Mois\r\n"                              ) \
    X_LBL_CFG( LBL_TIME_CFG_OPT6,         "Year\r\n",                                                                                                  "Année\r\n"                             ) \
    X_LBL_CFG( LBL_TDC_TIME,              "Time    :",                                                                                                 "Heure\r\n"                             ) \
    X_LBL_CFG( LBL_TDC_DATE,              "Date    :",                                                                                                 nullptr                                 ) \
\

//-------------------------------------------------------------------------------------------------
