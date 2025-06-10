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

#ifndef _ResourcesFontSet_H
#define _ResourcesFontSet_H

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

#include "_ResourcesFont.h"

/* Forward declaration of the class Resources::FontSet */
#ifndef _ResourcesFontSet_
  EW_DECLARE_CLASS( ResourcesFontSet )
#define _ResourcesFontSet_
#endif


/* The class Resources::FontSet provides a container in which up to four fonts of 
   different sizes can be combined. When assigned to a Views::Text view, the view 
   in question selects from the available fonts the one which is best suited to 
   display its text, filling the view's border area as much as possible and preventing 
   text from being cut off. */
EW_DEFINE_FIELDS( ResourcesFontSet, ResourcesFont )
  EW_ARRAY   ( fonts,           ResourcesFont, [4])
EW_END_OF_FIELDS( ResourcesFontSet )

/* Virtual Method Table (VMT) for the class : 'Resources::FontSet' */
EW_DEFINE_METHODS( ResourcesFontSet, ResourcesFont )
EW_END_OF_METHODS( ResourcesFontSet )

/* 'C' function for method : 'Resources::FontSet.Done()' */
void ResourcesFontSet_Done( ResourcesFontSet _this );

/* 'C' function for method : 'Resources::FontSet.Init()' */
void ResourcesFontSet_Init( ResourcesFontSet _this, XHandle aArg );

/* The method GetLargerFont() searches the FontSet for a font with height larger 
   than the of the font provided in the parameter aFont. If such font is not found, 
   returns the largest font existing in this FontSet. */
ResourcesFont ResourcesFontSet_GetLargerFont( ResourcesFontSet _this, ResourcesFont 
  aFont );

/* The method GetSmallerFont() searches the FontSet for a font with height smaller 
   than the of the font provided in the parameter aFont. If such font is not found, 
   returns the smallest font existing in this FontSet. */
ResourcesFont ResourcesFontSet_GetSmallerFont( ResourcesFontSet _this, ResourcesFont 
  aFont );

/* The method GetAnyFont() returns the first available font fond in the FontSet. */
ResourcesFont ResourcesFontSet_GetAnyFont( ResourcesFontSet _this );

#ifdef __cplusplus
  }
#endif

#endif /* _ResourcesFontSet_H */

/* Embedded Wizard */
