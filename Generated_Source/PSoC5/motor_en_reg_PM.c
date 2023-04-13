/*******************************************************************************
* File Name: motor_en_reg_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "motor_en_reg.h"

/* Check for removal by optimization */
#if !defined(motor_en_reg_Sync_ctrl_reg__REMOVED)

static motor_en_reg_BACKUP_STRUCT  motor_en_reg_backup = {0u};

    
/*******************************************************************************
* Function Name: motor_en_reg_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void motor_en_reg_SaveConfig(void) 
{
    motor_en_reg_backup.controlState = motor_en_reg_Control;
}


/*******************************************************************************
* Function Name: motor_en_reg_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void motor_en_reg_RestoreConfig(void) 
{
     motor_en_reg_Control = motor_en_reg_backup.controlState;
}


/*******************************************************************************
* Function Name: motor_en_reg_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void motor_en_reg_Sleep(void) 
{
    motor_en_reg_SaveConfig();
}


/*******************************************************************************
* Function Name: motor_en_reg_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void motor_en_reg_Wakeup(void)  
{
    motor_en_reg_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
