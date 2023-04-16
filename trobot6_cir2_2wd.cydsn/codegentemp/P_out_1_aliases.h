/*******************************************************************************
* File Name: P_out_1.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_P_out_1_ALIASES_H) /* Pins P_out_1_ALIASES_H */
#define CY_PINS_P_out_1_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define P_out_1_0			(P_out_1__0__PC)
#define P_out_1_0_INTR	((uint16)((uint16)0x0001u << P_out_1__0__SHIFT))

#define P_out_1_1			(P_out_1__1__PC)
#define P_out_1_1_INTR	((uint16)((uint16)0x0001u << P_out_1__1__SHIFT))

#define P_out_1_INTR_ALL	 ((uint16)(P_out_1_0_INTR| P_out_1_1_INTR))

#endif /* End Pins P_out_1_ALIASES_H */


/* [] END OF FILE */
