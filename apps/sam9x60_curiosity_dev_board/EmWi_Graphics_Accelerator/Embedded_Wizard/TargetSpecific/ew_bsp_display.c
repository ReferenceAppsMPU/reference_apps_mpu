/*******************************************************************************
*
* E M B E D D E D   W I Z A R D   P R O J E C T
*
*                                                Copyright (c) TARA Systems GmbH
*                                    written by Paul Banach and Manfred Schweyer
*
********************************************************************************
*
* This software is delivered "as is" and shows the usage of other software
* components. It is provided as an example software which is intended to be
* modified and extended according to particular requirements.
*
* TARA Systems hereby disclaims all warranties and conditions with regard to the
* software, including all implied warranties and conditions of merchantability
* and non-infringement of any third party IPR or other rights which may result
* from the use or the inability to use the software.
*
********************************************************************************
*
* DESCRIPTION:
*   This file is part of the interface (glue layer) between an Embedded Wizard
*   generated UI application and the board support package (BSP) of a dedicated
*   target.
*   This template is responsible to initialize the display hardware of the board
*   and to provide the necessary access to update the display content.
*
*   Important: This file is intended to be used as a template. Please adapt the
*   implementation and declarations according your particular hardware.
*   In order to provide a starting point for you, the current implementation
*   is prepared for using an embedded Linux system.
*   In this implementation the display is accessed by using the DRM device.
*   The color format of the framebuffer has to correspond to the color format
*   of the Graphics Engine.
*
*******************************************************************************/


#include "configuration.h"
#include "definitions.h"
#include "gfx/driver/gfx_driver.h"

#include "ewconfig.h"
#include "ewrte.h"
#include "ewgfx.h"
#include "ewextgfx.h"
#include "ewgfxdefs.h"

#include "ew_bsp_display.h"

#if EW_USE_OPERATING_SYSTEM == 1

  static XSemaphoreHandle     LcdUpdateSemaphore = 0;

#endif

#define LAYER_INDEX           0

char name[5] = "disp"; 

extern void app_display_update(unsigned int aAddress);

/*******************************************************************************
* FUNCTION:
*   EwBspDisplayInit
*
* DESCRIPTION:
*   The function EwBspDisplayInit initializes the display hardware and returns
*   the display parameter.
*
* ARGUMENTS:
*   aGuiWidth,
*   aGuiHeight   - Size of the GUI in pixel.
*   aDisplayInfo - Display info data structure.
*
* RETURN VALUE:
*   Returns 1 if successful, 0 otherwise.
*
*******************************************************************************/
int EwBspDisplayInit( int aGuiWidth, int aGuiHeight, XDisplayInfo* aDisplayInfo )
{
  EW_UNUSED_ARG( aGuiWidth );
  EW_UNUSED_ARG( aGuiHeight );

  /* check and clean display info structure */
  if ( !aDisplayInfo )
    return 0;

  memset( aDisplayInfo, 0, sizeof( XDisplayInfo ));
  /* return the current display configuration */
  aDisplayInfo->Name           = (char*)&name;
  aDisplayInfo->FrameBuffer    = (void*)EW_FRAME_BUFFER_ADDR;
  aDisplayInfo->DoubleBuffer   = (void*)EW_DOUBLE_BUFFER_ADDR;
  aDisplayInfo->BufferWidth    = EW_DISPLAY_PREFERRED_WIDTH;
  aDisplayInfo->BufferHeight   = EW_DISPLAY_PREFERRED_HEIGHT;
  aDisplayInfo->DisplayWidth   = EW_DISPLAY_PREFERRED_WIDTH;
  aDisplayInfo->DisplayHeight  = EW_DISPLAY_PREFERRED_HEIGHT;

  #if EW_USE_DOUBLE_BUFFER == 1
    aDisplayInfo->UpdateMode   = EW_BSP_DISPLAY_UPDATE_NORMAL;
  #else
    aDisplayInfo->UpdateMode   = EW_BSP_DISPLAY_UPDATE_PARTIAL;
  #endif

  return 1;
}


/*******************************************************************************
* FUNCTION:
*   EwBspDisplayDone
*
* DESCRIPTION:
*   The function EwBspDisplayDone deinitializes the display hardware.
*
* ARGUMENTS:
*   aDisplayInfo - Display info data structure.
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwBspDisplayDone( XDisplayInfo* aDisplayInfo )
{
  EW_UNUSED_ARG( aDisplayInfo );
}


/*******************************************************************************
* FUNCTION:
*   EwBspDisplayGetUpdateArea
*
* DESCRIPTION:
*   The function EwBspDisplayGetUpdateArea returns the next update area
*   depending on the selected display mode:
*   In case of a synchroneous single-buffer, the function has to return the
*   the rectangular areas that correspond to the horizontal stripes (fields)
*   of the framebuffer.
*
* ARGUMENTS:
*   aUpdateRect - Rectangular area which should be updated (redrawn).
*
* RETURN VALUE:
*   Returns 1 if a further update area can be provided, 0 otherwise.
*
*******************************************************************************/
int EwBspDisplayGetUpdateArea( XRect* aUpdateRect )
{
  #if EW_USE_DOUBLE_BUFFER == 0

    static int field = 0;

    /* check if last field is already reached */
    if ( field >= EW_NUMBER_OF_FIELDS )
    {
      field = 0;
      return 0;
    }

    /* determine rectangular area of current field */
    #if EW_SURFACE_ROTATION == 0
      *aUpdateRect = EwNewRect( 0, field * EW_FRAME_BUFFER_HEIGHT / EW_NUMBER_OF_FIELDS,
        EW_FRAME_BUFFER_WIDTH, ( field + 1 ) * EW_FRAME_BUFFER_HEIGHT / EW_NUMBER_OF_FIELDS );
    #endif

    #if EW_SURFACE_ROTATION == 90
      *aUpdateRect = EwNewRect( field * EW_FRAME_BUFFER_HEIGHT / EW_NUMBER_OF_FIELDS, 0,
        ( field + 1 ) * EW_FRAME_BUFFER_HEIGHT / EW_NUMBER_OF_FIELDS, EW_FRAME_BUFFER_WIDTH );
    #endif

    #if EW_SURFACE_ROTATION == 180
      *aUpdateRect = EwNewRect( 0, EW_FRAME_BUFFER_HEIGHT - ( field + 1 ) * EW_FRAME_BUFFER_HEIGHT / EW_NUMBER_OF_FIELDS,
        EW_FRAME_BUFFER_WIDTH, EW_FRAME_BUFFER_HEIGHT - field * EW_FRAME_BUFFER_HEIGHT / EW_NUMBER_OF_FIELDS );
    #endif

    #if EW_SURFACE_ROTATION == 270
      *aUpdateRect = EwNewRect( EW_FRAME_BUFFER_HEIGHT - ( field + 1 ) * EW_FRAME_BUFFER_HEIGHT / EW_NUMBER_OF_FIELDS,
        0, EW_FRAME_BUFFER_HEIGHT - field * EW_FRAME_BUFFER_HEIGHT / EW_NUMBER_OF_FIELDS, EW_FRAME_BUFFER_WIDTH );
    #endif

    /* next field */
    field++;

    /* sync on start line of next field to ensure save drawing operation */
    SyncOnLine( field * EW_FRAME_BUFFER_HEIGHT / EW_NUMBER_OF_FIELDS );

    return 1;

  #endif

  return 0;
}


/*******************************************************************************
* FUNCTION:
*   EwBspDisplayWaitForCompletion
*
* DESCRIPTION:
*   The function EwBspDisplayWaitForCompletion is called from the Graphics Engine
*   to ensure that all pending activities of the display system are completed, so
*   that the rendering of the next frame can start.
*   In case of a double-buffering system, the function has to wait until the
*   V-sync has occured and the pending buffer is used by the display controller.
*   In case of an external display controller, the function has to wait until
*   the transfer (update) of the graphics data has been completed and there are
*   no pending buffers.
*
* ARGUMENTS:
*   None
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwBspDisplayWaitForCompletion( void )
{
	;
}


/*******************************************************************************
* FUNCTION:
*   EwBspDisplayCommitBuffer
*
* DESCRIPTION:
*   The function EwBspDisplayCommitBuffer is called from the Graphics Engine
*   when the rendering of a certain buffer has been completed.
*   The type of buffer depends on the selected framebuffer concept.
*   If the display is running in a double-buffering mode, the function is called
*   after each buffer update in order to change the currently active framebuffer
*   address. Changing the framebuffer address should be synchronized with V-sync.
*   If the system is using an external graphics controller, this function is
*   responsible to start the transfer of the framebuffer content.
*
* ARGUMENTS:
*   aAddress - Address of the framebuffer to be shown on the display.
*   aX,
*   aY       - Origin of the area which has been updated by the Graphics Engine.
*   aWidth,
*   aHeight  - Size of the area which has been updated by the Graphics Engine.
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwBspDisplayCommitBuffer( void* aAddress, int aX, int aY, int aWidth, int aHeight )
{
    /* set pending framebuffer address to be used on next V-sync */
   
    app_display_update((unsigned int) aAddress);
    /* now, the function has to wait until the pending back-buffer is visible -
       otherwise the currently visible frontbuffer may be overwritten with next
       scene. */
    //EwBspDisplayWaitForCompletion();

}

/* mli, msy */
