/*******************************************************************************
* File Name: hu1.h  
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

#if !defined(CY_PINS_hu1_H) /* Pins hu1_H */
#define CY_PINS_hu1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "hu1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 hu1__PORT == 15 && ((hu1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    hu1_Write(uint8 value);
void    hu1_SetDriveMode(uint8 mode);
uint8   hu1_ReadDataReg(void);
uint8   hu1_Read(void);
void    hu1_SetInterruptMode(uint16 position, uint16 mode);
uint8   hu1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the hu1_SetDriveMode() function.
     *  @{
     */
        #define hu1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define hu1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define hu1_DM_RES_UP          PIN_DM_RES_UP
        #define hu1_DM_RES_DWN         PIN_DM_RES_DWN
        #define hu1_DM_OD_LO           PIN_DM_OD_LO
        #define hu1_DM_OD_HI           PIN_DM_OD_HI
        #define hu1_DM_STRONG          PIN_DM_STRONG
        #define hu1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define hu1_MASK               hu1__MASK
#define hu1_SHIFT              hu1__SHIFT
#define hu1_WIDTH              1u

/* Interrupt constants */
#if defined(hu1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in hu1_SetInterruptMode() function.
     *  @{
     */
        #define hu1_INTR_NONE      (uint16)(0x0000u)
        #define hu1_INTR_RISING    (uint16)(0x0001u)
        #define hu1_INTR_FALLING   (uint16)(0x0002u)
        #define hu1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define hu1_INTR_MASK      (0x01u) 
#endif /* (hu1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define hu1_PS                     (* (reg8 *) hu1__PS)
/* Data Register */
#define hu1_DR                     (* (reg8 *) hu1__DR)
/* Port Number */
#define hu1_PRT_NUM                (* (reg8 *) hu1__PRT) 
/* Connect to Analog Globals */                                                  
#define hu1_AG                     (* (reg8 *) hu1__AG)                       
/* Analog MUX bux enable */
#define hu1_AMUX                   (* (reg8 *) hu1__AMUX) 
/* Bidirectional Enable */                                                        
#define hu1_BIE                    (* (reg8 *) hu1__BIE)
/* Bit-mask for Aliased Register Access */
#define hu1_BIT_MASK               (* (reg8 *) hu1__BIT_MASK)
/* Bypass Enable */
#define hu1_BYP                    (* (reg8 *) hu1__BYP)
/* Port wide control signals */                                                   
#define hu1_CTL                    (* (reg8 *) hu1__CTL)
/* Drive Modes */
#define hu1_DM0                    (* (reg8 *) hu1__DM0) 
#define hu1_DM1                    (* (reg8 *) hu1__DM1)
#define hu1_DM2                    (* (reg8 *) hu1__DM2) 
/* Input Buffer Disable Override */
#define hu1_INP_DIS                (* (reg8 *) hu1__INP_DIS)
/* LCD Common or Segment Drive */
#define hu1_LCD_COM_SEG            (* (reg8 *) hu1__LCD_COM_SEG)
/* Enable Segment LCD */
#define hu1_LCD_EN                 (* (reg8 *) hu1__LCD_EN)
/* Slew Rate Control */
#define hu1_SLW                    (* (reg8 *) hu1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define hu1_PRTDSI__CAPS_SEL       (* (reg8 *) hu1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define hu1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) hu1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define hu1_PRTDSI__OE_SEL0        (* (reg8 *) hu1__PRTDSI__OE_SEL0) 
#define hu1_PRTDSI__OE_SEL1        (* (reg8 *) hu1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define hu1_PRTDSI__OUT_SEL0       (* (reg8 *) hu1__PRTDSI__OUT_SEL0) 
#define hu1_PRTDSI__OUT_SEL1       (* (reg8 *) hu1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define hu1_PRTDSI__SYNC_OUT       (* (reg8 *) hu1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(hu1__SIO_CFG)
    #define hu1_SIO_HYST_EN        (* (reg8 *) hu1__SIO_HYST_EN)
    #define hu1_SIO_REG_HIFREQ     (* (reg8 *) hu1__SIO_REG_HIFREQ)
    #define hu1_SIO_CFG            (* (reg8 *) hu1__SIO_CFG)
    #define hu1_SIO_DIFF           (* (reg8 *) hu1__SIO_DIFF)
#endif /* (hu1__SIO_CFG) */

/* Interrupt Registers */
#if defined(hu1__INTSTAT)
    #define hu1_INTSTAT            (* (reg8 *) hu1__INTSTAT)
    #define hu1_SNAP               (* (reg8 *) hu1__SNAP)
    
	#define hu1_0_INTTYPE_REG 		(* (reg8 *) hu1__0__INTTYPE)
#endif /* (hu1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_hu1_H */


/* [] END OF FILE */
