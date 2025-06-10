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

#ifndef _WidgetSetHorizontalSliderConfig_H
#define _WidgetSetHorizontalSliderConfig_H

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

#include "_WidgetSetWidgetConfig.h"

/* Forward declaration of the class Resources::Bitmap */
#ifndef _ResourcesBitmap_
  EW_DECLARE_CLASS( ResourcesBitmap )
#define _ResourcesBitmap_
#endif

/* Forward declaration of the class WidgetSet::HorizontalSliderConfig */
#ifndef _WidgetSetHorizontalSliderConfig_
  EW_DECLARE_CLASS( WidgetSetHorizontalSliderConfig )
#define _WidgetSetHorizontalSliderConfig_
#endif


/* This class implements the functionality permitting you to simply customize the 
   look and feel of a 'horizontal slider' widget (WidgetSet::HorizontalSlider). 
   In the practice, you will create an instance of this class, configure its properties 
   with bitmaps, colors and other relevant attributes according to your design expectations 
   and assign such prepared configuration object to the property 'Appearance' of 
   every affected horizontal slider widget. Thereupon the widgets will use the configuration 
   information provided in the object.
   During its lifetime the slider remains always in one of the four states: 'disabled', 
   'default', 'focused' and 'active'. The state 'disabled' is true for every not 
   available slider (the property 'Enabled' of the slider is 'false'). Such sliders 
   will ignore all user inputs. The state 'default' determines a slider, which is 
   ready to be touched by the user or ready to become focused. As soon as the slider 
   becomes focused, it switches in the state 'focused'. In this state the user can 
   control the slider by pressing keys on the keyboard. Finally, the state 'active' 
   is true, if the user actually interacts with the slider (the slider's thumb is 
   pressed). With the configuration object you can specify the appearance of the 
   slider for every state individually. For this purpose you should know from which 
   views the slider is composed of:
   - 'FaceImage' is a bitmap frame view (Views::Frame) filling vertically centered 
   the entire width in the background of the slider. In the configuration object 
   you can individually specify for every slider state the desired bitmap (@FaceBitmapActive, 
   @FaceBitmapDefault, @FaceBitmapDisabled, @FaceBitmapFocused), the frame number 
   within the bitmap (@FaceFrameActive, @FaceFrameDefault, @FaceFrameDisabled, @FaceFrameFocused) 
   and opacity or color to tint the bitmap (@FaceTintActive, @FaceTintDefault, @FaceTintDisabled, 
   @FaceTintFocused). The slider can automatically play animated bitmaps if the 
   specified frame number is -1.
   - 'TrackLeftRectangle' is a rectangle view (Views::Rectangle) filling per default 
   vertically centered the background of the slider between its left edge and the 
   actual position of the thumb. The height and an additional vertical displacement 
   of the track are determined by the properties @TrackLeftThicknessActive, @TrackLeftThicknessDefault, 
   @TrackLeftThicknessDisabled, @TrackLeftThicknessFocused and @TrackLeftOffsetActive, 
   @TrackLeftOffsetDefault, @TrackLeftOffsetDisabled, @TrackLeftOffsetFocused. The 
   area destined for the track can be limited by configuring the properties @TrackLeftMarginLeft 
   and @TrackLeftMarginRight. With the property @TrackLeftStatic the track can be 
   configured to not depend on the actual thumb position. Normally, the track has 
   rectangular shape with sharp corners. If desired the corners can be rounded (@TrackLeftCornerRadiusActive, 
   @TrackLeftCornerRadiusDefault, @TrackLeftCornerRadiusDisabled, @TrackLeftCornerRadiusFocused) 
   whereby the rounding at the thumb position can be controlled by the property 
   @TrackLeftFlattened. The track can be filled with a solid color (@TrackLeftColorActive, 
   @TrackLeftColorDefault, @TrackLeftColorDisabled, @TrackLeftColorFocused).
   - 'TrackLeftBorder' is a border view (Views::Border) surrounding the above described 
   'TrackLeftRectangle' and lying in front of it. Its size, position and corner 
   radius correspond thus to the of the 'TrackLeftRectangle'. The thickness of the 
   border (@TrackLeftBorderWidthActive, @TrackLeftBorderWidthDefault, @TrackLeftBorderWidthDisabled, 
   @TrackLeftBorderWidthFocused) and its color (@TrackLeftBorderColorActive, @TrackLeftBorderColorDefault, 
   @TrackLeftBorderColorDisabled, @TrackLeftBorderColorFocused) can be specified.
   - 'TrackLeftImage' is a bitmap frame view (Views::Frame) filling per default 
   vertically centered the background of the slider between its left edge and the 
   actual position of the thumb. The area destined for the track can be limited 
   by configuring the properties @TrackLeftMarginLeft and @TrackLeftMarginRight. 
   With the property @TrackLeftStatic the track can be configured to not depend 
   on the actual thumb position. An additional vertical displacement of the track 
   is determined by the properties @TrackLeftOffsetActive, @TrackLeftOffsetDefault, 
   @TrackLeftOffsetDisabled, @TrackLeftOffsetFocused. In the configuration object 
   you can individually specify for every slider state the desired bitmap (@TrackLeftBitmapActive, 
   @TrackLeftBitmapDefault, @TrackLeftBitmapDisabled, @TrackLeftBitmapFocused), 
   the frame number within the bitmap (@TrackLeftFrameActive, @TrackLeftFrameDefault, 
   @TrackLeftFrameDisabled, @TrackLeftFrameFocused) and opacity or color to tint 
   the bitmap (@TrackLeftTintActive, @TrackLeftTintDefault, @TrackLeftTintDisabled, 
   @TrackLeftTintFocused). With the property @TrackLeftWithEdge you can configure 
   how the right edge of the track (the edge at the thumb position) should appear. 
   The slider can automatically play animated bitmaps if the specified frame number 
   is -1.
   - 'TrackRightRectangle' is a rectangle view (Views::Rectangle) filling per default 
   vertically centered the background of the slider between the actual position 
   of the thumb and the right edge of the slider widget. The height and an additional 
   vertical displacement of the track are determined by the properties @TrackRightThicknessActive, 
   @TrackRightThicknessDefault, @TrackRightThicknessDisabled, @TrackRightThicknessFocused 
   and @TrackRightOffsetActive, @TrackRightOffsetDefault, @TrackRightOffsetDisabled, 
   @TrackRightOffsetFocused. The area destined for the track can be limited by configuring 
   the properties @TrackRightMarginLeft and @TrackRightMarginRight. With the property 
   @TrackRightStatic the track can be configured to not depend on the actual thumb 
   position. Normally, the track has rectangular shape with sharp corners. If desired 
   the corners can be rounded (@TrackRightCornerRadiusActive, @TrackRightCornerRadiusDefault, 
   @TrackRightCornerRadiusDisabled, @TrackRightCornerRadiusFocused) whereby the 
   rounding at the thumb position can be controlled by the property @TrackRightFlattened. 
   The track can be filled with a solid color (@TrackRightColorActive, @TrackRightColorDefault, 
   @TrackRightColorDisabled, @TrackRightColorFocused).
   - 'TrackRightBorder' is a border view (Views::Border) surrounding the above described 
   'TrackRightRectangle' and lying in front of it. Its size, position and corner 
   radius correspond thus to the of the 'TrackRightRectangle'. The thickness of 
   the border (@TrackRightBorderWidthActive, @TrackRightBorderWidthDefault, @TrackRightBorderWidthDisabled, 
   @TrackRightBorderWidthFocused) and its color (@TrackRightBorderColorActive, @TrackRightBorderColorDefault, 
   @TrackRightBorderColorDisabled, @TrackRightBorderColorFocused) can be specified.
   - 'TrackRightImage' is a bitmap frame view (Views::Frame) filling per default 
   vertically centered the background of the slider between the actual position 
   of the thumb and the right edge of the slider widget. The area destined for the 
   track can be limited by configuring the properties @TrackRightMarginLeft and 
   @TrackRightMarginRight. With the property @TrackRightStatic the track can be 
   configured to not depend on the actual thumb position. An additional vertical 
   displacement of the track is determined by the properties @TrackRightOffsetActive, 
   @TrackRightOffsetDefault, @TrackRightOffsetDisabled, @TrackRightOffsetFocused. 
   In the configuration object you can individually specify for every slider state 
   the desired bitmap (@TrackRightBitmapActive, @TrackRightBitmapDefault, @TrackRightBitmapDisabled, 
   @TrackRightBitmapFocused), the frame number within the bitmap (@TrackRightFrameActive, 
   @TrackRightFrameDefault, @TrackRightFrameDisabled, @TrackRightFrameFocused) and 
   opacity or color to tint the bitmap (@TrackRightTintActive, @TrackRightTintDefault, 
   @TrackRightTintDisabled, @TrackRightTintFocused). With the property @TrackRightWithEdge 
   you can configure how the left edge of the track (the edge at the thumb position) 
   should appear. The slider can automatically play animated bitmaps if the specified 
   frame number is -1.
   - 'ThumbRectangle' is a rectangle view (Views::Rectangle) displayed vertically 
   centered at the thumb position according to current value of the slider. In the 
   configuration object you can individually specify for every slider state the 
   size of the view (@ThumbSizeActive, @ThumbSizeDefault, @ThumbSizeDisabled, @ThumbSizeFocused) 
   and an additional displacement (@ThumbOffsetActive, @ThumbOffsetDefault, @ThumbOffsetDisabled, 
   @ThumbOffsetFocused). Normally, the thumb area has rectangular shape with sharp 
   corners. If desired the corners can be rounded (@ThumbCornerRadiusActive, @ThumbCornerRadiusDefault, 
   @ThumbCornerRadiusDisabled, @ThumbCornerRadiusFocused). The thumb area can be 
   filled with a solid color (@ThumbColorActive, @ThumbColorDefault, @ThumbColorDisabled, 
   @ThumbColorFocused).
   - 'ThumbBorder' is a border view (Views::Border) surrounding the above described 
   'ThumbRectangle' and lying in front of it. Its size, position and corner radius 
   correspond thus to the of the 'ThumbRectangle'. The thickness of the border (@ThumbBorderWidthActive, 
   @ThumbBorderWidthDefault, @ThumbBorderWidthDisabled, @ThumbBorderWidthFocused) 
   and its color (@ThumbBorderColorActive, @ThumbBorderColorDefault, @ThumbBorderColorDisabled, 
   @ThumbBorderColorFocused) can be specified.
   - 'ThumbShadow' is a shadow view (Views::Shadow) lying always behind the above 
   described 'ThumbRectangle' view. Its size, position and corner radius correspond 
   thus to the of the 'ThumbRectangle'. However, an additional displacement for 
   the shadow can be specified (@ThumbShadowOffsetActive, @ThumbShadowOffsetDefault, 
   @ThumbShadowOffsetDisabled, @ThumbShadowOffsetFocused). The color of the shadow 
   (@ThumbShadowColorActive, @ThumbShadowColorDefault, @ThumbShadowColorDisabled, 
   @ThumbShadowColorFocused) as well as its blur radius (@ThumbShadowBlurRadiusActive, 
   @ThumbShadowBlurRadiusDefault, @ThumbShadowBlurRadiusDisabled, @ThumbShadowBlurRadiusFocused) 
   can be specified.
   - 'ThumbImage' is an image view (Views::Image) displayed vertically centered 
   at the thumb position according to current value of the slider. In the configuration 
   object you can individually specify for every slider state the desired bitmap 
   (@ThumbBitmapActive, @ThumbBitmapDefault, @ThumbBitmapDisabled, @ThumbBitmapFocused), 
   the frame number within the bitmap (@ThumbFrameActive, @ThumbFrameDefault, @ThumbFrameDisabled, 
   @ThumbFrameFocused) and opacity or color to tint the bitmap (@ThumbTintActive, 
   @ThumbTintDefault, @ThumbTintDisabled, @ThumbTintFocused). If necessary, additional 
   margins on the left and on the right of the thumb can be specified by using the 
   properties @ThumbMarginLeft and @ThumbMarginRight. An additional displacement 
   (@ThumbOffsetActive, @ThumbOffsetDefault, @ThumbOffsetDisabled, @ThumbOffsetFocused) 
   can be configured. The slider can automatically play animated bitmaps if the 
   specified frame number is -1.
   - 'AccentRectangle' is a rectangle view (Views::Rectangle) displayed per default 
   vertically centered at the thumb position according to current value of the slider. 
   In the configuration object you can individually specify for every slider state 
   the size of the view (@AccentSizeActive, @AccentSizeDefault, @AccentSizeDisabled, 
   @AccentSizeFocused) and an additional displacement (@AccentOffsetActive, @AccentOffsetDefault, 
   @AccentOffsetDisabled, @AccentOffsetFocused). Normally, the accent area has rectangular 
   shape with sharp corners. If desired the corners can be rounded (@AccentCornerRadiusActive, 
   @AccentCornerRadiusDefault, @AccentCornerRadiusDisabled, @AccentCornerRadiusFocused). 
   The accent area can be filled with a solid color (@AccentColorActive, @AccentColorDefault, 
   @AccentColorDisabled, @AccentColorFocused). Accent usually serves to highlight 
   the widget when the user interacts with it actively or when the widget is focused.
   - 'AccentBorder' is a border view (Views::Border) surrounding the above described 
   'AccentRectangle' and lying in front of it. Its size, position and corner radius 
   correspond thus to the of the 'AccentRectangle'. The thickness of the border 
   (@AccentBorderWidthActive, @AccentBorderWidthDefault, @AccentBorderWidthDisabled, 
   @AccentBorderWidthFocused) and its color (@AccentBorderColorActive, @AccentBorderColorDefault, 
   @AccentBorderColorDisabled, @AccentBorderColorFocused) can be specified. Accent 
   usually serves to highlight the widget when the user interacts with it actively 
   or when the widget is focused.
   - 'CoverImage' is a bitmap frame view (Views::Frame) filling vertically centered 
   the entire width of the slider and covering so eventually the thumb and track. 
   In the configuration object you can individually specify for every slider state 
   the desired bitmap (@CoverBitmapActive, @CoverBitmapDefault, @CoverBitmapDisabled, 
   @CoverBitmapFocused), the frame number within the bitmap (@CoverFrameActive, 
   @CoverFrameDefault, @CoverFrameDisabled, @CoverFrameFocused) and opacity or color 
   to tint the bitmap (@CoverTintActive, @CoverTintDefault, @CoverTintDisabled, 
   @CoverTintFocused). The slider can automatically play animated bitmaps if the 
   specified frame number is -1.
   All above mentioned views are arranged one above the other whereby the resulting 
   stacking order can be configured by using the properties @FaceStackingPriority, 
   @TrackLeftStackingPriority, @TrackRightStackingPriority, @ThumbStackingPriority, 
   @AccentStackingPriority and @CoverStackingPriority. The view with higher priority 
   will appear in front of other views with lower priority.
   Normally, when a state alternation occurs, the affected views are updated immediatelly 
   to reflect the new state. By using the property @StateTransitionDuration it is 
   possible to configure the slider to perform state alternations with animations 
   (e.g. the displacement of the thumb shadow can be animated). This affects all 
   attributes of the filled rectangle, border and shadow views belonging to the 
   thumb, left track, right track and accent. In case of the images displayed in 
   the face, left track, right track, thumb and cover, the animation has an effect 
   only on the colors and offsets used to configure the views. Consequently, during 
   animations these views can fade-out/in their colors and move only.
   If the slider is actually focused, it can also be controlled by pressing the 
   keyboard keys specified in the properties @KeyCodeLeft and @KeyCodeRight causing 
   the slider's thumb to be moved left or right. To prevent the slider from being 
   able to be focused, initialize these properties with the value Core::KeyCode.NoKey. 
   With the properties @KeyRepeatDelay and @KeyRepeatPeriod you can configure whether 
   the thumb should be moved autonomously when the user holds the key pressed for 
   a while.
   To further enhance the widgets, a slot method can be assigned to the property 
   @OnUpdate. Within the slot method new decoration views can be added to the widgets 
   and updated according to the current state of the widget. 
   With the properties @WidgetMinSize and @WidgetMaxSize you can configure size 
   constraints for the widget itself. You can, for example, limit the slider to 
   not shrink below a specified width or height. */
EW_DEFINE_FIELDS( WidgetSetHorizontalSliderConfig, WidgetSetWidgetConfig )
  EW_PROPERTY( TrackLeftBitmapDefault, ResourcesBitmap )
  EW_PROPERTY( AccentColorActive, XColor )
  EW_PROPERTY( AccentColorFocused, XColor )
  EW_PROPERTY( AccentCornerRadiusActive, XInt32 )
  EW_PROPERTY( AccentCornerRadiusFocused, XInt32 )
  EW_PROPERTY( AccentCornerRadiusDisabled, XInt32 )
  EW_PROPERTY( AccentCornerRadiusDefault, XInt32 )
  EW_PROPERTY( AccentSizeActive, XPoint )
  EW_PROPERTY( AccentSizeFocused, XPoint )
  EW_PROPERTY( AccentSizeDisabled, XPoint )
  EW_PROPERTY( AccentSizeDefault, XPoint )
  EW_PROPERTY( ThumbBorderColorActive, XColor )
  EW_PROPERTY( ThumbBorderColorFocused, XColor )
  EW_PROPERTY( ThumbBorderColorDisabled, XColor )
  EW_PROPERTY( ThumbBorderColorDefault, XColor )
  EW_PROPERTY( ThumbBorderWidthActive, XInt32 )
  EW_PROPERTY( ThumbBorderWidthFocused, XInt32 )
  EW_PROPERTY( ThumbBorderWidthDisabled, XInt32 )
  EW_PROPERTY( ThumbBorderWidthDefault, XInt32 )
  EW_PROPERTY( ThumbColorActive, XColor )
  EW_PROPERTY( ThumbColorFocused, XColor )
  EW_PROPERTY( ThumbColorDisabled, XColor )
  EW_PROPERTY( ThumbColorDefault, XColor )
  EW_PROPERTY( ThumbCornerRadiusActive, XInt32 )
  EW_PROPERTY( ThumbCornerRadiusFocused, XInt32 )
  EW_PROPERTY( ThumbCornerRadiusDisabled, XInt32 )
  EW_PROPERTY( ThumbCornerRadiusDefault, XInt32 )
  EW_PROPERTY( ThumbSizeActive, XPoint )
  EW_PROPERTY( ThumbSizeFocused, XPoint )
  EW_PROPERTY( ThumbSizeDisabled, XPoint )
  EW_PROPERTY( ThumbSizeDefault, XPoint )
  EW_PROPERTY( TrackRightBorderColorActive, XColor )
  EW_PROPERTY( TrackRightBorderColorFocused, XColor )
  EW_PROPERTY( TrackRightBorderColorDisabled, XColor )
  EW_PROPERTY( TrackRightBorderColorDefault, XColor )
  EW_PROPERTY( TrackRightBorderWidthActive, XInt32 )
  EW_PROPERTY( TrackRightBorderWidthFocused, XInt32 )
  EW_PROPERTY( TrackRightBorderWidthDisabled, XInt32 )
  EW_PROPERTY( TrackRightBorderWidthDefault, XInt32 )
  EW_PROPERTY( TrackRightColorActive, XColor )
  EW_PROPERTY( TrackRightColorFocused, XColor )
  EW_PROPERTY( TrackRightColorDefault, XColor )
  EW_PROPERTY( TrackRightCornerRadiusActive, XInt32 )
  EW_PROPERTY( TrackRightCornerRadiusFocused, XInt32 )
  EW_PROPERTY( TrackRightCornerRadiusDisabled, XInt32 )
  EW_PROPERTY( TrackRightCornerRadiusDefault, XInt32 )
  EW_PROPERTY( TrackRightThicknessActive, XInt32 )
  EW_PROPERTY( TrackRightThicknessFocused, XInt32 )
  EW_PROPERTY( TrackRightThicknessDisabled, XInt32 )
  EW_PROPERTY( TrackRightThicknessDefault, XInt32 )
  EW_PROPERTY( TrackLeftColorActive, XColor )
  EW_PROPERTY( TrackLeftColorFocused, XColor )
  EW_PROPERTY( TrackLeftColorDisabled, XColor )
  EW_PROPERTY( TrackLeftColorDefault, XColor )
  EW_PROPERTY( TrackLeftCornerRadiusActive, XInt32 )
  EW_PROPERTY( TrackLeftCornerRadiusFocused, XInt32 )
  EW_PROPERTY( TrackLeftCornerRadiusDisabled, XInt32 )
  EW_PROPERTY( TrackLeftCornerRadiusDefault, XInt32 )
  EW_PROPERTY( TrackLeftThicknessActive, XInt32 )
  EW_PROPERTY( TrackLeftThicknessFocused, XInt32 )
  EW_PROPERTY( TrackLeftThicknessDisabled, XInt32 )
  EW_PROPERTY( TrackLeftThicknessDefault, XInt32 )
  EW_PROPERTY( TrackRightFlattened, XBool )
  EW_PROPERTY( TrackLeftFlattened, XBool )
EW_END_OF_FIELDS( WidgetSetHorizontalSliderConfig )

/* Virtual Method Table (VMT) for the class : 'WidgetSet::HorizontalSliderConfig' */
EW_DEFINE_METHODS( WidgetSetHorizontalSliderConfig, WidgetSetWidgetConfig )
EW_END_OF_METHODS( WidgetSetHorizontalSliderConfig )

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetAccentColorActive()' */
void WidgetSetHorizontalSliderConfig_OnSetAccentColorActive( WidgetSetHorizontalSliderConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetAccentColorFocused()' */
void WidgetSetHorizontalSliderConfig_OnSetAccentColorFocused( WidgetSetHorizontalSliderConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetAccentCornerRadiusActive()' */
void WidgetSetHorizontalSliderConfig_OnSetAccentCornerRadiusActive( WidgetSetHorizontalSliderConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetAccentCornerRadiusFocused()' */
void WidgetSetHorizontalSliderConfig_OnSetAccentCornerRadiusFocused( WidgetSetHorizontalSliderConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetAccentCornerRadiusDisabled()' */
void WidgetSetHorizontalSliderConfig_OnSetAccentCornerRadiusDisabled( WidgetSetHorizontalSliderConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetAccentCornerRadiusDefault()' */
void WidgetSetHorizontalSliderConfig_OnSetAccentCornerRadiusDefault( WidgetSetHorizontalSliderConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetAccentSizeActive()' */
void WidgetSetHorizontalSliderConfig_OnSetAccentSizeActive( WidgetSetHorizontalSliderConfig _this, 
  XPoint value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetAccentSizeFocused()' */
void WidgetSetHorizontalSliderConfig_OnSetAccentSizeFocused( WidgetSetHorizontalSliderConfig _this, 
  XPoint value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetAccentSizeDisabled()' */
void WidgetSetHorizontalSliderConfig_OnSetAccentSizeDisabled( WidgetSetHorizontalSliderConfig _this, 
  XPoint value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetAccentSizeDefault()' */
void WidgetSetHorizontalSliderConfig_OnSetAccentSizeDefault( WidgetSetHorizontalSliderConfig _this, 
  XPoint value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetThumbBorderColorActive()' */
void WidgetSetHorizontalSliderConfig_OnSetThumbBorderColorActive( WidgetSetHorizontalSliderConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetThumbBorderColorFocused()' */
void WidgetSetHorizontalSliderConfig_OnSetThumbBorderColorFocused( WidgetSetHorizontalSliderConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetThumbBorderColorDisabled()' */
void WidgetSetHorizontalSliderConfig_OnSetThumbBorderColorDisabled( WidgetSetHorizontalSliderConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetThumbBorderColorDefault()' */
void WidgetSetHorizontalSliderConfig_OnSetThumbBorderColorDefault( WidgetSetHorizontalSliderConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetThumbBorderWidthActive()' */
void WidgetSetHorizontalSliderConfig_OnSetThumbBorderWidthActive( WidgetSetHorizontalSliderConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetThumbBorderWidthFocused()' */
void WidgetSetHorizontalSliderConfig_OnSetThumbBorderWidthFocused( WidgetSetHorizontalSliderConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetThumbBorderWidthDisabled()' */
void WidgetSetHorizontalSliderConfig_OnSetThumbBorderWidthDisabled( WidgetSetHorizontalSliderConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetThumbBorderWidthDefault()' */
void WidgetSetHorizontalSliderConfig_OnSetThumbBorderWidthDefault( WidgetSetHorizontalSliderConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetThumbColorActive()' */
void WidgetSetHorizontalSliderConfig_OnSetThumbColorActive( WidgetSetHorizontalSliderConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetThumbColorFocused()' */
void WidgetSetHorizontalSliderConfig_OnSetThumbColorFocused( WidgetSetHorizontalSliderConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetThumbColorDisabled()' */
void WidgetSetHorizontalSliderConfig_OnSetThumbColorDisabled( WidgetSetHorizontalSliderConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetThumbColorDefault()' */
void WidgetSetHorizontalSliderConfig_OnSetThumbColorDefault( WidgetSetHorizontalSliderConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetThumbCornerRadiusActive()' */
void WidgetSetHorizontalSliderConfig_OnSetThumbCornerRadiusActive( WidgetSetHorizontalSliderConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetThumbCornerRadiusFocused()' */
void WidgetSetHorizontalSliderConfig_OnSetThumbCornerRadiusFocused( WidgetSetHorizontalSliderConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetThumbCornerRadiusDisabled()' */
void WidgetSetHorizontalSliderConfig_OnSetThumbCornerRadiusDisabled( WidgetSetHorizontalSliderConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetThumbCornerRadiusDefault()' */
void WidgetSetHorizontalSliderConfig_OnSetThumbCornerRadiusDefault( WidgetSetHorizontalSliderConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetThumbSizeActive()' */
void WidgetSetHorizontalSliderConfig_OnSetThumbSizeActive( WidgetSetHorizontalSliderConfig _this, 
  XPoint value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetThumbSizeFocused()' */
void WidgetSetHorizontalSliderConfig_OnSetThumbSizeFocused( WidgetSetHorizontalSliderConfig _this, 
  XPoint value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetThumbSizeDisabled()' */
void WidgetSetHorizontalSliderConfig_OnSetThumbSizeDisabled( WidgetSetHorizontalSliderConfig _this, 
  XPoint value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetThumbSizeDefault()' */
void WidgetSetHorizontalSliderConfig_OnSetThumbSizeDefault( WidgetSetHorizontalSliderConfig _this, 
  XPoint value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetTrackRightBorderColorActive()' */
void WidgetSetHorizontalSliderConfig_OnSetTrackRightBorderColorActive( WidgetSetHorizontalSliderConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetTrackRightBorderColorFocused()' */
void WidgetSetHorizontalSliderConfig_OnSetTrackRightBorderColorFocused( WidgetSetHorizontalSliderConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetTrackRightBorderColorDisabled()' */
void WidgetSetHorizontalSliderConfig_OnSetTrackRightBorderColorDisabled( WidgetSetHorizontalSliderConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetTrackRightBorderColorDefault()' */
void WidgetSetHorizontalSliderConfig_OnSetTrackRightBorderColorDefault( WidgetSetHorizontalSliderConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetTrackRightBorderWidthActive()' */
void WidgetSetHorizontalSliderConfig_OnSetTrackRightBorderWidthActive( WidgetSetHorizontalSliderConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetTrackRightBorderWidthFocused()' */
void WidgetSetHorizontalSliderConfig_OnSetTrackRightBorderWidthFocused( WidgetSetHorizontalSliderConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetTrackRightBorderWidthDisabled()' */
void WidgetSetHorizontalSliderConfig_OnSetTrackRightBorderWidthDisabled( WidgetSetHorizontalSliderConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetTrackRightBorderWidthDefault()' */
void WidgetSetHorizontalSliderConfig_OnSetTrackRightBorderWidthDefault( WidgetSetHorizontalSliderConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetTrackRightColorActive()' */
void WidgetSetHorizontalSliderConfig_OnSetTrackRightColorActive( WidgetSetHorizontalSliderConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetTrackRightColorFocused()' */
void WidgetSetHorizontalSliderConfig_OnSetTrackRightColorFocused( WidgetSetHorizontalSliderConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetTrackRightColorDefault()' */
void WidgetSetHorizontalSliderConfig_OnSetTrackRightColorDefault( WidgetSetHorizontalSliderConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetTrackRightCornerRadiusActive()' */
void WidgetSetHorizontalSliderConfig_OnSetTrackRightCornerRadiusActive( WidgetSetHorizontalSliderConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetTrackRightCornerRadiusFocused()' */
void WidgetSetHorizontalSliderConfig_OnSetTrackRightCornerRadiusFocused( WidgetSetHorizontalSliderConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetTrackRightCornerRadiusDisabled()' */
void WidgetSetHorizontalSliderConfig_OnSetTrackRightCornerRadiusDisabled( WidgetSetHorizontalSliderConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetTrackRightCornerRadiusDefault()' */
void WidgetSetHorizontalSliderConfig_OnSetTrackRightCornerRadiusDefault( WidgetSetHorizontalSliderConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetTrackRightThicknessActive()' */
void WidgetSetHorizontalSliderConfig_OnSetTrackRightThicknessActive( WidgetSetHorizontalSliderConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetTrackRightThicknessFocused()' */
void WidgetSetHorizontalSliderConfig_OnSetTrackRightThicknessFocused( WidgetSetHorizontalSliderConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetTrackRightThicknessDisabled()' */
void WidgetSetHorizontalSliderConfig_OnSetTrackRightThicknessDisabled( WidgetSetHorizontalSliderConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetTrackRightThicknessDefault()' */
void WidgetSetHorizontalSliderConfig_OnSetTrackRightThicknessDefault( WidgetSetHorizontalSliderConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetTrackRightFlattened()' */
void WidgetSetHorizontalSliderConfig_OnSetTrackRightFlattened( WidgetSetHorizontalSliderConfig _this, 
  XBool value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetTrackLeftColorActive()' */
void WidgetSetHorizontalSliderConfig_OnSetTrackLeftColorActive( WidgetSetHorizontalSliderConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetTrackLeftColorFocused()' */
void WidgetSetHorizontalSliderConfig_OnSetTrackLeftColorFocused( WidgetSetHorizontalSliderConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetTrackLeftColorDisabled()' */
void WidgetSetHorizontalSliderConfig_OnSetTrackLeftColorDisabled( WidgetSetHorizontalSliderConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetTrackLeftColorDefault()' */
void WidgetSetHorizontalSliderConfig_OnSetTrackLeftColorDefault( WidgetSetHorizontalSliderConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetTrackLeftCornerRadiusActive()' */
void WidgetSetHorizontalSliderConfig_OnSetTrackLeftCornerRadiusActive( WidgetSetHorizontalSliderConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetTrackLeftCornerRadiusFocused()' */
void WidgetSetHorizontalSliderConfig_OnSetTrackLeftCornerRadiusFocused( WidgetSetHorizontalSliderConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetTrackLeftCornerRadiusDisabled()' */
void WidgetSetHorizontalSliderConfig_OnSetTrackLeftCornerRadiusDisabled( WidgetSetHorizontalSliderConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetTrackLeftCornerRadiusDefault()' */
void WidgetSetHorizontalSliderConfig_OnSetTrackLeftCornerRadiusDefault( WidgetSetHorizontalSliderConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetTrackLeftThicknessActive()' */
void WidgetSetHorizontalSliderConfig_OnSetTrackLeftThicknessActive( WidgetSetHorizontalSliderConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetTrackLeftThicknessFocused()' */
void WidgetSetHorizontalSliderConfig_OnSetTrackLeftThicknessFocused( WidgetSetHorizontalSliderConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetTrackLeftThicknessDisabled()' */
void WidgetSetHorizontalSliderConfig_OnSetTrackLeftThicknessDisabled( WidgetSetHorizontalSliderConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetTrackLeftThicknessDefault()' */
void WidgetSetHorizontalSliderConfig_OnSetTrackLeftThicknessDefault( WidgetSetHorizontalSliderConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetTrackLeftFlattened()' */
void WidgetSetHorizontalSliderConfig_OnSetTrackLeftFlattened( WidgetSetHorizontalSliderConfig _this, 
  XBool value );

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetTrackLeftBitmapDefault()' */
void WidgetSetHorizontalSliderConfig_OnSetTrackLeftBitmapDefault( WidgetSetHorizontalSliderConfig _this, 
  ResourcesBitmap value );

#ifdef __cplusplus
  }
#endif

#endif /* _WidgetSetHorizontalSliderConfig_H */

/* Embedded Wizard */
