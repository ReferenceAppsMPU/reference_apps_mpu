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

#ifndef _CoreDialogContext_H
#define _CoreDialogContext_H

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

/* Forward declaration of the class Core::DialogContext */
#ifndef _CoreDialogContext_
  EW_DECLARE_CLASS( CoreDialogContext )
#define _CoreDialogContext_
#endif

/* Forward declaration of the class Core::Group */
#ifndef _CoreGroup_
  EW_DECLARE_CLASS( CoreGroup )
#define _CoreGroup_
#endif

/* Forward declaration of the class Effects::Transition */
#ifndef _EffectsTransition_
  EW_DECLARE_CLASS( EffectsTransition )
#define _EffectsTransition_
#endif


/* Deklaration of class : 'Core::DialogContext' */
EW_DEFINE_FIELDS( CoreDialogContext, XObject )
  EW_VARIABLE( group,           CoreGroup )
  EW_VARIABLE( next,            CoreDialogContext )
  EW_VARIABLE( dismissTransition, EffectsTransition )
  EW_VARIABLE( restoreTransition, EffectsTransition )
  EW_VARIABLE( overlayTransition, EffectsTransition )
  EW_VARIABLE( overrideRestoreTransition, EffectsTransition )
EW_END_OF_FIELDS( CoreDialogContext )

/* Virtual Method Table (VMT) for the class : 'Core::DialogContext' */
EW_DEFINE_METHODS( CoreDialogContext, XObject )
EW_END_OF_METHODS( CoreDialogContext )

#ifdef __cplusplus
  }
#endif

#endif /* _CoreDialogContext_H */

/* Embedded Wizard */
