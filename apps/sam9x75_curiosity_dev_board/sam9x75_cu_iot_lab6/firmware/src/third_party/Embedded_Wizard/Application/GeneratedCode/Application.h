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

#ifndef Application_H
#define Application_H

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

#include "_ApplicationApplication.h"
#include "_ApplicationBrightnessController.h"
#include "_ApplicationDeviceClass.h"
#include "_ApplicationFanController.h"
#include "_ApplicationModeController.h"
#include "_ApplicationTemperatureController.h"
#include "_ApplicationThermostat.h"

/* Font resource : 'Application::Font' */
EW_DECLARE_FONT_RES( ApplicationFont )

/* Bitmap resource : 'Application::Bluetooth_21_40' */
EW_DECLARE_BITMAP_RES( ApplicationBluetooth_21_40 )

/* Bitmap resource : 'Application::Circulate_75_80' */
EW_DECLARE_BITMAP_RES( ApplicationCirculate_75_80 )

/* Bitmap resource : 'Application::arrow_40_32' */
EW_DECLARE_BITMAP_RES( Applicationarrow_40_32 )

/* Bitmap resource : 'Application::bg_black' */
EW_DECLARE_BITMAP_RES( Applicationbg_black )

/* Bitmap resource : 'Application::bg_brown' */
EW_DECLARE_BITMAP_RES( Applicationbg_brown )

/* Bitmap resource : 'Application::blue1_60_60' */
EW_DECLARE_BITMAP_RES( Applicationblue1_60_60 )

/* Bitmap resource : 'Application::blue_720_720' */
EW_DECLARE_BITMAP_RES( Applicationblue_720_720 )

/* Bitmap resource : 'Application::brown_60_60' */
EW_DECLARE_BITMAP_RES( Applicationbrown_60_60 )

/* Bitmap resource : 'Application::circulate_invert_80_79' */
EW_DECLARE_BITMAP_RES( Applicationcirculate_invert_80_79 )

/* Bitmap resource : 'Application::coolset' */
EW_DECLARE_BITMAP_RES( Applicationcoolset )

/* Bitmap resource : 'Application::fan_50_50' */
EW_DECLARE_BITMAP_RES( Applicationfan_50_50 )

/* Bitmap resource : 'Application::home1_24_23' */
EW_DECLARE_BITMAP_RES( Applicationhome1_24_23 )

/* Bitmap resource : 'Application::hot_cold_49_60' */
EW_DECLARE_BITMAP_RES( Applicationhot_cold_49_60 )

/* Bitmap resource : 'Application::hotmode_43_60' */
EW_DECLARE_BITMAP_RES( Applicationhotmode_43_60 )

/* Bitmap resource : 'Application::humidity_small_14_18' */
EW_DECLARE_BITMAP_RES( Applicationhumidity_small_14_18 )

/* Bitmap resource : 'Application::mode_50_70' */
EW_DECLARE_BITMAP_RES( Applicationmode_50_70 )

/* Bitmap resource : 'Application::modebig_161_225' */
EW_DECLARE_BITMAP_RES( Applicationmodebig_161_225 )

/* Bitmap resource : 'Application::settings1_50_44' */
EW_DECLARE_BITMAP_RES( Applicationsettings1_50_44 )

/* Bitmap resource : 'Application::settings2_200_175' */
EW_DECLARE_BITMAP_RES( Applicationsettings2_200_175 )

/* Bitmap resource : 'Application::settings_50_49' */
EW_DECLARE_BITMAP_RES( Applicationsettings_50_49 )

/* Bitmap resource : 'Application::shutdown_43_50' */
EW_DECLARE_BITMAP_RES( Applicationshutdown_43_50 )

/* Bitmap resource : 'Application::shutdown_big_69_80' */
EW_DECLARE_BITMAP_RES( Applicationshutdown_big_69_80 )

/* Bitmap resource : 'Application::weather_35_30' */
EW_DECLARE_BITMAP_RES( Applicationweather_35_30 )

/* Bitmap resource : 'Application::wifi_48_40' */
EW_DECLARE_BITMAP_RES( Applicationwifi_48_40 )

/* Font resource : 'Application::Font1' */
EW_DECLARE_FONT_RES( ApplicationFont1 )

/* Bitmap resource : 'Application::Increment' */
EW_DECLARE_BITMAP_RES( ApplicationIncrement )

/* Bitmap resource : 'Application::decrement' */
EW_DECLARE_BITMAP_RES( Applicationdecrement )

/* Bitmap resource : 'Application::black_60_60' */
EW_DECLARE_BITMAP_RES( Applicationblack_60_60 )

/* User defined auto object: 'Application::Device' */
EW_DECLARE_AUTOOBJECT( ApplicationDevice, ApplicationDeviceClass )

/* User defined constant: 'Application::ColorCold' */
extern const XColor ApplicationColorCold;

/* User defined constant: 'Application::ColorHot' */
extern const XColor ApplicationColorHot;

#ifdef __cplusplus
  }
#endif

#endif /* Application_H */

/* Embedded Wizard */
