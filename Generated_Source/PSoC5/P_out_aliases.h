/*******************************************************************************
* File Name: P_out.h  
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

#if !defined(CY_PINS_P_out_ALIASES_H) /* Pins P_out_ALIASES_H */
#define CY_PINS_P_out_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define P_out_0			(P_out__0__PC)
#define P_out_0_INTR	((uint16)((uint16)0x0001u << P_out__0__SHIFT))

#define P_out_1			(P_out__1__PC)
#define P_out_1_INTR	((uint16)((uint16)0x0001u << P_out__1__SHIFT))

#define P_out_2			(P_out__2__PC)
#define P_out_2_INTR	((uint16)((uint16)0x0001u << P_out__2__SHIFT))

#define P_out_3			(P_out__3__PC)
#define P_out_3_INTR	((uint16)((uint16)0x0001u << P_out__3__SHIFT))

#define P_out_INTR_ALL	 ((uint16)(P_out_0_INTR| P_out_1_INTR| P_out_2_INTR| P_out_3_INTR))

#endif /* End Pins P_out_ALIASES_H */


/* [] END OF FILE */
