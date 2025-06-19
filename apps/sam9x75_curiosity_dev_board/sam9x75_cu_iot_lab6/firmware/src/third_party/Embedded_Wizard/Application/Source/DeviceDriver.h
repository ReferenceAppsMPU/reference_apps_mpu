/*******************************************************************************
*
* E M B E D D E D   W I Z A R D   P R O J E C T
*
*                                                Copyright (c) TARA Systems GmbH
*                                    written by Paul Banach and Manfred Schweyer
*
********************************************************************************
*
* This software is delivered "as is" and shows the usage of other software
* components. It is provided as an example software which is intended to be
* modified and extended according to particular requirements.
*
* TARA Systems hereby disclaims all warranties and conditions with regard to the
* software, including all implied warranties and conditions of merchantability
* and non-infringement of any third party IPR or other rights which may result
* from the use or the inability to use the software.
*
********************************************************************************
*
* DESCRIPTION:
*   This file implements an interface between an Embedded Wizard generated UI
*   application and a certain device. Please consider this file only as template
*   that is intended to show the binding between an UI application and the
*   underlying system (e.g. middleware, BSP, hardware driver, protocol, ...).
*
*   This device driver is the counterpart to a device class implemented within
*   your Embedded Wizard project.
*
*   Feel free to adapt this file according your needs!
*
*   The following code demonstrates the access to the board LED, a simulated
*   ADC value and the hardware button. Furthemore, the console interface is used
*   to print a string.
*
*   The Embedded Wizard GUI example 'DeviceIntegration' shows the usage of this
*   device driver.
*
*   This file assumes to be the counterpart of the device class 'DeviceClass'
*   within the unit 'Application'.
*
*******************************************************************************/

#ifndef DEVICEDRIVER_H
#define DEVICEDRIVER_H


#ifdef __cplusplus
  extern "C"
  {
#endif

/*******************************************************************************
* FUNCTION:
*   DeviceDriver_ProcessData
*
* DESCRIPTION:
*   The function DeviceDriver_ProcessData() is called from the main UI loop, in
*   order to process data and events from your particular device.
*   This function is responsible to update properties within the device class
*   if the corresponding state or value of the real device has changed.
*   This function is also responsible to trigger system events if necessary.
*
*   IMPORTANT NOTE: This data processing function can be used to process data
*   periodically in the context of the main GUI thread/task or in case there
*   is no operating system at all (bare metal).
*   In case you want to feed the GUI application with data and events from a
*   foreign thread/task or an interrupt service routine it will be much easier
*   to use the functions EwInvoke() and EwInvokeCopy().
*
* ARGUMENTS:
*   None
*
* RETURN VALUE:
*   The function returns a non-zero value if a property has changed or if a
*   system event was triggered. If nothing happens, the function returns 0.
*
*******************************************************************************/
int DeviceDriver_ProcessData( void );
void DeviceDriver_Deinitialize( void );
void DeviceDriver_Initialize( void );


#ifdef __cplusplus
  }
#endif

#endif /* DEVICEDRIVER_H */


/* msy */
