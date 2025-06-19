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

#ifndef _ApplicationThermostat_H
#define _ApplicationThermostat_H

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

#include "_CoreGroup.h"
#include "_CorePropertyObserver.h"
#include "_CoreSimpleTouchHandler.h"
#include "_CoreTimer.h"
#include "_EffectsRectEffect.h"
#include "_ViewsImage.h"
#include "_ViewsRectangle.h"
#include "_ViewsText.h"

/* Forward declaration of the class Application::Thermostat */
#ifndef _ApplicationThermostat_
  EW_DECLARE_CLASS( ApplicationThermostat )
#define _ApplicationThermostat_
#endif

/* Forward declaration of the class Core::DialogContext */
#ifndef _CoreDialogContext_
  EW_DECLARE_CLASS( CoreDialogContext )
#define _CoreDialogContext_
#endif

/* Forward declaration of the class Core::KeyPressHandler */
#ifndef _CoreKeyPressHandler_
  EW_DECLARE_CLASS( CoreKeyPressHandler )
#define _CoreKeyPressHandler_
#endif

/* Forward declaration of the class Core::LayoutContext */
#ifndef _CoreLayoutContext_
  EW_DECLARE_CLASS( CoreLayoutContext )
#define _CoreLayoutContext_
#endif

/* Forward declaration of the class Core::TaskQueue */
#ifndef _CoreTaskQueue_
  EW_DECLARE_CLASS( CoreTaskQueue )
#define _CoreTaskQueue_
#endif

/* Forward declaration of the class Core::View */
#ifndef _CoreView_
  EW_DECLARE_CLASS( CoreView )
#define _CoreView_
#endif

/* Forward declaration of the class Effects::Fader */
#ifndef _EffectsFader_
  EW_DECLARE_CLASS( EffectsFader )
#define _EffectsFader_
#endif


/* This is the root component of the entire GUI application. */
EW_DEFINE_FIELDS( ApplicationThermostat, CoreGroup )
  EW_OBJECT  ( Rectangle,       ViewsRectangle )
  EW_OBJECT  ( Background,      ViewsImage )
  EW_OBJECT  ( Rectangle1,      ViewsRectangle )
  EW_OBJECT  ( Rectangle2,      ViewsRectangle )
  EW_OBJECT  ( TempCurrentSymbol, ViewsImage )
  EW_OBJECT  ( TempCurrent,     ViewsText )
  EW_OBJECT  ( HumidityCurrent, ViewsText )
  EW_OBJECT  ( wifi,            ViewsImage )
  EW_OBJECT  ( home,            ViewsImage )
  EW_OBJECT  ( Day,             ViewsText )
  EW_OBJECT  ( Time,            ViewsText )
  EW_OBJECT  ( weatherSymbol,   ViewsImage )
  EW_OBJECT  ( TempOutdoor,     ViewsText )
  EW_OBJECT  ( humidity,        ViewsImage )
  EW_OBJECT  ( bluetooth,       ViewsImage )
  EW_OBJECT  ( Mode,            ViewsImage )
  EW_OBJECT  ( Fan,             ViewsImage )
  EW_OBJECT  ( ScreenBrightness, ViewsImage )
  EW_OBJECT  ( Off,             ViewsImage )
  EW_OBJECT  ( SimpleTouchHandler, CoreSimpleTouchHandler )
  EW_OBJECT  ( Timer,           CoreTimer )
  EW_OBJECT  ( SimpleTouchHandler1, CoreSimpleTouchHandler )
  EW_OBJECT  ( SimpleTouchHandler2, CoreSimpleTouchHandler )
  EW_OBJECT  ( SimpleTouchHandler3, CoreSimpleTouchHandler )
  EW_OBJECT  ( SimpleTouchHandler4, CoreSimpleTouchHandler )
  EW_OBJECT  ( SimpleTouchHandler5, CoreSimpleTouchHandler )
  EW_OBJECT  ( SimpleTouchHandler6, CoreSimpleTouchHandler )
  EW_OBJECT  ( Timer1,          CoreTimer )
  EW_OBJECT  ( Timer2,          CoreTimer )
  EW_OBJECT  ( Timer3,          CoreTimer )
  EW_OBJECT  ( Timer4,          CoreTimer )
  EW_OBJECT  ( PropertyObserver1, CorePropertyObserver )
  EW_OBJECT  ( PropertyObserver2, CorePropertyObserver )
  EW_OBJECT  ( PropertyObserver3, CorePropertyObserver )
  EW_OBJECT  ( PropertyObserver5, CorePropertyObserver )
  EW_OBJECT  ( Text,            ViewsText )
  EW_OBJECT  ( RectEffect,      EffectsRectEffect )
  EW_OBJECT  ( PropertyObserverBt, CorePropertyObserver )
  EW_OBJECT  ( PropertyObserverWifi, CorePropertyObserver )
EW_END_OF_FIELDS( ApplicationThermostat )

/* Virtual Method Table (VMT) for the class : 'Application::Thermostat' */
EW_DEFINE_METHODS( ApplicationThermostat, CoreGroup )
  EW_METHOD( initLayoutContext, void )( CoreRectView _this, XRect aBounds, CoreOutline 
    aOutline )
  EW_METHOD( GetRoot,           CoreRoot )( CoreView _this )
  EW_METHOD( Draw,              void )( CoreGroup _this, GraphicsCanvas aCanvas, 
    XRect aClip, XPoint aOffset, XInt32 aOpacity, XBool aBlend )
  EW_METHOD( GetClipping,       XRect )( CoreGroup _this )
  EW_METHOD( HandleEvent,       XObject )( CoreView _this, CoreEvent aEvent )
  EW_METHOD( CursorHitTest,     CoreCursorHit )( CoreGroup _this, XRect aArea, XInt32 
    aFinger, XInt32 aStrikeCount, CoreView aDedicatedView, CoreView aStartView, 
    XSet aRetargetReason )
  EW_METHOD( AdjustDrawingArea, XRect )( CoreGroup _this, XRect aArea )
  EW_METHOD( ArrangeView,       XPoint )( CoreRectView _this, XRect aBounds, XEnum 
    aFormation )
  EW_METHOD( MoveView,          void )( CoreRectView _this, XPoint aOffset, XBool 
    aFastMove )
  EW_METHOD( GetExtent,         XRect )( CoreRectView _this )
  EW_METHOD( ChangeViewState,   void )( CoreGroup _this, XSet aSetState, XSet aClearState )
  EW_METHOD( OnSetBounds,       void )( CoreGroup _this, XRect value )
  EW_METHOD( OnSetFocus,        void )( CoreGroup _this, CoreView value )
  EW_METHOD( OnSetOpacity,      void )( CoreGroup _this, XInt32 value )
  EW_METHOD( DispatchEvent,     XObject )( CoreGroup _this, CoreEvent aEvent )
  EW_METHOD( BroadcastEvent,    XObject )( CoreGroup _this, CoreEvent aEvent, XSet 
    aFilter )
  EW_METHOD( UpdateLayout,      void )( CoreGroup _this, XPoint aSize )
  EW_METHOD( UpdateViewState,   void )( CoreGroup _this, XSet aState )
  EW_METHOD( InvalidateArea,    void )( CoreGroup _this, XRect aArea )
EW_END_OF_METHODS( ApplicationThermostat )

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void ApplicationThermostat_Init( ApplicationThermostat _this, XHandle aArg );

/* 'C' function for method : 'Application::Thermostat.SimpleTouchSlot()' */
void ApplicationThermostat_SimpleTouchSlot( ApplicationThermostat _this, XObject 
  sender );

/* 'C' function for method : 'Application::Thermostat.SimpleDragSlot()' */
void ApplicationThermostat_SimpleDragSlot( ApplicationThermostat _this, XObject 
  sender );

/* 'C' function for method : 'Application::Thermostat.TimerSlot()' */
void ApplicationThermostat_TimerSlot( ApplicationThermostat _this, XObject sender );

/* 'C' function for method : 'Application::Thermostat.SimpleTouchSlot1()' */
void ApplicationThermostat_SimpleTouchSlot1( ApplicationThermostat _this, XObject 
  sender );

/* 'C' function for method : 'Application::Thermostat.SimpleTouchSlot2()' */
void ApplicationThermostat_SimpleTouchSlot2( ApplicationThermostat _this, XObject 
  sender );

/* 'C' function for method : 'Application::Thermostat.SimpleTouchSlot3()' */
void ApplicationThermostat_SimpleTouchSlot3( ApplicationThermostat _this, XObject 
  sender );

/* 'C' function for method : 'Application::Thermostat.SimpleTouchSlot4()' */
void ApplicationThermostat_SimpleTouchSlot4( ApplicationThermostat _this, XObject 
  sender );

/* 'C' function for method : 'Application::Thermostat.SimpleTouchSlot5()' */
void ApplicationThermostat_SimpleTouchSlot5( ApplicationThermostat _this, XObject 
  sender );

/* 'C' function for method : 'Application::Thermostat.SimpleTouchSlot6()' */
void ApplicationThermostat_SimpleTouchSlot6( ApplicationThermostat _this, XObject 
  sender );

/* 'C' function for method : 'Application::Thermostat.TimerSlot1()' */
void ApplicationThermostat_TimerSlot1( ApplicationThermostat _this, XObject sender );

/* 'C' function for method : 'Application::Thermostat.TimerSlot2()' */
void ApplicationThermostat_TimerSlot2( ApplicationThermostat _this, XObject sender );

/* 'C' function for method : 'Application::Thermostat.TimerSlot3()' */
void ApplicationThermostat_TimerSlot3( ApplicationThermostat _this, XObject sender );

/* 'C' function for method : 'Application::Thermostat.TimerSlot4()' */
void ApplicationThermostat_TimerSlot4( ApplicationThermostat _this, XObject sender );

/* This slot method is executed when the associated property observer 'PropertyObserver' 
   is notified. */
void ApplicationThermostat_onEvent1( ApplicationThermostat _this, XObject sender );

/* 'C' function for method : 'Application::Thermostat.EffectsSlot()' */
void ApplicationThermostat_EffectsSlot( ApplicationThermostat _this, XObject sender );

#ifdef __cplusplus
  }
#endif

#endif /* _ApplicationThermostat_H */

/* Embedded Wizard */
