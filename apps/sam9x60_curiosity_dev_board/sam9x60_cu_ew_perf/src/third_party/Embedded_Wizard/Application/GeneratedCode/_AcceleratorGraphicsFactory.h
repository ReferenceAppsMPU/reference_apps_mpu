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
* Version  : 14.04
* Profile  : SAM9x60
* Platform : Microchip.SAM9.RGBA8888
*
*******************************************************************************/

#ifndef _AcceleratorGraphicsFactory_H
#define _AcceleratorGraphicsFactory_H

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

/* Forward declaration of the class Accelerator::GraphicsFactory */
#ifndef _AcceleratorGraphicsFactory_
  EW_DECLARE_CLASS( AcceleratorGraphicsFactory )
#define _AcceleratorGraphicsFactory_
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

/* Forward declaration of the class Core::View */
#ifndef _CoreView_
  EW_DECLARE_CLASS( CoreView )
#define _CoreView_
#endif

/* Forward declaration of the class Graphics::Canvas */
#ifndef _GraphicsCanvas_
  EW_DECLARE_CLASS( GraphicsCanvas )
#define _GraphicsCanvas_
#endif

/* Forward declaration of the class Resources::Bitmap */
#ifndef _ResourcesBitmap_
  EW_DECLARE_CLASS( ResourcesBitmap )
#define _ResourcesBitmap_
#endif


/* The class 'GraphicsFactory' implements a component that draws a couple of graphics 
   objects. */
EW_DEFINE_FIELDS( AcceleratorGraphicsFactory, CoreGroup )
  EW_ARRAY   ( NativeImages,    ResourcesBitmap, [7])
  EW_ARRAY   ( RGB565Images,    ResourcesBitmap, [5])
  EW_VARIABLE( EmWiLogo,        ResourcesBitmap )
  EW_ARRAY   ( Position,        XPoint, [64])
  EW_PROPERTY( NoOfItems,       XInt32 )
  EW_ARRAY   ( DeltaPos,        XPoint, [64])
  EW_ARRAY   ( Color,           XColor, [64])
  EW_PROPERTY( TypeOfItems,     XEnum )
  EW_ARRAY   ( Size,            XPoint, [64])
  EW_ARRAY   ( Type,            XEnum, [64])
  EW_ARRAY   ( DeltaAlpha,      XInt8, [64])
EW_END_OF_FIELDS( AcceleratorGraphicsFactory )

/* Virtual Method Table (VMT) for the class : 'Accelerator::GraphicsFactory' */
EW_DEFINE_METHODS( AcceleratorGraphicsFactory, CoreGroup )
  EW_METHOD( initLayoutContext, void )( CoreRectView _this, XRect aBounds, CoreOutline 
    aOutline )
  EW_METHOD( GetRoot,           CoreRoot )( CoreView _this )
  EW_METHOD( Draw,              void )( AcceleratorGraphicsFactory _this, GraphicsCanvas 
    aCanvas, XRect aClip, XPoint aOffset, XInt32 aOpacity, XBool aBlend )
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
  EW_METHOD( DispatchEvent,     XObject )( CoreGroup _this, CoreEvent aEvent )
  EW_METHOD( BroadcastEvent,    XObject )( CoreGroup _this, CoreEvent aEvent, XSet 
    aFilter )
  EW_METHOD( UpdateLayout,      void )( AcceleratorGraphicsFactory _this, XPoint 
    aSize )
  EW_METHOD( UpdateViewState,   void )( CoreGroup _this, XSet aState )
  EW_METHOD( InvalidateArea,    void )( CoreGroup _this, XRect aArea )
EW_END_OF_METHODS( AcceleratorGraphicsFactory )

/* 'C' function for method : 'Accelerator::GraphicsFactory.Draw()' */
void AcceleratorGraphicsFactory_Draw( AcceleratorGraphicsFactory _this, GraphicsCanvas 
  aCanvas, XRect aClip, XPoint aOffset, XInt32 aOpacity, XBool aBlend );

/* The method UpdateLayout() is invoked automatically after the size of the component 
   has been changed. This method can be overridden and filled with logic to perform 
   a sophisticated arrangement calculation for one or more enclosed views. In this 
   case the parameter aSize can be used. It contains the current size of the component. 
   Usually, all enclosed views are arranged automatically accordingly to their @Layout 
   property. UpdateLayout() gives the derived components a chance to extend this 
   automatism by a user defined algorithm. */
void AcceleratorGraphicsFactory_UpdateLayout( AcceleratorGraphicsFactory _this, 
  XPoint aSize );

/* 'C' function for method : 'Accelerator::GraphicsFactory.OnSetNoOfItems()' */
void AcceleratorGraphicsFactory_OnSetNoOfItems( AcceleratorGraphicsFactory _this, 
  XInt32 value );

/* Slot method to invalidate the entire component. This slot method should be triggered 
   only by using 'idelsignal' in order to ensure that the invalidation happens after 
   the next screen update. */
void AcceleratorGraphicsFactory_TriggerNextRedraw( AcceleratorGraphicsFactory _this, 
  XObject sender );

/* The method 'RandomizeItem' calculates random values for the graphics object with 
   the given index. */
void AcceleratorGraphicsFactory_RandomizeItem( AcceleratorGraphicsFactory _this, 
  XInt32 aIndex );

#ifdef __cplusplus
  }
#endif

#endif /* _AcceleratorGraphicsFactory_H */

/* Embedded Wizard */
