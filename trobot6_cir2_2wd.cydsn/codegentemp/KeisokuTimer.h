/*******************************************************************************
* File Name: KeisokuTimer.h
* Version 2.70
*
*  Description:
*     Contains the function prototypes and constants available to the timer
*     user module.
*
*   Note:
*     None
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_Timer_v2_60_KeisokuTimer_H)
#define CY_Timer_v2_60_KeisokuTimer_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 KeisokuTimer_initVar;

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component Timer_v2_70 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */


/**************************************
*           Parameter Defaults
**************************************/

#define KeisokuTimer_Resolution                 16u
#define KeisokuTimer_UsingFixedFunction         1u
#define KeisokuTimer_UsingHWCaptureCounter      0u
#define KeisokuTimer_SoftwareCaptureMode        0u
#define KeisokuTimer_SoftwareTriggerMode        0u
#define KeisokuTimer_UsingHWEnable              1u
#define KeisokuTimer_EnableTriggerMode          0u
#define KeisokuTimer_InterruptOnCaptureCount    0u
#define KeisokuTimer_RunModeUsed                0u
#define KeisokuTimer_ControlRegRemoved          0u

#if defined(KeisokuTimer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG)
    #define KeisokuTimer_UDB_CONTROL_REG_REMOVED            (0u)
#elif  (KeisokuTimer_UsingFixedFunction)
    #define KeisokuTimer_UDB_CONTROL_REG_REMOVED            (0u)
#else 
    #define KeisokuTimer_UDB_CONTROL_REG_REMOVED            (1u)
#endif /* End KeisokuTimer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG */


/***************************************
*       Type defines
***************************************/


/**************************************************************************
 * Sleep Wakeup Backup structure for Timer Component
 *************************************************************************/
typedef struct
{
    uint8 TimerEnableState;
    #if(!KeisokuTimer_UsingFixedFunction)

        uint16 TimerUdb;
        uint8 InterruptMaskValue;
        #if (KeisokuTimer_UsingHWCaptureCounter)
            uint8 TimerCaptureCounter;
        #endif /* variable declarations for backing up non retention registers in CY_UDB_V1 */

        #if (!KeisokuTimer_UDB_CONTROL_REG_REMOVED)
            uint8 TimerControlRegister;
        #endif /* variable declaration for backing up enable state of the Timer */
    #endif /* define backup variables only for UDB implementation. Fixed function registers are all retention */

}KeisokuTimer_backupStruct;


/***************************************
*       Function Prototypes
***************************************/

void    KeisokuTimer_Start(void) ;
void    KeisokuTimer_Stop(void) ;

void    KeisokuTimer_SetInterruptMode(uint8 interruptMode) ;
uint8   KeisokuTimer_ReadStatusRegister(void) ;
/* Deprecated function. Do not use this in future. Retained for backward compatibility */
#define KeisokuTimer_GetInterruptSource() KeisokuTimer_ReadStatusRegister()

#if(!KeisokuTimer_UDB_CONTROL_REG_REMOVED)
    uint8   KeisokuTimer_ReadControlRegister(void) ;
    void    KeisokuTimer_WriteControlRegister(uint8 control) ;
#endif /* (!KeisokuTimer_UDB_CONTROL_REG_REMOVED) */

uint16  KeisokuTimer_ReadPeriod(void) ;
void    KeisokuTimer_WritePeriod(uint16 period) ;
uint16  KeisokuTimer_ReadCounter(void) ;
void    KeisokuTimer_WriteCounter(uint16 counter) ;
uint16  KeisokuTimer_ReadCapture(void) ;
void    KeisokuTimer_SoftwareCapture(void) ;

#if(!KeisokuTimer_UsingFixedFunction) /* UDB Prototypes */
    #if (KeisokuTimer_SoftwareCaptureMode)
        void    KeisokuTimer_SetCaptureMode(uint8 captureMode) ;
    #endif /* (!KeisokuTimer_UsingFixedFunction) */

    #if (KeisokuTimer_SoftwareTriggerMode)
        void    KeisokuTimer_SetTriggerMode(uint8 triggerMode) ;
    #endif /* (KeisokuTimer_SoftwareTriggerMode) */

    #if (KeisokuTimer_EnableTriggerMode)
        void    KeisokuTimer_EnableTrigger(void) ;
        void    KeisokuTimer_DisableTrigger(void) ;
    #endif /* (KeisokuTimer_EnableTriggerMode) */


    #if(KeisokuTimer_InterruptOnCaptureCount)
        void    KeisokuTimer_SetInterruptCount(uint8 interruptCount) ;
    #endif /* (KeisokuTimer_InterruptOnCaptureCount) */

    #if (KeisokuTimer_UsingHWCaptureCounter)
        void    KeisokuTimer_SetCaptureCount(uint8 captureCount) ;
        uint8   KeisokuTimer_ReadCaptureCount(void) ;
    #endif /* (KeisokuTimer_UsingHWCaptureCounter) */

    void KeisokuTimer_ClearFIFO(void) ;
#endif /* UDB Prototypes */

/* Sleep Retention APIs */
void KeisokuTimer_Init(void)          ;
void KeisokuTimer_Enable(void)        ;
void KeisokuTimer_SaveConfig(void)    ;
void KeisokuTimer_RestoreConfig(void) ;
void KeisokuTimer_Sleep(void)         ;
void KeisokuTimer_Wakeup(void)        ;


/***************************************
*   Enumerated Types and Parameters
***************************************/

/* Enumerated Type B_Timer__CaptureModes, Used in Capture Mode */
#define KeisokuTimer__B_TIMER__CM_NONE 0
#define KeisokuTimer__B_TIMER__CM_RISINGEDGE 1
#define KeisokuTimer__B_TIMER__CM_FALLINGEDGE 2
#define KeisokuTimer__B_TIMER__CM_EITHEREDGE 3
#define KeisokuTimer__B_TIMER__CM_SOFTWARE 4



/* Enumerated Type B_Timer__TriggerModes, Used in Trigger Mode */
#define KeisokuTimer__B_TIMER__TM_NONE 0x00u
#define KeisokuTimer__B_TIMER__TM_RISINGEDGE 0x04u
#define KeisokuTimer__B_TIMER__TM_FALLINGEDGE 0x08u
#define KeisokuTimer__B_TIMER__TM_EITHEREDGE 0x0Cu
#define KeisokuTimer__B_TIMER__TM_SOFTWARE 0x10u


/***************************************
*    Initialial Parameter Constants
***************************************/

#define KeisokuTimer_INIT_PERIOD             1199u
#define KeisokuTimer_INIT_CAPTURE_MODE       ((uint8)((uint8)0u << KeisokuTimer_CTRL_CAP_MODE_SHIFT))
#define KeisokuTimer_INIT_TRIGGER_MODE       ((uint8)((uint8)0u << KeisokuTimer_CTRL_TRIG_MODE_SHIFT))
#if (KeisokuTimer_UsingFixedFunction)
    #define KeisokuTimer_INIT_INTERRUPT_MODE (((uint8)((uint8)1u << KeisokuTimer_STATUS_TC_INT_MASK_SHIFT)) | \
                                                  ((uint8)((uint8)0 << KeisokuTimer_STATUS_CAPTURE_INT_MASK_SHIFT)))
#else
    #define KeisokuTimer_INIT_INTERRUPT_MODE (((uint8)((uint8)1u << KeisokuTimer_STATUS_TC_INT_MASK_SHIFT)) | \
                                                 ((uint8)((uint8)0 << KeisokuTimer_STATUS_CAPTURE_INT_MASK_SHIFT)) | \
                                                 ((uint8)((uint8)0 << KeisokuTimer_STATUS_FIFOFULL_INT_MASK_SHIFT)))
#endif /* (KeisokuTimer_UsingFixedFunction) */
#define KeisokuTimer_INIT_CAPTURE_COUNT      (2u)
#define KeisokuTimer_INIT_INT_CAPTURE_COUNT  ((uint8)((uint8)(1u - 1u) << KeisokuTimer_CTRL_INTCNT_SHIFT))


/***************************************
*           Registers
***************************************/

#if (KeisokuTimer_UsingFixedFunction) /* Implementation Specific Registers and Register Constants */


    /***************************************
    *    Fixed Function Registers
    ***************************************/

    #define KeisokuTimer_STATUS         (*(reg8 *) KeisokuTimer_TimerHW__SR0 )
    /* In Fixed Function Block Status and Mask are the same register */
    #define KeisokuTimer_STATUS_MASK    (*(reg8 *) KeisokuTimer_TimerHW__SR0 )
    #define KeisokuTimer_CONTROL        (*(reg8 *) KeisokuTimer_TimerHW__CFG0)
    #define KeisokuTimer_CONTROL2       (*(reg8 *) KeisokuTimer_TimerHW__CFG1)
    #define KeisokuTimer_CONTROL2_PTR   ( (reg8 *) KeisokuTimer_TimerHW__CFG1)
    #define KeisokuTimer_RT1            (*(reg8 *) KeisokuTimer_TimerHW__RT1)
    #define KeisokuTimer_RT1_PTR        ( (reg8 *) KeisokuTimer_TimerHW__RT1)

    #if (CY_PSOC3 || CY_PSOC5LP)
        #define KeisokuTimer_CONTROL3       (*(reg8 *) KeisokuTimer_TimerHW__CFG2)
        #define KeisokuTimer_CONTROL3_PTR   ( (reg8 *) KeisokuTimer_TimerHW__CFG2)
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    #define KeisokuTimer_GLOBAL_ENABLE  (*(reg8 *) KeisokuTimer_TimerHW__PM_ACT_CFG)
    #define KeisokuTimer_GLOBAL_STBY_ENABLE  (*(reg8 *) KeisokuTimer_TimerHW__PM_STBY_CFG)

    #define KeisokuTimer_CAPTURE_LSB         (* (reg16 *) KeisokuTimer_TimerHW__CAP0 )
    #define KeisokuTimer_CAPTURE_LSB_PTR       ((reg16 *) KeisokuTimer_TimerHW__CAP0 )
    #define KeisokuTimer_PERIOD_LSB          (* (reg16 *) KeisokuTimer_TimerHW__PER0 )
    #define KeisokuTimer_PERIOD_LSB_PTR        ((reg16 *) KeisokuTimer_TimerHW__PER0 )
    #define KeisokuTimer_COUNTER_LSB         (* (reg16 *) KeisokuTimer_TimerHW__CNT_CMP0 )
    #define KeisokuTimer_COUNTER_LSB_PTR       ((reg16 *) KeisokuTimer_TimerHW__CNT_CMP0 )


    /***************************************
    *    Register Constants
    ***************************************/

    /* Fixed Function Block Chosen */
    #define KeisokuTimer_BLOCK_EN_MASK                     KeisokuTimer_TimerHW__PM_ACT_MSK
    #define KeisokuTimer_BLOCK_STBY_EN_MASK                KeisokuTimer_TimerHW__PM_STBY_MSK

    /* Control Register Bit Locations */
    /* Interrupt Count - Not valid for Fixed Function Block */
    #define KeisokuTimer_CTRL_INTCNT_SHIFT                  0x00u
    /* Trigger Polarity - Not valid for Fixed Function Block */
    #define KeisokuTimer_CTRL_TRIG_MODE_SHIFT               0x00u
    /* Trigger Enable - Not valid for Fixed Function Block */
    #define KeisokuTimer_CTRL_TRIG_EN_SHIFT                 0x00u
    /* Capture Polarity - Not valid for Fixed Function Block */
    #define KeisokuTimer_CTRL_CAP_MODE_SHIFT                0x00u
    /* Timer Enable - As defined in Register Map, part of TMRX_CFG0 register */
    #define KeisokuTimer_CTRL_ENABLE_SHIFT                  0x00u

    /* Control Register Bit Masks */
    #define KeisokuTimer_CTRL_ENABLE                        ((uint8)((uint8)0x01u << KeisokuTimer_CTRL_ENABLE_SHIFT))

    /* Control2 Register Bit Masks */
    /* As defined in Register Map, Part of the TMRX_CFG1 register */
    #define KeisokuTimer_CTRL2_IRQ_SEL_SHIFT                 0x00u
    #define KeisokuTimer_CTRL2_IRQ_SEL                      ((uint8)((uint8)0x01u << KeisokuTimer_CTRL2_IRQ_SEL_SHIFT))

    #if (CY_PSOC5A)
        /* Use CFG1 Mode bits to set run mode */
        /* As defined by Verilog Implementation */
        #define KeisokuTimer_CTRL_MODE_SHIFT                 0x01u
        #define KeisokuTimer_CTRL_MODE_MASK                 ((uint8)((uint8)0x07u << KeisokuTimer_CTRL_MODE_SHIFT))
    #endif /* (CY_PSOC5A) */
    #if (CY_PSOC3 || CY_PSOC5LP)
        /* Control3 Register Bit Locations */
        #define KeisokuTimer_CTRL_RCOD_SHIFT        0x02u
        #define KeisokuTimer_CTRL_ENBL_SHIFT        0x00u
        #define KeisokuTimer_CTRL_MODE_SHIFT        0x00u

        /* Control3 Register Bit Masks */
        #define KeisokuTimer_CTRL_RCOD_MASK  ((uint8)((uint8)0x03u << KeisokuTimer_CTRL_RCOD_SHIFT)) /* ROD and COD bit masks */
        #define KeisokuTimer_CTRL_ENBL_MASK  ((uint8)((uint8)0x80u << KeisokuTimer_CTRL_ENBL_SHIFT)) /* HW_EN bit mask */
        #define KeisokuTimer_CTRL_MODE_MASK  ((uint8)((uint8)0x03u << KeisokuTimer_CTRL_MODE_SHIFT)) /* Run mode bit mask */

        #define KeisokuTimer_CTRL_RCOD       ((uint8)((uint8)0x03u << KeisokuTimer_CTRL_RCOD_SHIFT))
        #define KeisokuTimer_CTRL_ENBL       ((uint8)((uint8)0x80u << KeisokuTimer_CTRL_ENBL_SHIFT))
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */

    /*RT1 Synch Constants: Applicable for PSoC3 and PSoC5LP */
    #define KeisokuTimer_RT1_SHIFT                       0x04u
    /* Sync TC and CMP bit masks */
    #define KeisokuTimer_RT1_MASK                        ((uint8)((uint8)0x03u << KeisokuTimer_RT1_SHIFT))
    #define KeisokuTimer_SYNC                            ((uint8)((uint8)0x03u << KeisokuTimer_RT1_SHIFT))
    #define KeisokuTimer_SYNCDSI_SHIFT                   0x00u
    /* Sync all DSI inputs with Mask  */
    #define KeisokuTimer_SYNCDSI_MASK                    ((uint8)((uint8)0x0Fu << KeisokuTimer_SYNCDSI_SHIFT))
    /* Sync all DSI inputs */
    #define KeisokuTimer_SYNCDSI_EN                      ((uint8)((uint8)0x0Fu << KeisokuTimer_SYNCDSI_SHIFT))

    #define KeisokuTimer_CTRL_MODE_PULSEWIDTH            ((uint8)((uint8)0x01u << KeisokuTimer_CTRL_MODE_SHIFT))
    #define KeisokuTimer_CTRL_MODE_PERIOD                ((uint8)((uint8)0x02u << KeisokuTimer_CTRL_MODE_SHIFT))
    #define KeisokuTimer_CTRL_MODE_CONTINUOUS            ((uint8)((uint8)0x00u << KeisokuTimer_CTRL_MODE_SHIFT))

    /* Status Register Bit Locations */
    /* As defined in Register Map, part of TMRX_SR0 register */
    #define KeisokuTimer_STATUS_TC_SHIFT                 0x07u
    /* As defined in Register Map, part of TMRX_SR0 register, Shared with Compare Status */
    #define KeisokuTimer_STATUS_CAPTURE_SHIFT            0x06u
    /* As defined in Register Map, part of TMRX_SR0 register */
    #define KeisokuTimer_STATUS_TC_INT_MASK_SHIFT        (KeisokuTimer_STATUS_TC_SHIFT - 0x04u)
    /* As defined in Register Map, part of TMRX_SR0 register, Shared with Compare Status */
    #define KeisokuTimer_STATUS_CAPTURE_INT_MASK_SHIFT   (KeisokuTimer_STATUS_CAPTURE_SHIFT - 0x04u)

    /* Status Register Bit Masks */
    #define KeisokuTimer_STATUS_TC                       ((uint8)((uint8)0x01u << KeisokuTimer_STATUS_TC_SHIFT))
    #define KeisokuTimer_STATUS_CAPTURE                  ((uint8)((uint8)0x01u << KeisokuTimer_STATUS_CAPTURE_SHIFT))
    /* Interrupt Enable Bit-Mask for interrupt on TC */
    #define KeisokuTimer_STATUS_TC_INT_MASK              ((uint8)((uint8)0x01u << KeisokuTimer_STATUS_TC_INT_MASK_SHIFT))
    /* Interrupt Enable Bit-Mask for interrupt on Capture */
    #define KeisokuTimer_STATUS_CAPTURE_INT_MASK         ((uint8)((uint8)0x01u << KeisokuTimer_STATUS_CAPTURE_INT_MASK_SHIFT))

#else   /* UDB Registers and Register Constants */


    /***************************************
    *           UDB Registers
    ***************************************/

    #define KeisokuTimer_STATUS              (* (reg8 *) KeisokuTimer_TimerUDB_rstSts_stsreg__STATUS_REG )
    #define KeisokuTimer_STATUS_MASK         (* (reg8 *) KeisokuTimer_TimerUDB_rstSts_stsreg__MASK_REG)
    #define KeisokuTimer_STATUS_AUX_CTRL     (* (reg8 *) KeisokuTimer_TimerUDB_rstSts_stsreg__STATUS_AUX_CTL_REG)
    #define KeisokuTimer_CONTROL             (* (reg8 *) KeisokuTimer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG )
    
    #if(KeisokuTimer_Resolution <= 8u) /* 8-bit Timer */
        #define KeisokuTimer_CAPTURE_LSB         (* (reg8 *) KeisokuTimer_TimerUDB_sT16_timerdp_u0__F0_REG )
        #define KeisokuTimer_CAPTURE_LSB_PTR       ((reg8 *) KeisokuTimer_TimerUDB_sT16_timerdp_u0__F0_REG )
        #define KeisokuTimer_PERIOD_LSB          (* (reg8 *) KeisokuTimer_TimerUDB_sT16_timerdp_u0__D0_REG )
        #define KeisokuTimer_PERIOD_LSB_PTR        ((reg8 *) KeisokuTimer_TimerUDB_sT16_timerdp_u0__D0_REG )
        #define KeisokuTimer_COUNTER_LSB         (* (reg8 *) KeisokuTimer_TimerUDB_sT16_timerdp_u0__A0_REG )
        #define KeisokuTimer_COUNTER_LSB_PTR       ((reg8 *) KeisokuTimer_TimerUDB_sT16_timerdp_u0__A0_REG )
    #elif(KeisokuTimer_Resolution <= 16u) /* 8-bit Timer */
        #if(CY_PSOC3) /* 8-bit addres space */
            #define KeisokuTimer_CAPTURE_LSB         (* (reg16 *) KeisokuTimer_TimerUDB_sT16_timerdp_u0__F0_REG )
            #define KeisokuTimer_CAPTURE_LSB_PTR       ((reg16 *) KeisokuTimer_TimerUDB_sT16_timerdp_u0__F0_REG )
            #define KeisokuTimer_PERIOD_LSB          (* (reg16 *) KeisokuTimer_TimerUDB_sT16_timerdp_u0__D0_REG )
            #define KeisokuTimer_PERIOD_LSB_PTR        ((reg16 *) KeisokuTimer_TimerUDB_sT16_timerdp_u0__D0_REG )
            #define KeisokuTimer_COUNTER_LSB         (* (reg16 *) KeisokuTimer_TimerUDB_sT16_timerdp_u0__A0_REG )
            #define KeisokuTimer_COUNTER_LSB_PTR       ((reg16 *) KeisokuTimer_TimerUDB_sT16_timerdp_u0__A0_REG )
        #else /* 16-bit address space */
            #define KeisokuTimer_CAPTURE_LSB         (* (reg16 *) KeisokuTimer_TimerUDB_sT16_timerdp_u0__16BIT_F0_REG )
            #define KeisokuTimer_CAPTURE_LSB_PTR       ((reg16 *) KeisokuTimer_TimerUDB_sT16_timerdp_u0__16BIT_F0_REG )
            #define KeisokuTimer_PERIOD_LSB          (* (reg16 *) KeisokuTimer_TimerUDB_sT16_timerdp_u0__16BIT_D0_REG )
            #define KeisokuTimer_PERIOD_LSB_PTR        ((reg16 *) KeisokuTimer_TimerUDB_sT16_timerdp_u0__16BIT_D0_REG )
            #define KeisokuTimer_COUNTER_LSB         (* (reg16 *) KeisokuTimer_TimerUDB_sT16_timerdp_u0__16BIT_A0_REG )
            #define KeisokuTimer_COUNTER_LSB_PTR       ((reg16 *) KeisokuTimer_TimerUDB_sT16_timerdp_u0__16BIT_A0_REG )
        #endif /* CY_PSOC3 */
    #elif(KeisokuTimer_Resolution <= 24u)/* 24-bit Timer */
        #define KeisokuTimer_CAPTURE_LSB         (* (reg32 *) KeisokuTimer_TimerUDB_sT16_timerdp_u0__F0_REG )
        #define KeisokuTimer_CAPTURE_LSB_PTR       ((reg32 *) KeisokuTimer_TimerUDB_sT16_timerdp_u0__F0_REG )
        #define KeisokuTimer_PERIOD_LSB          (* (reg32 *) KeisokuTimer_TimerUDB_sT16_timerdp_u0__D0_REG )
        #define KeisokuTimer_PERIOD_LSB_PTR        ((reg32 *) KeisokuTimer_TimerUDB_sT16_timerdp_u0__D0_REG )
        #define KeisokuTimer_COUNTER_LSB         (* (reg32 *) KeisokuTimer_TimerUDB_sT16_timerdp_u0__A0_REG )
        #define KeisokuTimer_COUNTER_LSB_PTR       ((reg32 *) KeisokuTimer_TimerUDB_sT16_timerdp_u0__A0_REG )
    #else /* 32-bit Timer */
        #if(CY_PSOC3 || CY_PSOC5) /* 8-bit address space */
            #define KeisokuTimer_CAPTURE_LSB         (* (reg32 *) KeisokuTimer_TimerUDB_sT16_timerdp_u0__F0_REG )
            #define KeisokuTimer_CAPTURE_LSB_PTR       ((reg32 *) KeisokuTimer_TimerUDB_sT16_timerdp_u0__F0_REG )
            #define KeisokuTimer_PERIOD_LSB          (* (reg32 *) KeisokuTimer_TimerUDB_sT16_timerdp_u0__D0_REG )
            #define KeisokuTimer_PERIOD_LSB_PTR        ((reg32 *) KeisokuTimer_TimerUDB_sT16_timerdp_u0__D0_REG )
            #define KeisokuTimer_COUNTER_LSB         (* (reg32 *) KeisokuTimer_TimerUDB_sT16_timerdp_u0__A0_REG )
            #define KeisokuTimer_COUNTER_LSB_PTR       ((reg32 *) KeisokuTimer_TimerUDB_sT16_timerdp_u0__A0_REG )
        #else /* 32-bit address space */
            #define KeisokuTimer_CAPTURE_LSB         (* (reg32 *) KeisokuTimer_TimerUDB_sT16_timerdp_u0__32BIT_F0_REG )
            #define KeisokuTimer_CAPTURE_LSB_PTR       ((reg32 *) KeisokuTimer_TimerUDB_sT16_timerdp_u0__32BIT_F0_REG )
            #define KeisokuTimer_PERIOD_LSB          (* (reg32 *) KeisokuTimer_TimerUDB_sT16_timerdp_u0__32BIT_D0_REG )
            #define KeisokuTimer_PERIOD_LSB_PTR        ((reg32 *) KeisokuTimer_TimerUDB_sT16_timerdp_u0__32BIT_D0_REG )
            #define KeisokuTimer_COUNTER_LSB         (* (reg32 *) KeisokuTimer_TimerUDB_sT16_timerdp_u0__32BIT_A0_REG )
            #define KeisokuTimer_COUNTER_LSB_PTR       ((reg32 *) KeisokuTimer_TimerUDB_sT16_timerdp_u0__32BIT_A0_REG )
        #endif /* CY_PSOC3 || CY_PSOC5 */ 
    #endif

    #define KeisokuTimer_COUNTER_LSB_PTR_8BIT       ((reg8 *) KeisokuTimer_TimerUDB_sT16_timerdp_u0__A0_REG )
    
    #if (KeisokuTimer_UsingHWCaptureCounter)
        #define KeisokuTimer_CAP_COUNT              (*(reg8 *) KeisokuTimer_TimerUDB_sCapCount_counter__PERIOD_REG )
        #define KeisokuTimer_CAP_COUNT_PTR          ( (reg8 *) KeisokuTimer_TimerUDB_sCapCount_counter__PERIOD_REG )
        #define KeisokuTimer_CAPTURE_COUNT_CTRL     (*(reg8 *) KeisokuTimer_TimerUDB_sCapCount_counter__CONTROL_AUX_CTL_REG )
        #define KeisokuTimer_CAPTURE_COUNT_CTRL_PTR ( (reg8 *) KeisokuTimer_TimerUDB_sCapCount_counter__CONTROL_AUX_CTL_REG )
    #endif /* (KeisokuTimer_UsingHWCaptureCounter) */


    /***************************************
    *       Register Constants
    ***************************************/

    /* Control Register Bit Locations */
    #define KeisokuTimer_CTRL_INTCNT_SHIFT              0x00u       /* As defined by Verilog Implementation */
    #define KeisokuTimer_CTRL_TRIG_MODE_SHIFT           0x02u       /* As defined by Verilog Implementation */
    #define KeisokuTimer_CTRL_TRIG_EN_SHIFT             0x04u       /* As defined by Verilog Implementation */
    #define KeisokuTimer_CTRL_CAP_MODE_SHIFT            0x05u       /* As defined by Verilog Implementation */
    #define KeisokuTimer_CTRL_ENABLE_SHIFT              0x07u       /* As defined by Verilog Implementation */

    /* Control Register Bit Masks */
    #define KeisokuTimer_CTRL_INTCNT_MASK               ((uint8)((uint8)0x03u << KeisokuTimer_CTRL_INTCNT_SHIFT))
    #define KeisokuTimer_CTRL_TRIG_MODE_MASK            ((uint8)((uint8)0x03u << KeisokuTimer_CTRL_TRIG_MODE_SHIFT))
    #define KeisokuTimer_CTRL_TRIG_EN                   ((uint8)((uint8)0x01u << KeisokuTimer_CTRL_TRIG_EN_SHIFT))
    #define KeisokuTimer_CTRL_CAP_MODE_MASK             ((uint8)((uint8)0x03u << KeisokuTimer_CTRL_CAP_MODE_SHIFT))
    #define KeisokuTimer_CTRL_ENABLE                    ((uint8)((uint8)0x01u << KeisokuTimer_CTRL_ENABLE_SHIFT))

    /* Bit Counter (7-bit) Control Register Bit Definitions */
    /* As defined by the Register map for the AUX Control Register */
    #define KeisokuTimer_CNTR_ENABLE                    0x20u

    /* Status Register Bit Locations */
    #define KeisokuTimer_STATUS_TC_SHIFT                0x00u  /* As defined by Verilog Implementation */
    #define KeisokuTimer_STATUS_CAPTURE_SHIFT           0x01u  /* As defined by Verilog Implementation */
    #define KeisokuTimer_STATUS_TC_INT_MASK_SHIFT       KeisokuTimer_STATUS_TC_SHIFT
    #define KeisokuTimer_STATUS_CAPTURE_INT_MASK_SHIFT  KeisokuTimer_STATUS_CAPTURE_SHIFT
    #define KeisokuTimer_STATUS_FIFOFULL_SHIFT          0x02u  /* As defined by Verilog Implementation */
    #define KeisokuTimer_STATUS_FIFONEMP_SHIFT          0x03u  /* As defined by Verilog Implementation */
    #define KeisokuTimer_STATUS_FIFOFULL_INT_MASK_SHIFT KeisokuTimer_STATUS_FIFOFULL_SHIFT

    /* Status Register Bit Masks */
    /* Sticky TC Event Bit-Mask */
    #define KeisokuTimer_STATUS_TC                      ((uint8)((uint8)0x01u << KeisokuTimer_STATUS_TC_SHIFT))
    /* Sticky Capture Event Bit-Mask */
    #define KeisokuTimer_STATUS_CAPTURE                 ((uint8)((uint8)0x01u << KeisokuTimer_STATUS_CAPTURE_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define KeisokuTimer_STATUS_TC_INT_MASK             ((uint8)((uint8)0x01u << KeisokuTimer_STATUS_TC_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define KeisokuTimer_STATUS_CAPTURE_INT_MASK        ((uint8)((uint8)0x01u << KeisokuTimer_STATUS_CAPTURE_SHIFT))
    /* NOT-Sticky FIFO Full Bit-Mask */
    #define KeisokuTimer_STATUS_FIFOFULL                ((uint8)((uint8)0x01u << KeisokuTimer_STATUS_FIFOFULL_SHIFT))
    /* NOT-Sticky FIFO Not Empty Bit-Mask */
    #define KeisokuTimer_STATUS_FIFONEMP                ((uint8)((uint8)0x01u << KeisokuTimer_STATUS_FIFONEMP_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define KeisokuTimer_STATUS_FIFOFULL_INT_MASK       ((uint8)((uint8)0x01u << KeisokuTimer_STATUS_FIFOFULL_SHIFT))

    #define KeisokuTimer_STATUS_ACTL_INT_EN             0x10u   /* As defined for the ACTL Register */

    /* Datapath Auxillary Control Register definitions */
    #define KeisokuTimer_AUX_CTRL_FIFO0_CLR             0x01u   /* As defined by Register map */
    #define KeisokuTimer_AUX_CTRL_FIFO1_CLR             0x02u   /* As defined by Register map */
    #define KeisokuTimer_AUX_CTRL_FIFO0_LVL             0x04u   /* As defined by Register map */
    #define KeisokuTimer_AUX_CTRL_FIFO1_LVL             0x08u   /* As defined by Register map */
    #define KeisokuTimer_STATUS_ACTL_INT_EN_MASK        0x10u   /* As defined for the ACTL Register */

#endif /* Implementation Specific Registers and Register Constants */

#endif  /* CY_Timer_v2_30_KeisokuTimer_H */


/* [] END OF FILE */
