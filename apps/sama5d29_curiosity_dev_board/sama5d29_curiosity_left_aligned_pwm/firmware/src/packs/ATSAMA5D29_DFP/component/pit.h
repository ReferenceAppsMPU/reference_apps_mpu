/*
 * Component description for PIT
 *
 * Copyright (c) 2024 Microchip Technology Inc. and its subsidiaries.
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

/* file generated from device description file (ATDF) version 2024-06-24T14:43:55Z */
#ifndef _SAMA5D2_PIT_COMPONENT_H_
#define _SAMA5D2_PIT_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR PIT                                          */
/* ************************************************************************** */

/* -------- PIT_MR : (PIT Offset: 0x00) (R/W 32) Mode Register -------- */
#define PIT_MR_PIV_Pos                        _UINT32_(0)                                          /* (PIT_MR) Periodic Interval Value Position */
#define PIT_MR_PIV_Msk                        (_UINT32_(0xFFFFF) << PIT_MR_PIV_Pos)                /* (PIT_MR) Periodic Interval Value Mask */
#define PIT_MR_PIV(value)                     (PIT_MR_PIV_Msk & (_UINT32_(value) << PIT_MR_PIV_Pos)) /* Assigment of value for PIV in the PIT_MR register */
#define PIT_MR_PITEN_Pos                      _UINT32_(24)                                         /* (PIT_MR) Period Interval Timer Enabled Position */
#define PIT_MR_PITEN_Msk                      (_UINT32_(0x1) << PIT_MR_PITEN_Pos)                  /* (PIT_MR) Period Interval Timer Enabled Mask */
#define PIT_MR_PITEN(value)                   (PIT_MR_PITEN_Msk & (_UINT32_(value) << PIT_MR_PITEN_Pos)) /* Assigment of value for PITEN in the PIT_MR register */
#define PIT_MR_PITIEN_Pos                     _UINT32_(25)                                         /* (PIT_MR) Periodic Interval Timer Interrupt Enable Position */
#define PIT_MR_PITIEN_Msk                     (_UINT32_(0x1) << PIT_MR_PITIEN_Pos)                 /* (PIT_MR) Periodic Interval Timer Interrupt Enable Mask */
#define PIT_MR_PITIEN(value)                  (PIT_MR_PITIEN_Msk & (_UINT32_(value) << PIT_MR_PITIEN_Pos)) /* Assigment of value for PITIEN in the PIT_MR register */
#define PIT_MR_Msk                            _UINT32_(0x030FFFFF)                                 /* (PIT_MR) Register Mask  */


/* -------- PIT_SR : (PIT Offset: 0x04) ( R/ 32) Status Register -------- */
#define PIT_SR_PITS_Pos                       _UINT32_(0)                                          /* (PIT_SR) Periodic Interval Timer Status Position */
#define PIT_SR_PITS_Msk                       (_UINT32_(0x1) << PIT_SR_PITS_Pos)                   /* (PIT_SR) Periodic Interval Timer Status Mask */
#define PIT_SR_PITS(value)                    (PIT_SR_PITS_Msk & (_UINT32_(value) << PIT_SR_PITS_Pos)) /* Assigment of value for PITS in the PIT_SR register */
#define PIT_SR_Msk                            _UINT32_(0x00000001)                                 /* (PIT_SR) Register Mask  */


/* -------- PIT_PIVR : (PIT Offset: 0x08) ( R/ 32) Periodic Interval Value Register -------- */
#define PIT_PIVR_CPIV_Pos                     _UINT32_(0)                                          /* (PIT_PIVR) Current Periodic Interval Value Position */
#define PIT_PIVR_CPIV_Msk                     (_UINT32_(0xFFFFF) << PIT_PIVR_CPIV_Pos)             /* (PIT_PIVR) Current Periodic Interval Value Mask */
#define PIT_PIVR_CPIV(value)                  (PIT_PIVR_CPIV_Msk & (_UINT32_(value) << PIT_PIVR_CPIV_Pos)) /* Assigment of value for CPIV in the PIT_PIVR register */
#define PIT_PIVR_PICNT_Pos                    _UINT32_(20)                                         /* (PIT_PIVR) Periodic Interval Counter Position */
#define PIT_PIVR_PICNT_Msk                    (_UINT32_(0xFFF) << PIT_PIVR_PICNT_Pos)              /* (PIT_PIVR) Periodic Interval Counter Mask */
#define PIT_PIVR_PICNT(value)                 (PIT_PIVR_PICNT_Msk & (_UINT32_(value) << PIT_PIVR_PICNT_Pos)) /* Assigment of value for PICNT in the PIT_PIVR register */
#define PIT_PIVR_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (PIT_PIVR) Register Mask  */


/* -------- PIT_PIIR : (PIT Offset: 0x0C) ( R/ 32) Periodic Interval Image Register -------- */
#define PIT_PIIR_CPIV_Pos                     _UINT32_(0)                                          /* (PIT_PIIR) Current Periodic Interval Value Position */
#define PIT_PIIR_CPIV_Msk                     (_UINT32_(0xFFFFF) << PIT_PIIR_CPIV_Pos)             /* (PIT_PIIR) Current Periodic Interval Value Mask */
#define PIT_PIIR_CPIV(value)                  (PIT_PIIR_CPIV_Msk & (_UINT32_(value) << PIT_PIIR_CPIV_Pos)) /* Assigment of value for CPIV in the PIT_PIIR register */
#define PIT_PIIR_PICNT_Pos                    _UINT32_(20)                                         /* (PIT_PIIR) Periodic Interval Counter Position */
#define PIT_PIIR_PICNT_Msk                    (_UINT32_(0xFFF) << PIT_PIIR_PICNT_Pos)              /* (PIT_PIIR) Periodic Interval Counter Mask */
#define PIT_PIIR_PICNT(value)                 (PIT_PIIR_PICNT_Msk & (_UINT32_(value) << PIT_PIIR_PICNT_Pos)) /* Assigment of value for PICNT in the PIT_PIIR register */
#define PIT_PIIR_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (PIT_PIIR) Register Mask  */


/** \brief PIT register offsets definitions */
#define PIT_MR_REG_OFST                _UINT32_(0x00)      /* (PIT_MR) Mode Register Offset */
#define PIT_SR_REG_OFST                _UINT32_(0x04)      /* (PIT_SR) Status Register Offset */
#define PIT_PIVR_REG_OFST              _UINT32_(0x08)      /* (PIT_PIVR) Periodic Interval Value Register Offset */
#define PIT_PIIR_REG_OFST              _UINT32_(0x0C)      /* (PIT_PIIR) Periodic Interval Image Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief PIT register API structure */
typedef struct
{
  __IO  uint32_t                       PIT_MR;             /**< Offset: 0x00 (R/W  32) Mode Register */
  __I   uint32_t                       PIT_SR;             /**< Offset: 0x04 (R/   32) Status Register */
  __I   uint32_t                       PIT_PIVR;           /**< Offset: 0x08 (R/   32) Periodic Interval Value Register */
  __I   uint32_t                       PIT_PIIR;           /**< Offset: 0x0C (R/   32) Periodic Interval Image Register */
} pit_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAMA5D2_PIT_COMPONENT_H_ */
