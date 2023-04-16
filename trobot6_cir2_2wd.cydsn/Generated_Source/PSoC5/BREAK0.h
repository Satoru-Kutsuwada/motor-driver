/*******************************************************************************
* File Name: BREAK0.h  
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

#if !defined(CY_PINS_BREAK0_H) /* Pins BREAK0_H */
#define CY_PINS_BREAK0_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "BREAK0_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 BREAK0__PORT == 15 && ((BREAK0__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    BREAK0_Write(uint8 value);
void    BREAK0_SetDriveMode(uint8 mode);
uint8   BREAK0_ReadDataReg(void);
uint8   BREAK0_Read(void);
void    BREAK0_SetInterruptMode(uint16 position, uint16 mode);
uint8   BREAK0_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the BREAK0_SetDriveMode() function.
     *  @{
     */
        #define BREAK0_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define BREAK0_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define BREAK0_DM_RES_UP          PIN_DM_RES_UP
        #define BREAK0_DM_RES_DWN         PIN_DM_RES_DWN
        #define BREAK0_DM_OD_LO           PIN_DM_OD_LO
        #define BREAK0_DM_OD_HI           PIN_DM_OD_HI
        #define BREAK0_DM_STRONG          PIN_DM_STRONG
        #define BREAK0_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define BREAK0_MASK               BREAK0__MASK
#define BREAK0_SHIFT              BREAK0__SHIFT
#define BREAK0_WIDTH              1u

/* Interrupt constants */
#if defined(BREAK0__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in BREAK0_SetInterruptMode() function.
     *  @{
     */
        #define BREAK0_INTR_NONE      (uint16)(0x0000u)
        #define BREAK0_INTR_RISING    (uint16)(0x0001u)
        #define BREAK0_INTR_FALLING   (uint16)(0x0002u)
        #define BREAK0_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define BREAK0_INTR_MASK      (0x01u) 
#endif /* (BREAK0__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define BREAK0_PS                     (* (reg8 *) BREAK0__PS)
/* Data Register */
#define BREAK0_DR                     (* (reg8 *) BREAK0__DR)
/* Port Number */
#define BREAK0_PRT_NUM                (* (reg8 *) BREAK0__PRT) 
/* Connect to Analog Globals */                                                  
#define BREAK0_AG                     (* (reg8 *) BREAK0__AG)                       
/* Analog MUX bux enable */
#define BREAK0_AMUX                   (* (reg8 *) BREAK0__AMUX) 
/* Bidirectional Enable */                                                        
#define BREAK0_BIE                    (* (reg8 *) BREAK0__BIE)
/* Bit-mask for Aliased Register Access */
#define BREAK0_BIT_MASK               (* (reg8 *) BREAK0__BIT_MASK)
/* Bypass Enable */
#define BREAK0_BYP                    (* (reg8 *) BREAK0__BYP)
/* Port wide control signals */                                                   
#define BREAK0_CTL                    (* (reg8 *) BREAK0__CTL)
/* Drive Modes */
#define BREAK0_DM0                    (* (reg8 *) BREAK0__DM0) 
#define BREAK0_DM1                    (* (reg8 *) BREAK0__DM1)
#define BREAK0_DM2                    (* (reg8 *) BREAK0__DM2) 
/* Input Buffer Disable Override */
#define BREAK0_INP_DIS                (* (reg8 *) BREAK0__INP_DIS)
/* LCD Common or Segment Drive */
#define BREAK0_LCD_COM_SEG            (* (reg8 *) BREAK0__LCD_COM_SEG)
/* Enable Segment LCD */
#define BREAK0_LCD_EN                 (* (reg8 *) BREAK0__LCD_EN)
/* Slew Rate Control */
#define BREAK0_SLW                    (* (reg8 *) BREAK0__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define BREAK0_PRTDSI__CAPS_SEL       (* (reg8 *) BREAK0__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define BREAK0_PRTDSI__DBL_SYNC_IN    (* (reg8 *) BREAK0__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define BREAK0_PRTDSI__OE_SEL0        (* (reg8 *) BREAK0__PRTDSI__OE_SEL0) 
#define BREAK0_PRTDSI__OE_SEL1        (* (reg8 *) BREAK0__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define BREAK0_PRTDSI__OUT_SEL0       (* (reg8 *) BREAK0__PRTDSI__OUT_SEL0) 
#define BREAK0_PRTDSI__OUT_SEL1       (* (reg8 *) BREAK0__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define BREAK0_PRTDSI__SYNC_OUT       (* (reg8 *) BREAK0__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(BREAK0__SIO_CFG)
    #define BREAK0_SIO_HYST_EN        (* (reg8 *) BREAK0__SIO_HYST_EN)
    #define BREAK0_SIO_REG_HIFREQ     (* (reg8 *) BREAK0__SIO_REG_HIFREQ)
    #define BREAK0_SIO_CFG            (* (reg8 *) BREAK0__SIO_CFG)
    #define BREAK0_SIO_DIFF           (* (reg8 *) BREAK0__SIO_DIFF)
#endif /* (BREAK0__SIO_CFG) */

/* Interrupt Registers */
#if defined(BREAK0__INTSTAT)
    #define BREAK0_INTSTAT            (* (reg8 *) BREAK0__INTSTAT)
    #define BREAK0_SNAP               (* (reg8 *) BREAK0__SNAP)
    
	#define BREAK0_0_INTTYPE_REG 		(* (reg8 *) BREAK0__0__INTTYPE)
#endif /* (BREAK0__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_BREAK0_H */


/* [] END OF FILE */
