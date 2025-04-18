/*
 * Component description for SMC
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

/*  file generated from device description file (ATDF) version 2024-06-25T17:22:56Z  */
#ifndef _SAM9X7_SMC_COMPONENT_H_
#define _SAM9X7_SMC_COMPONENT_H_

/* ************************************************************************** */
/*                      SOFTWARE API DEFINITION FOR SMC                       */
/* ************************************************************************** */

/* -------- SMC_SETUP : (SMC Offset: 0x00) (R/W 32) SMC Setup Register  -------- */
#define SMC_SETUP_RESETVALUE                  _UINT32_(0x1010101)                                  /*  (SMC_SETUP) SMC Setup Register   Reset Value */

#define SMC_SETUP_NWE_SETUP_Pos               _UINT32_(0)                                          /* (SMC_SETUP) NWE Setup Length Position */
#define SMC_SETUP_NWE_SETUP_Msk               (_UINT32_(0x3F) << SMC_SETUP_NWE_SETUP_Pos)          /* (SMC_SETUP) NWE Setup Length Mask */
#define SMC_SETUP_NWE_SETUP(value)            (SMC_SETUP_NWE_SETUP_Msk & (_UINT32_(value) << SMC_SETUP_NWE_SETUP_Pos)) /* Assignment of value for NWE_SETUP in the SMC_SETUP register */
#define SMC_SETUP_NCS_WR_SETUP_Pos            _UINT32_(8)                                          /* (SMC_SETUP) NCS Setup Length in WRITE Access Position */
#define SMC_SETUP_NCS_WR_SETUP_Msk            (_UINT32_(0x3F) << SMC_SETUP_NCS_WR_SETUP_Pos)       /* (SMC_SETUP) NCS Setup Length in WRITE Access Mask */
#define SMC_SETUP_NCS_WR_SETUP(value)         (SMC_SETUP_NCS_WR_SETUP_Msk & (_UINT32_(value) << SMC_SETUP_NCS_WR_SETUP_Pos)) /* Assignment of value for NCS_WR_SETUP in the SMC_SETUP register */
#define SMC_SETUP_NRD_SETUP_Pos               _UINT32_(16)                                         /* (SMC_SETUP) NRD Setup Length Position */
#define SMC_SETUP_NRD_SETUP_Msk               (_UINT32_(0x3F) << SMC_SETUP_NRD_SETUP_Pos)          /* (SMC_SETUP) NRD Setup Length Mask */
#define SMC_SETUP_NRD_SETUP(value)            (SMC_SETUP_NRD_SETUP_Msk & (_UINT32_(value) << SMC_SETUP_NRD_SETUP_Pos)) /* Assignment of value for NRD_SETUP in the SMC_SETUP register */
#define SMC_SETUP_NCS_RD_SETUP_Pos            _UINT32_(24)                                         /* (SMC_SETUP) NCS Setup Length in READ Access Position */
#define SMC_SETUP_NCS_RD_SETUP_Msk            (_UINT32_(0x3F) << SMC_SETUP_NCS_RD_SETUP_Pos)       /* (SMC_SETUP) NCS Setup Length in READ Access Mask */
#define SMC_SETUP_NCS_RD_SETUP(value)         (SMC_SETUP_NCS_RD_SETUP_Msk & (_UINT32_(value) << SMC_SETUP_NCS_RD_SETUP_Pos)) /* Assignment of value for NCS_RD_SETUP in the SMC_SETUP register */
#define SMC_SETUP_Msk                         _UINT32_(0x3F3F3F3F)                                 /* (SMC_SETUP) Register Mask  */


/* -------- SMC_PULSE : (SMC Offset: 0x04) (R/W 32) SMC Pulse Register  -------- */
#define SMC_PULSE_RESETVALUE                  _UINT32_(0x1010101)                                  /*  (SMC_PULSE) SMC Pulse Register   Reset Value */

#define SMC_PULSE_NWE_PULSE_Pos               _UINT32_(0)                                          /* (SMC_PULSE) NWE Pulse Length Position */
#define SMC_PULSE_NWE_PULSE_Msk               (_UINT32_(0x7F) << SMC_PULSE_NWE_PULSE_Pos)          /* (SMC_PULSE) NWE Pulse Length Mask */
#define SMC_PULSE_NWE_PULSE(value)            (SMC_PULSE_NWE_PULSE_Msk & (_UINT32_(value) << SMC_PULSE_NWE_PULSE_Pos)) /* Assignment of value for NWE_PULSE in the SMC_PULSE register */
#define SMC_PULSE_NCS_WR_PULSE_Pos            _UINT32_(8)                                          /* (SMC_PULSE) NCS Pulse Length in WRITE Access Position */
#define SMC_PULSE_NCS_WR_PULSE_Msk            (_UINT32_(0x7F) << SMC_PULSE_NCS_WR_PULSE_Pos)       /* (SMC_PULSE) NCS Pulse Length in WRITE Access Mask */
#define SMC_PULSE_NCS_WR_PULSE(value)         (SMC_PULSE_NCS_WR_PULSE_Msk & (_UINT32_(value) << SMC_PULSE_NCS_WR_PULSE_Pos)) /* Assignment of value for NCS_WR_PULSE in the SMC_PULSE register */
#define SMC_PULSE_NRD_PULSE_Pos               _UINT32_(16)                                         /* (SMC_PULSE) NRD Pulse Length Position */
#define SMC_PULSE_NRD_PULSE_Msk               (_UINT32_(0x7F) << SMC_PULSE_NRD_PULSE_Pos)          /* (SMC_PULSE) NRD Pulse Length Mask */
#define SMC_PULSE_NRD_PULSE(value)            (SMC_PULSE_NRD_PULSE_Msk & (_UINT32_(value) << SMC_PULSE_NRD_PULSE_Pos)) /* Assignment of value for NRD_PULSE in the SMC_PULSE register */
#define SMC_PULSE_NCS_RD_PULSE_Pos            _UINT32_(24)                                         /* (SMC_PULSE) NCS Pulse Length in READ Access Position */
#define SMC_PULSE_NCS_RD_PULSE_Msk            (_UINT32_(0x7F) << SMC_PULSE_NCS_RD_PULSE_Pos)       /* (SMC_PULSE) NCS Pulse Length in READ Access Mask */
#define SMC_PULSE_NCS_RD_PULSE(value)         (SMC_PULSE_NCS_RD_PULSE_Msk & (_UINT32_(value) << SMC_PULSE_NCS_RD_PULSE_Pos)) /* Assignment of value for NCS_RD_PULSE in the SMC_PULSE register */
#define SMC_PULSE_Msk                         _UINT32_(0x7F7F7F7F)                                 /* (SMC_PULSE) Register Mask  */


/* -------- SMC_CYCLE : (SMC Offset: 0x08) (R/W 32) SMC Cycle Register  -------- */
#define SMC_CYCLE_RESETVALUE                  _UINT32_(0x30003)                                    /*  (SMC_CYCLE) SMC Cycle Register   Reset Value */

#define SMC_CYCLE_NWE_CYCLE_Pos               _UINT32_(0)                                          /* (SMC_CYCLE) Total Write Cycle Length Position */
#define SMC_CYCLE_NWE_CYCLE_Msk               (_UINT32_(0x1FF) << SMC_CYCLE_NWE_CYCLE_Pos)         /* (SMC_CYCLE) Total Write Cycle Length Mask */
#define SMC_CYCLE_NWE_CYCLE(value)            (SMC_CYCLE_NWE_CYCLE_Msk & (_UINT32_(value) << SMC_CYCLE_NWE_CYCLE_Pos)) /* Assignment of value for NWE_CYCLE in the SMC_CYCLE register */
#define SMC_CYCLE_NRD_CYCLE_Pos               _UINT32_(16)                                         /* (SMC_CYCLE) Total Read Cycle Length Position */
#define SMC_CYCLE_NRD_CYCLE_Msk               (_UINT32_(0x1FF) << SMC_CYCLE_NRD_CYCLE_Pos)         /* (SMC_CYCLE) Total Read Cycle Length Mask */
#define SMC_CYCLE_NRD_CYCLE(value)            (SMC_CYCLE_NRD_CYCLE_Msk & (_UINT32_(value) << SMC_CYCLE_NRD_CYCLE_Pos)) /* Assignment of value for NRD_CYCLE in the SMC_CYCLE register */
#define SMC_CYCLE_Msk                         _UINT32_(0x01FF01FF)                                 /* (SMC_CYCLE) Register Mask  */


/* -------- SMC_MODE : (SMC Offset: 0x0C) (R/W 32) SMC Mode Register  -------- */
#define SMC_MODE_RESETVALUE                   _UINT32_(0x10001000)                                 /*  (SMC_MODE) SMC Mode Register   Reset Value */

#define SMC_MODE_READ_MODE_Pos                _UINT32_(0)                                          /* (SMC_MODE) Selection of the Control Signal for Read Operation Position */
#define SMC_MODE_READ_MODE_Msk                (_UINT32_(0x1) << SMC_MODE_READ_MODE_Pos)            /* (SMC_MODE) Selection of the Control Signal for Read Operation Mask */
#define SMC_MODE_READ_MODE(value)             (SMC_MODE_READ_MODE_Msk & (_UINT32_(value) << SMC_MODE_READ_MODE_Pos)) /* Assignment of value for READ_MODE in the SMC_MODE register */
#define   SMC_MODE_READ_MODE_NCS_CTRL_Val     _UINT32_(0x0)                                        /* (SMC_MODE) Read operation controlled by NCS signal - If TDF cycles are programmed, the external bus is marked busy after the rising edge of NCS. - If TDF optimization is enabled (TDF_MODE = 1), TDF wait states are inserted after the setup of NCS.  */
#define   SMC_MODE_READ_MODE_NRD_CTRL_Val     _UINT32_(0x1)                                        /* (SMC_MODE) Read operation controlled by NRD signal - If TDF cycles are programmed, the external bus is marked busy after the rising edge of NRD.  - If TDF optimization is enabled (TDF_MODE = 1), TDF wait states are inserted after the setup of NRD.  */
#define SMC_MODE_READ_MODE_NCS_CTRL           (SMC_MODE_READ_MODE_NCS_CTRL_Val << SMC_MODE_READ_MODE_Pos) /* (SMC_MODE) Read operation controlled by NCS signal - If TDF cycles are programmed, the external bus is marked busy after the rising edge of NCS. - If TDF optimization is enabled (TDF_MODE = 1), TDF wait states are inserted after the setup of NCS. Position */
#define SMC_MODE_READ_MODE_NRD_CTRL           (SMC_MODE_READ_MODE_NRD_CTRL_Val << SMC_MODE_READ_MODE_Pos) /* (SMC_MODE) Read operation controlled by NRD signal - If TDF cycles are programmed, the external bus is marked busy after the rising edge of NRD.  - If TDF optimization is enabled (TDF_MODE = 1), TDF wait states are inserted after the setup of NRD. Position */
#define SMC_MODE_WRITE_MODE_Pos               _UINT32_(1)                                          /* (SMC_MODE) Selection of the Control Signal for Write Operation Position */
#define SMC_MODE_WRITE_MODE_Msk               (_UINT32_(0x1) << SMC_MODE_WRITE_MODE_Pos)           /* (SMC_MODE) Selection of the Control Signal for Write Operation Mask */
#define SMC_MODE_WRITE_MODE(value)            (SMC_MODE_WRITE_MODE_Msk & (_UINT32_(value) << SMC_MODE_WRITE_MODE_Pos)) /* Assignment of value for WRITE_MODE in the SMC_MODE register */
#define   SMC_MODE_WRITE_MODE_NCS_CTRL_Val    _UINT32_(0x0)                                        /* (SMC_MODE) Write operation controlled by NCS signal-If TDF optimization is enabled (TDF_MODE = 1), TDF wait states will be inserted after the setup of NCS.  */
#define   SMC_MODE_WRITE_MODE_NWE_CTRL_Val    _UINT32_(0x1)                                        /* (SMC_MODE) Write operation controlled by NWE signal-If TDF optimization is enabled (TDF_MODE = 1), TDF wait states will be inserted after the setup of NWE.  */
#define SMC_MODE_WRITE_MODE_NCS_CTRL          (SMC_MODE_WRITE_MODE_NCS_CTRL_Val << SMC_MODE_WRITE_MODE_Pos) /* (SMC_MODE) Write operation controlled by NCS signal-If TDF optimization is enabled (TDF_MODE = 1), TDF wait states will be inserted after the setup of NCS. Position */
#define SMC_MODE_WRITE_MODE_NWE_CTRL          (SMC_MODE_WRITE_MODE_NWE_CTRL_Val << SMC_MODE_WRITE_MODE_Pos) /* (SMC_MODE) Write operation controlled by NWE signal-If TDF optimization is enabled (TDF_MODE = 1), TDF wait states will be inserted after the setup of NWE. Position */
#define SMC_MODE_EXNW_MODE_Pos                _UINT32_(4)                                          /* (SMC_MODE) NWAIT Mode Position */
#define SMC_MODE_EXNW_MODE_Msk                (_UINT32_(0x3) << SMC_MODE_EXNW_MODE_Pos)            /* (SMC_MODE) NWAIT Mode Mask */
#define SMC_MODE_EXNW_MODE(value)             (SMC_MODE_EXNW_MODE_Msk & (_UINT32_(value) << SMC_MODE_EXNW_MODE_Pos)) /* Assignment of value for EXNW_MODE in the SMC_MODE register */
#define   SMC_MODE_EXNW_MODE_DISABLED_Val     _UINT32_(0x0)                                        /* (SMC_MODE) Disabled Mode-The NWAIT input signal is ignored on the corresponding Chip Select.  */
#define   SMC_MODE_EXNW_MODE_FROZEN_Val       _UINT32_(0x2)                                        /* (SMC_MODE) Frozen Mode-If asserted, the NWAIT signal freezes the current read or write cycle. After deassertion, the read/write cycle is resumed from the point where it was stopped.  */
#define   SMC_MODE_EXNW_MODE_READY_Val        _UINT32_(0x3)                                        /* (SMC_MODE) Ready Mode-The NWAIT signal indicates the availability of the external device at the end of the pulse of the controlling read or write signal, to complete the access. If high, the access normally completes. If low, the access is extended until NWAIT returns high.  */
#define SMC_MODE_EXNW_MODE_DISABLED           (SMC_MODE_EXNW_MODE_DISABLED_Val << SMC_MODE_EXNW_MODE_Pos) /* (SMC_MODE) Disabled Mode-The NWAIT input signal is ignored on the corresponding Chip Select. Position */
#define SMC_MODE_EXNW_MODE_FROZEN             (SMC_MODE_EXNW_MODE_FROZEN_Val << SMC_MODE_EXNW_MODE_Pos) /* (SMC_MODE) Frozen Mode-If asserted, the NWAIT signal freezes the current read or write cycle. After deassertion, the read/write cycle is resumed from the point where it was stopped. Position */
#define SMC_MODE_EXNW_MODE_READY              (SMC_MODE_EXNW_MODE_READY_Val << SMC_MODE_EXNW_MODE_Pos) /* (SMC_MODE) Ready Mode-The NWAIT signal indicates the availability of the external device at the end of the pulse of the controlling read or write signal, to complete the access. If high, the access normally completes. If low, the access is extended until NWAIT returns high. Position */
#define SMC_MODE_BAT_Pos                      _UINT32_(8)                                          /* (SMC_MODE) Byte Access Type Position */
#define SMC_MODE_BAT_Msk                      (_UINT32_(0x1) << SMC_MODE_BAT_Pos)                  /* (SMC_MODE) Byte Access Type Mask */
#define SMC_MODE_BAT(value)                   (SMC_MODE_BAT_Msk & (_UINT32_(value) << SMC_MODE_BAT_Pos)) /* Assignment of value for BAT in the SMC_MODE register */
#define   SMC_MODE_BAT_BYTE_SELECT_Val        _UINT32_(0x0)                                        /* (SMC_MODE) Byte select access type: - Write operation is controlled using NCS, NWE, NBS0, NBS1 - Read operation is controlled using NCS, NRD, NBS0, NBS1  */
#define   SMC_MODE_BAT_BYTE_WRITE_Val         _UINT32_(0x1)                                        /* (SMC_MODE) Byte write access type: - Write operation is controlled using NCS, NWR0, NWR1 - Read operation is controlled using NCS and NRD  */
#define SMC_MODE_BAT_BYTE_SELECT              (SMC_MODE_BAT_BYTE_SELECT_Val << SMC_MODE_BAT_Pos)   /* (SMC_MODE) Byte select access type: - Write operation is controlled using NCS, NWE, NBS0, NBS1 - Read operation is controlled using NCS, NRD, NBS0, NBS1 Position */
#define SMC_MODE_BAT_BYTE_WRITE               (SMC_MODE_BAT_BYTE_WRITE_Val << SMC_MODE_BAT_Pos)    /* (SMC_MODE) Byte write access type: - Write operation is controlled using NCS, NWR0, NWR1 - Read operation is controlled using NCS and NRD Position */
#define SMC_MODE_DBW_Pos                      _UINT32_(12)                                         /* (SMC_MODE) Data Bus Width Position */
#define SMC_MODE_DBW_Msk                      (_UINT32_(0x3) << SMC_MODE_DBW_Pos)                  /* (SMC_MODE) Data Bus Width Mask */
#define SMC_MODE_DBW(value)                   (SMC_MODE_DBW_Msk & (_UINT32_(value) << SMC_MODE_DBW_Pos)) /* Assignment of value for DBW in the SMC_MODE register */
#define   SMC_MODE_DBW_BIT_8_Val              _UINT32_(0x0)                                        /* (SMC_MODE) 8-bit bus  */
#define   SMC_MODE_DBW_BIT_16_Val             _UINT32_(0x1)                                        /* (SMC_MODE) 16-bit bus  */
#define SMC_MODE_DBW_BIT_8                    (SMC_MODE_DBW_BIT_8_Val << SMC_MODE_DBW_Pos)         /* (SMC_MODE) 8-bit bus Position */
#define SMC_MODE_DBW_BIT_16                   (SMC_MODE_DBW_BIT_16_Val << SMC_MODE_DBW_Pos)        /* (SMC_MODE) 16-bit bus Position */
#define SMC_MODE_TDF_CYCLES_Pos               _UINT32_(16)                                         /* (SMC_MODE) Data Float Time Position */
#define SMC_MODE_TDF_CYCLES_Msk               (_UINT32_(0xF) << SMC_MODE_TDF_CYCLES_Pos)           /* (SMC_MODE) Data Float Time Mask */
#define SMC_MODE_TDF_CYCLES(value)            (SMC_MODE_TDF_CYCLES_Msk & (_UINT32_(value) << SMC_MODE_TDF_CYCLES_Pos)) /* Assignment of value for TDF_CYCLES in the SMC_MODE register */
#define SMC_MODE_TDF_MODE_Pos                 _UINT32_(20)                                         /* (SMC_MODE) TDF Optimization Position */
#define SMC_MODE_TDF_MODE_Msk                 (_UINT32_(0x1) << SMC_MODE_TDF_MODE_Pos)             /* (SMC_MODE) TDF Optimization Mask */
#define SMC_MODE_TDF_MODE(value)              (SMC_MODE_TDF_MODE_Msk & (_UINT32_(value) << SMC_MODE_TDF_MODE_Pos)) /* Assignment of value for TDF_MODE in the SMC_MODE register */
#define   SMC_MODE_TDF_MODE_0_Val             _UINT32_(0x0)                                        /* (SMC_MODE) TDF optimization disabled-The number of TDF wait states is inserted before the next access begins.  */
#define   SMC_MODE_TDF_MODE_1_Val             _UINT32_(0x1)                                        /* (SMC_MODE) TDF optimization enabled-The number of TDF wait states is optimized using the setup period of the next read/write access.  */
#define SMC_MODE_TDF_MODE_0                   (SMC_MODE_TDF_MODE_0_Val << SMC_MODE_TDF_MODE_Pos)   /* (SMC_MODE) TDF optimization disabled-The number of TDF wait states is inserted before the next access begins. Position */
#define SMC_MODE_TDF_MODE_1                   (SMC_MODE_TDF_MODE_1_Val << SMC_MODE_TDF_MODE_Pos)   /* (SMC_MODE) TDF optimization enabled-The number of TDF wait states is optimized using the setup period of the next read/write access. Position */
#define SMC_MODE_PMEN_Pos                     _UINT32_(24)                                         /* (SMC_MODE) Page Mode Enabled Position */
#define SMC_MODE_PMEN_Msk                     (_UINT32_(0x1) << SMC_MODE_PMEN_Pos)                 /* (SMC_MODE) Page Mode Enabled Mask */
#define SMC_MODE_PMEN(value)                  (SMC_MODE_PMEN_Msk & (_UINT32_(value) << SMC_MODE_PMEN_Pos)) /* Assignment of value for PMEN in the SMC_MODE register */
#define   SMC_MODE_PMEN_0_Val                 _UINT32_(0x0)                                        /* (SMC_MODE) Standard read is applied.  */
#define   SMC_MODE_PMEN_1_Val                 _UINT32_(0x1)                                        /* (SMC_MODE) Asynchronous burst read in Page mode is applied on the corresponding chip select.  */
#define SMC_MODE_PMEN_0                       (SMC_MODE_PMEN_0_Val << SMC_MODE_PMEN_Pos)           /* (SMC_MODE) Standard read is applied. Position */
#define SMC_MODE_PMEN_1                       (SMC_MODE_PMEN_1_Val << SMC_MODE_PMEN_Pos)           /* (SMC_MODE) Asynchronous burst read in Page mode is applied on the corresponding chip select. Position */
#define SMC_MODE_PS_Pos                       _UINT32_(28)                                         /* (SMC_MODE) Page Size Position */
#define SMC_MODE_PS_Msk                       (_UINT32_(0x3) << SMC_MODE_PS_Pos)                   /* (SMC_MODE) Page Size Mask */
#define SMC_MODE_PS(value)                    (SMC_MODE_PS_Msk & (_UINT32_(value) << SMC_MODE_PS_Pos)) /* Assignment of value for PS in the SMC_MODE register */
#define   SMC_MODE_PS_BYTE_4_Val              _UINT32_(0x0)                                        /* (SMC_MODE) 4-byte page  */
#define   SMC_MODE_PS_BYTE_8_Val              _UINT32_(0x1)                                        /* (SMC_MODE) 8-byte page  */
#define   SMC_MODE_PS_BYTE_16_Val             _UINT32_(0x2)                                        /* (SMC_MODE) 16-byte page  */
#define   SMC_MODE_PS_BYTE_32_Val             _UINT32_(0x3)                                        /* (SMC_MODE) 32-byte page  */
#define SMC_MODE_PS_BYTE_4                    (SMC_MODE_PS_BYTE_4_Val << SMC_MODE_PS_Pos)          /* (SMC_MODE) 4-byte page Position */
#define SMC_MODE_PS_BYTE_8                    (SMC_MODE_PS_BYTE_8_Val << SMC_MODE_PS_Pos)          /* (SMC_MODE) 8-byte page Position */
#define SMC_MODE_PS_BYTE_16                   (SMC_MODE_PS_BYTE_16_Val << SMC_MODE_PS_Pos)         /* (SMC_MODE) 16-byte page Position */
#define SMC_MODE_PS_BYTE_32                   (SMC_MODE_PS_BYTE_32_Val << SMC_MODE_PS_Pos)         /* (SMC_MODE) 32-byte page Position */
#define SMC_MODE_Msk                          _UINT32_(0x311F3133)                                 /* (SMC_MODE) Register Mask  */


/* -------- SMC_OCMS : (SMC Offset: 0x80) (R/W 32) SMC Off-Chip Memory Scrambling Register -------- */
#define SMC_OCMS_RESETVALUE                   _UINT32_(0x00)                                       /*  (SMC_OCMS) SMC Off-Chip Memory Scrambling Register  Reset Value */

#define SMC_OCMS_SMSE_Pos                     _UINT32_(0)                                          /* (SMC_OCMS) Static Memory Controller Scrambling Enable Position */
#define SMC_OCMS_SMSE_Msk                     (_UINT32_(0x1) << SMC_OCMS_SMSE_Pos)                 /* (SMC_OCMS) Static Memory Controller Scrambling Enable Mask */
#define SMC_OCMS_SMSE(value)                  (SMC_OCMS_SMSE_Msk & (_UINT32_(value) << SMC_OCMS_SMSE_Pos)) /* Assignment of value for SMSE in the SMC_OCMS register */
#define   SMC_OCMS_SMSE_0_Val                 _UINT32_(0x0)                                        /* (SMC_OCMS) Disables scrambling for SMC access.  */
#define   SMC_OCMS_SMSE_1_Val                 _UINT32_(0x1)                                        /* (SMC_OCMS) Enables scrambling for SMC access.  */
#define SMC_OCMS_SMSE_0                       (SMC_OCMS_SMSE_0_Val << SMC_OCMS_SMSE_Pos)           /* (SMC_OCMS) Disables scrambling for SMC access. Position */
#define SMC_OCMS_SMSE_1                       (SMC_OCMS_SMSE_1_Val << SMC_OCMS_SMSE_Pos)           /* (SMC_OCMS) Enables scrambling for SMC access. Position */
#define SMC_OCMS_TAMPCLR_Pos                  _UINT32_(4)                                          /* (SMC_OCMS) Tamper Clear Enable Position */
#define SMC_OCMS_TAMPCLR_Msk                  (_UINT32_(0x1) << SMC_OCMS_TAMPCLR_Pos)              /* (SMC_OCMS) Tamper Clear Enable Mask */
#define SMC_OCMS_TAMPCLR(value)               (SMC_OCMS_TAMPCLR_Msk & (_UINT32_(value) << SMC_OCMS_TAMPCLR_Pos)) /* Assignment of value for TAMPCLR in the SMC_OCMS register */
#define   SMC_OCMS_TAMPCLR_0_Val              _UINT32_(0x0)                                        /* (SMC_OCMS) A tamper detection event has no effect on SMC scrambling keys.  */
#define   SMC_OCMS_TAMPCLR_1_Val              _UINT32_(0x1)                                        /* (SMC_OCMS) A tamper detection event immediately clears SMC scrambling keys.  */
#define SMC_OCMS_TAMPCLR_0                    (SMC_OCMS_TAMPCLR_0_Val << SMC_OCMS_TAMPCLR_Pos)     /* (SMC_OCMS) A tamper detection event has no effect on SMC scrambling keys. Position */
#define SMC_OCMS_TAMPCLR_1                    (SMC_OCMS_TAMPCLR_1_Val << SMC_OCMS_TAMPCLR_Pos)     /* (SMC_OCMS) A tamper detection event immediately clears SMC scrambling keys. Position */
#define SMC_OCMS_CS0SE_Pos                    _UINT32_(8)                                          /* (SMC_OCMS) Chip Select (x = 0 to 2) Scrambling Enable Position */
#define SMC_OCMS_CS0SE_Msk                    (_UINT32_(0x1) << SMC_OCMS_CS0SE_Pos)                /* (SMC_OCMS) Chip Select (x = 0 to 2) Scrambling Enable Mask */
#define SMC_OCMS_CS0SE(value)                 (SMC_OCMS_CS0SE_Msk & (_UINT32_(value) << SMC_OCMS_CS0SE_Pos)) /* Assignment of value for CS0SE in the SMC_OCMS register */
#define   SMC_OCMS_CS0SE_0_Val                _UINT32_(0x0)                                        /* (SMC_OCMS) Disables scrambling for CSx.  */
#define   SMC_OCMS_CS0SE_1_Val                _UINT32_(0x1)                                        /* (SMC_OCMS) Enables scrambling for CSx.  */
#define SMC_OCMS_CS0SE_0                      (SMC_OCMS_CS0SE_0_Val << SMC_OCMS_CS0SE_Pos)         /* (SMC_OCMS) Disables scrambling for CSx. Position */
#define SMC_OCMS_CS0SE_1                      (SMC_OCMS_CS0SE_1_Val << SMC_OCMS_CS0SE_Pos)         /* (SMC_OCMS) Enables scrambling for CSx. Position */
#define SMC_OCMS_CS1SE_Pos                    _UINT32_(9)                                          /* (SMC_OCMS) Chip Select (x = 0 to 2) Scrambling Enable Position */
#define SMC_OCMS_CS1SE_Msk                    (_UINT32_(0x1) << SMC_OCMS_CS1SE_Pos)                /* (SMC_OCMS) Chip Select (x = 0 to 2) Scrambling Enable Mask */
#define SMC_OCMS_CS1SE(value)                 (SMC_OCMS_CS1SE_Msk & (_UINT32_(value) << SMC_OCMS_CS1SE_Pos)) /* Assignment of value for CS1SE in the SMC_OCMS register */
#define   SMC_OCMS_CS1SE_0_Val                _UINT32_(0x0)                                        /* (SMC_OCMS) Disables scrambling for CSx.  */
#define   SMC_OCMS_CS1SE_1_Val                _UINT32_(0x1)                                        /* (SMC_OCMS) Enables scrambling for CSx.  */
#define SMC_OCMS_CS1SE_0                      (SMC_OCMS_CS1SE_0_Val << SMC_OCMS_CS1SE_Pos)         /* (SMC_OCMS) Disables scrambling for CSx. Position */
#define SMC_OCMS_CS1SE_1                      (SMC_OCMS_CS1SE_1_Val << SMC_OCMS_CS1SE_Pos)         /* (SMC_OCMS) Enables scrambling for CSx. Position */
#define SMC_OCMS_CS2SE_Pos                    _UINT32_(10)                                         /* (SMC_OCMS) Chip Select (x = 0 to 2) Scrambling Enable Position */
#define SMC_OCMS_CS2SE_Msk                    (_UINT32_(0x1) << SMC_OCMS_CS2SE_Pos)                /* (SMC_OCMS) Chip Select (x = 0 to 2) Scrambling Enable Mask */
#define SMC_OCMS_CS2SE(value)                 (SMC_OCMS_CS2SE_Msk & (_UINT32_(value) << SMC_OCMS_CS2SE_Pos)) /* Assignment of value for CS2SE in the SMC_OCMS register */
#define   SMC_OCMS_CS2SE_0_Val                _UINT32_(0x0)                                        /* (SMC_OCMS) Disables scrambling for CSx.  */
#define   SMC_OCMS_CS2SE_1_Val                _UINT32_(0x1)                                        /* (SMC_OCMS) Enables scrambling for CSx.  */
#define SMC_OCMS_CS2SE_0                      (SMC_OCMS_CS2SE_0_Val << SMC_OCMS_CS2SE_Pos)         /* (SMC_OCMS) Disables scrambling for CSx. Position */
#define SMC_OCMS_CS2SE_1                      (SMC_OCMS_CS2SE_1_Val << SMC_OCMS_CS2SE_Pos)         /* (SMC_OCMS) Enables scrambling for CSx. Position */
#define SMC_OCMS_Msk                          _UINT32_(0x00000711)                                 /* (SMC_OCMS) Register Mask  */


/* -------- SMC_KEY1 : (SMC Offset: 0x84) ( /W 32) SMC Off-Chip Memory Scrambling KEY1 Register -------- */
#define SMC_KEY1_RESETVALUE                   _UINT32_(0x00)                                       /*  (SMC_KEY1) SMC Off-Chip Memory Scrambling KEY1 Register  Reset Value */

#define SMC_KEY1_KEY1_Pos                     _UINT32_(0)                                          /* (SMC_KEY1) Off-Chip Memory Scrambling (OCMS) Key Part 1 Position */
#define SMC_KEY1_KEY1_Msk                     (_UINT32_(0xFFFFFFFF) << SMC_KEY1_KEY1_Pos)          /* (SMC_KEY1) Off-Chip Memory Scrambling (OCMS) Key Part 1 Mask */
#define SMC_KEY1_KEY1(value)                  (SMC_KEY1_KEY1_Msk & (_UINT32_(value) << SMC_KEY1_KEY1_Pos)) /* Assignment of value for KEY1 in the SMC_KEY1 register */
#define SMC_KEY1_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (SMC_KEY1) Register Mask  */


/* -------- SMC_KEY2 : (SMC Offset: 0x88) ( /W 32) SMC Off-Chip Memory Scrambling KEY2 Register -------- */
#define SMC_KEY2_RESETVALUE                   _UINT32_(0x00)                                       /*  (SMC_KEY2) SMC Off-Chip Memory Scrambling KEY2 Register  Reset Value */

#define SMC_KEY2_KEY2_Pos                     _UINT32_(0)                                          /* (SMC_KEY2) Off-Chip Memory Scrambling (OCMS) Key Part 2 Position */
#define SMC_KEY2_KEY2_Msk                     (_UINT32_(0xFFFFFFFF) << SMC_KEY2_KEY2_Pos)          /* (SMC_KEY2) Off-Chip Memory Scrambling (OCMS) Key Part 2 Mask */
#define SMC_KEY2_KEY2(value)                  (SMC_KEY2_KEY2_Msk & (_UINT32_(value) << SMC_KEY2_KEY2_Pos)) /* Assignment of value for KEY2 in the SMC_KEY2 register */
#define SMC_KEY2_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (SMC_KEY2) Register Mask  */


/* -------- SMC_SRIER : (SMC Offset: 0x90) (R/W 32) SMC Safety Report Interrupt Enable Register -------- */
#define SMC_SRIER_RESETVALUE                  _UINT32_(0x00)                                       /*  (SMC_SRIER) SMC Safety Report Interrupt Enable Register  Reset Value */

#define SMC_SRIER_SRIE_Pos                    _UINT32_(0)                                          /* (SMC_SRIER) Safety Report Interrupt Enable Position */
#define SMC_SRIER_SRIE_Msk                    (_UINT32_(0x1) << SMC_SRIER_SRIE_Pos)                /* (SMC_SRIER) Safety Report Interrupt Enable Mask */
#define SMC_SRIER_SRIE(value)                 (SMC_SRIER_SRIE_Msk & (_UINT32_(value) << SMC_SRIER_SRIE_Pos)) /* Assignment of value for SRIE in the SMC_SRIER register */
#define   SMC_SRIER_SRIE_0_Val                _UINT32_(0x0)                                        /* (SMC_SRIER) Disables the SMC safety report interrupt from External Bus Interface.  */
#define   SMC_SRIER_SRIE_1_Val                _UINT32_(0x1)                                        /* (SMC_SRIER) Enables the SMC safety report interrupt from External Bus Interface.  */
#define SMC_SRIER_SRIE_0                      (SMC_SRIER_SRIE_0_Val << SMC_SRIER_SRIE_Pos)         /* (SMC_SRIER) Disables the SMC safety report interrupt from External Bus Interface. Position */
#define SMC_SRIER_SRIE_1                      (SMC_SRIER_SRIE_1_Val << SMC_SRIER_SRIE_Pos)         /* (SMC_SRIER) Enables the SMC safety report interrupt from External Bus Interface. Position */
#define SMC_SRIER_Msk                         _UINT32_(0x00000001)                                 /* (SMC_SRIER) Register Mask  */


/* -------- SMC_WPMR : (SMC Offset: 0xE4) (R/W 32) SMC Write Protection Mode Register -------- */
#define SMC_WPMR_RESETVALUE                   _UINT32_(0x00)                                       /*  (SMC_WPMR) SMC Write Protection Mode Register  Reset Value */

#define SMC_WPMR_WPEN_Pos                     _UINT32_(0)                                          /* (SMC_WPMR) Write Protection Enable Position */
#define SMC_WPMR_WPEN_Msk                     (_UINT32_(0x1) << SMC_WPMR_WPEN_Pos)                 /* (SMC_WPMR) Write Protection Enable Mask */
#define SMC_WPMR_WPEN(value)                  (SMC_WPMR_WPEN_Msk & (_UINT32_(value) << SMC_WPMR_WPEN_Pos)) /* Assignment of value for WPEN in the SMC_WPMR register */
#define   SMC_WPMR_WPEN_0_Val                 _UINT32_(0x0)                                        /* (SMC_WPMR) Disables write protection if WPKEY value corresponds to 0x534D43 ("SMC" in ASCII).  */
#define   SMC_WPMR_WPEN_1_Val                 _UINT32_(0x1)                                        /* (SMC_WPMR) Enables write protection if WPKEY value corresponds to 0x534D43 ("SMC" in ASCII).  */
#define SMC_WPMR_WPEN_0                       (SMC_WPMR_WPEN_0_Val << SMC_WPMR_WPEN_Pos)           /* (SMC_WPMR) Disables write protection if WPKEY value corresponds to 0x534D43 ("SMC" in ASCII). Position */
#define SMC_WPMR_WPEN_1                       (SMC_WPMR_WPEN_1_Val << SMC_WPMR_WPEN_Pos)           /* (SMC_WPMR) Enables write protection if WPKEY value corresponds to 0x534D43 ("SMC" in ASCII). Position */
#define SMC_WPMR_WPKEY_Pos                    _UINT32_(8)                                          /* (SMC_WPMR) Write Protection Key Position */
#define SMC_WPMR_WPKEY_Msk                    (_UINT32_(0xFFFFFF) << SMC_WPMR_WPKEY_Pos)           /* (SMC_WPMR) Write Protection Key Mask */
#define SMC_WPMR_WPKEY(value)                 (SMC_WPMR_WPKEY_Msk & (_UINT32_(value) << SMC_WPMR_WPKEY_Pos)) /* Assignment of value for WPKEY in the SMC_WPMR register */
#define   SMC_WPMR_WPKEY_PASSWD_Val           _UINT32_(0x534D43)                                   /* (SMC_WPMR) Writing any other value in this field aborts the write operation of bit WPEN. Always reads as 0.  */
#define SMC_WPMR_WPKEY_PASSWD                 (SMC_WPMR_WPKEY_PASSWD_Val << SMC_WPMR_WPKEY_Pos)    /* (SMC_WPMR) Writing any other value in this field aborts the write operation of bit WPEN. Always reads as 0. Position */
#define SMC_WPMR_Msk                          _UINT32_(0xFFFFFF01)                                 /* (SMC_WPMR) Register Mask  */


/* -------- SMC_WPSR : (SMC Offset: 0xE8) ( R/ 32) SMC Write Protection Status Register -------- */
#define SMC_WPSR_RESETVALUE                   _UINT32_(0x00)                                       /*  (SMC_WPSR) SMC Write Protection Status Register  Reset Value */

#define SMC_WPSR_WPVS_Pos                     _UINT32_(0)                                          /* (SMC_WPSR) Write Protection Violation Status (Cleared on read) Position */
#define SMC_WPSR_WPVS_Msk                     (_UINT32_(0x1) << SMC_WPSR_WPVS_Pos)                 /* (SMC_WPSR) Write Protection Violation Status (Cleared on read) Mask */
#define SMC_WPSR_WPVS(value)                  (SMC_WPSR_WPVS_Msk & (_UINT32_(value) << SMC_WPSR_WPVS_Pos)) /* Assignment of value for WPVS in the SMC_WPSR register */
#define   SMC_WPSR_WPVS_0_Val                 _UINT32_(0x0)                                        /* (SMC_WPSR) No write protection violation has occurred since the last read of the SMC_WPSR.  */
#define   SMC_WPSR_WPVS_1_Val                 _UINT32_(0x1)                                        /* (SMC_WPSR) A write protection violation occurred since the last read of the SMC_WPSR. If this violation is an unauthorized attempt to write a protected register, the associated violation is reported into field WPVSRC.  */
#define SMC_WPSR_WPVS_0                       (SMC_WPSR_WPVS_0_Val << SMC_WPSR_WPVS_Pos)           /* (SMC_WPSR) No write protection violation has occurred since the last read of the SMC_WPSR. Position */
#define SMC_WPSR_WPVS_1                       (SMC_WPSR_WPVS_1_Val << SMC_WPSR_WPVS_Pos)           /* (SMC_WPSR) A write protection violation occurred since the last read of the SMC_WPSR. If this violation is an unauthorized attempt to write a protected register, the associated violation is reported into field WPVSRC. Position */
#define SMC_WPSR_SEQE_Pos                     _UINT32_(2)                                          /* (SMC_WPSR) Internal Sequencer Error (Cleared on read) Position */
#define SMC_WPSR_SEQE_Msk                     (_UINT32_(0x1) << SMC_WPSR_SEQE_Pos)                 /* (SMC_WPSR) Internal Sequencer Error (Cleared on read) Mask */
#define SMC_WPSR_SEQE(value)                  (SMC_WPSR_SEQE_Msk & (_UINT32_(value) << SMC_WPSR_SEQE_Pos)) /* Assignment of value for SEQE in the SMC_WPSR register */
#define   SMC_WPSR_SEQE_0_Val                 _UINT32_(0x0)                                        /* (SMC_WPSR) No internal sequencer error has occurred since the last read of SMC_WPSR.  */
#define   SMC_WPSR_SEQE_1_Val                 _UINT32_(0x1)                                        /* (SMC_WPSR) A internal sequencer error has occurred since the last read of SMC_WPSR. This flag can only be set under abnormal operating conditions.  */
#define SMC_WPSR_SEQE_0                       (SMC_WPSR_SEQE_0_Val << SMC_WPSR_SEQE_Pos)           /* (SMC_WPSR) No internal sequencer error has occurred since the last read of SMC_WPSR. Position */
#define SMC_WPSR_SEQE_1                       (SMC_WPSR_SEQE_1_Val << SMC_WPSR_SEQE_Pos)           /* (SMC_WPSR) A internal sequencer error has occurred since the last read of SMC_WPSR. This flag can only be set under abnormal operating conditions. Position */
#define SMC_WPSR_SWE_Pos                      _UINT32_(3)                                          /* (SMC_WPSR) Software Control Error (Cleared on read) Position */
#define SMC_WPSR_SWE_Msk                      (_UINT32_(0x1) << SMC_WPSR_SWE_Pos)                  /* (SMC_WPSR) Software Control Error (Cleared on read) Mask */
#define SMC_WPSR_SWE(value)                   (SMC_WPSR_SWE_Msk & (_UINT32_(value) << SMC_WPSR_SWE_Pos)) /* Assignment of value for SWE in the SMC_WPSR register */
#define   SMC_WPSR_SWE_0_Val                  _UINT32_(0x0)                                        /* (SMC_WPSR) No software error has occurred since the last read of SMC_WPSR.  */
#define   SMC_WPSR_SWE_1_Val                  _UINT32_(0x1)                                        /* (SMC_WPSR) A software error has occurred since the last read of SMC_WPSR. The field SWETYP details the type of software error; the associated incorrect software access is reported in the field WPVSRC (if WPVS=0).  */
#define SMC_WPSR_SWE_0                        (SMC_WPSR_SWE_0_Val << SMC_WPSR_SWE_Pos)             /* (SMC_WPSR) No software error has occurred since the last read of SMC_WPSR. Position */
#define SMC_WPSR_SWE_1                        (SMC_WPSR_SWE_1_Val << SMC_WPSR_SWE_Pos)             /* (SMC_WPSR) A software error has occurred since the last read of SMC_WPSR. The field SWETYP details the type of software error; the associated incorrect software access is reported in the field WPVSRC (if WPVS=0). Position */
#define SMC_WPSR_WPVSRC_Pos                   _UINT32_(8)                                          /* (SMC_WPSR) Write Protection Violation Source Position */
#define SMC_WPSR_WPVSRC_Msk                   (_UINT32_(0xFFFF) << SMC_WPSR_WPVSRC_Pos)            /* (SMC_WPSR) Write Protection Violation Source Mask */
#define SMC_WPSR_WPVSRC(value)                (SMC_WPSR_WPVSRC_Msk & (_UINT32_(value) << SMC_WPSR_WPVSRC_Pos)) /* Assignment of value for WPVSRC in the SMC_WPSR register */
#define SMC_WPSR_SWETYP_Pos                   _UINT32_(24)                                         /* (SMC_WPSR) Software Error Type (Cleared on read) Position */
#define SMC_WPSR_SWETYP_Msk                   (_UINT32_(0x3) << SMC_WPSR_SWETYP_Pos)               /* (SMC_WPSR) Software Error Type (Cleared on read) Mask */
#define SMC_WPSR_SWETYP(value)                (SMC_WPSR_SWETYP_Msk & (_UINT32_(value) << SMC_WPSR_SWETYP_Pos)) /* Assignment of value for SWETYP in the SMC_WPSR register */
#define   SMC_WPSR_SWETYP_READ_WO_Val         _UINT32_(0x0)                                        /* (SMC_WPSR) A write-only register has been read.  */
#define   SMC_WPSR_SWETYP_WRITE_RO_Val        _UINT32_(0x1)                                        /* (SMC_WPSR) A write access has been performed on a read-only register.  */
#define   SMC_WPSR_SWETYP_UNDEF_RW_Val        _UINT32_(0x2)                                        /* (SMC_WPSR) Access to an undefined address.  */
#define SMC_WPSR_SWETYP_READ_WO               (SMC_WPSR_SWETYP_READ_WO_Val << SMC_WPSR_SWETYP_Pos) /* (SMC_WPSR) A write-only register has been read. Position */
#define SMC_WPSR_SWETYP_WRITE_RO              (SMC_WPSR_SWETYP_WRITE_RO_Val << SMC_WPSR_SWETYP_Pos) /* (SMC_WPSR) A write access has been performed on a read-only register. Position */
#define SMC_WPSR_SWETYP_UNDEF_RW              (SMC_WPSR_SWETYP_UNDEF_RW_Val << SMC_WPSR_SWETYP_Pos) /* (SMC_WPSR) Access to an undefined address. Position */
#define SMC_WPSR_Msk                          _UINT32_(0x03FFFF0D)                                 /* (SMC_WPSR) Register Mask  */


/* SMC register offsets definitions */
#define SMC_SETUP_REG_OFST             _UINT32_(0x00)      /* (SMC_SETUP) SMC Setup Register  Offset */
#define SMC_PULSE_REG_OFST             _UINT32_(0x04)      /* (SMC_PULSE) SMC Pulse Register  Offset */
#define SMC_CYCLE_REG_OFST             _UINT32_(0x08)      /* (SMC_CYCLE) SMC Cycle Register  Offset */
#define SMC_MODE_REG_OFST              _UINT32_(0x0C)      /* (SMC_MODE) SMC Mode Register  Offset */
#define SMC_OCMS_REG_OFST              _UINT32_(0x80)      /* (SMC_OCMS) SMC Off-Chip Memory Scrambling Register Offset */
#define SMC_KEY1_REG_OFST              _UINT32_(0x84)      /* (SMC_KEY1) SMC Off-Chip Memory Scrambling KEY1 Register Offset */
#define SMC_KEY2_REG_OFST              _UINT32_(0x88)      /* (SMC_KEY2) SMC Off-Chip Memory Scrambling KEY2 Register Offset */
#define SMC_SRIER_REG_OFST             _UINT32_(0x90)      /* (SMC_SRIER) SMC Safety Report Interrupt Enable Register Offset */
#define SMC_WPMR_REG_OFST              _UINT32_(0xE4)      /* (SMC_WPMR) SMC Write Protection Mode Register Offset */
#define SMC_WPSR_REG_OFST              _UINT32_(0xE8)      /* (SMC_WPSR) SMC Write Protection Status Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/* SMC_CS_NUMBER register API structure */
typedef struct
{
  __IO  uint32_t                       SMC_SETUP;          /* Offset: 0x00 (R/W  32) SMC Setup Register  */
  __IO  uint32_t                       SMC_PULSE;          /* Offset: 0x04 (R/W  32) SMC Pulse Register  */
  __IO  uint32_t                       SMC_CYCLE;          /* Offset: 0x08 (R/W  32) SMC Cycle Register  */
  __IO  uint32_t                       SMC_MODE;           /* Offset: 0x0C (R/W  32) SMC Mode Register  */
} smc_cs_number_registers_t;

#define SMC_CS_NUMBER_NUMBER 3

/* SMC register API structure */
typedef struct
{  /* Static Memory Controller */
        smc_cs_number_registers_t      SMC_CS_NUMBER[SMC_CS_NUMBER_NUMBER]; /* Offset: 0x00  */
  __I   uint8_t                        Reserved1[0x50];
  __IO  uint32_t                       SMC_OCMS;           /* Offset: 0x80 (R/W  32) SMC Off-Chip Memory Scrambling Register */
  __O   uint32_t                       SMC_KEY1;           /* Offset: 0x84 ( /W  32) SMC Off-Chip Memory Scrambling KEY1 Register */
  __O   uint32_t                       SMC_KEY2;           /* Offset: 0x88 ( /W  32) SMC Off-Chip Memory Scrambling KEY2 Register */
  __I   uint8_t                        Reserved2[0x04];
  __IO  uint32_t                       SMC_SRIER;          /* Offset: 0x90 (R/W  32) SMC Safety Report Interrupt Enable Register */
  __I   uint8_t                        Reserved3[0x50];
  __IO  uint32_t                       SMC_WPMR;           /* Offset: 0xE4 (R/W  32) SMC Write Protection Mode Register */
  __I   uint32_t                       SMC_WPSR;           /* Offset: 0xE8 (R/   32) SMC Write Protection Status Register */
} smc_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAM9X7_SMC_COMPONENT_H_ */
