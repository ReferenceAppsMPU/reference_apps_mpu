/*
 * Component description for SFR
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
#ifndef _SAM9X7_SFR_COMPONENT_H_
#define _SAM9X7_SFR_COMPONENT_H_

/* ************************************************************************** */
/*                      SOFTWARE API DEFINITION FOR SFR                       */
/* ************************************************************************** */

/* -------- SFR_CCFG_EBICSA : (SFR Offset: 0x04) (R/W 32) EBI Chip Select Register -------- */
#define SFR_CCFG_EBICSA_RESETVALUE            _UINT32_(0x300)                                      /*  (SFR_CCFG_EBICSA) EBI Chip Select Register  Reset Value */

#define SFR_CCFG_EBICSA_EBI_CS1A_Pos          _UINT32_(1)                                          /* (SFR_CCFG_EBICSA) EBI Chip Select 1 Assignment Position */
#define SFR_CCFG_EBICSA_EBI_CS1A_Msk          (_UINT32_(0x1) << SFR_CCFG_EBICSA_EBI_CS1A_Pos)      /* (SFR_CCFG_EBICSA) EBI Chip Select 1 Assignment Mask */
#define SFR_CCFG_EBICSA_EBI_CS1A(value)       (SFR_CCFG_EBICSA_EBI_CS1A_Msk & (_UINT32_(value) << SFR_CCFG_EBICSA_EBI_CS1A_Pos)) /* Assignment of value for EBI_CS1A in the SFR_CCFG_EBICSA register */
#define   SFR_CCFG_EBICSA_EBI_CS1A_0_Val      _UINT32_(0x0)                                        /* (SFR_CCFG_EBICSA) EBI Chip Select 1 is assigned to the Static Memory Controller (SMC).  */
#define   SFR_CCFG_EBICSA_EBI_CS1A_1_Val      _UINT32_(0x1)                                        /* (SFR_CCFG_EBICSA) EBI Chip Select 1 is assigned to the AHB Multiport DDR-SDRAM Controller (MPDDRC).  */
#define SFR_CCFG_EBICSA_EBI_CS1A_0            (SFR_CCFG_EBICSA_EBI_CS1A_0_Val << SFR_CCFG_EBICSA_EBI_CS1A_Pos) /* (SFR_CCFG_EBICSA) EBI Chip Select 1 is assigned to the Static Memory Controller (SMC). Position */
#define SFR_CCFG_EBICSA_EBI_CS1A_1            (SFR_CCFG_EBICSA_EBI_CS1A_1_Val << SFR_CCFG_EBICSA_EBI_CS1A_Pos) /* (SFR_CCFG_EBICSA) EBI Chip Select 1 is assigned to the AHB Multiport DDR-SDRAM Controller (MPDDRC). Position */
#define SFR_CCFG_EBICSA_EBI_CS2A_Pos          _UINT32_(2)                                          /* (SFR_CCFG_EBICSA) EBI Chip Select 2 Assignment Position */
#define SFR_CCFG_EBICSA_EBI_CS2A_Msk          (_UINT32_(0x1) << SFR_CCFG_EBICSA_EBI_CS2A_Pos)      /* (SFR_CCFG_EBICSA) EBI Chip Select 2 Assignment Mask */
#define SFR_CCFG_EBICSA_EBI_CS2A(value)       (SFR_CCFG_EBICSA_EBI_CS2A_Msk & (_UINT32_(value) << SFR_CCFG_EBICSA_EBI_CS2A_Pos)) /* Assignment of value for EBI_CS2A in the SFR_CCFG_EBICSA register */
#define   SFR_CCFG_EBICSA_EBI_CS2A_0_Val      _UINT32_(0x0)                                        /* (SFR_CCFG_EBICSA) EBI Chip Select 2 is only assigned to the SMC and EBI_NCS2 behaves as defined by the SMC.  */
#define   SFR_CCFG_EBICSA_EBI_CS2A_1_Val      _UINT32_(0x1)                                        /* (SFR_CCFG_EBICSA) EBI Chip Select 2 is assigned to the SMC and the NAND Flash logic is activated.  */
#define SFR_CCFG_EBICSA_EBI_CS2A_0            (SFR_CCFG_EBICSA_EBI_CS2A_0_Val << SFR_CCFG_EBICSA_EBI_CS2A_Pos) /* (SFR_CCFG_EBICSA) EBI Chip Select 2 is only assigned to the SMC and EBI_NCS2 behaves as defined by the SMC. Position */
#define SFR_CCFG_EBICSA_EBI_CS2A_1            (SFR_CCFG_EBICSA_EBI_CS2A_1_Val << SFR_CCFG_EBICSA_EBI_CS2A_Pos) /* (SFR_CCFG_EBICSA) EBI Chip Select 2 is assigned to the SMC and the NAND Flash logic is activated. Position */
#define SFR_CCFG_EBICSA_EBI_DBPUC_Pos         _UINT32_(8)                                          /* (SFR_CCFG_EBICSA) EBI Data Bus Pullup Configuration Position */
#define SFR_CCFG_EBICSA_EBI_DBPUC_Msk         (_UINT32_(0x1) << SFR_CCFG_EBICSA_EBI_DBPUC_Pos)     /* (SFR_CCFG_EBICSA) EBI Data Bus Pullup Configuration Mask */
#define SFR_CCFG_EBICSA_EBI_DBPUC(value)      (SFR_CCFG_EBICSA_EBI_DBPUC_Msk & (_UINT32_(value) << SFR_CCFG_EBICSA_EBI_DBPUC_Pos)) /* Assignment of value for EBI_DBPUC in the SFR_CCFG_EBICSA register */
#define   SFR_CCFG_EBICSA_EBI_DBPUC_0_Val     _UINT32_(0x0)                                        /* (SFR_CCFG_EBICSA) EBI D0-D15 Data Bus bits are internally pulled up to the VDDIOM power supply.  */
#define   SFR_CCFG_EBICSA_EBI_DBPUC_1_Val     _UINT32_(0x1)                                        /* (SFR_CCFG_EBICSA) EBI D0-D15 Data Bus bits are not internally pulled up.  */
#define SFR_CCFG_EBICSA_EBI_DBPUC_0           (SFR_CCFG_EBICSA_EBI_DBPUC_0_Val << SFR_CCFG_EBICSA_EBI_DBPUC_Pos) /* (SFR_CCFG_EBICSA) EBI D0-D15 Data Bus bits are internally pulled up to the VDDIOM power supply. Position */
#define SFR_CCFG_EBICSA_EBI_DBPUC_1           (SFR_CCFG_EBICSA_EBI_DBPUC_1_Val << SFR_CCFG_EBICSA_EBI_DBPUC_Pos) /* (SFR_CCFG_EBICSA) EBI D0-D15 Data Bus bits are not internally pulled up. Position */
#define SFR_CCFG_EBICSA_EBI_DBPDC_Pos         _UINT32_(9)                                          /* (SFR_CCFG_EBICSA) EBI Data Bus Pulldown Configuration Position */
#define SFR_CCFG_EBICSA_EBI_DBPDC_Msk         (_UINT32_(0x1) << SFR_CCFG_EBICSA_EBI_DBPDC_Pos)     /* (SFR_CCFG_EBICSA) EBI Data Bus Pulldown Configuration Mask */
#define SFR_CCFG_EBICSA_EBI_DBPDC(value)      (SFR_CCFG_EBICSA_EBI_DBPDC_Msk & (_UINT32_(value) << SFR_CCFG_EBICSA_EBI_DBPDC_Pos)) /* Assignment of value for EBI_DBPDC in the SFR_CCFG_EBICSA register */
#define   SFR_CCFG_EBICSA_EBI_DBPDC_0_Val     _UINT32_(0x0)                                        /* (SFR_CCFG_EBICSA) EBI D0-D15 Data Bus bits are not internally pulled down.  */
#define   SFR_CCFG_EBICSA_EBI_DBPDC_1_Val     _UINT32_(0x1)                                        /* (SFR_CCFG_EBICSA) EBI D0-D15 Data Bus bits are internally pulled down to the ground.  */
#define SFR_CCFG_EBICSA_EBI_DBPDC_0           (SFR_CCFG_EBICSA_EBI_DBPDC_0_Val << SFR_CCFG_EBICSA_EBI_DBPDC_Pos) /* (SFR_CCFG_EBICSA) EBI D0-D15 Data Bus bits are not internally pulled down. Position */
#define SFR_CCFG_EBICSA_EBI_DBPDC_1           (SFR_CCFG_EBICSA_EBI_DBPDC_1_Val << SFR_CCFG_EBICSA_EBI_DBPDC_Pos) /* (SFR_CCFG_EBICSA) EBI D0-D15 Data Bus bits are internally pulled down to the ground. Position */
#define SFR_CCFG_EBICSA_DQIEN_F_Pos           _UINT32_(20)                                         /* (SFR_CCFG_EBICSA) Force Analog Input Comparator Configuration Position */
#define SFR_CCFG_EBICSA_DQIEN_F_Msk           (_UINT32_(0x1) << SFR_CCFG_EBICSA_DQIEN_F_Pos)       /* (SFR_CCFG_EBICSA) Force Analog Input Comparator Configuration Mask */
#define SFR_CCFG_EBICSA_DQIEN_F(value)        (SFR_CCFG_EBICSA_DQIEN_F_Msk & (_UINT32_(value) << SFR_CCFG_EBICSA_DQIEN_F_Pos)) /* Assignment of value for DQIEN_F in the SFR_CCFG_EBICSA register */
#define   SFR_CCFG_EBICSA_DQIEN_F_0_Val       _UINT32_(0x0)                                        /* (SFR_CCFG_EBICSA) No effect  */
#define   SFR_CCFG_EBICSA_DQIEN_F_1_Val       _UINT32_(0x1)                                        /* (SFR_CCFG_EBICSA) Enables the input comparator in the VDDIOM I/O data lines. Must be set to one in an initialization phase whenever an MPDDRC external component (DDR2 or LPDDR) and an SMC external component (e.g., NAND Flash) are multiplexed on the D0-D15 bus.  */
#define SFR_CCFG_EBICSA_DQIEN_F_0             (SFR_CCFG_EBICSA_DQIEN_F_0_Val << SFR_CCFG_EBICSA_DQIEN_F_Pos) /* (SFR_CCFG_EBICSA) No effect Position */
#define SFR_CCFG_EBICSA_DQIEN_F_1             (SFR_CCFG_EBICSA_DQIEN_F_1_Val << SFR_CCFG_EBICSA_DQIEN_F_Pos) /* (SFR_CCFG_EBICSA) Enables the input comparator in the VDDIOM I/O data lines. Must be set to one in an initialization phase whenever an MPDDRC external component (DDR2 or LPDDR) and an SMC external component (e.g., NAND Flash) are multiplexed on the D0-D15 bus. Position */
#define SFR_CCFG_EBICSA_NFD0_ON_D16_Pos       _UINT32_(24)                                         /* (SFR_CCFG_EBICSA) NAND Flash Databus Selection Position */
#define SFR_CCFG_EBICSA_NFD0_ON_D16_Msk       (_UINT32_(0x1) << SFR_CCFG_EBICSA_NFD0_ON_D16_Pos)   /* (SFR_CCFG_EBICSA) NAND Flash Databus Selection Mask */
#define SFR_CCFG_EBICSA_NFD0_ON_D16(value)    (SFR_CCFG_EBICSA_NFD0_ON_D16_Msk & (_UINT32_(value) << SFR_CCFG_EBICSA_NFD0_ON_D16_Pos)) /* Assignment of value for NFD0_ON_D16 in the SFR_CCFG_EBICSA register */
#define   SFR_CCFG_EBICSA_NFD0_ON_D16_0_Val   _UINT32_(0x0)                                        /* (SFR_CCFG_EBICSA) NAND Flash I/Os are connected to D0-D7 (default).  */
#define   SFR_CCFG_EBICSA_NFD0_ON_D16_1_Val   _UINT32_(0x1)                                        /* (SFR_CCFG_EBICSA) NAND Flash I/Os are connected to D16-D23.  */
#define SFR_CCFG_EBICSA_NFD0_ON_D16_0         (SFR_CCFG_EBICSA_NFD0_ON_D16_0_Val << SFR_CCFG_EBICSA_NFD0_ON_D16_Pos) /* (SFR_CCFG_EBICSA) NAND Flash I/Os are connected to D0-D7 (default). Position */
#define SFR_CCFG_EBICSA_NFD0_ON_D16_1         (SFR_CCFG_EBICSA_NFD0_ON_D16_1_Val << SFR_CCFG_EBICSA_NFD0_ON_D16_Pos) /* (SFR_CCFG_EBICSA) NAND Flash I/Os are connected to D16-D23. Position */
#define SFR_CCFG_EBICSA_DDR_MP_EN_Pos         _UINT32_(25)                                         /* (SFR_CCFG_EBICSA) DDR Multiport Enable Position */
#define SFR_CCFG_EBICSA_DDR_MP_EN_Msk         (_UINT32_(0x1) << SFR_CCFG_EBICSA_DDR_MP_EN_Pos)     /* (SFR_CCFG_EBICSA) DDR Multiport Enable Mask */
#define SFR_CCFG_EBICSA_DDR_MP_EN(value)      (SFR_CCFG_EBICSA_DDR_MP_EN_Msk & (_UINT32_(value) << SFR_CCFG_EBICSA_DDR_MP_EN_Pos)) /* Assignment of value for DDR_MP_EN in the SFR_CCFG_EBICSA register */
#define   SFR_CCFG_EBICSA_DDR_MP_EN_0_Val     _UINT32_(0x0)                                        /* (SFR_CCFG_EBICSA) DDR Multiport is disabled (default).  */
#define   SFR_CCFG_EBICSA_DDR_MP_EN_1_Val     _UINT32_(0x1)                                        /* (SFR_CCFG_EBICSA) DDR Multiport is enabled, performance is increased.  */
#define SFR_CCFG_EBICSA_DDR_MP_EN_0           (SFR_CCFG_EBICSA_DDR_MP_EN_0_Val << SFR_CCFG_EBICSA_DDR_MP_EN_Pos) /* (SFR_CCFG_EBICSA) DDR Multiport is disabled (default). Position */
#define SFR_CCFG_EBICSA_DDR_MP_EN_1           (SFR_CCFG_EBICSA_DDR_MP_EN_1_Val << SFR_CCFG_EBICSA_DDR_MP_EN_Pos) /* (SFR_CCFG_EBICSA) DDR Multiport is enabled, performance is increased. Position */
#define SFR_CCFG_EBICSA_Msk                   _UINT32_(0x03100306)                                 /* (SFR_CCFG_EBICSA) Register Mask  */

#define SFR_CCFG_EBICSA_NFD0_ON_D_Pos         _UINT32_(24)                                         /* (SFR_CCFG_EBICSA Position) NAND Flash Databus Selection */
#define SFR_CCFG_EBICSA_NFD0_ON_D_Msk         (_UINT32_(0x1) << SFR_CCFG_EBICSA_NFD0_ON_D_Pos)     /* (SFR_CCFG_EBICSA Mask) NFD0_ON_D */
#define SFR_CCFG_EBICSA_NFD0_ON_D(value)      (SFR_CCFG_EBICSA_NFD0_ON_D_Msk & (_UINT32_(value) << SFR_CCFG_EBICSA_NFD0_ON_D_Pos)) 

/* -------- SFR_OHCIICR : (SFR Offset: 0x10) (R/W 32) OHCI Interrupt Configuration Register -------- */
#define SFR_OHCIICR_RESETVALUE                _UINT32_(0x00)                                       /*  (SFR_OHCIICR) OHCI Interrupt Configuration Register  Reset Value */

#define SFR_OHCIICR_RES0_Pos                  _UINT32_(0)                                          /* (SFR_OHCIICR) USB PORTx Reset Position */
#define SFR_OHCIICR_RES0_Msk                  (_UINT32_(0x1) << SFR_OHCIICR_RES0_Pos)              /* (SFR_OHCIICR) USB PORTx Reset Mask */
#define SFR_OHCIICR_RES0(value)               (SFR_OHCIICR_RES0_Msk & (_UINT32_(value) << SFR_OHCIICR_RES0_Pos)) /* Assignment of value for RES0 in the SFR_OHCIICR register */
#define   SFR_OHCIICR_RES0_0_Val              _UINT32_(0x0)                                        /* (SFR_OHCIICR) No effect (USB PORTx reset released, default value)  */
#define   SFR_OHCIICR_RES0_1_Val              _UINT32_(0x1)                                        /* (SFR_OHCIICR) Resets USB PORTx.  */
#define SFR_OHCIICR_RES0_0                    (SFR_OHCIICR_RES0_0_Val << SFR_OHCIICR_RES0_Pos)     /* (SFR_OHCIICR) No effect (USB PORTx reset released, default value) Position */
#define SFR_OHCIICR_RES0_1                    (SFR_OHCIICR_RES0_1_Val << SFR_OHCIICR_RES0_Pos)     /* (SFR_OHCIICR) Resets USB PORTx. Position */
#define SFR_OHCIICR_RES1_Pos                  _UINT32_(1)                                          /* (SFR_OHCIICR) USB PORTx Reset Position */
#define SFR_OHCIICR_RES1_Msk                  (_UINT32_(0x1) << SFR_OHCIICR_RES1_Pos)              /* (SFR_OHCIICR) USB PORTx Reset Mask */
#define SFR_OHCIICR_RES1(value)               (SFR_OHCIICR_RES1_Msk & (_UINT32_(value) << SFR_OHCIICR_RES1_Pos)) /* Assignment of value for RES1 in the SFR_OHCIICR register */
#define   SFR_OHCIICR_RES1_0_Val              _UINT32_(0x0)                                        /* (SFR_OHCIICR) No effect (USB PORTx reset released, default value)  */
#define   SFR_OHCIICR_RES1_1_Val              _UINT32_(0x1)                                        /* (SFR_OHCIICR) Resets USB PORTx.  */
#define SFR_OHCIICR_RES1_0                    (SFR_OHCIICR_RES1_0_Val << SFR_OHCIICR_RES1_Pos)     /* (SFR_OHCIICR) No effect (USB PORTx reset released, default value) Position */
#define SFR_OHCIICR_RES1_1                    (SFR_OHCIICR_RES1_1_Val << SFR_OHCIICR_RES1_Pos)     /* (SFR_OHCIICR) Resets USB PORTx. Position */
#define SFR_OHCIICR_RES2_Pos                  _UINT32_(2)                                          /* (SFR_OHCIICR) USB PORTx Reset Position */
#define SFR_OHCIICR_RES2_Msk                  (_UINT32_(0x1) << SFR_OHCIICR_RES2_Pos)              /* (SFR_OHCIICR) USB PORTx Reset Mask */
#define SFR_OHCIICR_RES2(value)               (SFR_OHCIICR_RES2_Msk & (_UINT32_(value) << SFR_OHCIICR_RES2_Pos)) /* Assignment of value for RES2 in the SFR_OHCIICR register */
#define   SFR_OHCIICR_RES2_0_Val              _UINT32_(0x0)                                        /* (SFR_OHCIICR) No effect (USB PORTx reset released, default value)  */
#define   SFR_OHCIICR_RES2_1_Val              _UINT32_(0x1)                                        /* (SFR_OHCIICR) Resets USB PORTx.  */
#define SFR_OHCIICR_RES2_0                    (SFR_OHCIICR_RES2_0_Val << SFR_OHCIICR_RES2_Pos)     /* (SFR_OHCIICR) No effect (USB PORTx reset released, default value) Position */
#define SFR_OHCIICR_RES2_1                    (SFR_OHCIICR_RES2_1_Val << SFR_OHCIICR_RES2_Pos)     /* (SFR_OHCIICR) Resets USB PORTx. Position */
#define SFR_OHCIICR_ARIE_Pos                  _UINT32_(4)                                          /* (SFR_OHCIICR) OHCI Asynchronous Resume Interrupt Enable Position */
#define SFR_OHCIICR_ARIE_Msk                  (_UINT32_(0x1) << SFR_OHCIICR_ARIE_Pos)              /* (SFR_OHCIICR) OHCI Asynchronous Resume Interrupt Enable Mask */
#define SFR_OHCIICR_ARIE(value)               (SFR_OHCIICR_ARIE_Msk & (_UINT32_(value) << SFR_OHCIICR_ARIE_Pos)) /* Assignment of value for ARIE in the SFR_OHCIICR register */
#define   SFR_OHCIICR_ARIE_0_Val              _UINT32_(0x0)                                        /* (SFR_OHCIICR) Disables interrupt.  */
#define   SFR_OHCIICR_ARIE_1_Val              _UINT32_(0x1)                                        /* (SFR_OHCIICR) Enables interrupt.  */
#define SFR_OHCIICR_ARIE_0                    (SFR_OHCIICR_ARIE_0_Val << SFR_OHCIICR_ARIE_Pos)     /* (SFR_OHCIICR) Disables interrupt. Position */
#define SFR_OHCIICR_ARIE_1                    (SFR_OHCIICR_ARIE_1_Val << SFR_OHCIICR_ARIE_Pos)     /* (SFR_OHCIICR) Enables interrupt. Position */
#define SFR_OHCIICR_APPSTART_Pos              _UINT32_(5)                                          /* (SFR_OHCIICR) Reserved Position */
#define SFR_OHCIICR_APPSTART_Msk              (_UINT32_(0x1) << SFR_OHCIICR_APPSTART_Pos)          /* (SFR_OHCIICR) Reserved Mask */
#define SFR_OHCIICR_APPSTART(value)           (SFR_OHCIICR_APPSTART_Msk & (_UINT32_(value) << SFR_OHCIICR_APPSTART_Pos)) /* Assignment of value for APPSTART in the SFR_OHCIICR register */
#define   SFR_OHCIICR_APPSTART_0_Val          _UINT32_(0x0)                                        /* (SFR_OHCIICR) Must write 0.  */
#define SFR_OHCIICR_APPSTART_0                (SFR_OHCIICR_APPSTART_0_Val << SFR_OHCIICR_APPSTART_Pos) /* (SFR_OHCIICR) Must write 0. Position */
#define SFR_OHCIICR_SUSP0_Pos                 _UINT32_(8)                                          /* (SFR_OHCIICR) USB PORTx Position */
#define SFR_OHCIICR_SUSP0_Msk                 (_UINT32_(0x1) << SFR_OHCIICR_SUSP0_Pos)             /* (SFR_OHCIICR) USB PORTx Mask */
#define SFR_OHCIICR_SUSP0(value)              (SFR_OHCIICR_SUSP0_Msk & (_UINT32_(value) << SFR_OHCIICR_SUSP0_Pos)) /* Assignment of value for SUSP0 in the SFR_OHCIICR register */
#define   SFR_OHCIICR_SUSP0_0_Val             _UINT32_(0x0)                                        /* (SFR_OHCIICR) Does not suspend USB PORTx.  */
#define   SFR_OHCIICR_SUSP0_1_Val             _UINT32_(0x1)                                        /* (SFR_OHCIICR) Forces PORTx suspend.  */
#define SFR_OHCIICR_SUSP0_0                   (SFR_OHCIICR_SUSP0_0_Val << SFR_OHCIICR_SUSP0_Pos)   /* (SFR_OHCIICR) Does not suspend USB PORTx. Position */
#define SFR_OHCIICR_SUSP0_1                   (SFR_OHCIICR_SUSP0_1_Val << SFR_OHCIICR_SUSP0_Pos)   /* (SFR_OHCIICR) Forces PORTx suspend. Position */
#define SFR_OHCIICR_SUSP1_Pos                 _UINT32_(9)                                          /* (SFR_OHCIICR) USB PORTx Position */
#define SFR_OHCIICR_SUSP1_Msk                 (_UINT32_(0x1) << SFR_OHCIICR_SUSP1_Pos)             /* (SFR_OHCIICR) USB PORTx Mask */
#define SFR_OHCIICR_SUSP1(value)              (SFR_OHCIICR_SUSP1_Msk & (_UINT32_(value) << SFR_OHCIICR_SUSP1_Pos)) /* Assignment of value for SUSP1 in the SFR_OHCIICR register */
#define   SFR_OHCIICR_SUSP1_0_Val             _UINT32_(0x0)                                        /* (SFR_OHCIICR) Does not suspend USB PORTx.  */
#define   SFR_OHCIICR_SUSP1_1_Val             _UINT32_(0x1)                                        /* (SFR_OHCIICR) Forces PORTx suspend.  */
#define SFR_OHCIICR_SUSP1_0                   (SFR_OHCIICR_SUSP1_0_Val << SFR_OHCIICR_SUSP1_Pos)   /* (SFR_OHCIICR) Does not suspend USB PORTx. Position */
#define SFR_OHCIICR_SUSP1_1                   (SFR_OHCIICR_SUSP1_1_Val << SFR_OHCIICR_SUSP1_Pos)   /* (SFR_OHCIICR) Forces PORTx suspend. Position */
#define SFR_OHCIICR_SUSP2_Pos                 _UINT32_(10)                                         /* (SFR_OHCIICR) USB PORTx Position */
#define SFR_OHCIICR_SUSP2_Msk                 (_UINT32_(0x1) << SFR_OHCIICR_SUSP2_Pos)             /* (SFR_OHCIICR) USB PORTx Mask */
#define SFR_OHCIICR_SUSP2(value)              (SFR_OHCIICR_SUSP2_Msk & (_UINT32_(value) << SFR_OHCIICR_SUSP2_Pos)) /* Assignment of value for SUSP2 in the SFR_OHCIICR register */
#define   SFR_OHCIICR_SUSP2_0_Val             _UINT32_(0x0)                                        /* (SFR_OHCIICR) Does not suspend USB PORTx.  */
#define   SFR_OHCIICR_SUSP2_1_Val             _UINT32_(0x1)                                        /* (SFR_OHCIICR) Forces PORTx suspend.  */
#define SFR_OHCIICR_SUSP2_0                   (SFR_OHCIICR_SUSP2_0_Val << SFR_OHCIICR_SUSP2_Pos)   /* (SFR_OHCIICR) Does not suspend USB PORTx. Position */
#define SFR_OHCIICR_SUSP2_1                   (SFR_OHCIICR_SUSP2_1_Val << SFR_OHCIICR_SUSP2_Pos)   /* (SFR_OHCIICR) Forces PORTx suspend. Position */
#define SFR_OHCIICR_UDPPUDIS_Pos              _UINT32_(23)                                         /* (SFR_OHCIICR) Reserved Position */
#define SFR_OHCIICR_UDPPUDIS_Msk              (_UINT32_(0x1) << SFR_OHCIICR_UDPPUDIS_Pos)          /* (SFR_OHCIICR) Reserved Mask */
#define SFR_OHCIICR_UDPPUDIS(value)           (SFR_OHCIICR_UDPPUDIS_Msk & (_UINT32_(value) << SFR_OHCIICR_UDPPUDIS_Pos)) /* Assignment of value for UDPPUDIS in the SFR_OHCIICR register */
#define   SFR_OHCIICR_UDPPUDIS_0_Val          _UINT32_(0x0)                                        /* (SFR_OHCIICR) Must write 0.  */
#define SFR_OHCIICR_UDPPUDIS_0                (SFR_OHCIICR_UDPPUDIS_0_Val << SFR_OHCIICR_UDPPUDIS_Pos) /* (SFR_OHCIICR) Must write 0. Position */
#define SFR_OHCIICR_Msk                       _UINT32_(0x00800737)                                 /* (SFR_OHCIICR) Register Mask  */

#define SFR_OHCIICR_RES_Pos                   _UINT32_(0)                                          /* (SFR_OHCIICR Position) USB PORTx Reset */
#define SFR_OHCIICR_RES_Msk                   (_UINT32_(0x7) << SFR_OHCIICR_RES_Pos)               /* (SFR_OHCIICR Mask) RES */
#define SFR_OHCIICR_RES(value)                (SFR_OHCIICR_RES_Msk & (_UINT32_(value) << SFR_OHCIICR_RES_Pos)) 
#define SFR_OHCIICR_SUSP_Pos                  _UINT32_(8)                                          /* (SFR_OHCIICR Position) USB PORTx */
#define SFR_OHCIICR_SUSP_Msk                  (_UINT32_(0x7) << SFR_OHCIICR_SUSP_Pos)              /* (SFR_OHCIICR Mask) SUSP */
#define SFR_OHCIICR_SUSP(value)               (SFR_OHCIICR_SUSP_Msk & (_UINT32_(value) << SFR_OHCIICR_SUSP_Pos)) 

/* -------- SFR_OHCIISR : (SFR Offset: 0x14) ( R/ 32) OHCI Interrupt Status Register -------- */
#define SFR_OHCIISR_RESETVALUE                _UINT32_(0x00)                                       /*  (SFR_OHCIISR) OHCI Interrupt Status Register  Reset Value */

#define SFR_OHCIISR_RIS0_Pos                  _UINT32_(0)                                          /* (SFR_OHCIISR) OHCI Resume Interrupt Status Port 0 Position */
#define SFR_OHCIISR_RIS0_Msk                  (_UINT32_(0x1) << SFR_OHCIISR_RIS0_Pos)              /* (SFR_OHCIISR) OHCI Resume Interrupt Status Port 0 Mask */
#define SFR_OHCIISR_RIS0(value)               (SFR_OHCIISR_RIS0_Msk & (_UINT32_(value) << SFR_OHCIISR_RIS0_Pos)) /* Assignment of value for RIS0 in the SFR_OHCIISR register */
#define   SFR_OHCIISR_RIS0_0_Val              _UINT32_(0x0)                                        /* (SFR_OHCIISR) OHCI port resume is not detected.  */
#define   SFR_OHCIISR_RIS0_1_Val              _UINT32_(0x1)                                        /* (SFR_OHCIISR) OHCI port resume is detected.  */
#define SFR_OHCIISR_RIS0_0                    (SFR_OHCIISR_RIS0_0_Val << SFR_OHCIISR_RIS0_Pos)     /* (SFR_OHCIISR) OHCI port resume is not detected. Position */
#define SFR_OHCIISR_RIS0_1                    (SFR_OHCIISR_RIS0_1_Val << SFR_OHCIISR_RIS0_Pos)     /* (SFR_OHCIISR) OHCI port resume is detected. Position */
#define SFR_OHCIISR_RIS1_Pos                  _UINT32_(1)                                          /* (SFR_OHCIISR) OHCI Resume Interrupt Status Port 1 Position */
#define SFR_OHCIISR_RIS1_Msk                  (_UINT32_(0x1) << SFR_OHCIISR_RIS1_Pos)              /* (SFR_OHCIISR) OHCI Resume Interrupt Status Port 1 Mask */
#define SFR_OHCIISR_RIS1(value)               (SFR_OHCIISR_RIS1_Msk & (_UINT32_(value) << SFR_OHCIISR_RIS1_Pos)) /* Assignment of value for RIS1 in the SFR_OHCIISR register */
#define   SFR_OHCIISR_RIS1_0_Val              _UINT32_(0x0)                                        /* (SFR_OHCIISR) OHCI port resume is not detected.  */
#define   SFR_OHCIISR_RIS1_1_Val              _UINT32_(0x1)                                        /* (SFR_OHCIISR) OHCI port resume is detected.  */
#define SFR_OHCIISR_RIS1_0                    (SFR_OHCIISR_RIS1_0_Val << SFR_OHCIISR_RIS1_Pos)     /* (SFR_OHCIISR) OHCI port resume is not detected. Position */
#define SFR_OHCIISR_RIS1_1                    (SFR_OHCIISR_RIS1_1_Val << SFR_OHCIISR_RIS1_Pos)     /* (SFR_OHCIISR) OHCI port resume is detected. Position */
#define SFR_OHCIISR_RIS2_Pos                  _UINT32_(2)                                          /* (SFR_OHCIISR) OHCI Resume Interrupt Status Port 2 Position */
#define SFR_OHCIISR_RIS2_Msk                  (_UINT32_(0x1) << SFR_OHCIISR_RIS2_Pos)              /* (SFR_OHCIISR) OHCI Resume Interrupt Status Port 2 Mask */
#define SFR_OHCIISR_RIS2(value)               (SFR_OHCIISR_RIS2_Msk & (_UINT32_(value) << SFR_OHCIISR_RIS2_Pos)) /* Assignment of value for RIS2 in the SFR_OHCIISR register */
#define   SFR_OHCIISR_RIS2_0_Val              _UINT32_(0x0)                                        /* (SFR_OHCIISR) OHCI port resume is not detected.  */
#define   SFR_OHCIISR_RIS2_1_Val              _UINT32_(0x1)                                        /* (SFR_OHCIISR) OHCI port resume is detected.  */
#define SFR_OHCIISR_RIS2_0                    (SFR_OHCIISR_RIS2_0_Val << SFR_OHCIISR_RIS2_Pos)     /* (SFR_OHCIISR) OHCI port resume is not detected. Position */
#define SFR_OHCIISR_RIS2_1                    (SFR_OHCIISR_RIS2_1_Val << SFR_OHCIISR_RIS2_Pos)     /* (SFR_OHCIISR) OHCI port resume is detected. Position */
#define SFR_OHCIISR_Msk                       _UINT32_(0x00000007)                                 /* (SFR_OHCIISR) Register Mask  */

#define SFR_OHCIISR_RIS_Pos                   _UINT32_(0)                                          /* (SFR_OHCIISR Position) OHCI Resume Interrupt Status Port 2 */
#define SFR_OHCIISR_RIS_Msk                   (_UINT32_(0x7) << SFR_OHCIISR_RIS_Pos)               /* (SFR_OHCIISR Mask) RIS */
#define SFR_OHCIISR_RIS(value)                (SFR_OHCIISR_RIS_Msk & (_UINT32_(value) << SFR_OHCIISR_RIS_Pos)) 

/* -------- SFR_UTMIHSTRIM : (SFR Offset: 0x34) (R/W 32) UTMI High-Speed Trimming Register -------- */
#define SFR_UTMIHSTRIM_RESETVALUE             _UINT32_(0x44433)                                    /*  (SFR_UTMIHSTRIM) UTMI High-Speed Trimming Register  Reset Value */

#define SFR_UTMIHSTRIM_SLOPE0_Pos             _UINT32_(8)                                          /* (SFR_UTMIHSTRIM) UTMI HS PORTx Transceiver Slope Trimming Position */
#define SFR_UTMIHSTRIM_SLOPE0_Msk             (_UINT32_(0x7) << SFR_UTMIHSTRIM_SLOPE0_Pos)         /* (SFR_UTMIHSTRIM) UTMI HS PORTx Transceiver Slope Trimming Mask */
#define SFR_UTMIHSTRIM_SLOPE0(value)          (SFR_UTMIHSTRIM_SLOPE0_Msk & (_UINT32_(value) << SFR_UTMIHSTRIM_SLOPE0_Pos)) /* Assignment of value for SLOPE0 in the SFR_UTMIHSTRIM register */
#define SFR_UTMIHSTRIM_SLOPE1_Pos             _UINT32_(12)                                         /* (SFR_UTMIHSTRIM) UTMI HS PORTx Transceiver Slope Trimming Position */
#define SFR_UTMIHSTRIM_SLOPE1_Msk             (_UINT32_(0x7) << SFR_UTMIHSTRIM_SLOPE1_Pos)         /* (SFR_UTMIHSTRIM) UTMI HS PORTx Transceiver Slope Trimming Mask */
#define SFR_UTMIHSTRIM_SLOPE1(value)          (SFR_UTMIHSTRIM_SLOPE1_Msk & (_UINT32_(value) << SFR_UTMIHSTRIM_SLOPE1_Pos)) /* Assignment of value for SLOPE1 in the SFR_UTMIHSTRIM register */
#define SFR_UTMIHSTRIM_SLOPE2_Pos             _UINT32_(16)                                         /* (SFR_UTMIHSTRIM) UTMI HS PORTx Transceiver Slope Trimming Position */
#define SFR_UTMIHSTRIM_SLOPE2_Msk             (_UINT32_(0x7) << SFR_UTMIHSTRIM_SLOPE2_Pos)         /* (SFR_UTMIHSTRIM) UTMI HS PORTx Transceiver Slope Trimming Mask */
#define SFR_UTMIHSTRIM_SLOPE2(value)          (SFR_UTMIHSTRIM_SLOPE2_Msk & (_UINT32_(value) << SFR_UTMIHSTRIM_SLOPE2_Pos)) /* Assignment of value for SLOPE2 in the SFR_UTMIHSTRIM register */
#define SFR_UTMIHSTRIM_Msk                    _UINT32_(0x00077700)                                 /* (SFR_UTMIHSTRIM) Register Mask  */


/* -------- SFR_UTMIFSTRIM : (SFR Offset: 0x38) (R/W 32) UTMI Full-Speed Trimming Register -------- */
#define SFR_UTMIFSTRIM_RESETVALUE             _UINT32_(0x430211)                                   /*  (SFR_UTMIFSTRIM) UTMI Full-Speed Trimming Register  Reset Value */

#define SFR_UTMIFSTRIM_ZN_Pos                 _UINT32_(16)                                         /* (SFR_UTMIFSTRIM) FS Transceiver NMOS Impedance Trimming Position */
#define SFR_UTMIFSTRIM_ZN_Msk                 (_UINT32_(0x7) << SFR_UTMIFSTRIM_ZN_Pos)             /* (SFR_UTMIFSTRIM) FS Transceiver NMOS Impedance Trimming Mask */
#define SFR_UTMIFSTRIM_ZN(value)              (SFR_UTMIFSTRIM_ZN_Msk & (_UINT32_(value) << SFR_UTMIFSTRIM_ZN_Pos)) /* Assignment of value for ZN in the SFR_UTMIFSTRIM register */
#define SFR_UTMIFSTRIM_ZP_Pos                 _UINT32_(20)                                         /* (SFR_UTMIFSTRIM) FS Transceiver PMOS Impedance Trimming Position */
#define SFR_UTMIFSTRIM_ZP_Msk                 (_UINT32_(0x7) << SFR_UTMIFSTRIM_ZP_Pos)             /* (SFR_UTMIFSTRIM) FS Transceiver PMOS Impedance Trimming Mask */
#define SFR_UTMIFSTRIM_ZP(value)              (SFR_UTMIFSTRIM_ZP_Msk & (_UINT32_(value) << SFR_UTMIFSTRIM_ZP_Pos)) /* Assignment of value for ZP in the SFR_UTMIFSTRIM register */
#define SFR_UTMIFSTRIM_ZN_CAL_Pos             _UINT32_(24)                                         /* (SFR_UTMIFSTRIM) FS Transceiver NMOS Impedance Calibration Position */
#define SFR_UTMIFSTRIM_ZN_CAL_Msk             (_UINT32_(0x7) << SFR_UTMIFSTRIM_ZN_CAL_Pos)         /* (SFR_UTMIFSTRIM) FS Transceiver NMOS Impedance Calibration Mask */
#define SFR_UTMIFSTRIM_ZN_CAL(value)          (SFR_UTMIFSTRIM_ZN_CAL_Msk & (_UINT32_(value) << SFR_UTMIFSTRIM_ZN_CAL_Pos)) /* Assignment of value for ZN_CAL in the SFR_UTMIFSTRIM register */
#define SFR_UTMIFSTRIM_ZP_CAL_Pos             _UINT32_(28)                                         /* (SFR_UTMIFSTRIM) FS Transceiver PMOS Impedance Calibration Position */
#define SFR_UTMIFSTRIM_ZP_CAL_Msk             (_UINT32_(0x7) << SFR_UTMIFSTRIM_ZP_CAL_Pos)         /* (SFR_UTMIFSTRIM) FS Transceiver PMOS Impedance Calibration Mask */
#define SFR_UTMIFSTRIM_ZP_CAL(value)          (SFR_UTMIFSTRIM_ZP_CAL_Msk & (_UINT32_(value) << SFR_UTMIFSTRIM_ZP_CAL_Pos)) /* Assignment of value for ZP_CAL in the SFR_UTMIFSTRIM register */
#define SFR_UTMIFSTRIM_Msk                    _UINT32_(0x77770000)                                 /* (SFR_UTMIFSTRIM) Register Mask  */


/* -------- SFR_UTMISWAP : (SFR Offset: 0x3C) (R/W 32) UTMI DP/DM Pin Swapping Register -------- */
#define SFR_UTMISWAP_RESETVALUE               _UINT32_(0x00)                                       /*  (SFR_UTMISWAP) UTMI DP/DM Pin Swapping Register  Reset Value */

#define SFR_UTMISWAP_PORT0_Pos                _UINT32_(0)                                          /* (SFR_UTMISWAP) Port 0 DP/DM Pin Swapping Position */
#define SFR_UTMISWAP_PORT0_Msk                (_UINT32_(0x1) << SFR_UTMISWAP_PORT0_Pos)            /* (SFR_UTMISWAP) Port 0 DP/DM Pin Swapping Mask */
#define SFR_UTMISWAP_PORT0(value)             (SFR_UTMISWAP_PORT0_Msk & (_UINT32_(value) << SFR_UTMISWAP_PORT0_Pos)) /* Assignment of value for PORT0 in the SFR_UTMISWAP register */
#define   SFR_UTMISWAP_PORT0_NORMAL_Val       _UINT32_(0x0)                                        /* (SFR_UTMISWAP) DP/DM normal pinout  */
#define   SFR_UTMISWAP_PORT0_SWAPPED_Val      _UINT32_(0x1)                                        /* (SFR_UTMISWAP) DP/DM swapped pinout  */
#define SFR_UTMISWAP_PORT0_NORMAL             (SFR_UTMISWAP_PORT0_NORMAL_Val << SFR_UTMISWAP_PORT0_Pos) /* (SFR_UTMISWAP) DP/DM normal pinout Position */
#define SFR_UTMISWAP_PORT0_SWAPPED            (SFR_UTMISWAP_PORT0_SWAPPED_Val << SFR_UTMISWAP_PORT0_Pos) /* (SFR_UTMISWAP) DP/DM swapped pinout Position */
#define SFR_UTMISWAP_PORT1_Pos                _UINT32_(1)                                          /* (SFR_UTMISWAP) Port 1 DP/DM Pin Swapping Position */
#define SFR_UTMISWAP_PORT1_Msk                (_UINT32_(0x1) << SFR_UTMISWAP_PORT1_Pos)            /* (SFR_UTMISWAP) Port 1 DP/DM Pin Swapping Mask */
#define SFR_UTMISWAP_PORT1(value)             (SFR_UTMISWAP_PORT1_Msk & (_UINT32_(value) << SFR_UTMISWAP_PORT1_Pos)) /* Assignment of value for PORT1 in the SFR_UTMISWAP register */
#define   SFR_UTMISWAP_PORT1_NORMAL_Val       _UINT32_(0x0)                                        /* (SFR_UTMISWAP) DP/DM normal pinout  */
#define   SFR_UTMISWAP_PORT1_SWAPPED_Val      _UINT32_(0x1)                                        /* (SFR_UTMISWAP) DP/DM swapped pinout  */
#define SFR_UTMISWAP_PORT1_NORMAL             (SFR_UTMISWAP_PORT1_NORMAL_Val << SFR_UTMISWAP_PORT1_Pos) /* (SFR_UTMISWAP) DP/DM normal pinout Position */
#define SFR_UTMISWAP_PORT1_SWAPPED            (SFR_UTMISWAP_PORT1_SWAPPED_Val << SFR_UTMISWAP_PORT1_Pos) /* (SFR_UTMISWAP) DP/DM swapped pinout Position */
#define SFR_UTMISWAP_PORT2_Pos                _UINT32_(2)                                          /* (SFR_UTMISWAP) Port 2 DP/DM Pin Swapping Position */
#define SFR_UTMISWAP_PORT2_Msk                (_UINT32_(0x1) << SFR_UTMISWAP_PORT2_Pos)            /* (SFR_UTMISWAP) Port 2 DP/DM Pin Swapping Mask */
#define SFR_UTMISWAP_PORT2(value)             (SFR_UTMISWAP_PORT2_Msk & (_UINT32_(value) << SFR_UTMISWAP_PORT2_Pos)) /* Assignment of value for PORT2 in the SFR_UTMISWAP register */
#define   SFR_UTMISWAP_PORT2_NORMAL_Val       _UINT32_(0x0)                                        /* (SFR_UTMISWAP) DP/DM normal pinout  */
#define   SFR_UTMISWAP_PORT2_SWAPPED_Val      _UINT32_(0x1)                                        /* (SFR_UTMISWAP) DP/DM swapped pinout  */
#define SFR_UTMISWAP_PORT2_NORMAL             (SFR_UTMISWAP_PORT2_NORMAL_Val << SFR_UTMISWAP_PORT2_Pos) /* (SFR_UTMISWAP) DP/DM normal pinout Position */
#define SFR_UTMISWAP_PORT2_SWAPPED            (SFR_UTMISWAP_PORT2_SWAPPED_Val << SFR_UTMISWAP_PORT2_Pos) /* (SFR_UTMISWAP) DP/DM swapped pinout Position */
#define SFR_UTMISWAP_Msk                      _UINT32_(0x00000007)                                 /* (SFR_UTMISWAP) Register Mask  */

#define SFR_UTMISWAP_PORT_Pos                 _UINT32_(0)                                          /* (SFR_UTMISWAP Position) Port 2 DP/DM Pin Swapping */
#define SFR_UTMISWAP_PORT_Msk                 (_UINT32_(0x7) << SFR_UTMISWAP_PORT_Pos)             /* (SFR_UTMISWAP Mask) PORT */
#define SFR_UTMISWAP_PORT(value)              (SFR_UTMISWAP_PORT_Msk & (_UINT32_(value) << SFR_UTMISWAP_PORT_Pos)) 

/* -------- SFR_LS : (SFR Offset: 0xA0) (R/W 32) Light Sleep Register -------- */
#define SFR_LS_RESETVALUE                     _UINT32_(0x00)                                       /*  (SFR_LS) Light Sleep Register  Reset Value */

#define SFR_LS_LS0_Pos                        _UINT32_(0)                                          /* (SFR_LS) Light Sleep Value (GFX2D) Position */
#define SFR_LS_LS0_Msk                        (_UINT32_(0x1) << SFR_LS_LS0_Pos)                    /* (SFR_LS) Light Sleep Value (GFX2D) Mask */
#define SFR_LS_LS0(value)                     (SFR_LS_LS0_Msk & (_UINT32_(value) << SFR_LS_LS0_Pos)) /* Assignment of value for LS0 in the SFR_LS register */
#define SFR_LS_LS1_Pos                        _UINT32_(1)                                          /* (SFR_LS) Light Sleep Value (LCDC) Position */
#define SFR_LS_LS1_Msk                        (_UINT32_(0x1) << SFR_LS_LS1_Pos)                    /* (SFR_LS) Light Sleep Value (LCDC) Mask */
#define SFR_LS_LS1(value)                     (SFR_LS_LS1_Msk & (_UINT32_(value) << SFR_LS_LS1_Pos)) /* Assignment of value for LS1 in the SFR_LS register */
#define SFR_LS_LS2_Pos                        _UINT32_(2)                                          /* (SFR_LS) Light Sleep Value (SDMMC) Position */
#define SFR_LS_LS2_Msk                        (_UINT32_(0x1) << SFR_LS_LS2_Pos)                    /* (SFR_LS) Light Sleep Value (SDMMC) Mask */
#define SFR_LS_LS2(value)                     (SFR_LS_LS2_Msk & (_UINT32_(value) << SFR_LS_LS2_Pos)) /* Assignment of value for LS2 in the SFR_LS register */
#define SFR_LS_LS3_Pos                        _UINT32_(3)                                          /* (SFR_LS) Light Sleep Value (UDPHS) Position */
#define SFR_LS_LS3_Msk                        (_UINT32_(0x1) << SFR_LS_LS3_Pos)                    /* (SFR_LS) Light Sleep Value (UDPHS) Mask */
#define SFR_LS_LS3(value)                     (SFR_LS_LS3_Msk & (_UINT32_(value) << SFR_LS_LS3_Pos)) /* Assignment of value for LS3 in the SFR_LS register */
#define SFR_LS_LS4_Pos                        _UINT32_(4)                                          /* (SFR_LS) Light Sleep Value (XDMAC) Position */
#define SFR_LS_LS4_Msk                        (_UINT32_(0x1) << SFR_LS_LS4_Pos)                    /* (SFR_LS) Light Sleep Value (XDMAC) Mask */
#define SFR_LS_LS4(value)                     (SFR_LS_LS4_Msk & (_UINT32_(value) << SFR_LS_LS4_Pos)) /* Assignment of value for LS4 in the SFR_LS register */
#define SFR_LS_LS5_Pos                        _UINT32_(5)                                          /* (SFR_LS) Light Sleep Value (UHPHS) Position */
#define SFR_LS_LS5_Msk                        (_UINT32_(0x1) << SFR_LS_LS5_Pos)                    /* (SFR_LS) Light Sleep Value (UHPHS) Mask */
#define SFR_LS_LS5(value)                     (SFR_LS_LS5_Msk & (_UINT32_(value) << SFR_LS_LS5_Pos)) /* Assignment of value for LS5 in the SFR_LS register */
#define SFR_LS_LS6_Pos                        _UINT32_(6)                                          /* (SFR_LS) Light Sleep Value (FLEXRAM0) Position */
#define SFR_LS_LS6_Msk                        (_UINT32_(0x1) << SFR_LS_LS6_Pos)                    /* (SFR_LS) Light Sleep Value (FLEXRAM0) Mask */
#define SFR_LS_LS6(value)                     (SFR_LS_LS6_Msk & (_UINT32_(value) << SFR_LS_LS6_Pos)) /* Assignment of value for LS6 in the SFR_LS register */
#define SFR_LS_LS7_Pos                        _UINT32_(7)                                          /* (SFR_LS) Light Sleep Value (FLEXRAM1 (OTPC)) Position */
#define SFR_LS_LS7_Msk                        (_UINT32_(0x1) << SFR_LS_LS7_Pos)                    /* (SFR_LS) Light Sleep Value (FLEXRAM1 (OTPC)) Mask */
#define SFR_LS_LS7(value)                     (SFR_LS_LS7_Msk & (_UINT32_(value) << SFR_LS_LS7_Pos)) /* Assignment of value for LS7 in the SFR_LS register */
#define SFR_LS_LS8_Pos                        _UINT32_(8)                                          /* (SFR_LS) Light Sleep Value (ROM + OTPC) Position */
#define SFR_LS_LS8_Msk                        (_UINT32_(0x1) << SFR_LS_LS8_Pos)                    /* (SFR_LS) Light Sleep Value (ROM + OTPC) Mask */
#define SFR_LS_LS8(value)                     (SFR_LS_LS8_Msk & (_UINT32_(value) << SFR_LS_LS8_Pos)) /* Assignment of value for LS8 in the SFR_LS register */
#define SFR_LS_LS9_Pos                        _UINT32_(9)                                          /* (SFR_LS) Light Sleep Value (ARM926) Position */
#define SFR_LS_LS9_Msk                        (_UINT32_(0x1) << SFR_LS_LS9_Pos)                    /* (SFR_LS) Light Sleep Value (ARM926) Mask */
#define SFR_LS_LS9(value)                     (SFR_LS_LS9_Msk & (_UINT32_(value) << SFR_LS_LS9_Pos)) /* Assignment of value for LS9 in the SFR_LS register */
#define SFR_LS_LS10_Pos                       _UINT32_(10)                                         /* (SFR_LS) Light Sleep Value (CSI2DC) Position */
#define SFR_LS_LS10_Msk                       (_UINT32_(0x1) << SFR_LS_LS10_Pos)                   /* (SFR_LS) Light Sleep Value (CSI2DC) Mask */
#define SFR_LS_LS10(value)                    (SFR_LS_LS10_Msk & (_UINT32_(value) << SFR_LS_LS10_Pos)) /* Assignment of value for LS10 in the SFR_LS register */
#define SFR_LS_LS11_Pos                       _UINT32_(11)                                         /* (SFR_LS) Light Sleep Value (ISC) Position */
#define SFR_LS_LS11_Msk                       (_UINT32_(0x1) << SFR_LS_LS11_Pos)                   /* (SFR_LS) Light Sleep Value (ISC) Mask */
#define SFR_LS_LS11(value)                    (SFR_LS_LS11_Msk & (_UINT32_(value) << SFR_LS_LS11_Pos)) /* Assignment of value for LS11 in the SFR_LS register */
#define SFR_LS_LS12_Pos                       _UINT32_(12)                                         /* (SFR_LS) Light Sleep Value (DSI) Position */
#define SFR_LS_LS12_Msk                       (_UINT32_(0x1) << SFR_LS_LS12_Pos)                   /* (SFR_LS) Light Sleep Value (DSI) Mask */
#define SFR_LS_LS12(value)                    (SFR_LS_LS12_Msk & (_UINT32_(value) << SFR_LS_LS12_Pos)) /* Assignment of value for LS12 in the SFR_LS register */
#define SFR_LS_LS13_Pos                       _UINT32_(13)                                         /* (SFR_LS) Light Sleep Value (GMAC) Position */
#define SFR_LS_LS13_Msk                       (_UINT32_(0x1) << SFR_LS_LS13_Pos)                   /* (SFR_LS) Light Sleep Value (GMAC) Mask */
#define SFR_LS_LS13(value)                    (SFR_LS_LS13_Msk & (_UINT32_(value) << SFR_LS_LS13_Pos)) /* Assignment of value for LS13 in the SFR_LS register */
#define SFR_LS_MEM_POWER_GATING_ULP1_EN_Pos   _UINT32_(16)                                         /* (SFR_LS) Light Sleep Value for ULP1 Power-Gated Memories Position */
#define SFR_LS_MEM_POWER_GATING_ULP1_EN_Msk   (_UINT32_(0x1) << SFR_LS_MEM_POWER_GATING_ULP1_EN_Pos) /* (SFR_LS) Light Sleep Value for ULP1 Power-Gated Memories Mask */
#define SFR_LS_MEM_POWER_GATING_ULP1_EN(value) (SFR_LS_MEM_POWER_GATING_ULP1_EN_Msk & (_UINT32_(value) << SFR_LS_MEM_POWER_GATING_ULP1_EN_Pos)) /* Assignment of value for MEM_POWER_GATING_ULP1_EN in the SFR_LS register */
#define   SFR_LS_MEM_POWER_GATING_ULP1_EN_0_Val _UINT32_(0x0)                                        /* (SFR_LS) Light Sleep mode is not activated by the MEM_POWER_GATING_ULP1 output signal from the PMC.  */
#define   SFR_LS_MEM_POWER_GATING_ULP1_EN_1_Val _UINT32_(0x1)                                        /* (SFR_LS) Light Sleep mode is activated when the MEM_POWER_GATING_ULP1 output signal from the PMC is activated.  */
#define SFR_LS_MEM_POWER_GATING_ULP1_EN_0     (SFR_LS_MEM_POWER_GATING_ULP1_EN_0_Val << SFR_LS_MEM_POWER_GATING_ULP1_EN_Pos) /* (SFR_LS) Light Sleep mode is not activated by the MEM_POWER_GATING_ULP1 output signal from the PMC. Position */
#define SFR_LS_MEM_POWER_GATING_ULP1_EN_1     (SFR_LS_MEM_POWER_GATING_ULP1_EN_1_Val << SFR_LS_MEM_POWER_GATING_ULP1_EN_Pos) /* (SFR_LS) Light Sleep mode is activated when the MEM_POWER_GATING_ULP1 output signal from the PMC is activated. Position */
#define SFR_LS_Msk                            _UINT32_(0x00013FFF)                                 /* (SFR_LS) Register Mask  */

#define SFR_LS_LS_Pos                         _UINT32_(0)                                          /* (SFR_LS Position) Light Sleep Value (GFX2D) */
#define SFR_LS_LS_Msk                         (_UINT32_(0x3FFF) << SFR_LS_LS_Pos)                  /* (SFR_LS Mask) LS */
#define SFR_LS_LS(value)                      (SFR_LS_LS_Msk & (_UINT32_(value) << SFR_LS_LS_Pos)) 

/* -------- SFR_CAL1 : (SFR Offset: 0xB4) (R/W 32) I/O Calibration 1 Register -------- */
#define SFR_CAL1_RESETVALUE                   _UINT32_(0x84)                                       /*  (SFR_CAL1) I/O Calibration 1 Register  Reset Value */

#define SFR_CAL1_CALN_M_Pos                   _UINT32_(0)                                          /* (SFR_CAL1) Calibration of Low Level Output Impedance of Pads with VDDIOM Supply Position */
#define SFR_CAL1_CALN_M_Msk                   (_UINT32_(0xF) << SFR_CAL1_CALN_M_Pos)               /* (SFR_CAL1) Calibration of Low Level Output Impedance of Pads with VDDIOM Supply Mask */
#define SFR_CAL1_CALN_M(value)                (SFR_CAL1_CALN_M_Msk & (_UINT32_(value) << SFR_CAL1_CALN_M_Pos)) /* Assignment of value for CALN_M in the SFR_CAL1 register */
#define SFR_CAL1_CALP_M_Pos                   _UINT32_(4)                                          /* (SFR_CAL1) Calibration of High Level Output Impedance of Pads with VDDIOM Supply Position */
#define SFR_CAL1_CALP_M_Msk                   (_UINT32_(0xF) << SFR_CAL1_CALP_M_Pos)               /* (SFR_CAL1) Calibration of High Level Output Impedance of Pads with VDDIOM Supply Mask */
#define SFR_CAL1_CALP_M(value)                (SFR_CAL1_CALP_M_Msk & (_UINT32_(value) << SFR_CAL1_CALP_M_Pos)) /* Assignment of value for CALP_M in the SFR_CAL1 register */
#define SFR_CAL1_TEST_M_Pos                   _UINT32_(8)                                          /* (SFR_CAL1) Enable Calibration of Low/High Level Output Impedance of Pads with VDDIOM Supply Position */
#define SFR_CAL1_TEST_M_Msk                   (_UINT32_(0x1) << SFR_CAL1_TEST_M_Pos)               /* (SFR_CAL1) Enable Calibration of Low/High Level Output Impedance of Pads with VDDIOM Supply Mask */
#define SFR_CAL1_TEST_M(value)                (SFR_CAL1_TEST_M_Msk & (_UINT32_(value) << SFR_CAL1_TEST_M_Pos)) /* Assignment of value for TEST_M in the SFR_CAL1 register */
#define SFR_CAL1_Msk                          _UINT32_(0x000001FF)                                 /* (SFR_CAL1) Register Mask  */


/* -------- SFR_WPMR : (SFR Offset: 0xE4) (R/W 32) Write Protection Mode Register -------- */
#define SFR_WPMR_RESETVALUE                   _UINT32_(0x00)                                       /*  (SFR_WPMR) Write Protection Mode Register  Reset Value */

#define SFR_WPMR_WPEN_Pos                     _UINT32_(0)                                          /* (SFR_WPMR) Write Protection Enable Position */
#define SFR_WPMR_WPEN_Msk                     (_UINT32_(0x1) << SFR_WPMR_WPEN_Pos)                 /* (SFR_WPMR) Write Protection Enable Mask */
#define SFR_WPMR_WPEN(value)                  (SFR_WPMR_WPEN_Msk & (_UINT32_(value) << SFR_WPMR_WPEN_Pos)) /* Assignment of value for WPEN in the SFR_WPMR register */
#define   SFR_WPMR_WPEN_0_Val                 _UINT32_(0x0)                                        /* (SFR_WPMR) Disables write protection if WPKEY corresponds to 0x534652 ("SFR" in ASCII).  */
#define   SFR_WPMR_WPEN_1_Val                 _UINT32_(0x1)                                        /* (SFR_WPMR) Enables write protection if WPKEY corresponds to 0x534652 ("SFR" in ASCII).  */
#define SFR_WPMR_WPEN_0                       (SFR_WPMR_WPEN_0_Val << SFR_WPMR_WPEN_Pos)           /* (SFR_WPMR) Disables write protection if WPKEY corresponds to 0x534652 ("SFR" in ASCII). Position */
#define SFR_WPMR_WPEN_1                       (SFR_WPMR_WPEN_1_Val << SFR_WPMR_WPEN_Pos)           /* (SFR_WPMR) Enables write protection if WPKEY corresponds to 0x534652 ("SFR" in ASCII). Position */
#define SFR_WPMR_WPKEY_Pos                    _UINT32_(8)                                          /* (SFR_WPMR) Write Protection Key Position */
#define SFR_WPMR_WPKEY_Msk                    (_UINT32_(0xFFFFFF) << SFR_WPMR_WPKEY_Pos)           /* (SFR_WPMR) Write Protection Key Mask */
#define SFR_WPMR_WPKEY(value)                 (SFR_WPMR_WPKEY_Msk & (_UINT32_(value) << SFR_WPMR_WPKEY_Pos)) /* Assignment of value for WPKEY in the SFR_WPMR register */
#define   SFR_WPMR_WPKEY_PASSWD_Val           _UINT32_(0x534652)                                   /* (SFR_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit. Always reads as 0.  */
#define SFR_WPMR_WPKEY_PASSWD                 (SFR_WPMR_WPKEY_PASSWD_Val << SFR_WPMR_WPKEY_Pos)    /* (SFR_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit. Always reads as 0. Position */
#define SFR_WPMR_Msk                          _UINT32_(0xFFFFFF01)                                 /* (SFR_WPMR) Register Mask  */


/* -------- SFR_PUFCTL : (SFR Offset: 0x200) (R/W 32) Control Register for PUFSRAM domain -------- */
#define SFR_PUFCTL_RESETVALUE                 _UINT32_(0x148)                                      /*  (SFR_PUFCTL) Control Register for PUFSRAM domain  Reset Value */

#define SFR_PUFCTL_PONOFFM_Pos                _UINT32_(0)                                          /* (SFR_PUFCTL) PUFSRAM Power Switches Controlled Manually Position */
#define SFR_PUFCTL_PONOFFM_Msk                (_UINT32_(0x1) << SFR_PUFCTL_PONOFFM_Pos)            /* (SFR_PUFCTL) PUFSRAM Power Switches Controlled Manually Mask */
#define SFR_PUFCTL_PONOFFM(value)             (SFR_PUFCTL_PONOFFM_Msk & (_UINT32_(value) << SFR_PUFCTL_PONOFFM_Pos)) /* Assignment of value for PONOFFM in the SFR_PUFCTL register */
#define   SFR_PUFCTL_PONOFFM_0_Val            _UINT32_(0x0)                                        /* (SFR_PUFCTL) Power switches are automatically controlled by SYSC at startup.  */
#define   SFR_PUFCTL_PONOFFM_1_Val            _UINT32_(0x1)                                        /* (SFR_PUFCTL) Power switches are manually controlled by the PONOFFLZ and PONOFFHZ bits.  */
#define SFR_PUFCTL_PONOFFM_0                  (SFR_PUFCTL_PONOFFM_0_Val << SFR_PUFCTL_PONOFFM_Pos) /* (SFR_PUFCTL) Power switches are automatically controlled by SYSC at startup. Position */
#define SFR_PUFCTL_PONOFFM_1                  (SFR_PUFCTL_PONOFFM_1_Val << SFR_PUFCTL_PONOFFM_Pos) /* (SFR_PUFCTL) Power switches are manually controlled by the PONOFFLZ and PONOFFHZ bits. Position */
#define SFR_PUFCTL_PONOFFHZ_Pos               _UINT32_(1)                                          /* (SFR_PUFCTL) Controls Power Switch High Z if PONOFFM=1 Position */
#define SFR_PUFCTL_PONOFFHZ_Msk               (_UINT32_(0x1) << SFR_PUFCTL_PONOFFHZ_Pos)           /* (SFR_PUFCTL) Controls Power Switch High Z if PONOFFM=1 Mask */
#define SFR_PUFCTL_PONOFFHZ(value)            (SFR_PUFCTL_PONOFFHZ_Msk & (_UINT32_(value) << SFR_PUFCTL_PONOFFHZ_Pos)) /* Assignment of value for PONOFFHZ in the SFR_PUFCTL register */
#define   SFR_PUFCTL_PONOFFHZ_0_Val           _UINT32_(0x0)                                        /* (SFR_PUFCTL) Power switch High Z is off.  */
#define   SFR_PUFCTL_PONOFFHZ_1_Val           _UINT32_(0x1)                                        /* (SFR_PUFCTL) Power switch High Z is on.  */
#define SFR_PUFCTL_PONOFFHZ_0                 (SFR_PUFCTL_PONOFFHZ_0_Val << SFR_PUFCTL_PONOFFHZ_Pos) /* (SFR_PUFCTL) Power switch High Z is off. Position */
#define SFR_PUFCTL_PONOFFHZ_1                 (SFR_PUFCTL_PONOFFHZ_1_Val << SFR_PUFCTL_PONOFFHZ_Pos) /* (SFR_PUFCTL) Power switch High Z is on. Position */
#define SFR_PUFCTL_PONOFFLZ_Pos               _UINT32_(2)                                          /* (SFR_PUFCTL) Controls Power Switch Low Z if PONOFFM=1 Position */
#define SFR_PUFCTL_PONOFFLZ_Msk               (_UINT32_(0x1) << SFR_PUFCTL_PONOFFLZ_Pos)           /* (SFR_PUFCTL) Controls Power Switch Low Z if PONOFFM=1 Mask */
#define SFR_PUFCTL_PONOFFLZ(value)            (SFR_PUFCTL_PONOFFLZ_Msk & (_UINT32_(value) << SFR_PUFCTL_PONOFFLZ_Pos)) /* Assignment of value for PONOFFLZ in the SFR_PUFCTL register */
#define   SFR_PUFCTL_PONOFFLZ_0_Val           _UINT32_(0x0)                                        /* (SFR_PUFCTL) Power switch Low Z is off.  */
#define   SFR_PUFCTL_PONOFFLZ_1_Val           _UINT32_(0x1)                                        /* (SFR_PUFCTL) Power switch Low Z is on.  */
#define SFR_PUFCTL_PONOFFLZ_0                 (SFR_PUFCTL_PONOFFLZ_0_Val << SFR_PUFCTL_PONOFFLZ_Pos) /* (SFR_PUFCTL) Power switch Low Z is off. Position */
#define SFR_PUFCTL_PONOFFLZ_1                 (SFR_PUFCTL_PONOFFLZ_1_Val << SFR_PUFCTL_PONOFFLZ_Pos) /* (SFR_PUFCTL) Power switch Low Z is on. Position */
#define SFR_PUFCTL_PUFRST_Pos                 _UINT32_(3)                                          /* (SFR_PUFCTL) Reset for PUF IP Position */
#define SFR_PUFCTL_PUFRST_Msk                 (_UINT32_(0x1) << SFR_PUFCTL_PUFRST_Pos)             /* (SFR_PUFCTL) Reset for PUF IP Mask */
#define SFR_PUFCTL_PUFRST(value)              (SFR_PUFCTL_PUFRST_Msk & (_UINT32_(value) << SFR_PUFCTL_PUFRST_Pos)) /* Assignment of value for PUFRST in the SFR_PUFCTL register */
#define   SFR_PUFCTL_PUFRST_0_Val             _UINT32_(0x0)                                        /* (SFR_PUFCTL) PUF is active.  */
#define   SFR_PUFCTL_PUFRST_1_Val             _UINT32_(0x1)                                        /* (SFR_PUFCTL) PUF is in Reset mode.  */
#define SFR_PUFCTL_PUFRST_0                   (SFR_PUFCTL_PUFRST_0_Val << SFR_PUFCTL_PUFRST_Pos)   /* (SFR_PUFCTL) PUF is active. Position */
#define SFR_PUFCTL_PUFRST_1                   (SFR_PUFCTL_PUFRST_1_Val << SFR_PUFCTL_PUFRST_Pos)   /* (SFR_PUFCTL) PUF is in Reset mode. Position */
#define SFR_PUFCTL_PUFDIS_Pos                 _UINT32_(4)                                          /* (SFR_PUFCTL) Disable the PUF Position */
#define SFR_PUFCTL_PUFDIS_Msk                 (_UINT32_(0x1) << SFR_PUFCTL_PUFDIS_Pos)             /* (SFR_PUFCTL) Disable the PUF Mask */
#define SFR_PUFCTL_PUFDIS(value)              (SFR_PUFCTL_PUFDIS_Msk & (_UINT32_(value) << SFR_PUFCTL_PUFDIS_Pos)) /* Assignment of value for PUFDIS in the SFR_PUFCTL register */
#define   SFR_PUFCTL_PUFDIS_0_Val             _UINT32_(0x0)                                        /* (SFR_PUFCTL) No effect  */
#define   SFR_PUFCTL_PUFDIS_1_Val             _UINT32_(0x1)                                        /* (SFR_PUFCTL) PUF clock and psel signals are disabled by HW and PUFSRAM domain is off.  */
#define SFR_PUFCTL_PUFDIS_0                   (SFR_PUFCTL_PUFDIS_0_Val << SFR_PUFCTL_PUFDIS_Pos)   /* (SFR_PUFCTL) No effect Position */
#define SFR_PUFCTL_PUFDIS_1                   (SFR_PUFCTL_PUFDIS_1_Val << SFR_PUFCTL_PUFDIS_Pos)   /* (SFR_PUFCTL) PUF clock and psel signals are disabled by HW and PUFSRAM domain is off. Position */
#define SFR_PUFCTL_PUFLTM_Pos                 _UINT32_(5)                                          /* (SFR_PUFCTL) PUF Lab Test Mode Position */
#define SFR_PUFCTL_PUFLTM_Msk                 (_UINT32_(0x1) << SFR_PUFCTL_PUFLTM_Pos)             /* (SFR_PUFCTL) PUF Lab Test Mode Mask */
#define SFR_PUFCTL_PUFLTM(value)              (SFR_PUFCTL_PUFLTM_Msk & (_UINT32_(value) << SFR_PUFCTL_PUFLTM_Pos)) /* Assignment of value for PUFLTM in the SFR_PUFCTL register */
#define   SFR_PUFCTL_PUFLTM_0_Val             _UINT32_(0x0)                                        /* (SFR_PUFCTL) No effect  */
#define   SFR_PUFCTL_PUFLTM_1_Val             _UINT32_(0x1)                                        /* (SFR_PUFCTL) Enters Test mode when PUFRST=0.  */
#define SFR_PUFCTL_PUFLTM_0                   (SFR_PUFCTL_PUFLTM_0_Val << SFR_PUFCTL_PUFLTM_Pos)   /* (SFR_PUFCTL) No effect Position */
#define SFR_PUFCTL_PUFLTM_1                   (SFR_PUFCTL_PUFLTM_1_Val << SFR_PUFCTL_PUFLTM_Pos)   /* (SFR_PUFCTL) Enters Test mode when PUFRST=0. Position */
#define SFR_PUFCTL_ALWAYSONE_Pos              _UINT32_(6)                                          /* (SFR_PUFCTL) Must always be programmed to 1 Position */
#define SFR_PUFCTL_ALWAYSONE_Msk              (_UINT32_(0x1) << SFR_PUFCTL_ALWAYSONE_Pos)          /* (SFR_PUFCTL) Must always be programmed to 1 Mask */
#define SFR_PUFCTL_ALWAYSONE(value)           (SFR_PUFCTL_ALWAYSONE_Msk & (_UINT32_(value) << SFR_PUFCTL_ALWAYSONE_Pos)) /* Assignment of value for ALWAYSONE in the SFR_PUFCTL register */
#define SFR_PUFCTL_PLG_Pos                    _UINT32_(8)                                          /* (SFR_PUFCTL) PUFSRAM Power Low Status (read-only) Position */
#define SFR_PUFCTL_PLG_Msk                    (_UINT32_(0x1) << SFR_PUFCTL_PLG_Pos)                /* (SFR_PUFCTL) PUFSRAM Power Low Status (read-only) Mask */
#define SFR_PUFCTL_PLG(value)                 (SFR_PUFCTL_PLG_Msk & (_UINT32_(value) << SFR_PUFCTL_PLG_Pos)) /* Assignment of value for PLG in the SFR_PUFCTL register */
#define   SFR_PUFCTL_PLG_0_Val                _UINT32_(0x0)                                        /* (SFR_PUFCTL) PUFSRAM domain is powered.  */
#define   SFR_PUFCTL_PLG_1_Val                _UINT32_(0x1)                                        /* (SFR_PUFCTL) PUFSRAM domain is not powered.  */
#define SFR_PUFCTL_PLG_0                      (SFR_PUFCTL_PLG_0_Val << SFR_PUFCTL_PLG_Pos)         /* (SFR_PUFCTL) PUFSRAM domain is powered. Position */
#define SFR_PUFCTL_PLG_1                      (SFR_PUFCTL_PLG_1_Val << SFR_PUFCTL_PLG_Pos)         /* (SFR_PUFCTL) PUFSRAM domain is not powered. Position */
#define SFR_PUFCTL_PHG_Pos                    _UINT32_(9)                                          /* (SFR_PUFCTL) PUFSRAM Power High Status (read-only) Position */
#define SFR_PUFCTL_PHG_Msk                    (_UINT32_(0x1) << SFR_PUFCTL_PHG_Pos)                /* (SFR_PUFCTL) PUFSRAM Power High Status (read-only) Mask */
#define SFR_PUFCTL_PHG(value)                 (SFR_PUFCTL_PHG_Msk & (_UINT32_(value) << SFR_PUFCTL_PHG_Pos)) /* Assignment of value for PHG in the SFR_PUFCTL register */
#define   SFR_PUFCTL_PHG_0_Val                _UINT32_(0x0)                                        /* (SFR_PUFCTL) PUFSRAM domain is not powered.  */
#define   SFR_PUFCTL_PHG_1_Val                _UINT32_(0x1)                                        /* (SFR_PUFCTL) PUFSRAM domain is powered.  */
#define SFR_PUFCTL_PHG_0                      (SFR_PUFCTL_PHG_0_Val << SFR_PUFCTL_PHG_Pos)         /* (SFR_PUFCTL) PUFSRAM domain is not powered. Position */
#define SFR_PUFCTL_PHG_1                      (SFR_PUFCTL_PHG_1_Val << SFR_PUFCTL_PHG_Pos)         /* (SFR_PUFCTL) PUFSRAM domain is powered. Position */
#define SFR_PUFCTL_Msk                        _UINT32_(0x0000037F)                                 /* (SFR_PUFCTL) Register Mask  */


/* -------- SFR_PUFDIS : (SFR Offset: 0x208) (R/W 32) PUF Disable Functions Register -------- */
#define SFR_PUFDIS_RESETVALUE                 _UINT32_(0x00)                                       /*  (SFR_PUFDIS) PUF Disable Functions Register  Reset Value */

#define SFR_PUFDIS_ENROLL_Pos                 _UINT32_(0)                                          /* (SFR_PUFDIS) Connected to qk_disable_enroll input for QK Position */
#define SFR_PUFDIS_ENROLL_Msk                 (_UINT32_(0x1) << SFR_PUFDIS_ENROLL_Pos)             /* (SFR_PUFDIS) Connected to qk_disable_enroll input for QK Mask */
#define SFR_PUFDIS_ENROLL(value)              (SFR_PUFDIS_ENROLL_Msk & (_UINT32_(value) << SFR_PUFDIS_ENROLL_Pos)) /* Assignment of value for ENROLL in the SFR_PUFDIS register */
#define SFR_PUFDIS_GENERATE_RANDOM_Pos        _UINT32_(1)                                          /* (SFR_PUFDIS) Connected to qk_disable_generate_random input for QK Position */
#define SFR_PUFDIS_GENERATE_RANDOM_Msk        (_UINT32_(0x1) << SFR_PUFDIS_GENERATE_RANDOM_Pos)    /* (SFR_PUFDIS) Connected to qk_disable_generate_random input for QK Mask */
#define SFR_PUFDIS_GENERATE_RANDOM(value)     (SFR_PUFDIS_GENERATE_RANDOM_Msk & (_UINT32_(value) << SFR_PUFDIS_GENERATE_RANDOM_Pos)) /* Assignment of value for GENERATE_RANDOM in the SFR_PUFDIS register */
#define SFR_PUFDIS_GET_KEY_Pos                _UINT32_(2)                                          /* (SFR_PUFDIS) Connected to qk_disable_get_key input for QK Position */
#define SFR_PUFDIS_GET_KEY_Msk                (_UINT32_(0x1) << SFR_PUFDIS_GET_KEY_Pos)            /* (SFR_PUFDIS) Connected to qk_disable_get_key input for QK Mask */
#define SFR_PUFDIS_GET_KEY(value)             (SFR_PUFDIS_GET_KEY_Msk & (_UINT32_(value) << SFR_PUFDIS_GET_KEY_Pos)) /* Assignment of value for GET_KEY in the SFR_PUFDIS register */
#define SFR_PUFDIS_START_Pos                  _UINT32_(3)                                          /* (SFR_PUFDIS) Connected to qk_disable_start input for QK Position */
#define SFR_PUFDIS_START_Msk                  (_UINT32_(0x1) << SFR_PUFDIS_START_Pos)              /* (SFR_PUFDIS) Connected to qk_disable_start input for QK Mask */
#define SFR_PUFDIS_START(value)               (SFR_PUFDIS_START_Msk & (_UINT32_(value) << SFR_PUFDIS_START_Pos)) /* Assignment of value for START in the SFR_PUFDIS register */
#define SFR_PUFDIS_STOP_Pos                   _UINT32_(4)                                          /* (SFR_PUFDIS) Connected to qk_disable_stop input for QK Position */
#define SFR_PUFDIS_STOP_Msk                   (_UINT32_(0x1) << SFR_PUFDIS_STOP_Pos)               /* (SFR_PUFDIS) Connected to qk_disable_stop input for QK Mask */
#define SFR_PUFDIS_STOP(value)                (SFR_PUFDIS_STOP_Msk & (_UINT32_(value) << SFR_PUFDIS_STOP_Pos)) /* Assignment of value for STOP in the SFR_PUFDIS register */
#define SFR_PUFDIS_TEST_PUF_Pos               _UINT32_(5)                                          /* (SFR_PUFDIS) Connected to qk_disable_test_puf input for QK Position */
#define SFR_PUFDIS_TEST_PUF_Msk               (_UINT32_(0x1) << SFR_PUFDIS_TEST_PUF_Pos)           /* (SFR_PUFDIS) Connected to qk_disable_test_puf input for QK Mask */
#define SFR_PUFDIS_TEST_PUF(value)            (SFR_PUFDIS_TEST_PUF_Msk & (_UINT32_(value) << SFR_PUFDIS_TEST_PUF_Pos)) /* Assignment of value for TEST_PUF in the SFR_PUFDIS register */
#define SFR_PUFDIS_UNWRAP_Pos                 _UINT32_(6)                                          /* (SFR_PUFDIS) Connected to qk_disable_unwrap input for QK Position */
#define SFR_PUFDIS_UNWRAP_Msk                 (_UINT32_(0x1) << SFR_PUFDIS_UNWRAP_Pos)             /* (SFR_PUFDIS) Connected to qk_disable_unwrap input for QK Mask */
#define SFR_PUFDIS_UNWRAP(value)              (SFR_PUFDIS_UNWRAP_Msk & (_UINT32_(value) << SFR_PUFDIS_UNWRAP_Pos)) /* Assignment of value for UNWRAP in the SFR_PUFDIS register */
#define SFR_PUFDIS_WRAP_Pos                   _UINT32_(7)                                          /* (SFR_PUFDIS) Connected to qk_disable_wrap input for QK Position */
#define SFR_PUFDIS_WRAP_Msk                   (_UINT32_(0x1) << SFR_PUFDIS_WRAP_Pos)               /* (SFR_PUFDIS) Connected to qk_disable_wrap input for QK Mask */
#define SFR_PUFDIS_WRAP(value)                (SFR_PUFDIS_WRAP_Msk & (_UINT32_(value) << SFR_PUFDIS_WRAP_Pos)) /* Assignment of value for WRAP in the SFR_PUFDIS register */
#define SFR_PUFDIS_WRAP_GENERATED_RANDOM_Pos  _UINT32_(8)                                          /* (SFR_PUFDIS) Connected to qk_disable_wrap_generated_random input for QK Position */
#define SFR_PUFDIS_WRAP_GENERATED_RANDOM_Msk  (_UINT32_(0x1) << SFR_PUFDIS_WRAP_GENERATED_RANDOM_Pos) /* (SFR_PUFDIS) Connected to qk_disable_wrap_generated_random input for QK Mask */
#define SFR_PUFDIS_WRAP_GENERATED_RANDOM(value) (SFR_PUFDIS_WRAP_GENERATED_RANDOM_Msk & (_UINT32_(value) << SFR_PUFDIS_WRAP_GENERATED_RANDOM_Pos)) /* Assignment of value for WRAP_GENERATED_RANDOM in the SFR_PUFDIS register */
#define SFR_PUFDIS_RECONSTRUCT_Pos            _UINT32_(9)                                          /* (SFR_PUFDIS) Connected to qk_disable_reconstruct input for QK Position */
#define SFR_PUFDIS_RECONSTRUCT_Msk            (_UINT32_(0x1) << SFR_PUFDIS_RECONSTRUCT_Pos)        /* (SFR_PUFDIS) Connected to qk_disable_reconstruct input for QK Mask */
#define SFR_PUFDIS_RECONSTRUCT(value)         (SFR_PUFDIS_RECONSTRUCT_Msk & (_UINT32_(value) << SFR_PUFDIS_RECONSTRUCT_Pos)) /* Assignment of value for RECONSTRUCT in the SFR_PUFDIS register */
#define SFR_PUFDIS_TEST_MEMORY_Pos            _UINT32_(10)                                         /* (SFR_PUFDIS) Connected to qk_disable_test_memory input for QK Position */
#define SFR_PUFDIS_TEST_MEMORY_Msk            (_UINT32_(0x1) << SFR_PUFDIS_TEST_MEMORY_Pos)        /* (SFR_PUFDIS) Connected to qk_disable_test_memory input for QK Mask */
#define SFR_PUFDIS_TEST_MEMORY(value)         (SFR_PUFDIS_TEST_MEMORY_Msk & (_UINT32_(value) << SFR_PUFDIS_TEST_MEMORY_Pos)) /* Assignment of value for TEST_MEMORY in the SFR_PUFDIS register */
#define SFR_PUFDIS_LAB_TEST_MODE_Pos          _UINT32_(11)                                         /* (SFR_PUFDIS) Connected to qk_disable_lab_test_mode input for QK Position */
#define SFR_PUFDIS_LAB_TEST_MODE_Msk          (_UINT32_(0x1) << SFR_PUFDIS_LAB_TEST_MODE_Pos)      /* (SFR_PUFDIS) Connected to qk_disable_lab_test_mode input for QK Mask */
#define SFR_PUFDIS_LAB_TEST_MODE(value)       (SFR_PUFDIS_LAB_TEST_MODE_Msk & (_UINT32_(value) << SFR_PUFDIS_LAB_TEST_MODE_Pos)) /* Assignment of value for LAB_TEST_MODE in the SFR_PUFDIS register */
#define SFR_PUFDIS_RESEED_Pos                 _UINT32_(12)                                         /* (SFR_PUFDIS) Connected to qk_disable_reseed input for QK Position */
#define SFR_PUFDIS_RESEED_Msk                 (_UINT32_(0x1) << SFR_PUFDIS_RESEED_Pos)             /* (SFR_PUFDIS) Connected to qk_disable_reseed input for QK Mask */
#define SFR_PUFDIS_RESEED(value)              (SFR_PUFDIS_RESEED_Msk & (_UINT32_(value) << SFR_PUFDIS_RESEED_Pos)) /* Assignment of value for RESEED in the SFR_PUFDIS register */
#define SFR_PUFDIS_Msk                        _UINT32_(0x00001FFF)                                 /* (SFR_PUFDIS) Register Mask  */


/* -------- SFR_PUFRUCR0 : (SFR Offset: 0x20C) (R/W 32) PUF Restrict User Context 0 Register -------- */
#define SFR_PUFRUCR0_RESETVALUE               _UINT32_(0x00)                                       /*  (SFR_PUFRUCR0) PUF Restrict User Context 0 Register  Reset Value */

#define SFR_PUFRUCR0_RESTRICT_USER_CONTEXT_0_Pos _UINT32_(0)                                          /* (SFR_PUFRUCR0) Value Connected to qk_restrict_user_context_0 input for QK Position */
#define SFR_PUFRUCR0_RESTRICT_USER_CONTEXT_0_Msk (_UINT32_(0xFFFFFFFF) << SFR_PUFRUCR0_RESTRICT_USER_CONTEXT_0_Pos) /* (SFR_PUFRUCR0) Value Connected to qk_restrict_user_context_0 input for QK Mask */
#define SFR_PUFRUCR0_RESTRICT_USER_CONTEXT_0(value) (SFR_PUFRUCR0_RESTRICT_USER_CONTEXT_0_Msk & (_UINT32_(value) << SFR_PUFRUCR0_RESTRICT_USER_CONTEXT_0_Pos)) /* Assignment of value for RESTRICT_USER_CONTEXT_0 in the SFR_PUFRUCR0 register */
#define SFR_PUFRUCR0_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (SFR_PUFRUCR0) Register Mask  */


/* -------- SFR_PUFRUCR1 : (SFR Offset: 0x210) (R/W 32) PUF Restrict User Context 1 Register -------- */
#define SFR_PUFRUCR1_RESETVALUE               _UINT32_(0x00)                                       /*  (SFR_PUFRUCR1) PUF Restrict User Context 1 Register  Reset Value */

#define SFR_PUFRUCR1_RESTRICT_USER_CONTEXT_1_Pos _UINT32_(0)                                          /* (SFR_PUFRUCR1) Value Connected to qk_restrict_user_context_1 input for QK Position */
#define SFR_PUFRUCR1_RESTRICT_USER_CONTEXT_1_Msk (_UINT32_(0xFFFFFFFF) << SFR_PUFRUCR1_RESTRICT_USER_CONTEXT_1_Pos) /* (SFR_PUFRUCR1) Value Connected to qk_restrict_user_context_1 input for QK Mask */
#define SFR_PUFRUCR1_RESTRICT_USER_CONTEXT_1(value) (SFR_PUFRUCR1_RESTRICT_USER_CONTEXT_1_Msk & (_UINT32_(value) << SFR_PUFRUCR1_RESTRICT_USER_CONTEXT_1_Pos)) /* Assignment of value for RESTRICT_USER_CONTEXT_1 in the SFR_PUFRUCR1 register */
#define SFR_PUFRUCR1_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (SFR_PUFRUCR1) Register Mask  */


/* -------- SFR_PUFWORUCR0 : (SFR Offset: 0x214) (R/W 32) PUF Restrict User Context 0 Write Ones Register -------- */
#define SFR_PUFWORUCR0_RESETVALUE             _UINT32_(0x00)                                       /*  (SFR_PUFWORUCR0) PUF Restrict User Context 0 Write Ones Register  Reset Value */

#define SFR_PUFWORUCR0_RESTRICT_USER_CONTEXT_0_WO_Pos _UINT32_(0)                                          /* (SFR_PUFWORUCR0) Value Connected to qk_restrict_user_context_0 input for QK Position */
#define SFR_PUFWORUCR0_RESTRICT_USER_CONTEXT_0_WO_Msk (_UINT32_(0xFFFFFFFF) << SFR_PUFWORUCR0_RESTRICT_USER_CONTEXT_0_WO_Pos) /* (SFR_PUFWORUCR0) Value Connected to qk_restrict_user_context_0 input for QK Mask */
#define SFR_PUFWORUCR0_RESTRICT_USER_CONTEXT_0_WO(value) (SFR_PUFWORUCR0_RESTRICT_USER_CONTEXT_0_WO_Msk & (_UINT32_(value) << SFR_PUFWORUCR0_RESTRICT_USER_CONTEXT_0_WO_Pos)) /* Assignment of value for RESTRICT_USER_CONTEXT_0_WO in the SFR_PUFWORUCR0 register */
#define SFR_PUFWORUCR0_Msk                    _UINT32_(0xFFFFFFFF)                                 /* (SFR_PUFWORUCR0) Register Mask  */


/* -------- SFR_PUFWORUCR1 : (SFR Offset: 0x218) (R/W 32) PUF Restrict User Context 1 Write Ones Register -------- */
#define SFR_PUFWORUCR1_RESETVALUE             _UINT32_(0x00)                                       /*  (SFR_PUFWORUCR1) PUF Restrict User Context 1 Write Ones Register  Reset Value */

#define SFR_PUFWORUCR1_RESTRICT_USER_CONTEXT_1_WO_Pos _UINT32_(0)                                          /* (SFR_PUFWORUCR1) Value Connected to qk_restrict_user_context_1 input for QK Position */
#define SFR_PUFWORUCR1_RESTRICT_USER_CONTEXT_1_WO_Msk (_UINT32_(0xFFFFFFFF) << SFR_PUFWORUCR1_RESTRICT_USER_CONTEXT_1_WO_Pos) /* (SFR_PUFWORUCR1) Value Connected to qk_restrict_user_context_1 input for QK Mask */
#define SFR_PUFWORUCR1_RESTRICT_USER_CONTEXT_1_WO(value) (SFR_PUFWORUCR1_RESTRICT_USER_CONTEXT_1_WO_Msk & (_UINT32_(value) << SFR_PUFWORUCR1_RESTRICT_USER_CONTEXT_1_WO_Pos)) /* Assignment of value for RESTRICT_USER_CONTEXT_1_WO in the SFR_PUFWORUCR1 register */
#define SFR_PUFWORUCR1_Msk                    _UINT32_(0xFFFFFFFF)                                 /* (SFR_PUFWORUCR1) Register Mask  */


/* -------- SFR_FLEXRAMS_CLKG_DIS : (SFR Offset: 0x220) (R/W 32) FLEXRAMS Clock Gating Disable Register -------- */
#define SFR_FLEXRAMS_CLKG_DIS_RESETVALUE      _UINT32_(0x00)                                       /*  (SFR_FLEXRAMS_CLKG_DIS) FLEXRAMS Clock Gating Disable Register  Reset Value */

#define SFR_FLEXRAMS_CLKG_DIS_FLEX0_CLKG_DIS_Pos _UINT32_(0)                                          /* (SFR_FLEXRAMS_CLKG_DIS) Clock Gating Disable for FLEXRAM0 Position */
#define SFR_FLEXRAMS_CLKG_DIS_FLEX0_CLKG_DIS_Msk (_UINT32_(0x1) << SFR_FLEXRAMS_CLKG_DIS_FLEX0_CLKG_DIS_Pos) /* (SFR_FLEXRAMS_CLKG_DIS) Clock Gating Disable for FLEXRAM0 Mask */
#define SFR_FLEXRAMS_CLKG_DIS_FLEX0_CLKG_DIS(value) (SFR_FLEXRAMS_CLKG_DIS_FLEX0_CLKG_DIS_Msk & (_UINT32_(value) << SFR_FLEXRAMS_CLKG_DIS_FLEX0_CLKG_DIS_Pos)) /* Assignment of value for FLEX0_CLKG_DIS in the SFR_FLEXRAMS_CLKG_DIS register */
#define   SFR_FLEXRAMS_CLKG_DIS_FLEX0_CLKG_DIS_0_Val _UINT32_(0x0)                                        /* (SFR_FLEXRAMS_CLKG_DIS) Clock Gating is enabled.  */
#define   SFR_FLEXRAMS_CLKG_DIS_FLEX0_CLKG_DIS_1_Val _UINT32_(0x1)                                        /* (SFR_FLEXRAMS_CLKG_DIS) Clock Gating is disabled.  */
#define SFR_FLEXRAMS_CLKG_DIS_FLEX0_CLKG_DIS_0 (SFR_FLEXRAMS_CLKG_DIS_FLEX0_CLKG_DIS_0_Val << SFR_FLEXRAMS_CLKG_DIS_FLEX0_CLKG_DIS_Pos) /* (SFR_FLEXRAMS_CLKG_DIS) Clock Gating is enabled. Position */
#define SFR_FLEXRAMS_CLKG_DIS_FLEX0_CLKG_DIS_1 (SFR_FLEXRAMS_CLKG_DIS_FLEX0_CLKG_DIS_1_Val << SFR_FLEXRAMS_CLKG_DIS_FLEX0_CLKG_DIS_Pos) /* (SFR_FLEXRAMS_CLKG_DIS) Clock Gating is disabled. Position */
#define SFR_FLEXRAMS_CLKG_DIS_FLEX1_CLKG_DIS_Pos _UINT32_(1)                                          /* (SFR_FLEXRAMS_CLKG_DIS) Clock Gating Disable for FLEXRAM1 Position */
#define SFR_FLEXRAMS_CLKG_DIS_FLEX1_CLKG_DIS_Msk (_UINT32_(0x1) << SFR_FLEXRAMS_CLKG_DIS_FLEX1_CLKG_DIS_Pos) /* (SFR_FLEXRAMS_CLKG_DIS) Clock Gating Disable for FLEXRAM1 Mask */
#define SFR_FLEXRAMS_CLKG_DIS_FLEX1_CLKG_DIS(value) (SFR_FLEXRAMS_CLKG_DIS_FLEX1_CLKG_DIS_Msk & (_UINT32_(value) << SFR_FLEXRAMS_CLKG_DIS_FLEX1_CLKG_DIS_Pos)) /* Assignment of value for FLEX1_CLKG_DIS in the SFR_FLEXRAMS_CLKG_DIS register */
#define   SFR_FLEXRAMS_CLKG_DIS_FLEX1_CLKG_DIS_0_Val _UINT32_(0x0)                                        /* (SFR_FLEXRAMS_CLKG_DIS) Clock Gating is enabled.  */
#define   SFR_FLEXRAMS_CLKG_DIS_FLEX1_CLKG_DIS_1_Val _UINT32_(0x1)                                        /* (SFR_FLEXRAMS_CLKG_DIS) Clock Gating is disabled.  */
#define SFR_FLEXRAMS_CLKG_DIS_FLEX1_CLKG_DIS_0 (SFR_FLEXRAMS_CLKG_DIS_FLEX1_CLKG_DIS_0_Val << SFR_FLEXRAMS_CLKG_DIS_FLEX1_CLKG_DIS_Pos) /* (SFR_FLEXRAMS_CLKG_DIS) Clock Gating is enabled. Position */
#define SFR_FLEXRAMS_CLKG_DIS_FLEX1_CLKG_DIS_1 (SFR_FLEXRAMS_CLKG_DIS_FLEX1_CLKG_DIS_1_Val << SFR_FLEXRAMS_CLKG_DIS_FLEX1_CLKG_DIS_Pos) /* (SFR_FLEXRAMS_CLKG_DIS) Clock Gating is disabled. Position */
#define SFR_FLEXRAMS_CLKG_DIS_Msk             _UINT32_(0x00000003)                                 /* (SFR_FLEXRAMS_CLKG_DIS) Register Mask  */


/* -------- SFR_ISS_CFG : (SFR Offset: 0x240) (R/W 32) ISS Configuration Register -------- */
#define SFR_ISS_CFG_RESETVALUE                _UINT32_(0x00)                                       /*  (SFR_ISS_CFG) ISS Configuration Register  Reset Value */

#define SFR_ISS_CFG_MODE_Pos                  _UINT32_(0)                                          /* (SFR_ISS_CFG) DSI/CSI Selection Position */
#define SFR_ISS_CFG_MODE_Msk                  (_UINT32_(0x1) << SFR_ISS_CFG_MODE_Pos)              /* (SFR_ISS_CFG) DSI/CSI Selection Mask */
#define SFR_ISS_CFG_MODE(value)               (SFR_ISS_CFG_MODE_Msk & (_UINT32_(value) << SFR_ISS_CFG_MODE_Pos)) /* Assignment of value for MODE in the SFR_ISS_CFG register */
#define   SFR_ISS_CFG_MODE_CSI_Val            _UINT32_(0x0)                                        /* (SFR_ISS_CFG) CSI mode  */
#define   SFR_ISS_CFG_MODE_DSI_Val            _UINT32_(0x1)                                        /* (SFR_ISS_CFG) DSI mode  */
#define SFR_ISS_CFG_MODE_CSI                  (SFR_ISS_CFG_MODE_CSI_Val << SFR_ISS_CFG_MODE_Pos)   /* (SFR_ISS_CFG) CSI mode Position */
#define SFR_ISS_CFG_MODE_DSI                  (SFR_ISS_CFG_MODE_DSI_Val << SFR_ISS_CFG_MODE_Pos)   /* (SFR_ISS_CFG) DSI mode Position */
#define SFR_ISS_CFG_Msk                       _UINT32_(0x00000001)                                 /* (SFR_ISS_CFG) Register Mask  */


/* -------- SFR_TSU_CFG : (SFR Offset: 0x250) (R/W 32) TSU Configuration Register -------- */
#define SFR_TSU_CFG_RESETVALUE                _UINT32_(0x43)                                       /*  (SFR_TSU_CFG) TSU Configuration Register  Reset Value */

#define SFR_TSU_CFG_WIDTH_Pos                 _UINT32_(0)                                          /* (SFR_TSU_CFG) Number of TSU Cycles to Increase GTSUCOMP Width Position */
#define SFR_TSU_CFG_WIDTH_Msk                 (_UINT32_(0xFF) << SFR_TSU_CFG_WIDTH_Pos)            /* (SFR_TSU_CFG) Number of TSU Cycles to Increase GTSUCOMP Width Mask */
#define SFR_TSU_CFG_WIDTH(value)              (SFR_TSU_CFG_WIDTH_Msk & (_UINT32_(value) << SFR_TSU_CFG_WIDTH_Pos)) /* Assignment of value for WIDTH in the SFR_TSU_CFG register */
#define SFR_TSU_CFG_Msk                       _UINT32_(0x000000FF)                                 /* (SFR_TSU_CFG) Register Mask  */


/* -------- SFR_REMAP_MP_DDR : (SFR Offset: 0x260) (R/W 32) Remap Multiport DDR Register -------- */
#define SFR_REMAP_MP_DDR_RESETVALUE           _UINT32_(0x00)                                       /*  (SFR_REMAP_MP_DDR) Remap Multiport DDR Register  Reset Value */

#define SFR_REMAP_MP_DDR_Host_0_Pos           _UINT32_(0)                                          /* (SFR_REMAP_MP_DDR) Enable DDR Multiport Only for Host_0 Position */
#define SFR_REMAP_MP_DDR_Host_0_Msk           (_UINT32_(0x1) << SFR_REMAP_MP_DDR_Host_0_Pos)       /* (SFR_REMAP_MP_DDR) Enable DDR Multiport Only for Host_0 Mask */
#define SFR_REMAP_MP_DDR_Host_0(value)        (SFR_REMAP_MP_DDR_Host_0_Msk & (_UINT32_(value) << SFR_REMAP_MP_DDR_Host_0_Pos)) /* Assignment of value for Host_0 in the SFR_REMAP_MP_DDR register */
#define SFR_REMAP_MP_DDR_Host_1_Pos           _UINT32_(1)                                          /* (SFR_REMAP_MP_DDR) Enable DDR Multiport Only for Host_1 Position */
#define SFR_REMAP_MP_DDR_Host_1_Msk           (_UINT32_(0x1) << SFR_REMAP_MP_DDR_Host_1_Pos)       /* (SFR_REMAP_MP_DDR) Enable DDR Multiport Only for Host_1 Mask */
#define SFR_REMAP_MP_DDR_Host_1(value)        (SFR_REMAP_MP_DDR_Host_1_Msk & (_UINT32_(value) << SFR_REMAP_MP_DDR_Host_1_Pos)) /* Assignment of value for Host_1 in the SFR_REMAP_MP_DDR register */
#define SFR_REMAP_MP_DDR_Host_2_Pos           _UINT32_(2)                                          /* (SFR_REMAP_MP_DDR) Enable DDR Multiport Only for Host_2 Position */
#define SFR_REMAP_MP_DDR_Host_2_Msk           (_UINT32_(0x1) << SFR_REMAP_MP_DDR_Host_2_Pos)       /* (SFR_REMAP_MP_DDR) Enable DDR Multiport Only for Host_2 Mask */
#define SFR_REMAP_MP_DDR_Host_2(value)        (SFR_REMAP_MP_DDR_Host_2_Msk & (_UINT32_(value) << SFR_REMAP_MP_DDR_Host_2_Pos)) /* Assignment of value for Host_2 in the SFR_REMAP_MP_DDR register */
#define SFR_REMAP_MP_DDR_Host_3_Pos           _UINT32_(3)                                          /* (SFR_REMAP_MP_DDR) Enable DDR Multiport Only for Host_3 Position */
#define SFR_REMAP_MP_DDR_Host_3_Msk           (_UINT32_(0x1) << SFR_REMAP_MP_DDR_Host_3_Pos)       /* (SFR_REMAP_MP_DDR) Enable DDR Multiport Only for Host_3 Mask */
#define SFR_REMAP_MP_DDR_Host_3(value)        (SFR_REMAP_MP_DDR_Host_3_Msk & (_UINT32_(value) << SFR_REMAP_MP_DDR_Host_3_Pos)) /* Assignment of value for Host_3 in the SFR_REMAP_MP_DDR register */
#define SFR_REMAP_MP_DDR_Host_4_Pos           _UINT32_(4)                                          /* (SFR_REMAP_MP_DDR) Enable DDR Multiport Only for Host_4 Position */
#define SFR_REMAP_MP_DDR_Host_4_Msk           (_UINT32_(0x1) << SFR_REMAP_MP_DDR_Host_4_Pos)       /* (SFR_REMAP_MP_DDR) Enable DDR Multiport Only for Host_4 Mask */
#define SFR_REMAP_MP_DDR_Host_4(value)        (SFR_REMAP_MP_DDR_Host_4_Msk & (_UINT32_(value) << SFR_REMAP_MP_DDR_Host_4_Pos)) /* Assignment of value for Host_4 in the SFR_REMAP_MP_DDR register */
#define SFR_REMAP_MP_DDR_Host_5_Pos           _UINT32_(5)                                          /* (SFR_REMAP_MP_DDR) Enable DDR Multiport Only for Host_5 Position */
#define SFR_REMAP_MP_DDR_Host_5_Msk           (_UINT32_(0x1) << SFR_REMAP_MP_DDR_Host_5_Pos)       /* (SFR_REMAP_MP_DDR) Enable DDR Multiport Only for Host_5 Mask */
#define SFR_REMAP_MP_DDR_Host_5(value)        (SFR_REMAP_MP_DDR_Host_5_Msk & (_UINT32_(value) << SFR_REMAP_MP_DDR_Host_5_Pos)) /* Assignment of value for Host_5 in the SFR_REMAP_MP_DDR register */
#define SFR_REMAP_MP_DDR_Host_6_Pos           _UINT32_(6)                                          /* (SFR_REMAP_MP_DDR) Enable DDR Multiport Only for Host_6 Position */
#define SFR_REMAP_MP_DDR_Host_6_Msk           (_UINT32_(0x1) << SFR_REMAP_MP_DDR_Host_6_Pos)       /* (SFR_REMAP_MP_DDR) Enable DDR Multiport Only for Host_6 Mask */
#define SFR_REMAP_MP_DDR_Host_6(value)        (SFR_REMAP_MP_DDR_Host_6_Msk & (_UINT32_(value) << SFR_REMAP_MP_DDR_Host_6_Pos)) /* Assignment of value for Host_6 in the SFR_REMAP_MP_DDR register */
#define SFR_REMAP_MP_DDR_Host_7_Pos           _UINT32_(7)                                          /* (SFR_REMAP_MP_DDR) Enable DDR Multiport Only for Host_7 Position */
#define SFR_REMAP_MP_DDR_Host_7_Msk           (_UINT32_(0x1) << SFR_REMAP_MP_DDR_Host_7_Pos)       /* (SFR_REMAP_MP_DDR) Enable DDR Multiport Only for Host_7 Mask */
#define SFR_REMAP_MP_DDR_Host_7(value)        (SFR_REMAP_MP_DDR_Host_7_Msk & (_UINT32_(value) << SFR_REMAP_MP_DDR_Host_7_Pos)) /* Assignment of value for Host_7 in the SFR_REMAP_MP_DDR register */
#define SFR_REMAP_MP_DDR_Host_8_Pos           _UINT32_(8)                                          /* (SFR_REMAP_MP_DDR) Enable DDR Multiport Only for Host_8 Position */
#define SFR_REMAP_MP_DDR_Host_8_Msk           (_UINT32_(0x1) << SFR_REMAP_MP_DDR_Host_8_Pos)       /* (SFR_REMAP_MP_DDR) Enable DDR Multiport Only for Host_8 Mask */
#define SFR_REMAP_MP_DDR_Host_8(value)        (SFR_REMAP_MP_DDR_Host_8_Msk & (_UINT32_(value) << SFR_REMAP_MP_DDR_Host_8_Pos)) /* Assignment of value for Host_8 in the SFR_REMAP_MP_DDR register */
#define SFR_REMAP_MP_DDR_Host_9_Pos           _UINT32_(9)                                          /* (SFR_REMAP_MP_DDR) Enable DDR Multiport Only for Host_9 Position */
#define SFR_REMAP_MP_DDR_Host_9_Msk           (_UINT32_(0x1) << SFR_REMAP_MP_DDR_Host_9_Pos)       /* (SFR_REMAP_MP_DDR) Enable DDR Multiport Only for Host_9 Mask */
#define SFR_REMAP_MP_DDR_Host_9(value)        (SFR_REMAP_MP_DDR_Host_9_Msk & (_UINT32_(value) << SFR_REMAP_MP_DDR_Host_9_Pos)) /* Assignment of value for Host_9 in the SFR_REMAP_MP_DDR register */
#define SFR_REMAP_MP_DDR_Host_10_Pos          _UINT32_(10)                                         /* (SFR_REMAP_MP_DDR) Enable DDR Multiport Only for Host_10 Position */
#define SFR_REMAP_MP_DDR_Host_10_Msk          (_UINT32_(0x1) << SFR_REMAP_MP_DDR_Host_10_Pos)      /* (SFR_REMAP_MP_DDR) Enable DDR Multiport Only for Host_10 Mask */
#define SFR_REMAP_MP_DDR_Host_10(value)       (SFR_REMAP_MP_DDR_Host_10_Msk & (_UINT32_(value) << SFR_REMAP_MP_DDR_Host_10_Pos)) /* Assignment of value for Host_10 in the SFR_REMAP_MP_DDR register */
#define SFR_REMAP_MP_DDR_Host_11_Pos          _UINT32_(11)                                         /* (SFR_REMAP_MP_DDR) Enable DDR Multiport Only for Host_11 Position */
#define SFR_REMAP_MP_DDR_Host_11_Msk          (_UINT32_(0x1) << SFR_REMAP_MP_DDR_Host_11_Pos)      /* (SFR_REMAP_MP_DDR) Enable DDR Multiport Only for Host_11 Mask */
#define SFR_REMAP_MP_DDR_Host_11(value)       (SFR_REMAP_MP_DDR_Host_11_Msk & (_UINT32_(value) << SFR_REMAP_MP_DDR_Host_11_Pos)) /* Assignment of value for Host_11 in the SFR_REMAP_MP_DDR register */
#define SFR_REMAP_MP_DDR_Host_12_Pos          _UINT32_(12)                                         /* (SFR_REMAP_MP_DDR) Enable DDR Multiport Only for Host_12 Position */
#define SFR_REMAP_MP_DDR_Host_12_Msk          (_UINT32_(0x1) << SFR_REMAP_MP_DDR_Host_12_Pos)      /* (SFR_REMAP_MP_DDR) Enable DDR Multiport Only for Host_12 Mask */
#define SFR_REMAP_MP_DDR_Host_12(value)       (SFR_REMAP_MP_DDR_Host_12_Msk & (_UINT32_(value) << SFR_REMAP_MP_DDR_Host_12_Pos)) /* Assignment of value for Host_12 in the SFR_REMAP_MP_DDR register */
#define SFR_REMAP_MP_DDR_Host_13_Pos          _UINT32_(13)                                         /* (SFR_REMAP_MP_DDR) Enable DDR Multiport Only for Host_13 Position */
#define SFR_REMAP_MP_DDR_Host_13_Msk          (_UINT32_(0x1) << SFR_REMAP_MP_DDR_Host_13_Pos)      /* (SFR_REMAP_MP_DDR) Enable DDR Multiport Only for Host_13 Mask */
#define SFR_REMAP_MP_DDR_Host_13(value)       (SFR_REMAP_MP_DDR_Host_13_Msk & (_UINT32_(value) << SFR_REMAP_MP_DDR_Host_13_Pos)) /* Assignment of value for Host_13 in the SFR_REMAP_MP_DDR register */
#define SFR_REMAP_MP_DDR_Msk                  _UINT32_(0x00003FFF)                                 /* (SFR_REMAP_MP_DDR) Register Mask  */

#define SFR_REMAP_MP_DDR_Host__Pos            _UINT32_(0)                                          /* (SFR_REMAP_MP_DDR Position) Enable DDR Multiport Only for Host_x3 */
#define SFR_REMAP_MP_DDR_Host__Msk            (_UINT32_(0x3FFF) << SFR_REMAP_MP_DDR_Host__Pos)     /* (SFR_REMAP_MP_DDR Mask) Host_ */
#define SFR_REMAP_MP_DDR_Host_(value)         (SFR_REMAP_MP_DDR_Host__Msk & (_UINT32_(value) << SFR_REMAP_MP_DDR_Host__Pos)) 

/* SFR register offsets definitions */
#define SFR_CCFG_EBICSA_REG_OFST       _UINT32_(0x04)      /* (SFR_CCFG_EBICSA) EBI Chip Select Register Offset */
#define SFR_OHCIICR_REG_OFST           _UINT32_(0x10)      /* (SFR_OHCIICR) OHCI Interrupt Configuration Register Offset */
#define SFR_OHCIISR_REG_OFST           _UINT32_(0x14)      /* (SFR_OHCIISR) OHCI Interrupt Status Register Offset */
#define SFR_UTMIHSTRIM_REG_OFST        _UINT32_(0x34)      /* (SFR_UTMIHSTRIM) UTMI High-Speed Trimming Register Offset */
#define SFR_UTMIFSTRIM_REG_OFST        _UINT32_(0x38)      /* (SFR_UTMIFSTRIM) UTMI Full-Speed Trimming Register Offset */
#define SFR_UTMISWAP_REG_OFST          _UINT32_(0x3C)      /* (SFR_UTMISWAP) UTMI DP/DM Pin Swapping Register Offset */
#define SFR_LS_REG_OFST                _UINT32_(0xA0)      /* (SFR_LS) Light Sleep Register Offset */
#define SFR_CAL1_REG_OFST              _UINT32_(0xB4)      /* (SFR_CAL1) I/O Calibration 1 Register Offset */
#define SFR_WPMR_REG_OFST              _UINT32_(0xE4)      /* (SFR_WPMR) Write Protection Mode Register Offset */
#define SFR_PUFCTL_REG_OFST            _UINT32_(0x200)     /* (SFR_PUFCTL) Control Register for PUFSRAM domain Offset */
#define SFR_PUFDIS_REG_OFST            _UINT32_(0x208)     /* (SFR_PUFDIS) PUF Disable Functions Register Offset */
#define SFR_PUFRUCR0_REG_OFST          _UINT32_(0x20C)     /* (SFR_PUFRUCR0) PUF Restrict User Context 0 Register Offset */
#define SFR_PUFRUCR1_REG_OFST          _UINT32_(0x210)     /* (SFR_PUFRUCR1) PUF Restrict User Context 1 Register Offset */
#define SFR_PUFWORUCR0_REG_OFST        _UINT32_(0x214)     /* (SFR_PUFWORUCR0) PUF Restrict User Context 0 Write Ones Register Offset */
#define SFR_PUFWORUCR1_REG_OFST        _UINT32_(0x218)     /* (SFR_PUFWORUCR1) PUF Restrict User Context 1 Write Ones Register Offset */
#define SFR_FLEXRAMS_CLKG_DIS_REG_OFST _UINT32_(0x220)     /* (SFR_FLEXRAMS_CLKG_DIS) FLEXRAMS Clock Gating Disable Register Offset */
#define SFR_ISS_CFG_REG_OFST           _UINT32_(0x240)     /* (SFR_ISS_CFG) ISS Configuration Register Offset */
#define SFR_TSU_CFG_REG_OFST           _UINT32_(0x250)     /* (SFR_TSU_CFG) TSU Configuration Register Offset */
#define SFR_REMAP_MP_DDR_REG_OFST      _UINT32_(0x260)     /* (SFR_REMAP_MP_DDR) Remap Multiport DDR Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/* SFR register API structure */
typedef struct
{  /* Special Function Registers */
  __I   uint8_t                        Reserved1[0x04];
  __IO  uint32_t                       SFR_CCFG_EBICSA;    /* Offset: 0x04 (R/W  32) EBI Chip Select Register */
  __I   uint8_t                        Reserved2[0x08];
  __IO  uint32_t                       SFR_OHCIICR;        /* Offset: 0x10 (R/W  32) OHCI Interrupt Configuration Register */
  __I   uint32_t                       SFR_OHCIISR;        /* Offset: 0x14 (R/   32) OHCI Interrupt Status Register */
  __I   uint8_t                        Reserved3[0x1C];
  __IO  uint32_t                       SFR_UTMIHSTRIM;     /* Offset: 0x34 (R/W  32) UTMI High-Speed Trimming Register */
  __IO  uint32_t                       SFR_UTMIFSTRIM;     /* Offset: 0x38 (R/W  32) UTMI Full-Speed Trimming Register */
  __IO  uint32_t                       SFR_UTMISWAP;       /* Offset: 0x3C (R/W  32) UTMI DP/DM Pin Swapping Register */
  __I   uint8_t                        Reserved4[0x60];
  __IO  uint32_t                       SFR_LS;             /* Offset: 0xA0 (R/W  32) Light Sleep Register */
  __I   uint8_t                        Reserved5[0x10];
  __IO  uint32_t                       SFR_CAL1;           /* Offset: 0xB4 (R/W  32) I/O Calibration 1 Register */
  __I   uint8_t                        Reserved6[0x2C];
  __IO  uint32_t                       SFR_WPMR;           /* Offset: 0xE4 (R/W  32) Write Protection Mode Register */
  __I   uint8_t                        Reserved7[0x118];
  __IO  uint32_t                       SFR_PUFCTL;         /* Offset: 0x200 (R/W  32) Control Register for PUFSRAM domain */
  __I   uint8_t                        Reserved8[0x04];
  __IO  uint32_t                       SFR_PUFDIS;         /* Offset: 0x208 (R/W  32) PUF Disable Functions Register */
  __IO  uint32_t                       SFR_PUFRUCR0;       /* Offset: 0x20C (R/W  32) PUF Restrict User Context 0 Register */
  __IO  uint32_t                       SFR_PUFRUCR1;       /* Offset: 0x210 (R/W  32) PUF Restrict User Context 1 Register */
  __IO  uint32_t                       SFR_PUFWORUCR0;     /* Offset: 0x214 (R/W  32) PUF Restrict User Context 0 Write Ones Register */
  __IO  uint32_t                       SFR_PUFWORUCR1;     /* Offset: 0x218 (R/W  32) PUF Restrict User Context 1 Write Ones Register */
  __I   uint8_t                        Reserved9[0x04];
  __IO  uint32_t                       SFR_FLEXRAMS_CLKG_DIS; /* Offset: 0x220 (R/W  32) FLEXRAMS Clock Gating Disable Register */
  __I   uint8_t                        Reserved10[0x1C];
  __IO  uint32_t                       SFR_ISS_CFG;        /* Offset: 0x240 (R/W  32) ISS Configuration Register */
  __I   uint8_t                        Reserved11[0x0C];
  __IO  uint32_t                       SFR_TSU_CFG;        /* Offset: 0x250 (R/W  32) TSU Configuration Register */
  __I   uint8_t                        Reserved12[0x0C];
  __IO  uint32_t                       SFR_REMAP_MP_DDR;   /* Offset: 0x260 (R/W  32) Remap Multiport DDR Register */
} sfr_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAM9X7_SFR_COMPONENT_H_ */
