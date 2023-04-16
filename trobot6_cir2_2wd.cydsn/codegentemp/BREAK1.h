/*******************************************************************************
* File Name: BREAK1.h  
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

#if !defined(CY_PINS_BREAK1_H) /* Pins BREAK1_H */
#define CY_PINS_BREAK1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "BREAK1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 BREAK1__PORT == 15 && ((BREAK1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    BREAK1_Write(uint8 value);
void    BREAK1_SetDriveMode(uint8 mode);
uint8   BREAK1_ReadDataReg(void);
uint8   BREAK1_Read(void);
void    BREAK1_SetInterruptMode(uint16 position, uint16 mode);
uint8   BREAK1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the BREAK1_SetDriveMode() function.
     *  @{
     */
        #define BREAK1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define BREAK1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define BREAK1_DM_RES_UP          PIN_DM_RES_UP
        #define BREAK1_DM_RES_DWN         PIN_DM_RES_DWN
        #define BREAK1_DM_OD_LO           PIN_DM_OD_LO
        #define BREAK1_DM_OD_HI           PIN_DM_OD_HI
        #define BREAK1_DM_STRONG          PIN_DM_STRONG
        #define BREAK1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define BREAK1_MASK               BREAK1__MASK
#define BREAK1_SHIFT              BREAK1__SHIFT
#define BREAK1_WIDTH              1u

/* Interrupt constants */
#if defined(BREAK1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in BREAK1_SetInterruptMode() function.
     *  @{
     */
        #define BREAK1_INTR_NONE      (uint16)(0x0000u)
        #define BREAK1_INTR_RISING    (uint16)(0x0001u)
        #define BREAK1_INTR_FALLING   (uint16)(0x0002u)
        #define BREAK1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define BREAK1_INTR_MASK      (0x01u) 
#endif /* (BREAK1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define BREAK1_PS                     (* (reg8 *) BREAK1__PS)
/* Data Register */
#define BREAK1_DR                     (* (reg8 *) BREAK1__DR)
/* Port Number */
#define BREAK1_PRT_NUM                (* (reg8 *) BREAK1__PRT) 
/* Connect to Analog Globals */                                                  
#define BREAK1_AG                     (* (reg8 *) BREAK1__AG)                       
/* Analog MUX bux enable */
#define BREAK1_AMUX                   (* (reg8 *) BREAK1__AMUX) 
/* Bidirectional Enable */                                                        
#define BREAK1_BIE                    (* (reg8 *) BREAK1__BIE)
/* Bit-mask for Aliased Register Access */
#define BREAK1_BIT_MASK               (* (reg8 *) BREAK1__BIT_MASK)
/* Bypass Enable */
#define BREAK1_BYP                    (* (reg8 *) BREAK1__BYP)
/* Port wide control signals */                                                   
#define BREAK1_CTL                    (* (reg8 *) BREAK1__CTL)
/* Drive Modes */
#define BREAK1_DM0                    (* (reg8 *) BREAK1__DM0) 
#define BREAK1_DM1                    (* (reg8 *) BREAK1__DM1)
#define BREAK1_DM2                    (* (reg8 *) BREAK1__DM2) 
/* Input Buffer Disable Override */
#define BREAK1_INP_DIS                (* (reg8 *) BREAK1__INP_DIS)
/* LCD Common or Segment Drive */
#define BREAK1_LCD_COM_SEG            (* (reg8 *) BREAK1__LCD_COM_SEG)
/* Enable Segment LCD */
#define BREAK1_LCD_EN                 (* (reg8 *) BREAK1__LCD_EN)
/* Slew Rate Control */
#define BREAK1_SLW                    (* (reg8 *) BREAK1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define BREAK1_PRTDSI__CAPS_SEL       (* (reg8 *) BREAK1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define BREAK1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) BREAK1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define BREAK1_PRTDSI__OE_SEL0        (* (reg8 *) BREAK1__PRTDSI__OE_SEL0) 
#define BREAK1_PRTDSI__OE_SEL1        (* (reg8 *) BREAK1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define BREAK1_PRTDSI__OUT_SEL0       (* (reg8 *) BREAK1__PRTDSI__OUT_SEL0) 
#define BREAK1_PRTDSI__OUT_SEL1       (* (reg8 *) BREAK1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define BREAK1_PRTDSI__SYNC_OUT       (* (reg8 *) BREAK1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(BREAK1__SIO_CFG)
    #define BREAK1_SIO_HYST_EN        (* (reg8 *) BREAK1__SIO_HYST_EN)
    #define BREAK1_SIO_REG_HIFREQ     (* (reg8 *) BREAK1__SIO_REG_HIFREQ)
    #define BREAK1_SIO_CFG            (* (reg8 *) BREAK1__SIO_CFG)
    #define BREAK1_SIO_DIFF           (* (reg8 *) BREAK1__SIO_DIFF)
#endif /* (BREAK1__SIO_CFG) */

/* Interrupt Registers */
#if defined(BREAK1__INTSTAT)
    #define BREAK1_INTSTAT            (* (reg8 *) BREAK1__INTSTAT)
    #define BREAK1_SNAP               (* (reg8 *) BREAK1__SNAP)
    
	#define BREAK1_0_INTTYPE_REG 		(* (reg8 *) BREAK1__0__INTTYPE)
#endif /* (BREAK1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_BREAK1_H */


/* [] END OF FILE */
