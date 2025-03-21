/*
 * Component description for SCKC
 *
 * Copyright (c) 2025 Microchip Technology Inc. and its subsidiaries.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

/*  file generated from device description file (ATDF) version 2024-06-25T17:22:56Z  */
#ifndef _SAM9X7_SCKC_COMPONENT_H_
#define _SAM9X7_SCKC_COMPONENT_H_

/* ************************************************************************** */
/*                      SOFTWARE API DEFINITION FOR SCKC                      */
/* ************************************************************************** */

/* -------- SCKC_CR : (SCKC Offset: 0x00) (R/W 32) Slow Clock Controller Configuration Register -------- */
#define SCKC_CR_RESETVALUE                    _UINT32_(0x01)                                       /*  (SCKC_CR) Slow Clock Controller Configuration Register  Reset Value */

#define SCKC_CR_OSC32EN_Pos                   _UINT32_(1)                                          /* (SCKC_CR) 32.768 kHz Crystal Oscillator Position */
#define SCKC_CR_OSC32EN_Msk                   (_UINT32_(0x1) << SCKC_CR_OSC32EN_Pos)               /* (SCKC_CR) 32.768 kHz Crystal Oscillator Mask */
#define SCKC_CR_OSC32EN(value)                (SCKC_CR_OSC32EN_Msk & (_UINT32_(value) << SCKC_CR_OSC32EN_Pos)) /* Assignment of value for OSC32EN in the SCKC_CR register */
#define   SCKC_CR_OSC32EN_0_Val               _UINT32_(0x0)                                        /* (SCKC_CR) 32.768 kHz crystal oscillator is disabled.  */
#define   SCKC_CR_OSC32EN_1_Val               _UINT32_(0x1)                                        /* (SCKC_CR) 32.768 kHz crystal oscillator is enabled.  */
#define SCKC_CR_OSC32EN_0                     (SCKC_CR_OSC32EN_0_Val << SCKC_CR_OSC32EN_Pos)       /* (SCKC_CR) 32.768 kHz crystal oscillator is disabled. Position */
#define SCKC_CR_OSC32EN_1                     (SCKC_CR_OSC32EN_1_Val << SCKC_CR_OSC32EN_Pos)       /* (SCKC_CR) 32.768 kHz crystal oscillator is enabled. Position */
#define SCKC_CR_OSC32BYP_Pos                  _UINT32_(2)                                          /* (SCKC_CR) 32.768 kHz Crystal Oscillator Bypass Position */
#define SCKC_CR_OSC32BYP_Msk                  (_UINT32_(0x1) << SCKC_CR_OSC32BYP_Pos)              /* (SCKC_CR) 32.768 kHz Crystal Oscillator Bypass Mask */
#define SCKC_CR_OSC32BYP(value)               (SCKC_CR_OSC32BYP_Msk & (_UINT32_(value) << SCKC_CR_OSC32BYP_Pos)) /* Assignment of value for OSC32BYP in the SCKC_CR register */
#define   SCKC_CR_OSC32BYP_0_Val              _UINT32_(0x0)                                        /* (SCKC_CR) 32.768 kHz crystal oscillator is not bypassed.  */
#define   SCKC_CR_OSC32BYP_1_Val              _UINT32_(0x1)                                        /* (SCKC_CR) 32.768 kHz crystal oscillator is bypassed and accepts an external slow clock on XIN32.  */
#define SCKC_CR_OSC32BYP_0                    (SCKC_CR_OSC32BYP_0_Val << SCKC_CR_OSC32BYP_Pos)     /* (SCKC_CR) 32.768 kHz crystal oscillator is not bypassed. Position */
#define SCKC_CR_OSC32BYP_1                    (SCKC_CR_OSC32BYP_1_Val << SCKC_CR_OSC32BYP_Pos)     /* (SCKC_CR) 32.768 kHz crystal oscillator is bypassed and accepts an external slow clock on XIN32. Position */
#define SCKC_CR_TD_OSCSEL_Pos                 _UINT32_(24)                                         /* (SCKC_CR) Timing Domain Slow Clock Selector Position */
#define SCKC_CR_TD_OSCSEL_Msk                 (_UINT32_(0x1) << SCKC_CR_TD_OSCSEL_Pos)             /* (SCKC_CR) Timing Domain Slow Clock Selector Mask */
#define SCKC_CR_TD_OSCSEL(value)              (SCKC_CR_TD_OSCSEL_Msk & (_UINT32_(value) << SCKC_CR_TD_OSCSEL_Pos)) /* Assignment of value for TD_OSCSEL in the SCKC_CR register */
#define   SCKC_CR_TD_OSCSEL_RC_Val            _UINT32_(0x0)                                        /* (SCKC_CR) Slow clock of the timing domain is driven by the embedded 32 kHz (typical) RC oscillator.  */
#define   SCKC_CR_TD_OSCSEL_XTAL_Val          _UINT32_(0x1)                                        /* (SCKC_CR) Slow clock of the timing domain is driven by the 32.768 kHz crystal oscillator.  */
#define SCKC_CR_TD_OSCSEL_RC                  (SCKC_CR_TD_OSCSEL_RC_Val << SCKC_CR_TD_OSCSEL_Pos)  /* (SCKC_CR) Slow clock of the timing domain is driven by the embedded 32 kHz (typical) RC oscillator. Position */
#define SCKC_CR_TD_OSCSEL_XTAL                (SCKC_CR_TD_OSCSEL_XTAL_Val << SCKC_CR_TD_OSCSEL_Pos) /* (SCKC_CR) Slow clock of the timing domain is driven by the 32.768 kHz crystal oscillator. Position */
#define SCKC_CR_Msk                           _UINT32_(0x01000006)                                 /* (SCKC_CR) Register Mask  */


/* SCKC register offsets definitions */
#define SCKC_CR_REG_OFST               _UINT32_(0x00)      /* (SCKC_CR) Slow Clock Controller Configuration Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/* SCKC register API structure */
typedef struct
{  /* Slow Clock Controller */
  __IO  uint32_t                       SCKC_CR;            /* Offset: 0x00 (R/W  32) Slow Clock Controller Configuration Register */
} sckc_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAM9X7_SCKC_COMPONENT_H_ */
