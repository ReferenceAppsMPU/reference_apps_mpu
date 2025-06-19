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

#include "ewlocale.h"
#include "_ApplicationApplication.h"
#include "_ApplicationBrightnessController.h"
#include "_ApplicationDeviceClass.h"
#include "_ApplicationFanController.h"
#include "_ApplicationModeController.h"
#include "_ApplicationTemperatureController.h"
#include "_ApplicationThermostat.h"
#include "_CoreGroup.h"
#include "_CorePropertyObserver.h"
#include "_CoreRotateTouchHandler.h"
#include "_CoreSimpleTouchHandler.h"
#include "_CoreTimer.h"
#include "_CoreView.h"
#include "_EffectsFadeInOutTransition.h"
#include "_EffectsRectEffect.h"
#include "_EffectsTransition.h"
#include "_GraphicsPath.h"
#include "_ResourcesBitmap.h"
#include "_ResourcesFont.h"
#include "_ViewsImage.h"
#include "_ViewsRectangle.h"
#include "_ViewsStrokePath.h"
#include "_ViewsText.h"
#include "_ViewsWarpImage.h"
#include "_WidgetSetHorizontalSlider.h"
#include "_WidgetSetHorizontalSliderConfig.h"
#include "Application.h"
#include "Core.h"
#include "Effects.h"
#include "Graphics.h"
#include "Resources.h"
#include "Views.h"

/* Compressed strings for the language 'Default'. */
EW_CONST_STRING_PRAGMA static const unsigned int _StringsDefault0[] =
{
  0x0000021E, /* ratio 56.83 % */
  0xB8000B00, 0x80082452, 0x1A120026, 0x61045818, 0x12720018, 0x70C07802, 0x103A8008,
  0xE0019633, 0x001D0006, 0x78020E20, 0x800C8003, 0x300F098D, 0x06000194, 0x2C005800,
  0x30C04C26, 0x2392C709, 0x284C4673, 0x994C2090, 0x04541800, 0x98E32690, 0x00D8008B,
  0x2511F878, 0x0D049500, 0x5248FC62, 0x0027C321, 0x489564CC, 0x0014E181, 0xDC6E2347,
  0x90A431D8, 0x00CF458C, 0xE6F1E340, 0xE00039C6, 0x036864A6, 0x129FCB00, 0x619916A1,
  0xBF094017, 0x74301D12, 0xC3A437C9, 0xBA59218C, 0xA2435964, 0x7400BA02, 0x12D18800,
  0x22280024, 0x7BE412E7, 0x9EC4A637, 0x4C872445, 0x68E18048, 0xF74C0800, 0x31A00C5D,
  0xFF7F864F, 0xF0C08C26, 0x4600510A, 0x48B4876E, 0x8DC763B2, 0x7CE29B47, 0x4233104D,
  0x2C9504AB, 0x48BC89BD, 0x24628DEE, 0x000A8C2E, 0x87E6C64E, 0xA86748F3, 0xE6C7631C,
  0xA76E93DD, 0xF36D518E, 0x37AD1BAF, 0x7C7C1AC7, 0xED392711, 0x127227B8, 0x0C0B44AC,
  0xB8C52ACF, 0x8FCE6A91, 0x9396ED6C, 0xB7B5F56F, 0x49124991, 0x00001014, 0x00000000
};

/* Constant values used in this 'C' module only. */
static const XRect _Const0000 = {{ 0, 0 }, { 720, 720 }};
static const XStringRes _Const0001 = { _StringsDefault0, 0x0002 };
static const XStringRes _Const0002 = { _StringsDefault0, 0x0007 };
static const XRect _Const0003 = {{ 103, 425 }, { 449, 497 }};
static const XStringRes _Const0004 = { _StringsDefault0, 0x000D };
static const XRect _Const0005 = {{ 115, 179 }, { 387, 418 }};
static const XRect _Const0006 = {{ 460, 98 }, { 510, 148 }};
static const XRect _Const0007 = {{ 556, 169 }, { 606, 219 }};
static const XRect _Const0008 = {{ 556, 312 }, { 614, 384 }};
static const XRect _Const0009 = {{ 485, 435 }, { 535, 485 }};
static const XPoint _Const000A = { 421, 56 };
static const XPoint _Const000B = { 521, 56 };
static const XPoint _Const000C = { 521, 156 };
static const XPoint _Const000D = { 421, 156 };
static const XPoint _Const000E = { 535, 156 };
static const XPoint _Const000F = { 635, 156 };
static const XPoint _Const0010 = { 635, 256 };
static const XPoint _Const0011 = { 535, 256 };
static const XPoint _Const0012 = { 528, 292 };
static const XPoint _Const0013 = { 628, 292 };
static const XPoint _Const0014 = { 628, 392 };
static const XPoint _Const0015 = { 528, 392 };
static const XPoint _Const0016 = { 471, 411 };
static const XPoint _Const0017 = { 571, 411 };
static const XPoint _Const0018 = { 571, 511 };
static const XPoint _Const0019 = { 471, 511 };
static const XRect _Const001A = {{ 335, 196 }, { 385, 246 }};
static const XRect _Const001B = {{ 337, 412 }, { 387, 462 }};
static const XColor _Const001C = { 0xFF, 0x71, 0x55, 0xFF };
static const XPoint _Const001D = { 0, 0 };
static const XRect _Const001E = {{ 327, 323 }, { 405, 397 }};
static const XRect _Const001F = {{ 267, 263 }, { 412, 333 }};
static const XStringRes _Const0020 = { _StringsDefault0, 0x001C };
static const XColor _Const0021 = { 0x00, 0x00, 0x00, 0xFF };
static const XPoint _Const0022 = { 323, 263 };
static const XPoint _Const0023 = { 401, 263 };
static const XPoint _Const0024 = { 401, 193 };
static const XPoint _Const0025 = { 323, 193 };
static const XPoint _Const0026 = { 323, 466 };
static const XPoint _Const0027 = { 401, 466 };
static const XPoint _Const0028 = { 401, 396 };
static const XPoint _Const0029 = { 323, 396 };
static const XPoint _Const002A = { 362, 99 };
static const XPoint _Const002B = { 373, 124 };
static const XPoint _Const002C = { 397, 116 };
static const XPoint _Const002D = { 381, 84 };
static const XPoint _Const002E = { 25, 157 };
static const XRect _Const002F = {{ 199, 503 }, { 363, 562 }};
static const XStringRes _Const0030 = { _StringsDefault0, 0x0023 };
static const XRect _Const0031 = {{ 353, 503 }, { 472, 562 }};
static const XStringRes _Const0032 = { _StringsDefault0, 0x002C };
static const XColor _Const0033 = { 0xFF, 0x00, 0x00, 0xFF };
static const XRect _Const0034 = {{ 103, 285 }, { 231, 413 }};
static const XRect _Const0035 = {{ 296, 285 }, { 424, 413 }};
static const XRect _Const0036 = {{ 522, 285 }, { 650, 413 }};
static const XRect _Const0037 = {{ 98, 396 }, { 231, 460 }};
static const XStringRes _Const0038 = { _StringsDefault0, 0x0031 };
static const XRect _Const0039 = {{ 291, 396 }, { 424, 460 }};
static const XStringRes _Const003A = { _StringsDefault0, 0x003D };
static const XRect _Const003B = {{ 522, 396 }, { 655, 460 }};
static const XStringRes _Const003C = { _StringsDefault0, 0x0044 };
static const XRect _Const003D = {{ 280, 586 }, { 330, 636 }};
static const XPoint _Const003E = { 257, 565 };
static const XPoint _Const003F = { 357, 565 };
static const XPoint _Const0040 = { 357, 665 };
static const XPoint _Const0041 = { 257, 665 };
static const XRect _Const0042 = {{ 332, 525 }, { 382, 575 }};
static const XRect _Const0043 = {{ 257, 403 }, { 457, 458 }};
static const XStringRes _Const0044 = { _StringsDefault0, 0x004A };
static const XPoint _Const0045 = { 313, 514 };
static const XPoint _Const0046 = { 413, 514 };
static const XPoint _Const0047 = { 413, 592 };
static const XPoint _Const0048 = { 313, 592 };
static const XColor _Const0049 = { 0x00, 0x00, 0x00, 0x11 };
static const XPoint _Const004A = { 86, 86 };
static const XPoint _Const004B = { 76, 76 };
static const XColor _Const004C = { 0x01, 0x00, 0x05, 0xFF };
static const XPoint _Const004D = { 48, 48 };
static const XColor _Const004E = { 0x00, 0x00, 0x00, 0x22 };
static const XColor _Const004F = { 0xEE, 0xEE, 0xEE, 0xFF };
static const XColor _Const0050 = { 0xAA, 0x2E, 0x55, 0xFF };
static const XRect _Const0051 = {{ 175, 295 }, { 563, 360 }};
static const XRect _Const0052 = {{ 328, 485 }, { 375, 540 }};
static const XColor _Const0053 = { 0x1D, 0x74, 0xB9, 0xFF };
static const XRect _Const0054 = {{ 383, 485 }, { 430, 540 }};
static const XRect _Const0055 = {{ 410, 287 }, { 480, 351 }};
static const XRect _Const0056 = {{ 302, 280 }, { 410, 339 }};
static const XStringRes _Const0057 = { _StringsDefault0, 0x005E };
static const XRect _Const0058 = {{ 335, 339 }, { 385, 363 }};
static const XStringRes _Const0059 = { _StringsDefault0, 0x0065 };
static const XRect _Const005A = {{ 261, 295 }, { 312, 348 }};
static const XRect _Const005B = {{ 309, 163 }, { 415, 187 }};
static const XStringRes _Const005C = { _StringsDefault0, 0x006C };
static const XRect _Const005D = {{ 293, 139 }, { 399, 163 }};
static const XStringRes _Const005E = { _StringsDefault0, 0x007A };
static const XRect _Const005F = {{ 219, 144 }, { 258, 183 }};
static const XRect _Const0060 = {{ 244, 145 }, { 312, 181 }};
static const XStringRes _Const0061 = { _StringsDefault0, 0x0084 };
static const XRect _Const0062 = {{ 317, 336 }, { 334, 359 }};
static const XRect _Const0063 = {{ 396, 493 }, { 416, 532 }};
static const XRect _Const0064 = {{ 485, 198 }, { 535, 248 }};
static const XRect _Const0065 = {{ 547, 271 }, { 597, 321 }};
static const XRect _Const0066 = {{ 547, 363 }, { 597, 413 }};
static const XPoint _Const0067 = { 727, 0 };
static const XPoint _Const0068 = { 727, 720 };
static const XPoint _Const0069 = { 7, 720 };
static const XPoint _Const006A = { 317, 478 };
static const XPoint _Const006B = { 380, 478 };
static const XPoint _Const006C = { 380, 550 };
static const XPoint _Const006D = { 317, 550 };
static const XPoint _Const006E = { 385, 478 };
static const XPoint _Const006F = { 448, 478 };
static const XPoint _Const0070 = { 448, 550 };
static const XPoint _Const0071 = { 385, 550 };
static const XPoint _Const0072 = { 484, 192 };
static const XPoint _Const0073 = { 547, 192 };
static const XPoint _Const0074 = { 547, 264 };
static const XPoint _Const0075 = { 484, 264 };
static const XPoint _Const0076 = { 548, 259 };
static const XPoint _Const0077 = { 611, 259 };
static const XPoint _Const0078 = { 611, 331 };
static const XPoint _Const0079 = { 548, 331 };
static const XPoint _Const007A = { 535, 359 };
static const XPoint _Const007B = { 598, 359 };
static const XPoint _Const007C = { 598, 431 };
static const XPoint _Const007D = { 535, 431 };
static const XPoint _Const007E = { 485, 435 };
static const XPoint _Const007F = { 548, 435 };
static const XPoint _Const0080 = { 548, 507 };
static const XPoint _Const0081 = { 485, 507 };
static const XRect _Const0082 = {{ 192, 573 }, { 535, 613 }};
static const XColor _Const0083 = { 0xB5, 0xFF, 0xCE, 0xFF };
static const XRect _Const0084 = {{ 230, 208 }, { 462, 248 }};
static const XStringRes _Const0085 = { _StringsDefault0, 0x008B };
static const XStringRes _Const0086 = { _StringsDefault0, 0x0090 };
static const XStringRes _Const0087 = { _StringsDefault0, 0x0094 };
static const XColor _Const0088 = { 0x06, 0x18, 0x27, 0xA6 };
static const XColor _Const0089 = { 0xB8, 0x69, 0x2D, 0xD1 };
static const XStringRes _Const008A = { _StringsDefault0, 0x009C };
static const XStringRes _Const008B = { _StringsDefault0, 0x00A1 };
static const XStringRes _Const008C = { _StringsDefault0, 0x00B2 };
static const XStringRes _Const008D = { _StringsDefault0, 0x00B7 };
static const XStringRes _Const008E = { _StringsDefault0, 0x00BD };
static const XStringRes _Const008F = { _StringsDefault0, 0x00C3 };
static const XStringRes _Const0090 = { _StringsDefault0, 0x00C9 };
static const XStringRes _Const0091 = { _StringsDefault0, 0x00CF };
static const XStringRes _Const0092 = { _StringsDefault0, 0x00D5 };
static const XStringRes _Const0093 = { _StringsDefault0, 0x00DB };
static const XStringRes _Const0094 = { _StringsDefault0, 0x00E1 };
static const XStringRes _Const0095 = { _StringsDefault0, 0x00E7 };
static const XStringRes _Const0096 = { _StringsDefault0, 0x00ED };
static const XStringRes _Const0097 = { _StringsDefault0, 0x00F3 };
static const XStringRes _Const0098 = { _StringsDefault0, 0x00F9 };

/* Initializer for the class 'Application::Application' */
void ApplicationApplication__Init( ApplicationApplication _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreRoot__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( ApplicationApplication );

  /* ... then construct all embedded objects */
  ApplicationThermostat__Init( &_this->Thermostat, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( ApplicationApplication );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->Thermostat, _Const0000 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Thermostat ), 0 );
}

/* Re-Initializer for the class 'Application::Application' */
void ApplicationApplication__ReInit( ApplicationApplication _this )
{
  /* At first re-initialize the super class ... */
  CoreRoot__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ApplicationThermostat__ReInit( &_this->Thermostat );
}

/* Finalizer method for the class 'Application::Application' */
void ApplicationApplication__Done( ApplicationApplication _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreRoot );

  /* Finalize all embedded objects */
  ApplicationThermostat__Done( &_this->Thermostat );

  /* Don't forget to deinitialize the super class ... */
  CoreRoot__Done( &_this->_.Super );
}

/* Variants derived from the class : 'Application::Application' */
EW_DEFINE_CLASS_VARIANTS( ApplicationApplication )
EW_END_OF_CLASS_VARIANTS( ApplicationApplication )

/* Virtual Method Table (VMT) for the class : 'Application::Application' */
EW_DEFINE_CLASS( ApplicationApplication, CoreRoot, Thermostat, _.VMT, _.VMT, _.VMT, 
                 _.VMT, _.VMT, "Application::Application" )
  CoreRectView_initLayoutContext,
  CoreRoot_GetRoot,
  CoreRoot_Draw,
  CoreGroup_GetClipping,
  CoreView_HandleEvent,
  CoreGroup_CursorHitTest,
  CoreGroup_AdjustDrawingArea,
  CoreRectView_ArrangeView,
  CoreRectView_MoveView,
  CoreRectView_GetExtent,
  CoreRoot_ChangeViewState,
  CoreGroup_OnSetBounds,
  CoreRoot_OnSetFocus,
  CoreRoot_OnSetOpacity,
  CoreRoot_DispatchEvent,
  CoreRoot_BroadcastEvent,
  CoreGroup_UpdateLayout,
  CoreGroup_UpdateViewState,
  CoreRoot_InvalidateArea,
EW_END_OF_CLASS( ApplicationApplication )

/* Include a file containing the font resource : 'Application::Font' */
#include "_ApplicationFont.h"

/* Table with links to derived variants of the font resource : 'Application::Font' */
EW_RES_WITHOUT_VARIANTS( ApplicationFont )

/* Include a file containing the bitmap resource : 'Application::Bluetooth_21_40' */
#include "_ApplicationBluetooth_21_40.h"

/* Table with links to derived variants of the bitmap resource : 'Application::Bluetooth_21_40' */
EW_RES_WITHOUT_VARIANTS( ApplicationBluetooth_21_40 )

/* Include a file containing the bitmap resource : 'Application::Circulate_75_80' */
#include "_ApplicationCirculate_75_80.h"

/* Table with links to derived variants of the bitmap resource : 'Application::Circulate_75_80' */
EW_RES_WITHOUT_VARIANTS( ApplicationCirculate_75_80 )

/* Include a file containing the bitmap resource : 'Application::arrow_40_32' */
#include "_Applicationarrow_40_32.h"

/* Table with links to derived variants of the bitmap resource : 'Application::arrow_40_32' */
EW_RES_WITHOUT_VARIANTS( Applicationarrow_40_32 )

/* Include a file containing the bitmap resource : 'Application::bg_black' */
#include "_Applicationbg_black.h"

/* Table with links to derived variants of the bitmap resource : 'Application::bg_black' */
EW_RES_WITHOUT_VARIANTS( Applicationbg_black )

/* Include a file containing the bitmap resource : 'Application::bg_brown' */
#include "_Applicationbg_brown.h"

/* Table with links to derived variants of the bitmap resource : 'Application::bg_brown' */
EW_RES_WITHOUT_VARIANTS( Applicationbg_brown )

/* Include a file containing the bitmap resource : 'Application::blue1_60_60' */
#include "_Applicationblue1_60_60.h"

/* Table with links to derived variants of the bitmap resource : 'Application::blue1_60_60' */
EW_RES_WITHOUT_VARIANTS( Applicationblue1_60_60 )

/* Include a file containing the bitmap resource : 'Application::blue_720_720' */
#include "_Applicationblue_720_720.h"

/* Table with links to derived variants of the bitmap resource : 'Application::blue_720_720' */
EW_RES_WITHOUT_VARIANTS( Applicationblue_720_720 )

/* Include a file containing the bitmap resource : 'Application::brown_60_60' */
#include "_Applicationbrown_60_60.h"

/* Table with links to derived variants of the bitmap resource : 'Application::brown_60_60' */
EW_RES_WITHOUT_VARIANTS( Applicationbrown_60_60 )

/* Include a file containing the bitmap resource : 'Application::circulate_invert_80_79' */
#include "_Applicationcirculate_invert_80_79.h"

/* Table with links to derived variants of the bitmap resource : 'Application::circulate_invert_80_79' */
EW_RES_WITHOUT_VARIANTS( Applicationcirculate_invert_80_79 )

/* Include a file containing the bitmap resource : 'Application::coolset' */
#include "_Applicationcoolset.h"

/* Table with links to derived variants of the bitmap resource : 'Application::coolset' */
EW_RES_WITHOUT_VARIANTS( Applicationcoolset )

/* Include a file containing the bitmap resource : 'Application::fan_50_50' */
#include "_Applicationfan_50_50.h"

/* Table with links to derived variants of the bitmap resource : 'Application::fan_50_50' */
EW_RES_WITHOUT_VARIANTS( Applicationfan_50_50 )

/* Include a file containing the bitmap resource : 'Application::home1_24_23' */
#include "_Applicationhome1_24_23.h"

/* Table with links to derived variants of the bitmap resource : 'Application::home1_24_23' */
EW_RES_WITHOUT_VARIANTS( Applicationhome1_24_23 )

/* Include a file containing the bitmap resource : 'Application::hot_cold_49_60' */
#include "_Applicationhot_cold_49_60.h"

/* Table with links to derived variants of the bitmap resource : 'Application::hot_cold_49_60' */
EW_RES_WITHOUT_VARIANTS( Applicationhot_cold_49_60 )

/* Include a file containing the bitmap resource : 'Application::hotmode_43_60' */
#include "_Applicationhotmode_43_60.h"

/* Table with links to derived variants of the bitmap resource : 'Application::hotmode_43_60' */
EW_RES_WITHOUT_VARIANTS( Applicationhotmode_43_60 )

/* Include a file containing the bitmap resource : 'Application::humidity_small_14_18' */
#include "_Applicationhumidity_small_14_18.h"

/* Table with links to derived variants of the bitmap resource : 'Application::humidity_small_14_18' */
EW_RES_WITHOUT_VARIANTS( Applicationhumidity_small_14_18 )

/* Include a file containing the bitmap resource : 'Application::mode_50_70' */
#include "_Applicationmode_50_70.h"

/* Table with links to derived variants of the bitmap resource : 'Application::mode_50_70' */
EW_RES_WITHOUT_VARIANTS( Applicationmode_50_70 )

/* Include a file containing the bitmap resource : 'Application::modebig_161_225' */
#include "_Applicationmodebig_161_225.h"

/* Table with links to derived variants of the bitmap resource : 'Application::modebig_161_225' */
EW_RES_WITHOUT_VARIANTS( Applicationmodebig_161_225 )

/* Include a file containing the bitmap resource : 'Application::settings1_50_44' */
#include "_Applicationsettings1_50_44.h"

/* Table with links to derived variants of the bitmap resource : 'Application::settings1_50_44' */
EW_RES_WITHOUT_VARIANTS( Applicationsettings1_50_44 )

/* Include a file containing the bitmap resource : 'Application::settings2_200_175' */
#include "_Applicationsettings2_200_175.h"

/* Table with links to derived variants of the bitmap resource : 'Application::settings2_200_175' */
EW_RES_WITHOUT_VARIANTS( Applicationsettings2_200_175 )

/* Include a file containing the bitmap resource : 'Application::settings_50_49' */
#include "_Applicationsettings_50_49.h"

/* Table with links to derived variants of the bitmap resource : 'Application::settings_50_49' */
EW_RES_WITHOUT_VARIANTS( Applicationsettings_50_49 )

/* Include a file containing the bitmap resource : 'Application::shutdown_43_50' */
#include "_Applicationshutdown_43_50.h"

/* Table with links to derived variants of the bitmap resource : 'Application::shutdown_43_50' */
EW_RES_WITHOUT_VARIANTS( Applicationshutdown_43_50 )

/* Include a file containing the bitmap resource : 'Application::shutdown_big_69_80' */
#include "_Applicationshutdown_big_69_80.h"

/* Table with links to derived variants of the bitmap resource : 'Application::shutdown_big_69_80' */
EW_RES_WITHOUT_VARIANTS( Applicationshutdown_big_69_80 )

/* Include a file containing the bitmap resource : 'Application::weather_35_30' */
#include "_Applicationweather_35_30.h"

/* Table with links to derived variants of the bitmap resource : 'Application::weather_35_30' */
EW_RES_WITHOUT_VARIANTS( Applicationweather_35_30 )

/* Include a file containing the bitmap resource : 'Application::wifi_48_40' */
#include "_Applicationwifi_48_40.h"

/* Table with links to derived variants of the bitmap resource : 'Application::wifi_48_40' */
EW_RES_WITHOUT_VARIANTS( Applicationwifi_48_40 )

/* Include a file containing the font resource : 'Application::Font1' */
#include "_ApplicationFont1.h"

/* Table with links to derived variants of the font resource : 'Application::Font1' */
EW_RES_WITHOUT_VARIANTS( ApplicationFont1 )

/* Initializer for the class 'Application::DeviceClass' */
void ApplicationDeviceClass__Init( ApplicationDeviceClass _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  TemplatesDeviceClass__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( ApplicationDeviceClass );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( ApplicationDeviceClass );

  /* ... and initialize objects, variables, properties, etc. */
  _this->Brightness = 225;
  _this->Mode = 2;
  _this->Day = 3;
  _this->Temperature = 25;
  _this->Minute = 25;
  _this->Hour = 11;
  _this->Year = 2025;
  _this->am_pm = EwShareString( EwLoadString( &_Const0001 ));
  _this->Humidity = 50;
  _this->month = EwShareString( EwLoadString( &_Const0002 ));
  _this->Month = 11;
}

/* Re-Initializer for the class 'Application::DeviceClass' */
void ApplicationDeviceClass__ReInit( ApplicationDeviceClass _this )
{
  /* At first re-initialize the super class ... */
  TemplatesDeviceClass__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Application::DeviceClass' */
void ApplicationDeviceClass__Done( ApplicationDeviceClass _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( TemplatesDeviceClass );

  /* Don't forget to deinitialize the super class ... */
  TemplatesDeviceClass__Done( &_this->_.Super );
}

/* 'C' function for method : 'Application::DeviceClass.OnSetMode()' */
void ApplicationDeviceClass_OnSetMode( ApplicationDeviceClass _this, XInt32 value )
{
  if ( _this->Mode == value )
    return;

  _this->Mode = value;
  {
    /*
       TO DO:

       You can call a function of your own device API or you simply
       modify a variable existing in your middleware to reflect the
       new value:

       YourDevice_SetSomeValue( value );

       or

       YourDevice_SomeVariable = value;
    */
  }
  EwNotifyRefObservers( EwNewRef( _this, ApplicationDeviceClass_OnGetMode, ApplicationDeviceClass_OnSetMode ), 
    0 );
}

/* 'C' function for method : 'Application::DeviceClass.OnSetWifiConnected()' */
void ApplicationDeviceClass_OnSetWifiConnected( ApplicationDeviceClass _this, XBool 
  value )
{
  if ( _this->WifiConnected == value )
    return;

  _this->WifiConnected = value;
  EwNotifyRefObservers( EwNewRef( _this, ApplicationDeviceClass_OnGetWifiConnected, 
    ApplicationDeviceClass_OnSetWifiConnected ), 0 );
}

/* Default onget method for the property 'Brightness' */
XInt32 ApplicationDeviceClass_OnGetBrightness( ApplicationDeviceClass _this )
{
  return _this->Brightness;
}

/* Default onset method for the property 'Brightness' */
void ApplicationDeviceClass_OnSetBrightness( ApplicationDeviceClass _this, XInt32 
  value )
{
  _this->Brightness = value;
}

/* Default onget method for the property 'Mode' */
XInt32 ApplicationDeviceClass_OnGetMode( ApplicationDeviceClass _this )
{
  return _this->Mode;
}

/* Default onget method for the property 'WifiConnected' */
XBool ApplicationDeviceClass_OnGetWifiConnected( ApplicationDeviceClass _this )
{
  return _this->WifiConnected;
}

/* Default onget method for the property 'BtConnected' */
XBool ApplicationDeviceClass_OnGetBtConnected( ApplicationDeviceClass _this )
{
  return _this->BtConnected;
}

/* Default onset method for the property 'BtConnected' */
void ApplicationDeviceClass_OnSetBtConnected( ApplicationDeviceClass _this, XBool 
  value )
{
  _this->BtConnected = value;
}

/* Default onget method for the property 'Day' */
XInt32 ApplicationDeviceClass_OnGetDay( ApplicationDeviceClass _this )
{
  return _this->Day;
}

/* Default onset method for the property 'Day' */
void ApplicationDeviceClass_OnSetDay( ApplicationDeviceClass _this, XInt32 value )
{
  _this->Day = value;
}

/* Default onget method for the property 'Year' */
XInt32 ApplicationDeviceClass_OnGetYear( ApplicationDeviceClass _this )
{
  return _this->Year;
}

/* Default onset method for the property 'Year' */
void ApplicationDeviceClass_OnSetYear( ApplicationDeviceClass _this, XInt32 value )
{
  _this->Year = value;
}

/* Default onget method for the property 'Month' */
XInt32 ApplicationDeviceClass_OnGetMonth( ApplicationDeviceClass _this )
{
  return _this->Month;
}

/* Default onset method for the property 'Month' */
void ApplicationDeviceClass_OnSetMonth( ApplicationDeviceClass _this, XInt32 value )
{
  _this->Month = value;
}

/* Variants derived from the class : 'Application::DeviceClass' */
EW_DEFINE_CLASS_VARIANTS( ApplicationDeviceClass )
EW_END_OF_CLASS_VARIANTS( ApplicationDeviceClass )

/* Virtual Method Table (VMT) for the class : 'Application::DeviceClass' */
EW_DEFINE_CLASS( ApplicationDeviceClass, TemplatesDeviceClass, am_pm, am_pm, am_pm, 
                 am_pm, am_pm, Brightness, "Application::DeviceClass" )
EW_END_OF_CLASS( ApplicationDeviceClass )

/* User defined auto object: 'Application::Device' */
EW_DEFINE_AUTOOBJECT( ApplicationDevice, ApplicationDeviceClass )

/* Initializer for the auto object 'Application::Device' */
void ApplicationDevice__Init( ApplicationDeviceClass _this )
{
  EW_UNUSED_ARG( _this );
}

/* Re-Initializer for the auto object 'Application::Device' */
void ApplicationDevice__ReInit( ApplicationDeviceClass _this )
{
  EW_UNUSED_ARG( _this );
}

/* Table with links to derived variants of the auto object : 'Application::Device' */
EW_DEFINE_AUTOOBJECT_VARIANTS( ApplicationDevice )
EW_END_OF_AUTOOBJECT_VARIANTS( ApplicationDevice )

/* User defined constant: 'Application::ColorCold' */
const XColor ApplicationColorCold = { 0x14, 0x88, 0xD7, 0xFF };

/* User defined constant: 'Application::ColorHot' */
const XColor ApplicationColorHot = { 0xE8, 0x9F, 0x6A, 0xFF };

/* Include a file containing the bitmap resource : 'Application::Increment' */
#include "_ApplicationIncrement.h"

/* Table with links to derived variants of the bitmap resource : 'Application::Increment' */
EW_RES_WITHOUT_VARIANTS( ApplicationIncrement )

/* Include a file containing the bitmap resource : 'Application::decrement' */
#include "_Applicationdecrement.h"

/* Table with links to derived variants of the bitmap resource : 'Application::decrement' */
EW_RES_WITHOUT_VARIANTS( Applicationdecrement )

/* Initializer for the class 'Application::ModeController' */
void ApplicationModeController__Init( ApplicationModeController _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( ApplicationModeController );

  /* ... then construct all embedded objects */
  ViewsImage__Init( &_this->Background, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->CurrentMode, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->Image, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->Mode, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->Fan, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->ScreenBrightness, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->Off, &_this->_.XObject, 0 );
  CoreSimpleTouchHandler__Init( &_this->SimpleTouchHandler, &_this->_.XObject, 0 );
  CoreSimpleTouchHandler__Init( &_this->SimpleTouchHandler1, &_this->_.XObject, 0 );
  CoreSimpleTouchHandler__Init( &_this->SimpleTouchHandler2, &_this->_.XObject, 0 );
  CoreSimpleTouchHandler__Init( &_this->SimpleTouchHandler3, &_this->_.XObject, 0 );
  CorePropertyObserver__Init( &_this->PropertyObserver, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( ApplicationModeController );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( &_this->Background, _Const0000 );
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->CurrentMode, _Const0003 );
  ViewsText_OnSetString( &_this->CurrentMode, EwLoadString( &_Const0004 ));
  CoreRectView__OnSetBounds( &_this->Image, _Const0005 );
  CoreRectView__OnSetBounds( &_this->Mode, _Const0006 );
  CoreRectView__OnSetBounds( &_this->Fan, _Const0007 );
  CoreRectView__OnSetBounds( &_this->ScreenBrightness, _Const0008 );
  CoreRectView__OnSetBounds( &_this->Off, _Const0009 );
  CoreQuadView__OnSetPoint4( &_this->SimpleTouchHandler, _Const000A );
  CoreQuadView__OnSetPoint3( &_this->SimpleTouchHandler, _Const000B );
  CoreQuadView__OnSetPoint2( &_this->SimpleTouchHandler, _Const000C );
  CoreQuadView__OnSetPoint1( &_this->SimpleTouchHandler, _Const000D );
  CoreQuadView__OnSetPoint4( &_this->SimpleTouchHandler1, _Const000E );
  CoreQuadView__OnSetPoint3( &_this->SimpleTouchHandler1, _Const000F );
  CoreQuadView__OnSetPoint2( &_this->SimpleTouchHandler1, _Const0010 );
  CoreQuadView__OnSetPoint1( &_this->SimpleTouchHandler1, _Const0011 );
  CoreQuadView__OnSetPoint4( &_this->SimpleTouchHandler2, _Const0012 );
  CoreQuadView__OnSetPoint3( &_this->SimpleTouchHandler2, _Const0013 );
  CoreQuadView__OnSetPoint2( &_this->SimpleTouchHandler2, _Const0014 );
  CoreQuadView__OnSetPoint1( &_this->SimpleTouchHandler2, _Const0015 );
  CoreQuadView__OnSetPoint4( &_this->SimpleTouchHandler3, _Const0016 );
  CoreQuadView__OnSetPoint3( &_this->SimpleTouchHandler3, _Const0017 );
  CoreQuadView__OnSetPoint2( &_this->SimpleTouchHandler3, _Const0018 );
  CoreQuadView__OnSetPoint1( &_this->SimpleTouchHandler3, _Const0019 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Background ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->CurrentMode ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Image ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Mode ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Fan ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->ScreenBrightness ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Off ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->SimpleTouchHandler ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->SimpleTouchHandler1 ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->SimpleTouchHandler2 ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->SimpleTouchHandler3 ), 0 );
  ViewsImage_OnSetBitmap( &_this->Background, EwLoadResource( &Applicationblue_720_720, 
  ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->CurrentMode, EwLoadResource( &ApplicationFont1, ResourcesFont ));
  ViewsImage_OnSetBitmap( &_this->Image, EwLoadResource( &Applicationsettings2_200_175, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->Mode, EwLoadResource( &Applicationarrow_40_32, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->Fan, EwLoadResource( &Applicationshutdown_43_50, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->ScreenBrightness, EwLoadResource( &Applicationmode_50_70, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->Off, EwLoadResource( &Applicationsettings1_50_44, 
  ResourcesBitmap ));
  _this->SimpleTouchHandler.OnPress = EwNewSlot( _this, ApplicationModeController_SlotMethod1 );
  _this->SimpleTouchHandler1.OnPress = EwNewSlot( _this, ApplicationModeController_SlotMethod2 );
  _this->SimpleTouchHandler2.OnPress = EwNewSlot( _this, ApplicationModeController_SlotMethod3 );
  _this->SimpleTouchHandler3.OnPress = EwNewSlot( _this, ApplicationModeController_SlotMethod4 );
  _this->PropertyObserver.OnEvent = EwNewSlot( _this, ApplicationModeController_onEvent );
  CorePropertyObserver_OnSetOutlet( &_this->PropertyObserver, EwNewRef( EwGetAutoObject( 
  &ApplicationDevice, ApplicationDeviceClass ), ApplicationDeviceClass_OnGetMode, 
  ApplicationDeviceClass_OnSetMode ));

  /* Call the user defined constructor */
  ApplicationModeController_Init( _this, aArg );
}

/* Re-Initializer for the class 'Application::ModeController' */
void ApplicationModeController__ReInit( ApplicationModeController _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsImage__ReInit( &_this->Background );
  ViewsText__ReInit( &_this->CurrentMode );
  ViewsImage__ReInit( &_this->Image );
  ViewsImage__ReInit( &_this->Mode );
  ViewsImage__ReInit( &_this->Fan );
  ViewsImage__ReInit( &_this->ScreenBrightness );
  ViewsImage__ReInit( &_this->Off );
  CoreSimpleTouchHandler__ReInit( &_this->SimpleTouchHandler );
  CoreSimpleTouchHandler__ReInit( &_this->SimpleTouchHandler1 );
  CoreSimpleTouchHandler__ReInit( &_this->SimpleTouchHandler2 );
  CoreSimpleTouchHandler__ReInit( &_this->SimpleTouchHandler3 );
  CorePropertyObserver__ReInit( &_this->PropertyObserver );
}

/* Finalizer method for the class 'Application::ModeController' */
void ApplicationModeController__Done( ApplicationModeController _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsImage__Done( &_this->Background );
  ViewsText__Done( &_this->CurrentMode );
  ViewsImage__Done( &_this->Image );
  ViewsImage__Done( &_this->Mode );
  ViewsImage__Done( &_this->Fan );
  ViewsImage__Done( &_this->ScreenBrightness );
  ViewsImage__Done( &_this->Off );
  CoreSimpleTouchHandler__Done( &_this->SimpleTouchHandler );
  CoreSimpleTouchHandler__Done( &_this->SimpleTouchHandler1 );
  CoreSimpleTouchHandler__Done( &_this->SimpleTouchHandler2 );
  CoreSimpleTouchHandler__Done( &_this->SimpleTouchHandler3 );
  CorePropertyObserver__Done( &_this->PropertyObserver );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void ApplicationModeController_Init( ApplicationModeController _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  if ( EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Mode == 0 )
  {
    ViewsImage_OnSetBitmap( &_this->Image, EwLoadResource( &Applicationshutdown_big_69_80, 
    ResourcesBitmap ));
    ViewsImage_OnSetBitmap( &_this->Background, EwLoadResource( &Applicationbg_black, 
    ResourcesBitmap ));
  }
  else
    if ( EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Mode == 
        1 )
    {
      ViewsImage_OnSetBitmap( &_this->Image, EwLoadResource( &Applicationmodebig_161_225, 
      ResourcesBitmap ));
      ViewsImage_OnSetBitmap( &_this->Background, EwLoadResource( &Applicationbg_brown, 
      ResourcesBitmap ));
    }
    else
    {
      ViewsImage_OnSetBitmap( &_this->Image, EwLoadResource( &Applicationsettings2_200_175, 
      ResourcesBitmap ));
      ViewsImage_OnSetBitmap( &_this->Background, EwLoadResource( &Applicationblue_720_720, 
      ResourcesBitmap ));
    }
}

/* 'C' function for method : 'Application::ModeController.SlotMethod1()' */
void ApplicationModeController_SlotMethod1( ApplicationModeController _this, XObject 
  sender )
{
  CoreGroup newDialog;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  newDialog = ((CoreGroup)EwNewObject( ApplicationThermostat, 0 ));
  CoreGroup_SwitchToDialog((CoreGroup)_this, newDialog, 0, 0, 0, 0, 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
}

/* 'C' function for method : 'Application::ModeController.SlotMethod2()' */
void ApplicationModeController_SlotMethod2( ApplicationModeController _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( sender );

  ApplicationDeviceClass_OnSetMode( EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass ), 
  0 );
}

/* 'C' function for method : 'Application::ModeController.SlotMethod3()' */
void ApplicationModeController_SlotMethod3( ApplicationModeController _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( sender );

  ApplicationDeviceClass_OnSetMode( EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass ), 
  1 );
}

/* 'C' function for method : 'Application::ModeController.SlotMethod4()' */
void ApplicationModeController_SlotMethod4( ApplicationModeController _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( sender );

  ApplicationDeviceClass_OnSetMode( EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass ), 
  2 );
}

/* This slot method is executed when the associated property observer 'PropertyObserver' 
   is notified. */
void ApplicationModeController_onEvent( ApplicationModeController _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Mode == 0 )
  {
    ViewsImage_OnSetBitmap( &_this->Image, EwLoadResource( &Applicationshutdown_big_69_80, 
    ResourcesBitmap ));
    ViewsImage_OnSetBitmap( &_this->Background, EwLoadResource( &Applicationbg_black, 
    ResourcesBitmap ));
  }
  else
    if ( EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Mode == 
        1 )
    {
      ViewsImage_OnSetBitmap( &_this->Image, EwLoadResource( &Applicationmodebig_161_225, 
      ResourcesBitmap ));
      ViewsImage_OnSetBitmap( &_this->Background, EwLoadResource( &Applicationbg_brown, 
      ResourcesBitmap ));
    }
    else
    {
      ViewsImage_OnSetBitmap( &_this->Image, EwLoadResource( &Applicationsettings2_200_175, 
      ResourcesBitmap ));
      ViewsImage_OnSetBitmap( &_this->Background, EwLoadResource( &Applicationblue_720_720, 
      ResourcesBitmap ));
    }
}

/* Variants derived from the class : 'Application::ModeController' */
EW_DEFINE_CLASS_VARIANTS( ApplicationModeController )
EW_END_OF_CLASS_VARIANTS( ApplicationModeController )

/* Virtual Method Table (VMT) for the class : 'Application::ModeController' */
EW_DEFINE_CLASS( ApplicationModeController, CoreGroup, Background, _.VMT, _.VMT, 
                 _.VMT, _.VMT, _.VMT, "Application::ModeController" )
  CoreRectView_initLayoutContext,
  CoreView_GetRoot,
  CoreGroup_Draw,
  CoreGroup_GetClipping,
  CoreView_HandleEvent,
  CoreGroup_CursorHitTest,
  CoreGroup_AdjustDrawingArea,
  CoreRectView_ArrangeView,
  CoreRectView_MoveView,
  CoreRectView_GetExtent,
  CoreGroup_ChangeViewState,
  CoreGroup_OnSetBounds,
  CoreGroup_OnSetFocus,
  CoreGroup_OnSetOpacity,
  CoreGroup_DispatchEvent,
  CoreGroup_BroadcastEvent,
  CoreGroup_UpdateLayout,
  CoreGroup_UpdateViewState,
  CoreGroup_InvalidateArea,
EW_END_OF_CLASS( ApplicationModeController )

/* Initializer for the class 'Application::TemperatureController' */
void ApplicationTemperatureController__Init( ApplicationTemperatureController _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( ApplicationTemperatureController );

  /* ... then construct all embedded objects */
  ViewsImage__Init( &_this->Background, &_this->_.XObject, 0 );
  CoreRotateTouchHandler__Init( &_this->RotateTouchHandler, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->Wheel, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->Image, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->Image1, &_this->_.XObject, 0 );
  GraphicsPath__Init( &_this->DeltaTempPath, &_this->_.XObject, 0 );
  ViewsStrokePath__Init( &_this->DeltaTempView, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->Symbol, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->ActualText, &_this->_.XObject, 0 );
  CoreSimpleTouchHandler__Init( &_this->SimpleTouchHandlerPlus, &_this->_.XObject, 0 );
  CoreSimpleTouchHandler__Init( &_this->SimpleTouchHandlerMinus, &_this->_.XObject, 0 );
  ViewsWarpImage__Init( &_this->Needle, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->CurrentMode, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->CurrentMode1, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->Timer, &_this->_.XObject, 0 );
  CorePropertyObserver__Init( &_this->PropertyObserver, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( ApplicationTemperatureController );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( &_this->Background, _Const0000 );
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreGroup_OnSetAlphaBlended((CoreGroup)_this, 1 );
  CoreView_OnSetLayout((CoreView)&_this->RotateTouchHandler, CoreLayoutAlignToLeft 
  | CoreLayoutAlignToRight | CoreLayoutAlignToTop );
  CoreRectView__OnSetBounds( &_this->RotateTouchHandler, _Const0000 );
  CoreRectView__OnSetBounds( &_this->Wheel, _Const0000 );
  _this->NominalValue = 180;
  CoreRectView__OnSetBounds( &_this->Image, _Const001A );
  CoreRectView__OnSetBounds( &_this->Image1, _Const001B );
  CoreView_OnSetLayout((CoreView)&_this->DeltaTempView, CoreLayoutAlignToTop );
  CoreRectView__OnSetBounds( &_this->DeltaTempView, _Const0000 );
  ViewsStrokePath_OnSetColor( &_this->DeltaTempView, _Const001C );
  ViewsStrokePath_OnSetOffset( &_this->DeltaTempView, _Const001D );
  ViewsStrokePath_OnSetMiterLimit( &_this->DeltaTempView, 3.0f );
  ViewsStrokePath_OnSetJoinPoints( &_this->DeltaTempView, GraphicsPathJoinRound );
  ViewsStrokePath_OnSetEndCap( &_this->DeltaTempView, GraphicsPathCapRound );
  ViewsStrokePath_OnSetStartCap( &_this->DeltaTempView, GraphicsPathCapRound );
  ViewsStrokePath_OnSetWidth( &_this->DeltaTempView, 20.0f );
  CoreRectView__OnSetBounds( &_this->Symbol, _Const001E );
  ViewsImage_OnSetOpacity( &_this->Symbol, 100 );
  CoreView_OnSetLayout((CoreView)&_this->ActualText, CoreLayoutAlignToBottom | CoreLayoutAlignToRight 
  | CoreLayoutAlignToTop | CoreLayoutResizeHorz | CoreLayoutResizeVert );
  CoreRectView__OnSetBounds( &_this->ActualText, _Const001F );
  ViewsText_OnSetAlignment( &_this->ActualText, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertTop );
  ViewsText_OnSetString( &_this->ActualText, EwLoadString( &_Const0020 ));
  ViewsText_OnSetColor( &_this->ActualText, _Const0021 );
  CoreQuadView__OnSetPoint4( &_this->SimpleTouchHandlerPlus, _Const0022 );
  CoreQuadView__OnSetPoint3( &_this->SimpleTouchHandlerPlus, _Const0023 );
  CoreQuadView__OnSetPoint2( &_this->SimpleTouchHandlerPlus, _Const0024 );
  CoreQuadView__OnSetPoint1( &_this->SimpleTouchHandlerPlus, _Const0025 );
  CoreSimpleTouchHandler_OnSetMaxStrikeCount( &_this->SimpleTouchHandlerPlus, 100 );
  CoreQuadView__OnSetPoint4( &_this->SimpleTouchHandlerMinus, _Const0026 );
  CoreQuadView__OnSetPoint3( &_this->SimpleTouchHandlerMinus, _Const0027 );
  CoreQuadView__OnSetPoint2( &_this->SimpleTouchHandlerMinus, _Const0028 );
  CoreQuadView__OnSetPoint1( &_this->SimpleTouchHandlerMinus, _Const0029 );
  CoreSimpleTouchHandler_OnSetMaxStrikeCount( &_this->SimpleTouchHandlerMinus, 100 );
  CoreQuadView__OnSetPoint4( &_this->Needle, _Const002A );
  CoreQuadView__OnSetPoint3( &_this->Needle, _Const002B );
  CoreQuadView__OnSetPoint2( &_this->Needle, _Const002C );
  CoreQuadView__OnSetPoint1( &_this->Needle, _Const002D );
  ViewsWarpView_OnSetShininess((ViewsWarpView)&_this->Needle, 0.0f );
  ViewsWarpView_OnSetSourceAnchor((ViewsWarpView)&_this->Needle, _Const002E );
  CoreRectView__OnSetBounds( &_this->CurrentMode, _Const002F );
  ViewsText_OnSetString( &_this->CurrentMode, EwLoadString( &_Const0030 ));
  CoreRectView__OnSetBounds( &_this->CurrentMode1, _Const0031 );
  ViewsText_OnSetString( &_this->CurrentMode1, EwLoadString( &_Const0020 ));
  CoreTimer_OnSetPeriod( &_this->Timer, 2000 );
  CoreTimer_OnSetEnabled( &_this->Timer, 1 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Background ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->RotateTouchHandler ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Wheel ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Image ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Image1 ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->DeltaTempView ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Symbol ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->ActualText ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->SimpleTouchHandlerPlus ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->SimpleTouchHandlerMinus ), 
  0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Needle ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->CurrentMode ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->CurrentMode1 ), 0 );
  ViewsImage_OnSetBitmap( &_this->Background, EwLoadResource( &Applicationblue_720_720, 
  ResourcesBitmap ));
  _this->RotateTouchHandler.OnRotate = EwNewSlot( _this, ApplicationTemperatureController_onRotateSlot );
  _this->RotateTouchHandler.OnEnd = EwNewSlot( _this, ApplicationTemperatureController_onEndSlot );
  _this->RotateTouchHandler.OnStart = EwNewSlot( _this, ApplicationTemperatureController_onStartSlot );
  ViewsImage_OnSetBitmap( &_this->Wheel, EwLoadResource( &Applicationcoolset, ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->Image, EwLoadResource( &ApplicationIncrement, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->Image1, EwLoadResource( &Applicationdecrement, 
  ResourcesBitmap ));
  ViewsStrokePath_OnSetPath( &_this->DeltaTempView, &_this->DeltaTempPath );
  ViewsImage_OnSetBitmap( &_this->Symbol, EwLoadResource( &Applicationhot_cold_49_60, 
  ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->ActualText, EwLoadResource( &ApplicationFont1, ResourcesFont ));
  _this->SimpleTouchHandlerPlus.OnPress = EwNewSlot( _this, ApplicationTemperatureController_incrNominal );
  _this->SimpleTouchHandlerMinus.OnPress = EwNewSlot( _this, ApplicationTemperatureController_decrNominal );
  ViewsWarpImage_OnSetBitmap( &_this->Needle, EwLoadResource( &Applicationblue1_60_60, 
  ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->CurrentMode, EwLoadResource( &ApplicationFont1, ResourcesFont ));
  ViewsText_OnSetFont( &_this->CurrentMode1, EwLoadResource( &ApplicationFont1, 
  ResourcesFont ));
  _this->Timer.OnTrigger = EwNewSlot( _this, ApplicationTemperatureController_TimerSlot );
  _this->PropertyObserver.OnEvent = EwNewSlot( _this, ApplicationTemperatureController_onEvent );
  CorePropertyObserver_OnSetOutlet( &_this->PropertyObserver, EwNewRef( EwGetAutoObject( 
  &ApplicationDevice, ApplicationDeviceClass ), ApplicationDeviceClass_OnGetMode, 
  ApplicationDeviceClass_OnSetMode ));

  /* Call the user defined constructor */
  ApplicationTemperatureController_Init( _this, aArg );
}

/* Re-Initializer for the class 'Application::TemperatureController' */
void ApplicationTemperatureController__ReInit( ApplicationTemperatureController _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsImage__ReInit( &_this->Background );
  CoreRotateTouchHandler__ReInit( &_this->RotateTouchHandler );
  ViewsImage__ReInit( &_this->Wheel );
  ViewsImage__ReInit( &_this->Image );
  ViewsImage__ReInit( &_this->Image1 );
  GraphicsPath__ReInit( &_this->DeltaTempPath );
  ViewsStrokePath__ReInit( &_this->DeltaTempView );
  ViewsImage__ReInit( &_this->Symbol );
  ViewsText__ReInit( &_this->ActualText );
  CoreSimpleTouchHandler__ReInit( &_this->SimpleTouchHandlerPlus );
  CoreSimpleTouchHandler__ReInit( &_this->SimpleTouchHandlerMinus );
  ViewsWarpImage__ReInit( &_this->Needle );
  ViewsText__ReInit( &_this->CurrentMode );
  ViewsText__ReInit( &_this->CurrentMode1 );
  CoreTimer__ReInit( &_this->Timer );
  CorePropertyObserver__ReInit( &_this->PropertyObserver );
}

/* Finalizer method for the class 'Application::TemperatureController' */
void ApplicationTemperatureController__Done( ApplicationTemperatureController _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsImage__Done( &_this->Background );
  CoreRotateTouchHandler__Done( &_this->RotateTouchHandler );
  ViewsImage__Done( &_this->Wheel );
  ViewsImage__Done( &_this->Image );
  ViewsImage__Done( &_this->Image1 );
  GraphicsPath__Done( &_this->DeltaTempPath );
  ViewsStrokePath__Done( &_this->DeltaTempView );
  ViewsImage__Done( &_this->Symbol );
  ViewsText__Done( &_this->ActualText );
  CoreSimpleTouchHandler__Done( &_this->SimpleTouchHandlerPlus );
  CoreSimpleTouchHandler__Done( &_this->SimpleTouchHandlerMinus );
  ViewsWarpImage__Done( &_this->Needle );
  ViewsText__Done( &_this->CurrentMode );
  ViewsText__Done( &_this->CurrentMode1 );
  CoreTimer__Done( &_this->Timer );
  CorePropertyObserver__Done( &_this->PropertyObserver );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void ApplicationTemperatureController_Init( ApplicationTemperatureController _this, 
  XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  if ( EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Mode == 0 )
  {
    ViewsImage_OnSetBitmap( &_this->Background, EwLoadResource( &Applicationbg_black, 
    ResourcesBitmap ));
    ViewsWarpImage_OnSetBitmap( &_this->Needle, EwLoadResource( &Applicationblack_60_60, 
    ResourcesBitmap ));
  }
  else
    if ( EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Mode == 
        1 )
    {
      ViewsImage_OnSetBitmap( &_this->Background, EwLoadResource( &Applicationbg_brown, 
      ResourcesBitmap ));
      ViewsWarpImage_OnSetBitmap( &_this->Needle, EwLoadResource( &Applicationbrown_60_60, 
      ResourcesBitmap ));
    }
    else
    {
      ViewsImage_OnSetBitmap( &_this->Background, EwLoadResource( &Applicationblue_720_720, 
      ResourcesBitmap ));
      ViewsWarpImage_OnSetBitmap( &_this->Needle, EwLoadResource( &Applicationblue1_60_60, 
      ResourcesBitmap ));
    }

  ViewsText_OnSetString( &_this->CurrentMode1, EwConcatString( EwNewStringInt( EwGetAutoObject( 
  &ApplicationDevice, ApplicationDeviceClass )->Temperature, 0, 10 ), EwLoadString( 
  &_Const0032 )));
}

/* The method UpdateLayout() is invoked automatically after the size of the component 
   has been changed. This method can be overridden and filled with logic to perform 
   a sophisticated arrangement calculation for one or more enclosed views. In this 
   case the parameter aSize can be used. It contains the current size of the component. 
   Usually, all enclosed views are arranged automatically accordingly to their @Layout 
   property. UpdateLayout() gives the derived components a chance to extend this 
   automatism by a user defined algorithm. */
void ApplicationTemperatureController_UpdateLayout( ApplicationTemperatureController _this, 
  XPoint aSize )
{
  XInt32 cX;
  XInt32 cY;

  CoreGroup_UpdateLayout((CoreGroup)_this, aSize );
  cX = aSize.X / 2;
  cY = aSize.Y / 2;
  CoreRectView__OnSetBounds( &_this->DeltaTempView, EwNewRect2Point( _Const001D, 
  aSize ));
  ViewsStrokePath_OnSetOffset( &_this->DeltaTempView, EwNewPoint( cX, cY ));
}

/* The method UpdateViewState() is invoked automatically after the state of the 
   component has been changed. This method can be overridden and filled with logic 
   to ensure the visual aspect of the component does reflect its current state. 
   For example, the 'enabled' state of the component can affect its colors (disabled 
   components may appear pale). In this case the logic of the method should modify 
   the respective color properties accordingly to the current 'enabled' state. 
   The current state of the component is passed as a set in the parameter aState. 
   It reflects the very basic component state like its visibility or the ability 
   to react to user inputs. Beside this common state, the method can also involve 
   any other variables used in the component as long as they reflect its current 
   state. For example, the toggle switch component can take in account its toggle 
   state 'on' or 'off' and change accordingly the location of the slider, etc.
   Usually, this method will be invoked automatically by the framework. Optionally 
   you can request its invocation by using the method @InvalidateViewState(). */
void ApplicationTemperatureController_UpdateViewState( ApplicationTemperatureController _this, 
  XSet aState )
{
  XInt32 alpha;
  XInt32 nominal;
  XFloat nomAngle;

  CoreGroup_UpdateViewState((CoreGroup)_this, aState );
  alpha = 0;
  nominal = _this->NominalValue;

  if ( nominal < 100 )
    nominal = 100;

  if ( nominal > 400 )
    nominal = 400;

  nomAngle = 135.0f - (((XFloat)( nominal - 100 ) * 270.0f ) / 300.0f );
  ViewsWarpView_RotateAndScale((ViewsWarpView)&_this->Needle, EwGetRectCenter( _this->Wheel.Super1.Bounds ), 
  nomAngle, 2.2f, 2.2f );

  if ( 180 != nominal )
  {
    GraphicsPath_InitSubPath( &_this->DeltaTempPath, 0, 84 );
    GraphicsPath_Rotate( &_this->DeltaTempPath, -153.0f );
    GraphicsPath_Begin( &_this->DeltaTempPath, 0, 250.0f, 0.0f );
    GraphicsPath_AddLine( &_this->DeltaTempPath, 0, 270.0f, 0.0f );
    GraphicsPath_AddArc( &_this->DeltaTempPath, 0, 0.0f, 0.0f, 270.0f, 270.0f, 0.0f, 
    -nomAngle + 63.0f, 80 );
    GraphicsPath_Rotate( &_this->DeltaTempPath, 153.0f );
  }
  else
    GraphicsPath_InitSubPath( &_this->DeltaTempPath, 0, 84 );

  if ( 180 <= nominal )
  {
    ViewsImage_OnSetFrameNumber( &_this->Symbol, 0 );
    ViewsImage_OnSetColor( &_this->Symbol, ApplicationColorHot );
    ViewsStrokePath_OnSetColor( &_this->DeltaTempView, ApplicationColorHot );
    alpha = ( nominal - 180 ) * 10;

    if ( alpha > 255 )
      alpha = 255;

    ViewsImage_OnSetOpacity( &_this->Symbol, alpha );
  }
  else
  {
    ViewsImage_OnSetOpacity( &_this->Symbol, 255 );
    ViewsStrokePath_OnSetColor( &_this->DeltaTempView, ApplicationColorCold );
  }
}

/* 'C' function for method : 'Application::TemperatureController.OnSetNominalValue()' */
void ApplicationTemperatureController_OnSetNominalValue( ApplicationTemperatureController _this, 
  XInt32 value )
{
  if ( _this->NominalValue == value )
    return;

  _this->NominalValue = value;
  CoreGroup_InvalidateViewState((CoreGroup)_this );
}

/* 'C' function for method : 'Application::TemperatureController.onStartSlot()' */
void ApplicationTemperatureController_onStartSlot( ApplicationTemperatureController _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  _this->startValue = _this->NominalValue;
}

/* 'C' function for method : 'Application::TemperatureController.onRotateSlot()' */
void ApplicationTemperatureController_onRotateSlot( ApplicationTemperatureController _this, 
  XObject sender )
{
  XInt32 temp;
  XInt32 delta;
  XInt32 alpha;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  delta = 0;
  alpha = 0;
  CoreTimer_OnSetEnabled( &_this->Timer, 0 );

  if (( _this->NominalValue >= 100 ) && ( _this->NominalValue <= 400 ))
    delta = ( _this->RotateTouchHandler.Relative * 300 ) / 720;

  temp = _this->startValue - delta;

  if ( temp < 120 )
    temp = 120;

  if ( temp > 380 )
    temp = 380;

  if ( temp < 180 )
    ViewsImage_OnSetBitmap( &_this->Symbol, EwLoadResource( &Applicationsettings1_50_44, 
    ResourcesBitmap ));
  else
    if ( temp > 270 )
      ViewsImage_OnSetBitmap( &_this->Symbol, EwLoadResource( &Applicationhotmode_43_60, 
      ResourcesBitmap ));
    else
      ViewsImage_OnSetBitmap( &_this->Symbol, EwLoadResource( &Applicationhot_cold_49_60, 
      ResourcesBitmap ));

  if ( _this->NominalValue != temp )
  {
    XInt32 inx = _this->Wheel.FrameNumber;
    XColor hot;
    XColor cold;

    if (( _this->NominalValue - temp ) > 0 )
      inx = inx - 1;
    else
      inx = inx + 1;

    if ( inx < 0 )
      inx = 3;

    if ( inx > 3 )
      inx = 0;

    ViewsImage_OnSetFrameNumber( &_this->Wheel, inx );
    ApplicationTemperatureController_OnSetNominalValue( _this, temp );
    ViewsText_OnSetString( &_this->ActualText, EwConcatString( EwNewStringInt( _this->NominalValue 
    / 10, 0, 10 ), EwLoadString( &_Const0032 )));
    alpha = (( _this->NominalValue - 100 ) * 255 ) / 300;
    hot = EwBlendColorInt( _Const0033, alpha );
    cold = EwBlendColorInt( ApplicationColorCold, (XUInt8)( 255 - alpha ));
    ViewsText_OnSetColor( &_this->ActualText, EwPlusColor( hot, cold ));
  }
}

/* 'C' function for method : 'Application::TemperatureController.onEndSlot()' */
void ApplicationTemperatureController_onEndSlot( ApplicationTemperatureController _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreTimer_OnSetEnabled( &_this->Timer, 0 );
  ViewsImage_OnSetFrameNumber( &_this->Wheel, 0 );
  CoreTimer_OnSetEnabled( &_this->Timer, 1 );
}

/* 'C' function for method : 'Application::TemperatureController.incrNominal()' */
void ApplicationTemperatureController_incrNominal( ApplicationTemperatureController _this, 
  XObject sender )
{
  XInt32 temp;
  XInt32 alpha;
  XColor hot;
  XColor cold;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  temp = _this->NominalValue + 5;
  CoreTimer_OnSetEnabled( &_this->Timer, 0 );

  if ( temp > 380 )
    temp = 380;

  if ( temp < 180 )
    ViewsImage_OnSetBitmap( &_this->Symbol, EwLoadResource( &Applicationsettings1_50_44, 
    ResourcesBitmap ));
  else
    if ( temp > 270 )
      ViewsImage_OnSetBitmap( &_this->Symbol, EwLoadResource( &Applicationhotmode_43_60, 
      ResourcesBitmap ));
    else
      ViewsImage_OnSetBitmap( &_this->Symbol, EwLoadResource( &Applicationhot_cold_49_60, 
      ResourcesBitmap ));

  ApplicationTemperatureController_OnSetNominalValue( _this, temp );
  CoreTimer_OnSetEnabled( &_this->Timer, 1 );
  ViewsText_OnSetString( &_this->ActualText, EwConcatString( EwNewStringInt( _this->NominalValue 
  / 10, 0, 10 ), EwLoadString( &_Const0032 )));
  alpha = (( _this->NominalValue - 100 ) * 255 ) / 300;
  hot = EwBlendColorInt( _Const0033, alpha );
  cold = EwBlendColorInt( ApplicationColorCold, (XUInt8)( 255 - alpha ));
  ViewsText_OnSetColor( &_this->ActualText, EwPlusColor( hot, cold ));
}

/* 'C' function for method : 'Application::TemperatureController.decrNominal()' */
void ApplicationTemperatureController_decrNominal( ApplicationTemperatureController _this, 
  XObject sender )
{
  XInt32 temp;
  XInt32 alpha;
  XColor hot;
  XColor cold;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  temp = _this->NominalValue - 5;
  CoreTimer_OnSetEnabled( &_this->Timer, 0 );

  if ( temp < 120 )
    temp = 120;

  if ( temp < 180 )
    ViewsImage_OnSetBitmap( &_this->Symbol, EwLoadResource( &Applicationsettings1_50_44, 
    ResourcesBitmap ));
  else
    if ( temp > 270 )
      ViewsImage_OnSetBitmap( &_this->Symbol, EwLoadResource( &Applicationhotmode_43_60, 
      ResourcesBitmap ));
    else
      ViewsImage_OnSetBitmap( &_this->Symbol, EwLoadResource( &Applicationhot_cold_49_60, 
      ResourcesBitmap ));

  ApplicationTemperatureController_OnSetNominalValue( _this, temp );
  CoreTimer_OnSetEnabled( &_this->Timer, 1 );
  ViewsText_OnSetString( &_this->ActualText, EwConcatString( EwNewStringInt( _this->NominalValue 
  / 10, 0, 10 ), EwLoadString( &_Const0032 )));
  alpha = (( _this->NominalValue - 100 ) * 255 ) / 300;
  hot = EwBlendColorInt( _Const0033, alpha );
  cold = EwBlendColorInt( ApplicationColorCold, (XUInt8)( 255 - alpha ));
  ViewsText_OnSetColor( &_this->ActualText, EwPlusColor( hot, cold ));
}

/* 'C' function for method : 'Application::TemperatureController.TimerSlot()' */
void ApplicationTemperatureController_TimerSlot( ApplicationTemperatureController _this, 
  XObject sender )
{
  CoreGroup newDialog;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreTimer_OnSetEnabled( &_this->Timer, 0 );
  newDialog = ((CoreGroup)EwNewObject( ApplicationThermostat, 0 ));
  CoreGroup_SwitchToDialog((CoreGroup)_this, newDialog, 0, 0, 0, 0, 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
}

/* This slot method is executed when the associated property observer 'PropertyObserver' 
   is notified. */
void ApplicationTemperatureController_onEvent( ApplicationTemperatureController _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Mode == 0 )
  {
    ViewsImage_OnSetBitmap( &_this->Background, EwLoadResource( &Applicationbg_black, 
    ResourcesBitmap ));
    ViewsWarpImage_OnSetBitmap( &_this->Needle, EwLoadResource( &Applicationblack_60_60, 
    ResourcesBitmap ));
  }
  else
    if ( EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Mode == 
        1 )
    {
      ViewsImage_OnSetBitmap( &_this->Background, EwLoadResource( &Applicationbg_brown, 
      ResourcesBitmap ));
      ViewsWarpImage_OnSetBitmap( &_this->Needle, EwLoadResource( &Applicationbrown_60_60, 
      ResourcesBitmap ));
    }
    else
    {
      ViewsImage_OnSetBitmap( &_this->Background, EwLoadResource( &Applicationblue_720_720, 
      ResourcesBitmap ));
      ViewsWarpImage_OnSetBitmap( &_this->Needle, EwLoadResource( &Applicationblue1_60_60, 
      ResourcesBitmap ));
    }
}

/* Variants derived from the class : 'Application::TemperatureController' */
EW_DEFINE_CLASS_VARIANTS( ApplicationTemperatureController )
EW_END_OF_CLASS_VARIANTS( ApplicationTemperatureController )

/* Virtual Method Table (VMT) for the class : 'Application::TemperatureController' */
EW_DEFINE_CLASS( ApplicationTemperatureController, CoreGroup, Background, NominalValue, 
                 NominalValue, NominalValue, NominalValue, NominalValue, "Application::TemperatureController" )
  CoreRectView_initLayoutContext,
  CoreView_GetRoot,
  CoreGroup_Draw,
  CoreGroup_GetClipping,
  CoreView_HandleEvent,
  CoreGroup_CursorHitTest,
  CoreGroup_AdjustDrawingArea,
  CoreRectView_ArrangeView,
  CoreRectView_MoveView,
  CoreRectView_GetExtent,
  CoreGroup_ChangeViewState,
  CoreGroup_OnSetBounds,
  CoreGroup_OnSetFocus,
  CoreGroup_OnSetOpacity,
  CoreGroup_DispatchEvent,
  CoreGroup_BroadcastEvent,
  ApplicationTemperatureController_UpdateLayout,
  ApplicationTemperatureController_UpdateViewState,
  CoreGroup_InvalidateArea,
EW_END_OF_CLASS( ApplicationTemperatureController )

/* Initializer for the class 'Application::FanController' */
void ApplicationFanController__Init( ApplicationFanController _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( ApplicationFanController );

  /* ... then construct all embedded objects */
  ViewsImage__Init( &_this->Background, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->Image, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->Image1, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->Image2, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->CurrentMode, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->CurrentMode1, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->CurrentMode2, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->Mode, &_this->_.XObject, 0 );
  CoreSimpleTouchHandler__Init( &_this->SimpleTouchHandler, &_this->_.XObject, 0 );
  CorePropertyObserver__Init( &_this->PropertyObserver, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( ApplicationFanController );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( &_this->Background, _Const0000 );
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->Image, _Const0034 );
  CoreRectView__OnSetBounds( &_this->Image1, _Const0035 );
  CoreRectView__OnSetBounds( &_this->Image2, _Const0036 );
  CoreRectView__OnSetBounds( &_this->CurrentMode, _Const0037 );
  ViewsText_OnSetString( &_this->CurrentMode, EwLoadString( &_Const0038 ));
  CoreRectView__OnSetBounds( &_this->CurrentMode1, _Const0039 );
  ViewsText_OnSetString( &_this->CurrentMode1, EwLoadString( &_Const003A ));
  CoreRectView__OnSetBounds( &_this->CurrentMode2, _Const003B );
  ViewsText_OnSetString( &_this->CurrentMode2, EwLoadString( &_Const003C ));
  CoreRectView__OnSetBounds( &_this->Mode, _Const003D );
  CoreQuadView__OnSetPoint4( &_this->SimpleTouchHandler, _Const003E );
  CoreQuadView__OnSetPoint3( &_this->SimpleTouchHandler, _Const003F );
  CoreQuadView__OnSetPoint2( &_this->SimpleTouchHandler, _Const0040 );
  CoreQuadView__OnSetPoint1( &_this->SimpleTouchHandler, _Const0041 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Background ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Image ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Image1 ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Image2 ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->CurrentMode ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->CurrentMode1 ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->CurrentMode2 ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Mode ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->SimpleTouchHandler ), 0 );
  ViewsImage_OnSetBitmap( &_this->Background, EwLoadResource( &Applicationblue_720_720, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->Image, EwLoadResource( &ApplicationCirculate_75_80, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->Image1, EwLoadResource( &Applicationcirculate_invert_80_79, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->Image2, EwLoadResource( &Applicationshutdown_big_69_80, 
  ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->CurrentMode, EwLoadResource( &ResourcesFontMedium, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->CurrentMode1, EwLoadResource( &ResourcesFontMedium, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->CurrentMode2, EwLoadResource( &ResourcesFontMedium, 
  ResourcesFont ));
  ViewsImage_OnSetBitmap( &_this->Mode, EwLoadResource( &Applicationarrow_40_32, 
  ResourcesBitmap ));
  _this->SimpleTouchHandler.OnPress = EwNewSlot( _this, ApplicationFanController_SlotMethod1 );
  _this->PropertyObserver.OnEvent = EwNewSlot( _this, ApplicationFanController_onEvent );
  CorePropertyObserver_OnSetOutlet( &_this->PropertyObserver, EwNewRef( EwGetAutoObject( 
  &ApplicationDevice, ApplicationDeviceClass ), ApplicationDeviceClass_OnGetMode, 
  ApplicationDeviceClass_OnSetMode ));

  /* Call the user defined constructor */
  ApplicationFanController_Init( _this, aArg );
}

/* Re-Initializer for the class 'Application::FanController' */
void ApplicationFanController__ReInit( ApplicationFanController _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsImage__ReInit( &_this->Background );
  ViewsImage__ReInit( &_this->Image );
  ViewsImage__ReInit( &_this->Image1 );
  ViewsImage__ReInit( &_this->Image2 );
  ViewsText__ReInit( &_this->CurrentMode );
  ViewsText__ReInit( &_this->CurrentMode1 );
  ViewsText__ReInit( &_this->CurrentMode2 );
  ViewsImage__ReInit( &_this->Mode );
  CoreSimpleTouchHandler__ReInit( &_this->SimpleTouchHandler );
  CorePropertyObserver__ReInit( &_this->PropertyObserver );
}

/* Finalizer method for the class 'Application::FanController' */
void ApplicationFanController__Done( ApplicationFanController _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsImage__Done( &_this->Background );
  ViewsImage__Done( &_this->Image );
  ViewsImage__Done( &_this->Image1 );
  ViewsImage__Done( &_this->Image2 );
  ViewsText__Done( &_this->CurrentMode );
  ViewsText__Done( &_this->CurrentMode1 );
  ViewsText__Done( &_this->CurrentMode2 );
  ViewsImage__Done( &_this->Mode );
  CoreSimpleTouchHandler__Done( &_this->SimpleTouchHandler );
  CorePropertyObserver__Done( &_this->PropertyObserver );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void ApplicationFanController_Init( ApplicationFanController _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  if ( EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Mode == 0 )
    ViewsImage_OnSetBitmap( &_this->Background, EwLoadResource( &Applicationbg_black, 
    ResourcesBitmap ));
  else
    if ( EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Mode == 
        1 )
      ViewsImage_OnSetBitmap( &_this->Background, EwLoadResource( &Applicationbg_brown, 
      ResourcesBitmap ));
    else
      ViewsImage_OnSetBitmap( &_this->Background, EwLoadResource( &Applicationblue_720_720, 
      ResourcesBitmap ));
}

/* 'C' function for method : 'Application::FanController.SlotMethod1()' */
void ApplicationFanController_SlotMethod1( ApplicationFanController _this, XObject 
  sender )
{
  CoreGroup newDialog;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  newDialog = ((CoreGroup)EwNewObject( ApplicationThermostat, 0 ));
  CoreGroup_SwitchToDialog((CoreGroup)_this, newDialog, 0, 0, 0, 0, 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
}

/* This slot method is executed when the associated property observer 'PropertyObserver' 
   is notified. */
void ApplicationFanController_onEvent( ApplicationFanController _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Mode == 0 )
    ViewsImage_OnSetBitmap( &_this->Background, EwLoadResource( &Applicationbg_black, 
    ResourcesBitmap ));
  else
    if ( EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Mode == 
        1 )
      ViewsImage_OnSetBitmap( &_this->Background, EwLoadResource( &Applicationbg_brown, 
      ResourcesBitmap ));
    else
      ViewsImage_OnSetBitmap( &_this->Background, EwLoadResource( &Applicationblue_720_720, 
      ResourcesBitmap ));
}

/* Variants derived from the class : 'Application::FanController' */
EW_DEFINE_CLASS_VARIANTS( ApplicationFanController )
EW_END_OF_CLASS_VARIANTS( ApplicationFanController )

/* Virtual Method Table (VMT) for the class : 'Application::FanController' */
EW_DEFINE_CLASS( ApplicationFanController, CoreGroup, Background, _.VMT, _.VMT, 
                 _.VMT, _.VMT, _.VMT, "Application::FanController" )
  CoreRectView_initLayoutContext,
  CoreView_GetRoot,
  CoreGroup_Draw,
  CoreGroup_GetClipping,
  CoreView_HandleEvent,
  CoreGroup_CursorHitTest,
  CoreGroup_AdjustDrawingArea,
  CoreRectView_ArrangeView,
  CoreRectView_MoveView,
  CoreRectView_GetExtent,
  CoreGroup_ChangeViewState,
  CoreGroup_OnSetBounds,
  CoreGroup_OnSetFocus,
  CoreGroup_OnSetOpacity,
  CoreGroup_DispatchEvent,
  CoreGroup_BroadcastEvent,
  CoreGroup_UpdateLayout,
  CoreGroup_UpdateViewState,
  CoreGroup_InvalidateArea,
EW_END_OF_CLASS( ApplicationFanController )

/* Initializer for the class 'Application::BrightnessController' */
void ApplicationBrightnessController__Init( ApplicationBrightnessController _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( ApplicationBrightnessController );

  /* ... then construct all embedded objects */
  ViewsImage__Init( &_this->Background, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->Mode, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->CurrentMode, &_this->_.XObject, 0 );
  CoreSimpleTouchHandler__Init( &_this->SimpleTouchHandler, &_this->_.XObject, 0 );
  WidgetSetHorizontalSliderConfig__Init( &_this->HorizontalSliderConfig, &_this->_.XObject, 0 );
  WidgetSetHorizontalSlider__Init( &_this->HorizontalSlider, &_this->_.XObject, 0 );
  CorePropertyObserver__Init( &_this->PropertyObserver, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( ApplicationBrightnessController );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( &_this->Background, _Const0000 );
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->Mode, _Const0042 );
  CoreRectView__OnSetBounds( &_this->CurrentMode, _Const0043 );
  ViewsText_OnSetString( &_this->CurrentMode, EwLoadString( &_Const0044 ));
  CoreQuadView__OnSetPoint4( &_this->SimpleTouchHandler, _Const0045 );
  CoreQuadView__OnSetPoint3( &_this->SimpleTouchHandler, _Const0046 );
  CoreQuadView__OnSetPoint2( &_this->SimpleTouchHandler, _Const0047 );
  CoreQuadView__OnSetPoint1( &_this->SimpleTouchHandler, _Const0048 );
  WidgetSetHorizontalSliderConfig_OnSetAccentColorActive( &_this->HorizontalSliderConfig, 
  _Const0049 );
  WidgetSetHorizontalSliderConfig_OnSetAccentColorFocused( &_this->HorizontalSliderConfig, 
  _Const0049 );
  WidgetSetHorizontalSliderConfig_OnSetAccentCornerRadiusActive( &_this->HorizontalSliderConfig, 
  43 );
  WidgetSetHorizontalSliderConfig_OnSetAccentCornerRadiusFocused( &_this->HorizontalSliderConfig, 
  38 );
  WidgetSetHorizontalSliderConfig_OnSetAccentCornerRadiusDisabled( &_this->HorizontalSliderConfig, 
  38 );
  WidgetSetHorizontalSliderConfig_OnSetAccentCornerRadiusDefault( &_this->HorizontalSliderConfig, 
  38 );
  WidgetSetHorizontalSliderConfig_OnSetAccentSizeActive( &_this->HorizontalSliderConfig, 
  _Const004A );
  WidgetSetHorizontalSliderConfig_OnSetAccentSizeFocused( &_this->HorizontalSliderConfig, 
  _Const004B );
  WidgetSetHorizontalSliderConfig_OnSetAccentSizeDisabled( &_this->HorizontalSliderConfig, 
  _Const004B );
  WidgetSetHorizontalSliderConfig_OnSetAccentSizeDefault( &_this->HorizontalSliderConfig, 
  _Const004B );
  WidgetSetHorizontalSliderConfig_OnSetThumbBorderColorActive( &_this->HorizontalSliderConfig, 
  _Const004C );
  WidgetSetHorizontalSliderConfig_OnSetThumbBorderColorFocused( &_this->HorizontalSliderConfig, 
  _Const004C );
  WidgetSetHorizontalSliderConfig_OnSetThumbBorderColorDisabled( &_this->HorizontalSliderConfig, 
  _Const004C );
  WidgetSetHorizontalSliderConfig_OnSetThumbBorderColorDefault( &_this->HorizontalSliderConfig, 
  _Const004C );
  WidgetSetHorizontalSliderConfig_OnSetThumbBorderWidthActive( &_this->HorizontalSliderConfig, 
  1 );
  WidgetSetHorizontalSliderConfig_OnSetThumbBorderWidthFocused( &_this->HorizontalSliderConfig, 
  1 );
  WidgetSetHorizontalSliderConfig_OnSetThumbBorderWidthDisabled( &_this->HorizontalSliderConfig, 
  1 );
  WidgetSetHorizontalSliderConfig_OnSetThumbBorderWidthDefault( &_this->HorizontalSliderConfig, 
  1 );
  WidgetSetHorizontalSliderConfig_OnSetThumbColorActive( &_this->HorizontalSliderConfig, 
  _Const0021 );
  WidgetSetHorizontalSliderConfig_OnSetThumbColorFocused( &_this->HorizontalSliderConfig, 
  _Const0021 );
  WidgetSetHorizontalSliderConfig_OnSetThumbColorDisabled( &_this->HorizontalSliderConfig, 
  _Const0021 );
  WidgetSetHorizontalSliderConfig_OnSetThumbColorDefault( &_this->HorizontalSliderConfig, 
  _Const0021 );
  WidgetSetHorizontalSliderConfig_OnSetThumbCornerRadiusActive( &_this->HorizontalSliderConfig, 
  15 );
  WidgetSetHorizontalSliderConfig_OnSetThumbCornerRadiusFocused( &_this->HorizontalSliderConfig, 
  15 );
  WidgetSetHorizontalSliderConfig_OnSetThumbCornerRadiusDisabled( &_this->HorizontalSliderConfig, 
  15 );
  WidgetSetHorizontalSliderConfig_OnSetThumbCornerRadiusDefault( &_this->HorizontalSliderConfig, 
  15 );
  WidgetSetHorizontalSliderConfig_OnSetThumbSizeActive( &_this->HorizontalSliderConfig, 
  _Const004D );
  WidgetSetHorizontalSliderConfig_OnSetThumbSizeFocused( &_this->HorizontalSliderConfig, 
  _Const004D );
  WidgetSetHorizontalSliderConfig_OnSetThumbSizeDisabled( &_this->HorizontalSliderConfig, 
  _Const004D );
  WidgetSetHorizontalSliderConfig_OnSetThumbSizeDefault( &_this->HorizontalSliderConfig, 
  _Const004D );
  WidgetSetHorizontalSliderConfig_OnSetTrackRightBorderColorActive( &_this->HorizontalSliderConfig, 
  _Const0049 );
  WidgetSetHorizontalSliderConfig_OnSetTrackRightBorderColorFocused( &_this->HorizontalSliderConfig, 
  _Const0049 );
  WidgetSetHorizontalSliderConfig_OnSetTrackRightBorderColorDisabled( &_this->HorizontalSliderConfig, 
  _Const004E );
  WidgetSetHorizontalSliderConfig_OnSetTrackRightBorderColorDefault( &_this->HorizontalSliderConfig, 
  _Const0049 );
  WidgetSetHorizontalSliderConfig_OnSetTrackRightBorderWidthActive( &_this->HorizontalSliderConfig, 
  2 );
  WidgetSetHorizontalSliderConfig_OnSetTrackRightBorderWidthFocused( &_this->HorizontalSliderConfig, 
  2 );
  WidgetSetHorizontalSliderConfig_OnSetTrackRightBorderWidthDisabled( &_this->HorizontalSliderConfig, 
  2 );
  WidgetSetHorizontalSliderConfig_OnSetTrackRightBorderWidthDefault( &_this->HorizontalSliderConfig, 
  2 );
  WidgetSetHorizontalSliderConfig_OnSetTrackRightColorActive( &_this->HorizontalSliderConfig, 
  _Const004F );
  WidgetSetHorizontalSliderConfig_OnSetTrackRightColorFocused( &_this->HorizontalSliderConfig, 
  _Const004F );
  WidgetSetHorizontalSliderConfig_OnSetTrackRightColorDefault( &_this->HorizontalSliderConfig, 
  _Const004F );
  WidgetSetHorizontalSliderConfig_OnSetTrackRightCornerRadiusActive( &_this->HorizontalSliderConfig, 
  20 );
  WidgetSetHorizontalSliderConfig_OnSetTrackRightCornerRadiusFocused( &_this->HorizontalSliderConfig, 
  20 );
  WidgetSetHorizontalSliderConfig_OnSetTrackRightCornerRadiusDisabled( &_this->HorizontalSliderConfig, 
  20 );
  WidgetSetHorizontalSliderConfig_OnSetTrackRightCornerRadiusDefault( &_this->HorizontalSliderConfig, 
  20 );
  WidgetSetHorizontalSliderConfig_OnSetTrackRightThicknessActive( &_this->HorizontalSliderConfig, 
  40 );
  WidgetSetHorizontalSliderConfig_OnSetTrackRightThicknessFocused( &_this->HorizontalSliderConfig, 
  40 );
  WidgetSetHorizontalSliderConfig_OnSetTrackRightThicknessDisabled( &_this->HorizontalSliderConfig, 
  40 );
  WidgetSetHorizontalSliderConfig_OnSetTrackRightThicknessDefault( &_this->HorizontalSliderConfig, 
  40 );
  WidgetSetHorizontalSliderConfig_OnSetTrackRightFlattened( &_this->HorizontalSliderConfig, 
  1 );
  WidgetSetHorizontalSliderConfig_OnSetTrackLeftColorActive( &_this->HorizontalSliderConfig, 
  _Const0050 );
  WidgetSetHorizontalSliderConfig_OnSetTrackLeftColorFocused( &_this->HorizontalSliderConfig, 
  _Const0050 );
  WidgetSetHorizontalSliderConfig_OnSetTrackLeftColorDisabled( &_this->HorizontalSliderConfig, 
  _Const0050 );
  WidgetSetHorizontalSliderConfig_OnSetTrackLeftColorDefault( &_this->HorizontalSliderConfig, 
  _Const0050 );
  WidgetSetHorizontalSliderConfig_OnSetTrackLeftCornerRadiusActive( &_this->HorizontalSliderConfig, 
  20 );
  WidgetSetHorizontalSliderConfig_OnSetTrackLeftCornerRadiusFocused( &_this->HorizontalSliderConfig, 
  20 );
  WidgetSetHorizontalSliderConfig_OnSetTrackLeftCornerRadiusDisabled( &_this->HorizontalSliderConfig, 
  20 );
  WidgetSetHorizontalSliderConfig_OnSetTrackLeftCornerRadiusDefault( &_this->HorizontalSliderConfig, 
  20 );
  WidgetSetHorizontalSliderConfig_OnSetTrackLeftThicknessActive( &_this->HorizontalSliderConfig, 
  40 );
  WidgetSetHorizontalSliderConfig_OnSetTrackLeftThicknessFocused( &_this->HorizontalSliderConfig, 
  40 );
  WidgetSetHorizontalSliderConfig_OnSetTrackLeftThicknessDisabled( &_this->HorizontalSliderConfig, 
  40 );
  WidgetSetHorizontalSliderConfig_OnSetTrackLeftThicknessDefault( &_this->HorizontalSliderConfig, 
  40 );
  WidgetSetHorizontalSliderConfig_OnSetTrackLeftFlattened( &_this->HorizontalSliderConfig, 
  1 );
  CoreRectView__OnSetBounds( &_this->HorizontalSlider, _Const0051 );
  WidgetSetHorizontalSlider_OnSetStepSize( &_this->HorizontalSlider, 5 );
  WidgetSetHorizontalSlider_OnSetMaxValue( &_this->HorizontalSlider, 255 );
  WidgetSetHorizontalSlider_OnSetCurrentValue( &_this->HorizontalSlider, EwGetAutoObject( 
  &ApplicationDevice, ApplicationDeviceClass )->Brightness );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Background ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Mode ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->CurrentMode ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->SimpleTouchHandler ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->HorizontalSlider ), 0 );
  ViewsImage_OnSetBitmap( &_this->Background, EwLoadResource( &Applicationblue_720_720, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->Mode, EwLoadResource( &Applicationarrow_40_32, 
  ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->CurrentMode, EwLoadResource( &ResourcesFontMedium, 
  ResourcesFont ));
  _this->SimpleTouchHandler.OnPress = EwNewSlot( _this, ApplicationBrightnessController_SlotMethod1 );
  WidgetSetHorizontalSliderConfig_OnSetTrackLeftBitmapDefault( &_this->HorizontalSliderConfig, 
  0 );
  _this->HorizontalSlider.OnEnd = EwNewSlot( _this, ApplicationBrightnessController_HorizontalSliderSlot );
  WidgetSetHorizontalSlider_OnSetOutlet( &_this->HorizontalSlider, EwNewRef( EwGetAutoObject( 
  &ApplicationDevice, ApplicationDeviceClass ), ApplicationDeviceClass_OnGetBrightness, 
  ApplicationDeviceClass_OnSetBrightness ));
  WidgetSetHorizontalSlider_OnSetAppearance( &_this->HorizontalSlider, &_this->HorizontalSliderConfig );
  _this->PropertyObserver.OnEvent = EwNewSlot( _this, ApplicationBrightnessController_onEvent );
  CorePropertyObserver_OnSetOutlet( &_this->PropertyObserver, EwNewRef( EwGetAutoObject( 
  &ApplicationDevice, ApplicationDeviceClass ), ApplicationDeviceClass_OnGetMode, 
  ApplicationDeviceClass_OnSetMode ));

  /* Call the user defined constructor */
  ApplicationBrightnessController_Init( _this, aArg );
}

/* Re-Initializer for the class 'Application::BrightnessController' */
void ApplicationBrightnessController__ReInit( ApplicationBrightnessController _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsImage__ReInit( &_this->Background );
  ViewsImage__ReInit( &_this->Mode );
  ViewsText__ReInit( &_this->CurrentMode );
  CoreSimpleTouchHandler__ReInit( &_this->SimpleTouchHandler );
  WidgetSetHorizontalSliderConfig__ReInit( &_this->HorizontalSliderConfig );
  WidgetSetHorizontalSlider__ReInit( &_this->HorizontalSlider );
  CorePropertyObserver__ReInit( &_this->PropertyObserver );
}

/* Finalizer method for the class 'Application::BrightnessController' */
void ApplicationBrightnessController__Done( ApplicationBrightnessController _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsImage__Done( &_this->Background );
  ViewsImage__Done( &_this->Mode );
  ViewsText__Done( &_this->CurrentMode );
  CoreSimpleTouchHandler__Done( &_this->SimpleTouchHandler );
  WidgetSetHorizontalSliderConfig__Done( &_this->HorizontalSliderConfig );
  WidgetSetHorizontalSlider__Done( &_this->HorizontalSlider );
  CorePropertyObserver__Done( &_this->PropertyObserver );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void ApplicationBrightnessController_Init( ApplicationBrightnessController _this, 
  XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  WidgetSetHorizontalSlider_OnSetCurrentValue( &_this->HorizontalSlider, EwGetAutoObject( 
  &ApplicationDevice, ApplicationDeviceClass )->Brightness );

  if ( EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Mode == 0 )
    ViewsImage_OnSetBitmap( &_this->Background, EwLoadResource( &Applicationbg_black, 
    ResourcesBitmap ));
  else
    if ( EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Mode == 
        1 )
      ViewsImage_OnSetBitmap( &_this->Background, EwLoadResource( &Applicationbg_brown, 
      ResourcesBitmap ));
    else
      ViewsImage_OnSetBitmap( &_this->Background, EwLoadResource( &Applicationblue_720_720, 
      ResourcesBitmap ));
}

/* 'C' function for method : 'Application::BrightnessController.SlotMethod1()' */
void ApplicationBrightnessController_SlotMethod1( ApplicationBrightnessController _this, 
  XObject sender )
{
  CoreGroup newDialog;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  newDialog = ((CoreGroup)EwNewObject( ApplicationThermostat, 0 ));
  CoreGroup_SwitchToDialog((CoreGroup)_this, newDialog, 0, 0, 0, 0, 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
}

/* 'C' function for method : 'Application::BrightnessController.HorizontalSliderSlot()' */
void ApplicationBrightnessController_HorizontalSliderSlot( ApplicationBrightnessController _this, 
  XObject sender )
{
  XUInt8 brightness;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  brightness = (XUInt8)WidgetSetHorizontalSlider_OnGetCurrentValue( &_this->HorizontalSlider );
  {
    extern void  DISP_WS_SetBrightness(XInt8 brightness);
    DISP_WS_SetBrightness(brightness);
  }
}

/* This slot method is executed when the associated property observer 'PropertyObserver' 
   is notified. */
void ApplicationBrightnessController_onEvent( ApplicationBrightnessController _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Mode == 0 )
    ViewsImage_OnSetBitmap( &_this->Background, EwLoadResource( &Applicationbg_black, 
    ResourcesBitmap ));
  else
    if ( EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Mode == 
        1 )
      ViewsImage_OnSetBitmap( &_this->Background, EwLoadResource( &Applicationbg_brown, 
      ResourcesBitmap ));
    else
      ViewsImage_OnSetBitmap( &_this->Background, EwLoadResource( &Applicationblue_720_720, 
      ResourcesBitmap ));
}

/* Variants derived from the class : 'Application::BrightnessController' */
EW_DEFINE_CLASS_VARIANTS( ApplicationBrightnessController )
EW_END_OF_CLASS_VARIANTS( ApplicationBrightnessController )

/* Virtual Method Table (VMT) for the class : 'Application::BrightnessController' */
EW_DEFINE_CLASS( ApplicationBrightnessController, CoreGroup, Background, _.VMT, 
                 _.VMT, _.VMT, _.VMT, _.VMT, "Application::BrightnessController" )
  CoreRectView_initLayoutContext,
  CoreView_GetRoot,
  CoreGroup_Draw,
  CoreGroup_GetClipping,
  CoreView_HandleEvent,
  CoreGroup_CursorHitTest,
  CoreGroup_AdjustDrawingArea,
  CoreRectView_ArrangeView,
  CoreRectView_MoveView,
  CoreRectView_GetExtent,
  CoreGroup_ChangeViewState,
  CoreGroup_OnSetBounds,
  CoreGroup_OnSetFocus,
  CoreGroup_OnSetOpacity,
  CoreGroup_DispatchEvent,
  CoreGroup_BroadcastEvent,
  CoreGroup_UpdateLayout,
  CoreGroup_UpdateViewState,
  CoreGroup_InvalidateArea,
EW_END_OF_CLASS( ApplicationBrightnessController )

/* Initializer for the class 'Application::Thermostat' */
void ApplicationThermostat__Init( ApplicationThermostat _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( ApplicationThermostat );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->Rectangle, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->Background, &_this->_.XObject, 0 );
  ViewsRectangle__Init( &_this->Rectangle1, &_this->_.XObject, 0 );
  ViewsRectangle__Init( &_this->Rectangle2, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->TempCurrentSymbol, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->TempCurrent, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->HumidityCurrent, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->wifi, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->home, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->Day, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->Time, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->weatherSymbol, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->TempOutdoor, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->humidity, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->bluetooth, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->Mode, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->Fan, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->ScreenBrightness, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->Off, &_this->_.XObject, 0 );
  CoreSimpleTouchHandler__Init( &_this->SimpleTouchHandler, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->Timer, &_this->_.XObject, 0 );
  CoreSimpleTouchHandler__Init( &_this->SimpleTouchHandler1, &_this->_.XObject, 0 );
  CoreSimpleTouchHandler__Init( &_this->SimpleTouchHandler2, &_this->_.XObject, 0 );
  CoreSimpleTouchHandler__Init( &_this->SimpleTouchHandler3, &_this->_.XObject, 0 );
  CoreSimpleTouchHandler__Init( &_this->SimpleTouchHandler4, &_this->_.XObject, 0 );
  CoreSimpleTouchHandler__Init( &_this->SimpleTouchHandler5, &_this->_.XObject, 0 );
  CoreSimpleTouchHandler__Init( &_this->SimpleTouchHandler6, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->Timer1, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->Timer2, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->Timer3, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->Timer4, &_this->_.XObject, 0 );
  CorePropertyObserver__Init( &_this->PropertyObserver1, &_this->_.XObject, 0 );
  CorePropertyObserver__Init( &_this->PropertyObserver2, &_this->_.XObject, 0 );
  CorePropertyObserver__Init( &_this->PropertyObserver3, &_this->_.XObject, 0 );
  CorePropertyObserver__Init( &_this->PropertyObserver5, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->Text, &_this->_.XObject, 0 );
  EffectsRectEffect__Init( &_this->RectEffect, &_this->_.XObject, 0 );
  CorePropertyObserver__Init( &_this->PropertyObserverBt, &_this->_.XObject, 0 );
  CorePropertyObserver__Init( &_this->PropertyObserverWifi, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( ApplicationThermostat );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->Rectangle, _Const0000 );
  CoreRectView__OnSetBounds( &_this->Background, _Const0000 );
  CoreRectView__OnSetBounds( &_this->Rectangle1, _Const0052 );
  ViewsRectangle_OnSetColor( &_this->Rectangle1, _Const0053 );
  ViewsRectangle_OnSetVisible( &_this->Rectangle1, 0 );
  CoreRectView__OnSetBounds( &_this->Rectangle2, _Const0054 );
  ViewsRectangle_OnSetColor( &_this->Rectangle2, _Const0053 );
  ViewsRectangle_OnSetVisible( &_this->Rectangle2, 0 );
  CoreRectView__OnSetBounds( &_this->TempCurrentSymbol, _Const0055 );
  CoreRectView__OnSetBounds( &_this->TempCurrent, _Const0056 );
  ViewsText_OnSetString( &_this->TempCurrent, EwLoadString( &_Const0057 ));
  CoreRectView__OnSetBounds( &_this->HumidityCurrent, _Const0058 );
  ViewsText_OnSetString( &_this->HumidityCurrent, EwLoadString( &_Const0059 ));
  CoreRectView__OnSetBounds( &_this->wifi, _Const0052 );
  CoreRectView__OnSetBounds( &_this->home, _Const005A );
  CoreRectView__OnSetBounds( &_this->Day, _Const005B );
  ViewsText_OnSetAlignment( &_this->Day, ViewsTextAlignmentAlignHorzLeft );
  ViewsText_OnSetString( &_this->Day, EwLoadString( &_Const005C ));
  CoreRectView__OnSetBounds( &_this->Time, _Const005D );
  ViewsText_OnSetString( &_this->Time, EwLoadString( &_Const005E ));
  CoreRectView__OnSetBounds( &_this->weatherSymbol, _Const005F );
  ViewsImage_OnSetVisible( &_this->weatherSymbol, 0 );
  CoreRectView__OnSetBounds( &_this->TempOutdoor, _Const0060 );
  ViewsText_OnSetString( &_this->TempOutdoor, EwLoadString( &_Const0061 ));
  ViewsText_OnSetVisible( &_this->TempOutdoor, 0 );
  CoreRectView__OnSetBounds( &_this->humidity, _Const0062 );
  CoreRectView__OnSetBounds( &_this->bluetooth, _Const0063 );
  CoreRectView__OnSetBounds( &_this->Mode, _Const0064 );
  ViewsImage_OnSetVisible( &_this->Mode, 0 );
  CoreRectView__OnSetBounds( &_this->Fan, _Const0065 );
  ViewsImage_OnSetVisible( &_this->Fan, 0 );
  CoreRectView__OnSetBounds( &_this->ScreenBrightness, _Const0066 );
  ViewsImage_OnSetVisible( &_this->ScreenBrightness, 0 );
  CoreRectView__OnSetBounds( &_this->Off, _Const0009 );
  ViewsImage_OnSetVisible( &_this->Off, 0 );
  CoreQuadView__OnSetPoint4( &_this->SimpleTouchHandler, _Const001D );
  CoreQuadView__OnSetPoint3( &_this->SimpleTouchHandler, _Const0067 );
  CoreQuadView__OnSetPoint2( &_this->SimpleTouchHandler, _Const0068 );
  CoreQuadView__OnSetPoint1( &_this->SimpleTouchHandler, _Const0069 );
  CoreTimer_OnSetPeriod( &_this->Timer, 5000 );
  CoreTimer_OnSetEnabled( &_this->Timer, 0 );
  CoreQuadView__OnSetPoint4( &_this->SimpleTouchHandler1, _Const006A );
  CoreQuadView__OnSetPoint3( &_this->SimpleTouchHandler1, _Const006B );
  CoreQuadView__OnSetPoint2( &_this->SimpleTouchHandler1, _Const006C );
  CoreQuadView__OnSetPoint1( &_this->SimpleTouchHandler1, _Const006D );
  CoreQuadView__OnSetPoint4( &_this->SimpleTouchHandler2, _Const006E );
  CoreQuadView__OnSetPoint3( &_this->SimpleTouchHandler2, _Const006F );
  CoreQuadView__OnSetPoint2( &_this->SimpleTouchHandler2, _Const0070 );
  CoreQuadView__OnSetPoint1( &_this->SimpleTouchHandler2, _Const0071 );
  CoreQuadView__OnSetPoint4( &_this->SimpleTouchHandler3, _Const0072 );
  CoreQuadView__OnSetPoint3( &_this->SimpleTouchHandler3, _Const0073 );
  CoreQuadView__OnSetPoint2( &_this->SimpleTouchHandler3, _Const0074 );
  CoreQuadView__OnSetPoint1( &_this->SimpleTouchHandler3, _Const0075 );
  CoreSimpleTouchHandler_OnSetEnabled( &_this->SimpleTouchHandler3, 0 );
  CoreQuadView__OnSetPoint4( &_this->SimpleTouchHandler4, _Const0076 );
  CoreQuadView__OnSetPoint3( &_this->SimpleTouchHandler4, _Const0077 );
  CoreQuadView__OnSetPoint2( &_this->SimpleTouchHandler4, _Const0078 );
  CoreQuadView__OnSetPoint1( &_this->SimpleTouchHandler4, _Const0079 );
  CoreSimpleTouchHandler_OnSetEnabled( &_this->SimpleTouchHandler4, 0 );
  CoreQuadView__OnSetPoint4( &_this->SimpleTouchHandler5, _Const007A );
  CoreQuadView__OnSetPoint3( &_this->SimpleTouchHandler5, _Const007B );
  CoreQuadView__OnSetPoint2( &_this->SimpleTouchHandler5, _Const007C );
  CoreQuadView__OnSetPoint1( &_this->SimpleTouchHandler5, _Const007D );
  CoreSimpleTouchHandler_OnSetEnabled( &_this->SimpleTouchHandler5, 0 );
  CoreQuadView__OnSetPoint4( &_this->SimpleTouchHandler6, _Const007E );
  CoreQuadView__OnSetPoint3( &_this->SimpleTouchHandler6, _Const007F );
  CoreQuadView__OnSetPoint2( &_this->SimpleTouchHandler6, _Const0080 );
  CoreQuadView__OnSetPoint1( &_this->SimpleTouchHandler6, _Const0081 );
  CoreSimpleTouchHandler_OnSetEnabled( &_this->SimpleTouchHandler6, 0 );
  CoreTimer_OnSetPeriod( &_this->Timer1, 250 );
  CoreTimer_OnSetEnabled( &_this->Timer1, 0 );
  CoreTimer_OnSetPeriod( &_this->Timer2, 250 );
  CoreTimer_OnSetEnabled( &_this->Timer2, 0 );
  CoreTimer_OnSetPeriod( &_this->Timer3, 60000 );
  CoreTimer_OnSetEnabled( &_this->Timer3, 1 );
  CoreTimer_OnSetPeriod( &_this->Timer4, 10000 );
  CoreTimer_OnSetEnabled( &_this->Timer4, 1 );
  CoreRectView__OnSetBounds( &_this->Text, _Const0082 );
  ViewsText_OnSetString( &_this->Text, 0 );
  ViewsText_OnSetColor( &_this->Text, _Const0083 );
  ViewsText_OnSetVisible( &_this->Text, 1 );
  EffectsEffect_OnSetNoOfCycles((EffectsEffect)&_this->RectEffect, 1 );
  EffectsEffect_OnSetCycleDuration((EffectsEffect)&_this->RectEffect, 2000 );
  EffectsEffect_OnSetEnabled((EffectsEffect)&_this->RectEffect, 0 );
  _this->RectEffect.Value2 = _Const0084;
  _this->RectEffect.Value1 = _this->Text.Super1.Bounds;
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Rectangle ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Background ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Rectangle1 ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Rectangle2 ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->TempCurrentSymbol ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->TempCurrent ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->HumidityCurrent ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->wifi ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->home ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Day ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Time ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->weatherSymbol ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->TempOutdoor ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->humidity ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->bluetooth ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Mode ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Fan ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->ScreenBrightness ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Off ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->SimpleTouchHandler ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->SimpleTouchHandler1 ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->SimpleTouchHandler2 ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->SimpleTouchHandler3 ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->SimpleTouchHandler4 ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->SimpleTouchHandler5 ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->SimpleTouchHandler6 ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Text ), 0 );
  ViewsImage_OnSetBitmap( &_this->Background, EwLoadResource( &Applicationblue_720_720, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->TempCurrentSymbol, EwLoadResource( &Applicationsettings1_50_44, 
  ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->TempCurrent, EwLoadResource( &ApplicationFont, ResourcesFont ));
  ViewsText_OnSetFont( &_this->HumidityCurrent, EwLoadResource( &ResourcesFontMedium, 
  ResourcesFont ));
  ViewsImage_OnSetBitmap( &_this->wifi, EwLoadResource( &Applicationwifi_48_40, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->home, EwLoadResource( &Applicationhome1_24_23, 
  ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->Day, EwLoadResource( &ResourcesFontSmall, ResourcesFont ));
  ViewsText_OnSetFont( &_this->Time, EwLoadResource( &ResourcesFontMedium, ResourcesFont ));
  ViewsImage_OnSetBitmap( &_this->weatherSymbol, EwLoadResource( &Applicationweather_35_30, 
  ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->TempOutdoor, EwLoadResource( &ResourcesFontMedium, 
  ResourcesFont ));
  ViewsImage_OnSetBitmap( &_this->humidity, EwLoadResource( &Applicationhumidity_small_14_18, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->bluetooth, EwLoadResource( &ApplicationBluetooth_21_40, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->Mode, EwLoadResource( &Applicationsettings1_50_44, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->Fan, EwLoadResource( &Applicationfan_50_50, ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->ScreenBrightness, EwLoadResource( &Applicationsettings_50_49, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->Off, EwLoadResource( &Applicationshutdown_43_50, 
  ResourcesBitmap ));
  _this->SimpleTouchHandler.OnDrag = EwNewSlot( _this, ApplicationThermostat_SimpleDragSlot );
  _this->SimpleTouchHandler.OnPress = EwNewSlot( _this, ApplicationThermostat_SimpleTouchSlot );
  _this->Timer.OnTrigger = EwNewSlot( _this, ApplicationThermostat_TimerSlot );
  _this->SimpleTouchHandler1.OnPress = EwNewSlot( _this, ApplicationThermostat_SimpleTouchSlot1 );
  _this->SimpleTouchHandler2.OnPress = EwNewSlot( _this, ApplicationThermostat_SimpleTouchSlot2 );
  _this->SimpleTouchHandler3.OnPress = EwNewSlot( _this, ApplicationThermostat_SimpleTouchSlot3 );
  _this->SimpleTouchHandler4.OnPress = EwNewSlot( _this, ApplicationThermostat_SimpleTouchSlot4 );
  _this->SimpleTouchHandler5.OnPress = EwNewSlot( _this, ApplicationThermostat_SimpleTouchSlot5 );
  _this->SimpleTouchHandler6.OnPress = EwNewSlot( _this, ApplicationThermostat_SimpleTouchSlot6 );
  _this->Timer1.OnTrigger = EwNewSlot( _this, ApplicationThermostat_TimerSlot1 );
  _this->Timer2.OnTrigger = EwNewSlot( _this, ApplicationThermostat_TimerSlot2 );
  _this->Timer3.OnTrigger = EwNewSlot( _this, ApplicationThermostat_TimerSlot3 );
  _this->Timer4.OnTrigger = EwNewSlot( _this, ApplicationThermostat_TimerSlot4 );
  _this->PropertyObserver1.OnEvent = EwNullSlot;
  CorePropertyObserver_OnSetOutlet( &_this->PropertyObserver1, EwNewRef( EwGetAutoObject( 
  &ApplicationDevice, ApplicationDeviceClass ), ApplicationDeviceClass_OnGetDay, 
  ApplicationDeviceClass_OnSetDay ));
  _this->PropertyObserver2.OnEvent = EwNullSlot;
  CorePropertyObserver_OnSetOutlet( &_this->PropertyObserver2, EwNewRef( EwGetAutoObject( 
  &ApplicationDevice, ApplicationDeviceClass ), ApplicationDeviceClass_OnGetYear, 
  ApplicationDeviceClass_OnSetYear ));
  _this->PropertyObserver3.OnEvent = EwNullSlot;
  CorePropertyObserver_OnSetOutlet( &_this->PropertyObserver3, EwNewRef( EwGetAutoObject( 
  &ApplicationDevice, ApplicationDeviceClass ), ApplicationDeviceClass_OnGetMonth, 
  ApplicationDeviceClass_OnSetMonth ));
  _this->PropertyObserver5.OnEvent = EwNewSlot( _this, ApplicationThermostat_onEvent1 );
  CorePropertyObserver_OnSetOutlet( &_this->PropertyObserver5, EwNewRef( EwGetAutoObject( 
  &ApplicationDevice, ApplicationDeviceClass ), ApplicationDeviceClass_OnGetMode, 
  ApplicationDeviceClass_OnSetMode ));
  ViewsText_OnSetFont( &_this->Text, EwLoadResource( &ResourcesFontLarge, ResourcesFont ));
  _this->RectEffect.Super1.OnFinished = EwNewSlot( _this, ApplicationThermostat_EffectsSlot );
  _this->RectEffect.Outlet = EwNewRef( &_this->Text, CoreRectView_OnGetBounds, CoreRectView__OnSetBounds );
  _this->PropertyObserverBt.OnEvent = EwNullSlot;
  CorePropertyObserver_OnSetOutlet( &_this->PropertyObserverBt, EwNewRef( EwGetAutoObject( 
  &ApplicationDevice, ApplicationDeviceClass ), ApplicationDeviceClass_OnGetBtConnected, 
  ApplicationDeviceClass_OnSetBtConnected ));
  _this->PropertyObserverWifi.OnEvent = EwNullSlot;
  CorePropertyObserver_OnSetOutlet( &_this->PropertyObserverWifi, EwNewRef( EwGetAutoObject( 
  &ApplicationDevice, ApplicationDeviceClass ), ApplicationDeviceClass_OnGetWifiConnected, 
  ApplicationDeviceClass_OnSetWifiConnected ));

  /* Call the user defined constructor */
  ApplicationThermostat_Init( _this, aArg );
}

/* Re-Initializer for the class 'Application::Thermostat' */
void ApplicationThermostat__ReInit( ApplicationThermostat _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsRectangle__ReInit( &_this->Rectangle );
  ViewsImage__ReInit( &_this->Background );
  ViewsRectangle__ReInit( &_this->Rectangle1 );
  ViewsRectangle__ReInit( &_this->Rectangle2 );
  ViewsImage__ReInit( &_this->TempCurrentSymbol );
  ViewsText__ReInit( &_this->TempCurrent );
  ViewsText__ReInit( &_this->HumidityCurrent );
  ViewsImage__ReInit( &_this->wifi );
  ViewsImage__ReInit( &_this->home );
  ViewsText__ReInit( &_this->Day );
  ViewsText__ReInit( &_this->Time );
  ViewsImage__ReInit( &_this->weatherSymbol );
  ViewsText__ReInit( &_this->TempOutdoor );
  ViewsImage__ReInit( &_this->humidity );
  ViewsImage__ReInit( &_this->bluetooth );
  ViewsImage__ReInit( &_this->Mode );
  ViewsImage__ReInit( &_this->Fan );
  ViewsImage__ReInit( &_this->ScreenBrightness );
  ViewsImage__ReInit( &_this->Off );
  CoreSimpleTouchHandler__ReInit( &_this->SimpleTouchHandler );
  CoreTimer__ReInit( &_this->Timer );
  CoreSimpleTouchHandler__ReInit( &_this->SimpleTouchHandler1 );
  CoreSimpleTouchHandler__ReInit( &_this->SimpleTouchHandler2 );
  CoreSimpleTouchHandler__ReInit( &_this->SimpleTouchHandler3 );
  CoreSimpleTouchHandler__ReInit( &_this->SimpleTouchHandler4 );
  CoreSimpleTouchHandler__ReInit( &_this->SimpleTouchHandler5 );
  CoreSimpleTouchHandler__ReInit( &_this->SimpleTouchHandler6 );
  CoreTimer__ReInit( &_this->Timer1 );
  CoreTimer__ReInit( &_this->Timer2 );
  CoreTimer__ReInit( &_this->Timer3 );
  CoreTimer__ReInit( &_this->Timer4 );
  CorePropertyObserver__ReInit( &_this->PropertyObserver1 );
  CorePropertyObserver__ReInit( &_this->PropertyObserver2 );
  CorePropertyObserver__ReInit( &_this->PropertyObserver3 );
  CorePropertyObserver__ReInit( &_this->PropertyObserver5 );
  ViewsText__ReInit( &_this->Text );
  EffectsRectEffect__ReInit( &_this->RectEffect );
  CorePropertyObserver__ReInit( &_this->PropertyObserverBt );
  CorePropertyObserver__ReInit( &_this->PropertyObserverWifi );
}

/* Finalizer method for the class 'Application::Thermostat' */
void ApplicationThermostat__Done( ApplicationThermostat _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->Rectangle );
  ViewsImage__Done( &_this->Background );
  ViewsRectangle__Done( &_this->Rectangle1 );
  ViewsRectangle__Done( &_this->Rectangle2 );
  ViewsImage__Done( &_this->TempCurrentSymbol );
  ViewsText__Done( &_this->TempCurrent );
  ViewsText__Done( &_this->HumidityCurrent );
  ViewsImage__Done( &_this->wifi );
  ViewsImage__Done( &_this->home );
  ViewsText__Done( &_this->Day );
  ViewsText__Done( &_this->Time );
  ViewsImage__Done( &_this->weatherSymbol );
  ViewsText__Done( &_this->TempOutdoor );
  ViewsImage__Done( &_this->humidity );
  ViewsImage__Done( &_this->bluetooth );
  ViewsImage__Done( &_this->Mode );
  ViewsImage__Done( &_this->Fan );
  ViewsImage__Done( &_this->ScreenBrightness );
  ViewsImage__Done( &_this->Off );
  CoreSimpleTouchHandler__Done( &_this->SimpleTouchHandler );
  CoreTimer__Done( &_this->Timer );
  CoreSimpleTouchHandler__Done( &_this->SimpleTouchHandler1 );
  CoreSimpleTouchHandler__Done( &_this->SimpleTouchHandler2 );
  CoreSimpleTouchHandler__Done( &_this->SimpleTouchHandler3 );
  CoreSimpleTouchHandler__Done( &_this->SimpleTouchHandler4 );
  CoreSimpleTouchHandler__Done( &_this->SimpleTouchHandler5 );
  CoreSimpleTouchHandler__Done( &_this->SimpleTouchHandler6 );
  CoreTimer__Done( &_this->Timer1 );
  CoreTimer__Done( &_this->Timer2 );
  CoreTimer__Done( &_this->Timer3 );
  CoreTimer__Done( &_this->Timer4 );
  CorePropertyObserver__Done( &_this->PropertyObserver1 );
  CorePropertyObserver__Done( &_this->PropertyObserver2 );
  CorePropertyObserver__Done( &_this->PropertyObserver3 );
  CorePropertyObserver__Done( &_this->PropertyObserver5 );
  ViewsText__Done( &_this->Text );
  EffectsRectEffect__Done( &_this->RectEffect );
  CorePropertyObserver__Done( &_this->PropertyObserverBt );
  CorePropertyObserver__Done( &_this->PropertyObserverWifi );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void ApplicationThermostat_Init( ApplicationThermostat _this, XHandle aArg )
{
  XInt32 temperature;
  XInt32 local_humidity;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  ViewsText_OnSetString( &_this->Time, EwConcatString( EwConcatString( EwConcatString( 
  EwNewStringInt( EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Hour, 
  0, 10 ), EwLoadString( &_Const0085 )), EwNewStringInt( EwGetAutoObject( &ApplicationDevice, 
  ApplicationDeviceClass )->Minute, 0, 10 )), EwGetAutoObject( &ApplicationDevice, 
  ApplicationDeviceClass )->am_pm ));
  ViewsText_OnSetString( &_this->Day, EwConcatString( EwConcatString( EwConcatString( 
  EwNewStringInt( EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Day, 
  0, 10 ), EwLoadString( &_Const0086 )), EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->month ), 
  EwLoadString( &_Const0087 )));
  temperature = 25;
  local_humidity = 50;
  {
    extern XInt32  temp_hum_13_click_get_temp(void);
    extern XInt32  temp_hum_13_click_get_humidity(void);
    temperature=(5*(temp_hum_13_click_get_temp()-32))/9;
    local_humidity=temp_hum_13_click_get_humidity();
  }

  if ( EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Mode == 0 )
  {
    ViewsImage_OnSetBitmap( &_this->TempCurrentSymbol, EwLoadResource( &Applicationshutdown_43_50, 
    ResourcesBitmap ));
    ViewsImage_OnSetBitmap( &_this->Background, EwLoadResource( &Applicationbg_black, 
    ResourcesBitmap ));
    ViewsRectangle_OnSetColor( &_this->Rectangle1, _Const0088 );
    ViewsRectangle_OnSetColor( &_this->Rectangle2, _Const0088 );
  }
  else
    if ( EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Mode == 
        1 )
    {
      ViewsImage_OnSetBitmap( &_this->TempCurrentSymbol, EwLoadResource( &Applicationhotmode_43_60, 
      ResourcesBitmap ));
      ViewsImage_OnSetBitmap( &_this->Background, EwLoadResource( &Applicationbg_brown, 
      ResourcesBitmap ));
      ViewsRectangle_OnSetColor( &_this->Rectangle1, _Const0089 );
      ViewsRectangle_OnSetColor( &_this->Rectangle2, _Const0089 );
    }
    else
    {
      ViewsImage_OnSetBitmap( &_this->TempCurrentSymbol, EwLoadResource( &Applicationsettings1_50_44, 
      ResourcesBitmap ));
      ViewsImage_OnSetBitmap( &_this->Background, EwLoadResource( &Applicationblue_720_720, 
      ResourcesBitmap ));
      ViewsRectangle_OnSetColor( &_this->Rectangle1, _Const0053 );
      ViewsRectangle_OnSetColor( &_this->Rectangle2, _Const0053 );
    }

  CoreTimer_OnSetEnabled( &_this->Timer3, 1 );
  CoreSimpleTouchHandler_OnSetEnabled( &_this->SimpleTouchHandler, 1 );
  CoreSimpleTouchHandler_OnSetEnabled( &_this->SimpleTouchHandler3, 0 );
  CoreSimpleTouchHandler_OnSetEnabled( &_this->SimpleTouchHandler4, 0 );
  CoreSimpleTouchHandler_OnSetEnabled( &_this->SimpleTouchHandler5, 0 );
  CoreSimpleTouchHandler_OnSetEnabled( &_this->SimpleTouchHandler6, 0 );
  EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Temperature = temperature;
  EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Humidity = local_humidity;
  ViewsText_OnSetString( &_this->TempCurrent, EwConcatString( EwNewStringInt( EwGetAutoObject( 
  &ApplicationDevice, ApplicationDeviceClass )->Temperature, 0, 10 ), EwLoadString( 
  &_Const0032 )));
  ViewsText_OnSetString( &_this->HumidityCurrent, EwConcatString( EwNewStringInt( 
  EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Humidity, 0, 10 ), 
  EwLoadString( &_Const008A )));

  if ( EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->BtConnected 
      == 1 )
    ViewsRectangle_OnSetVisible( &_this->Rectangle2, 1 );

  if ( EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->WifiConnected 
      == 1 )
    ViewsRectangle_OnSetVisible( &_this->Rectangle1, 1 );
}

/* 'C' function for method : 'Application::Thermostat.SimpleTouchSlot()' */
void ApplicationThermostat_SimpleTouchSlot( ApplicationThermostat _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( ViewsImage_OnGetVisible( &_this->Mode ) == 0 )
  {
    CoreTimer_OnSetEnabled( &_this->Timer, 0 );
    ViewsImage_OnSetVisible( &_this->Mode, 1 );
    ViewsImage_OnSetVisible( &_this->weatherSymbol, 1 );
    ViewsText_OnSetVisible( &_this->TempOutdoor, 1 );
    ViewsImage_OnSetVisible( &_this->Fan, 1 );
    ViewsImage_OnSetVisible( &_this->ScreenBrightness, 1 );
    ViewsImage_OnSetVisible( &_this->Off, 1 );
    CoreTimer_OnSetEnabled( &_this->Timer, 1 );
    CoreSimpleTouchHandler_OnSetEnabled( &_this->SimpleTouchHandler3, 1 );
    CoreSimpleTouchHandler_OnSetEnabled( &_this->SimpleTouchHandler4, 1 );
    CoreSimpleTouchHandler_OnSetEnabled( &_this->SimpleTouchHandler5, 1 );
    CoreSimpleTouchHandler_OnSetEnabled( &_this->SimpleTouchHandler6, 1 );
  }
}

/* 'C' function for method : 'Application::Thermostat.SimpleDragSlot()' */
void ApplicationThermostat_SimpleDragSlot( ApplicationThermostat _this, XObject 
  sender )
{
  CoreGroup newDialog;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  newDialog = ((CoreGroup)EwNewObject( ApplicationTemperatureController, 0 ));
  CoreTimer_OnSetEnabled( &_this->Timer, 0 );
  CoreSimpleTouchHandler_OnSetEnabled( &_this->SimpleTouchHandler, 0 );
  CoreSimpleTouchHandler_OnSetEnabled( &_this->SimpleTouchHandler3, 0 );
  CoreSimpleTouchHandler_OnSetEnabled( &_this->SimpleTouchHandler4, 0 );
  CoreSimpleTouchHandler_OnSetEnabled( &_this->SimpleTouchHandler5, 0 );
  CoreSimpleTouchHandler_OnSetEnabled( &_this->SimpleTouchHandler6, 0 );
  CoreGroup_SwitchToDialog((CoreGroup)_this, newDialog, 0, 0, 0, 0, 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
}

/* 'C' function for method : 'Application::Thermostat.TimerSlot()' */
void ApplicationThermostat_TimerSlot( ApplicationThermostat _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  ViewsImage_OnSetVisible( &_this->Mode, 0 );
  ViewsImage_OnSetVisible( &_this->weatherSymbol, 0 );
  ViewsText_OnSetVisible( &_this->TempOutdoor, 0 );
  ViewsImage_OnSetVisible( &_this->Fan, 0 );
  ViewsImage_OnSetVisible( &_this->ScreenBrightness, 0 );
  ViewsImage_OnSetVisible( &_this->Off, 0 );
  CoreTimer_OnSetEnabled( &_this->Timer, 0 );
  CoreSimpleTouchHandler_OnSetEnabled( &_this->SimpleTouchHandler, 1 );
  CoreSimpleTouchHandler_OnSetEnabled( &_this->SimpleTouchHandler3, 0 );
  CoreSimpleTouchHandler_OnSetEnabled( &_this->SimpleTouchHandler4, 0 );
  CoreSimpleTouchHandler_OnSetEnabled( &_this->SimpleTouchHandler5, 0 );
  CoreSimpleTouchHandler_OnSetEnabled( &_this->SimpleTouchHandler6, 0 );
}

/* 'C' function for method : 'Application::Thermostat.SimpleTouchSlot1()' */
void ApplicationThermostat_SimpleTouchSlot1( ApplicationThermostat _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( ViewsRectangle_OnGetVisible( &_this->Rectangle1 ) == 1 )
  {
    EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->TurnWifiOn = 
    0;
    ViewsRectangle_OnSetVisible( &_this->Rectangle1, 0 );
  }
  else
  {
    EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->TurnWifiOn = 
    1;
    CoreTimer_OnSetEnabled( &_this->Timer1, 1 );
  }
}

/* 'C' function for method : 'Application::Thermostat.SimpleTouchSlot2()' */
void ApplicationThermostat_SimpleTouchSlot2( ApplicationThermostat _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( ViewsRectangle_OnGetVisible( &_this->Rectangle2 ) == 1 )
  {
    EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->TurnBtOn = 0;
    ViewsRectangle_OnSetVisible( &_this->Rectangle2, 0 );
  }
  else
  {
    EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->TurnBtOn = 1;
    CoreTimer_OnSetEnabled( &_this->Timer2, 1 );
  }
}

/* 'C' function for method : 'Application::Thermostat.SimpleTouchSlot3()' */
void ApplicationThermostat_SimpleTouchSlot3( ApplicationThermostat _this, XObject 
  sender )
{
  CoreGroup newDialog;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  newDialog = ((CoreGroup)EwNewObject( ApplicationModeController, 0 ));
  CoreTimer_OnSetEnabled( &_this->Timer, 0 );
  CoreSimpleTouchHandler_OnSetEnabled( &_this->SimpleTouchHandler, 0 );
  CoreSimpleTouchHandler_OnSetEnabled( &_this->SimpleTouchHandler3, 0 );
  CoreSimpleTouchHandler_OnSetEnabled( &_this->SimpleTouchHandler4, 0 );
  CoreSimpleTouchHandler_OnSetEnabled( &_this->SimpleTouchHandler5, 0 );
  CoreSimpleTouchHandler_OnSetEnabled( &_this->SimpleTouchHandler6, 0 );
  CoreGroup_SwitchToDialog((CoreGroup)_this, newDialog, ((EffectsTransition)EwGetAutoObject( 
  &EffectsFadeInOutCentered, EffectsFadeInOutTransition )), 0, 0, 0, 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
}

/* 'C' function for method : 'Application::Thermostat.SimpleTouchSlot4()' */
void ApplicationThermostat_SimpleTouchSlot4( ApplicationThermostat _this, XObject 
  sender )
{
  CoreGroup newDialog;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  newDialog = ((CoreGroup)EwNewObject( ApplicationFanController, 0 ));
  CoreTimer_OnSetEnabled( &_this->Timer, 0 );
  CoreSimpleTouchHandler_OnSetEnabled( &_this->SimpleTouchHandler, 0 );
  CoreSimpleTouchHandler_OnSetEnabled( &_this->SimpleTouchHandler3, 0 );
  CoreSimpleTouchHandler_OnSetEnabled( &_this->SimpleTouchHandler4, 0 );
  CoreSimpleTouchHandler_OnSetEnabled( &_this->SimpleTouchHandler5, 0 );
  CoreSimpleTouchHandler_OnSetEnabled( &_this->SimpleTouchHandler6, 0 );
  CoreGroup_SwitchToDialog((CoreGroup)_this, newDialog, ((EffectsTransition)EwGetAutoObject( 
  &EffectsFadeInOutCentered, EffectsFadeInOutTransition )), 0, 0, 0, 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
}

/* 'C' function for method : 'Application::Thermostat.SimpleTouchSlot5()' */
void ApplicationThermostat_SimpleTouchSlot5( ApplicationThermostat _this, XObject 
  sender )
{
  CoreGroup newDialog;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  newDialog = ((CoreGroup)EwNewObject( ApplicationBrightnessController, 0 ));
  CoreTimer_OnSetEnabled( &_this->Timer, 0 );
  CoreSimpleTouchHandler_OnSetEnabled( &_this->SimpleTouchHandler, 0 );
  CoreSimpleTouchHandler_OnSetEnabled( &_this->SimpleTouchHandler3, 0 );
  CoreSimpleTouchHandler_OnSetEnabled( &_this->SimpleTouchHandler4, 0 );
  CoreSimpleTouchHandler_OnSetEnabled( &_this->SimpleTouchHandler5, 0 );
  CoreSimpleTouchHandler_OnSetEnabled( &_this->SimpleTouchHandler6, 0 );
  CoreGroup_SwitchToDialog((CoreGroup)_this, newDialog, ((EffectsTransition)EwGetAutoObject( 
  &EffectsFadeInOutCentered, EffectsFadeInOutTransition )), 0, 0, 0, 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
}

/* 'C' function for method : 'Application::Thermostat.SimpleTouchSlot6()' */
void ApplicationThermostat_SimpleTouchSlot6( ApplicationThermostat _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( sender );
}

/* 'C' function for method : 'Application::Thermostat.TimerSlot1()' */
void ApplicationThermostat_TimerSlot1( ApplicationThermostat _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  ViewsImage_OnSetVisible( &_this->wifi, (XBool)!ViewsImage_OnGetVisible( &_this->wifi ));

  if ( EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->WifiConnected 
      == 1 )
  {
    CoreTimer_OnSetEnabled( &_this->Timer1, 0 );
    ViewsRectangle_OnSetVisible( &_this->Rectangle1, 1 );
    ViewsImage_OnSetVisible( &_this->wifi, 1 );
    EffectsEffect_OnSetEnabled((EffectsEffect)&_this->RectEffect, 0 );
    ViewsText_OnSetString( &_this->Text, EwLoadString( &_Const008B ));
    ViewsText_OnSetVisible( &_this->Text, 1 );
    EffectsEffect_OnSetEnabled((EffectsEffect)&_this->RectEffect, 1 );
    CoreTimer_OnSetEnabled( &_this->Timer3, 1 );

    if ( EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Hour > 12 )
    {
      EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Hour = 24 - 
      EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Hour;
      EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->am_pm = EwShareString( 
      EwLoadString( &_Const008C ));
    }

    if ( EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Month == 
        0 )
      EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->month = EwShareString( 
      EwLoadString( &_Const008D ));

    if ( EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Month == 
        1 )
      EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->month = EwShareString( 
      EwLoadString( &_Const008E ));

    if ( EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Month == 
        2 )
      EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->month = EwShareString( 
      EwLoadString( &_Const0002 ));

    if ( EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Month == 
        3 )
      EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->month = EwShareString( 
      EwLoadString( &_Const008F ));

    if ( EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Month == 
        4 )
      EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->month = EwShareString( 
      EwLoadString( &_Const0090 ));

    if ( EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Month == 
        5 )
      EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->month = EwShareString( 
      EwLoadString( &_Const0091 ));

    if ( EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Month == 
        6 )
      EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->month = EwShareString( 
      EwLoadString( &_Const0092 ));

    if ( EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Month == 
        7 )
      EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->month = EwShareString( 
      EwLoadString( &_Const0093 ));

    if ( EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Month == 
        8 )
      EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->month = EwShareString( 
      EwLoadString( &_Const0094 ));

    if ( EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Month == 
        9 )
      EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->month = EwShareString( 
      EwLoadString( &_Const0095 ));

    if ( EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Month == 
        10 )
      EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->month = EwShareString( 
      EwLoadString( &_Const0096 ));

    if ( EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Month == 
        11 )
      EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->month = EwShareString( 
      EwLoadString( &_Const0097 ));

    ViewsText_OnSetString( &_this->Time, EwConcatString( EwConcatString( EwConcatString( 
    EwNewStringInt( EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Hour, 
    0, 10 ), EwLoadString( &_Const0085 )), EwNewStringInt( EwGetAutoObject( &ApplicationDevice, 
    ApplicationDeviceClass )->Minute, 0, 10 )), EwGetAutoObject( &ApplicationDevice, 
    ApplicationDeviceClass )->am_pm ));
    ViewsText_OnSetString( &_this->Day, EwConcatString( EwConcatString( EwConcatString( 
    EwNewStringInt( EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Day, 
    0, 10 ), EwLoadString( &_Const0086 )), EwGetAutoObject( &ApplicationDevice, 
    ApplicationDeviceClass )->month ), EwLoadString( &_Const0087 )));
  }
}

/* 'C' function for method : 'Application::Thermostat.TimerSlot2()' */
void ApplicationThermostat_TimerSlot2( ApplicationThermostat _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  ViewsImage_OnSetVisible( &_this->bluetooth, (XBool)!ViewsImage_OnGetVisible( &_this->bluetooth ));

  if ( EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->BtConnected 
      == 1 )
  {
    CoreTimer_OnSetEnabled( &_this->Timer2, 0 );
    ViewsRectangle_OnSetVisible( &_this->Rectangle2, 1 );
    ViewsImage_OnSetVisible( &_this->bluetooth, 1 );
    EffectsEffect_OnSetEnabled((EffectsEffect)&_this->RectEffect, 0 );
    ViewsText_OnSetString( &_this->Text, EwLoadString( &_Const0098 ));
    ViewsText_OnSetVisible( &_this->Text, 1 );
    EffectsEffect_OnSetEnabled((EffectsEffect)&_this->RectEffect, 1 );
  }
}

/* 'C' function for method : 'Application::Thermostat.TimerSlot3()' */
void ApplicationThermostat_TimerSlot3( ApplicationThermostat _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Minute >= 
      60 )
  {
    EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Hour = EwGetAutoObject( 
    &ApplicationDevice, ApplicationDeviceClass )->Hour + 1;
    EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Minute = 0;
  }
  else
    EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Minute = EwGetAutoObject( 
    &ApplicationDevice, ApplicationDeviceClass )->Minute + 1;

  if ( EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Hour > 12 )
  {
    EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Hour = 24 - EwGetAutoObject( 
    &ApplicationDevice, ApplicationDeviceClass )->Hour;
    EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->am_pm = EwShareString( 
    EwLoadString( &_Const008C ));
  }

  ViewsText_OnSetString( &_this->Time, EwConcatString( EwConcatString( EwConcatString( 
  EwNewStringInt( EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Hour, 
  0, 10 ), EwLoadString( &_Const0085 )), EwNewStringInt( EwGetAutoObject( &ApplicationDevice, 
  ApplicationDeviceClass )->Minute, 0, 10 )), EwGetAutoObject( &ApplicationDevice, 
  ApplicationDeviceClass )->am_pm ));
}

/* 'C' function for method : 'Application::Thermostat.TimerSlot4()' */
void ApplicationThermostat_TimerSlot4( ApplicationThermostat _this, XObject sender )
{
  XInt32 temperature;
  XInt32 local_humidity;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  temperature = 25;
  local_humidity = 50;
  {
    extern XInt32  temp_hum_13_click_get_temp(void);
    extern XInt32  temp_hum_13_click_get_humidity(void);
    temperature=(5*(temp_hum_13_click_get_temp()-32))/9;
    local_humidity=temp_hum_13_click_get_humidity();
  }
  EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Temperature = temperature;
  EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Humidity = local_humidity;
  ViewsText_OnSetString( &_this->TempCurrent, EwConcatString( EwNewStringInt( EwGetAutoObject( 
  &ApplicationDevice, ApplicationDeviceClass )->Temperature, 0, 10 ), EwLoadString( 
  &_Const0032 )));
  ViewsText_OnSetString( &_this->HumidityCurrent, EwConcatString( EwNewStringInt( 
  EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Humidity, 0, 10 ), 
  EwLoadString( &_Const008A )));
}

/* This slot method is executed when the associated property observer 'PropertyObserver' 
   is notified. */
void ApplicationThermostat_onEvent1( ApplicationThermostat _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Mode == 0 )
  {
    ViewsImage_OnSetBitmap( &_this->TempCurrentSymbol, EwLoadResource( &Applicationshutdown_43_50, 
    ResourcesBitmap ));
    ViewsImage_OnSetBitmap( &_this->Background, EwLoadResource( &Applicationbg_black, 
    ResourcesBitmap ));
    ViewsRectangle_OnSetColor( &_this->Rectangle1, _Const0088 );
    ViewsRectangle_OnSetColor( &_this->Rectangle2, _Const0088 );
  }
  else
    if ( EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass )->Mode == 
        1 )
    {
      ViewsImage_OnSetBitmap( &_this->TempCurrentSymbol, EwLoadResource( &Applicationhotmode_43_60, 
      ResourcesBitmap ));
      ViewsImage_OnSetBitmap( &_this->Background, EwLoadResource( &Applicationbg_brown, 
      ResourcesBitmap ));
      ViewsRectangle_OnSetColor( &_this->Rectangle1, _Const0089 );
      ViewsRectangle_OnSetColor( &_this->Rectangle2, _Const0089 );
    }
    else
    {
      ViewsImage_OnSetBitmap( &_this->TempCurrentSymbol, EwLoadResource( &Applicationsettings1_50_44, 
      ResourcesBitmap ));
      ViewsImage_OnSetBitmap( &_this->Background, EwLoadResource( &Applicationblue_720_720, 
      ResourcesBitmap ));
      ViewsRectangle_OnSetColor( &_this->Rectangle1, _Const0053 );
      ViewsRectangle_OnSetColor( &_this->Rectangle2, _Const0053 );
    }
}

/* 'C' function for method : 'Application::Thermostat.EffectsSlot()' */
void ApplicationThermostat_EffectsSlot( ApplicationThermostat _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  ViewsText_OnSetVisible( &_this->Text, 0 );
}

/* Variants derived from the class : 'Application::Thermostat' */
EW_DEFINE_CLASS_VARIANTS( ApplicationThermostat )
EW_END_OF_CLASS_VARIANTS( ApplicationThermostat )

/* Virtual Method Table (VMT) for the class : 'Application::Thermostat' */
EW_DEFINE_CLASS( ApplicationThermostat, CoreGroup, Rectangle, _.VMT, _.VMT, _.VMT, 
                 _.VMT, _.VMT, "Application::Thermostat" )
  CoreRectView_initLayoutContext,
  CoreView_GetRoot,
  CoreGroup_Draw,
  CoreGroup_GetClipping,
  CoreView_HandleEvent,
  CoreGroup_CursorHitTest,
  CoreGroup_AdjustDrawingArea,
  CoreRectView_ArrangeView,
  CoreRectView_MoveView,
  CoreRectView_GetExtent,
  CoreGroup_ChangeViewState,
  CoreGroup_OnSetBounds,
  CoreGroup_OnSetFocus,
  CoreGroup_OnSetOpacity,
  CoreGroup_DispatchEvent,
  CoreGroup_BroadcastEvent,
  CoreGroup_UpdateLayout,
  CoreGroup_UpdateViewState,
  CoreGroup_InvalidateArea,
EW_END_OF_CLASS( ApplicationThermostat )

/* Include a file containing the bitmap resource : 'Application::black_60_60' */
#include "_Applicationblack_60_60.h"

/* Table with links to derived variants of the bitmap resource : 'Application::black_60_60' */
EW_RES_WITHOUT_VARIANTS( Applicationblack_60_60 )

/* Embedded Wizard */
