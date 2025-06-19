/*******************************************************************************
*
* E M B E D D E D   W I Z A R D   P R O J E C T
*
*                                                Copyright (c) TARA Systems GmbH
*                                    written by Paul Banach and Manfred Schweyer
*
********************************************************************************
*
* This file was generated automatically by Embedded Wizard Studio.
*
* Please do not make any modifications of this file! The modifications are lost
* when the file is generated again by Embedded Wizard Studio!
*
* The template of this heading text can be found in the file 'head.ewt' in the
* directory 'Platforms' of your Embedded Wizard installation directory. If you
* wish to adapt this text, please copy the template file 'head.ewt' into your
* project directory and edit the copy only. Please avoid any modifications of
* the original template file!
*
* Version  : 14.02
* Profile  : Profile
* Platform : Microchip.PIC32.RGBA8888
*
*******************************************************************************/

#ifndef _ApplicationDeviceClass_H
#define _ApplicationDeviceClass_H

#ifdef __cplusplus
  extern "C"
  {
#endif

#include "ewrte.h"
#if ( EW_RTE_VERSION >> 16 ) != 14
  #error Wrong version of Embedded Wizard Runtime Environment.
#endif

#include "ewgfx.h"
#if ( EW_GFX_VERSION >> 16 ) != 14
  #error Wrong version of Embedded Wizard Graphics Engine.
#endif

#include "_TemplatesDeviceClass.h"

/* Forward declaration of the class Application::DeviceClass */
#ifndef _ApplicationDeviceClass_
  EW_DECLARE_CLASS( ApplicationDeviceClass )
#define _ApplicationDeviceClass_
#endif


/* Deklaration of class : 'Application::DeviceClass' */
EW_DEFINE_FIELDS( ApplicationDeviceClass, TemplatesDeviceClass )
  EW_VARIABLE( am_pm,           XString )
  EW_VARIABLE( month,           XString )
  EW_PROPERTY( Brightness,      XInt32 )
  EW_PROPERTY( Mode,            XInt32 )
  EW_PROPERTY( Day,             XInt32 )
  EW_PROPERTY( Temperature,     XInt32 )
  EW_PROPERTY( Minute,          XInt32 )
  EW_PROPERTY( Hour,            XInt32 )
  EW_PROPERTY( Year,            XInt32 )
  EW_PROPERTY( Humidity,        XInt32 )
  EW_PROPERTY( Month,           XInt32 )
  EW_PROPERTY( TurnWifiOn,      XBool )
  EW_PROPERTY( WifiConnected,   XBool )
  EW_PROPERTY( TurnBtOn,        XBool )
  EW_PROPERTY( BtConnected,     XBool )
EW_END_OF_FIELDS( ApplicationDeviceClass )

/* Virtual Method Table (VMT) for the class : 'Application::DeviceClass' */
EW_DEFINE_METHODS( ApplicationDeviceClass, TemplatesDeviceClass )
EW_END_OF_METHODS( ApplicationDeviceClass )

/* 'C' function for method : 'Application::DeviceClass.OnSetMode()' */
void ApplicationDeviceClass_OnSetMode( ApplicationDeviceClass _this, XInt32 value );

/* 'C' function for method : 'Application::DeviceClass.OnSetWifiConnected()' */
void ApplicationDeviceClass_OnSetWifiConnected( ApplicationDeviceClass _this, XBool 
  value );

/* Default onget method for the property 'Brightness' */
XInt32 ApplicationDeviceClass_OnGetBrightness( ApplicationDeviceClass _this );

/* Default onset method for the property 'Brightness' */
void ApplicationDeviceClass_OnSetBrightness( ApplicationDeviceClass _this, XInt32 
  value );

/* Default onget method for the property 'Mode' */
XInt32 ApplicationDeviceClass_OnGetMode( ApplicationDeviceClass _this );

/* Default onget method for the property 'WifiConnected' */
XBool ApplicationDeviceClass_OnGetWifiConnected( ApplicationDeviceClass _this );

/* Default onget method for the property 'BtConnected' */
XBool ApplicationDeviceClass_OnGetBtConnected( ApplicationDeviceClass _this );

/* Default onset method for the property 'BtConnected' */
void ApplicationDeviceClass_OnSetBtConnected( ApplicationDeviceClass _this, XBool 
  value );

/* Default onget method for the property 'Day' */
XInt32 ApplicationDeviceClass_OnGetDay( ApplicationDeviceClass _this );

/* Default onset method for the property 'Day' */
void ApplicationDeviceClass_OnSetDay( ApplicationDeviceClass _this, XInt32 value );

/* Default onget method for the property 'Year' */
XInt32 ApplicationDeviceClass_OnGetYear( ApplicationDeviceClass _this );

/* Default onset method for the property 'Year' */
void ApplicationDeviceClass_OnSetYear( ApplicationDeviceClass _this, XInt32 value );

/* Default onget method for the property 'Month' */
XInt32 ApplicationDeviceClass_OnGetMonth( ApplicationDeviceClass _this );

/* Default onset method for the property 'Month' */
void ApplicationDeviceClass_OnSetMonth( ApplicationDeviceClass _this, XInt32 value );

#ifdef __cplusplus
  }
#endif

#endif /* _ApplicationDeviceClass_H */

/* Embedded Wizard */
