/*
 * Component description for PMERRLOC
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
#ifndef _SAM9X7_PMERRLOC_COMPONENT_H_
#define _SAM9X7_PMERRLOC_COMPONENT_H_

/* ************************************************************************** */
/*                    SOFTWARE API DEFINITION FOR PMERRLOC                    */
/* ************************************************************************** */

/* -------- PMERRLOC_ELCFG : (PMERRLOC Offset: 0x00) (R/W 32) Configuration Register -------- */
#define PMERRLOC_ELCFG_RESETVALUE             _UINT32_(0x00)                                       /*  (PMERRLOC_ELCFG) Configuration Register  Reset Value */

#define PMERRLOC_ELCFG_SECTORSZ_Pos           _UINT32_(0)                                          /* (PMERRLOC_ELCFG) Sector Size Position */
#define PMERRLOC_ELCFG_SECTORSZ_Msk           (_UINT32_(0x1) << PMERRLOC_ELCFG_SECTORSZ_Pos)       /* (PMERRLOC_ELCFG) Sector Size Mask */
#define PMERRLOC_ELCFG_SECTORSZ(value)        (PMERRLOC_ELCFG_SECTORSZ_Msk & (_UINT32_(value) << PMERRLOC_ELCFG_SECTORSZ_Pos)) /* Assignment of value for SECTORSZ in the PMERRLOC_ELCFG register */
#define   PMERRLOC_ELCFG_SECTORSZ_0_Val       _UINT32_(0x0)                                        /* (PMERRLOC_ELCFG) The ECC computation is based on a 512-byte sector.  */
#define   PMERRLOC_ELCFG_SECTORSZ_1_Val       _UINT32_(0x1)                                        /* (PMERRLOC_ELCFG) The ECC computation is based on a 1024-byte sector.  */
#define PMERRLOC_ELCFG_SECTORSZ_0             (PMERRLOC_ELCFG_SECTORSZ_0_Val << PMERRLOC_ELCFG_SECTORSZ_Pos) /* (PMERRLOC_ELCFG) The ECC computation is based on a 512-byte sector. Position */
#define PMERRLOC_ELCFG_SECTORSZ_1             (PMERRLOC_ELCFG_SECTORSZ_1_Val << PMERRLOC_ELCFG_SECTORSZ_Pos) /* (PMERRLOC_ELCFG) The ECC computation is based on a 1024-byte sector. Position */
#define PMERRLOC_ELCFG_ERRNUM_Pos             _UINT32_(16)                                         /* (PMERRLOC_ELCFG) Number of Errors Position */
#define PMERRLOC_ELCFG_ERRNUM_Msk             (_UINT32_(0x1F) << PMERRLOC_ELCFG_ERRNUM_Pos)        /* (PMERRLOC_ELCFG) Number of Errors Mask */
#define PMERRLOC_ELCFG_ERRNUM(value)          (PMERRLOC_ELCFG_ERRNUM_Msk & (_UINT32_(value) << PMERRLOC_ELCFG_ERRNUM_Pos)) /* Assignment of value for ERRNUM in the PMERRLOC_ELCFG register */
#define PMERRLOC_ELCFG_Msk                    _UINT32_(0x001F0001)                                 /* (PMERRLOC_ELCFG) Register Mask  */


/* -------- PMERRLOC_ELPRIM : (PMERRLOC Offset: 0x04) ( R/ 32) Primitive Register -------- */
#define PMERRLOC_ELPRIM_RESETVALUE            _UINT32_(0x00)                                       /*  (PMERRLOC_ELPRIM) Primitive Register  Reset Value */

#define PMERRLOC_ELPRIM_PRIMITIV_Pos          _UINT32_(0)                                          /* (PMERRLOC_ELPRIM) Primitive Polynomial Position */
#define PMERRLOC_ELPRIM_PRIMITIV_Msk          (_UINT32_(0xFFFF) << PMERRLOC_ELPRIM_PRIMITIV_Pos)   /* (PMERRLOC_ELPRIM) Primitive Polynomial Mask */
#define PMERRLOC_ELPRIM_PRIMITIV(value)       (PMERRLOC_ELPRIM_PRIMITIV_Msk & (_UINT32_(value) << PMERRLOC_ELPRIM_PRIMITIV_Pos)) /* Assignment of value for PRIMITIV in the PMERRLOC_ELPRIM register */
#define PMERRLOC_ELPRIM_Msk                   _UINT32_(0x0000FFFF)                                 /* (PMERRLOC_ELPRIM) Register Mask  */


/* -------- PMERRLOC_ELEN : (PMERRLOC Offset: 0x08) (R/W 32) Enable Register -------- */
#define PMERRLOC_ELEN_RESETVALUE              _UINT32_(0x00)                                       /*  (PMERRLOC_ELEN) Enable Register  Reset Value */

#define PMERRLOC_ELEN_ENINIT_Pos              _UINT32_(0)                                          /* (PMERRLOC_ELEN) Initial Number of Bits in the Codeword Position */
#define PMERRLOC_ELEN_ENINIT_Msk              (_UINT32_(0x3FFF) << PMERRLOC_ELEN_ENINIT_Pos)       /* (PMERRLOC_ELEN) Initial Number of Bits in the Codeword Mask */
#define PMERRLOC_ELEN_ENINIT(value)           (PMERRLOC_ELEN_ENINIT_Msk & (_UINT32_(value) << PMERRLOC_ELEN_ENINIT_Pos)) /* Assignment of value for ENINIT in the PMERRLOC_ELEN register */
#define PMERRLOC_ELEN_Msk                     _UINT32_(0x00003FFF)                                 /* (PMERRLOC_ELEN) Register Mask  */


/* -------- PMERRLOC_ELDIS : (PMERRLOC Offset: 0x0C) (R/W 32) Disable Register -------- */
#define PMERRLOC_ELDIS_RESETVALUE             _UINT32_(0x00)                                       /*  (PMERRLOC_ELDIS) Disable Register  Reset Value */

#define PMERRLOC_ELDIS_DIS_Pos                _UINT32_(0)                                          /* (PMERRLOC_ELDIS) Disable Error Location Engine Position */
#define PMERRLOC_ELDIS_DIS_Msk                (_UINT32_(0x1) << PMERRLOC_ELDIS_DIS_Pos)            /* (PMERRLOC_ELDIS) Disable Error Location Engine Mask */
#define PMERRLOC_ELDIS_DIS(value)             (PMERRLOC_ELDIS_DIS_Msk & (_UINT32_(value) << PMERRLOC_ELDIS_DIS_Pos)) /* Assignment of value for DIS in the PMERRLOC_ELDIS register */
#define PMERRLOC_ELDIS_Msk                    _UINT32_(0x00000001)                                 /* (PMERRLOC_ELDIS) Register Mask  */


/* -------- PMERRLOC_ELSR : (PMERRLOC Offset: 0x10) (R/W 32) Status Register -------- */
#define PMERRLOC_ELSR_RESETVALUE              _UINT32_(0x00)                                       /*  (PMERRLOC_ELSR) Status Register  Reset Value */

#define PMERRLOC_ELSR_BUSY_Pos                _UINT32_(0)                                          /* (PMERRLOC_ELSR) Error Location Engine Busy Position */
#define PMERRLOC_ELSR_BUSY_Msk                (_UINT32_(0x1) << PMERRLOC_ELSR_BUSY_Pos)            /* (PMERRLOC_ELSR) Error Location Engine Busy Mask */
#define PMERRLOC_ELSR_BUSY(value)             (PMERRLOC_ELSR_BUSY_Msk & (_UINT32_(value) << PMERRLOC_ELSR_BUSY_Pos)) /* Assignment of value for BUSY in the PMERRLOC_ELSR register */
#define PMERRLOC_ELSR_Msk                     _UINT32_(0x00000001)                                 /* (PMERRLOC_ELSR) Register Mask  */


/* -------- PMERRLOC_ELIER : (PMERRLOC Offset: 0x14) ( /W 32) Interrupt Enable Register -------- */
#define PMERRLOC_ELIER_RESETVALUE             _UINT32_(0x00)                                       /*  (PMERRLOC_ELIER) Interrupt Enable Register  Reset Value */

#define PMERRLOC_ELIER_DONE_Pos               _UINT32_(0)                                          /* (PMERRLOC_ELIER) Computation Terminated Interrupt Enable Position */
#define PMERRLOC_ELIER_DONE_Msk               (_UINT32_(0x1) << PMERRLOC_ELIER_DONE_Pos)           /* (PMERRLOC_ELIER) Computation Terminated Interrupt Enable Mask */
#define PMERRLOC_ELIER_DONE(value)            (PMERRLOC_ELIER_DONE_Msk & (_UINT32_(value) << PMERRLOC_ELIER_DONE_Pos)) /* Assignment of value for DONE in the PMERRLOC_ELIER register */
#define PMERRLOC_ELIER_Msk                    _UINT32_(0x00000001)                                 /* (PMERRLOC_ELIER) Register Mask  */


/* -------- PMERRLOC_ELIDR : (PMERRLOC Offset: 0x18) ( /W 32) Interrupt Disable Register -------- */
#define PMERRLOC_ELIDR_RESETVALUE             _UINT32_(0x00)                                       /*  (PMERRLOC_ELIDR) Interrupt Disable Register  Reset Value */

#define PMERRLOC_ELIDR_DONE_Pos               _UINT32_(0)                                          /* (PMERRLOC_ELIDR) Computation Terminated Interrupt Disable Position */
#define PMERRLOC_ELIDR_DONE_Msk               (_UINT32_(0x1) << PMERRLOC_ELIDR_DONE_Pos)           /* (PMERRLOC_ELIDR) Computation Terminated Interrupt Disable Mask */
#define PMERRLOC_ELIDR_DONE(value)            (PMERRLOC_ELIDR_DONE_Msk & (_UINT32_(value) << PMERRLOC_ELIDR_DONE_Pos)) /* Assignment of value for DONE in the PMERRLOC_ELIDR register */
#define PMERRLOC_ELIDR_Msk                    _UINT32_(0x00000001)                                 /* (PMERRLOC_ELIDR) Register Mask  */


/* -------- PMERRLOC_ELIMR : (PMERRLOC Offset: 0x1C) ( R/ 32) Interrupt Mask Register -------- */
#define PMERRLOC_ELIMR_RESETVALUE             _UINT32_(0x00)                                       /*  (PMERRLOC_ELIMR) Interrupt Mask Register  Reset Value */

#define PMERRLOC_ELIMR_DONE_Pos               _UINT32_(0)                                          /* (PMERRLOC_ELIMR) Computation Terminated Interrupt Mask Position */
#define PMERRLOC_ELIMR_DONE_Msk               (_UINT32_(0x1) << PMERRLOC_ELIMR_DONE_Pos)           /* (PMERRLOC_ELIMR) Computation Terminated Interrupt Mask Mask */
#define PMERRLOC_ELIMR_DONE(value)            (PMERRLOC_ELIMR_DONE_Msk & (_UINT32_(value) << PMERRLOC_ELIMR_DONE_Pos)) /* Assignment of value for DONE in the PMERRLOC_ELIMR register */
#define PMERRLOC_ELIMR_Msk                    _UINT32_(0x00000001)                                 /* (PMERRLOC_ELIMR) Register Mask  */


/* -------- PMERRLOC_ELISR : (PMERRLOC Offset: 0x20) ( R/ 32) Interrupt Status Register -------- */
#define PMERRLOC_ELISR_RESETVALUE             _UINT32_(0x00)                                       /*  (PMERRLOC_ELISR) Interrupt Status Register  Reset Value */

#define PMERRLOC_ELISR_DONE_Pos               _UINT32_(0)                                          /* (PMERRLOC_ELISR) Computation Terminated Interrupt Status Position */
#define PMERRLOC_ELISR_DONE_Msk               (_UINT32_(0x1) << PMERRLOC_ELISR_DONE_Pos)           /* (PMERRLOC_ELISR) Computation Terminated Interrupt Status Mask */
#define PMERRLOC_ELISR_DONE(value)            (PMERRLOC_ELISR_DONE_Msk & (_UINT32_(value) << PMERRLOC_ELISR_DONE_Pos)) /* Assignment of value for DONE in the PMERRLOC_ELISR register */
#define PMERRLOC_ELISR_ERR_CNT_Pos            _UINT32_(8)                                          /* (PMERRLOC_ELISR) Error Counter Value Position */
#define PMERRLOC_ELISR_ERR_CNT_Msk            (_UINT32_(0x1F) << PMERRLOC_ELISR_ERR_CNT_Pos)       /* (PMERRLOC_ELISR) Error Counter Value Mask */
#define PMERRLOC_ELISR_ERR_CNT(value)         (PMERRLOC_ELISR_ERR_CNT_Msk & (_UINT32_(value) << PMERRLOC_ELISR_ERR_CNT_Pos)) /* Assignment of value for ERR_CNT in the PMERRLOC_ELISR register */
#define PMERRLOC_ELISR_Msk                    _UINT32_(0x00001F01)                                 /* (PMERRLOC_ELISR) Register Mask  */


/* -------- PMERRLOC_SIGMA0 : (PMERRLOC Offset: 0x28) ( R/ 32) SIGMA0 Register -------- */
#define PMERRLOC_SIGMA0_RESETVALUE            _UINT32_(0x01)                                       /*  (PMERRLOC_SIGMA0) SIGMA0 Register  Reset Value */

#define PMERRLOC_SIGMA0_SIGMA_Pos             _UINT32_(0)                                          /* (PMERRLOC_SIGMA0) Coefficient of Degree 0 in the SIGMA Polynomial Position */
#define PMERRLOC_SIGMA0_SIGMA_Msk             (_UINT32_(0x3FFF) << PMERRLOC_SIGMA0_SIGMA_Pos)      /* (PMERRLOC_SIGMA0) Coefficient of Degree 0 in the SIGMA Polynomial Mask */
#define PMERRLOC_SIGMA0_SIGMA(value)          (PMERRLOC_SIGMA0_SIGMA_Msk & (_UINT32_(value) << PMERRLOC_SIGMA0_SIGMA_Pos)) /* Assignment of value for SIGMA in the PMERRLOC_SIGMA0 register */
#define PMERRLOC_SIGMA0_Msk                   _UINT32_(0x00003FFF)                                 /* (PMERRLOC_SIGMA0) Register Mask  */


/* -------- PMERRLOC_SIGMA1 : (PMERRLOC Offset: 0x2C) (R/W 32) SIGMA1 Register -------- */
#define PMERRLOC_SIGMA1_RESETVALUE            _UINT32_(0x00)                                       /*  (PMERRLOC_SIGMA1) SIGMA1 Register  Reset Value */

#define PMERRLOC_SIGMA1_SIGMA_Pos             _UINT32_(0)                                          /* (PMERRLOC_SIGMA1) Coefficient of Degree x in the SIGMA Polynomial. Position */
#define PMERRLOC_SIGMA1_SIGMA_Msk             (_UINT32_(0x3FFF) << PMERRLOC_SIGMA1_SIGMA_Pos)      /* (PMERRLOC_SIGMA1) Coefficient of Degree x in the SIGMA Polynomial. Mask */
#define PMERRLOC_SIGMA1_SIGMA(value)          (PMERRLOC_SIGMA1_SIGMA_Msk & (_UINT32_(value) << PMERRLOC_SIGMA1_SIGMA_Pos)) /* Assignment of value for SIGMA in the PMERRLOC_SIGMA1 register */
#define PMERRLOC_SIGMA1_Msk                   _UINT32_(0x00003FFF)                                 /* (PMERRLOC_SIGMA1) Register Mask  */


/* -------- PMERRLOC_SIGMA2 : (PMERRLOC Offset: 0x30) (R/W 32) SIGMA2 Register -------- */
#define PMERRLOC_SIGMA2_RESETVALUE            _UINT32_(0x00)                                       /*  (PMERRLOC_SIGMA2) SIGMA2 Register  Reset Value */

#define PMERRLOC_SIGMA2_SIGMA_Pos             _UINT32_(0)                                          /* (PMERRLOC_SIGMA2) Coefficient of Degree x in the SIGMA Polynomial. Position */
#define PMERRLOC_SIGMA2_SIGMA_Msk             (_UINT32_(0x3FFF) << PMERRLOC_SIGMA2_SIGMA_Pos)      /* (PMERRLOC_SIGMA2) Coefficient of Degree x in the SIGMA Polynomial. Mask */
#define PMERRLOC_SIGMA2_SIGMA(value)          (PMERRLOC_SIGMA2_SIGMA_Msk & (_UINT32_(value) << PMERRLOC_SIGMA2_SIGMA_Pos)) /* Assignment of value for SIGMA in the PMERRLOC_SIGMA2 register */
#define PMERRLOC_SIGMA2_Msk                   _UINT32_(0x00003FFF)                                 /* (PMERRLOC_SIGMA2) Register Mask  */


/* -------- PMERRLOC_SIGMA3 : (PMERRLOC Offset: 0x34) (R/W 32) SIGMA3 Register -------- */
#define PMERRLOC_SIGMA3_RESETVALUE            _UINT32_(0x00)                                       /*  (PMERRLOC_SIGMA3) SIGMA3 Register  Reset Value */

#define PMERRLOC_SIGMA3_SIGMA_Pos             _UINT32_(0)                                          /* (PMERRLOC_SIGMA3) Coefficient of Degree x in the SIGMA Polynomial. Position */
#define PMERRLOC_SIGMA3_SIGMA_Msk             (_UINT32_(0x3FFF) << PMERRLOC_SIGMA3_SIGMA_Pos)      /* (PMERRLOC_SIGMA3) Coefficient of Degree x in the SIGMA Polynomial. Mask */
#define PMERRLOC_SIGMA3_SIGMA(value)          (PMERRLOC_SIGMA3_SIGMA_Msk & (_UINT32_(value) << PMERRLOC_SIGMA3_SIGMA_Pos)) /* Assignment of value for SIGMA in the PMERRLOC_SIGMA3 register */
#define PMERRLOC_SIGMA3_Msk                   _UINT32_(0x00003FFF)                                 /* (PMERRLOC_SIGMA3) Register Mask  */


/* -------- PMERRLOC_SIGMA4 : (PMERRLOC Offset: 0x38) (R/W 32) SIGMA4 Register -------- */
#define PMERRLOC_SIGMA4_RESETVALUE            _UINT32_(0x00)                                       /*  (PMERRLOC_SIGMA4) SIGMA4 Register  Reset Value */

#define PMERRLOC_SIGMA4_SIGMA_Pos             _UINT32_(0)                                          /* (PMERRLOC_SIGMA4) Coefficient of Degree x in the SIGMA Polynomial. Position */
#define PMERRLOC_SIGMA4_SIGMA_Msk             (_UINT32_(0x3FFF) << PMERRLOC_SIGMA4_SIGMA_Pos)      /* (PMERRLOC_SIGMA4) Coefficient of Degree x in the SIGMA Polynomial. Mask */
#define PMERRLOC_SIGMA4_SIGMA(value)          (PMERRLOC_SIGMA4_SIGMA_Msk & (_UINT32_(value) << PMERRLOC_SIGMA4_SIGMA_Pos)) /* Assignment of value for SIGMA in the PMERRLOC_SIGMA4 register */
#define PMERRLOC_SIGMA4_Msk                   _UINT32_(0x00003FFF)                                 /* (PMERRLOC_SIGMA4) Register Mask  */


/* -------- PMERRLOC_SIGMA5 : (PMERRLOC Offset: 0x3C) (R/W 32) SIGMA5 Register -------- */
#define PMERRLOC_SIGMA5_RESETVALUE            _UINT32_(0x00)                                       /*  (PMERRLOC_SIGMA5) SIGMA5 Register  Reset Value */

#define PMERRLOC_SIGMA5_SIGMA_Pos             _UINT32_(0)                                          /* (PMERRLOC_SIGMA5) Coefficient of Degree x in the SIGMA Polynomial. Position */
#define PMERRLOC_SIGMA5_SIGMA_Msk             (_UINT32_(0x3FFF) << PMERRLOC_SIGMA5_SIGMA_Pos)      /* (PMERRLOC_SIGMA5) Coefficient of Degree x in the SIGMA Polynomial. Mask */
#define PMERRLOC_SIGMA5_SIGMA(value)          (PMERRLOC_SIGMA5_SIGMA_Msk & (_UINT32_(value) << PMERRLOC_SIGMA5_SIGMA_Pos)) /* Assignment of value for SIGMA in the PMERRLOC_SIGMA5 register */
#define PMERRLOC_SIGMA5_Msk                   _UINT32_(0x00003FFF)                                 /* (PMERRLOC_SIGMA5) Register Mask  */


/* -------- PMERRLOC_SIGMA6 : (PMERRLOC Offset: 0x40) (R/W 32) SIGMA6 Register -------- */
#define PMERRLOC_SIGMA6_RESETVALUE            _UINT32_(0x00)                                       /*  (PMERRLOC_SIGMA6) SIGMA6 Register  Reset Value */

#define PMERRLOC_SIGMA6_SIGMA_Pos             _UINT32_(0)                                          /* (PMERRLOC_SIGMA6) Coefficient of Degree x in the SIGMA Polynomial. Position */
#define PMERRLOC_SIGMA6_SIGMA_Msk             (_UINT32_(0x3FFF) << PMERRLOC_SIGMA6_SIGMA_Pos)      /* (PMERRLOC_SIGMA6) Coefficient of Degree x in the SIGMA Polynomial. Mask */
#define PMERRLOC_SIGMA6_SIGMA(value)          (PMERRLOC_SIGMA6_SIGMA_Msk & (_UINT32_(value) << PMERRLOC_SIGMA6_SIGMA_Pos)) /* Assignment of value for SIGMA in the PMERRLOC_SIGMA6 register */
#define PMERRLOC_SIGMA6_Msk                   _UINT32_(0x00003FFF)                                 /* (PMERRLOC_SIGMA6) Register Mask  */


/* -------- PMERRLOC_SIGMA7 : (PMERRLOC Offset: 0x44) (R/W 32) SIGMA7 Register -------- */
#define PMERRLOC_SIGMA7_RESETVALUE            _UINT32_(0x00)                                       /*  (PMERRLOC_SIGMA7) SIGMA7 Register  Reset Value */

#define PMERRLOC_SIGMA7_SIGMA_Pos             _UINT32_(0)                                          /* (PMERRLOC_SIGMA7) Coefficient of Degree x in the SIGMA Polynomial. Position */
#define PMERRLOC_SIGMA7_SIGMA_Msk             (_UINT32_(0x3FFF) << PMERRLOC_SIGMA7_SIGMA_Pos)      /* (PMERRLOC_SIGMA7) Coefficient of Degree x in the SIGMA Polynomial. Mask */
#define PMERRLOC_SIGMA7_SIGMA(value)          (PMERRLOC_SIGMA7_SIGMA_Msk & (_UINT32_(value) << PMERRLOC_SIGMA7_SIGMA_Pos)) /* Assignment of value for SIGMA in the PMERRLOC_SIGMA7 register */
#define PMERRLOC_SIGMA7_Msk                   _UINT32_(0x00003FFF)                                 /* (PMERRLOC_SIGMA7) Register Mask  */


/* -------- PMERRLOC_SIGMA8 : (PMERRLOC Offset: 0x48) (R/W 32) SIGMA8 Register -------- */
#define PMERRLOC_SIGMA8_RESETVALUE            _UINT32_(0x00)                                       /*  (PMERRLOC_SIGMA8) SIGMA8 Register  Reset Value */

#define PMERRLOC_SIGMA8_SIGMA_Pos             _UINT32_(0)                                          /* (PMERRLOC_SIGMA8) Coefficient of Degree x in the SIGMA Polynomial. Position */
#define PMERRLOC_SIGMA8_SIGMA_Msk             (_UINT32_(0x3FFF) << PMERRLOC_SIGMA8_SIGMA_Pos)      /* (PMERRLOC_SIGMA8) Coefficient of Degree x in the SIGMA Polynomial. Mask */
#define PMERRLOC_SIGMA8_SIGMA(value)          (PMERRLOC_SIGMA8_SIGMA_Msk & (_UINT32_(value) << PMERRLOC_SIGMA8_SIGMA_Pos)) /* Assignment of value for SIGMA in the PMERRLOC_SIGMA8 register */
#define PMERRLOC_SIGMA8_Msk                   _UINT32_(0x00003FFF)                                 /* (PMERRLOC_SIGMA8) Register Mask  */


/* -------- PMERRLOC_SIGMA9 : (PMERRLOC Offset: 0x4C) (R/W 32) SIGMA9 Register -------- */
#define PMERRLOC_SIGMA9_RESETVALUE            _UINT32_(0x00)                                       /*  (PMERRLOC_SIGMA9) SIGMA9 Register  Reset Value */

#define PMERRLOC_SIGMA9_SIGMA_Pos             _UINT32_(0)                                          /* (PMERRLOC_SIGMA9) Coefficient of Degree x in the SIGMA Polynomial. Position */
#define PMERRLOC_SIGMA9_SIGMA_Msk             (_UINT32_(0x3FFF) << PMERRLOC_SIGMA9_SIGMA_Pos)      /* (PMERRLOC_SIGMA9) Coefficient of Degree x in the SIGMA Polynomial. Mask */
#define PMERRLOC_SIGMA9_SIGMA(value)          (PMERRLOC_SIGMA9_SIGMA_Msk & (_UINT32_(value) << PMERRLOC_SIGMA9_SIGMA_Pos)) /* Assignment of value for SIGMA in the PMERRLOC_SIGMA9 register */
#define PMERRLOC_SIGMA9_Msk                   _UINT32_(0x00003FFF)                                 /* (PMERRLOC_SIGMA9) Register Mask  */


/* -------- PMERRLOC_SIGMA10 : (PMERRLOC Offset: 0x50) (R/W 32) SIGMA10 Register -------- */
#define PMERRLOC_SIGMA10_RESETVALUE           _UINT32_(0x00)                                       /*  (PMERRLOC_SIGMA10) SIGMA10 Register  Reset Value */

#define PMERRLOC_SIGMA10_SIGMA_Pos            _UINT32_(0)                                          /* (PMERRLOC_SIGMA10) Coefficient of Degree x in the SIGMA Polynomial. Position */
#define PMERRLOC_SIGMA10_SIGMA_Msk            (_UINT32_(0x3FFF) << PMERRLOC_SIGMA10_SIGMA_Pos)     /* (PMERRLOC_SIGMA10) Coefficient of Degree x in the SIGMA Polynomial. Mask */
#define PMERRLOC_SIGMA10_SIGMA(value)         (PMERRLOC_SIGMA10_SIGMA_Msk & (_UINT32_(value) << PMERRLOC_SIGMA10_SIGMA_Pos)) /* Assignment of value for SIGMA in the PMERRLOC_SIGMA10 register */
#define PMERRLOC_SIGMA10_Msk                  _UINT32_(0x00003FFF)                                 /* (PMERRLOC_SIGMA10) Register Mask  */


/* -------- PMERRLOC_SIGMA11 : (PMERRLOC Offset: 0x54) (R/W 32) SIGMA11 Register -------- */
#define PMERRLOC_SIGMA11_RESETVALUE           _UINT32_(0x00)                                       /*  (PMERRLOC_SIGMA11) SIGMA11 Register  Reset Value */

#define PMERRLOC_SIGMA11_SIGMA_Pos            _UINT32_(0)                                          /* (PMERRLOC_SIGMA11) Coefficient of Degree x in the SIGMA Polynomial. Position */
#define PMERRLOC_SIGMA11_SIGMA_Msk            (_UINT32_(0x3FFF) << PMERRLOC_SIGMA11_SIGMA_Pos)     /* (PMERRLOC_SIGMA11) Coefficient of Degree x in the SIGMA Polynomial. Mask */
#define PMERRLOC_SIGMA11_SIGMA(value)         (PMERRLOC_SIGMA11_SIGMA_Msk & (_UINT32_(value) << PMERRLOC_SIGMA11_SIGMA_Pos)) /* Assignment of value for SIGMA in the PMERRLOC_SIGMA11 register */
#define PMERRLOC_SIGMA11_Msk                  _UINT32_(0x00003FFF)                                 /* (PMERRLOC_SIGMA11) Register Mask  */


/* -------- PMERRLOC_SIGMA12 : (PMERRLOC Offset: 0x58) (R/W 32) SIGMA12 Register -------- */
#define PMERRLOC_SIGMA12_RESETVALUE           _UINT32_(0x00)                                       /*  (PMERRLOC_SIGMA12) SIGMA12 Register  Reset Value */

#define PMERRLOC_SIGMA12_SIGMA_Pos            _UINT32_(0)                                          /* (PMERRLOC_SIGMA12) Coefficient of Degree x in the SIGMA Polynomial. Position */
#define PMERRLOC_SIGMA12_SIGMA_Msk            (_UINT32_(0x3FFF) << PMERRLOC_SIGMA12_SIGMA_Pos)     /* (PMERRLOC_SIGMA12) Coefficient of Degree x in the SIGMA Polynomial. Mask */
#define PMERRLOC_SIGMA12_SIGMA(value)         (PMERRLOC_SIGMA12_SIGMA_Msk & (_UINT32_(value) << PMERRLOC_SIGMA12_SIGMA_Pos)) /* Assignment of value for SIGMA in the PMERRLOC_SIGMA12 register */
#define PMERRLOC_SIGMA12_Msk                  _UINT32_(0x00003FFF)                                 /* (PMERRLOC_SIGMA12) Register Mask  */


/* -------- PMERRLOC_SIGMA13 : (PMERRLOC Offset: 0x5C) (R/W 32) SIGMA13 Register -------- */
#define PMERRLOC_SIGMA13_RESETVALUE           _UINT32_(0x00)                                       /*  (PMERRLOC_SIGMA13) SIGMA13 Register  Reset Value */

#define PMERRLOC_SIGMA13_SIGMA_Pos            _UINT32_(0)                                          /* (PMERRLOC_SIGMA13) Coefficient of Degree x in the SIGMA Polynomial. Position */
#define PMERRLOC_SIGMA13_SIGMA_Msk            (_UINT32_(0x3FFF) << PMERRLOC_SIGMA13_SIGMA_Pos)     /* (PMERRLOC_SIGMA13) Coefficient of Degree x in the SIGMA Polynomial. Mask */
#define PMERRLOC_SIGMA13_SIGMA(value)         (PMERRLOC_SIGMA13_SIGMA_Msk & (_UINT32_(value) << PMERRLOC_SIGMA13_SIGMA_Pos)) /* Assignment of value for SIGMA in the PMERRLOC_SIGMA13 register */
#define PMERRLOC_SIGMA13_Msk                  _UINT32_(0x00003FFF)                                 /* (PMERRLOC_SIGMA13) Register Mask  */


/* -------- PMERRLOC_SIGMA14 : (PMERRLOC Offset: 0x60) (R/W 32) SIGMA14 Register -------- */
#define PMERRLOC_SIGMA14_RESETVALUE           _UINT32_(0x00)                                       /*  (PMERRLOC_SIGMA14) SIGMA14 Register  Reset Value */

#define PMERRLOC_SIGMA14_SIGMA_Pos            _UINT32_(0)                                          /* (PMERRLOC_SIGMA14) Coefficient of Degree x in the SIGMA Polynomial. Position */
#define PMERRLOC_SIGMA14_SIGMA_Msk            (_UINT32_(0x3FFF) << PMERRLOC_SIGMA14_SIGMA_Pos)     /* (PMERRLOC_SIGMA14) Coefficient of Degree x in the SIGMA Polynomial. Mask */
#define PMERRLOC_SIGMA14_SIGMA(value)         (PMERRLOC_SIGMA14_SIGMA_Msk & (_UINT32_(value) << PMERRLOC_SIGMA14_SIGMA_Pos)) /* Assignment of value for SIGMA in the PMERRLOC_SIGMA14 register */
#define PMERRLOC_SIGMA14_Msk                  _UINT32_(0x00003FFF)                                 /* (PMERRLOC_SIGMA14) Register Mask  */


/* -------- PMERRLOC_SIGMA15 : (PMERRLOC Offset: 0x64) (R/W 32) SIGMA15 Register -------- */
#define PMERRLOC_SIGMA15_RESETVALUE           _UINT32_(0x00)                                       /*  (PMERRLOC_SIGMA15) SIGMA15 Register  Reset Value */

#define PMERRLOC_SIGMA15_SIGMA_Pos            _UINT32_(0)                                          /* (PMERRLOC_SIGMA15) Coefficient of Degree x in the SIGMA Polynomial. Position */
#define PMERRLOC_SIGMA15_SIGMA_Msk            (_UINT32_(0x3FFF) << PMERRLOC_SIGMA15_SIGMA_Pos)     /* (PMERRLOC_SIGMA15) Coefficient of Degree x in the SIGMA Polynomial. Mask */
#define PMERRLOC_SIGMA15_SIGMA(value)         (PMERRLOC_SIGMA15_SIGMA_Msk & (_UINT32_(value) << PMERRLOC_SIGMA15_SIGMA_Pos)) /* Assignment of value for SIGMA in the PMERRLOC_SIGMA15 register */
#define PMERRLOC_SIGMA15_Msk                  _UINT32_(0x00003FFF)                                 /* (PMERRLOC_SIGMA15) Register Mask  */


/* -------- PMERRLOC_SIGMA16 : (PMERRLOC Offset: 0x68) (R/W 32) SIGMA16 Register -------- */
#define PMERRLOC_SIGMA16_RESETVALUE           _UINT32_(0x00)                                       /*  (PMERRLOC_SIGMA16) SIGMA16 Register  Reset Value */

#define PMERRLOC_SIGMA16_SIGMA_Pos            _UINT32_(0)                                          /* (PMERRLOC_SIGMA16) Coefficient of Degree x in the SIGMA Polynomial. Position */
#define PMERRLOC_SIGMA16_SIGMA_Msk            (_UINT32_(0x3FFF) << PMERRLOC_SIGMA16_SIGMA_Pos)     /* (PMERRLOC_SIGMA16) Coefficient of Degree x in the SIGMA Polynomial. Mask */
#define PMERRLOC_SIGMA16_SIGMA(value)         (PMERRLOC_SIGMA16_SIGMA_Msk & (_UINT32_(value) << PMERRLOC_SIGMA16_SIGMA_Pos)) /* Assignment of value for SIGMA in the PMERRLOC_SIGMA16 register */
#define PMERRLOC_SIGMA16_Msk                  _UINT32_(0x00003FFF)                                 /* (PMERRLOC_SIGMA16) Register Mask  */


/* -------- PMERRLOC_SIGMA17 : (PMERRLOC Offset: 0x6C) (R/W 32) SIGMA17 Register -------- */
#define PMERRLOC_SIGMA17_RESETVALUE           _UINT32_(0x00)                                       /*  (PMERRLOC_SIGMA17) SIGMA17 Register  Reset Value */

#define PMERRLOC_SIGMA17_SIGMA_Pos            _UINT32_(0)                                          /* (PMERRLOC_SIGMA17) Coefficient of Degree x in the SIGMA Polynomial. Position */
#define PMERRLOC_SIGMA17_SIGMA_Msk            (_UINT32_(0x3FFF) << PMERRLOC_SIGMA17_SIGMA_Pos)     /* (PMERRLOC_SIGMA17) Coefficient of Degree x in the SIGMA Polynomial. Mask */
#define PMERRLOC_SIGMA17_SIGMA(value)         (PMERRLOC_SIGMA17_SIGMA_Msk & (_UINT32_(value) << PMERRLOC_SIGMA17_SIGMA_Pos)) /* Assignment of value for SIGMA in the PMERRLOC_SIGMA17 register */
#define PMERRLOC_SIGMA17_Msk                  _UINT32_(0x00003FFF)                                 /* (PMERRLOC_SIGMA17) Register Mask  */


/* -------- PMERRLOC_SIGMA18 : (PMERRLOC Offset: 0x70) (R/W 32) SIGMA18 Register -------- */
#define PMERRLOC_SIGMA18_RESETVALUE           _UINT32_(0x00)                                       /*  (PMERRLOC_SIGMA18) SIGMA18 Register  Reset Value */

#define PMERRLOC_SIGMA18_SIGMA_Pos            _UINT32_(0)                                          /* (PMERRLOC_SIGMA18) Coefficient of Degree x in the SIGMA Polynomial. Position */
#define PMERRLOC_SIGMA18_SIGMA_Msk            (_UINT32_(0x3FFF) << PMERRLOC_SIGMA18_SIGMA_Pos)     /* (PMERRLOC_SIGMA18) Coefficient of Degree x in the SIGMA Polynomial. Mask */
#define PMERRLOC_SIGMA18_SIGMA(value)         (PMERRLOC_SIGMA18_SIGMA_Msk & (_UINT32_(value) << PMERRLOC_SIGMA18_SIGMA_Pos)) /* Assignment of value for SIGMA in the PMERRLOC_SIGMA18 register */
#define PMERRLOC_SIGMA18_Msk                  _UINT32_(0x00003FFF)                                 /* (PMERRLOC_SIGMA18) Register Mask  */


/* -------- PMERRLOC_SIGMA19 : (PMERRLOC Offset: 0x74) (R/W 32) SIGMA19 Register -------- */
#define PMERRLOC_SIGMA19_RESETVALUE           _UINT32_(0x00)                                       /*  (PMERRLOC_SIGMA19) SIGMA19 Register  Reset Value */

#define PMERRLOC_SIGMA19_SIGMA_Pos            _UINT32_(0)                                          /* (PMERRLOC_SIGMA19) Coefficient of Degree x in the SIGMA Polynomial. Position */
#define PMERRLOC_SIGMA19_SIGMA_Msk            (_UINT32_(0x3FFF) << PMERRLOC_SIGMA19_SIGMA_Pos)     /* (PMERRLOC_SIGMA19) Coefficient of Degree x in the SIGMA Polynomial. Mask */
#define PMERRLOC_SIGMA19_SIGMA(value)         (PMERRLOC_SIGMA19_SIGMA_Msk & (_UINT32_(value) << PMERRLOC_SIGMA19_SIGMA_Pos)) /* Assignment of value for SIGMA in the PMERRLOC_SIGMA19 register */
#define PMERRLOC_SIGMA19_Msk                  _UINT32_(0x00003FFF)                                 /* (PMERRLOC_SIGMA19) Register Mask  */


/* -------- PMERRLOC_SIGMA20 : (PMERRLOC Offset: 0x78) (R/W 32) SIGMA20 Register -------- */
#define PMERRLOC_SIGMA20_RESETVALUE           _UINT32_(0x00)                                       /*  (PMERRLOC_SIGMA20) SIGMA20 Register  Reset Value */

#define PMERRLOC_SIGMA20_SIGMA_Pos            _UINT32_(0)                                          /* (PMERRLOC_SIGMA20) Coefficient of Degree x in the SIGMA Polynomial. Position */
#define PMERRLOC_SIGMA20_SIGMA_Msk            (_UINT32_(0x3FFF) << PMERRLOC_SIGMA20_SIGMA_Pos)     /* (PMERRLOC_SIGMA20) Coefficient of Degree x in the SIGMA Polynomial. Mask */
#define PMERRLOC_SIGMA20_SIGMA(value)         (PMERRLOC_SIGMA20_SIGMA_Msk & (_UINT32_(value) << PMERRLOC_SIGMA20_SIGMA_Pos)) /* Assignment of value for SIGMA in the PMERRLOC_SIGMA20 register */
#define PMERRLOC_SIGMA20_Msk                  _UINT32_(0x00003FFF)                                 /* (PMERRLOC_SIGMA20) Register Mask  */


/* -------- PMERRLOC_SIGMA21 : (PMERRLOC Offset: 0x7C) (R/W 32) SIGMA21 Register -------- */
#define PMERRLOC_SIGMA21_RESETVALUE           _UINT32_(0x00)                                       /*  (PMERRLOC_SIGMA21) SIGMA21 Register  Reset Value */

#define PMERRLOC_SIGMA21_SIGMA_Pos            _UINT32_(0)                                          /* (PMERRLOC_SIGMA21) Coefficient of Degree x in the SIGMA Polynomial. Position */
#define PMERRLOC_SIGMA21_SIGMA_Msk            (_UINT32_(0x3FFF) << PMERRLOC_SIGMA21_SIGMA_Pos)     /* (PMERRLOC_SIGMA21) Coefficient of Degree x in the SIGMA Polynomial. Mask */
#define PMERRLOC_SIGMA21_SIGMA(value)         (PMERRLOC_SIGMA21_SIGMA_Msk & (_UINT32_(value) << PMERRLOC_SIGMA21_SIGMA_Pos)) /* Assignment of value for SIGMA in the PMERRLOC_SIGMA21 register */
#define PMERRLOC_SIGMA21_Msk                  _UINT32_(0x00003FFF)                                 /* (PMERRLOC_SIGMA21) Register Mask  */


/* -------- PMERRLOC_SIGMA22 : (PMERRLOC Offset: 0x80) (R/W 32) SIGMA22 Register -------- */
#define PMERRLOC_SIGMA22_RESETVALUE           _UINT32_(0x00)                                       /*  (PMERRLOC_SIGMA22) SIGMA22 Register  Reset Value */

#define PMERRLOC_SIGMA22_SIGMA_Pos            _UINT32_(0)                                          /* (PMERRLOC_SIGMA22) Coefficient of Degree x in the SIGMA Polynomial. Position */
#define PMERRLOC_SIGMA22_SIGMA_Msk            (_UINT32_(0x3FFF) << PMERRLOC_SIGMA22_SIGMA_Pos)     /* (PMERRLOC_SIGMA22) Coefficient of Degree x in the SIGMA Polynomial. Mask */
#define PMERRLOC_SIGMA22_SIGMA(value)         (PMERRLOC_SIGMA22_SIGMA_Msk & (_UINT32_(value) << PMERRLOC_SIGMA22_SIGMA_Pos)) /* Assignment of value for SIGMA in the PMERRLOC_SIGMA22 register */
#define PMERRLOC_SIGMA22_Msk                  _UINT32_(0x00003FFF)                                 /* (PMERRLOC_SIGMA22) Register Mask  */


/* -------- PMERRLOC_SIGMA23 : (PMERRLOC Offset: 0x84) (R/W 32) SIGMA23 Register -------- */
#define PMERRLOC_SIGMA23_RESETVALUE           _UINT32_(0x00)                                       /*  (PMERRLOC_SIGMA23) SIGMA23 Register  Reset Value */

#define PMERRLOC_SIGMA23_SIGMA_Pos            _UINT32_(0)                                          /* (PMERRLOC_SIGMA23) Coefficient of Degree x in the SIGMA Polynomial. Position */
#define PMERRLOC_SIGMA23_SIGMA_Msk            (_UINT32_(0x3FFF) << PMERRLOC_SIGMA23_SIGMA_Pos)     /* (PMERRLOC_SIGMA23) Coefficient of Degree x in the SIGMA Polynomial. Mask */
#define PMERRLOC_SIGMA23_SIGMA(value)         (PMERRLOC_SIGMA23_SIGMA_Msk & (_UINT32_(value) << PMERRLOC_SIGMA23_SIGMA_Pos)) /* Assignment of value for SIGMA in the PMERRLOC_SIGMA23 register */
#define PMERRLOC_SIGMA23_Msk                  _UINT32_(0x00003FFF)                                 /* (PMERRLOC_SIGMA23) Register Mask  */


/* -------- PMERRLOC_SIGMA24 : (PMERRLOC Offset: 0x88) (R/W 32) SIGMA24 Register -------- */
#define PMERRLOC_SIGMA24_RESETVALUE           _UINT32_(0x00)                                       /*  (PMERRLOC_SIGMA24) SIGMA24 Register  Reset Value */

#define PMERRLOC_SIGMA24_SIGMA_Pos            _UINT32_(0)                                          /* (PMERRLOC_SIGMA24) Coefficient of Degree x in the SIGMA Polynomial. Position */
#define PMERRLOC_SIGMA24_SIGMA_Msk            (_UINT32_(0x3FFF) << PMERRLOC_SIGMA24_SIGMA_Pos)     /* (PMERRLOC_SIGMA24) Coefficient of Degree x in the SIGMA Polynomial. Mask */
#define PMERRLOC_SIGMA24_SIGMA(value)         (PMERRLOC_SIGMA24_SIGMA_Msk & (_UINT32_(value) << PMERRLOC_SIGMA24_SIGMA_Pos)) /* Assignment of value for SIGMA in the PMERRLOC_SIGMA24 register */
#define PMERRLOC_SIGMA24_Msk                  _UINT32_(0x00003FFF)                                 /* (PMERRLOC_SIGMA24) Register Mask  */


/* -------- PMERRLOC_EL : (PMERRLOC Offset: 0x8C) ( R/ 32) Error Location x Register -------- */
#define PMERRLOC_EL_RESETVALUE                _UINT32_(0x00)                                       /*  (PMERRLOC_EL) Error Location x Register  Reset Value */

#define PMERRLOC_EL_ERRLOCN_Pos               _UINT32_(0)                                          /* (PMERRLOC_EL) Error Position within the Set {sector area, spare area}. Position */
#define PMERRLOC_EL_ERRLOCN_Msk               (_UINT32_(0x3FFF) << PMERRLOC_EL_ERRLOCN_Pos)        /* (PMERRLOC_EL) Error Position within the Set {sector area, spare area}. Mask */
#define PMERRLOC_EL_ERRLOCN(value)            (PMERRLOC_EL_ERRLOCN_Msk & (_UINT32_(value) << PMERRLOC_EL_ERRLOCN_Pos)) /* Assignment of value for ERRLOCN in the PMERRLOC_EL register */
#define PMERRLOC_EL_Msk                       _UINT32_(0x00003FFF)                                 /* (PMERRLOC_EL) Register Mask  */


/* PMERRLOC register offsets definitions */
#define PMERRLOC_ELCFG_REG_OFST        _UINT32_(0x00)      /* (PMERRLOC_ELCFG) Configuration Register Offset */
#define PMERRLOC_ELPRIM_REG_OFST       _UINT32_(0x04)      /* (PMERRLOC_ELPRIM) Primitive Register Offset */
#define PMERRLOC_ELEN_REG_OFST         _UINT32_(0x08)      /* (PMERRLOC_ELEN) Enable Register Offset */
#define PMERRLOC_ELDIS_REG_OFST        _UINT32_(0x0C)      /* (PMERRLOC_ELDIS) Disable Register Offset */
#define PMERRLOC_ELSR_REG_OFST         _UINT32_(0x10)      /* (PMERRLOC_ELSR) Status Register Offset */
#define PMERRLOC_ELIER_REG_OFST        _UINT32_(0x14)      /* (PMERRLOC_ELIER) Interrupt Enable Register Offset */
#define PMERRLOC_ELIDR_REG_OFST        _UINT32_(0x18)      /* (PMERRLOC_ELIDR) Interrupt Disable Register Offset */
#define PMERRLOC_ELIMR_REG_OFST        _UINT32_(0x1C)      /* (PMERRLOC_ELIMR) Interrupt Mask Register Offset */
#define PMERRLOC_ELISR_REG_OFST        _UINT32_(0x20)      /* (PMERRLOC_ELISR) Interrupt Status Register Offset */
#define PMERRLOC_SIGMA0_REG_OFST       _UINT32_(0x28)      /* (PMERRLOC_SIGMA0) SIGMA0 Register Offset */
#define PMERRLOC_SIGMA1_REG_OFST       _UINT32_(0x2C)      /* (PMERRLOC_SIGMA1) SIGMA1 Register Offset */
#define PMERRLOC_SIGMA2_REG_OFST       _UINT32_(0x30)      /* (PMERRLOC_SIGMA2) SIGMA2 Register Offset */
#define PMERRLOC_SIGMA3_REG_OFST       _UINT32_(0x34)      /* (PMERRLOC_SIGMA3) SIGMA3 Register Offset */
#define PMERRLOC_SIGMA4_REG_OFST       _UINT32_(0x38)      /* (PMERRLOC_SIGMA4) SIGMA4 Register Offset */
#define PMERRLOC_SIGMA5_REG_OFST       _UINT32_(0x3C)      /* (PMERRLOC_SIGMA5) SIGMA5 Register Offset */
#define PMERRLOC_SIGMA6_REG_OFST       _UINT32_(0x40)      /* (PMERRLOC_SIGMA6) SIGMA6 Register Offset */
#define PMERRLOC_SIGMA7_REG_OFST       _UINT32_(0x44)      /* (PMERRLOC_SIGMA7) SIGMA7 Register Offset */
#define PMERRLOC_SIGMA8_REG_OFST       _UINT32_(0x48)      /* (PMERRLOC_SIGMA8) SIGMA8 Register Offset */
#define PMERRLOC_SIGMA9_REG_OFST       _UINT32_(0x4C)      /* (PMERRLOC_SIGMA9) SIGMA9 Register Offset */
#define PMERRLOC_SIGMA10_REG_OFST      _UINT32_(0x50)      /* (PMERRLOC_SIGMA10) SIGMA10 Register Offset */
#define PMERRLOC_SIGMA11_REG_OFST      _UINT32_(0x54)      /* (PMERRLOC_SIGMA11) SIGMA11 Register Offset */
#define PMERRLOC_SIGMA12_REG_OFST      _UINT32_(0x58)      /* (PMERRLOC_SIGMA12) SIGMA12 Register Offset */
#define PMERRLOC_SIGMA13_REG_OFST      _UINT32_(0x5C)      /* (PMERRLOC_SIGMA13) SIGMA13 Register Offset */
#define PMERRLOC_SIGMA14_REG_OFST      _UINT32_(0x60)      /* (PMERRLOC_SIGMA14) SIGMA14 Register Offset */
#define PMERRLOC_SIGMA15_REG_OFST      _UINT32_(0x64)      /* (PMERRLOC_SIGMA15) SIGMA15 Register Offset */
#define PMERRLOC_SIGMA16_REG_OFST      _UINT32_(0x68)      /* (PMERRLOC_SIGMA16) SIGMA16 Register Offset */
#define PMERRLOC_SIGMA17_REG_OFST      _UINT32_(0x6C)      /* (PMERRLOC_SIGMA17) SIGMA17 Register Offset */
#define PMERRLOC_SIGMA18_REG_OFST      _UINT32_(0x70)      /* (PMERRLOC_SIGMA18) SIGMA18 Register Offset */
#define PMERRLOC_SIGMA19_REG_OFST      _UINT32_(0x74)      /* (PMERRLOC_SIGMA19) SIGMA19 Register Offset */
#define PMERRLOC_SIGMA20_REG_OFST      _UINT32_(0x78)      /* (PMERRLOC_SIGMA20) SIGMA20 Register Offset */
#define PMERRLOC_SIGMA21_REG_OFST      _UINT32_(0x7C)      /* (PMERRLOC_SIGMA21) SIGMA21 Register Offset */
#define PMERRLOC_SIGMA22_REG_OFST      _UINT32_(0x80)      /* (PMERRLOC_SIGMA22) SIGMA22 Register Offset */
#define PMERRLOC_SIGMA23_REG_OFST      _UINT32_(0x84)      /* (PMERRLOC_SIGMA23) SIGMA23 Register Offset */
#define PMERRLOC_SIGMA24_REG_OFST      _UINT32_(0x88)      /* (PMERRLOC_SIGMA24) SIGMA24 Register Offset */
#define PMERRLOC_EL_REG_OFST           _UINT32_(0x8C)      /* (PMERRLOC_EL) Error Location x Register Offset */
#define PMERRLOC_EL0_REG_OFST          _UINT32_(0x8C)      /* (PMERRLOC_EL0) Error Location x Register Offset */
#define PMERRLOC_EL1_REG_OFST          _UINT32_(0x90)      /* (PMERRLOC_EL1) Error Location x Register Offset */
#define PMERRLOC_EL2_REG_OFST          _UINT32_(0x94)      /* (PMERRLOC_EL2) Error Location x Register Offset */
#define PMERRLOC_EL3_REG_OFST          _UINT32_(0x98)      /* (PMERRLOC_EL3) Error Location x Register Offset */
#define PMERRLOC_EL4_REG_OFST          _UINT32_(0x9C)      /* (PMERRLOC_EL4) Error Location x Register Offset */
#define PMERRLOC_EL5_REG_OFST          _UINT32_(0xA0)      /* (PMERRLOC_EL5) Error Location x Register Offset */
#define PMERRLOC_EL6_REG_OFST          _UINT32_(0xA4)      /* (PMERRLOC_EL6) Error Location x Register Offset */
#define PMERRLOC_EL7_REG_OFST          _UINT32_(0xA8)      /* (PMERRLOC_EL7) Error Location x Register Offset */
#define PMERRLOC_EL8_REG_OFST          _UINT32_(0xAC)      /* (PMERRLOC_EL8) Error Location x Register Offset */
#define PMERRLOC_EL9_REG_OFST          _UINT32_(0xB0)      /* (PMERRLOC_EL9) Error Location x Register Offset */
#define PMERRLOC_EL10_REG_OFST         _UINT32_(0xB4)      /* (PMERRLOC_EL10) Error Location x Register Offset */
#define PMERRLOC_EL11_REG_OFST         _UINT32_(0xB8)      /* (PMERRLOC_EL11) Error Location x Register Offset */
#define PMERRLOC_EL12_REG_OFST         _UINT32_(0xBC)      /* (PMERRLOC_EL12) Error Location x Register Offset */
#define PMERRLOC_EL13_REG_OFST         _UINT32_(0xC0)      /* (PMERRLOC_EL13) Error Location x Register Offset */
#define PMERRLOC_EL14_REG_OFST         _UINT32_(0xC4)      /* (PMERRLOC_EL14) Error Location x Register Offset */
#define PMERRLOC_EL15_REG_OFST         _UINT32_(0xC8)      /* (PMERRLOC_EL15) Error Location x Register Offset */
#define PMERRLOC_EL16_REG_OFST         _UINT32_(0xCC)      /* (PMERRLOC_EL16) Error Location x Register Offset */
#define PMERRLOC_EL17_REG_OFST         _UINT32_(0xD0)      /* (PMERRLOC_EL17) Error Location x Register Offset */
#define PMERRLOC_EL18_REG_OFST         _UINT32_(0xD4)      /* (PMERRLOC_EL18) Error Location x Register Offset */
#define PMERRLOC_EL19_REG_OFST         _UINT32_(0xD8)      /* (PMERRLOC_EL19) Error Location x Register Offset */
#define PMERRLOC_EL20_REG_OFST         _UINT32_(0xDC)      /* (PMERRLOC_EL20) Error Location x Register Offset */
#define PMERRLOC_EL21_REG_OFST         _UINT32_(0xE0)      /* (PMERRLOC_EL21) Error Location x Register Offset */
#define PMERRLOC_EL22_REG_OFST         _UINT32_(0xE4)      /* (PMERRLOC_EL22) Error Location x Register Offset */
#define PMERRLOC_EL23_REG_OFST         _UINT32_(0xE8)      /* (PMERRLOC_EL23) Error Location x Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/* PMERRLOC register API structure */
typedef struct
{  /* Programmable Multibit ECC Error Location */
  __IO  uint32_t                       PMERRLOC_ELCFG;     /* Offset: 0x00 (R/W  32) Configuration Register */
  __I   uint32_t                       PMERRLOC_ELPRIM;    /* Offset: 0x04 (R/   32) Primitive Register */
  __IO  uint32_t                       PMERRLOC_ELEN;      /* Offset: 0x08 (R/W  32) Enable Register */
  __IO  uint32_t                       PMERRLOC_ELDIS;     /* Offset: 0x0C (R/W  32) Disable Register */
  __IO  uint32_t                       PMERRLOC_ELSR;      /* Offset: 0x10 (R/W  32) Status Register */
  __O   uint32_t                       PMERRLOC_ELIER;     /* Offset: 0x14 ( /W  32) Interrupt Enable Register */
  __O   uint32_t                       PMERRLOC_ELIDR;     /* Offset: 0x18 ( /W  32) Interrupt Disable Register */
  __I   uint32_t                       PMERRLOC_ELIMR;     /* Offset: 0x1C (R/   32) Interrupt Mask Register */
  __I   uint32_t                       PMERRLOC_ELISR;     /* Offset: 0x20 (R/   32) Interrupt Status Register */
  __I   uint8_t                        Reserved1[0x04];
  __I   uint32_t                       PMERRLOC_SIGMA0;    /* Offset: 0x28 (R/   32) SIGMA0 Register */
  __IO  uint32_t                       PMERRLOC_SIGMA1;    /* Offset: 0x2C (R/W  32) SIGMA1 Register */
  __IO  uint32_t                       PMERRLOC_SIGMA2;    /* Offset: 0x30 (R/W  32) SIGMA2 Register */
  __IO  uint32_t                       PMERRLOC_SIGMA3;    /* Offset: 0x34 (R/W  32) SIGMA3 Register */
  __IO  uint32_t                       PMERRLOC_SIGMA4;    /* Offset: 0x38 (R/W  32) SIGMA4 Register */
  __IO  uint32_t                       PMERRLOC_SIGMA5;    /* Offset: 0x3C (R/W  32) SIGMA5 Register */
  __IO  uint32_t                       PMERRLOC_SIGMA6;    /* Offset: 0x40 (R/W  32) SIGMA6 Register */
  __IO  uint32_t                       PMERRLOC_SIGMA7;    /* Offset: 0x44 (R/W  32) SIGMA7 Register */
  __IO  uint32_t                       PMERRLOC_SIGMA8;    /* Offset: 0x48 (R/W  32) SIGMA8 Register */
  __IO  uint32_t                       PMERRLOC_SIGMA9;    /* Offset: 0x4C (R/W  32) SIGMA9 Register */
  __IO  uint32_t                       PMERRLOC_SIGMA10;   /* Offset: 0x50 (R/W  32) SIGMA10 Register */
  __IO  uint32_t                       PMERRLOC_SIGMA11;   /* Offset: 0x54 (R/W  32) SIGMA11 Register */
  __IO  uint32_t                       PMERRLOC_SIGMA12;   /* Offset: 0x58 (R/W  32) SIGMA12 Register */
  __IO  uint32_t                       PMERRLOC_SIGMA13;   /* Offset: 0x5C (R/W  32) SIGMA13 Register */
  __IO  uint32_t                       PMERRLOC_SIGMA14;   /* Offset: 0x60 (R/W  32) SIGMA14 Register */
  __IO  uint32_t                       PMERRLOC_SIGMA15;   /* Offset: 0x64 (R/W  32) SIGMA15 Register */
  __IO  uint32_t                       PMERRLOC_SIGMA16;   /* Offset: 0x68 (R/W  32) SIGMA16 Register */
  __IO  uint32_t                       PMERRLOC_SIGMA17;   /* Offset: 0x6C (R/W  32) SIGMA17 Register */
  __IO  uint32_t                       PMERRLOC_SIGMA18;   /* Offset: 0x70 (R/W  32) SIGMA18 Register */
  __IO  uint32_t                       PMERRLOC_SIGMA19;   /* Offset: 0x74 (R/W  32) SIGMA19 Register */
  __IO  uint32_t                       PMERRLOC_SIGMA20;   /* Offset: 0x78 (R/W  32) SIGMA20 Register */
  __IO  uint32_t                       PMERRLOC_SIGMA21;   /* Offset: 0x7C (R/W  32) SIGMA21 Register */
  __IO  uint32_t                       PMERRLOC_SIGMA22;   /* Offset: 0x80 (R/W  32) SIGMA22 Register */
  __IO  uint32_t                       PMERRLOC_SIGMA23;   /* Offset: 0x84 (R/W  32) SIGMA23 Register */
  __IO  uint32_t                       PMERRLOC_SIGMA24;   /* Offset: 0x88 (R/W  32) SIGMA24 Register */
  __I   uint32_t                       PMERRLOC_EL[24];    /* Offset: 0x8C (R/   32) Error Location x Register */
} pmerrloc_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAM9X7_PMERRLOC_COMPONENT_H_ */
