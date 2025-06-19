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

/*
   Include all necessary files to access the real device and/or to get access
   to the required operating system calls.
*/
#include "Application.h"


/*
   In order to ensure that the example code of this module is only compiled
   and linked to the example 'DeviceIntegration', we check for generated defines.
*/
#ifdef _ApplicationThermostat_
#include "app_ew_interface.h"

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
int DeviceDriver_ProcessData( void )
{
   int needUpdate = 0;
   app_temperature= EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Temperature;
   app_humidity = EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Humidity;

   /*
     Get the data you want to provide to the GUI application.
     Please note, that this function is called within the context of the main
     GUI thread/task.
   */
   if(app_wifi_connected==true)
   {
	 if(app_sntp_read ==true)
     {
		 app_sntp_read=false;
         EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->WifiConnected=1;
	     EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Day =    app_sntp_day;
	     EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Month  = app_sntp_month;
	     EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Year   = app_sntp_year;
	     EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Hour   = app_sntp_hour;
         EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Minute = app_sntp_minute;
	 }
		 
   }
   if(app_bluetooth_connected==true)
   {
     EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->BtConnected =1;
   }

   if ( EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->TurnWifiOn == 1 )
   {
	   app_wifi_connect = true;
   }
   
   if ( EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->TurnBtOn == 1 )
   {
	   app_bluetooth_connect = true;
   }

   if(app_mode_changed)
   {
	   app_mode_changed=false;
	   ApplicationDeviceClass_OnSetMode( EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass ), app_mode );
   }
   /*
     Return a value != 0 if there is at least one property changed or if a
     system event was triggered. The return value is used by the main loop, to
     decide whether the GUI application has changed or not.
   */
   return needUpdate;
}
#endif
/*******************************************************************************
* FUNCTION:
*   DeviceDriver_Initialize
*
* DESCRIPTION:
*   The function DeviceDriver_Initialize() initializes the module and prepares all
*   necessary things to access or communicate with the real device.
*   The function has to be called from your main module, before the initialization
*   of your GUI application.
*
*   IMPORTANT NOTE: This global initialization function exists for compatibility
*   reasons. The initialization of dedicated hardware drivers or middleware APIs
*   should be done in separate functions called by the Init constructor of the
*   device class.
*
* ARGUMENTS:
*   None
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void DeviceDriver_Initialize( void )
{
  /*
     You can implement here the necessary code to initialize your particular
     hardware, to open needed devices, to open communication channels, etc.
  */
}


/*******************************************************************************
* FUNCTION:
*   DeviceDriver_Deinitialize
*
* DESCRIPTION:
*   The function DeviceDriver_Deinitialize() deinitializes the module and
*   finalizes the access or communication with the real device.
*   The function has to be called from your main module, after the GUI
*   application will be deinitialized.
*
*   IMPORTANT NOTE: This global de-initialization function exists for
*   compatibility reasons. It is recommend to use the Done destructor of the
*   device class.
*
* ARGUMENTS:
*   None
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void DeviceDriver_Deinitialize( void )
{
  /*
     You can implement here the necessary code to deinitialize your particular
     hardware, to close used devices, to close communication channels, etc.
  */
}

/* msy */
