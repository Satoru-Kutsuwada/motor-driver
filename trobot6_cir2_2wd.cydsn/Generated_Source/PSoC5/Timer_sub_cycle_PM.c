/*******************************************************************************
* File Name: Timer_sub_cycle_PM.c
* Version 2.70
*
*  Description:
*     This file provides the power management source code to API for the
*     Timer.
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "Timer_sub_cycle.h"

static Timer_sub_cycle_backupStruct Timer_sub_cycle_backup;


/*******************************************************************************
* Function Name: Timer_sub_cycle_SaveConfig
********************************************************************************
*
* Summary:
*     Save the current user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timer_sub_cycle_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Timer_sub_cycle_SaveConfig(void) 
{
    #if (!Timer_sub_cycle_UsingFixedFunction)
        Timer_sub_cycle_backup.TimerUdb = Timer_sub_cycle_ReadCounter();
        Timer_sub_cycle_backup.InterruptMaskValue = Timer_sub_cycle_STATUS_MASK;
        #if (Timer_sub_cycle_UsingHWCaptureCounter)
            Timer_sub_cycle_backup.TimerCaptureCounter = Timer_sub_cycle_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!Timer_sub_cycle_UDB_CONTROL_REG_REMOVED)
            Timer_sub_cycle_backup.TimerControlRegister = Timer_sub_cycle_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: Timer_sub_cycle_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timer_sub_cycle_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Timer_sub_cycle_RestoreConfig(void) 
{   
    #if (!Timer_sub_cycle_UsingFixedFunction)

        Timer_sub_cycle_WriteCounter(Timer_sub_cycle_backup.TimerUdb);
        Timer_sub_cycle_STATUS_MASK =Timer_sub_cycle_backup.InterruptMaskValue;
        #if (Timer_sub_cycle_UsingHWCaptureCounter)
            Timer_sub_cycle_SetCaptureCount(Timer_sub_cycle_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!Timer_sub_cycle_UDB_CONTROL_REG_REMOVED)
            Timer_sub_cycle_WriteControlRegister(Timer_sub_cycle_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: Timer_sub_cycle_Sleep
********************************************************************************
*
* Summary:
*     Stop and Save the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timer_sub_cycle_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void Timer_sub_cycle_Sleep(void) 
{
    #if(!Timer_sub_cycle_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(Timer_sub_cycle_CTRL_ENABLE == (Timer_sub_cycle_CONTROL & Timer_sub_cycle_CTRL_ENABLE))
        {
            /* Timer is enabled */
            Timer_sub_cycle_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            Timer_sub_cycle_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    Timer_sub_cycle_Stop();
    Timer_sub_cycle_SaveConfig();
}


/*******************************************************************************
* Function Name: Timer_sub_cycle_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timer_sub_cycle_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Timer_sub_cycle_Wakeup(void) 
{
    Timer_sub_cycle_RestoreConfig();
    #if(!Timer_sub_cycle_UDB_CONTROL_REG_REMOVED)
        if(Timer_sub_cycle_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                Timer_sub_cycle_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
