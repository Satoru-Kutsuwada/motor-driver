/*******************************************************************************
* File Name: EM_STOP.h  
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

#if !defined(CY_PINS_EM_STOP_ALIASES_H) /* Pins EM_STOP_ALIASES_H */
#define CY_PINS_EM_STOP_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define EM_STOP_0			(EM_STOP__0__PC)
#define EM_STOP_0_INTR	((uint16)((uint16)0x0001u << EM_STOP__0__SHIFT))

#define EM_STOP_INTR_ALL	 ((uint16)(EM_STOP_0_INTR))

#endif /* End Pins EM_STOP_ALIASES_H */


/* [] END OF FILE */
