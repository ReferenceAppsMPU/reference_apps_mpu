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

#ifndef _ViewsText_H
#define _ViewsText_H

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

#include "_CoreRectView.h"

/* Forward declaration of the class Core::Group */
#ifndef _CoreGroup_
  EW_DECLARE_CLASS( CoreGroup )
#define _CoreGroup_
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

/* Forward declaration of the class Resources::Font */
#ifndef _ResourcesFont_
  EW_DECLARE_CLASS( ResourcesFont )
#define _ResourcesFont_
#endif

/* Forward declaration of the class Views::Text */
#ifndef _ViewsText_
  EW_DECLARE_CLASS( ViewsText )
#define _ViewsText_
#endif


/* The class Views::Text provides a kind of view specialized to print the text. 
   The text is stored in the property @String. It can consist of several rows separated 
   by the new-line sign '\\n'. Optionally an automatic text wrap ca be performed 
   if the property @WrapText is 'true'. The automatic text wrap takes place primarily 
   between words. More sophisticated text wrap can be controlled by following special 
   signs used within the text:
   - The tilde sign '~' and the soft-hyphen sign '\x00AD' identify a potential text 
   wrap position. They are usually not displayed until the text wrap took place 
   at their position. Then the text row is terminated with a hyphen '-' sign.
   - The circumflex accent '^' sign and '\x200B' zero-width non breakable space 
   identify potential text wrap positions without ever being visible.
   In order to be able to output the special characters '^' and '~' and as regular 
   signs, the character '%' can be applied in front of the affected sign to convert 
   it to a regular sign. To show the '%' sign itself, use '%%' sequence.
   Beside the automatic text wrap, an explicit linefeed is possible when the '\n' 
   sign has been found in the string.
   The text output is performed with the font specified in the property @Font. The 
   position and the size of the area where the text is drawn is determined by the 
   property @Bounds. If the size of this area differs from the size of the text, 
   the text can be aligned. This is controlled by the property @Alignment. With 
   the property @Orientation the displayed content can be rotated. With the property 
   @Ellipsis the text view can be configured to replace the text fragments lying 
   outside the view's boundary area by the ellipsis sign. By configuring the property 
   @OverflowWarning the Text view can be instructed to report runtime warnings if 
   the displayed text is too long causing the text to appear clipped.
   The color to print the text is defined by the property @Color. Alternatively, 
   the text can be drawn with a color gradient specified by the properties @ColorTL, 
   @ColorTR, @ColorBL and @ColorBR. For each view's corner different color can be 
   set.
   The property @SlideHandler permits the text view to be connected together with 
   an interactive Core::SlideTouchHandler. In this manner the user can scroll the 
   displayed text by simply touching the slide handler on the screen. Alternatively, 
   the scroll position can be controlled by the value of the property @ScrollOffset.
   The visibility of the text is controlled by the properties @Visible and @Embedded. 
   In particular the property @Embedded can determine whether the corresponding 
   view is limited (== embedded) to the boundary of a sibling Core::Outline view 
   or not. The embedding of views within a Core::Outline allows a kind of sub-groups 
   within the GUI component itself. Very useful for any kind of scrollable lists, 
   menus, etc.
   With the property @EnableBidiText the view can be configured to treat the original 
   string @String as containing bi-directional text. In such case, the string is 
   processed by the Unicode Bidirectional Algorithm. If the text contains Arabic 
   characters, the algorithm performs the shaping and determines the obligatory 
   Arabic ligatures. With the method @IsBidiText(), @IsBaseDirectionRTL() and @IsCharDirectionRTL() 
   the resulting state of the processed text can be determined.
   The text provides an additional set of methods useful to access the text rows 
   and glyphs, e.g. @GetNoOfRows(), @GetRowArea(), @RowCol2Position(), @RowCol2StringIndex(), 
   @StringIndex2RowCol(), etc. These methods can be invoked from a slot method assigned 
   to the property @OnUpdate. In this manner text position can be calculated or 
   additional decorations can be drawn. */
EW_DEFINE_FIELDS( ViewsText, CoreRectView )
  EW_VARIABLE( usedFont,        ResourcesFont )
  EW_PROPERTY( Font,            ResourcesFont )
  EW_VARIABLE( flowString,      XString )
  EW_PROPERTY( String,          XString )
  EW_VARIABLE( textSize,        XPoint )
  EW_PROPERTY( Alignment,       XSet )
  EW_PROPERTY( Color,           XColor )
  EW_VARIABLE( reparsed,        XBool )
EW_END_OF_FIELDS( ViewsText )

/* Virtual Method Table (VMT) for the class : 'Views::Text' */
EW_DEFINE_METHODS( ViewsText, CoreRectView )
  EW_METHOD( initLayoutContext, void )( CoreRectView _this, XRect aBounds, CoreOutline 
    aOutline )
  EW_METHOD( GetRoot,           CoreRoot )( CoreView _this )
  EW_METHOD( Draw,              void )( ViewsText _this, GraphicsCanvas aCanvas, 
    XRect aClip, XPoint aOffset, XInt32 aOpacity, XBool aBlend )
  EW_METHOD( GetClipping,       XRect )( CoreView _this )
  EW_METHOD( HandleEvent,       XObject )( CoreView _this, CoreEvent aEvent )
  EW_METHOD( CursorHitTest,     CoreCursorHit )( CoreView _this, XRect aArea, XInt32 
    aFinger, XInt32 aStrikeCount, CoreView aDedicatedView, CoreView aStartView, 
    XSet aRetargetReason )
  EW_METHOD( AdjustDrawingArea, XRect )( CoreView _this, XRect aArea )
  EW_METHOD( ArrangeView,       XPoint )( CoreRectView _this, XRect aBounds, XEnum 
    aFormation )
  EW_METHOD( MoveView,          void )( CoreRectView _this, XPoint aOffset, XBool 
    aFastMove )
  EW_METHOD( GetExtent,         XRect )( CoreRectView _this )
  EW_METHOD( ChangeViewState,   void )( CoreView _this, XSet aSetState, XSet aClearState )
  EW_METHOD( OnSetBounds,       void )( ViewsText _this, XRect value )
EW_END_OF_METHODS( ViewsText )

/* 'C' function for method : 'Views::Text.Done()' */
void ViewsText_Done( ViewsText _this );

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
  aOffset, XInt32 aOpacity, XBool aBlend );

/* 'C' function for method : 'Views::Text.OnSetBounds()' */
void ViewsText_OnSetBounds( ViewsText _this, XRect value );

/* 'C' function for method : 'Views::Text.preOnUpdateSlot()' */
void ViewsText_preOnUpdateSlot( ViewsText _this, XObject sender );

/* 'C' function for method : 'Views::Text.preReparseSlot()' */
void ViewsText_preReparseSlot( ViewsText _this, XObject sender );

/* 'C' function for method : 'Views::Text.onOverflowTest()' */
void ViewsText_onOverflowTest( ViewsText _this, XObject sender );

/* 'C' function for method : 'Views::Text.onUpdateFont()' */
void ViewsText_onUpdateFont( ViewsText _this, XObject sender );

/* 'C' function for method : 'Views::Text.reparseSlot()' */
void ViewsText_reparseSlot( ViewsText _this, XObject sender );

/* 'C' function for method : 'Views::Text.OnSetAlignment()' */
void ViewsText_OnSetAlignment( ViewsText _this, XSet value );

/* 'C' function for method : 'Views::Text.OnSetString()' */
void ViewsText_OnSetString( ViewsText _this, XString value );

/* 'C' function for method : 'Views::Text.OnSetFont()' */
void ViewsText_OnSetFont( ViewsText _this, ResourcesFont value );

/* 'C' function for method : 'Views::Text.OnSetColor()' */
void ViewsText_OnSetColor( ViewsText _this, XColor value );

/* 'C' function for method : 'Views::Text.OnSetVisible()' */
void ViewsText_OnSetVisible( ViewsText _this, XBool value );

/* The method IsBaseDirectionRTL() returns 'true' if the text specified in @String 
   starts with an RTL (right-to-left) character. This implies the base direction 
   of the entire text paragraph. If the text starts with an LTR (left-to-right) 
   sign or the property @EnableBidiText is 'false', this method returns 'false'. */
XBool ViewsText_IsBaseDirectionRTL( ViewsText _this );

/* The method GetContentArea() returns the position and the size of an area where 
   the view will show the text. This area is expressed in coordinates relative to 
   the top-left corner of the view's @Owner. The method takes in account all properties 
   which do affect the position and the alignment of the text, e.g. @Alignment, 
   @Orientation, @ScrollOffset, @WrapText, etc. */
XRect ViewsText_GetContentArea( ViewsText _this );

#ifdef __cplusplus
  }
#endif

#endif /* _ViewsText_H */

/* Embedded Wizard */
