/*******************************************************************************
* File Name: hw1.h  
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

#if !defined(CY_PINS_hw1_H) /* Pins hw1_H */
#define CY_PINS_hw1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "hw1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 hw1__PORT == 15 && ((hw1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    hw1_Write(uint8 value);
void    hw1_SetDriveMode(uint8 mode);
uint8   hw1_ReadDataReg(void);
uint8   hw1_Read(void);
void    hw1_SetInterruptMode(uint16 position, uint16 mode);
uint8   hw1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the hw1_SetDriveMode() function.
     *  @{
     */
        #define hw1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define hw1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define hw1_DM_RES_UP          PIN_DM_RES_UP
        #define hw1_DM_RES_DWN         PIN_DM_RES_DWN
        #define hw1_DM_OD_LO           PIN_DM_OD_LO
        #define hw1_DM_OD_HI           PIN_DM_OD_HI
        #define hw1_DM_STRONG          PIN_DM_STRONG
        #define hw1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define hw1_MASK               hw1__MASK
#define hw1_SHIFT              hw1__SHIFT
#define hw1_WIDTH              1u

/* Interrupt constants */
#if defined(hw1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in hw1_SetInterruptMode() function.
     *  @{
     */
        #define hw1_INTR_NONE      (uint16)(0x0000u)
        #define hw1_INTR_RISING    (uint16)(0x0001u)
        #define hw1_INTR_FALLING   (uint16)(0x0002u)
        #define hw1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define hw1_INTR_MASK      (0x01u) 
#endif /* (hw1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define hw1_PS                     (* (reg8 *) hw1__PS)
/* Data Register */
#define hw1_DR                     (* (reg8 *) hw1__DR)
/* Port Number */
#define hw1_PRT_NUM                (* (reg8 *) hw1__PRT) 
/* Connect to Analog Globals */                                                  
#define hw1_AG                     (* (reg8 *) hw1__AG)                       
/* Analog MUX bux enable */
#define hw1_AMUX                   (* (reg8 *) hw1__AMUX) 
/* Bidirectional Enable */                                                        
#define hw1_BIE                    (* (reg8 *) hw1__BIE)
/* Bit-mask for Aliased Register Access */
#define hw1_BIT_MASK               (* (reg8 *) hw1__BIT_MASK)
/* Bypass Enable */
#define hw1_BYP                    (* (reg8 *) hw1__BYP)
/* Port wide control signals */                                                   
#define hw1_CTL                    (* (reg8 *) hw1__CTL)
/* Drive Modes */
#define hw1_DM0                    (* (reg8 *) hw1__DM0) 
#define hw1_DM1                    (* (reg8 *) hw1__DM1)
#define hw1_DM2                    (* (reg8 *) hw1__DM2) 
/* Input Buffer Disable Override */
#define hw1_INP_DIS                (* (reg8 *) hw1__INP_DIS)
/* LCD Common or Segment Drive */
#define hw1_LCD_COM_SEG            (* (reg8 *) hw1__LCD_COM_SEG)
/* Enable Segment LCD */
#define hw1_LCD_EN                 (* (reg8 *) hw1__LCD_EN)
/* Slew Rate Control */
#define hw1_SLW                    (* (reg8 *) hw1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define hw1_PRTDSI__CAPS_SEL       (* (reg8 *) hw1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define hw1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) hw1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define hw1_PRTDSI__OE_SEL0        (* (reg8 *) hw1__PRTDSI__OE_SEL0) 
#define hw1_PRTDSI__OE_SEL1        (* (reg8 *) hw1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define hw1_PRTDSI__OUT_SEL0       (* (reg8 *) hw1__PRTDSI__OUT_SEL0) 
#define hw1_PRTDSI__OUT_SEL1       (* (reg8 *) hw1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define hw1_PRTDSI__SYNC_OUT       (* (reg8 *) hw1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(hw1__SIO_CFG)
    #define hw1_SIO_HYST_EN        (* (reg8 *) hw1__SIO_HYST_EN)
    #define hw1_SIO_REG_HIFREQ     (* (reg8 *) hw1__SIO_REG_HIFREQ)
    #define hw1_SIO_CFG            (* (reg8 *) hw1__SIO_CFG)
    #define hw1_SIO_DIFF           (* (reg8 *) hw1__SIO_DIFF)
#endif /* (hw1__SIO_CFG) */

/* Interrupt Registers */
#if defined(hw1__INTSTAT)
    #define hw1_INTSTAT            (* (reg8 *) hw1__INTSTAT)
    #define hw1_SNAP               (* (reg8 *) hw1__SNAP)
    
	#define hw1_0_INTTYPE_REG 		(* (reg8 *) hw1__0__INTTYPE)
#endif /* (hw1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_hw1_H */


/* [] END OF FILE */
