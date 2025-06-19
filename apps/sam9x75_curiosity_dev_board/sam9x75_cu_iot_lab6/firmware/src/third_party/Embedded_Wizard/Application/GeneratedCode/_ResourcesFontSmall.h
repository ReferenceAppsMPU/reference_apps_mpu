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

#include "_EwFont_Roboto_HC18_C16.h"

/* The small version of the default font resource. The resource is using 'Roboto' 
   TrueType font with 18 pixel height. */
EW_DEFINE_FONT_RES( ResourcesFontSmall )
  EW_FONT_ENTRY( EwFont_Roboto_HC18_C16, 18, 18, 1, 0, 0, 16 )

  EW_FONT_RANGES( ResourcesFontSmall )

  EW_FONT_MAPPINGS( ResourcesFontSmall )
    EW_FONT_MAPPING( ResourcesFontSmall, Default, 0 )

  EW_FONTS_TABLE( ResourcesFontSmall )
    EW_FONT( ResourcesFontSmall, Default )
EW_END_OF_FONT_RES( ResourcesFontSmall )

/* Embedded Wizard */
