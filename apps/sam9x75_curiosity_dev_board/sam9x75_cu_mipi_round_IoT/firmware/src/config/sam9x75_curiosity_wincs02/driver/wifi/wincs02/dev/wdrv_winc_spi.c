/*******************************************************************************
  WINC Wireless Driver SPI Communication Support

  File Name:
    wdrv_winc_spi.c

  Summary:
    WINC Wireless Driver SPI Communications Support

  Description:
    Supports SPI communications to the WINC module.
 *******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2024 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/

#include "configuration.h"
#include "definitions.h"
#include "osal/osal.h"
#include "wdrv_winc_common.h"
#include "wdrv_winc_spi.h"

// *****************************************************************************
// *****************************************************************************
// Section: Data Type Definitions
// *****************************************************************************
// *****************************************************************************

typedef struct
{
    bool                                isInit;
    bool                                isOpen;
    WDRV_WINC_SPI_CFG                   cfg;
    SYS_DMA_SOURCE_ADDRESSING_MODE      txDMAAddrMode;
    SYS_DMA_DESTINATION_ADDRESSING_MODE rxDMAAddrMode;
    OSAL_SEM_HANDLE_TYPE                syncSem;
} WDRV_WINC_SPIDCPT;

// *****************************************************************************
// *****************************************************************************
// Section: Global Data
// *****************************************************************************
// *****************************************************************************

static WDRV_WINC_SPIDCPT spiDcpt = {.isInit = false};
static CACHE_ALIGN uint8_t dummyDataTx[CACHE_ALIGNED_SIZE_GET(4)];
static CACHE_ALIGN uint8_t dummyDataRx[CACHE_ALIGNED_SIZE_GET(4)];

// *****************************************************************************
// *****************************************************************************
// Section: File scope functions
// *****************************************************************************
// *****************************************************************************

static void lDRV_SPI_PlibCallbackHandler(SYS_DMA_TRANSFER_EVENT status, uintptr_t contextHandle)
{
    (void)OSAL_SEM_PostISR((OSAL_SEM_HANDLE_TYPE*)contextHandle);
}

//*******************************************************************************
/*
  Function:
    bool WDRV_WINC_SPISendReceive(void* pTransmitData, void* pReceiveData, size_t size)

  Summary:
    Sends and receives data from the module through the SPI bus.

  Description:
    This function sends and receives data from the module through the SPI bus.

  Remarks:
    See wdrv_winc_spi.h for usage information.

    If the receive buffers are located in cached memory the following rules should
    be applied.

    The receive buffer should not share cache lines with other variables. Any cache
    lines the receive buffer occupies must not be touched during the receive operation.
 */

bool WDRV_WINC_SPISendReceive(void* pTransmitData, void* pReceiveData, size_t size)
{
    SYS_DMA_SOURCE_ADDRESSING_MODE      txDMAAddrMode = SYS_DMA_SOURCE_ADDRESSING_MODE_FIXED;
    SYS_DMA_DESTINATION_ADDRESSING_MODE rxDMAAddrMode = SYS_DMA_DESTINATION_ADDRESSING_MODE_FIXED;

    if ((false == spiDcpt.isInit) || (false == spiDcpt.isOpen))
    {
        return false;
    }

#ifdef WDRV_WINC_SSN_Clear
    WDRV_WINC_SSN_Clear();
#endif

    if (NULL == pReceiveData)
    {
        /* Configure the RX DMA channel - to receive dummy data */
        pReceiveData = dummyDataRx;
    }
    else
    {
        /* Configure the RX DMA channel - to receive data in receive buffer */
        rxDMAAddrMode = SYS_DMA_DESTINATION_ADDRESSING_MODE_INCREMENTED;

        /* Flush receive buffer data from cache to memory, in case there are
          changes to other locations within the cache line. */
        SYS_CACHE_CleanDCache_by_Addr(pReceiveData, size);
    }

    if (NULL == pTransmitData)
    {
        /* Configure the TX DMA channel - to send dummy data */
        pTransmitData = dummyDataTx;
    }
    else
    {
        /* Configure the transmit DMA channel - to send data from transmit buffer */
        txDMAAddrMode = SYS_DMA_SOURCE_ADDRESSING_MODE_INCREMENTED;

        /* Flush transmit data from cache to memory */
        SYS_CACHE_CleanDCache_by_Addr(pTransmitData, size);
    }

    if (rxDMAAddrMode != spiDcpt.rxDMAAddrMode)
    {
        SYS_DMA_AddressingModeSetup(spiDcpt.cfg.rxDMAChannel, SYS_DMA_SOURCE_ADDRESSING_MODE_FIXED, rxDMAAddrMode);
        spiDcpt.rxDMAAddrMode = rxDMAAddrMode;
    }
    (void)SYS_DMA_ChannelTransfer(spiDcpt.cfg.rxDMAChannel, (const void*)spiDcpt.cfg.rxAddress, pReceiveData, size);

    if (txDMAAddrMode != spiDcpt.txDMAAddrMode)
    {
        SYS_DMA_AddressingModeSetup(spiDcpt.cfg.txDMAChannel, txDMAAddrMode, SYS_DMA_DESTINATION_ADDRESSING_MODE_FIXED);
        spiDcpt.txDMAAddrMode = txDMAAddrMode;
    }
    (void)SYS_DMA_ChannelTransfer(spiDcpt.cfg.txDMAChannel, pTransmitData, (const void*)spiDcpt.cfg.txAddress, size);

    while (OSAL_RESULT_FALSE == OSAL_SEM_Pend(&spiDcpt.syncSem, OSAL_WAIT_FOREVER))
    {
    }

    if (SYS_DMA_DESTINATION_ADDRESSING_MODE_INCREMENTED == rxDMAAddrMode)
    {
        SYS_CACHE_InvalidateDCache_by_Addr(pReceiveData, size);
    }

#ifdef WDRV_WINC_SSN_Set
    WDRV_WINC_SSN_Set();
#endif

    return true;
}

//*******************************************************************************
/*
  Function:
    bool WDRV_WINC_SPIOpen(void)

  Summary:
    Opens the SPI object for the WiFi driver.

  Description:
    This function opens the SPI object for the WiFi driver.

  Remarks:
    See wdrv_winc_spi.h for usage information.
 */

bool WDRV_WINC_SPIOpen(void)
{
    if (false == spiDcpt.isInit)
    {
        return false;
    }

    if (true == spiDcpt.isOpen)
    {
        return true;
    }

    if (OSAL_RESULT_TRUE != OSAL_SEM_Create(&spiDcpt.syncSem, OSAL_SEM_TYPE_COUNTING, 10, 0))
    {
        return false;
    }

    SYS_DMA_DataWidthSetup(spiDcpt.cfg.rxDMAChannel, SYS_DMA_WIDTH_8_BIT);
    SYS_DMA_DataWidthSetup(spiDcpt.cfg.txDMAChannel, SYS_DMA_WIDTH_8_BIT);

    spiDcpt.txDMAAddrMode = SYS_DMA_SOURCE_ADDRESSING_MODE_NONE;
    spiDcpt.rxDMAAddrMode = SYS_DMA_DESTINATION_ADDRESSING_MODE_NONE;

    SYS_DMA_ChannelCallbackRegister(spiDcpt.cfg.rxDMAChannel, lDRV_SPI_PlibCallbackHandler, (uintptr_t)&spiDcpt.syncSem);

    spiDcpt.isOpen = true;

    return true;
}

//*******************************************************************************
/*
  Function:
    void WDRV_WINC_SPIInitialize(const WDRV_WINC_SPI_CFG *const pInitData)

  Summary:
    Initializes the SPI object for the WiFi driver.

  Description:
    This function initializes the SPI object for the WiFi driver.

  Remarks:
    See wdrv_winc_spi.h for usage information.
 */

void WDRV_WINC_SPIInitialize(const WDRV_WINC_SPI_CFG *const pInitData)
{
    if ((NULL == pInitData) || (true == spiDcpt.isInit))
    {
        return;
    }

    (void)memcpy(&spiDcpt.cfg, pInitData, sizeof(WDRV_WINC_SPI_CFG));
    (void)memset(dummyDataTx, 0xff, sizeof(dummyDataTx));

    SYS_CACHE_CleanDCache_by_Addr(dummyDataTx, sizeof(dummyDataTx));

    spiDcpt.isOpen = false;
    spiDcpt.isInit = true;
}

//*******************************************************************************
/*
  Function:
    void WDRV_WINC_SPIDeinitialize(void)

  Summary:
    Deinitializes the SPI object for the WiFi driver.

  Description:
    This function deinitializes the SPI object for the WiFi driver.

  Remarks:
    See wdrv_winc_spi.h for usage information.
 */

void WDRV_WINC_SPIDeinitialize(void)
{
    if (false == spiDcpt.isInit)
    {
        return;
    }

    (void)OSAL_SEM_Post(&spiDcpt.syncSem);
    (void)OSAL_SEM_Delete(&spiDcpt.syncSem);

    spiDcpt.isOpen = false;
    spiDcpt.isInit = false;
}

//DOM-IGNORE-END
