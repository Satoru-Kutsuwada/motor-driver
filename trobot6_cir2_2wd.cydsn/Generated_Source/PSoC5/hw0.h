/*******************************************************************************
* File Name: hw0.h  
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

#if !defined(CY_PINS_hw0_H) /* Pins hw0_H */
#define CY_PINS_hw0_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "hw0_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 hw0__PORT == 15 && ((hw0__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    hw0_Write(uint8 value);
void    hw0_SetDriveMode(uint8 mode);
uint8   hw0_ReadDataReg(void);
uint8   hw0_Read(void);
void    hw0_SetInterruptMode(uint16 position, uint16 mode);
uint8   hw0_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the hw0_SetDriveMode() function.
     *  @{
     */
        #define hw0_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define hw0_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define hw0_DM_RES_UP          PIN_DM_RES_UP
        #define hw0_DM_RES_DWN         PIN_DM_RES_DWN
        #define hw0_DM_OD_LO           PIN_DM_OD_LO
        #define hw0_DM_OD_HI           PIN_DM_OD_HI
        #define hw0_DM_STRONG          PIN_DM_STRONG
        #define hw0_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define hw0_MASK               hw0__MASK
#define hw0_SHIFT              hw0__SHIFT
#define hw0_WIDTH              1u

/* Interrupt constants */
#if defined(hw0__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in hw0_SetInterruptMode() function.
     *  @{
     */
        #define hw0_INTR_NONE      (uint16)(0x0000u)
        #define hw0_INTR_RISING    (uint16)(0x0001u)
        #define hw0_INTR_FALLING   (uint16)(0x0002u)
        #define hw0_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define hw0_INTR_MASK      (0x01u) 
#endif /* (hw0__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define hw0_PS                     (* (reg8 *) hw0__PS)
/* Data Register */
#define hw0_DR                     (* (reg8 *) hw0__DR)
/* Port Number */
#define hw0_PRT_NUM                (* (reg8 *) hw0__PRT) 
/* Connect to Analog Globals */                                                  
#define hw0_AG                     (* (reg8 *) hw0__AG)                       
/* Analog MUX bux enable */
#define hw0_AMUX                   (* (reg8 *) hw0__AMUX) 
/* Bidirectional Enable */                                                        
#define hw0_BIE                    (* (reg8 *) hw0__BIE)
/* Bit-mask for Aliased Register Access */
#define hw0_BIT_MASK               (* (reg8 *) hw0__BIT_MASK)
/* Bypass Enable */
#define hw0_BYP                    (* (reg8 *) hw0__BYP)
/* Port wide control signals */                                                   
#define hw0_CTL                    (* (reg8 *) hw0__CTL)
/* Drive Modes */
#define hw0_DM0                    (* (reg8 *) hw0__DM0) 
#define hw0_DM1                    (* (reg8 *) hw0__DM1)
#define hw0_DM2                    (* (reg8 *) hw0__DM2) 
/* Input Buffer Disable Override */
#define hw0_INP_DIS                (* (reg8 *) hw0__INP_DIS)
/* LCD Common or Segment Drive */
#define hw0_LCD_COM_SEG            (* (reg8 *) hw0__LCD_COM_SEG)
/* Enable Segment LCD */
#define hw0_LCD_EN                 (* (reg8 *) hw0__LCD_EN)
/* Slew Rate Control */
#define hw0_SLW                    (* (reg8 *) hw0__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define hw0_PRTDSI__CAPS_SEL       (* (reg8 *) hw0__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define hw0_PRTDSI__DBL_SYNC_IN    (* (reg8 *) hw0__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define hw0_PRTDSI__OE_SEL0        (* (reg8 *) hw0__PRTDSI__OE_SEL0) 
#define hw0_PRTDSI__OE_SEL1        (* (reg8 *) hw0__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define hw0_PRTDSI__OUT_SEL0       (* (reg8 *) hw0__PRTDSI__OUT_SEL0) 
#define hw0_PRTDSI__OUT_SEL1       (* (reg8 *) hw0__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define hw0_PRTDSI__SYNC_OUT       (* (reg8 *) hw0__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(hw0__SIO_CFG)
    #define hw0_SIO_HYST_EN        (* (reg8 *) hw0__SIO_HYST_EN)
    #define hw0_SIO_REG_HIFREQ     (* (reg8 *) hw0__SIO_REG_HIFREQ)
    #define hw0_SIO_CFG            (* (reg8 *) hw0__SIO_CFG)
    #define hw0_SIO_DIFF           (* (reg8 *) hw0__SIO_DIFF)
#endif /* (hw0__SIO_CFG) */

/* Interrupt Registers */
#if defined(hw0__INTSTAT)
    #define hw0_INTSTAT            (* (reg8 *) hw0__INTSTAT)
    #define hw0_SNAP               (* (reg8 *) hw0__SNAP)
    
	#define hw0_0_INTTYPE_REG 		(* (reg8 *) hw0__0__INTTYPE)
#endif /* (hw0__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_hw0_H */


/* [] END OF FILE */
