/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2021 Microchip Technology Inc. and its subsidiaries.
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

#include <app.h>


uint16_t adc_count;
float input_voltage;
int low_power_mode=0;
// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    
    printf("\n\r------------------------------------------------------------------------------");
    printf("\n\r  SAMA7D65 Low Power mode demonstarion - Default is an ADC application   ");
    printf("\n\r------------------------------------------------------------------------------\n\r");

    printf("\n\rFirst Press the User Button on the Curiosity board to enable mode selection \n\rThen Enter a number (1-6) to select a Low Power Mode: \n\r 1 for Backup mode \n\r 2 for BSR mode\n\r 3 for ULP1 mode\n\r 4 for ULP0 mode\n\r 5 for Idle mode\n\r 6 to test Backup mode\n\r 7 to test BSR mode\n\r");
  
    PIT64B0_TimerStart();

    while (1)
    {
        /* Start ADC conversion */
        ADC_ConversionStart();

        /* Wait till ADC conversion result is available */
        while(!ADC_ChannelResultIsReady(ADC_CH0))
        {

        };

        /* Read the ADC result */
        adc_count = ADC_ChannelResultGet(ADC_CH0);
        input_voltage = (float)adc_count * ADC_VREF / 4095U;
        
        if(!USER_BUTTON_Get())
        {scanf("%d",&low_power_mode);}
        
        PIT64B0_DelayMs(500);
        switch(low_power_mode)
        {
          case 1:
            printf("\n\r Entering Backup Mode. Press Wake-up switch to wake me");  
            enter_backup_mode();
            low_power_mode=0; 
            break;
          case 2:
            printf("\n\r Entering Backup Self-Refresh Mode. Press Wake-up switch to wake me"); 
            enter_bsr_mode();
            low_power_mode=0;
            break;
          case 3:
            printf("\n\r Entering ULP1 Mode, Will exit ULP1 mode in 15Seconds");
            /* Some portion of the code should be in SRAm while entering into UP1*/
            memcpy(&_sramcode, &_ramcode_lma, (uint32_t)&_eramcode - (uint32_t)&_sramcode);
	          memcpy(&_sramdata, &_ramdata_lma, (uint32_t)&_eramdata - (uint32_t)&_sramdata);
            enter_ulp1_mode();
            printf("Leaving ULP1 Mode\n\r");
            /* disable RTC alarm */
            RTC_InterruptDisable(RTC_INT_ALARM);
            low_power_mode=0;
            break;
          case 4:
            printf("\n\r Entering ULP0 Mode, Will exit ULP0 mode in 15Seconds");
            /* Some portion of the code should be in SRAm while entering into UP0*/
            memcpy(&_sramcode, &_ramcode_lma, (uint32_t)&_eramcode - (uint32_t)&_sramcode);
	          memcpy(&_sramdata, &_ramdata_lma, (uint32_t)&_eramdata - (uint32_t)&_sramdata);
            enter_ulp0_mode();
            printf("Leaving ULP0 Mode\n\r");
            /* disable RTC alarm */
            RTC_InterruptDisable(RTC_INT_ALARM);
            low_power_mode=0;
            break;
          case 5:
            printf("\n\r \n\rEntering Idle Mode. Press Wake-up switch to wake me");
            enter_idle_mode();
            low_power_mode=0;
            break;
          case 6:
            printf("\n\r \n\rTesting Backup Mode.");
            test_backup_mode();
            low_power_mode=0;
            break;
          case 7:
            printf("\n\r \n\rTesting Backup Self Refresh Mode.");
            test_bsr_mode();
            low_power_mode=0;
            break;
          default:
            printf("ADC Count = 0x%03x, ADC Input Voltage = %0.2f V \r",adc_count, input_voltage);
            break;  
        }
        
    }
    
    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}

void configure_wkup0_interrupt (void)
{
  __disable_irq();
  /*Wakeup Pin Interrupt Enable*/
  SHDWC_REGS->SHDW_IER = SHDW_IER_WKUP0_1;
  /*  Clear Interrupt*/
  SHDWC_REGS->SHDW_SR;
  SHDWC_REGS->SHDW_ISR;

  /* Enable WKPU0 as the wakup pin in shutdown controller */
  SHDWC_REGS->SHDW_MR = SHDW_MR_WKUPDBC(3);

  SHDWC_REGS->SHDW_WUIR = SHDW_WUIR_WKUPEN0_ENABLE  | SHDW_WUIR_WKUPT0_LOW ;
  __enable_irq();

  /*Wakeup Pin Interrupt Enable*/
  SHDWC_REGS->SHDW_IER = SHDW_IER_WKUP0_1;

}

void SHDWC_Handler (void);
void SHDWC_Handler (void)
{
  printf("\n\r Entered the shutdown handler \n\r");
  /*  Clear Interrupt*/
  SHDWC_REGS->SHDW_SR;
  SHDWC_REGS->SHDW_ISR;
  /*Disable Wake-up Interrupt*/
  SHDWC_REGS->SHDW_IDR = SHDW_IER_WKUP0_1;

}
