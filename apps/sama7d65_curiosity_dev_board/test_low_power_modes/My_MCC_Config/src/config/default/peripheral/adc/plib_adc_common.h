/*******************************************************************************
  ADC Peripheral Library Interface Common Header File

  Company
    Microchip Technology Inc.

  File Name
    plib_adc_common.h

  Summary
    ADC peripheral library common interface.

  Description
    This file defines the common interface to the ADC peripheral library. This
    library provides access to and control of the associated peripheral
    instance.

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

#ifndef PLIB_ADC_COMMON_H    // Guards against multiple inclusion
#define PLIB_ADC_COMMON_H


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

/*  This section lists the other files that are included in this file.
*/

#include <stddef.h>
#include <stdbool.h>


// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif

// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************

/* Identifies ADC channel mask */
typedef enum
{
    ADC_CH0_MASK = (1U << 0U),
    ADC_CH1_MASK = (1U << 1U),
    ADC_CH2_MASK = (1U << 2U),
    ADC_CH3_MASK = (1U << 3U),
    ADC_CH4_MASK = (1U << 4U),
    ADC_CH5_MASK = (1U << 5U),
    ADC_CH6_MASK = (1U << 6U),
    ADC_CH7_MASK = (1U << 7U),
    ADC_CH8_MASK = (1U << 8U),
    ADC_CH9_MASK = (1U << 9U),
    ADC_CH10_MASK = (1U << 10U),
    ADC_CH11_MASK = (1U << 11U),
    ADC_CH12_MASK = (1U << 12U),
    ADC_CH13_MASK = (1U << 13U),
    ADC_CH14_MASK = (1U << 14U),
    ADC_CH15_MASK = (1U << 15U),
    ADC_CH30_MASK = (1U << 30U),
    ADC_CH31_MASK = (1U << 31U),
}ADC_CHANNEL_MASK;

/* Analog channel numbers */

#define     ADC_CH0   (0U)
#define     ADC_CH1   (1U)
#define     ADC_CH2   (2U)
#define     ADC_CH3   (3U)
#define     ADC_CH4   (4U)
#define     ADC_CH5   (5U)
#define     ADC_CH6   (6U)
#define     ADC_CH7   (7U)
#define     ADC_CH8   (8U)
#define     ADC_CH9   (9U)
#define     ADC_CH10   (10U)
#define     ADC_CH11   (11U)
#define     ADC_CH12   (12U)
#define     ADC_CH13   (13U)
#define     ADC_CH14   (14U)
#define     ADC_CH15   (15U)
#define     ADC_CH30  (30U)
#define     ADC_CH31  (31U)
typedef uint32_t ADC_CHANNEL_NUM;

/* EOC Interrupt sources number */
typedef enum
{
    ADC_INTERRUPT_EOC_0_MASK = (1U << 0U),
    ADC_INTERRUPT_EOC_1_MASK = (1U << 1U),
    ADC_INTERRUPT_EOC_2_MASK = (1U << 2U),
    ADC_INTERRUPT_EOC_3_MASK = (1U << 3U),
    ADC_INTERRUPT_EOC_4_MASK = (1U << 4U),
    ADC_INTERRUPT_EOC_5_MASK = (1U << 5U),
    ADC_INTERRUPT_EOC_6_MASK = (1U << 6U),
    ADC_INTERRUPT_EOC_7_MASK = (1U << 7U),
    ADC_INTERRUPT_EOC_8_MASK = (1U << 8U),
    ADC_INTERRUPT_EOC_9_MASK = (1U << 9U),
    ADC_INTERRUPT_EOC_10_MASK = (1U << 10U),
    ADC_INTERRUPT_EOC_11_MASK = (1U << 11U),
    ADC_INTERRUPT_EOC_12_MASK = (1U << 12U),
    ADC_INTERRUPT_EOC_13_MASK = (1U << 13U),
    ADC_INTERRUPT_EOC_14_MASK = (1U << 14U),
    ADC_INTERRUPT_EOC_15_MASK = (1U << 15U),
    ADC_INTERRUPT_EOC_30_MASK = (1U << 30U),
    ADC_INTERRUPT_EOC_31_MASK = (1U << 31U),
}ADC_INTERRUPT_EOC_MASK;

/* Interrupt sources number */
typedef enum
{
    ADC_INTERRUPT_RXRDY_MASK = ADC_ISR_RXRDY_Msk,
    ADC_INTERRUPT_RXEMPTY_MASK = ADC_ISR_RXEMPTY_Msk,
    ADC_INTERRUPT_RXFULL_MASK = ADC_ISR_RXFULL_Msk,
    ADC_INTERRUPT_RXCHUNK_MASK = ADC_ISR_RXCHUNK_Msk,
    ADC_INTERRUPT_RXUDR_MASK = ADC_ISR_RXUDR_Msk,
    ADC_INTERRUPT_RXOVR_MASK = ADC_ISR_RXOVR_Msk,
    ADC_INTERRUPT_EOS_MASK = ADC_ISR_EOS_Msk,
    ADC_INTERRUPT_TEMPCHG_MASK = ADC_ISR_TEMPCHG_Msk,
    ADC_INTERRUPT_DRDY_MASK = ADC_ISR_DRDY_Msk,
    ADC_INTERRUPT_GOVRE_MASK = ADC_ISR_GOVRE_Msk,
    ADC_INTERRUPT_COMPE_MASK = ADC_ISR_COMPE_Msk
}ADC_INTERRUPT_MASK;

/* Callback Function Pointer */
typedef void (*ADC_CALLBACK)(uint32_t interruptStatus, uint32_t eocInterruptStatus, uintptr_t context);

/* Callback structure */
typedef struct
{
    ADC_CALLBACK callback_fn;
    uintptr_t context;
}ADC_CALLBACK_OBJECT;

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

}

#endif
// DOM-IGNORE-END

#endif //PLIB_ADC_COMMMON_H

/**
 End of File
*/
