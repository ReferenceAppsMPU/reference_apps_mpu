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

#ifndef _EffectsOpacityFader_H
#define _EffectsOpacityFader_H

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

#include "_EffectsFader.h"
#include "_EffectsInt32Effect.h"

/* Forward declaration of the class Core::Group */
#ifndef _CoreGroup_
  EW_DECLARE_CLASS( CoreGroup )
#define _CoreGroup_
#endif

/* Forward declaration of the class Effects::FaderTask */
#ifndef _EffectsFaderTask_
  EW_DECLARE_CLASS( EffectsFaderTask )
#define _EffectsFaderTask_
#endif

/* Forward declaration of the class Effects::OpacityFader */
#ifndef _EffectsOpacityFader_
  EW_DECLARE_CLASS( EffectsOpacityFader )
#define _EffectsOpacityFader_
#endif


/* The class Effects::OpacityFader provides functionality for the fade-in and fade-out 
   transitions affecting the opacity of a given GUI component. This fader is thus 
   ideal wherever one GUI component should smoothly appear or disappear in context 
   of another component without changing its actual position.
   The parameters for the transition (the start and the end values for the opacity, 
   the duration of the transition, its timing, etc.) are configured in the embedded 
   object @Effect. If the property @UseCurrentState is 'true', the opacity to start 
   the animation is automatically taken over from the affected GUI component as 
   it is just in the moment the fader starts the transition.
   Whether the fader is considered as performing a fade-in or fade-out transition 
   is determined by value of the property @Visible. Set this property to the value 
   'true' if you want the component to appear or remain visible after the transition 
   is done. Set this property to the value 'false' if your intention is to hide 
   or keep invisible the component.
   With the property @Buffered you can configure, whether the fader should additionally 
   enable the buffering mode for the affected GUI component while it drives the 
   transition.
   The fader automatically takes care of adding the GUI component to the intended 
   owner, when the component should appear and it is not yet a member within the 
   owner. Moreover, when fading-in the component, the fader automatically focuses 
   it and restacks it to appear above all other sibling views existing already within 
   the owner component. This behavior can be configured by modifying the properties 
   @AssignFocus and @RestackTopmost.
   The fader automatically removes the GUI component from its owner, when the component 
   disappears (after fade-out). This behavior can be changed by modifying the property 
   @RemoveIfHidden.
   Applying the fade-out transition on a GUI component, which is already invisible 
   has no effect. Similarly, the fade-in transition has no effect if the GUI component 
   is already visible and has the opacity equal to the specified in @Effect object. 
   In both cases the affected component retains its actual state and the fader finishes 
   its work immediately without driving the @Effect object and waiting for its finish.
   In practice, you create an instance of the fader class, configure its properties 
   (in particular the property @Visible) and the @Effect object according to the 
   desired kind of transition and pass both, the fader instance and the affected 
   GUI component as parameters in the invocation of the method Core::Group.FadeGroup(). */
EW_DEFINE_FIELDS( EffectsOpacityFader, EffectsFader )
  EW_OBJECT  ( Effect,          EffectsInt32Effect )
  EW_VARIABLE( finished,        XBool )
EW_END_OF_FIELDS( EffectsOpacityFader )

/* Virtual Method Table (VMT) for the class : 'Effects::OpacityFader' */
EW_DEFINE_METHODS( EffectsOpacityFader, EffectsFader )
  EW_METHOD( IsFinished,        XBool )( EffectsOpacityFader _this )
  EW_METHOD( OnEnd,             void )( EffectsOpacityFader _this )
  EW_METHOD( OnStart,           void )( EffectsOpacityFader _this )
EW_END_OF_METHODS( EffectsOpacityFader )

/* The method IsFinished() should return 'true' if the fader has finalized its fading 
   animation and 'false' if the animation is not started or it is still in progress. 
   This method should therefore be overridden in derived classes to evaluate the 
   state of animation effects used inside the fader. */
XBool EffectsOpacityFader_IsFinished( EffectsOpacityFader _this );

/* The method OnEnd() is invoked automatically just in the moment, when this fader 
   and all other faders belonging to the same fading task have signaled that they 
   are finished with their animations. The default implementation of this method 
   simply does nothing.
   Derived classes can override this method and implement there the code to complete 
   the animation (e.g. to remove the group from its owner after it has been faded-out, 
   etc.). The implementation of the overridden OnEnd() method has to use the variables 
   @Group and @Owner to determine on which group the fader has applied the animation. 
   Depending on the kind of the implemented animation, the OnEnd() method can also 
   evaluate the properties @UseCurrentState, @AssignFocus and @RestackTopmost. */
void EffectsOpacityFader_OnEnd( EffectsOpacityFader _this );

/* The method OnStart() is invoked automatically just in the moment, when the fader 
   is triggered to begin its animation. The default implementation of this method 
   simply calls the @Complete() method indicating so, that the fader is done with 
   its work. Thereupon the next fader waiting for its execution can start.
   Derived classes should override this method and implement there the code to prepare 
   and start the desired fade-in/out animation effects. The implementation of the 
   overridden OnStart() method has to use the variables @Group and @Owner to determine 
   on which group the fader should apply the animation. Depending on the kind of 
   the implemented animation, the OnStart() method can also evaluate the properties 
   @UseCurrentState, @AssignFocus and @RestackTopmost.
   Please note, if there is a slot method associated to the property @OnInitialize, 
   this slot method is signaled shortly before the method OnStart() is executed 
   given the slot method a possibility to apply more individual initialization steps 
   on the fader just before the animation begins.
   When the animation reaches its end (e.g. when the animation effects used inside 
   the fader do terminate), your implementation of the fader should invoke the method 
   @Complete() otherwise the animation is considered as still being in progress 
   causing other pending faders to wait. */
void EffectsOpacityFader_OnStart( EffectsOpacityFader _this );

/* 'C' function for method : 'Effects::OpacityFader.onFinished()' */
void EffectsOpacityFader_onFinished( EffectsOpacityFader _this, XObject sender );

#ifdef __cplusplus
  }
#endif

#endif /* _EffectsOpacityFader_H */

/* Embedded Wizard */
