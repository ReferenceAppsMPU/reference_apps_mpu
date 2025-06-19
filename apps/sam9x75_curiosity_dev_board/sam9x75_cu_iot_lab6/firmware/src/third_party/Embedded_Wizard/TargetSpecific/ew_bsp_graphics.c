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
*   This file contains an interface to the GFX2D hardware of the SAM9x target
*   in order to provide graphics acceleration for the Embedded Wizard generated
*   UI applications.
*   This interface is intended to be used only by the Graphics Engine of
*   Embedded Wizard.
*
*******************************************************************************/
#include "configuration.h"
#include "definitions.h"
#include "gfx/driver/gfx_driver.h"

#include "ewrte.h"
#include "ewgfx.h"
#include "ewextgfx.h"
#include "ewgfxdefs.h"
#include "ew_bsp_graphics.h"


#if EW_USE_OPERATING_SYSTEM == 1
  #include "cmsis_os.h"
  osSemaphoreId AcceleratorSemaphoreId;
#endif


static volatile char       TransferInProgress  = 0;
static char                ConcurrentOperation = 1;


/* Indicate end of execute instruction */
volatile uint8_t gpu_end = 0;


static GFX2D_PIXEL_FORMAT gfx2dFormats[GFX_COLOR_MODE_LAST + 1] =
{
    -1, // GFX_COLOR_MODE_GS_8
    -1, // GFX_COLOR_MODE_RGB_332,
    GFX2D_RGB16, // GFX_COLOR_MODE_RGB_565
    -1, // GFX_COLOR_MODE_RGBA_5551
    -1, // GFX_COLOR_MODE_RGB_888
    GFX2D_ARGB32, // GFX_COLOR_MODE_RGBA_8888
    -1, // GFX_COLOR_MODE_ARGB_8888
    -1, // GFX_COLOR_MODE_INDEX_1
    -1, // GFX_COLOR_MODE_INDEX_4
    GFX2D_IDX8, //GFX_COLOR_MODE_INDEX_8
};


void EwBspGraphics_IntHandler(uintptr_t context)
{
    gpu_end = 1;
}

/*******************************************************************************
* FUNCTION:
*   EwBspGraphicsInit
*
* DESCRIPTION:
*   Initialize the GFX2D graphics accelerator.
*
* ARGUMENTS:
*   aDstColorMode - Colorformat of the destination bitmap
*
* RETURN VALUE:
*   If successful, returns != 0.
*
*******************************************************************************/
int EwBspGraphicsInit( uint32_t aDstColorMode )
{
//  DRV_GFX2D_Initialize();

  PLIB_GFX2D_Initialize();
  PLIB_GFX2D_Enable();
  PLIB_GFX2D_IRQ_CallbackRegister(EwBspGraphics_IntHandler, 0);

  #if EW_USE_OPERATING_SYSTEM == 1

    /* create the accelerator semaphore */
    AcceleratorSemaphoreId = EwBspOsSemaphoreCreate( 1, 1 );

    /* initially take the accelerator token for the first GFX2D transfer */
    EwBspOsSemaphoreWait( AcceleratorSemaphoreId, 1000 );

  #endif

  TransferInProgress  = 0;

  return 1;
}


/*******************************************************************************
* FUNCTION:
*   EwBspGraphicsDone
*
* DESCRIPTION:
*   Deinitialize the GFX2D graphics accelerator.
*
* ARGUMENTS:
*   None
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwBspGraphicsDone( void )
{
  /* deinitialize the graphics hal */
}


/*******************************************************************************
* FUNCTION:
*   EwBspGraphicsWaitForCompletion
*
* DESCRIPTION:
*   The function EwBspGraphicsWaitForCompletion returns as soon as the GFX2D has
*   completed a pending graphics instruction. If the GFX2D is in idle mode,
*   the function returns immediately.
*
* ARGUMENTS:
*   None
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwBspGraphicsWaitForCompletion()
{
  // currently all GFX2D transfer is done synchonous
  return;

#if 0
  /* return immediately if no GFX2D transfer is ongoing */
  if ( TransferInProgress == 0 )
    return;

  CPU_LOAD_SET_IDLE();


#ifdef EW_USE_GFX2D_INTERRUPT_MODE

  #if EW_USE_OPERATING_SYSTEM == 1

    EwBspOsSemaphoreWait( AcceleratorSemaphoreId, 1000 );
    TransferInProgress = 0;

  #else

    /* wait until GFX2D transfer is done */
    while( TransferInProgress )
      ;

  #endif

#else

  /* wait until GFX2D transfer is done */
  TransferInProgress = 0;

#endif

  CPU_LOAD_SET_ACTIVE();
#endif
}


/*******************************************************************************
* FUNCTION:
*   EwBspGraphicsConcurrentOperation
*
* DESCRIPTION:
*   The function EwBspGraphicsConcurrentOperation configures the operation mode
*   of GFX2D and CPU. If concurrent operation is enabled, the CPU will work in
*   parallel while the GFX2D is transferring data. If concurrent operation is
*   disabled, the CPU will wait everytime the GFX2D is active.
*   This feature is intended to limit the memory bandwidth, e.g. during display
*   update or other bandwidth consuming activities.
*
* ARGUMENTS:
*   aEnable - flag to switch on/off concurrent operation mode.
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwBspGraphicsConcurrentOperation( int aEnable )
{
  ConcurrentOperation = (char)aEnable;
}


/*******************************************************************************
* FUNCTION:
*   EwBspGraphicsFill
*
* DESCRIPTION:
*   The function EwBspGraphicsFill is used by the Graphics Engine, when a
*   rectangular area should be filled with a constant color by using the GFX2D
*   functionality.
*
* ARGUMENTS:
*   aDstAddr      - Destination address of the transfer.
*   aDstOffset    - Offset in pixel to next row within the destination.
*   aWidth,
*   aHeight       - Size of the area to fill.
*   aDstColorMode - Colorformat of the destination.
*   aSrcColor     - Color to fill the rectangular area.
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwBspGraphicsFill( uint32_t aDstAddr, uint32_t aDstOffset, uint32_t aWidth,
  uint32_t aHeight, uint32_t aDstColorMode, uint32_t aSrcColor )
{
  GFX2D_BUFFER    dest_buffer;
  GFX2D_RECTANGLE dest_rect;

  dest_buffer.width  = aDstOffset + aWidth;
  dest_buffer.height = aHeight;
  dest_buffer.format = gfx2dFormats[ aDstColorMode ];
  dest_buffer.dir    = GFX2D_XY00;
  dest_buffer.addr   = aDstAddr;

  dest_rect.x        = 0;
  dest_rect.y        = 0;
  dest_rect.width    = aWidth;
  dest_rect.height   = aHeight;

  PLIB_GFX2D_Fill( &dest_buffer, &dest_rect, aSrcColor );

  /* Wait for instruction to complete */
  while ( PLIB_GFX2D_GetGlobalStatusBusy() == true ) ;

  /* check for immediate completion of drawing operation */
  if ( !ConcurrentOperation )
    EwBspGraphicsWaitForCompletion();
}


/*******************************************************************************
* FUNCTION:
*   EwBspGraphicsFillBlend
*
* DESCRIPTION:
*   The function EwBspGraphicsFillBlend is used by the Graphics Engine, when a
*   rectangular area should be blended with a constant color by using the GFX2D
*   functionality.
*
* ARGUMENTS:
*   aDstAddr      - Destination address of the transfer.
*   aDstOffset    - Offset in pixel to next row within the destination.
*   aWidth,
*   aHeight       - Size of the area to blend.
*   aDstColorMode - Colorformat of the destination.
*   aSrcColor     - Color to blend the rectangular area.
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwBspGraphicsFillBlend( uint32_t aDstAddr, uint32_t aDstOffset, uint32_t aWidth,
  uint32_t aHeight, uint32_t aDstColorMode, uint32_t aSrcColor )
{
  GFX2D_BUFFER    dest_buffer;
  GFX2D_RECTANGLE dest_rect;

  dest_buffer.width  = aDstOffset + aWidth;
  dest_buffer.height = aHeight;
  dest_buffer.format = gfx2dFormats[ aDstColorMode ];
  dest_buffer.dir    = GFX2D_XY00;
  dest_buffer.addr   = aDstAddr;

  dest_rect.x        = 0;
  dest_rect.y        = 0;
  dest_rect.width    = aWidth;
  dest_rect.height   = aHeight;

  PLIB_GFX2D_Fill(&dest_buffer, &dest_rect, aSrcColor);

  /* Wait for instruction to complete */
  while ( PLIB_GFX2D_GetGlobalStatusBusy() == true ) ;

  /* check for immediate completion of drawing operation */
  if ( !ConcurrentOperation )
    EwBspGraphicsWaitForCompletion();
}


/*******************************************************************************
* FUNCTION:
*   EwBspGraphicsCopy
*
* DESCRIPTION:
*   The function EwBspGraphicsCopy is used by the Graphics Engine, when a source
*   bitmap should be copied into a destination bitmap by using the GFX2D
*   functionality.
*
* ARGUMENTS:
*   aDstAddr      - Destination address of the transfer.
*   aSrcAddr      - Source address of the transfer.
*   aDstOffset    - Offset in pixel to next row within the destination bitmap.
*   aSrcOffset    - Offset in pixel to next row within the source bitmap.
*   aWidth,
*   aHeight       - Size of the area to transfer the bitmap.
*   aDstColorMode - Colorformat of the destination bitmap
*   aSrcColorMode - Colorformat of the source bitmap.
*   aSrcColor     - Color/alpha value to be used for the transfer.
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwBspGraphicsCopy( uint32_t aDstAddr, uint32_t aSrcAddr, uint32_t aDstOffset,
  uint32_t aSrcOffset, uint32_t aWidth, uint32_t aHeight, uint32_t aDstColorMode,
  uint32_t aSrcColorMode, uint32_t aSrcColor )
{
  GFX2D_BUFFER    dest_buffer;
  GFX2D_RECTANGLE dest_rect;
  GFX2D_BUFFER    src_buffer;
  GFX2D_RECTANGLE src_rect;

  dest_buffer.width  = aDstOffset + aWidth;
  dest_buffer.height = aHeight;
  dest_buffer.format = gfx2dFormats[ aDstColorMode ];
  dest_buffer.dir    = GFX2D_XY00;
  dest_buffer.addr   = aDstAddr;

  dest_rect.x        = 0;
  dest_rect.y        = 0;
  dest_rect.width    = aWidth;
  dest_rect.height   = aHeight;

  src_buffer.width   = aSrcOffset + aWidth;
  src_buffer.height  = aHeight;
  src_buffer.format  = gfx2dFormats[ aSrcColorMode ];
  src_buffer.dir     = GFX2D_XY00;
  src_buffer.addr    = aSrcAddr;

  src_rect.x         = 0;
  src_rect.y         = 0;
  src_rect.width     = aWidth;
  src_rect.height    = aHeight;

  PLIB_GFX2D_Copy(&dest_buffer, &dest_rect, &src_buffer, &src_rect);

  while(PLIB_GFX2D_GetGlobalStatusBusy() == true);

  /* check for immediate completion of drawing operation */
  if ( !ConcurrentOperation )
    EwBspGraphicsWaitForCompletion();
}


/*******************************************************************************
* FUNCTION:
*   EwBspGraphicsCopyBlend
*
* DESCRIPTION:
*   The function EwBspGraphicsCopyBlend is used by the Graphics Engine, when a
*   source bitmap should be blended over a destination bitmap by using the GFX2D
*   functionality.
*
* ARGUMENTS:
*   aDstAddr      - Destination address of the transfer.
*   aSrcAddr      - Source address of the transfer.
*   aDstOffset    - Offset in pixel to next row within the destination bitmap.
*   aSrcOffset    - Offset in pixel to next row within the source bitmap.
*   aWidth,
*   aHeight       - Size of the area to transfer the bitmap.
*   aDstColorMode - Colorformat of the destination bitmap
*   aSrcColorMode - Colorformat of the source bitmap.
*   aSrcColor     - Color/alpha value to be used for the transfer.
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwBspGraphicsCopyBlend( uint32_t aDstAddr, uint32_t aSrcAddr, uint32_t aDstOffset,
  uint32_t aSrcOffset, uint32_t aWidth, uint32_t aHeight, uint32_t aDstColorMode,
  uint32_t aSrcColorMode, uint32_t aSrcColor )
{
  GFX2D_BUFFER    dest_buffer;
  GFX2D_RECTANGLE dest_rect;
  GFX2D_BUFFER    src_buffer;
  GFX2D_RECTANGLE src_rect;
  GFX2D_BLEND     blend;

  dest_buffer.width  = aDstOffset + aWidth;
  dest_buffer.height = aHeight;
  dest_buffer.format = gfx2dFormats[ aDstColorMode ];
  dest_buffer.dir    = GFX2D_XY00;
  dest_buffer.addr   = aDstAddr;

  dest_rect.x        = 0;
  dest_rect.y        = 0;
  dest_rect.width    = aWidth;
  dest_rect.height   = aHeight;

  src_buffer.width   = aSrcOffset + aWidth;
  src_buffer.height  = aHeight;
  src_buffer.format  = gfx2dFormats[ aSrcColorMode ];
  src_buffer.dir     = GFX2D_XY00;
  src_buffer.addr    = aSrcAddr;

  src_rect.x         = 0;
  src_rect.y         = 0;
  src_rect.width     = aWidth;
  src_rect.height    = aHeight;

  blend.spe          = GFX2D_SPE_MULTIPLY;
  blend.func         = GFX2D_FUNCTION_ADD;
  blend.dfact        = GFX2D_FACTOR_ONE_MINUS_SRC_ALPHA;
  blend.sfact        = GFX2D_FACTOR_ONE;

  PLIB_GFX2D_Blend(&dest_buffer, &dest_rect, &src_buffer, &src_rect, &dest_buffer, &dest_rect, blend );

  while(PLIB_GFX2D_GetGlobalStatusBusy() == true);

  /* check for immediate completion of drawing operation */
  if ( !ConcurrentOperation )
    EwBspGraphicsWaitForCompletion();
}


/*******************************************************************************
* FUNCTION:
*   EwBspGraphicsLoadClut
*
* DESCRIPTION:
*   The function EwBspGraphicsLoadClut is used by the Graphics Engine, when
*   a Index8 source bitmap should be copied into a destination bitmap by using
*   the GFX2D functionality. In this case, the CLUT of the GFX2D has to be loaded
*   with the given CLUT.
*
* ARGUMENTS:
*   aClutAddr     - Address of the first color entry of the CLUT.
*   aClutSize     - Number of color entries within the CLUT.
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwBspGraphicsLoadClut( uint32_t aClutAddr, uint32_t aClutSize )
{
  /* ensure that previous GFX2D instruction is finished */
  EwBspGraphicsWaitForCompletion();

  /* set the flag for CLUT transfer */
  TransferInProgress = 1;

//  PLIB_GFX2D_SetSurfaceColorLookupTable(GFX2D_SURFACE surface, GFX2D_COLOR_LOOKUP_TABLE table);
  
#ifdef EW_USE_GFX2D_INTERRUPT_MODE

  /* start the transfer */

#else

  /* process the transfer */

#endif

  /* wait for immediate completion of CLUT loading */
  EwBspGraphicsWaitForCompletion();

  /* set the flag for GFX2D transfer */
  TransferInProgress = 1;

  /* check for immediate completion of CLUT loading */
  if ( !ConcurrentOperation )
    EwBspGraphicsWaitForCompletion();
}



#ifdef EW_USE_GFX2D_INTERRUPT_MODE

/*******************************************************************************
* FUNCTION:
*   GFX2D_IRQHandler
*
* DESCRIPTION:
*   GFX2D Interrupt Handler.
*
* ARGUMENTS:
*   None
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void GFX2D_IRQHandler( void )
{
  #if EW_USE_OPERATING_SYSTEM == 1

  osSemaphoreRelease( AcceleratorSemaphoreId );

  #else

  TransferInProgress = 0;

  #endif
}

#endif

/* msy, mli */
