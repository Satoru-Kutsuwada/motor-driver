/*******************************************************************************
* File Name: hu0.h  
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

#if !defined(CY_PINS_hu0_H) /* Pins hu0_H */
#define CY_PINS_hu0_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "hu0_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 hu0__PORT == 15 && ((hu0__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    hu0_Write(uint8 value);
void    hu0_SetDriveMode(uint8 mode);
uint8   hu0_ReadDataReg(void);
uint8   hu0_Read(void);
void    hu0_SetInterruptMode(uint16 position, uint16 mode);
uint8   hu0_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the hu0_SetDriveMode() function.
     *  @{
     */
        #define hu0_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define hu0_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define hu0_DM_RES_UP          PIN_DM_RES_UP
        #define hu0_DM_RES_DWN         PIN_DM_RES_DWN
        #define hu0_DM_OD_LO           PIN_DM_OD_LO
        #define hu0_DM_OD_HI           PIN_DM_OD_HI
        #define hu0_DM_STRONG          PIN_DM_STRONG
        #define hu0_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define hu0_MASK               hu0__MASK
#define hu0_SHIFT              hu0__SHIFT
#define hu0_WIDTH              1u

/* Interrupt constants */
#if defined(hu0__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in hu0_SetInterruptMode() function.
     *  @{
     */
        #define hu0_INTR_NONE      (uint16)(0x0000u)
        #define hu0_INTR_RISING    (uint16)(0x0001u)
        #define hu0_INTR_FALLING   (uint16)(0x0002u)
        #define hu0_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define hu0_INTR_MASK      (0x01u) 
#endif /* (hu0__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define hu0_PS                     (* (reg8 *) hu0__PS)
/* Data Register */
#define hu0_DR                     (* (reg8 *) hu0__DR)
/* Port Number */
#define hu0_PRT_NUM                (* (reg8 *) hu0__PRT) 
/* Connect to Analog Globals */                                                  
#define hu0_AG                     (* (reg8 *) hu0__AG)                       
/* Analog MUX bux enable */
#define hu0_AMUX                   (* (reg8 *) hu0__AMUX) 
/* Bidirectional Enable */                                                        
#define hu0_BIE                    (* (reg8 *) hu0__BIE)
/* Bit-mask for Aliased Register Access */
#define hu0_BIT_MASK               (* (reg8 *) hu0__BIT_MASK)
/* Bypass Enable */
#define hu0_BYP                    (* (reg8 *) hu0__BYP)
/* Port wide control signals */                                                   
#define hu0_CTL                    (* (reg8 *) hu0__CTL)
/* Drive Modes */
#define hu0_DM0                    (* (reg8 *) hu0__DM0) 
#define hu0_DM1                    (* (reg8 *) hu0__DM1)
#define hu0_DM2                    (* (reg8 *) hu0__DM2) 
/* Input Buffer Disable Override */
#define hu0_INP_DIS                (* (reg8 *) hu0__INP_DIS)
/* LCD Common or Segment Drive */
#define hu0_LCD_COM_SEG            (* (reg8 *) hu0__LCD_COM_SEG)
/* Enable Segment LCD */
#define hu0_LCD_EN                 (* (reg8 *) hu0__LCD_EN)
/* Slew Rate Control */
#define hu0_SLW                    (* (reg8 *) hu0__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define hu0_PRTDSI__CAPS_SEL       (* (reg8 *) hu0__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define hu0_PRTDSI__DBL_SYNC_IN    (* (reg8 *) hu0__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define hu0_PRTDSI__OE_SEL0        (* (reg8 *) hu0__PRTDSI__OE_SEL0) 
#define hu0_PRTDSI__OE_SEL1        (* (reg8 *) hu0__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define hu0_PRTDSI__OUT_SEL0       (* (reg8 *) hu0__PRTDSI__OUT_SEL0) 
#define hu0_PRTDSI__OUT_SEL1       (* (reg8 *) hu0__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define hu0_PRTDSI__SYNC_OUT       (* (reg8 *) hu0__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(hu0__SIO_CFG)
    #define hu0_SIO_HYST_EN        (* (reg8 *) hu0__SIO_HYST_EN)
    #define hu0_SIO_REG_HIFREQ     (* (reg8 *) hu0__SIO_REG_HIFREQ)
    #define hu0_SIO_CFG            (* (reg8 *) hu0__SIO_CFG)
    #define hu0_SIO_DIFF           (* (reg8 *) hu0__SIO_DIFF)
#endif /* (hu0__SIO_CFG) */

/* Interrupt Registers */
#if defined(hu0__INTSTAT)
    #define hu0_INTSTAT            (* (reg8 *) hu0__INTSTAT)
    #define hu0_SNAP               (* (reg8 *) hu0__SNAP)
    
	#define hu0_0_INTTYPE_REG 		(* (reg8 *) hu0__0__INTTYPE)
#endif /* (hu0__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_hu0_H */


/* [] END OF FILE */
