/*******************************************************************************
  WINC Wireless Driver System Interface Header File

  Company:
    Microchip Technology Inc.

  File Name:
    wdrv_winc_api.h

  Summary:
    WINC wireless driver system API header file.

  Description:
    This interface is intended to be called from the main system initialization
    and task functions.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*
Copyright (C) 2024, Microchip Technology Inc., and its subsidiaries. All rights reserved.

The software and documentation is provided by microchip and its contributors
"as is" and any express, implied or statutory warranties, including, but not
limited to, the implied warranties of merchantability, fitness for a particular
purpose and non-infringement of third party intellectual property rights are
disclaimed to the fullest extent permitted by law. In no event shall microchip
or its contributors be liable for any direct, indirect, incidental, special,
exemplary, or consequential damages (including, but not limited to, procurement
of substitute goods or services; loss of use, data, or profits; or business
interruption) however caused and on any theory of liability, whether in contract,
strict liability, or tort (including negligence or otherwise) arising in any way
out of the use of the software and documentation, even if advised of the
possibility of such damage.

Except as expressly permitted hereunder and subject to the applicable license terms
for any third-party software incorporated in the software and any applicable open
source software license terms, no license or other rights, whether express or
implied, are granted under any patent or other intellectual property rights of
Microchip or any third party.
*/
// DOM-IGNORE-END

#ifndef WDRV_WINC_API_H
#define WDRV_WINC_API_H

// *****************************************************************************
// *****************************************************************************
// Section: File includes
// *****************************************************************************
// *****************************************************************************

#include <ctype.h>
#include <stdint.h>
#include <stdbool.h>

#include "system/system_module.h"
#include "wdrv_winc_spi.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus // Provide C++ Compatibility
    extern "C" {
#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: WINC Driver System Data Types
// *****************************************************************************
// *****************************************************************************

/* WINC device system interface index 0. */
#define WDRV_WINC_SYS_IDX_0         0U

// *****************************************************************************
/*  WINC Device System Events.

  Summary:
    Possible WINC device system events.

  Description:
    Enumeration of possible WINC device system events.

*/

typedef enum
{
    /* Invalid system event. */
    WDRV_WINC_SYSTEM_EVENT_INVALID,

    /* WINC device in hard reset. */
    WDRV_WINC_SYSTEM_EVENT_DEVICE_HARD_RESET,

    /* WINC device initialization has begun. */
    WDRV_WINC_SYSTEM_EVENT_DEVICE_INIT_BEGIN,

    /* WINC device initialization has completed. */
    WDRV_WINC_SYSTEM_EVENT_DEVICE_INIT_COMPLETE,

    /* WINC device is ready. */
    WDRV_WINC_SYSTEM_EVENT_DEVICE_READY,

    /* WINC device reset has failed. */
    WDRV_WINC_SYSTEM_EVENT_DEVICE_RESET_FAILED,

    /* WINC device reset has timed out. */
    WDRV_WINC_SYSTEM_EVENT_DEVICE_RESET_TIMEOUT,

    /* WINC device reset is being retried. */
    WDRV_WINC_SYSTEM_EVENT_DEVICE_RESET_RETRY,

    /* WINC device comms error has been detected. */
    WDRV_WINC_SYSTEM_EVENT_DEVICE_COMMS_ERROR,
} WDRV_WINC_SYSTEM_EVENT_TYPE;

// *****************************************************************************
/*  WiFi Control Initialization Data

  Summary:
    Data that's passed to the Control instance.

  Description:
    This structure defines the Control instance initialization.

*/

typedef struct
{
    /* SPI configuration. */
    const WDRV_WINC_SPI_CFG* const pSPICfg;

    /* Interrupt source. */
    int intSrc;
} WDRV_WINC_SYS_INIT;

//*******************************************************************************
/*
  Function:
    void (*WDRV_WINC_SYSTEM_EVENT_CALLBACK)
    (
        SYS_MODULE_OBJ object,
        WDRV_WINC_SYSTEM_EVENT_TYPE event
    )

  Summary:
    System event callback.

  Description:
    Callback used to communicate system events from the WINC driver.

  Parameters:
    object - Driver object handle, returned from WDRV_WINC_Initialize.
    event  - System event.

  Returns:
    None.

  Remarks:
    None.

*/

typedef void (*WDRV_WINC_SYSTEM_EVENT_CALLBACK)
(
    SYS_MODULE_OBJ object,
    WDRV_WINC_SYSTEM_EVENT_TYPE event
);

// *****************************************************************************
// *****************************************************************************
// Section: WINC Driver System Routines
// *****************************************************************************
// *****************************************************************************

//*******************************************************************************
/*
  Function:
    SYS_MODULE_OBJ WDRV_WINC_Initialize
    (
        const SYS_MODULE_INDEX index,
        const SYS_MODULE_INIT *const init
    )

  Summary:
    System interface initialization of the WINC driver.

  Description:
    This is the function that initializes the WINC driver. It is called by
    the system.

  Precondition:
    None.

  Parameters:
    index - Index for the WINC driver instance to be initialized.
    init  - Pointer to initialization data, see WDRV_WINC_SYS_INIT.

  Returns:
    Success - Valid handle to a driver object.
    Failure - SYS_MODULE_OBJ_INVALID.

  Remarks:
    The returned object must be passed as argument to WDRV_WINC_Reinitialize,
      WDRV_WINC_Deinitialize, WDRV_WINC_Tasks and WDRV_WINC_Status routines.

*/

SYS_MODULE_OBJ WDRV_WINC_Initialize
(
    const SYS_MODULE_INDEX index,
    const SYS_MODULE_INIT *const init
);

//*******************************************************************************
/*
  Function:
    void WDRV_WINC_Deinitialize(SYS_MODULE_OBJ object)

  Summary:
    WINC driver deinitialization function.

  Description:
    This is the function that deinitializes the WINC.
    It is called by the system.

  Precondition:
    WDRV_WINC_Initialize must have been called.

  Parameters:
    object - Driver object handle, returned from WDRV_WINC_Initialize.

  Returns:
    None.

  Remarks:
    None.

*/

void WDRV_WINC_Deinitialize(SYS_MODULE_OBJ object);

//*******************************************************************************
/*
  Function:
    void WDRV_WINC_Reinitialize
    (
        SYS_MODULE_OBJ object,
        const SYS_MODULE_INIT *const init
    )

  Summary:
    WINC driver reinitialization function.

  Description:
    This is the function that re-initializes the WINC.
    It is called by the system.

  Precondition:
    WDRV_WINC_Initialize must have been called.

  Parameters:
    object - Driver object handle, returned from WDRV_WINC_Initialize.
    init   - Pointer to initialization data, currently not used.

  Returns:
    None.

  Remarks:
    None.

*/

void WDRV_WINC_Reinitialize
(
    SYS_MODULE_OBJ object,
    const SYS_MODULE_INIT *const init
);

//*******************************************************************************
/*
  Function:
    SYS_STATUS WDRV_WINC_Status(SYS_MODULE_OBJ object)

  Summary:
    Provides the current status of the WINC driver module.

  Description:
    This function provides the current status of the WINC driver module.

  Precondition:
    WDRV_WINC_Initialize must have been called before calling this function.

  Parameters:
    object - Driver object handle, returned from WDRV_WINC_Initialize.

  Returns:
    SYS_STATUS_READY         - Indicates that any previous module operation for the
                                specified module has completed.
    SYS_STATUS_BUSY          - Indicates that a previous module operation for the
                                specified module has not yet completed.
    SYS_STATUS_ERROR         - Indicates that the specified module is in an error state.
    SYS_STATUS_UNINITIALIZED - Driver uninitialized.

  Example:
    <code>
    SYS_MODULE_OBJ      object;     // Returned from WDRV_WINC_Initialize
    SYS_STATUS          status;

    status = WDRV_WINC_Status(object);
    if (SYS_STATUS_ERROR >= status)
    {
        // Handle error
    }
    </code>

  Remarks:
    Any value greater than SYS_STATUS_READY is also a normal running state
      in which the driver is ready to accept new operations.

    SYS_STATUS_BUSY - Indicates that the driver is busy with a previous
      system level operation and cannot start another.

    SYS_STATUS_ERROR - Indicates that the driver is in an error state.
     Any value less than SYS_STATUS_ERROR is also an error state.

    SYS_STATUS_UNINITIALIZED - Indicates that the driver has been
      deinitialized.

    This operation can be used to determine when any of the driver's
      module level operations has completed.

    If the status operation returns SYS_STATUS_BUSY, then a previous
      operation has not yet completed. Once the status operation returns
      SYS_STATUS_READY, any previous operations have completed.

    The value of SYS_STATUS_ERROR is negative (-1). Any value less than
      that is also an error state.

    This function will NEVER block waiting for hardware.

    If the Status operation returns an error value, the error may be
      cleared by calling the reinitialize operation. If that fails, the
      deinitialize operation will need to be called, followed by the
      initialize operation to return to normal operations.

*/

SYS_STATUS WDRV_WINC_Status(SYS_MODULE_OBJ object);

//*******************************************************************************
/*
  Function:
    void WDRV_WINC_Tasks(SYS_MODULE_OBJ object)

  Summary:
    Maintains the WINC drivers state machine.

  Description:
    This function is used to maintain the driver's internal state machine.

  Precondition:
    WDRV_WINC_Initialize must have been called before calling this function.

  Parameters:
    object - Driver object handle, returned from WDRV_WINC_Initialize.

  Returns:
    None.

  Remarks:
    This function is normally not called directly by an application. It is
      called by the system's Tasks routine (SYS_Tasks).

*/

void WDRV_WINC_Tasks(SYS_MODULE_OBJ object);

//*******************************************************************************
/*
  Function:
    void WDRV_WINC_ISR(SYS_MODULE_OBJ object);

  Summary:
    WINC interrupt handler.

  Description:
    This function is called by the interrupt routines to signal an interrupt
      from the WINC.

  Precondition:
    WDRV_WINC_Initialize must have been called before calling this function.

  Parameters:
    object - Driver object handle, returned from WDRV_WINC_Initialize.

  Returns:
    None.

  Remarks:
    None.

*/

void WDRV_WINC_ISR(SYS_MODULE_OBJ object);

//*******************************************************************************
/*
  Function:
    void WDRV_WINC_RegisterSystemEventCallback
    (
        SYS_MODULE_OBJ object,
        WDRV_WINC_SYSTEM_EVENT_CALLBACK pfEventCallback
    )

  Summary:
    Register system event callback.

  Description:
    This function registers a system event callback to be notified of system
    events.

  Precondition:
    WDRV_WINC_Initialize must have been called before calling this function.

  Parameters:
    object          - Driver object handle, returned from WDRV_WINC_Initialize.
    pfEventCallback - Pointer to callback function.

  Returns:
    None.

  Remarks:
    None.

*/

void WDRV_WINC_RegisterSystemEventCallback
(
    SYS_MODULE_OBJ object,
    WDRV_WINC_SYSTEM_EVENT_CALLBACK pfEventCallback
);

// DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
// DOM-IGNORE-END

#endif /* WDRV_WINC_API_H */
