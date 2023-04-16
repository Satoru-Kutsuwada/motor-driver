/*******************************************************************************
* File Name: BMP_SW.h  
* Version 1.90
*
* Description:
*  This file containts Status Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_STATUS_REG_BMP_SW_H) /* CY_STATUS_REG_BMP_SW_H */
#define CY_STATUS_REG_BMP_SW_H

#include "cytypes.h"
#include "CyLib.h"

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 statusState;

} BMP_SW_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

uint8 BMP_SW_Read(void) ;
void BMP_SW_InterruptEnable(void) ;
void BMP_SW_InterruptDisable(void) ;
void BMP_SW_WriteMask(uint8 mask) ;
uint8 BMP_SW_ReadMask(void) ;


/***************************************
*           API Constants
***************************************/

#define BMP_SW_STATUS_INTR_ENBL    0x10u


/***************************************
*         Parameter Constants
***************************************/

/* Status Register Inputs */
#define BMP_SW_INPUTS              8


/***************************************
*             Registers
***************************************/

/* Status Register */
#define BMP_SW_Status             (* (reg8 *) BMP_SW_sts_sts_reg__STATUS_REG )
#define BMP_SW_Status_PTR         (  (reg8 *) BMP_SW_sts_sts_reg__STATUS_REG )
#define BMP_SW_Status_Mask        (* (reg8 *) BMP_SW_sts_sts_reg__MASK_REG )
#define BMP_SW_Status_Aux_Ctrl    (* (reg8 *) BMP_SW_sts_sts_reg__STATUS_AUX_CTL_REG )

#endif /* End CY_STATUS_REG_BMP_SW_H */


/* [] END OF FILE */
