/*******************************************************************************
* File Name: motor_contl_reg_0.h  
* Version 1.80
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CONTROL_REG_motor_contl_reg_0_H) /* CY_CONTROL_REG_motor_contl_reg_0_H */
#define CY_CONTROL_REG_motor_contl_reg_0_H

#include "cytypes.h"

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 controlState;

} motor_contl_reg_0_BACKUP_STRUCT;


/***************************************
*         Function Prototypes 
***************************************/

void    motor_contl_reg_0_Write(uint8 control) ;
uint8   motor_contl_reg_0_Read(void) ;

void motor_contl_reg_0_SaveConfig(void) ;
void motor_contl_reg_0_RestoreConfig(void) ;
void motor_contl_reg_0_Sleep(void) ; 
void motor_contl_reg_0_Wakeup(void) ;


/***************************************
*            Registers        
***************************************/

/* Control Register */
#define motor_contl_reg_0_Control        (* (reg8 *) motor_contl_reg_0_Sync_ctrl_reg__CONTROL_REG )
#define motor_contl_reg_0_Control_PTR    (  (reg8 *) motor_contl_reg_0_Sync_ctrl_reg__CONTROL_REG )

#endif /* End CY_CONTROL_REG_motor_contl_reg_0_H */


/* [] END OF FILE */
