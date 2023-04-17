/*******************************************************************************
* File Name: KeisokuTimer_PM.c
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

#include "KeisokuTimer.h"

static KeisokuTimer_backupStruct KeisokuTimer_backup;


/*******************************************************************************
* Function Name: KeisokuTimer_SaveConfig
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
*  KeisokuTimer_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void KeisokuTimer_SaveConfig(void) 
{
    #if (!KeisokuTimer_UsingFixedFunction)
        KeisokuTimer_backup.TimerUdb = KeisokuTimer_ReadCounter();
        KeisokuTimer_backup.InterruptMaskValue = KeisokuTimer_STATUS_MASK;
        #if (KeisokuTimer_UsingHWCaptureCounter)
            KeisokuTimer_backup.TimerCaptureCounter = KeisokuTimer_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!KeisokuTimer_UDB_CONTROL_REG_REMOVED)
            KeisokuTimer_backup.TimerControlRegister = KeisokuTimer_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: KeisokuTimer_RestoreConfig
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
*  KeisokuTimer_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void KeisokuTimer_RestoreConfig(void) 
{   
    #if (!KeisokuTimer_UsingFixedFunction)

        KeisokuTimer_WriteCounter(KeisokuTimer_backup.TimerUdb);
        KeisokuTimer_STATUS_MASK =KeisokuTimer_backup.InterruptMaskValue;
        #if (KeisokuTimer_UsingHWCaptureCounter)
            KeisokuTimer_SetCaptureCount(KeisokuTimer_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!KeisokuTimer_UDB_CONTROL_REG_REMOVED)
            KeisokuTimer_WriteControlRegister(KeisokuTimer_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: KeisokuTimer_Sleep
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
*  KeisokuTimer_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void KeisokuTimer_Sleep(void) 
{
    #if(!KeisokuTimer_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(KeisokuTimer_CTRL_ENABLE == (KeisokuTimer_CONTROL & KeisokuTimer_CTRL_ENABLE))
        {
            /* Timer is enabled */
            KeisokuTimer_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            KeisokuTimer_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    KeisokuTimer_Stop();
    KeisokuTimer_SaveConfig();
}


/*******************************************************************************
* Function Name: KeisokuTimer_Wakeup
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
*  KeisokuTimer_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void KeisokuTimer_Wakeup(void) 
{
    KeisokuTimer_RestoreConfig();
    #if(!KeisokuTimer_UDB_CONTROL_REG_REMOVED)
        if(KeisokuTimer_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                KeisokuTimer_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
