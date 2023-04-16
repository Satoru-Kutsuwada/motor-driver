/*******************************************************************************
* File Name: Dist4_PVM_CUR.h  
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

#if !defined(CY_PINS_Dist4_PVM_CUR_ALIASES_H) /* Pins Dist4_PVM_CUR_ALIASES_H */
#define CY_PINS_Dist4_PVM_CUR_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define Dist4_PVM_CUR_0			(Dist4_PVM_CUR__0__PC)
#define Dist4_PVM_CUR_0_INTR	((uint16)((uint16)0x0001u << Dist4_PVM_CUR__0__SHIFT))

#define Dist4_PVM_CUR_INTR_ALL	 ((uint16)(Dist4_PVM_CUR_0_INTR))

#endif /* End Pins Dist4_PVM_CUR_ALIASES_H */


/* [] END OF FILE */
