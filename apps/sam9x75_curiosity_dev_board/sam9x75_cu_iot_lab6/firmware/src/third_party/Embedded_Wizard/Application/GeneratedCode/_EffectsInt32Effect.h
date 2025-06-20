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

#ifndef _EffectsInt32Effect_H
#define _EffectsInt32Effect_H

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

#include "_EffectsEffect.h"

/* Forward declaration of the class Core::Timer */
#ifndef _CoreTimer_
  EW_DECLARE_CLASS( CoreTimer )
#define _CoreTimer_
#endif

/* Forward declaration of the class Effects::Int32Effect */
#ifndef _EffectsInt32Effect_
  EW_DECLARE_CLASS( EffectsInt32Effect )
#define _EffectsInt32Effect_
#endif

/* Forward declaration of the class Effects::TimingList */
#ifndef _EffectsTimingList_
  EW_DECLARE_CLASS( EffectsTimingList )
#define _EffectsTimingList_
#endif


/* The class Effects::Int32Effect provides an animation effect intended to animate 
   an 'int32' value within a range determined by the properties @Value1 and @value2. 
   During the animation the value is interpolated and stored in the variable @Value. 
   Additionally the @Outlet property can refer to an 'int32' property which thus 
   will be 'remote controlled' by the effect. 
   Beside the both end values, animation effects are determined by their duration 
   and by the timing function. The duration is primarily controlled by the value 
   of the property @CycleDuration. This is the time the effect will take for a single 
   animation run. Whether and how often the animation is repeated is stored in the 
   property @NoOfCycles. In this case the property @InterCycleDelay can determine 
   an optional interval to wait between two consecutive animation runs. Finally 
   the property @InitialDelay determines the interval to wait at the very beginning 
   of the effect still before the first animation run began.
   The timing function determines the curve to run the animation. The class implements 
   an extensive set of various timing functions. In its simplest case the animation 
   can follow a straight line, or it can start slow and get faster afterwards. More 
   complex timings perform realistic spring elastic and bounce animations. Besides 
   it the user can configure his/her own animation curve. In such case the timing 
   function is based on a cubic Bezier curve. It gives the designer a lot of possibilities 
   to specify very fancy timing functions. The timing is controlled by the property 
   @Timing. In the case the designer wants to specify a new curve, the properties 
   @TimingCustom1 and @TimingCustom2 are available. With the property @Noise an 
   additional random noise can be added to the effect.
   During the runtime of the animation, the effect will send signals to the slot 
   method stored in the property @OnAnimate. When the effect is finished a signal 
   is send to the slot method stored in the @OnFinished property.
   Whether the effect is running or not is controlled by its property @Enabled. 
   It can be used to start and stop the effect. The effect can also be controlled 
   by sending signals to its @StartEffect and @StopEffect slot methods. With the 
   property @Reversed the playback direction can be determined. This allows to simply 
   rewind running effects or to configure an effect to be played in the reverse 
   direction. The slot method @ReverseEffect can also be used to switch the playback 
   direction. */
EW_DEFINE_FIELDS( EffectsInt32Effect, EffectsEffect )
  EW_PROPERTY( Outlet,          XRef )
  EW_VARIABLE( Value,           XInt32 )
  EW_PROPERTY( Value2,          XInt32 )
  EW_PROPERTY( Value1,          XInt32 )
EW_END_OF_FIELDS( EffectsInt32Effect )

/* Virtual Method Table (VMT) for the class : 'Effects::Int32Effect' */
EW_DEFINE_METHODS( EffectsInt32Effect, EffectsEffect )
  EW_METHOD( Animate,           void )( EffectsInt32Effect _this, XFloat aProgress )
EW_END_OF_METHODS( EffectsInt32Effect )

/* 'C' function for method : 'Effects::Int32Effect.Animate()' */
void EffectsInt32Effect_Animate( EffectsInt32Effect _this, XFloat aProgress );

#ifdef __cplusplus
  }
#endif

#endif /* _EffectsInt32Effect_H */

/* Embedded Wizard */
