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

#ifndef _ApplicationTemperatureController_H
#define _ApplicationTemperatureController_H

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
#include "_CoreRotateTouchHandler.h"
#include "_CoreSimpleTouchHandler.h"
#include "_CoreTimer.h"
#include "_GraphicsPath.h"
#include "_ViewsImage.h"
#include "_ViewsStrokePath.h"
#include "_ViewsText.h"
#include "_ViewsWarpImage.h"

/* Forward declaration of the class Application::TemperatureController */
#ifndef _ApplicationTemperatureController_
  EW_DECLARE_CLASS( ApplicationTemperatureController )
#define _ApplicationTemperatureController_
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


/* Deklaration of class : 'Application::TemperatureController' */
EW_DEFINE_FIELDS( ApplicationTemperatureController, CoreGroup )
  EW_OBJECT  ( Background,      ViewsImage )
  EW_OBJECT  ( RotateTouchHandler, CoreRotateTouchHandler )
  EW_OBJECT  ( Wheel,           ViewsImage )
  EW_OBJECT  ( Image,           ViewsImage )
  EW_OBJECT  ( Image1,          ViewsImage )
  EW_OBJECT  ( DeltaTempPath,   GraphicsPath )
  EW_OBJECT  ( DeltaTempView,   ViewsStrokePath )
  EW_OBJECT  ( Symbol,          ViewsImage )
  EW_OBJECT  ( ActualText,      ViewsText )
  EW_OBJECT  ( SimpleTouchHandlerPlus, CoreSimpleTouchHandler )
  EW_OBJECT  ( SimpleTouchHandlerMinus, CoreSimpleTouchHandler )
  EW_OBJECT  ( Needle,          ViewsWarpImage )
  EW_OBJECT  ( CurrentMode,     ViewsText )
  EW_OBJECT  ( CurrentMode1,    ViewsText )
  EW_OBJECT  ( Timer,           CoreTimer )
  EW_OBJECT  ( PropertyObserver, CorePropertyObserver )
  EW_PROPERTY( NominalValue,    XInt32 )
  EW_VARIABLE( startValue,      XInt32 )
EW_END_OF_FIELDS( ApplicationTemperatureController )

/* Virtual Method Table (VMT) for the class : 'Application::TemperatureController' */
EW_DEFINE_METHODS( ApplicationTemperatureController, CoreGroup )
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
  EW_METHOD( UpdateLayout,      void )( ApplicationTemperatureController _this, 
    XPoint aSize )
  EW_METHOD( UpdateViewState,   void )( ApplicationTemperatureController _this, 
    XSet aState )
  EW_METHOD( InvalidateArea,    void )( CoreGroup _this, XRect aArea )
EW_END_OF_METHODS( ApplicationTemperatureController )

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void ApplicationTemperatureController_Init( ApplicationTemperatureController _this, 
  XHandle aArg );

/* The method UpdateLayout() is invoked automatically after the size of the component 
   has been changed. This method can be overridden and filled with logic to perform 
   a sophisticated arrangement calculation for one or more enclosed views. In this 
   case the parameter aSize can be used. It contains the current size of the component. 
   Usually, all enclosed views are arranged automatically accordingly to their @Layout 
   property. UpdateLayout() gives the derived components a chance to extend this 
   automatism by a user defined algorithm. */
void ApplicationTemperatureController_UpdateLayout( ApplicationTemperatureController _this, 
  XPoint aSize );

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
  XSet aState );

/* 'C' function for method : 'Application::TemperatureController.OnSetNominalValue()' */
void ApplicationTemperatureController_OnSetNominalValue( ApplicationTemperatureController _this, 
  XInt32 value );

/* 'C' function for method : 'Application::TemperatureController.onStartSlot()' */
void ApplicationTemperatureController_onStartSlot( ApplicationTemperatureController _this, 
  XObject sender );

/* 'C' function for method : 'Application::TemperatureController.onRotateSlot()' */
void ApplicationTemperatureController_onRotateSlot( ApplicationTemperatureController _this, 
  XObject sender );

/* 'C' function for method : 'Application::TemperatureController.onEndSlot()' */
void ApplicationTemperatureController_onEndSlot( ApplicationTemperatureController _this, 
  XObject sender );

/* 'C' function for method : 'Application::TemperatureController.incrNominal()' */
void ApplicationTemperatureController_incrNominal( ApplicationTemperatureController _this, 
  XObject sender );

/* 'C' function for method : 'Application::TemperatureController.decrNominal()' */
void ApplicationTemperatureController_decrNominal( ApplicationTemperatureController _this, 
  XObject sender );

/* 'C' function for method : 'Application::TemperatureController.TimerSlot()' */
void ApplicationTemperatureController_TimerSlot( ApplicationTemperatureController _this, 
  XObject sender );

/* This slot method is executed when the associated property observer 'PropertyObserver' 
   is notified. */
void ApplicationTemperatureController_onEvent( ApplicationTemperatureController _this, 
  XObject sender );

#ifdef __cplusplus
  }
#endif

#endif /* _ApplicationTemperatureController_H */

/* Embedded Wizard */
