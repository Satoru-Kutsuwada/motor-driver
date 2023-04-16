/*******************************************************************************
* File Name: BMP_SW.c  
* Version 1.90
*
* Description:
*  This file contains API to enable firmware to read the value of a Status 
*  Register.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "BMP_SW.h"

#if !defined(BMP_SW_sts_sts_reg__REMOVED) /* Check for removal by optimization */


/*******************************************************************************
* Function Name: BMP_SW_Read
********************************************************************************
*
* Summary:
*  Reads the current value assigned to the Status Register.
*
* Parameters:
*  None.
*
* Return:
*  The current value in the Status Register.
*
*******************************************************************************/
uint8 BMP_SW_Read(void) 
{ 
    return BMP_SW_Status;
}


/*******************************************************************************
* Function Name: BMP_SW_InterruptEnable
********************************************************************************
*
* Summary:
*  Enables the Status Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void BMP_SW_InterruptEnable(void) 
{
    uint8 interruptState;
    interruptState = CyEnterCriticalSection();
    BMP_SW_Status_Aux_Ctrl |= BMP_SW_STATUS_INTR_ENBL;
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: BMP_SW_InterruptDisable
********************************************************************************
*
* Summary:
*  Disables the Status Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void BMP_SW_InterruptDisable(void) 
{
    uint8 interruptState;
    interruptState = CyEnterCriticalSection();
    BMP_SW_Status_Aux_Ctrl &= (uint8)(~BMP_SW_STATUS_INTR_ENBL);
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: BMP_SW_WriteMask
********************************************************************************
*
* Summary:
*  Writes the current mask value assigned to the Status Register.
*
* Parameters:
*  mask:  Value to write into the mask register.
*
* Return:
*  None.
*
*******************************************************************************/
void BMP_SW_WriteMask(uint8 mask) 
{
    #if(BMP_SW_INPUTS < 8u)
    	mask &= ((uint8)(1u << BMP_SW_INPUTS) - 1u);
	#endif /* End BMP_SW_INPUTS < 8u */
    BMP_SW_Status_Mask = mask;
}


/*******************************************************************************
* Function Name: BMP_SW_ReadMask
********************************************************************************
*
* Summary:
*  Reads the current interrupt mask assigned to the Status Register.
*
* Parameters:
*  None.
*
* Return:
*  The value of the interrupt mask of the Status Register.
*
*******************************************************************************/
uint8 BMP_SW_ReadMask(void) 
{
    return BMP_SW_Status_Mask;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
