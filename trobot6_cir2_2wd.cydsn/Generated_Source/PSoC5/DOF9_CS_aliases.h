/*******************************************************************************
* File Name: DOF9_CS.h  
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

#if !defined(CY_PINS_DOF9_CS_ALIASES_H) /* Pins DOF9_CS_ALIASES_H */
#define CY_PINS_DOF9_CS_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define DOF9_CS_0			(DOF9_CS__0__PC)
#define DOF9_CS_0_INTR	((uint16)((uint16)0x0001u << DOF9_CS__0__SHIFT))

#define DOF9_CS_INTR_ALL	 ((uint16)(DOF9_CS_0_INTR))

#endif /* End Pins DOF9_CS_ALIASES_H */


/* [] END OF FILE */
