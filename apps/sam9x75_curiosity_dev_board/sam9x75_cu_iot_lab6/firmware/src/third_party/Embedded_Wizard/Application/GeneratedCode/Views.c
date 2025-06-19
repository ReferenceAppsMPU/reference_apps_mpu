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
#include "_CoreGroup.h"
#include "_CoreTimer.h"
#include "_EffectsEffectTimerClass.h"
#include "_GraphicsCanvas.h"
#include "_GraphicsWarpMatrix.h"
#include "_ResourcesBitmap.h"
#include "_ResourcesFont.h"
#include "_ResourcesFontSet.h"
#include "_ViewsBorder.h"
#include "_ViewsFrame.h"
#include "_ViewsImage.h"
#include "_ViewsRectangle.h"
#include "_ViewsStrokePath.h"
#include "_ViewsText.h"
#include "_ViewsWarpImage.h"
#include "_ViewsWarpView.h"
#include "Core.h"
#include "Effects.h"
#include "Graphics.h"
#include "Views.h"

/* Constant values used in this 'C' module only. */
static const XColor _Const0000 = { 0xFF, 0xFF, 0xFF, 0xFF };
static const XPoint _Const0001 = { 0, 0 };
static const XRect _Const0002 = {{ 0, 0 }, { 0, 0 }};

/* Initializer for the class 'Views::Rectangle' */
void ViewsRectangle__Init( ViewsRectangle _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreRectView__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( ViewsRectangle );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( ViewsRectangle );

  /* ... and initialize objects, variables, properties, etc. */
  _this->Color = _Const0000;
}

/* Re-Initializer for the class 'Views::Rectangle' */
void ViewsRectangle__ReInit( ViewsRectangle _this )
{
  /* At first re-initialize the super class ... */
  CoreRectView__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Views::Rectangle' */
void ViewsRectangle__Done( ViewsRectangle _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreRectView );

  /* Don't forget to deinitialize the super class ... */
  CoreRectView__Done( &_this->_.Super );
}

/* The method Draw() is invoked automatically if parts of the view should be redrawn 
   on the screen. This can occur when e.g. the view has been moved or the appearance 
   of the view has changed before.
   Draw() is invoked automatically by the framework, you will never need to invoke 
   this method directly. However you can request an invocation of this method by 
   calling the method InvalidateArea() of the views @Owner. Usually this is also 
   unnecessary unless you are developing your own view.
   The passed parameters determine the drawing destination aCanvas and the area 
   to redraw aClip in the coordinate space of the canvas. The parameter aOffset 
   contains the displacement between the origin of the views owner and the origin 
   of the canvas. You will need it to convert views coordinates into these of the 
   canvas.
   The parameter aOpacity contains the opacity descended from this view's @Owner. 
   It lies in range 0 .. 255. If the view implements its own 'Opacity', 'Color', 
   etc. properties, the Draw() method should calculate the resulting real opacity 
   by mixing the values of these properties with the one passed in aOpacity parameter.
   The parameter aBlend contains the blending mode descended from this view's @Owner. 
   It determines, whether the view should be drawn with alpha-blending active or 
   not. If aBlend is false, the outputs of the view should overwrite the corresponding 
   pixel in the drawing destination aCanvas. If aBlend is true, the outputs should 
   be mixed with the pixel already stored in aCanvas. For this purpose all Graphics 
   Engine functions provide a parameter to specify the mode for the respective drawing 
   operation. If the view implements its own 'Blend' property, the Draw() method 
   should calculate the resulting real blend mode by using logical AND operation 
   of the value of the property and the one passed in aBlend parameter. */
void ViewsRectangle_Draw( ViewsRectangle _this, GraphicsCanvas aCanvas, XRect aClip, 
  XPoint aOffset, XInt32 aOpacity, XBool aBlend )
{
  XColor ctl;
  XColor ctr;
  XColor cbl;
  XColor cbr;
  XColor c = _this->Color;
  XInt32 rtl = _this->Radius;
  XInt32 rtr = _this->Radius;
  XInt32 rbr = _this->Radius;
  XInt32 rbl = _this->Radius;

  aBlend = (XBool)( aBlend && (( _this->Super2.viewState & CoreViewStateAlphaBlended ) 
  == CoreViewStateAlphaBlended ));
  aOpacity = aOpacity + 1;
  ctl = ctr = cbl = cbr = c;

  if ( aOpacity < 256 )
  {
    ctl.Alpha = (XUInt8)(( aOpacity * ctl.Alpha ) >> 8 );
    ctr.Alpha = (XUInt8)(( aOpacity * ctr.Alpha ) >> 8 );
    cbl.Alpha = (XUInt8)(( aOpacity * cbl.Alpha ) >> 8 );
    cbr.Alpha = (XUInt8)(( aOpacity * cbr.Alpha ) >> 8 );
  }

  if ((( !!rtl || !!rtr ) || !!rbr ) || !!rbl )
    GraphicsCanvas_FillRoundedRectangle( aCanvas, aClip, EwMoveRectPos( _this->Super1.Bounds, 
    aOffset ), rtl, rtr, rbr, rbl, ctl, ctr, cbr, cbl, aBlend );
  else
    GraphicsCanvas_FillRectangle( aCanvas, aClip, EwMoveRectPos( _this->Super1.Bounds, 
    aOffset ), ctl, ctr, cbr, cbl, aBlend );
}

/* 'C' function for method : 'Views::Rectangle.OnSetRadius()' */
void ViewsRectangle_OnSetRadius( ViewsRectangle _this, XInt32 value )
{
  if ( value < 0 )
    value = 0;

  if ( value == _this->Radius )
    return;

  _this->Radius = value;

  if (( _this->Super2.Owner != 0 ) && (( _this->Super2.viewState & CoreViewStateVisible ) 
      == CoreViewStateVisible ))
    CoreGroup__InvalidateArea( _this->Super2.Owner, _this->Super1.Bounds );
}

/* 'C' function for method : 'Views::Rectangle.OnSetColor()' */
void ViewsRectangle_OnSetColor( ViewsRectangle _this, XColor value )
{
  if ( !EwCompColor( value, _this->Color ))
    return;

  _this->Color = value;

  if (( _this->Super2.Owner != 0 ) && (( _this->Super2.viewState & CoreViewStateVisible ) 
      == CoreViewStateVisible ))
    CoreGroup__InvalidateArea( _this->Super2.Owner, _this->Super1.Bounds );
}

/* 'C' function for method : 'Views::Rectangle.OnSetEmbedded()' */
void ViewsRectangle_OnSetEmbedded( ViewsRectangle _this, XBool value )
{
  if ( value )
    CoreView__ChangeViewState( _this, CoreViewStateEmbedded, 0 );
  else
    CoreView__ChangeViewState( _this, 0, CoreViewStateEmbedded );
}

/* 'C' function for method : 'Views::Rectangle.OnGetVisible()' */
XBool ViewsRectangle_OnGetVisible( ViewsRectangle _this )
{
  return (( _this->Super2.viewState & CoreViewStateVisible ) == CoreViewStateVisible );
}

/* 'C' function for method : 'Views::Rectangle.OnSetVisible()' */
void ViewsRectangle_OnSetVisible( ViewsRectangle _this, XBool value )
{
  if ( value )
    CoreView__ChangeViewState( _this, CoreViewStateVisible, 0 );
  else
    CoreView__ChangeViewState( _this, 0, CoreViewStateVisible );
}

/* Variants derived from the class : 'Views::Rectangle' */
EW_DEFINE_CLASS_VARIANTS( ViewsRectangle )
EW_END_OF_CLASS_VARIANTS( ViewsRectangle )

/* Virtual Method Table (VMT) for the class : 'Views::Rectangle' */
EW_DEFINE_CLASS( ViewsRectangle, CoreRectView, _.VMT, _.VMT, _.VMT, _.VMT, _.VMT, 
                 _.VMT, "Views::Rectangle" )
  CoreRectView_initLayoutContext,
  CoreView_GetRoot,
  ViewsRectangle_Draw,
  CoreView_GetClipping,
  CoreView_HandleEvent,
  CoreView_CursorHitTest,
  CoreView_AdjustDrawingArea,
  CoreRectView_ArrangeView,
  CoreRectView_MoveView,
  CoreRectView_GetExtent,
  CoreView_ChangeViewState,
  CoreRectView_OnSetBounds,
EW_END_OF_CLASS( ViewsRectangle )

/* Initializer for the class 'Views::Border' */
void ViewsBorder__Init( ViewsBorder _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreRectView__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( ViewsBorder );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( ViewsBorder );

  /* ... and initialize objects, variables, properties, etc. */
  _this->Width = 1;
  _this->Color = _Const0000;
}

/* Re-Initializer for the class 'Views::Border' */
void ViewsBorder__ReInit( ViewsBorder _this )
{
  /* At first re-initialize the super class ... */
  CoreRectView__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Views::Border' */
void ViewsBorder__Done( ViewsBorder _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreRectView );

  /* Don't forget to deinitialize the super class ... */
  CoreRectView__Done( &_this->_.Super );
}

/* The method Draw() is invoked automatically if parts of the view should be redrawn 
   on the screen. This can occur when e.g. the view has been moved or the appearance 
   of the view has changed before.
   Draw() is invoked automatically by the framework, you will never need to invoke 
   this method directly. However you can request an invocation of this method by 
   calling the method InvalidateArea() of the views @Owner. Usually this is also 
   unnecessary unless you are developing your own view.
   The passed parameters determine the drawing destination aCanvas and the area 
   to redraw aClip in the coordinate space of the canvas. The parameter aOffset 
   contains the displacement between the origin of the views owner and the origin 
   of the canvas. You will need it to convert views coordinates into these of the 
   canvas.
   The parameter aOpacity contains the opacity descended from this view's @Owner. 
   It lies in range 0 .. 255. If the view implements its own 'Opacity', 'Color', 
   etc. properties, the Draw() method should calculate the resulting real opacity 
   by mixing the values of these properties with the one passed in aOpacity parameter.
   The parameter aBlend contains the blending mode descended from this view's @Owner. 
   It determines, whether the view should be drawn with alpha-blending active or 
   not. If aBlend is false, the outputs of the view should overwrite the corresponding 
   pixel in the drawing destination aCanvas. If aBlend is true, the outputs should 
   be mixed with the pixel already stored in aCanvas. For this purpose all Graphics 
   Engine functions provide a parameter to specify the mode for the respective drawing 
   operation. If the view implements its own 'Blend' property, the Draw() method 
   should calculate the resulting real blend mode by using logical AND operation 
   of the value of the property and the one passed in aBlend parameter. */
void ViewsBorder_Draw( ViewsBorder _this, GraphicsCanvas aCanvas, XRect aClip, XPoint 
  aOffset, XInt32 aOpacity, XBool aBlend )
{
  XColor ctl;
  XColor ctr;
  XColor cbl;
  XColor cbr;
  XColor c = _this->Color;
  XInt32 rtl = _this->Radius;
  XInt32 rtr = _this->Radius;
  XInt32 rbr = _this->Radius;
  XInt32 rbl = _this->Radius;

  aBlend = (XBool)( aBlend && (( _this->Super2.viewState & CoreViewStateAlphaBlended ) 
  == CoreViewStateAlphaBlended ));
  aOpacity = aOpacity + 1;
  ctl = ctr = cbl = cbr = c;

  if ( aOpacity < 256 )
  {
    ctl.Alpha = (XUInt8)(( aOpacity * ctl.Alpha ) >> 8 );
    ctr.Alpha = (XUInt8)(( aOpacity * ctr.Alpha ) >> 8 );
    cbl.Alpha = (XUInt8)(( aOpacity * cbl.Alpha ) >> 8 );
    cbr.Alpha = (XUInt8)(( aOpacity * cbr.Alpha ) >> 8 );
  }

  if ((( !!rtl || !!rtr ) || !!rbr ) || !!rbl )
    GraphicsCanvas_DrawRoundedBorder( aCanvas, aClip, EwMoveRectPos( _this->Super1.Bounds, 
    aOffset ), _this->Width, rtl, rtr, rbr, rbl, ctl, ctr, cbr, cbl, aBlend );
  else
    GraphicsCanvas_DrawBorder( aCanvas, aClip, EwMoveRectPos( _this->Super1.Bounds, 
    aOffset ), _this->Width, ctl, ctr, cbr, cbl, aBlend );
}

/* 'C' function for method : 'Views::Border.OnSetRadius()' */
void ViewsBorder_OnSetRadius( ViewsBorder _this, XInt32 value )
{
  if ( value < 0 )
    value = 0;

  if ( value == _this->Radius )
    return;

  _this->Radius = value;

  if (( _this->Super2.Owner != 0 ) && (( _this->Super2.viewState & CoreViewStateVisible ) 
      == CoreViewStateVisible ))
    CoreGroup__InvalidateArea( _this->Super2.Owner, _this->Super1.Bounds );
}

/* 'C' function for method : 'Views::Border.OnSetWidth()' */
void ViewsBorder_OnSetWidth( ViewsBorder _this, XInt32 value )
{
  if ( value < 0 )
    value = 0;

  if ( value == _this->Width )
    return;

  _this->Width = value;

  if (( _this->Super2.Owner != 0 ) && (( _this->Super2.viewState & CoreViewStateVisible ) 
      == CoreViewStateVisible ))
    CoreGroup__InvalidateArea( _this->Super2.Owner, _this->Super1.Bounds );
}

/* 'C' function for method : 'Views::Border.OnSetColor()' */
void ViewsBorder_OnSetColor( ViewsBorder _this, XColor value )
{
  if ( !EwCompColor( value, _this->Color ))
    return;

  _this->Color = value;

  if (( _this->Super2.Owner != 0 ) && (( _this->Super2.viewState & CoreViewStateVisible ) 
      == CoreViewStateVisible ))
    CoreGroup__InvalidateArea( _this->Super2.Owner, _this->Super1.Bounds );
}

/* 'C' function for method : 'Views::Border.OnSetEmbedded()' */
void ViewsBorder_OnSetEmbedded( ViewsBorder _this, XBool value )
{
  if ( value )
    CoreView__ChangeViewState( _this, CoreViewStateEmbedded, 0 );
  else
    CoreView__ChangeViewState( _this, 0, CoreViewStateEmbedded );
}

/* Variants derived from the class : 'Views::Border' */
EW_DEFINE_CLASS_VARIANTS( ViewsBorder )
EW_END_OF_CLASS_VARIANTS( ViewsBorder )

/* Virtual Method Table (VMT) for the class : 'Views::Border' */
EW_DEFINE_CLASS( ViewsBorder, CoreRectView, _.VMT, _.VMT, _.VMT, _.VMT, _.VMT, _.VMT, 
                 "Views::Border" )
  CoreRectView_initLayoutContext,
  CoreView_GetRoot,
  ViewsBorder_Draw,
  CoreView_GetClipping,
  CoreView_HandleEvent,
  CoreView_CursorHitTest,
  CoreView_AdjustDrawingArea,
  CoreRectView_ArrangeView,
  CoreRectView_MoveView,
  CoreRectView_GetExtent,
  CoreView_ChangeViewState,
  CoreRectView_OnSetBounds,
EW_END_OF_CLASS( ViewsBorder )

/* Initializer for the class 'Views::Frame' */
void ViewsFrame__Init( ViewsFrame _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreRectView__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( ViewsFrame );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( ViewsFrame );

  /* ... and initialize objects, variables, properties, etc. */
  _this->animFrameNumber = -1;
  _this->Color = _Const0000;
  _this->Edges = GraphicsEdgesBottom | GraphicsEdgesInterior | GraphicsEdgesLeft 
  | GraphicsEdgesRight | GraphicsEdgesTop;
}

/* Re-Initializer for the class 'Views::Frame' */
void ViewsFrame__ReInit( ViewsFrame _this )
{
  /* At first re-initialize the super class ... */
  CoreRectView__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Views::Frame' */
void ViewsFrame__Done( ViewsFrame _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreRectView );

  /* Don't forget to deinitialize the super class ... */
  CoreRectView__Done( &_this->_.Super );
}

/* The method Draw() is invoked automatically if parts of the view should be redrawn 
   on the screen. This can occur when e.g. the view has been moved or the appearance 
   of the view has changed before.
   Draw() is invoked automatically by the framework, you will never need to invoke 
   this method directly. However you can request an invocation of this method by 
   calling the method InvalidateArea() of the views @Owner. Usually this is also 
   unnecessary unless you are developing your own view.
   The passed parameters determine the drawing destination aCanvas and the area 
   to redraw aClip in the coordinate space of the canvas. The parameter aOffset 
   contains the displacement between the origin of the views owner and the origin 
   of the canvas. You will need it to convert views coordinates into these of the 
   canvas.
   The parameter aOpacity contains the opacity descended from this view's @Owner. 
   It lies in range 0 .. 255. If the view implements its own 'Opacity', 'Color', 
   etc. properties, the Draw() method should calculate the resulting real opacity 
   by mixing the values of these properties with the one passed in aOpacity parameter.
   The parameter aBlend contains the blending mode descended from this view's @Owner. 
   It determines, whether the view should be drawn with alpha-blending active or 
   not. If aBlend is false, the outputs of the view should overwrite the corresponding 
   pixel in the drawing destination aCanvas. If aBlend is true, the outputs should 
   be mixed with the pixel already stored in aCanvas. For this purpose all Graphics 
   Engine functions provide a parameter to specify the mode for the respective drawing 
   operation. If the view implements its own 'Blend' property, the Draw() method 
   should calculate the resulting real blend mode by using logical AND operation 
   of the value of the property and the one passed in aBlend parameter. */
void ViewsFrame_Draw( ViewsFrame _this, GraphicsCanvas aCanvas, XRect aClip, XPoint 
  aOffset, XInt32 aOpacity, XBool aBlend )
{
  XInt32 frameNr = _this->FrameNumber;
  XColor ctl;
  XColor ctr;
  XColor cbr;
  XColor cbl;
  XColor c;
  XInt32 opacity;
  XSet edges;
  XRect r;
  XPoint sd;

  if ( _this->animFrameNumber >= 0 )
    frameNr = _this->animFrameNumber;

  if (( _this->Bitmap == 0 ) || ( frameNr >= _this->Bitmap->NoOfFrames ))
    return;

  ResourcesBitmap__Update( _this->Bitmap );
  c = _this->Color;
  opacity = ((( aOpacity + 1 ) * 255 ) >> 8 ) + 1;
  edges = _this->Edges;
  r = EwMoveRectPos( _this->Super1.Bounds, aOffset );
  sd = EwMovePointNeg( EwGetRectSize( r ), _this->NoEdgesLimit );
  aBlend = (XBool)( aBlend && (( _this->Super2.viewState & CoreViewStateAlphaBlended ) 
  == CoreViewStateAlphaBlended ));
  ctl = ctr = cbl = cbr = c;

  if ( opacity < 256 )
  {
    ctl.Alpha = (XUInt8)(( ctl.Alpha * opacity ) >> 8 );
    ctr.Alpha = (XUInt8)(( ctr.Alpha * opacity ) >> 8 );
    cbr.Alpha = (XUInt8)(( cbr.Alpha * opacity ) >> 8 );
    cbl.Alpha = (XUInt8)(( cbl.Alpha * opacity ) >> 8 );
  }

  if ((( _this->NoEdgesLimit.X > 0 ) && ( sd.X > 0 )) && !(( edges & ( GraphicsEdgesLeft 
      | GraphicsEdgesRight )) == ( GraphicsEdgesLeft | GraphicsEdgesRight )))
  {
    XInt32 d = ( _this->Bitmap->FrameSize.X / 3 ) - sd.X;

    if ((( edges & GraphicsEdgesLeft ) == GraphicsEdgesLeft ))
    {
      if ( aClip.Point2.X > r.Point2.X )
        aClip.Point2.X = r.Point2.X;

      if ( d > 0 )
        r.Point2.X = ( r.Point2.X + d );

      edges = edges | GraphicsEdgesRight;
    }
    else
      if ((( edges & GraphicsEdgesRight ) == GraphicsEdgesRight ))
      {
        if ( aClip.Point1.X < r.Point1.X )
          aClip.Point1.X = r.Point1.X;

        if ( d > 0 )
          r.Point1.X = ( r.Point1.X - d );

        edges = edges | GraphicsEdgesLeft;
      }
      else
      {
        if ( aClip.Point1.X < r.Point1.X )
          aClip.Point1.X = r.Point1.X;

        if ( aClip.Point2.X > r.Point2.X )
          aClip.Point2.X = r.Point2.X;

        if ( d > 0 )
        {
          r.Point1.X = ( r.Point1.X - ( d / 2 ));
          r.Point2.X = (( r.Point2.X + d ) - ( d / 2 ));
        }

        edges = edges | ( GraphicsEdgesLeft | GraphicsEdgesRight );
      }
  }

  if ((( _this->NoEdgesLimit.Y > 0 ) && ( sd.Y > 0 )) && !(( edges & ( GraphicsEdgesBottom 
      | GraphicsEdgesTop )) == ( GraphicsEdgesBottom | GraphicsEdgesTop )))
  {
    XInt32 d = ( _this->Bitmap->FrameSize.Y / 3 ) - sd.Y;

    if ((( edges & GraphicsEdgesTop ) == GraphicsEdgesTop ))
    {
      if ( aClip.Point2.Y > r.Point2.Y )
        aClip.Point2.Y = r.Point2.Y;

      if ( d > 0 )
        r.Point2.Y = ( r.Point2.Y + d );

      edges = edges | GraphicsEdgesBottom;
    }
    else
      if ((( edges & GraphicsEdgesBottom ) == GraphicsEdgesBottom ))
      {
        if ( aClip.Point1.Y < r.Point1.Y )
          aClip.Point1.Y = r.Point1.Y;

        if ( d > 0 )
          r.Point1.Y = ( r.Point1.Y - d );

        edges = edges | GraphicsEdgesTop;
      }
      else
      {
        if ( aClip.Point1.Y < r.Point1.Y )
          aClip.Point1.Y = r.Point1.Y;

        if ( aClip.Point2.Y > r.Point2.Y )
          aClip.Point2.Y = r.Point2.Y;

        if ( d > 0 )
        {
          r.Point1.Y = ( r.Point1.Y - ( d / 2 ));
          r.Point2.Y = (( r.Point2.Y + d ) - ( d / 2 ));
        }

        edges = edges | ( GraphicsEdgesBottom | GraphicsEdgesTop );
      }
  }

  GraphicsCanvas_DrawBitmapFrame( aCanvas, aClip, _this->Bitmap, frameNr, r, edges, 
  ctl, ctr, cbr, cbl, aBlend );
}

/* 'C' function for method : 'Views::Frame.observerSlot()' */
void ViewsFrame_observerSlot( ViewsFrame _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if (( _this->Super2.Owner != 0 ) && (( _this->Super2.viewState & CoreViewStateVisible ) 
      == CoreViewStateVisible ))
    CoreGroup__InvalidateArea( _this->Super2.Owner, _this->Super1.Bounds );
}

/* 'C' function for method : 'Views::Frame.timerSlot()' */
void ViewsFrame_timerSlot( ViewsFrame _this, XObject sender )
{
  XInt32 frameNr;
  XInt32 period;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  frameNr = _this->animFrameNumber;
  period = 0;

  if ( _this->Bitmap != 0 )
    period = _this->Bitmap->NoOfFrames * _this->Bitmap->FrameDelay;

  if ((( _this->timer != 0 ) && ( _this->animFrameNumber < 0 )) && ( period > 0 ))
    _this->startTime = _this->timer->Time - ( _this->FrameNumber * _this->Bitmap->FrameDelay );

  if (( _this->timer != 0 ) && ( period > 0 ))
  {
    XInt32 time = (XInt32)( _this->timer->Time - _this->startTime );
    frameNr = time / _this->Bitmap->FrameDelay;

    if ( time >= period )
    {
      frameNr = frameNr % _this->Bitmap->NoOfFrames;
      _this->startTime = _this->timer->Time - ( time % period );
    }
  }

  if ((( frameNr != _this->animFrameNumber ) && ( _this->Super2.Owner != 0 )) && 
      (( _this->Super2.viewState & CoreViewStateVisible ) == CoreViewStateVisible ))
    CoreGroup__InvalidateArea( _this->Super2.Owner, _this->Super1.Bounds );

  _this->animFrameNumber = frameNr;

  if (( period == 0 ) && ( _this->timer != 0 ))
  {
    EwDetachObjObserver( EwNewSlot( _this, ViewsFrame_timerSlot ), (XObject)_this->timer, 
      0 );
    _this->timer = 0;
  }
}

/* 'C' function for method : 'Views::Frame.OnSetColor()' */
void ViewsFrame_OnSetColor( ViewsFrame _this, XColor value )
{
  if ( !EwCompColor( value, _this->Color ))
    return;

  _this->Color = value;

  if (( _this->Super2.Owner != 0 ) && (( _this->Super2.viewState & CoreViewStateVisible ) 
      == CoreViewStateVisible ))
    CoreGroup__InvalidateArea( _this->Super2.Owner, _this->Super1.Bounds );
}

/* 'C' function for method : 'Views::Frame.OnSetAnimated()' */
void ViewsFrame_OnSetAnimated( ViewsFrame _this, XBool value )
{
  if ( _this->Animated == value )
    return;

  _this->Animated = value;
  _this->animFrameNumber = -1;

  if ( !value && ( _this->timer != 0 ))
  {
    EwDetachObjObserver( EwNewSlot( _this, ViewsFrame_timerSlot ), (XObject)_this->timer, 
      0 );
    _this->timer = 0;
  }

  if ( value )
  {
    _this->timer = ((CoreTimer)EwGetAutoObject( &EffectsEffectTimer, EffectsEffectTimerClass ));
    EwAttachObjObserver( EwNewSlot( _this, ViewsFrame_timerSlot ), (XObject)_this->timer, 
      0 );
    EwPostSignal( EwNewSlot( _this, ViewsFrame_timerSlot ), ((XObject)_this ));
  }

  if (( _this->Super2.Owner != 0 ) && (( _this->Super2.viewState & CoreViewStateVisible ) 
      == CoreViewStateVisible ))
    CoreGroup__InvalidateArea( _this->Super2.Owner, _this->Super1.Bounds );
}

/* 'C' function for method : 'Views::Frame.OnSetEdges()' */
void ViewsFrame_OnSetEdges( ViewsFrame _this, XSet value )
{
  if ( value == _this->Edges )
    return;

  _this->Edges = value;

  if (( _this->Super2.Owner != 0 ) && (( _this->Super2.viewState & CoreViewStateVisible ) 
      == CoreViewStateVisible ))
    CoreGroup__InvalidateArea( _this->Super2.Owner, _this->Super1.Bounds );
}

/* 'C' function for method : 'Views::Frame.OnSetFrameNumber()' */
void ViewsFrame_OnSetFrameNumber( ViewsFrame _this, XInt32 value )
{
  if ( value < 0 )
    value = 0;

  if (( value == _this->FrameNumber ) && ( _this->animFrameNumber == -1 ))
    return;

  _this->FrameNumber = value;

  if ( _this->timer == 0 )
    _this->animFrameNumber = -1;

  if (( _this->Super2.Owner != 0 ) && (( _this->Super2.viewState & CoreViewStateVisible ) 
      == CoreViewStateVisible ))
    CoreGroup__InvalidateArea( _this->Super2.Owner, _this->Super1.Bounds );
}

/* 'C' function for method : 'Views::Frame.OnSetBitmap()' */
void ViewsFrame_OnSetBitmap( ViewsFrame _this, ResourcesBitmap value )
{
  if ( value == _this->Bitmap )
    return;

  if (( _this->Bitmap != 0 ) && _this->Bitmap->Mutable )
    EwDetachObjObserver( EwNewSlot( _this, ViewsFrame_observerSlot ), (XObject)_this->Bitmap, 
      0 );

  _this->Bitmap = value;
  _this->animFrameNumber = -1;

  if (( value != 0 ) && value->Mutable )
    EwAttachObjObserver( EwNewSlot( _this, ViewsFrame_observerSlot ), (XObject)value, 
      0 );

  if ( _this->Animated )
  {
    ViewsFrame_OnSetAnimated( _this, 0 );
    ViewsFrame_OnSetAnimated( _this, 1 );
  }

  if (( _this->Super2.Owner != 0 ) && (( _this->Super2.viewState & CoreViewStateVisible ) 
      == CoreViewStateVisible ))
    CoreGroup__InvalidateArea( _this->Super2.Owner, _this->Super1.Bounds );
}

/* 'C' function for method : 'Views::Frame.OnSetVisible()' */
void ViewsFrame_OnSetVisible( ViewsFrame _this, XBool value )
{
  if ( value )
    CoreView__ChangeViewState( _this, CoreViewStateVisible, 0 );
  else
    CoreView__ChangeViewState( _this, 0, CoreViewStateVisible );
}

/* 'C' function for method : 'Views::Frame.OnSetNoEdgesLimit()' */
void ViewsFrame_OnSetNoEdgesLimit( ViewsFrame _this, XPoint value )
{
  if ( value.X < 0 )
    value.X = 0;

  if ( value.Y < 0 )
    value.Y = 0;

  if ( !EwCompPoint( value, _this->NoEdgesLimit ))
    return;

  _this->NoEdgesLimit = value;

  if ((( _this->Super2.Owner != 0 ) && (( _this->Super2.viewState & CoreViewStateVisible ) 
      == CoreViewStateVisible )) && !(( _this->Edges & ( GraphicsEdgesBottom | GraphicsEdgesLeft 
      | GraphicsEdgesRight | GraphicsEdgesTop )) == ( GraphicsEdgesBottom | GraphicsEdgesLeft 
      | GraphicsEdgesRight | GraphicsEdgesTop )))
    CoreGroup__InvalidateArea( _this->Super2.Owner, _this->Super1.Bounds );
}

/* Variants derived from the class : 'Views::Frame' */
EW_DEFINE_CLASS_VARIANTS( ViewsFrame )
EW_END_OF_CLASS_VARIANTS( ViewsFrame )

/* Virtual Method Table (VMT) for the class : 'Views::Frame' */
EW_DEFINE_CLASS( ViewsFrame, CoreRectView, timer, timer, animFrameNumber, animFrameNumber, 
                 animFrameNumber, animFrameNumber, "Views::Frame" )
  CoreRectView_initLayoutContext,
  CoreView_GetRoot,
  ViewsFrame_Draw,
  CoreView_GetClipping,
  CoreView_HandleEvent,
  CoreView_CursorHitTest,
  CoreView_AdjustDrawingArea,
  CoreRectView_ArrangeView,
  CoreRectView_MoveView,
  CoreRectView_GetExtent,
  CoreView_ChangeViewState,
  CoreRectView_OnSetBounds,
EW_END_OF_CLASS( ViewsFrame )

/* Initializer for the class 'Views::Image' */
void ViewsImage__Init( ViewsImage _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreRectView__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( ViewsImage );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( ViewsImage );

  /* ... and initialize objects, variables, properties, etc. */
  _this->Color = _Const0000;
  _this->Opacity = 255;
}

/* Re-Initializer for the class 'Views::Image' */
void ViewsImage__ReInit( ViewsImage _this )
{
  /* At first re-initialize the super class ... */
  CoreRectView__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Views::Image' */
void ViewsImage__Done( ViewsImage _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreRectView );

  /* Don't forget to deinitialize the super class ... */
  CoreRectView__Done( &_this->_.Super );
}

/* The method Draw() is invoked automatically if parts of the view should be redrawn 
   on the screen. This can occur when e.g. the view has been moved or the appearance 
   of the view has changed before.
   Draw() is invoked automatically by the framework, you will never need to invoke 
   this method directly. However you can request an invocation of this method by 
   calling the method InvalidateArea() of the views @Owner. Usually this is also 
   unnecessary unless you are developing your own view.
   The passed parameters determine the drawing destination aCanvas and the area 
   to redraw aClip in the coordinate space of the canvas. The parameter aOffset 
   contains the displacement between the origin of the views owner and the origin 
   of the canvas. You will need it to convert views coordinates into these of the 
   canvas.
   The parameter aOpacity contains the opacity descended from this view's @Owner. 
   It lies in range 0 .. 255. If the view implements its own 'Opacity', 'Color', 
   etc. properties, the Draw() method should calculate the resulting real opacity 
   by mixing the values of these properties with the one passed in aOpacity parameter.
   The parameter aBlend contains the blending mode descended from this view's @Owner. 
   It determines, whether the view should be drawn with alpha-blending active or 
   not. If aBlend is false, the outputs of the view should overwrite the corresponding 
   pixel in the drawing destination aCanvas. If aBlend is true, the outputs should 
   be mixed with the pixel already stored in aCanvas. For this purpose all Graphics 
   Engine functions provide a parameter to specify the mode for the respective drawing 
   operation. If the view implements its own 'Blend' property, the Draw() method 
   should calculate the resulting real blend mode by using logical AND operation 
   of the value of the property and the one passed in aBlend parameter. */
void ViewsImage_Draw( ViewsImage _this, GraphicsCanvas aCanvas, XRect aClip, XPoint 
  aOffset, XInt32 aOpacity, XBool aBlend )
{
  XInt32 frameNr = _this->FrameNumber;
  XRect area;
  XPoint size;
  XColor ctl;
  XColor ctr;
  XColor cbr;
  XColor cbl;
  XColor c;
  XInt32 opacity;

  if ( _this->animFrameNumber >= 0 )
    frameNr = _this->animFrameNumber;

  if (( _this->Bitmap == 0 ) || ( frameNr >= _this->Bitmap->NoOfFrames ))
    return;

  ResourcesBitmap__Update( _this->Bitmap );
  area = ViewsImage_GetContentArea( _this );
  size = _this->Bitmap->FrameSize;

  if ( EwIsRectEmpty( area ))
    return;

  c = _this->Color;
  opacity = ((( aOpacity + 1 ) * _this->Opacity ) >> 8 ) + 1;
  aBlend = (XBool)( aBlend && (( _this->Super2.viewState & CoreViewStateAlphaBlended ) 
  == CoreViewStateAlphaBlended ));
  ctl = ctr = cbl = cbr = c;

  if ( opacity < 256 )
  {
    ctl.Alpha = (XUInt8)(( ctl.Alpha * opacity ) >> 8 );
    ctr.Alpha = (XUInt8)(( ctr.Alpha * opacity ) >> 8 );
    cbr.Alpha = (XUInt8)(( cbr.Alpha * opacity ) >> 8 );
    cbl.Alpha = (XUInt8)(( cbl.Alpha * opacity ) >> 8 );
  }

  if ( !EwCompPoint( EwGetRectSize( area ), size ))
    GraphicsCanvas_CopyBitmap( aCanvas, aClip, _this->Bitmap, frameNr, EwMoveRectPos( 
    _this->Super1.Bounds, aOffset ), EwMovePointNeg( _this->Super1.Bounds.Point1, 
    area.Point1 ), ctl, ctr, cbr, cbl, aBlend );
  else
    GraphicsCanvas_ScaleBitmap( aCanvas, aClip, _this->Bitmap, frameNr, EwMoveRectPos( 
    area, aOffset ), EwNewRect2Point( _Const0001, size ), ctl, ctr, cbr, cbl, aBlend, 
    1 );
}

/* 'C' function for method : 'Views::Image.observerSlot()' */
void ViewsImage_observerSlot( ViewsImage _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if (( _this->Super2.Owner != 0 ) && (( _this->Super2.viewState & CoreViewStateVisible ) 
      == CoreViewStateVisible ))
    CoreGroup__InvalidateArea( _this->Super2.Owner, _this->Super1.Bounds );
}

/* 'C' function for method : 'Views::Image.timerSlot()' */
void ViewsImage_timerSlot( ViewsImage _this, XObject sender )
{
  XInt32 frameNr;
  XInt32 period;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  frameNr = _this->animFrameNumber;
  period = 0;

  if ( _this->Bitmap != 0 )
    period = _this->Bitmap->NoOfFrames * _this->Bitmap->FrameDelay;

  if ((( _this->timer != 0 ) && ( _this->animFrameNumber < 0 )) && ( period > 0 ))
    _this->startTime = _this->timer->Time - ( _this->FrameNumber * _this->Bitmap->FrameDelay );

  if (( _this->timer != 0 ) && ( period > 0 ))
  {
    XInt32 time = (XInt32)( _this->timer->Time - _this->startTime );
    frameNr = time / _this->Bitmap->FrameDelay;

    if ( time >= period )
    {
      frameNr = frameNr % _this->Bitmap->NoOfFrames;
      _this->startTime = _this->timer->Time - ( time % period );
    }
  }

  if ((( frameNr != _this->animFrameNumber ) && ( _this->Super2.Owner != 0 )) && 
      (( _this->Super2.viewState & CoreViewStateVisible ) == CoreViewStateVisible ))
    CoreGroup__InvalidateArea( _this->Super2.Owner, _this->Super1.Bounds );

  _this->animFrameNumber = frameNr;

  if (( period == 0 ) && ( _this->timer != 0 ))
  {
    EwDetachObjObserver( EwNewSlot( _this, ViewsImage_timerSlot ), (XObject)_this->timer, 
      0 );
    _this->timer = 0;
  }
}

/* 'C' function for method : 'Views::Image.OnSetColor()' */
void ViewsImage_OnSetColor( ViewsImage _this, XColor value )
{
  if ( !EwCompColor( value, _this->Color ))
    return;

  _this->Color = value;

  if (( _this->Super2.Owner != 0 ) && (( _this->Super2.viewState & CoreViewStateVisible ) 
      == CoreViewStateVisible ))
    CoreGroup__InvalidateArea( _this->Super2.Owner, _this->Super1.Bounds );
}

/* 'C' function for method : 'Views::Image.OnSetAnimated()' */
void ViewsImage_OnSetAnimated( ViewsImage _this, XBool value )
{
  if ( _this->Animated == value )
    return;

  _this->Animated = value;
  _this->animFrameNumber = -1;

  if ( !value && ( _this->timer != 0 ))
  {
    EwDetachObjObserver( EwNewSlot( _this, ViewsImage_timerSlot ), (XObject)_this->timer, 
      0 );
    _this->timer = 0;
  }

  if ( value )
  {
    _this->timer = ((CoreTimer)EwGetAutoObject( &EffectsEffectTimer, EffectsEffectTimerClass ));
    EwAttachObjObserver( EwNewSlot( _this, ViewsImage_timerSlot ), (XObject)_this->timer, 
      0 );
    EwPostSignal( EwNewSlot( _this, ViewsImage_timerSlot ), ((XObject)_this ));
  }

  if (( _this->Super2.Owner != 0 ) && (( _this->Super2.viewState & CoreViewStateVisible ) 
      == CoreViewStateVisible ))
    CoreGroup__InvalidateArea( _this->Super2.Owner, _this->Super1.Bounds );
}

/* 'C' function for method : 'Views::Image.OnSetFrameNumber()' */
void ViewsImage_OnSetFrameNumber( ViewsImage _this, XInt32 value )
{
  if ( value < 0 )
    value = 0;

  if (( value == _this->FrameNumber ) && ( _this->animFrameNumber == -1 ))
    return;

  _this->FrameNumber = value;

  if ( _this->timer == 0 )
    _this->animFrameNumber = -1;

  if (( _this->Super2.Owner != 0 ) && (( _this->Super2.viewState & CoreViewStateVisible ) 
      == CoreViewStateVisible ))
    CoreGroup__InvalidateArea( _this->Super2.Owner, _this->Super1.Bounds );
}

/* 'C' function for method : 'Views::Image.OnSetBitmap()' */
void ViewsImage_OnSetBitmap( ViewsImage _this, ResourcesBitmap value )
{
  if ( value == _this->Bitmap )
    return;

  if (( _this->Bitmap != 0 ) && _this->Bitmap->Mutable )
    EwDetachObjObserver( EwNewSlot( _this, ViewsImage_observerSlot ), (XObject)_this->Bitmap, 
      0 );

  _this->Bitmap = value;
  _this->animFrameNumber = -1;

  if (( value != 0 ) && value->Mutable )
    EwAttachObjObserver( EwNewSlot( _this, ViewsImage_observerSlot ), (XObject)value, 
      0 );

  if ( _this->Animated )
  {
    ViewsImage_OnSetAnimated( _this, 0 );
    ViewsImage_OnSetAnimated( _this, 1 );
  }

  if (( _this->Super2.Owner != 0 ) && (( _this->Super2.viewState & CoreViewStateVisible ) 
      == CoreViewStateVisible ))
    CoreGroup__InvalidateArea( _this->Super2.Owner, _this->Super1.Bounds );
}

/* 'C' function for method : 'Views::Image.OnSetOpacity()' */
void ViewsImage_OnSetOpacity( ViewsImage _this, XInt32 value )
{
  if ( value > 255 )
    value = 255;

  if ( value < 0 )
    value = 0;

  if ( value == _this->Opacity )
    return;

  _this->Opacity = value;

  if (( _this->Super2.Owner != 0 ) && (( _this->Super2.viewState & CoreViewStateVisible ) 
      == CoreViewStateVisible ))
    CoreGroup__InvalidateArea( _this->Super2.Owner, _this->Super1.Bounds );
}

/* 'C' function for method : 'Views::Image.OnGetVisible()' */
XBool ViewsImage_OnGetVisible( ViewsImage _this )
{
  return (( _this->Super2.viewState & CoreViewStateVisible ) == CoreViewStateVisible );
}

/* 'C' function for method : 'Views::Image.OnSetVisible()' */
void ViewsImage_OnSetVisible( ViewsImage _this, XBool value )
{
  if ( value )
    CoreView__ChangeViewState( _this, CoreViewStateVisible, 0 );
  else
    CoreView__ChangeViewState( _this, 0, CoreViewStateVisible );
}

/* The method GetContentArea() returns the position and the size of an area where 
   the view will show the bitmap. This area is expressed in coordinates relative 
   to the top-left corner of the view's @Owner. The method takes in account all 
   properties which do affect the position and the alignment of the bitmap, e.g. 
   @Alignment or @ScrollOffset. */
XRect ViewsImage_GetContentArea( ViewsImage _this )
{
  XPoint size;
  XRect bounds;
  XInt32 width;
  XInt32 height;
  XRect rd;
  XRect rs;

  if ( _this->Bitmap == 0 )
    return _Const0002;

  size = _this->Bitmap->FrameSize;
  bounds = _this->Super1.Bounds;
  width = EwGetRectW( bounds );
  height = EwGetRectH( bounds );

  if (( size.X == 0 ) || ( size.Y == 0 ))
    return _Const0002;

  rd = EwNewRect( 0, 0, width, height );
  rs = rd;
  rs = EwSetRectSize( rs, size );

  if ( EwGetRectW( rs ) != EwGetRectW( rd ))
    rs = EwSetRectX( rs, ( rd.Point1.X + ( EwGetRectW( rd ) / 2 )) - ( EwGetRectW( 
    rs ) / 2 ));

  if ( EwGetRectH( rs ) != EwGetRectH( rd ))
    rs = EwSetRectY( rs, ( rd.Point1.Y + ( EwGetRectH( rd ) / 2 )) - ( EwGetRectH( 
    rs ) / 2 ));

  rs = EwMoveRectPos( rs, bounds.Point1 );
  return rs;
}

/* Variants derived from the class : 'Views::Image' */
EW_DEFINE_CLASS_VARIANTS( ViewsImage )
EW_END_OF_CLASS_VARIANTS( ViewsImage )

/* Virtual Method Table (VMT) for the class : 'Views::Image' */
EW_DEFINE_CLASS( ViewsImage, CoreRectView, timer, timer, startTime, startTime, startTime, 
                 startTime, "Views::Image" )
  CoreRectView_initLayoutContext,
  CoreView_GetRoot,
  ViewsImage_Draw,
  CoreView_GetClipping,
  CoreView_HandleEvent,
  CoreView_CursorHitTest,
  CoreView_AdjustDrawingArea,
  CoreRectView_ArrangeView,
  CoreRectView_MoveView,
  CoreRectView_GetExtent,
  CoreView_ChangeViewState,
  CoreRectView_OnSetBounds,
EW_END_OF_CLASS( ViewsImage )

/* Initializer for the class 'Views::Text' */
void ViewsText__Init( ViewsText _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreRectView__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( ViewsText );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( ViewsText );

  /* ... and initialize objects, variables, properties, etc. */
  _this->Alignment = ViewsTextAlignmentAlignHorzCenter | ViewsTextAlignmentAlignVertCenter;
  _this->Color = _Const0000;
}

/* Re-Initializer for the class 'Views::Text' */
void ViewsText__ReInit( ViewsText _this )
{
  /* At first re-initialize the super class ... */
  CoreRectView__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Views::Text' */
void ViewsText__Done( ViewsText _this )
{
  /* Call the user defined destructor of the class */
  ViewsText_Done( _this );

  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreRectView );

  /* Don't forget to deinitialize the super class ... */
  CoreRectView__Done( &_this->_.Super );
}

/* 'C' function for method : 'Views::Text.Done()' */
void ViewsText_Done( ViewsText _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
}

/* The method Draw() is invoked automatically if parts of the view should be redrawn 
   on the screen. This can occur when e.g. the view has been moved or the appearance 
   of the view has changed before.
   Draw() is invoked automatically by the framework, you will never need to invoke 
   this method directly. However you can request an invocation of this method by 
   calling the method InvalidateArea() of the views @Owner. Usually this is also 
   unnecessary unless you are developing your own view.
   The passed parameters determine the drawing destination aCanvas and the area 
   to redraw aClip in the coordinate space of the canvas. The parameter aOffset 
   contains the displacement between the origin of the views owner and the origin 
   of the canvas. You will need it to convert views coordinates into these of the 
   canvas.
   The parameter aOpacity contains the opacity descended from this view's @Owner. 
   It lies in range 0 .. 255. If the view implements its own 'Opacity', 'Color', 
   etc. properties, the Draw() method should calculate the resulting real opacity 
   by mixing the values of these properties with the one passed in aOpacity parameter.
   The parameter aBlend contains the blending mode descended from this view's @Owner. 
   It determines, whether the view should be drawn with alpha-blending active or 
   not. If aBlend is false, the outputs of the view should overwrite the corresponding 
   pixel in the drawing destination aCanvas. If aBlend is true, the outputs should 
   be mixed with the pixel already stored in aCanvas. For this purpose all Graphics 
   Engine functions provide a parameter to specify the mode for the respective drawing 
   operation. If the view implements its own 'Blend' property, the Draw() method 
   should calculate the resulting real blend mode by using logical AND operation 
   of the value of the property and the one passed in aBlend parameter. */
void ViewsText_Draw( ViewsText _this, GraphicsCanvas aCanvas, XRect aClip, XPoint 
  aOffset, XInt32 aOpacity, XBool aBlend )
{
  XSet align;
  ResourcesFont font;
  XRect rd;
  XColor ctl;
  XColor ctr;
  XColor cbr;
  XColor cbl;
  XColor col;
  XInt32 opacity;
  XInt32 noOfRows;
  XRect area;
  XPoint ofs;
  XInt32 leading;
  XInt32 rowHeight;
  XInt32 clipY1;
  XInt32 clipY2;
  XInt32 areaW;
  XInt32 y;
  XInt32 i;
  XInt32 c;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aBlend );

  if ( !EwCompString( _this->flowString, 0 ) || ( _this->usedFont == 0 ))
    return;

  align = _this->Alignment;
  font = _this->usedFont;
  rd = EwMoveRectPos( _this->Super1.Bounds, aOffset );
  col = _this->Color;
  opacity = ((( aOpacity + 1 ) * 255 ) >> 8 ) + 1;
  noOfRows = EwGetStringChar( _this->flowString, 0 );
  area = EwMoveRectPos( ViewsText_GetContentArea( _this ), aOffset );
  ofs = EwNewPoint( rd.Point1.X - area.Point1.X, ( rd.Point1.Y - area.Point1.Y ) 
  - font->Ascent );

  if ( noOfRows < 1 )
    return;

  ctl = ctr = cbl = cbr = col;

  if ( opacity < 256 )
  {
    ctl.Alpha = (XUInt8)(( ctl.Alpha * opacity ) >> 8 );
    ctr.Alpha = (XUInt8)(( ctr.Alpha * opacity ) >> 8 );
    cbr.Alpha = (XUInt8)(( cbr.Alpha * opacity ) >> 8 );
    cbl.Alpha = (XUInt8)(( cbl.Alpha * opacity ) >> 8 );
  }

  if ((( align & ViewsTextAlignmentAlignHorzAuto ) == ViewsTextAlignmentAlignHorzAuto ))
  {
    if ( ViewsText_IsBaseDirectionRTL( _this ))
      align = ( align & ~ViewsTextAlignmentAlignHorzAuto ) | ViewsTextAlignmentAlignHorzRight;
    else
      align = ( align & ~ViewsTextAlignmentAlignHorzAuto ) | ViewsTextAlignmentAlignHorzLeft;
  }

  if (( noOfRows == 1 ) && !(( align & ViewsTextAlignmentAlignHorzJustified ) == 
      ViewsTextAlignmentAlignHorzJustified ))
  {
    GraphicsCanvas_DrawText( aCanvas, aClip, font, _this->flowString, 2, EwGetStringChar( 
    _this->flowString, 1 ) - 1, rd, ofs, 0, ViewsOrientationNormal, ctl, ctr, cbr, 
    cbl, 1 );
    return;
  }

  leading = font->Leading;
  rowHeight = ( font->Ascent + font->Descent ) + leading;
  clipY1 = aClip.Point1.Y - area.Point1.Y;
  clipY2 = aClip.Point2.Y - area.Point1.Y;
  areaW = EwGetRectW( area );
  y = 0;
  i = 1;
  c = EwGetStringChar( _this->flowString, 1 );

  while ((( y + rowHeight ) < clipY1 ) && ( c > 0 ))
  {
    i = i + c;
    y = y + rowHeight;
    c = EwGetStringChar( _this->flowString, i );
  }

  while (( y < clipY2 ) && ( c > 0 ))
  {
    XPoint ofs2 = EwMovePointNeg( ofs, EwNewPoint( 0, y ));
    XInt32 rw = 0;
    XBool justified = 0;

    if ((((( align & ViewsTextAlignmentAlignHorzJustified ) == ViewsTextAlignmentAlignHorzJustified ) 
        && ( EwGetStringChar( _this->flowString, ( i + c ) - 1 ) != 0x000A )) && 
        ( EwGetStringChar( _this->flowString, i + 1 ) != 0x000A )) && ( EwGetStringChar( 
        _this->flowString, i + c ) != 0x0000 ))
      justified = 1;

    if ( justified && !!( align & ( ViewsTextAlignmentAlignHorzCenter | ViewsTextAlignmentAlignHorzRight )))
    {
      XInt32 rowEnd = i + c;
      XInt32 blank1 = EwStringFindChar( _this->flowString, 0x0020, i + 1 );
      XInt32 blank2 = EwStringFindChar( _this->flowString, 0x00A0, i + 1 );

      if ((( blank1 < 0 ) || ( blank1 >= rowEnd )) && (( blank2 < 0 ) || ( blank2 
          >= rowEnd )))
        justified = 0;
    }

    if ( justified )
      rw = areaW;
    else
      if ((( align & ViewsTextAlignmentAlignHorzRight ) == ViewsTextAlignmentAlignHorzRight ))
        ofs2.X = (( ofs2.X - areaW ) + ResourcesFont_GetTextAdvance( font, _this->flowString, 
        i + 1, c - 1 ));
      else
        if ((( align & ViewsTextAlignmentAlignHorzCenter ) == ViewsTextAlignmentAlignHorzCenter ))
          ofs2.X = (( ofs2.X - ( areaW / 2 )) + ( ResourcesFont_GetTextAdvance( 
          font, _this->flowString, i + 1, c - 1 ) / 2 ));

    GraphicsCanvas_DrawText( aCanvas, aClip, font, _this->flowString, i + 1, c - 
    1, rd, ofs2, rw, ViewsOrientationNormal, ctl, ctr, cbr, cbl, 1 );
    i = i + c;
    y = y + rowHeight;
    c = EwGetStringChar( _this->flowString, i );
  }
}

/* 'C' function for method : 'Views::Text.OnSetBounds()' */
void ViewsText_OnSetBounds( ViewsText _this, XRect value )
{
  if ( !EwCompRect( value, _this->Super1.Bounds ))
    return;

  if (((( _this->usedFont != _this->Font ) && _this->reparsed ) && EwCompPoint( 
      EwGetRectSize( _this->Super1.Bounds ), EwGetRectSize( value ))) && !(( _this->Super2.viewState 
      & CoreViewStateUpdatingLayout ) == CoreViewStateUpdatingLayout ))
  {
    _this->flowString = 0;
    _this->reparsed = 0;
    EwPostSignal( EwNewSlot( _this, ViewsText_preReparseSlot ), ((XObject)_this ));
  }

  CoreRectView_OnSetBounds((CoreRectView)_this, value );
  EwPostSignal( EwNewSlot( _this, ViewsText_preOnUpdateSlot ), ((XObject)_this ));
  EwIdleSignal( EwNewSlot( _this, ViewsText_onOverflowTest ), ((XObject)_this ));
}

/* 'C' function for method : 'Views::Text.preOnUpdateSlot()' */
void ViewsText_preOnUpdateSlot( ViewsText _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( sender );
}

/* 'C' function for method : 'Views::Text.preReparseSlot()' */
void ViewsText_preReparseSlot( ViewsText _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  EwPostSignal( EwNewSlot( _this, ViewsText_reparseSlot ), ((XObject)_this ));
}

/* 'C' function for method : 'Views::Text.onOverflowTest()' */
void ViewsText_onOverflowTest( ViewsText _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( sender );
}

/* 'C' function for method : 'Views::Text.onUpdateFont()' */
void ViewsText_onUpdateFont( ViewsText _this, XObject sender )
{
  ResourcesFontSet fontSet;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  fontSet = EwCastObject( _this->Font, ResourcesFontSet );

  if ( fontSet != 0 )
    _this->usedFont = ResourcesFontSet_GetAnyFont( fontSet );

  _this->flowString = 0;
  _this->reparsed = 0;
  EwPostSignal( EwNewSlot( _this, ViewsText_preReparseSlot ), ((XObject)_this ));
}

/* 'C' function for method : 'Views::Text.reparseSlot()' */
void ViewsText_reparseSlot( ViewsText _this, XObject sender )
{
  XInt32 width;
  XInt32 height;
  ResourcesFont font;
  ResourcesFontSet fontSet;
  XBool shrink;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( _this->reparsed )
    return;

  width = EwGetRectW( _this->Super1.Bounds );
  height = EwGetRectH( _this->Super1.Bounds );
  font = _this->usedFont;
  fontSet = EwCastObject( _this->Font, ResourcesFontSet );
  shrink = 0;

  do
  {
    if ((( font != 0 ) && !!!font->Ascent ) && !!!font->Descent )
      font = 0;

    _this->reparsed = 1;

    if (( EwCompString( _this->String, 0 ) != 0 ) && ( font != 0 ))
    {
      XInt32 length = EwGetStringLength( _this->String );
      _this->flowString = EwShareString( ResourcesFont_ParseFlowString( font, _this->String, 
      0, -1, length, 0 ));
    }
    else
      _this->flowString = 0;

    _this->textSize = _Const0001;

    if (( fontSet != 0 ) && !EwIsStringEmpty( _this->flowString ))
    {
      XPoint size = EwGetRectSize( ViewsText_GetContentArea( _this ));

      if (( size.X > width ) || ( size.Y > height ))
      {
        ResourcesFont smallerFont = ResourcesFontSet_GetSmallerFont( fontSet, _this->usedFont );

        if ( !( smallerFont != 0 ) || ( smallerFont == _this->usedFont ))
          break;

        _this->usedFont = smallerFont;
        font = _this->usedFont;
        shrink = 1;
      }
      else
        if ( !shrink )
        {
          ResourcesFont largerFont = ResourcesFontSet_GetLargerFont( fontSet, _this->usedFont );

          if ( !( largerFont != 0 ) || ( largerFont == _this->usedFont ))
            break;

          _this->usedFont = largerFont;
          font = _this->usedFont;
        }
        else
          break;
    }
  }
  while (( fontSet != 0 ) && !EwIsStringEmpty( _this->flowString ));

  if (( _this->Super2.Owner != 0 ) && (( _this->Super2.viewState & CoreViewStateVisible ) 
      == CoreViewStateVisible ))
    CoreGroup__InvalidateArea( _this->Super2.Owner, _this->Super1.Bounds );

  EwPostSignal( EwNewSlot( _this, ViewsText_preOnUpdateSlot ), ((XObject)_this ));
  EwIdleSignal( EwNewSlot( _this, ViewsText_onOverflowTest ), ((XObject)_this ));
}

/* 'C' function for method : 'Views::Text.OnSetAlignment()' */
void ViewsText_OnSetAlignment( ViewsText _this, XSet value )
{
  if ( value == _this->Alignment )
    return;

  _this->Alignment = value;

  if (( _this->Super2.Owner != 0 ) && (( _this->Super2.viewState & CoreViewStateVisible ) 
      == CoreViewStateVisible ))
    CoreGroup__InvalidateArea( _this->Super2.Owner, _this->Super1.Bounds );

  if ( _this->usedFont != _this->Font )
  {
    _this->flowString = 0;
    _this->reparsed = 0;
    EwPostSignal( EwNewSlot( _this, ViewsText_preReparseSlot ), ((XObject)_this ));
  }

  if ( _this->reparsed )
    EwPostSignal( EwNewSlot( _this, ViewsText_preOnUpdateSlot ), ((XObject)_this ));
}

/* 'C' function for method : 'Views::Text.OnSetString()' */
void ViewsText_OnSetString( ViewsText _this, XString value )
{
  if ( !EwCompString( value, _this->String ))
    return;

  _this->String = EwShareString( value );
  _this->flowString = 0;
  _this->reparsed = 0;
  EwPostSignal( EwNewSlot( _this, ViewsText_preReparseSlot ), ((XObject)_this ));
}

/* 'C' function for method : 'Views::Text.OnSetFont()' */
void ViewsText_OnSetFont( ViewsText _this, ResourcesFont value )
{
  ResourcesFontSet fontSet;

  if ( value == _this->Font )
    return;

  if (( _this->Font != 0 ) && _this->Font->Mutable )
    EwDetachObjObserver( EwNewSlot( _this, ViewsText_onUpdateFont ), (XObject)_this->Font, 
      0 );

  _this->Font = value;
  fontSet = EwCastObject( value, ResourcesFontSet );
  _this->usedFont = (( fontSet != 0 )? ResourcesFontSet_GetAnyFont( fontSet ) : 
  value );

  if (( value != 0 ) && value->Mutable )
    EwAttachObjObserver( EwNewSlot( _this, ViewsText_onUpdateFont ), (XObject)_this->Font, 
      0 );

  _this->flowString = 0;
  _this->reparsed = 0;
  EwPostSignal( EwNewSlot( _this, ViewsText_preReparseSlot ), ((XObject)_this ));
}

/* 'C' function for method : 'Views::Text.OnSetColor()' */
void ViewsText_OnSetColor( ViewsText _this, XColor value )
{
  if ( !EwCompColor( value, _this->Color ))
    return;

  _this->Color = value;

  if (( _this->Super2.Owner != 0 ) && (( _this->Super2.viewState & CoreViewStateVisible ) 
      == CoreViewStateVisible ))
    CoreGroup__InvalidateArea( _this->Super2.Owner, _this->Super1.Bounds );
}

/* 'C' function for method : 'Views::Text.OnSetVisible()' */
void ViewsText_OnSetVisible( ViewsText _this, XBool value )
{
  if ( value )
    CoreView__ChangeViewState( _this, CoreViewStateVisible, 0 );
  else
    CoreView__ChangeViewState( _this, 0, CoreViewStateVisible );
}

/* The method IsBaseDirectionRTL() returns 'true' if the text specified in @String 
   starts with an RTL (right-to-left) character. This implies the base direction 
   of the entire text paragraph. If the text starts with an LTR (left-to-right) 
   sign or the property @EnableBidiText is 'false', this method returns 'false'. */
XBool ViewsText_IsBaseDirectionRTL( ViewsText _this )
{
  if ( !_this->reparsed )
    EwSignal( EwNewSlot( _this, ViewsText_reparseSlot ), ((XObject)_this ));

  return 0;
}

/* The method GetContentArea() returns the position and the size of an area where 
   the view will show the text. This area is expressed in coordinates relative to 
   the top-left corner of the view's @Owner. The method takes in account all properties 
   which do affect the position and the alignment of the text, e.g. @Alignment, 
   @Orientation, @ScrollOffset, @WrapText, etc. */
XRect ViewsText_GetContentArea( ViewsText _this )
{
  XInt32 leading;
  XInt32 rh;
  XSet align;
  XRect bounds;
  XInt32 width;
  XInt32 height;
  XRect rd;
  XRect rs;

  if ( !EwCompString( _this->String, 0 ) || ( _this->usedFont == 0 ))
    return _Const0002;

  if ( !_this->reparsed )
    EwSignal( EwNewSlot( _this, ViewsText_reparseSlot ), ((XObject)_this ));

  if ( !EwCompString( _this->flowString, 0 ))
    return _Const0002;

  leading = _this->usedFont->Leading;
  rh = ( _this->usedFont->Ascent + _this->usedFont->Descent ) + _this->usedFont->Leading;

  if ( !EwCompPoint( _this->textSize, _Const0001 ))
    _this->textSize.X = ResourcesFont_GetFlowTextAdvance( _this->usedFont, _this->flowString );

  _this->textSize.Y = (( EwGetStringChar( _this->flowString, 0 ) * rh ) - leading );
  align = _this->Alignment;
  bounds = _this->Super1.Bounds;
  width = EwGetRectW( bounds );
  height = EwGetRectH( bounds );
  rd = EwNewRect( 0, 0, width, height );
  rs = EwNewRect2Point( rd.Point1, EwMovePointPos( rd.Point1, _this->textSize ));

  if ((( align & ViewsTextAlignmentAlignHorzAuto ) == ViewsTextAlignmentAlignHorzAuto ))
  {
    if ( ViewsText_IsBaseDirectionRTL( _this ))
      align = ( align & ~ViewsTextAlignmentAlignHorzAuto ) | ViewsTextAlignmentAlignHorzRight;
    else
      align = ( align & ~ViewsTextAlignmentAlignHorzAuto ) | ViewsTextAlignmentAlignHorzLeft;
  }

  if ((( align & ViewsTextAlignmentAlignHorzJustified ) == ViewsTextAlignmentAlignHorzJustified ))
  {
    XInt32 maxWidth;
    maxWidth = width;

    if ( maxWidth < 0 )
      maxWidth = 0;

    if ( maxWidth > EwGetRectW( rs ))
      rs = EwSetRectW( rs, maxWidth );
  }

  if (( !!( align & ( ViewsTextAlignmentAlignVertCenter | ViewsTextAlignmentAlignVertCenterBaseline )) 
      && !!( align & ( ViewsTextAlignmentAlignVertBottom | ViewsTextAlignmentAlignVertTop ))) 
      && ( EwGetRectH( rs ) > EwGetRectH( rd )))
    align &= ~( ViewsTextAlignmentAlignVertCenter | ViewsTextAlignmentAlignVertCenterBaseline );

  if ( !!( align & ( ViewsTextAlignmentAlignVertCenter | ViewsTextAlignmentAlignVertCenterBaseline )))
    align &= ~( ViewsTextAlignmentAlignVertBottom | ViewsTextAlignmentAlignVertTop );

  if (((( align & ViewsTextAlignmentAlignHorzCenter ) == ViewsTextAlignmentAlignHorzCenter ) 
      && !!( align & ( ViewsTextAlignmentAlignHorzLeft | ViewsTextAlignmentAlignHorzRight ))) 
      && ( EwGetRectW( rs ) > EwGetRectW( rd )))
    align &= ~ViewsTextAlignmentAlignHorzCenter;

  if ((( align & ViewsTextAlignmentAlignHorzCenter ) == ViewsTextAlignmentAlignHorzCenter ))
    align &= ~( ViewsTextAlignmentAlignHorzLeft | ViewsTextAlignmentAlignHorzRight );

  if ( EwGetRectW( rs ) != EwGetRectW( rd ))
  {
    if ((( align & ViewsTextAlignmentAlignHorzRight ) == ViewsTextAlignmentAlignHorzRight ))
      rs = EwSetRectX( rs, rd.Point2.X - EwGetRectW( rs ));
    else
      if ((( align & ViewsTextAlignmentAlignHorzCenter ) == ViewsTextAlignmentAlignHorzCenter ))
        rs = EwSetRectX( rs, ( rd.Point1.X + ( EwGetRectW( rd ) / 2 )) - ( EwGetRectW( 
        rs ) / 2 ));
  }

  if ( EwGetRectH( rs ) != EwGetRectH( rd ))
  {
    if ((( align & ViewsTextAlignmentAlignVertBottom ) == ViewsTextAlignmentAlignVertBottom ))
      rs = EwSetRectY( rs, rd.Point2.Y - EwGetRectH( rs ));
    else
      if ((( align & ViewsTextAlignmentAlignVertCenterBaseline ) == ViewsTextAlignmentAlignVertCenterBaseline ))
        rs = EwSetRectY( rs, (( rd.Point1.Y + ( EwGetRectH( rd ) / 2 )) - ( EwGetRectH( 
        rs ) / 2 )) + (( _this->usedFont->Descent - _this->usedFont->Ascent ) / 
        2 ));
      else
        if ((( align & ViewsTextAlignmentAlignVertCenter ) == ViewsTextAlignmentAlignVertCenter ))
          rs = EwSetRectY( rs, ( rd.Point1.Y + ( EwGetRectH( rd ) / 2 )) - ( EwGetRectH( 
          rs ) / 2 ));
  }

  rs = EwMoveRectPos( rs, bounds.Point1 );
  return rs;
}

/* Variants derived from the class : 'Views::Text' */
EW_DEFINE_CLASS_VARIANTS( ViewsText )
EW_END_OF_CLASS_VARIANTS( ViewsText )

/* Virtual Method Table (VMT) for the class : 'Views::Text' */
EW_DEFINE_CLASS( ViewsText, CoreRectView, usedFont, usedFont, flowString, flowString, 
                 flowString, textSize, "Views::Text" )
  CoreRectView_initLayoutContext,
  CoreView_GetRoot,
  ViewsText_Draw,
  CoreView_GetClipping,
  CoreView_HandleEvent,
  CoreView_CursorHitTest,
  CoreView_AdjustDrawingArea,
  CoreRectView_ArrangeView,
  CoreRectView_MoveView,
  CoreRectView_GetExtent,
  CoreView_ChangeViewState,
  ViewsText_OnSetBounds,
EW_END_OF_CLASS( ViewsText )

/* Initializer for the class 'Views::WarpView' */
void ViewsWarpView__Init( ViewsWarpView _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreQuadView__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( ViewsWarpView );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( ViewsWarpView );

  /* ... and initialize objects, variables, properties, etc. */
  _this->Super2.viewState = CoreViewStateAlphaBlended | CoreViewStateVisible;
  _this->Shininess = 5.0f;
}

/* Re-Initializer for the class 'Views::WarpView' */
void ViewsWarpView__ReInit( ViewsWarpView _this )
{
  /* At first re-initialize the super class ... */
  CoreQuadView__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Views::WarpView' */
void ViewsWarpView__Done( ViewsWarpView _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreQuadView );

  /* Don't forget to deinitialize the super class ... */
  CoreQuadView__Done( &_this->_.Super );
}

/* 'C' function for method : 'Views::WarpView.OnSetPoint4()' */
void ViewsWarpView_OnSetPoint4( ViewsWarpView _this, XPoint value )
{
  if ( !EwCompPoint( value, _this->Super1.Point4 ))
    return;

  CoreQuadView_OnSetPoint4((CoreQuadView)_this, value );
  _this->vertices[ 3 ][ 0 ] = (XFloat)value.X;
  _this->vertices[ 3 ][ 1 ] = (XFloat)value.Y;
  _this->vertices[ 3 ][ 2 ] = 1.0f;
  _this->newUpdateCase = 'E';
  EwPostSignal( EwNewSlot( _this, ViewsWarpView_update ), ((XObject)_this ));
}

/* 'C' function for method : 'Views::WarpView.OnSetPoint3()' */
void ViewsWarpView_OnSetPoint3( ViewsWarpView _this, XPoint value )
{
  if ( !EwCompPoint( value, _this->Super1.Point3 ))
    return;

  CoreQuadView_OnSetPoint3((CoreQuadView)_this, value );
  _this->vertices[ 2 ][ 0 ] = (XFloat)value.X;
  _this->vertices[ 2 ][ 1 ] = (XFloat)value.Y;
  _this->vertices[ 2 ][ 2 ] = 1.0f;
  _this->newUpdateCase = 'E';
  EwPostSignal( EwNewSlot( _this, ViewsWarpView_update ), ((XObject)_this ));
}

/* 'C' function for method : 'Views::WarpView.OnSetPoint2()' */
void ViewsWarpView_OnSetPoint2( ViewsWarpView _this, XPoint value )
{
  if ( !EwCompPoint( value, _this->Super1.Point2 ))
    return;

  CoreQuadView_OnSetPoint2((CoreQuadView)_this, value );
  _this->vertices[ 1 ][ 0 ] = (XFloat)value.X;
  _this->vertices[ 1 ][ 1 ] = (XFloat)value.Y;
  _this->vertices[ 1 ][ 2 ] = 1.0f;
  _this->newUpdateCase = 'E';
  EwPostSignal( EwNewSlot( _this, ViewsWarpView_update ), ((XObject)_this ));
}

/* 'C' function for method : 'Views::WarpView.OnSetPoint1()' */
void ViewsWarpView_OnSetPoint1( ViewsWarpView _this, XPoint value )
{
  if ( !EwCompPoint( value, _this->Super1.Point1 ))
    return;

  CoreQuadView_OnSetPoint1((CoreQuadView)_this, value );
  _this->vertices[ 0 ][ 0 ] = (XFloat)value.X;
  _this->vertices[ 0 ][ 1 ] = (XFloat)value.Y;
  _this->vertices[ 0 ][ 2 ] = 1.0f;
  _this->newUpdateCase = 'E';
  EwPostSignal( EwNewSlot( _this, ViewsWarpView_update ), ((XObject)_this ));
}

/* 'C' function for method : 'Views::WarpView.calculateLight()' */
void ViewsWarpView_calculateLight( ViewsWarpView _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  return;
}

/* 'C' function for method : 'Views::WarpView.update()' */
void ViewsWarpView_update( ViewsWarpView _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( _this->newUpdateCase == 0x0000 )
    return;

  if ( _this->newUpdateCase == 'E' )
  {
    GraphicsWarpMatrix m = EwNewObject( GraphicsWarpMatrix, 0 );
    m = GraphicsWarpMatrix_DeriveFromQuad( m, _this->vertices[ 0 ][ 0 ], _this->vertices[ 
    0 ][ 1 ], _this->vertices[ 1 ][ 0 ], _this->vertices[ 1 ][ 1 ], _this->vertices[ 
    2 ][ 0 ], _this->vertices[ 2 ][ 1 ], _this->vertices[ 3 ][ 0 ], _this->vertices[ 
    3 ][ 1 ]);

    if ( m != 0 )
    {
      GraphicsWarpMatrix_CalculateZ( m, 0.0f, 0.0f );
      _this->vertices[ 0 ][ 2 ] = m->Z * 240.0f;
      GraphicsWarpMatrix_CalculateZ( m, 1.0f, 0.0f );
      _this->vertices[ 1 ][ 2 ] = m->Z * 240.0f;
      GraphicsWarpMatrix_CalculateZ( m, 1.0f, 1.0f );
      _this->vertices[ 2 ][ 2 ] = m->Z * 240.0f;
      GraphicsWarpMatrix_CalculateZ( m, 0.0f, 1.0f );
      _this->vertices[ 3 ][ 2 ] = m->Z * 240.0f;
    }

    ViewsWarpView_calculateLight( _this );
  }

  _this->oldUpdateCase = _this->newUpdateCase;
  _this->newUpdateCase = 0x0000;

  if (( _this->Super2.Owner != 0 ) && (( _this->Super2.viewState & CoreViewStateVisible ) 
      == CoreViewStateVisible ))
    CoreGroup__InvalidateArea( _this->Super2.Owner, CoreView__GetClipping( _this ));
}

/* 'C' function for method : 'Views::WarpView.OnSetShininess()' */
void ViewsWarpView_OnSetShininess( ViewsWarpView _this, XFloat value )
{
  if ( value < 0.0f )
    value = 1.0f;

  if ( value > 100.0f )
    value = 100.0f;

  if ( value == _this->Shininess )
    return;

  _this->Shininess = value;

  if ( _this->newUpdateCase == 0x0000 )
  {
    ViewsWarpView_calculateLight( _this );

    if (( _this->Super2.Owner != 0 ) && (( _this->Super2.viewState & CoreViewStateVisible ) 
        == CoreViewStateVisible ))
      CoreGroup__InvalidateArea( _this->Super2.Owner, CoreView__GetClipping( _this ));
  }
}

/* 'C' function for method : 'Views::WarpView.OnSetSourceAnchor()' */
void ViewsWarpView_OnSetSourceAnchor( ViewsWarpView _this, XPoint value )
{
  if ( !EwCompPoint( value, _this->SourceAnchor ))
    return;

  _this->SourceAnchor = value;

  if (( _this->oldUpdateCase != 'E' ) && ( _this->newUpdateCase == 0x0000 ))
  {
    _this->newUpdateCase = _this->oldUpdateCase;
    EwPostSignal( EwNewSlot( _this, ViewsWarpView_update ), ((XObject)_this ));
  }
}

/* The method RotateAndScale() performs a 2D rotation and scaling of the source 
   image. The transformation is performed around a reference position specified 
   in the property @SourceAnchor. This allows e.g. a rotation around the center 
   of the image, etc. The rotation angle is passed in the parameter aAngle as a 
   value in the range 0 .. 360°. The values passed in the parameters aScaleX and 
   aScaleY determine additional scaling factors for the image in the horizontal 
   and vertical direction. If no scaling should be performed, the value 1.0 can 
   be passed to these parameters. In contrast, if no rotation is desired, 0.0 can 
   be passed to the parameter aAngle.
   The transformed image appears on the screen at the position aDstPos relative 
   to the top-left corner of this view's @Owner. The view itself takes the shape 
   resulting from this transformation and adapts its @Point1 .. @Point4 coordinates 
   accordingly. More sophisticated 2D and 3D transformations are performed by the 
   method @Warp3D(). */
void ViewsWarpView_RotateAndScale( ViewsWarpView _this, XPoint aDstPos, XFloat aAngle, 
  XFloat aScaleX, XFloat aScaleY )
{
  XRect sourceArea;
  XPoint sourceAnchor;
  XFloat l;
  XFloat r;
  XFloat t;
  XFloat b;
  XFloat cosA;
  XFloat sinA;
  XFloat l_cosA;
  XFloat l_sinA;
  XFloat r_cosA;
  XFloat r_sinA;
  XFloat t_cosA;
  XFloat t_sinA;
  XFloat b_cosA;
  XFloat b_sinA;
  XFloat dstX;
  XFloat dstY;

  if (( _this->bitmapSize.X == 0 ) || ( _this->bitmapSize.Y == 0 ))
    return;

  sourceArea = EwNewRect2Point( _Const0001, _this->bitmapSize );
  sourceAnchor = _this->SourceAnchor;
  l = (XFloat)( sourceArea.Point1.X - sourceAnchor.X ) * aScaleX;
  r = (XFloat)( sourceArea.Point2.X - sourceAnchor.X ) * aScaleX;
  t = (XFloat)( sourceArea.Point1.Y - sourceAnchor.Y ) * aScaleY;
  b = (XFloat)( sourceArea.Point2.Y - sourceAnchor.Y ) * aScaleY;
  cosA = EwMathCos( aAngle );
  sinA = EwMathSin( aAngle );
  l_cosA = l * cosA;
  l_sinA = l * sinA;
  r_cosA = r * cosA;
  r_sinA = r * sinA;
  t_cosA = t * cosA;
  t_sinA = t * sinA;
  b_cosA = b * cosA;
  b_sinA = b * sinA;
  dstX = (XFloat)aDstPos.X;
  dstY = (XFloat)aDstPos.Y;
  _this->vertices[ 0 ][ 0 ] = ( dstX + l_cosA ) + t_sinA;
  _this->vertices[ 0 ][ 1 ] = ( dstY - l_sinA ) + t_cosA;
  _this->vertices[ 1 ][ 0 ] = ( dstX + r_cosA ) + t_sinA;
  _this->vertices[ 1 ][ 1 ] = ( dstY - r_sinA ) + t_cosA;
  _this->vertices[ 2 ][ 0 ] = ( dstX + r_cosA ) + b_sinA;
  _this->vertices[ 2 ][ 1 ] = ( dstY - r_sinA ) + b_cosA;
  _this->vertices[ 3 ][ 0 ] = ( dstX + l_cosA ) + b_sinA;
  _this->vertices[ 3 ][ 1 ] = ( dstY - l_sinA ) + b_cosA;
  _this->vertices[ 0 ][ 2 ] = 1.0f;
  _this->vertices[ 1 ][ 2 ] = 1.0f;
  _this->vertices[ 2 ][ 2 ] = 1.0f;
  _this->vertices[ 3 ][ 2 ] = 1.0f;

  if (( _this->Super2.Owner != 0 ) && (( _this->Super2.viewState & CoreViewStateVisible ) 
      == CoreViewStateVisible ))
    CoreGroup__InvalidateArea( _this->Super2.Owner, CoreView__GetClipping( _this ));

  _this->Super1.Point1 = EwNewPoint((XInt32)( _this->vertices[ 0 ][ 0 ] + 0.5f ), 
  (XInt32)( _this->vertices[ 0 ][ 1 ] + 0.5f ));
  _this->Super1.Point2 = EwNewPoint((XInt32)( _this->vertices[ 1 ][ 0 ] + 0.5f ), 
  (XInt32)( _this->vertices[ 1 ][ 1 ] + 0.5f ));
  _this->Super1.Point3 = EwNewPoint((XInt32)( _this->vertices[ 2 ][ 0 ] + 0.5f ), 
  (XInt32)( _this->vertices[ 2 ][ 1 ] + 0.5f ));
  _this->Super1.Point4 = EwNewPoint((XInt32)( _this->vertices[ 3 ][ 0 ] + 0.5f ), 
  (XInt32)( _this->vertices[ 3 ][ 1 ] + 0.5f ));
  _this->oldUpdateCase = 'E';
  _this->newUpdateCase = 0x0000;

  if (( _this->Super2.Owner != 0 ) && (( _this->Super2.viewState & CoreViewStateVisible ) 
      == CoreViewStateVisible ))
    CoreGroup__InvalidateArea( _this->Super2.Owner, CoreView__GetClipping( _this ));

  ViewsWarpView_calculateLight( _this );
}

/* Variants derived from the class : 'Views::WarpView' */
EW_DEFINE_CLASS_VARIANTS( ViewsWarpView )
EW_END_OF_CLASS_VARIANTS( ViewsWarpView )

/* Virtual Method Table (VMT) for the class : 'Views::WarpView' */
EW_DEFINE_CLASS( ViewsWarpView, CoreQuadView, _.VMT, _.VMT, _.VMT, _.VMT, _.VMT, 
                 _.VMT, "Views::WarpView" )
  CoreQuadView_initLayoutContext,
  CoreView_GetRoot,
  CoreView_Draw,
  CoreView_GetClipping,
  CoreView_HandleEvent,
  CoreView_CursorHitTest,
  CoreView_AdjustDrawingArea,
  CoreQuadView_ArrangeView,
  CoreQuadView_MoveView,
  CoreQuadView_GetExtent,
  CoreView_ChangeViewState,
  ViewsWarpView_OnSetPoint4,
  ViewsWarpView_OnSetPoint3,
  ViewsWarpView_OnSetPoint2,
  ViewsWarpView_OnSetPoint1,
EW_END_OF_CLASS( ViewsWarpView )

/* Initializer for the class 'Views::WarpImage' */
void ViewsWarpImage__Init( ViewsWarpImage _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ViewsWarpView__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( ViewsWarpImage );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( ViewsWarpImage );

  /* ... and initialize objects, variables, properties, etc. */
}

/* Re-Initializer for the class 'Views::WarpImage' */
void ViewsWarpImage__ReInit( ViewsWarpImage _this )
{
  /* At first re-initialize the super class ... */
  ViewsWarpView__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Views::WarpImage' */
void ViewsWarpImage__Done( ViewsWarpImage _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( ViewsWarpView );

  /* Don't forget to deinitialize the super class ... */
  ViewsWarpView__Done( &_this->_.Super );
}

/* The method Draw() is invoked automatically if parts of the view should be redrawn 
   on the screen. This can occur when e.g. the view has been moved or the appearance 
   of the view has changed before.
   Draw() is invoked automatically by the framework, you will never need to invoke 
   this method directly. However you can request an invocation of this method by 
   calling the method InvalidateArea() of the views @Owner. Usually this is also 
   unnecessary unless you are developing your own view.
   The passed parameters determine the drawing destination aCanvas and the area 
   to redraw aClip in the coordinate space of the canvas. The parameter aOffset 
   contains the displacement between the origin of the views owner and the origin 
   of the canvas. You will need it to convert views coordinates into these of the 
   canvas.
   The parameter aOpacity contains the opacity descended from this view's @Owner. 
   It lies in range 0 .. 255. If the view implements its own 'Opacity', 'Color', 
   etc. properties, the Draw() method should calculate the resulting real opacity 
   by mixing the values of these properties with the one passed in aOpacity parameter.
   The parameter aBlend contains the blending mode descended from this view's @Owner. 
   It determines, whether the view should be drawn with alpha-blending active or 
   not. If aBlend is false, the outputs of the view should overwrite the corresponding 
   pixel in the drawing destination aCanvas. If aBlend is true, the outputs should 
   be mixed with the pixel already stored in aCanvas. For this purpose all Graphics 
   Engine functions provide a parameter to specify the mode for the respective drawing 
   operation. If the view implements its own 'Blend' property, the Draw() method 
   should calculate the resulting real blend mode by using logical AND operation 
   of the value of the property and the one passed in aBlend parameter. */
void ViewsWarpImage_Draw( ViewsWarpImage _this, GraphicsCanvas aCanvas, XRect aClip, 
  XPoint aOffset, XInt32 aOpacity, XBool aBlend )
{
  XInt32 frameNr = 0;
  XColor c1;
  XColor c2;
  XColor c3;
  XColor c4;
  XInt32 opacity;
  XFloat ofsX;
  XFloat ofsY;
  XRect area;

  if ( _this->animFrameNumber >= 0 )
    frameNr = _this->animFrameNumber;

  if (( _this->Bitmap == 0 ) || ( frameNr >= _this->Bitmap->NoOfFrames ))
    return;

  ResourcesBitmap__Update( _this->Bitmap );
  opacity = ((( aOpacity + 1 ) * 255 ) >> 8 ) + 1;
  ofsX = (XFloat)aOffset.X;
  ofsY = (XFloat)aOffset.Y;
  area = EwNewRect2Point( _Const0001, _this->Super1.bitmapSize );
  aBlend = (XBool)( aBlend && (( _this->Super3.viewState & CoreViewStateAlphaBlended ) 
  == CoreViewStateAlphaBlended ));
  c1 = c2 = c3 = c4 = _Const0000;

  if ( opacity < 256 )
  {
    c1.Alpha = (XUInt8)(( 255 * opacity ) >> 8 );
    c2.Alpha = (XUInt8)(( 255 * opacity ) >> 8 );
    c3.Alpha = (XUInt8)(( 255 * opacity ) >> 8 );
    c4.Alpha = (XUInt8)(( 255 * opacity ) >> 8 );
  }

  aClip = EwIntersectRect2( aClip, EwMoveRectPos( _Const0002, aOffset ));
  GraphicsCanvas_WarpBitmap( aCanvas, aClip, _this->Bitmap, frameNr, _this->Super1.vertices[ 
  0 ][ 0 ] + ofsX, _this->Super1.vertices[ 0 ][ 1 ] + ofsY, _this->Super1.vertices[ 
  0 ][ 2 ], _this->Super1.vertices[ 1 ][ 0 ] + ofsX, _this->Super1.vertices[ 1 ][ 
  1 ] + ofsY, _this->Super1.vertices[ 1 ][ 2 ], _this->Super1.vertices[ 2 ][ 0 ] 
  + ofsX, _this->Super1.vertices[ 2 ][ 1 ] + ofsY, _this->Super1.vertices[ 2 ][ 
  2 ], _this->Super1.vertices[ 3 ][ 0 ] + ofsX, _this->Super1.vertices[ 3 ][ 1 ] 
  + ofsY, _this->Super1.vertices[ 3 ][ 2 ], area, c1, c2, c3, c4, aBlend, 1 );
}

/* 'C' function for method : 'Views::WarpImage.observerSlot()' */
void ViewsWarpImage_observerSlot( ViewsWarpImage _this, XObject sender )
{
  XPoint oldBitmapSize;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  oldBitmapSize = _this->Super1.bitmapSize;

  if ( _this->Bitmap != 0 )
    _this->Super1.bitmapSize = _this->Bitmap->FrameSize;
  else
    _this->Super1.bitmapSize = _Const0001;

  if ((( !EwCompPoint( oldBitmapSize, _this->Super1.bitmapSize ) || (( _this->Super1.oldUpdateCase 
      == 'E' ) && ( _this->Super1.newUpdateCase == 0x0000 ))) && ( _this->Super3.Owner 
      != 0 )) && (( _this->Super3.viewState & CoreViewStateVisible ) == CoreViewStateVisible ))
    CoreGroup__InvalidateArea( _this->Super3.Owner, CoreView__GetClipping( _this ));

  if ((( _this->Super1.oldUpdateCase != 'E' ) && ( _this->Super1.newUpdateCase == 
      0x0000 )) && EwCompPoint( oldBitmapSize, _this->Super1.bitmapSize ))
  {
    _this->Super1.newUpdateCase = _this->Super1.oldUpdateCase;
    EwPostSignal( EwNewSlot( _this, ViewsWarpView_update ), ((XObject)_this ));
  }
}

/* 'C' function for method : 'Views::WarpImage.timerSlot()' */
void ViewsWarpImage_timerSlot( ViewsWarpImage _this, XObject sender )
{
  XInt32 frameNr;
  XInt32 period;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  frameNr = _this->animFrameNumber;
  period = 0;

  if ( _this->Bitmap != 0 )
    period = _this->Bitmap->NoOfFrames * _this->Bitmap->FrameDelay;

  if ((( _this->timer != 0 ) && ( _this->animFrameNumber < 0 )) && ( period > 0 ))
    _this->startTime = _this->timer->Time;

  if (( _this->timer != 0 ) && ( period > 0 ))
  {
    XInt32 time = (XInt32)( _this->timer->Time - _this->startTime );
    frameNr = time / _this->Bitmap->FrameDelay;

    if ( time >= period )
    {
      frameNr = frameNr % _this->Bitmap->NoOfFrames;
      _this->startTime = _this->timer->Time - ( time % period );
    }
  }

  if ((( frameNr != _this->animFrameNumber ) && ( _this->Super3.Owner != 0 )) && 
      (( _this->Super3.viewState & CoreViewStateVisible ) == CoreViewStateVisible ))
    CoreGroup__InvalidateArea( _this->Super3.Owner, CoreView__GetClipping( _this ));

  _this->animFrameNumber = frameNr;

  if (( period == 0 ) && ( _this->timer != 0 ))
  {
    EwDetachObjObserver( EwNewSlot( _this, ViewsWarpImage_timerSlot ), (XObject)_this->timer, 
      0 );
    _this->timer = 0;
  }
}

/* 'C' function for method : 'Views::WarpImage.OnSetAnimated()' */
void ViewsWarpImage_OnSetAnimated( ViewsWarpImage _this, XBool value )
{
  if ( _this->Animated == value )
    return;

  _this->Animated = value;
  _this->animFrameNumber = -1;

  if ( !value && ( _this->timer != 0 ))
  {
    EwDetachObjObserver( EwNewSlot( _this, ViewsWarpImage_timerSlot ), (XObject)_this->timer, 
      0 );
    _this->timer = 0;
  }

  if ( value )
  {
    _this->timer = ((CoreTimer)EwGetAutoObject( &EffectsEffectTimer, EffectsEffectTimerClass ));
    EwAttachObjObserver( EwNewSlot( _this, ViewsWarpImage_timerSlot ), (XObject)_this->timer, 
      0 );
    EwPostSignal( EwNewSlot( _this, ViewsWarpImage_timerSlot ), ((XObject)_this ));
  }

  if (( _this->Super3.Owner != 0 ) && (( _this->Super3.viewState & CoreViewStateVisible ) 
      == CoreViewStateVisible ))
    CoreGroup__InvalidateArea( _this->Super3.Owner, CoreView__GetClipping( _this ));
}

/* 'C' function for method : 'Views::WarpImage.OnSetBitmap()' */
void ViewsWarpImage_OnSetBitmap( ViewsWarpImage _this, ResourcesBitmap value )
{
  if ( value == _this->Bitmap )
    return;

  if (( _this->Bitmap != 0 ) && _this->Bitmap->Mutable )
    EwDetachObjObserver( EwNewSlot( _this, ViewsWarpImage_observerSlot ), (XObject)_this->Bitmap, 
      0 );

  _this->Bitmap = value;
  _this->animFrameNumber = -1;

  if (( value != 0 ) && value->Mutable )
    EwAttachObjObserver( EwNewSlot( _this, ViewsWarpImage_observerSlot ), (XObject)value, 
      0 );

  if ( _this->Animated )
  {
    ViewsWarpImage_OnSetAnimated( _this, 0 );
    ViewsWarpImage_OnSetAnimated( _this, 1 );
  }

  EwSignal( EwNewSlot( _this, ViewsWarpImage_observerSlot ), ((XObject)_this ));
}

/* Variants derived from the class : 'Views::WarpImage' */
EW_DEFINE_CLASS_VARIANTS( ViewsWarpImage )
EW_END_OF_CLASS_VARIANTS( ViewsWarpImage )

/* Virtual Method Table (VMT) for the class : 'Views::WarpImage' */
EW_DEFINE_CLASS( ViewsWarpImage, ViewsWarpView, timer, timer, startTime, startTime, 
                 startTime, startTime, "Views::WarpImage" )
  CoreQuadView_initLayoutContext,
  CoreView_GetRoot,
  ViewsWarpImage_Draw,
  CoreView_GetClipping,
  CoreView_HandleEvent,
  CoreView_CursorHitTest,
  CoreView_AdjustDrawingArea,
  CoreQuadView_ArrangeView,
  CoreQuadView_MoveView,
  CoreQuadView_GetExtent,
  CoreView_ChangeViewState,
  ViewsWarpView_OnSetPoint4,
  ViewsWarpView_OnSetPoint3,
  ViewsWarpView_OnSetPoint2,
  ViewsWarpView_OnSetPoint1,
EW_END_OF_CLASS( ViewsWarpImage )

/* Initializer for the class 'Views::StrokePath' */
void ViewsStrokePath__Init( ViewsStrokePath _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreRectView__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( ViewsStrokePath );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( ViewsStrokePath );

  /* ... and initialize objects, variables, properties, etc. */
  _this->Color = _Const0000;
  _this->MiterLimit = 3.0f;
  _this->JoinPoints = GraphicsPathJoinBevel;
  _this->EndCap = GraphicsPathCapFlat;
  _this->StartCap = GraphicsPathCapFlat;
  _this->Width = 1.0f;
}

/* Re-Initializer for the class 'Views::StrokePath' */
void ViewsStrokePath__ReInit( ViewsStrokePath _this )
{
  /* At first re-initialize the super class ... */
  CoreRectView__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Views::StrokePath' */
void ViewsStrokePath__Done( ViewsStrokePath _this )
{
  /* Call the user defined destructor of the class */
  ViewsStrokePath_Done( _this );

  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreRectView );

  /* Don't forget to deinitialize the super class ... */
  CoreRectView__Done( &_this->_.Super );
}

/* 'C' function for method : 'Views::StrokePath.Done()' */
void ViewsStrokePath_Done( ViewsStrokePath _this )
{
  ViewsStrokePath_destroyBuffer( _this );
}

/* The method Draw() is invoked automatically if parts of the view should be redrawn 
   on the screen. This can occur when e.g. the view has been moved or the appearance 
   of the view has changed before.
   Draw() is invoked automatically by the framework, you will never need to invoke 
   this method directly. However you can request an invocation of this method by 
   calling the method InvalidateArea() of the views @Owner. Usually this is also 
   unnecessary unless you are developing your own view.
   The passed parameters determine the drawing destination aCanvas and the area 
   to redraw aClip in the coordinate space of the canvas. The parameter aOffset 
   contains the displacement between the origin of the views owner and the origin 
   of the canvas. You will need it to convert views coordinates into these of the 
   canvas.
   The parameter aOpacity contains the opacity descended from this view's @Owner. 
   It lies in range 0 .. 255. If the view implements its own 'Opacity', 'Color', 
   etc. properties, the Draw() method should calculate the resulting real opacity 
   by mixing the values of these properties with the one passed in aOpacity parameter.
   The parameter aBlend contains the blending mode descended from this view's @Owner. 
   It determines, whether the view should be drawn with alpha-blending active or 
   not. If aBlend is false, the outputs of the view should overwrite the corresponding 
   pixel in the drawing destination aCanvas. If aBlend is true, the outputs should 
   be mixed with the pixel already stored in aCanvas. For this purpose all Graphics 
   Engine functions provide a parameter to specify the mode for the respective drawing 
   operation. If the view implements its own 'Blend' property, the Draw() method 
   should calculate the resulting real blend mode by using logical AND operation 
   of the value of the property and the one passed in aBlend parameter. */
void ViewsStrokePath_Draw( ViewsStrokePath _this, GraphicsCanvas aCanvas, XRect 
  aClip, XPoint aOffset, XInt32 aOpacity, XBool aBlend )
{
  XColor ctl;
  XColor ctr;
  XColor cbl;
  XColor cbr;
  XColor c;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aBlend );

  if ( _this->Path == 0 )
    return;

  c = _this->Color;
  aOpacity = aOpacity + 1;
  ctl = ctr = cbl = cbr = c;

  if ( aOpacity < 256 )
  {
    ctl.Alpha = (XUInt8)(( aOpacity * ctl.Alpha ) >> 8 );
    ctr.Alpha = (XUInt8)(( aOpacity * ctr.Alpha ) >> 8 );
    cbl.Alpha = (XUInt8)(( aOpacity * cbl.Alpha ) >> 8 );
    cbr.Alpha = (XUInt8)(( aOpacity * cbr.Alpha ) >> 8 );
  }

  GraphicsCanvas_StrokePath( aCanvas, aClip, _this->Path, EwMoveRectPos( _this->Super1.Bounds, 
  aOffset ), 0, _this->Offset, _this->Width, _this->StartCap, _this->EndCap, _this->JoinPoints, 
  _this->MiterLimit, ctl, ctr, cbr, cbl, 1, 1 );
}

/* 'C' function for method : 'Views::StrokePath.destroyBuffer()' */
void ViewsStrokePath_destroyBuffer( ViewsStrokePath _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  return;
}

/* 'C' function for method : 'Views::StrokePath.updatePath()' */
void ViewsStrokePath_updatePath( ViewsStrokePath _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if (( _this->Super2.Owner != 0 ) && (( _this->Super2.viewState & CoreViewStateVisible ) 
      == CoreViewStateVisible ))
    CoreGroup__InvalidateArea( _this->Super2.Owner, _this->Super1.Bounds );
}

/* 'C' function for method : 'Views::StrokePath.OnSetColor()' */
void ViewsStrokePath_OnSetColor( ViewsStrokePath _this, XColor value )
{
  if ( !EwCompColor( value, _this->Color ))
    return;

  _this->Color = value;

  if ((( _this->Super2.Owner != 0 ) && (( _this->Super2.viewState & CoreViewStateVisible ) 
      == CoreViewStateVisible )) && ( _this->Path != 0 ))
    CoreGroup__InvalidateArea( _this->Super2.Owner, _this->Super1.Bounds );
}

/* 'C' function for method : 'Views::StrokePath.OnSetOffset()' */
void ViewsStrokePath_OnSetOffset( ViewsStrokePath _this, XPoint value )
{
  if ( !EwCompPoint( value, _this->Offset ))
    return;

  _this->Offset = value;

  if ((( _this->Super2.Owner != 0 ) && (( _this->Super2.viewState & CoreViewStateVisible ) 
      == CoreViewStateVisible )) && ( _this->Path != 0 ))
    CoreGroup__InvalidateArea( _this->Super2.Owner, _this->Super1.Bounds );
}

/* 'C' function for method : 'Views::StrokePath.OnSetMiterLimit()' */
void ViewsStrokePath_OnSetMiterLimit( ViewsStrokePath _this, XFloat value )
{
  if ( value < 0.0f )
    value = 0.0f;

  if ( value == _this->MiterLimit )
    return;

  _this->MiterLimit = value;

  if ((( _this->Super2.Owner != 0 ) && (( _this->Super2.viewState & CoreViewStateVisible ) 
      == CoreViewStateVisible )) && ( _this->Path != 0 ))
    CoreGroup__InvalidateArea( _this->Super2.Owner, _this->Super1.Bounds );
}

/* 'C' function for method : 'Views::StrokePath.OnSetJoinPoints()' */
void ViewsStrokePath_OnSetJoinPoints( ViewsStrokePath _this, XEnum value )
{
  if ( value == _this->JoinPoints )
    return;

  _this->JoinPoints = value;

  if ((( _this->Super2.Owner != 0 ) && (( _this->Super2.viewState & CoreViewStateVisible ) 
      == CoreViewStateVisible )) && ( _this->Path != 0 ))
    CoreGroup__InvalidateArea( _this->Super2.Owner, _this->Super1.Bounds );
}

/* 'C' function for method : 'Views::StrokePath.OnSetEndCap()' */
void ViewsStrokePath_OnSetEndCap( ViewsStrokePath _this, XEnum value )
{
  if ( value == _this->EndCap )
    return;

  _this->EndCap = value;

  if ((( _this->Super2.Owner != 0 ) && (( _this->Super2.viewState & CoreViewStateVisible ) 
      == CoreViewStateVisible )) && ( _this->Path != 0 ))
    CoreGroup__InvalidateArea( _this->Super2.Owner, _this->Super1.Bounds );
}

/* 'C' function for method : 'Views::StrokePath.OnSetStartCap()' */
void ViewsStrokePath_OnSetStartCap( ViewsStrokePath _this, XEnum value )
{
  if ( value == _this->StartCap )
    return;

  _this->StartCap = value;

  if ((( _this->Super2.Owner != 0 ) && (( _this->Super2.viewState & CoreViewStateVisible ) 
      == CoreViewStateVisible )) && ( _this->Path != 0 ))
    CoreGroup__InvalidateArea( _this->Super2.Owner, _this->Super1.Bounds );
}

/* 'C' function for method : 'Views::StrokePath.OnSetWidth()' */
void ViewsStrokePath_OnSetWidth( ViewsStrokePath _this, XFloat value )
{
  if ( value < 0.0f )
    value = 0.0f;

  if ( value == _this->Width )
    return;

  _this->Width = value;

  if ((( _this->Super2.Owner != 0 ) && (( _this->Super2.viewState & CoreViewStateVisible ) 
      == CoreViewStateVisible )) && ( _this->Path != 0 ))
    CoreGroup__InvalidateArea( _this->Super2.Owner, _this->Super1.Bounds );
}

/* 'C' function for method : 'Views::StrokePath.OnSetPath()' */
void ViewsStrokePath_OnSetPath( ViewsStrokePath _this, GraphicsPath value )
{
  if ( value == _this->Path )
    return;

  if ( _this->Path != 0 )
    EwDetachObjObserver( EwNewSlot( _this, ViewsStrokePath_updatePath ), (XObject)_this->Path, 
      0 );

  _this->Path = value;

  if ( _this->Path != 0 )
    EwAttachObjObserver( EwNewSlot( _this, ViewsStrokePath_updatePath ), (XObject)_this->Path, 
      0 );

  if (( _this->Super2.Owner != 0 ) && (( _this->Super2.viewState & CoreViewStateVisible ) 
      == CoreViewStateVisible ))
    CoreGroup__InvalidateArea( _this->Super2.Owner, _this->Super1.Bounds );
}

/* Variants derived from the class : 'Views::StrokePath' */
EW_DEFINE_CLASS_VARIANTS( ViewsStrokePath )
EW_END_OF_CLASS_VARIANTS( ViewsStrokePath )

/* Virtual Method Table (VMT) for the class : 'Views::StrokePath' */
EW_DEFINE_CLASS( ViewsStrokePath, CoreRectView, Path, Path, Color, Color, Color, 
                 Color, "Views::StrokePath" )
  CoreRectView_initLayoutContext,
  CoreView_GetRoot,
  ViewsStrokePath_Draw,
  CoreView_GetClipping,
  CoreView_HandleEvent,
  CoreView_CursorHitTest,
  CoreView_AdjustDrawingArea,
  CoreRectView_ArrangeView,
  CoreRectView_MoveView,
  CoreRectView_GetExtent,
  CoreView_ChangeViewState,
  CoreRectView_OnSetBounds,
EW_END_OF_CLASS( ViewsStrokePath )

/* Embedded Wizard */
