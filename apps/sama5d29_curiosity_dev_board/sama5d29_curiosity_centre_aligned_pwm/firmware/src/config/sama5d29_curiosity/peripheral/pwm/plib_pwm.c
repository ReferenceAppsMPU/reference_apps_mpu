/*******************************************************************************
  PWM Peripheral Library Interface Source File

  Company
    Microchip Technology Inc.

  File Name
    plib_PWM.c

  Summary
    PWM peripheral library source file.

  Description
    This file implements the interface to the PWM peripheral library.  This
    library provides access to and control of the associated peripheral
    instance.

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

/*  This section lists the other files that are included in this file.
*/
#include "device.h"
#include "plib_pwm.h"
#include "interrupts.h"



/* Initialize enabled PWM channels */
void PWM_Initialize (void)
{
 

    /************** Channel 1 *************************/
    /* PWM channel mode configurations */
    PWM_REGS->PWM_CH_NUM[1].PWM_CMR = PWM_CMR_CPRE_MCK_DIV_2 | PWM_CMR_CALG_CENTER_ALIGNED
                    | PWM_CMR_CPOL_LOW_POLARITY | PWM_CMR_UPDS_UPDATE_AT_PERIOD \
                    | PWM_CMR_CES_SINGLE_EVENT | (PWM_CMR_DTE_Msk);

    /* PWM period */
    PWM_REGS->PWM_CH_NUM[1].PWM_CPRD = 20750U;

    /* PWM duty cycle */
    PWM_REGS->PWM_CH_NUM[1].PWM_CDTY = 7000U;
    /* Dead time */
    PWM_REGS->PWM_CH_NUM[1].PWM_DT = (100UL << PWM_DT_DTL_Pos) | (100U);
         
     
 
 
}

/* Start the PWM generation */
void PWM_ChannelsStart (PWM_CHANNEL_MASK channelMask)
{
    PWM_REGS->PWM_ENA = (uint32_t)channelMask;
}

/* Stop the PWM generation */
void PWM_ChannelsStop (PWM_CHANNEL_MASK channelMask)
{
    PWM_REGS->PWM_DIS = (uint32_t)channelMask;
}

/* configure PWM period */
void PWM_ChannelPeriodSet (PWM_CHANNEL_NUM channel, uint16_t period)
{
    PWM_REGS->PWM_CH_NUM[channel].PWM_CPRDUPD = period;
}

/* Read PWM period */
uint16_t PWM_ChannelPeriodGet (PWM_CHANNEL_NUM channel)
{
    return (uint16_t)PWM_REGS->PWM_CH_NUM[channel].PWM_CPRD;
}

/* Configure dead time */
void PWM_ChannelDeadTimeSet (PWM_CHANNEL_NUM channel, uint16_t deadtime_high, uint16_t deadtime_low)
{
    PWM_REGS->PWM_CH_NUM[channel].PWM_DTUPD = (((uint32_t)deadtime_low << PWM_DT_DTL_Pos) | deadtime_high);
}

/* Configure compare unit value */
void PWM_CompareValueSet (PWM_COMPARE cmp_unit, uint16_t cmp_value)
{
    PWM_REGS->PWM_CMP[cmp_unit].PWM_CMPVUPD = cmp_value;
}

/* Enable counter event */
void PWM_ChannelCounterEventEnable (PWM_CHANNEL_MASK channelMask)
{
    PWM_REGS->PWM_IER1 = (uint32_t)channelMask;
}

/* Disable counter event */
void PWM_ChannelCounterEventDisable (PWM_CHANNEL_MASK channelMask)
{
    PWM_REGS->PWM_IDR1 = (uint32_t)channelMask;
}


/* Enable synchronous update */
void PWM_SyncUpdateEnable (void)
{
    PWM_REGS->PWM_SCUC = PWM_SCUC_UPDULOCK_Msk;
}

/* Clear the fault status */
void PWM_FaultStatusClear(PWM_FAULT_ID fault_id)
{
    PWM_REGS->PWM_FCR = 0x1UL << (uint32_t)fault_id;
}

/* Override PWM outputs */
void PWM_ChannelOverrideEnable(PWM_CHANNEL_NUM channel)
{
    PWM_REGS->PWM_OS &= ~((1UL << (uint32_t)channel) | (1UL << ((uint32_t)channel + 16U)));

}

/* Disable override of PWM outputs */
void PWM_ChannelOverrideDisable(PWM_CHANNEL_NUM channel)
{
    PWM_REGS->PWM_OS |= ((1UL << (uint32_t)channel) | (1UL << ((uint32_t)channel + 16U)));
}


/* Check the status of counter event */
bool PWM_ChannelCounterEventStatusGet (PWM_CHANNEL_NUM channel)
{
    bool pwm_status;
    pwm_status = (bool)(((PWM_REGS->PWM_ISR1 >> (uint32_t)channel) & 0x1U) != 0U);
    return pwm_status;
}

/**
 End of File
*/
