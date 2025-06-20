/*******************************************************************************
  System Configuration Header

  File Name:
    configuration.h

  Summary:
    Build-time configuration header for the system defined by this project.

  Description:
    An MPLAB Project may have multiple configurations.  This file defines the
    build-time options for a single configuration.

  Remarks:
    This configuration header must not define any prototypes or data
    definitions (or include any files that do).  It only provides macro
    definitions for build-time configuration options

*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
// DOM-IGNORE-END

#ifndef CONFIGURATION_H
#define CONFIGURATION_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
/*  This section Includes other configuration headers necessary to completely
    define this configuration.
*/

#include "user.h"
#include "device.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: System Configuration
// *****************************************************************************
// *****************************************************************************



// *****************************************************************************
// *****************************************************************************
// Section: System Service Configuration
// *****************************************************************************
// *****************************************************************************
/*----------------- WINCS Net System Service Configuration -----------------*/
#define SYS_WINCS_NET_BIND_TYPE0                SYS_WINCS_NET_BIND_REMOTE 
#define SYS_WINCS_NET_SOCK_TYPE0                SYS_WINCS_NET_SOCK_TYPE_TCP 
#define SYS_WINCS_NET_SOCK_TYPE_IPv4_0          4
#define SYS_WINCS_NET_SOCK_TYPE_IPv6_LOCAL0     0
#define SYS_WINCS_NET_SOCK_TYPE_IPv6_GLOBAL0    0
#define SYS_WINCS_NET_SOCK_SERVER_ADDR0         ""
#define SYS_WINCS_NET_SOCK_PORT0                80
#define SYS_WINCS_TLS_ENABLE0                   0
/*----------------------------------------------------------------------------*/

/* -----------------WINCS02 MQTT System Service Configuration ----------------- */

#define SYS_WINCS_MQTT_PROTO_VERSION             SYS_WINCS_MQTT_PROTO_VER_3

#define SYS_WINCS_MQTT_CLOUD_URL                 "broker.emqx.io"
#define SYS_WINCS_MQTT_CLOUD_PORT                1883
#define SYS_WINCS_MQTT_CLIENT_ID                 "MCHP_device_01"
#define SYS_WINCS_MQTT_CLOUD_USER_NAME           ""
#define SYS_WINCS_MQTT_PASSWORD                  ""
#define SYS_WINCS_MQTT_CLEAN_SESSION             true
#define SYS_WINCS_MQTT_KEEP_ALIVE_TIME           60
#define SYS_WINCS_MQTT_SUB_TOPIC_0               "$MCHP/Wireless/device02"
#define SYS_WINCS_MQTT_SUB_TOPIC_0_QOS           SYS_WINCS_MQTT_QOS0


#define SYS_WINCS_MQTT_PUB_TOPIC_NAME            "$MCHP/Wireless/device01"
#define SYS_WINCS_MQTT_PUB_MSG                   "Hi. It's MCHP Thermostat Device"
#define SYS_WINCS_MQTT_PUB_MSG_QOS_TYPE          SYS_WINCS_MQTT_QOS0
#define SYS_WINCS_MQTT_PUB_MSG_RETAIN            false
#define SYS_WINCS_MQTT_TLS_ENABLE                false
#define SYS_WINCS_MQTT_AZURE_DPS_ENABLE          false
#define SYS_WINCS_MQTT_CallbackHandler           APP_MQTT_Callback

/*----------------------------------------------------------------------------*/


#define SYS_DEBUG_ENABLE
#define SYS_DEBUG_GLOBAL_ERROR_LEVEL       SYS_ERROR_INFO
#define SYS_DEBUG_BUFFER_DMA_READY
#define SYS_DEBUG_USE_CONSOLE


/* TIME System Service Configuration Options */
#define SYS_TIME_INDEX_0                            (0)
#define SYS_TIME_MAX_TIMERS                         (5)
#define SYS_TIME_HW_COUNTER_WIDTH                   (32)
#define SYS_TIME_HW_COUNTER_PERIOD                  (4294967295U)
#define SYS_TIME_HW_COUNTER_HALF_PERIOD             (SYS_TIME_HW_COUNTER_PERIOD>>1)
#define SYS_TIME_CPU_CLOCK_FREQUENCY                (800000000)
#define SYS_TIME_COMPARE_UPDATE_EXECUTION_CYCLES    (1210)

#define SYS_CONSOLE_DEVICE_MAX_INSTANCES   			(1U)
#define SYS_CONSOLE_UART_MAX_INSTANCES 	   			(1U)
#define SYS_CONSOLE_USB_CDC_MAX_INSTANCES 	   		(0U)
#define SYS_CONSOLE_PRINT_BUFFER_SIZE        		(1000U)


#define SYS_CONSOLE_INDEX_0                       0






// *****************************************************************************
// *****************************************************************************
// Section: Driver Configuration
// *****************************************************************************
// *****************************************************************************
/* I2C Driver Instance 0 Configuration Options */
#define DRV_I2C_INDEX_0                       0
#define DRV_I2C_CLIENTS_NUMBER_IDX0           1
#define DRV_I2C_QUEUE_SIZE_IDX0               2
#define DRV_I2C_CLOCK_SPEED_IDX0              400000

/*** WiFi WINC Driver Configuration ***/
#define WDRV_WINC_PIO_SOURCE
#define WDRV_WINC_DEVICE_USE_SYS_DEBUG
#define WDRV_WINC_DEV_RX_BUFF_SZ            2048
#define WDRV_WINC_DEV_SOCK_SLAB_NUM         50
#define WDRV_WINC_DEV_SOCK_SLAB_SZ          1472
#define WINC_SOCK_NUM_SOCKETS               10
#define WINC_SOCK_BUF_RX_SZ                 7360
#define WINC_SOCK_BUF_TX_SZ                 4416
#define WINC_SOCK_BUF_RX_PKT_BUF_NUM        5
#define WINC_SOCK_BUF_TX_PKT_BUF_NUM        5

/* I2C Driver Common Configuration Options */
#define DRV_I2C_INSTANCES_NUMBER              (1U)




// *****************************************************************************
// *****************************************************************************
// Section: Middleware & Other Library Configuration
// *****************************************************************************
// *****************************************************************************
/* WINCS02  WIFI System Service Configuration Options */

#define SYS_WINCS_WIFI_DEVMODE        		SYS_WINCS_WIFI_MODE_STA

#define SYS_WINCS_WIFI_STA_SSID				"DEMO_AP"
#define SYS_WINCS_WIFI_STA_PWD        		"password"
#define SYS_WINCS_WIFI_STA_SECURITY			SYS_WINCS_WIFI_SECURITY_WPA2 
#define SYS_WINCS_WIFI_STA_AUTOCONNECT   	true


#define SYS_WINCS_WIFI_COUNTRYCODE          "GEN"
#define SYS_WINCS_WIFI_SNTP_ADDRESS          "162.159.200.1"


#define SYS_WINCS_WIFI_CallbackHandler	     APP_WIFI_Callback


// *****************************************************************************
// *****************************************************************************
// Section: Application Configuration
// *****************************************************************************
// *****************************************************************************


//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // CONFIGURATION_H
/*******************************************************************************
 End of File
*/
