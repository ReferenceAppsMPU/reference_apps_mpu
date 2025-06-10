/*******************************************************************************
  System Initialization File

  File Name:
    initialization.c

  Summary:
    This file contains source code necessary to initialize the system.

  Description:
    This file contains source code necessary to initialize the system.  It
    implements the "SYS_Initialize" function, defines the configuration bits,
    and allocates any necessary global system resources,
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
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
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include "configuration.h"
#include "definitions.h"
#include "device.h"
#include "app_dsi.h"
#include "app_rnbd.h"

// ****************************************************************************
// ****************************************************************************
// Section: Configuration Bits
// ****************************************************************************
// ****************************************************************************



// *****************************************************************************
// *****************************************************************************
// Section: Driver Initialization Data
// *****************************************************************************
// *****************************************************************************
/* Following MISRA-C rules are deviated in the below code block */
/* MISRA C-2012 Rule 7.2 - Deviation record ID - H3_MISRAC_2012_R_7_2_DR_1 */
/* MISRA C-2012 Rule 11.1 - Deviation record ID - H3_MISRAC_2012_R_11_1_DR_1 */
/* MISRA C-2012 Rule 11.3 - Deviation record ID - H3_MISRAC_2012_R_11_3_DR_1 */
/* MISRA C-2012 Rule 11.8 - Deviation record ID - H3_MISRAC_2012_R_11_8_DR_1 */
// <editor-fold defaultstate="collapsed" desc="DRV_I2C Instance 0 Initialization Data">

/* I2C Client Objects Pool */
static DRV_I2C_CLIENT_OBJ drvI2C0ClientObjPool[DRV_I2C_CLIENTS_NUMBER_IDX0];

/* I2C Transfer Objects Pool */
static DRV_I2C_TRANSFER_OBJ drvI2C0TransferObj[DRV_I2C_QUEUE_SIZE_IDX0];

/* I2C PLib Interface Initialization */
static const DRV_I2C_PLIB_INTERFACE drvI2C0PLibAPI = {

    /* I2C PLib Transfer Read Add function */
    .read_t = (DRV_I2C_PLIB_READ)FLEXCOM6_TWI_Read,

    /* I2C PLib Transfer Write Add function */
    .write_t = (DRV_I2C_PLIB_WRITE)FLEXCOM6_TWI_Write,


    /* I2C PLib Transfer Write Read Add function */
    .writeRead = (DRV_I2C_PLIB_WRITE_READ)FLEXCOM6_TWI_WriteRead,

    /*I2C PLib Transfer Abort function */
    .transferAbort = (DRV_I2C_PLIB_TRANSFER_ABORT)FLEXCOM6_TWI_TransferAbort,

    /* I2C PLib Transfer Status function */
    .errorGet = (DRV_I2C_PLIB_ERROR_GET)FLEXCOM6_TWI_ErrorGet,

    /* I2C PLib Transfer Setup function */
    .transferSetup = (DRV_I2C_PLIB_TRANSFER_SETUP)FLEXCOM6_TWI_TransferSetup,

    /* I2C PLib Callback Register */
    .callbackRegister = (DRV_I2C_PLIB_CALLBACK_REGISTER)FLEXCOM6_TWI_CallbackRegister,
};


static const DRV_I2C_INTERRUPT_SOURCES drvI2C0InterruptSources =
{
    /* Peripheral has single interrupt vector */
    .isSingleIntSrc                        = true,

    /* Peripheral interrupt line */
    .intSources.i2cInterrupt             = (int32_t)FLEXCOM6_IRQn,
};

/* I2C Driver Initialization Data */
static const DRV_I2C_INIT drvI2C0InitData =
{
    /* I2C PLib API */
    .i2cPlib = &drvI2C0PLibAPI,

    /* I2C Number of clients */
    .numClients = DRV_I2C_CLIENTS_NUMBER_IDX0,

    /* I2C Client Objects Pool */
    .clientObjPool = (uintptr_t)&drvI2C0ClientObjPool[0],

    /* I2C TWI Queue Size */
    .transferObjPoolSize = DRV_I2C_QUEUE_SIZE_IDX0,

    /* I2C Transfer Objects */
    .transferObjPool = (uintptr_t)&drvI2C0TransferObj[0],

    /* I2C interrupt sources */
    .interruptSources = &drvI2C0InterruptSources,

    /* I2C Clock Speed */
    .clockSpeed = DRV_I2C_CLOCK_SPEED_IDX0,
};
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="DRV_I2C Instance 1 Initialization Data">

/* I2C Client Objects Pool */
static DRV_I2C_CLIENT_OBJ drvI2C1ClientObjPool[DRV_I2C_CLIENTS_NUMBER_IDX1];

/* I2C Transfer Objects Pool */
static DRV_I2C_TRANSFER_OBJ drvI2C1TransferObj[DRV_I2C_QUEUE_SIZE_IDX1];

/* I2C PLib Interface Initialization */
static const DRV_I2C_PLIB_INTERFACE drvI2C1PLibAPI = {

    /* I2C PLib Transfer Read Add function */
    .read_t = (DRV_I2C_PLIB_READ)FLEXCOM7_TWI_Read,

    /* I2C PLib Transfer Write Add function */
    .write_t = (DRV_I2C_PLIB_WRITE)FLEXCOM7_TWI_Write,


    /* I2C PLib Transfer Write Read Add function */
    .writeRead = (DRV_I2C_PLIB_WRITE_READ)FLEXCOM7_TWI_WriteRead,

    /*I2C PLib Transfer Abort function */
    .transferAbort = (DRV_I2C_PLIB_TRANSFER_ABORT)FLEXCOM7_TWI_TransferAbort,

    /* I2C PLib Transfer Status function */
    .errorGet = (DRV_I2C_PLIB_ERROR_GET)FLEXCOM7_TWI_ErrorGet,

    /* I2C PLib Transfer Setup function */
    .transferSetup = (DRV_I2C_PLIB_TRANSFER_SETUP)FLEXCOM7_TWI_TransferSetup,

    /* I2C PLib Callback Register */
    .callbackRegister = (DRV_I2C_PLIB_CALLBACK_REGISTER)FLEXCOM7_TWI_CallbackRegister,
};


static const DRV_I2C_INTERRUPT_SOURCES drvI2C1InterruptSources =
{
    /* Peripheral has single interrupt vector */
    .isSingleIntSrc                        = true,

    /* Peripheral interrupt line */
    .intSources.i2cInterrupt             = (int32_t)FLEXCOM7_IRQn,
};

/* I2C Driver Initialization Data */
static const DRV_I2C_INIT drvI2C1InitData =
{
    /* I2C PLib API */
    .i2cPlib = &drvI2C1PLibAPI,

    /* I2C Number of clients */
    .numClients = DRV_I2C_CLIENTS_NUMBER_IDX1,

    /* I2C Client Objects Pool */
    .clientObjPool = (uintptr_t)&drvI2C1ClientObjPool[0],

    /* I2C TWI Queue Size */
    .transferObjPoolSize = DRV_I2C_QUEUE_SIZE_IDX1,

    /* I2C Transfer Objects */
    .transferObjPool = (uintptr_t)&drvI2C1TransferObj[0],

    /* I2C interrupt sources */
    .interruptSources = &drvI2C1InterruptSources,

    /* I2C Clock Speed */
    .clockSpeed = DRV_I2C_CLOCK_SPEED_IDX1,
};
// </editor-fold>

static const WDRV_WINC_SPI_CFG wdrvWincSpiInitData =
{
    .txDMAChannel       = SYS_DMA_CHANNEL_0,
    .rxDMAChannel       = SYS_DMA_CHANNEL_1,
    .txAddress          = (void *)&(FLEXCOM4_REGS->FLEX_SPI_TDR),
    .rxAddress          = (void *)&(FLEXCOM4_REGS->FLEX_SPI_RDR),
};

static const WDRV_WINC_SYS_INIT wdrvWincInitData = {
    .pSPICfg    = &wdrvWincSpiInitData,
    .intSrc     = PIO_PIN_PC17
};




// *****************************************************************************
// *****************************************************************************
// Section: System Data
// *****************************************************************************
// *****************************************************************************
/* Structure to hold the object handles for the modules in the system. */
SYSTEM_OBJECTS sysObj;

// *****************************************************************************
// *****************************************************************************
// Section: Library/Stack Initialization Data
// *****************************************************************************
// *****************************************************************************


// *****************************************************************************
// *****************************************************************************
// Section: System Initialization
// *****************************************************************************
// *****************************************************************************
// <editor-fold defaultstate="collapsed" desc="SYS_TIME Initialization Data">

static const SYS_TIME_PLIB_INTERFACE sysTimePlibAPI = {
    .timerCallbackSet = (SYS_TIME_PLIB_CALLBACK_REGISTER)TC0_CH0_TimerCallbackRegister,
    .timerStart = (SYS_TIME_PLIB_START)TC0_CH0_TimerStart,
    .timerStop = (SYS_TIME_PLIB_STOP)TC0_CH0_TimerStop ,
    .timerFrequencyGet = (SYS_TIME_PLIB_FREQUENCY_GET)TC0_CH0_TimerFrequencyGet,
    .timerPeriodSet = (SYS_TIME_PLIB_PERIOD_SET)TC0_CH0_TimerPeriodSet,
    .timerCompareSet = (SYS_TIME_PLIB_COMPARE_SET)TC0_CH0_TimerCompareSet,
    .timerCounterGet = (SYS_TIME_PLIB_COUNTER_GET)TC0_CH0_TimerCounterGet,
};

static const SYS_TIME_INIT sysTimeInitData =
{
    .timePlib = &sysTimePlibAPI,
    .hwTimerIntNum = TC0_IRQn,
};

// </editor-fold>
// <editor-fold defaultstate="collapsed" desc="SYS_CONSOLE Instance 0 Initialization Data">


static const SYS_CONSOLE_UART_PLIB_INTERFACE sysConsole0UARTPlibAPI =
{
    .read_t = (SYS_CONSOLE_UART_PLIB_READ)DBGU_Read,
    .readCountGet = (SYS_CONSOLE_UART_PLIB_READ_COUNT_GET)DBGU_ReadCountGet,
    .readFreeBufferCountGet = (SYS_CONSOLE_UART_PLIB_READ_FREE_BUFFFER_COUNT_GET)DBGU_ReadFreeBufferCountGet,
    .write_t = (SYS_CONSOLE_UART_PLIB_WRITE)DBGU_Write,
    .writeCountGet = (SYS_CONSOLE_UART_PLIB_WRITE_COUNT_GET)DBGU_WriteCountGet,
    .writeFreeBufferCountGet = (SYS_CONSOLE_UART_PLIB_WRITE_FREE_BUFFER_COUNT_GET)DBGU_WriteFreeBufferCountGet,
};

static const SYS_CONSOLE_UART_INIT_DATA sysConsole0UARTInitData =
{
    .uartPLIB = &sysConsole0UARTPlibAPI,
};

static const SYS_CONSOLE_INIT sysConsole0Init =
{
    .deviceInitData = (const void*)&sysConsole0UARTInitData,
    .consDevDesc = &sysConsoleUARTDevDesc,
    .deviceIndex = 0,
};



// </editor-fold>


static const SYS_DEBUG_INIT debugInit =
{
    .moduleInit = {0},
    .errorLevel = SYS_DEBUG_GLOBAL_ERROR_LEVEL,
    .consoleIndex = 0,
};





// *****************************************************************************
// *****************************************************************************
// Section: Local initialization functions
// *****************************************************************************
// *****************************************************************************
/*******************************************************************************
  Function:
    void SYSC_Disable ( void )

  Summary:
    Disables ununsed SYSC peripherals

  Remarks:
 */
static void SYSC_Disable( void )
{
    //save context and disable write protection
    uint32_t sysc_wpmr = SYSCWP_REGS->SYSCWP_SYSC_WPMR &
      (SYSCWP_SYSC_WPMR_WPEN_Msk | SYSCWP_SYSC_WPMR_WPITEN_Msk);
    SYSCWP_REGS->SYSCWP_SYSC_WPMR = SYSCWP_SYSC_WPMR_WPKEY_PASSWD &
                                    ~(SYSCWP_SYSC_WPMR_WPITEN_Msk |
                                    SYSCWP_SYSC_WPMR_WPITEN_Msk);


    /* ----------------------------   RTT  -------------------------------*/
    //Disable Timer and interrupt
    uint32_t rtt_mr = RTT_REGS->RTT_MR;
    RTT_REGS->RTT_MR = rtt_mr & ~(RTT_MR_RTTDIS_Msk | RTT_MR_RTTINCIEN_Msk);

    //Clear status
    RTT_REGS->RTT_SR;

    /* ----------------------------   RSTC  ------------------------------*/
    // Disable interrupt
    uint32_t rstc_mr = RSTC_REGS->RSTC_MR & (RSTC_MR_ENGCLR_Msk |
                                             RSTC_MR_ERSTL_Msk |
                                             RSTC_MR_URSTIEN_Msk |
                                             RSTC_MR_URSTASYNC_Msk |
                                             RSTC_MR_SCKSW_Msk |
                                             RSTC_MR_URSTEN_Msk);
    rstc_mr = rstc_mr & (~RSTC_MR_URSTIEN_Msk);
    RSTC_REGS->RSTC_MR = RSTC_MR_KEY_PASSWD | rstc_mr;

    /* ----------------------------   PIT  -------------------------------*/
    //Disable Timer and interrupt
    uint32_t pit_mr = PIT_REGS->PIT_MR & PIT_MR_PIV_Msk;
    PIT_REGS->PIT_MR = pit_mr & ~(PIT_MR_PITEN_Msk | PIT_MR_PITIEN_Msk);

    //Clear status
    PIT_REGS->PIT_SR;

   //Context restore SYSC write protect registers
   SYSCWP_REGS->SYSCWP_SYSC_WPMR = (SYSCWP_SYSC_WPMR_WPKEY_PASSWD | sysc_wpmr);
}


/* MISRAC 2012 deviation block end */

/*******************************************************************************
  Function:
    void SYS_Initialize ( void *data )

  Summary:
    Initializes the board, services, drivers, application and other modules.

  Remarks:
 */

void SYS_Initialize ( void* data )
{

    /* MISRAC 2012 deviation block start */
    /* MISRA C-2012 Rule 2.2 deviated in this file.  Deviation record ID -  H3_MISRAC_2012_R_2_2_DR_1 */

	SYSC_Disable( );

  
    CLK_Initialize();

	PIO_Initialize();

    XDMAC_Initialize();



    FLEXCOM7_TWI_Initialize();

    FLEXCOM4_SPI_Initialize();

 
    TC0_CH0_TimerInitialize(); 
     
    
    FLEXCOM6_TWI_Initialize();

	RTC_Initialize();

    FLEXCOM1_USART_Initialize();

    XLCDC_Initialize();

    MMU_Initialize();

    AIC_INT_Initialize();
    
    /* Disable WDT   */
    WDT_REGS->WDT_MR = WDT_MR_WDDIS_Msk;

    DSI_Initialize();

	BSP_Initialize();
    DBGU_Initialize();


    /* MISRAC 2012 deviation block start */
    /* Following MISRA-C rules deviated in this block  */
    /* MISRA C-2012 Rule 11.3 - Deviation record ID - H3_MISRAC_2012_R_11_3_DR_1 */
    /* MISRA C-2012 Rule 11.8 - Deviation record ID - H3_MISRAC_2012_R_11_8_DR_1 */

    /* Initialize I2C0 Driver Instance */
    sysObj.drvI2C0 = DRV_I2C_Initialize(DRV_I2C_INDEX_0, (SYS_MODULE_INIT *)&drvI2C0InitData);

    /* Initialize I2C1 Driver Instance */
    sysObj.drvI2C1 = DRV_I2C_Initialize(DRV_I2C_INDEX_1, (SYS_MODULE_INIT *)&drvI2C1InitData);

    /* Initialize the WINC Driver */
    sysObj.drvWifiWinc = WDRV_WINC_Initialize(0, (SYS_MODULE_INIT*)&wdrvWincInitData);

    DRV_XLCDC_Initialize();

    DRV_GFX2D_Initialize();


    /* MISRA C-2012 Rule 11.3, 11.8 deviated below. Deviation record ID -  
    H3_MISRAC_2012_R_11_3_DR_1 & H3_MISRAC_2012_R_11_8_DR_1*/
        
    sysObj.sysTime = SYS_TIME_Initialize(SYS_TIME_INDEX_0, (SYS_MODULE_INIT *)&sysTimeInitData);
    
    /* MISRAC 2012 deviation block end */
    /* MISRA C-2012 Rule 11.3, 11.8 deviated below. Deviation record ID -  
     H3_MISRAC_2012_R_11_3_DR_1 & H3_MISRAC_2012_R_11_8_DR_1*/
        sysObj.sysConsole0 = SYS_CONSOLE_Initialize(SYS_CONSOLE_INDEX_0, (SYS_MODULE_INIT *)&sysConsole0Init);
   /* MISRAC 2012 deviation block end */
    /* MISRA C-2012 Rule 11.3, 11.8 deviated below. Deviation record ID -  
     H3_MISRAC_2012_R_11_3_DR_1 & H3_MISRAC_2012_R_11_8_DR_1*/
        
    sysObj.sysDebug = SYS_DEBUG_Initialize(SYS_DEBUG_INDEX_0, (SYS_MODULE_INIT*)&debugInit);

    /* MISRAC 2012 deviation block end */

    SYS_INP_Init();


    DISP_WS_Initialize();


    /* MISRAC 2012 deviation block end */
    APP_WINCS02_Initialize();


   APP_DSI_Initialize();
   
   APP_RNBD_Initialize();

    /* MISRAC 2012 deviation block end */
}

/*******************************************************************************
 End of File
*/
