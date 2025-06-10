/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    app_dsi.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "APP_DSI_Initialize" and "APP_DSI_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "APP_DSI_STATES" definition).  Both
    are defined here for convenience.
*******************************************************************************/

#ifndef _APP_DSI_H
#define _APP_DSI_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Type Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application states

  Summary:
    Application states enumeration

  Description:
    This enumeration defines the valid application states.  These states
    determine the behavior of the application at various times.
*/


// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    Application strings and buffers are be defined outside this structure.
 */


// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************
/* These routines are called by drivers when certain events occur.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************
extern int32_t app_sntp_day;
extern int32_t app_sntp_month;
extern int32_t app_sntp_year;
extern int32_t app_sntp_hour;
extern int32_t app_sntp_minute;

extern bool app_wifi_connect;
extern bool app_wifi_connected;
extern bool app_sntp_read;
extern bool app_bluetooth_connected;
extern bool app_bluetooth_connect;

extern bool app_mode_changed;
extern int32_t app_mode;

extern int32_t app_temperature;
extern int32_t app_humidity;

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _APP_DSI_H */

/*******************************************************************************
 End of File
 */

