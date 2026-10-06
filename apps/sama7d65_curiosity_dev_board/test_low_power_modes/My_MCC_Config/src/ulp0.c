/*******************************************************************************
 Source File

  Company:
    Microchip Technology Inc.

  File Name:
    ulp0.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "ulp0" ultra low power mode 0 function for a project.  The
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

static void exit_selfrefresh_ddr (void);
static void enter_selfrefresh_ddr (void);
static void configure_wkup_rtc_interrupt(void);
static void configure_wkup_rtc_interrupt(void)
{
  struct tm time;

  /*  Clear Interrupt*/
  SHDWC_REGS->SHDW_SR;
  SHDWC_REGS->SHDW_ISR;

  SYSCWP_REGS->SYSCWP_SYSC_WPMR = SYSCWP_SYSC_WPMR_WPKEY_PASSWD | SYSCWP_SYSC_WPMR_WPEN_0 ;
  SHDWC_REGS->SHDW_MR = SHDW_MR_RTCWKEN_1_Val;
  
  /* Set RTC alarm for fast wakeup */
  PMC_REGS->PMC_WPMR = PMC_WPMR_WPEN_0 | PMC_WPMR_WPKEY_PASSWD;
  PMC_REGS->PMC_FSMR = PMC_FSMR_RTCAL_1; 

  /* configure RTC alarm */
  RTC_TimeGet(&time);
  time.tm_sec += 10;
  time.tm_sec = time.tm_sec % 60;

  RTC_AlarmSet(&time, RTC_ALARM_MASK_SS);
 // RTC_InterruptEnable(RTC_INT_ALARM);
}

void enter_ulp0_mode(void);
uint32_t tmp_stack[256] __attribute__((__section__(".ramdata_section"), aligned(8)));
void  enter_ulp0_mode(void)
{
    asm("dsb" ::: "memory");
    asm("isb" ::: "memory");
    __disable_irq();
    configure_wkup_rtc_interrupt();
   
    /* set up new stack in sram since ddr will be unavailable */
    uint32_t new_sp = ((uint32_t)&tmp_stack[256]) & ~7U;

    /* 3. Execute stack swap, function call, and stack restoration */
    asm volatile (
        "mov r3, sp \n\t"                /* Save DDR SP into r3 */
        "mov sp, %0 \n\t"                /* Switch SP to SRAM stack (8-byte aligned) */
        "push {r3, r12} \n\t"            /* Push old SP + r12 dummy (keeps SP 8-byte aligned) */
        "bl really_enter_ulp0_sram \n\t" /* Call C function with guaranteed 8-byte SP */
        "pop {r3, r12} \n\t"             /* Restore old SP and dummy reg */
        "mov sp, r3 \n\t"                /* Restore original DDR SP */
        : /* No output operands */
        : "r" (new_sp)                   /* Input: SRAM top-of-stack pointer */
        : "r0", "r1", "r2", "r3", "r12", "lr", "memory", "cc" /* Clobber list */
    );

    asm("cpsie if");

}

struct clock_cfg {
        uint32_t scsr;
        uint32_t mckr;
        uint32_t mor;
        uint32_t pcr[157];
        uint32_t pll_sys_backup;
        uint32_t pll_ddr_backup;
    } clock_cfg __attribute__((__section__(".ramdata_section")));
uint32_t pcr_ulp0 __attribute__((section(".ramdata_section")));
uint32_t i __attribute__((section(".ramdata_section")));
__attribute__((__section__(".ramcode_section"))) void really_enter_ulp0_sram(void)
{

    clock_cfg.scsr = PMC_REGS->PMC_SCSR;
    
    clock_cfg.mckr = PMC_REGS->PMC_MCR;
    clock_cfg.mor = PMC_REGS->CKGR_MOR;

    /* 1. Set SDRAM Self-refresh Mode (Mandatory before dropping clocks/resetting PHY) */
    __DSB();

    /* Blocks AXI ports from taking anymore transactions */
    DDRUMCTL_REGS->UDDRC_PCTRL_0 = 0; /* disable port */
    DDRUMCTL_REGS->UDDRC_PCTRL_1 = 0; /* disable port */
    DDRUMCTL_REGS->UDDRC_PCTRL_2 = 0; /* disable port */  
    DDRUMCTL_REGS->UDDRC_PCTRL_3 = 0; /* disable port */
    DDRUMCTL_REGS->UDDRC_PCTRL_4 = 0; /* disable port */

    /* Waits until all AXI ports are idle */
    while (DDRUMCTL_REGS->UDDRC_PSTAT &
         UDDRC_PSTAT_RD_PORT_BUSY_0_Msk &
         UDDRC_PSTAT_WR_PORT_BUSY_0_Msk &
         UDDRC_PSTAT_RD_PORT_BUSY_1_Msk &
         UDDRC_PSTAT_WR_PORT_BUSY_1_Msk &
         UDDRC_PSTAT_RD_PORT_BUSY_2_Msk &
         UDDRC_PSTAT_WR_PORT_BUSY_2_Msk &
         UDDRC_PSTAT_RD_PORT_BUSY_3_Msk &
         UDDRC_PSTAT_WR_PORT_BUSY_3_Msk &
         UDDRC_PSTAT_RD_PORT_BUSY_4_Msk &
         UDDRC_PSTAT_WR_PORT_BUSY_4_Msk);

    /* Causes system to move to Self Refresh state */
    DDRUMCTL_REGS->UDDRC_PWRCTL |= UDDRC_PWRCTL_SELFREF_SW_Msk;

    /* Waits until Self Refresh state is entered */
    while ((DDRUMCTL_REGS->UDDRC_STAT & UDDRC_STAT_SELFREF_TYPE_Msk) !=
         (0x2 << UDDRC_STAT_SELFREF_TYPE_Pos));

    /* Bypass the DLLs */
    DDRPUBL_REGS->DDR3PHY_PIR |= DDR3PHY_PIR_DLLBYP_Msk;

    /* Enable power-down of the data IO's receiver */
    DDRPUBL_REGS->DDR3PHY_DXCCR  |= DDR3PHY_DXCCR_DXPDR_Msk;
    /* Enable power-down of the ADDR/CMD IO's driver */
    DDRPUBL_REGS->DDR3PHY_ACIOCR |= (DDR3PHY_ACIOCR_ACPDD_Msk | DDR3PHY_ACIOCR_CKPDD(1) | DDR3PHY_ACIOCR_CSPDD(1));
    /* Enable power-down of the ODT IO's driver */
    DDRPUBL_REGS->DDR3PHY_DSGCR  |= DDR3PHY_DSGCR_ODTPDD(1);

    /* Step 2 is skipped: Turn on DDR PLL (if DDR was not used). DDR is used, so it is already on. */

    /* 3 & 4. RESET DDR_CONTROLLER using RSTC_GRSTR */
    RSTC_REGS->RSTC_GRSTR |= RSTC_GRSTR_DDR_PHY_RST_1;
    while( ( RSTC_REGS->RSTC_SR & RSTC_SR_SRCMP_Msk ) != RSTC_SR_SRCMP_0 ); 
    
    /* 5. set DDR Program Lane and Control Delay line to bypass */
	  DDRPUBL_REGS->DDR3PHY_ACDLLCR = (DDRPUBL_REGS->DDR3PHY_ACDLLCR & ~DDR3PHY_ACDLLCR_DLLSRST_Msk) | DDR3PHY_ACDLLCR_DLLDIS_Msk;
    DDRPUBL_REGS->DDR3PHY_DX0DLLCR |= DDR3PHY_ACDLLCR_DLLDIS_Msk;
    DDRPUBL_REGS->DDR3PHY_DX1DLLCR |= DDR3PHY_ACDLLCR_DLLDIS_Msk;
	
    /* 6. Turn off DDRPLL in PMC. */
   
    // Step A: Read PMC_PLL_UPDT to capture existing STUPTIM (Bits 21:16)
    uint32_t updt = PMC_REGS->PMC_PLL_UPDT;
    
    // Clear only the ID field (Bits 3:0) and the UPDATE bit (Bit 8). 
    // This perfectly preserves STUPTIM and any other reserved bits.
    updt &= ~(0x0F | (1 << 8)); 
    
    // Step B: Select the target PLL ID without triggering an update
    PMC_REGS->PMC_PLL_UPDT = updt | PMC_PLL_UPDT_ID(0x2); // PLL_ID_DDRPLL is 2
    
    // Step C: Read the currently selected PLL's CTRL0, append Enable bits, and write back.
    // This preserves existing multipliers and dividers in CTRL0.
    clock_cfg.pll_ddr_backup = PMC_REGS->PMC_PLL_CTRL0;
    PMC_REGS->PMC_PLL_CTRL0 &= ~(PMC_PLL_CTRL0_ENIOPLLCK(1) | PMC_PLL_CTRL0_ENLOCK(1));
    
    // Step D: Trigger the actual configuration update for this PLL ID
    PMC_REGS->PMC_PLL_UPDT = updt | PMC_PLL_UPDT_ID(0x2) | PMC_PLL_UPDT_UPDATE_Msk;
    
    PMC_REGS->PMC_PLL_CTRL0 &= ~(PMC_PLL_CTRL0_ENPLL(1));
    PMC_REGS->PMC_PLL_UPDT = updt | PMC_PLL_UPDT_ID(0x2) | PMC_PLL_UPDT_UPDATE_Msk;

    /* 7. Enable RTC interrupt */
    RTC_REGS->RTC_IER = 0x2;

    /* 8. Disable all Peripheral clocks. Before disabling ensure to backup the PCR. No.of peripherals 157 */
    for (i = 0; i < 157; i++)
    {
        /* Step 1: Set PID with CMD = 0 (Read Access) */
        PMC_REGS->PMC_PCR = PMC_PCR_PID(i);
        
        /* Step 2: Read back and backup current configuration */
        pcr_ulp0 = PMC_REGS->PMC_PCR;
        clock_cfg.pcr[i] = pcr_ulp0;

        /* Step 3: Disable peripheral clock ONLY if it is currently enabled */
        if (pcr_ulp0 & PMC_PCR_EN_Msk)
        {
            pcr_ulp0 &= ~PMC_PCR_EN_Msk;       /* Clear enable bit */
            pcr_ulp0 |= PMC_PCR_CMD_Msk;       /* Set CMD = 1 (Write mode) */
            
            PMC_REGS->PMC_PCR = pcr_ulp0;      /* Apply update */
        }
    }

    /* 9. set IOs to user required state and suspend USB controller */
   // UDPHSA_REGS->UDPHS_CTRL &= ~UDPHS_CTRL_EN_UDPHS_Msk;
   // UDPHSB_REGS->UDPHS_CTRL &= ~UDPHS_CTRL_EN_UDPHS_Msk;

    /* 10. switch to slow clock */    
    uint32_t mckr = 0;
    /* Switch Master Clock source to Slow Clock */
    mckr = PMC_REGS->PMC_MCR;
    mckr &= ~PMC_MCR_CSS_Msk;
    mckr |= PMC_MCR_CSS_MD_SLOW_CLK;
    PMC_REGS->PMC_MCR = mckr;

    /* Wait for MCK ready */
    while ((PMC_REGS->PMC_SR & PMC_SR_MCKRDY_Msk) == 0);

    
    /* 11. disable PLL and main clock */    
    uint32_t updt_mclk = PMC_REGS->PMC_PLL_UPDT;
    updt_mclk &= ~(0x0F | (1 << 8)); 
    PMC_REGS->PMC_PLL_UPDT = updt_mclk | PMC_PLL_UPDT_ID(0x1); // PLL_ID_SYSPLL is 1
    

    clock_cfg.pll_sys_backup = PMC_REGS->PMC_PLL_CTRL0;
    PMC_REGS->PMC_PLL_CTRL0 &= ~(PMC_PLL_CTRL0_ENIOPLLCK(1) | PMC_PLL_CTRL0_ENLOCK(1));
  
    
    // Step D: Trigger the actual configuration update for this PLL ID
    PMC_REGS->PMC_PLL_UPDT = updt_mclk | PMC_PLL_UPDT_ID(0x1) | PMC_PLL_UPDT_UPDATE_Msk;
    
    PMC_REGS->PMC_PLL_CTRL0 &= ~(PMC_PLL_CTRL0_ENPLL(1));
    PMC_REGS->PMC_PLL_UPDT = updt_mclk | PMC_PLL_UPDT_ID(0x1) | PMC_PLL_UPDT_UPDATE_Msk;
    
    /* Shut down Main Crystal and RC Oscillators securely */
    uint32_t tmp_mor = PMC_REGS->CKGR_MOR;
    tmp_mor &= ~(CKGR_MOR_MOSCXTEN_Msk | CKGR_MOR_MOSCRCEN_Msk);
    PMC_REGS->CKGR_MOR = tmp_mor | CKGR_MOR_KEY_PASSWD | CKGR_MOR_KEY_Msk;

    /* 12. enter ULP0 */
    //asm("dsb" ::: "memory");
    //asm("wfi" ::: "memory");

    /* =================== WAKE UP =================== */

    /* Exit ULP0 and enable main clock */
    PMC_REGS->CKGR_MOR = clock_cfg.mor | CKGR_MOR_KEY_PASSWD | CKGR_MOR_KEY_Msk;
    if (clock_cfg.mor & CKGR_MOR_MOSCSEL_Msk) {
        while (!(PMC_REGS->PMC_SR & PMC_SR_MOSCXTS_Msk));
    }

    /* FIX: You MUST turn the  DDR PLL and SYSPLL back on before waiting for it to lock! */
    PMC_REGS->PMC_PLL_IER = (1 << 0x1)                          \
                          | (1 << 0x2); /* Enable SYSPLL and DDRPLL lock interrupts */
    updt = PMC_REGS->PMC_PLL_UPDT;
    updt &= ~(0x0F | (1 << 8)); 
    PMC_REGS->PMC_PLL_UPDT = updt | PMC_PLL_UPDT_ID(0x2); // PLL_ID_DDRPLL is 2
    PMC_REGS->PMC_PLL_CTRL0 = clock_cfg.pll_ddr_backup | PMC_PLL_CTRL0_ENPLL(1) | PMC_PLL_CTRL0_ENLOCK(1) | PMC_PLL_CTRL0_ENIOPLLCK(1);
    PMC_REGS->PMC_PLL_UPDT = updt | PMC_PLL_UPDT_ID(0x2) | PMC_PLL_UPDT_UPDATE_Msk;
    while (!(PMC_REGS->PMC_PLL_ISR0 & (1 << 0x2))); 

    updt = PMC_REGS->PMC_PLL_UPDT;
    updt &= ~(0x0F | (1 << 8)); 
    PMC_REGS->PMC_PLL_UPDT = updt | PMC_PLL_UPDT_ID(0x1); // PLL_ID_SYSPLL is 1
    PMC_REGS->PMC_PLL_CTRL0 = clock_cfg.pll_sys_backup | PMC_PLL_CTRL0_ENPLL(1) | PMC_PLL_CTRL0_ENLOCK(1) | PMC_PLL_CTRL0_ENIOPLLCK(1);
    PMC_REGS->PMC_PLL_UPDT = updt | PMC_PLL_UPDT_ID(0x1) | PMC_PLL_UPDT_UPDATE_Msk;
    while (!(PMC_REGS->PMC_PLL_ISR0 & (1 << 0x1))); 

    /* switch master clock to pll */
    PMC_REGS->PMC_MCR = clock_cfg.mckr;
    while (!(PMC_REGS->PMC_SR & PMC_SR_MCKRDY_Msk));

    PMC_REGS->PMC_SCER = clock_cfg.scsr;

    /* Restore Peripheral Clock*/
    for(i=0; i<157; i++)
    {
      clock_cfg.pcr[i] |= PMC_PCR_CMD_1;        
      PMC_REGS->PMC_PCR =  clock_cfg.pcr[i];
    }
    exit_selfrefresh_ddr();
}


__attribute__((__section__(".ramcode_section")))  static void exit_selfrefresh_ddr (void)
{

  /* Disable power-down of the data IO's receiver */
  DDRPUBL_REGS->DDR3PHY_DXCCR  &= ~DDR3PHY_DXCCR_DXPDR_Msk;  
  /* Disable power-down of the ADDR/CMD IO's driver */
  DDRPUBL_REGS->DDR3PHY_ACIOCR &= ~(DDR3PHY_ACIOCR_ACPDD_Msk | DDR3PHY_ACIOCR_CKPDD(1) | DDR3PHY_ACIOCR_CSPDD(1));
  /* Disable power-down of the ODT IO's driver */
  DDRPUBL_REGS->DDR3PHY_DSGCR  &= ~DDR3PHY_DSGCR_ODTPDD(1);

  /* Release bypass of DLLs (SAMA7D6 Specific) */
  DDRPUBL_REGS->DDR3PHY_ACDLLCR &= ~DDR3PHY_ACDLLCR_DLLDIS_Msk;
  DDRPUBL_REGS->DDR3PHY_DX0DLLCR &= ~DDR3PHY_ACDLLCR_DLLDIS_Msk;
  DDRPUBL_REGS->DDR3PHY_DX1DLLCR &= ~DDR3PHY_ACDLLCR_DLLDIS_Msk;

  /* Wait for DLL lock then reset ITMs */
  DDRUMCTL_REGS->UDDRC_SWCTL = 0; 
  DDRUMCTL_REGS->UDDRC_DFIMISC &= ~UDDRC_DFIMISC_DFI_INIT_COMPLETE_EN_Msk;
  DDRUMCTL_REGS->UDDRC_SWCTL = UDDRC_SWCTL_SW_DONE_Msk;
  while (DDRUMCTL_REGS->UDDRC_SWSTAT != UDDRC_SWSTAT_SW_DONE_ACK_Msk);
  
  /*DLL SRST is mandatory in top of DLL lock and ITM SRST */
  DDRPUBL_REGS->DDR3PHY_PIR = DDR3PHY_PIR_INIT_Msk | DDR3PHY_PIR_DLLSRST_Msk | DDR3PHY_PIR_DLLLOCK_Msk | DDR3PHY_PIR_ITMSRST_Msk;
  while ((DDRPUBL_REGS->DDR3PHY_PGSR & DDR3PHY_PGSR_IDONE_Msk) != DDR3PHY_PGSR_IDONE_Msk);

  DDRUMCTL_REGS->UDDRC_SWCTL = 0;  // Enable quasi-dynamic register programming outside reset.
  DDRUMCTL_REGS->UDDRC_DFIMISC |=  UDDRC_DFIMISC_DFI_INIT_COMPLETE_EN_Msk;
  DDRUMCTL_REGS->UDDRC_SWCTL = UDDRC_SWCTL_SW_DONE_Msk;
  while (DDRUMCTL_REGS->UDDRC_SWSTAT != UDDRC_SWSTAT_SW_DONE_ACK_Msk);

  /*Trigger self-refresh exit*/
  DDRUMCTL_REGS->UDDRC_PWRCTL &= ~UDDRC_PWRCTL_SELFREF_SW_Msk;

  /* Waits until Self Refresh state is exited */
  while ((DDRUMCTL_REGS->UDDRC_STAT & UDDRC_STAT_OPERATING_MODE_Msk) != (0x1 << UDDRC_STAT_OPERATING_MODE_Pos));

  /* AXI ports no longer block from taking transactions */
  DDRUMCTL_REGS->UDDRC_PCTRL_0 = 1; // enable port
  DDRUMCTL_REGS->UDDRC_PCTRL_1 = 1; // enable port
  DDRUMCTL_REGS->UDDRC_PCTRL_2 = 1; // enable port
  DDRUMCTL_REGS->UDDRC_PCTRL_3 = 1; // enable port
  DDRUMCTL_REGS->UDDRC_PCTRL_4 = 1; // enable port

  /* DSB */
  __DSB();

}

