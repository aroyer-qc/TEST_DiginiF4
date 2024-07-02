//-------------------------------------------------------------------------------------------------
//
//  File : ip_cfg.h
//
//-------------------------------------------------------------------------------------------------
//
// Copyright(c) 2011-2024 Alain Royer.
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

//-------------------------------------------------------------------------------------------------
// Driver

// Include file for the ETH PHY Driver
#define PHY_DRIVER_INCLUDE                      "./NanoIP/inc/device/lib_class_PHY_LAN8742A.h"



// Name of the driver class
// need to be change #define PHY_DRIVER_INTERFACE                    PHY_LAN8742A_Driver

//-------------------------------------------------------------------------------------------------
// Driver configuration  (may vary according to driver)

// for PHY_LAN8742A_Driver

#define ETH_USED_INTERFACE                      ETH_INTERFACE_RMII
#define ETH_USE_TIME_STAMP                      DEF_DISABLED
#define ETH_USE_CHECKSUM_OFFLOAD                DEF_DISABLED
#define ETH_DEBUG_PACKET_COUNT                  DEF_ENABLED
#define ETH_USE_PHY_LINK_IRQ                    DEF_DISABLED
#define ETH_PHY_LINK_IO                         IO_NOT_DEFINED  // Put here the IO ID if supported

//-------------------------------------------------------------------------------------------------
// Protocol supported by the application

#define IP_USE_ARP 							    DEF_DISABLED//DEF_ENABLED
#define IP_USE_DHCP							    DEF_DISABLED//DEF_ENABLED     // Need UDP
#define IP_USE_ICMP							    DEF_DISABLED//DEF_ENABLED
#define IP_USE_NTP							    DEF_DISABLED
#define IP_USE_SNTP							    DEF_DISABLED
#define IP_USE_SOAP 						    DEF_DISABLED
#define IP_USE_TCP 							    DEF_DISABLED
#define IP_USE_UDP 							    DEF_DISABLED//DEF_ENABLED

//---------------------------------------------------------
// External server URL

#define IP_DEFAULT_NTP_SERVER_1                 "0.ca.pool.ntp.org"
#define IP_DEFAULT_NTP_SERVER_2                 "1.ca.pool.ntp.org"

//-------------------------------------------------------------------------------------------------
// Interface configuration

//       not shure it is needed
#define IP_INTERFACE_SUPPORT_EXTERNAL_PHY       DEF_ENABLED                 // Code generated for support of PHY controller (MAC is Build-in the CPU)
#define IP_INTERFACE_SUPPORT_HEC                DEF_DISABLED                // Code generated for support of HEC (Hardwired Ethernet Controller)  EX. Wiznet W5100S
#define IP_INTERFACE_SUPPORT_EXT_MAC_AND_PHY    DEF_DISABLED                // Code generated for support of MAC and PHY chip SPI and other

// If IP Interface use host name
#define IP_USE_HOSTNAME                         DEF_ENABLED

#define IP_IF_WIRED_PROTOCOL                    (IP_FLAG_USE_ARP | IP_FLAG_USE_DHCP | IP_FLAG_USE_ICMP | IP_FLAG_USE_TCP | IP_FLAG_USE_UDP)

// MAC address configuration using GUID of the CPU.
#define MAC_ADDR0                               (((char*)0x1FFF7A10)[0])
#define MAC_ADDR1                               (((char*)0x1FFF7A10)[2])
#define MAC_ADDR2                               (((char*)0x1FFF7A10)[4])
#define MAC_ADDR3                               (((char*)0x1FFF7A10)[6])
#define MAC_ADDR4                               (((char*)0x1FFF7A10)[8])
#define MAC_ADDR5                               (((char*)0x1FFF7A10)[10])

#define IP_MAC_ADDRESS_WIRED                    {MAC_ADDR0, MAC_ADDR1, MAC_ADDR2, MAC_ADDR3, MAC_ADDR4, MAC_ADDR5}


// This configuration use the hostname           (IP_USE_HOSTNAME == DEF_ENABLED)
//                    use the internal MAC & PHY (IP_INTERFACE_SUPPORT_EXTERNAL_PHY == DEF_ENABLED)
#define IF_ETH_DEF(X_IF) \
/*        ENUM ID of the ETH IF  Hostname            Protocol Flag         Default static IP,         Default Gateway,         Default subnet,            Default Static DNS,      MAC Address,          ETH Driver,    PHY Driver  */ \
/* Interface 1 ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/ \
    X_IF( IF_WIRED,              (char*)("TEST IP"), IP_IF_WIRED_PROTOCOL, IP_ADDRESS(192,168,0,254), IP_ADDRESS(192,168,0,1), IP_ADDRESS(255,255,255,0), IP_ADDRESS(192,168,0,1), IP_MAC_ADDRESS_WIRED, &myETH_Driver, &myPHY_Driver) \



/*

//--- Socket allocation -----------------------------------
// in this stack socket can be allocated statically.
// It is useful for NIC with hardwired IP Stack like
// Wiznet W5100S with limited number of socket and
// configurable socket memory size

#define IP_USE_STATIC_SOCKET					DEF_DISABLED

#if (IP_USE_STATIC_SOCKET == DEF_ENABLED)

// Socket use on for DHCP business
#define IP_SOCKET_DHCP                     		3

//-------------------------------------------------------------------------------------------------

#define ETH_DEBUG_PACKET_COUNT

//-------------------------------------------------------------------------------------------------

#define IP_NET_IF_MTU                           1500                // not sure it is used in my stack



need to add to database_cfg.h :

    X_EEPROM_DBASE( ETHERNET_MAC_Address,        myE2_Setting, 1, 1, sizeof(MAC_t)) \
    X_EEPROM_DBASE( CONFIGURATION_IP,            myE2_Setting, 1, 1, sizeof(struct of configuration size)) \
    X_EEPROM_DBASE( ETHERNET_STATIC_HOST_IP,     myE2_Setting, 1, 1, sizeof(IP_Address_t));
    X_EEPROM_DBASE( ETHERNET_SUBNET_MASK_IP,     myE2_Setting, 1, 1, sizeof(IP_Address_t));
    X_EEPROM_DBASE( ETHERNET_GATEWAY_IP,         myE2_Setting, 1, 1, sizeof(IP_Address_t));






*/
