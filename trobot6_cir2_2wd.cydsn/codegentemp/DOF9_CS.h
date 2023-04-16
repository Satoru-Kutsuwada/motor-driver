/*******************************************************************************
* File Name: DOF9_CS.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_DOF9_CS_H) /* Pins DOF9_CS_H */
#define CY_PINS_DOF9_CS_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DOF9_CS_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 DOF9_CS__PORT == 15 && ((DOF9_CS__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    DOF9_CS_Write(uint8 value);
void    DOF9_CS_SetDriveMode(uint8 mode);
uint8   DOF9_CS_ReadDataReg(void);
uint8   DOF9_CS_Read(void);
void    DOF9_CS_SetInterruptMode(uint16 position, uint16 mode);
uint8   DOF9_CS_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the DOF9_CS_SetDriveMode() function.
     *  @{
     */
        #define DOF9_CS_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define DOF9_CS_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define DOF9_CS_DM_RES_UP          PIN_DM_RES_UP
        #define DOF9_CS_DM_RES_DWN         PIN_DM_RES_DWN
        #define DOF9_CS_DM_OD_LO           PIN_DM_OD_LO
        #define DOF9_CS_DM_OD_HI           PIN_DM_OD_HI
        #define DOF9_CS_DM_STRONG          PIN_DM_STRONG
        #define DOF9_CS_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define DOF9_CS_MASK               DOF9_CS__MASK
#define DOF9_CS_SHIFT              DOF9_CS__SHIFT
#define DOF9_CS_WIDTH              1u

/* Interrupt constants */
#if defined(DOF9_CS__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DOF9_CS_SetInterruptMode() function.
     *  @{
     */
        #define DOF9_CS_INTR_NONE      (uint16)(0x0000u)
        #define DOF9_CS_INTR_RISING    (uint16)(0x0001u)
        #define DOF9_CS_INTR_FALLING   (uint16)(0x0002u)
        #define DOF9_CS_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define DOF9_CS_INTR_MASK      (0x01u) 
#endif /* (DOF9_CS__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DOF9_CS_PS                     (* (reg8 *) DOF9_CS__PS)
/* Data Register */
#define DOF9_CS_DR                     (* (reg8 *) DOF9_CS__DR)
/* Port Number */
#define DOF9_CS_PRT_NUM                (* (reg8 *) DOF9_CS__PRT) 
/* Connect to Analog Globals */                                                  
#define DOF9_CS_AG                     (* (reg8 *) DOF9_CS__AG)                       
/* Analog MUX bux enable */
#define DOF9_CS_AMUX                   (* (reg8 *) DOF9_CS__AMUX) 
/* Bidirectional Enable */                                                        
#define DOF9_CS_BIE                    (* (reg8 *) DOF9_CS__BIE)
/* Bit-mask for Aliased Register Access */
#define DOF9_CS_BIT_MASK               (* (reg8 *) DOF9_CS__BIT_MASK)
/* Bypass Enable */
#define DOF9_CS_BYP                    (* (reg8 *) DOF9_CS__BYP)
/* Port wide control signals */                                                   
#define DOF9_CS_CTL                    (* (reg8 *) DOF9_CS__CTL)
/* Drive Modes */
#define DOF9_CS_DM0                    (* (reg8 *) DOF9_CS__DM0) 
#define DOF9_CS_DM1                    (* (reg8 *) DOF9_CS__DM1)
#define DOF9_CS_DM2                    (* (reg8 *) DOF9_CS__DM2) 
/* Input Buffer Disable Override */
#define DOF9_CS_INP_DIS                (* (reg8 *) DOF9_CS__INP_DIS)
/* LCD Common or Segment Drive */
#define DOF9_CS_LCD_COM_SEG            (* (reg8 *) DOF9_CS__LCD_COM_SEG)
/* Enable Segment LCD */
#define DOF9_CS_LCD_EN                 (* (reg8 *) DOF9_CS__LCD_EN)
/* Slew Rate Control */
#define DOF9_CS_SLW                    (* (reg8 *) DOF9_CS__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DOF9_CS_PRTDSI__CAPS_SEL       (* (reg8 *) DOF9_CS__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DOF9_CS_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DOF9_CS__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DOF9_CS_PRTDSI__OE_SEL0        (* (reg8 *) DOF9_CS__PRTDSI__OE_SEL0) 
#define DOF9_CS_PRTDSI__OE_SEL1        (* (reg8 *) DOF9_CS__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DOF9_CS_PRTDSI__OUT_SEL0       (* (reg8 *) DOF9_CS__PRTDSI__OUT_SEL0) 
#define DOF9_CS_PRTDSI__OUT_SEL1       (* (reg8 *) DOF9_CS__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DOF9_CS_PRTDSI__SYNC_OUT       (* (reg8 *) DOF9_CS__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(DOF9_CS__SIO_CFG)
    #define DOF9_CS_SIO_HYST_EN        (* (reg8 *) DOF9_CS__SIO_HYST_EN)
    #define DOF9_CS_SIO_REG_HIFREQ     (* (reg8 *) DOF9_CS__SIO_REG_HIFREQ)
    #define DOF9_CS_SIO_CFG            (* (reg8 *) DOF9_CS__SIO_CFG)
    #define DOF9_CS_SIO_DIFF           (* (reg8 *) DOF9_CS__SIO_DIFF)
#endif /* (DOF9_CS__SIO_CFG) */

/* Interrupt Registers */
#if defined(DOF9_CS__INTSTAT)
    #define DOF9_CS_INTSTAT            (* (reg8 *) DOF9_CS__INTSTAT)
    #define DOF9_CS_SNAP               (* (reg8 *) DOF9_CS__SNAP)
    
	#define DOF9_CS_0_INTTYPE_REG 		(* (reg8 *) DOF9_CS__0__INTTYPE)
#endif /* (DOF9_CS__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_DOF9_CS_H */


/* [] END OF FILE */
