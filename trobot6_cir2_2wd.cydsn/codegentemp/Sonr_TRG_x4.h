/*******************************************************************************
* File Name: Sonr_TRG_x4.h  
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

#if !defined(CY_PINS_Sonr_TRG_x4_H) /* Pins Sonr_TRG_x4_H */
#define CY_PINS_Sonr_TRG_x4_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Sonr_TRG_x4_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Sonr_TRG_x4__PORT == 15 && ((Sonr_TRG_x4__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Sonr_TRG_x4_Write(uint8 value);
void    Sonr_TRG_x4_SetDriveMode(uint8 mode);
uint8   Sonr_TRG_x4_ReadDataReg(void);
uint8   Sonr_TRG_x4_Read(void);
void    Sonr_TRG_x4_SetInterruptMode(uint16 position, uint16 mode);
uint8   Sonr_TRG_x4_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Sonr_TRG_x4_SetDriveMode() function.
     *  @{
     */
        #define Sonr_TRG_x4_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Sonr_TRG_x4_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Sonr_TRG_x4_DM_RES_UP          PIN_DM_RES_UP
        #define Sonr_TRG_x4_DM_RES_DWN         PIN_DM_RES_DWN
        #define Sonr_TRG_x4_DM_OD_LO           PIN_DM_OD_LO
        #define Sonr_TRG_x4_DM_OD_HI           PIN_DM_OD_HI
        #define Sonr_TRG_x4_DM_STRONG          PIN_DM_STRONG
        #define Sonr_TRG_x4_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Sonr_TRG_x4_MASK               Sonr_TRG_x4__MASK
#define Sonr_TRG_x4_SHIFT              Sonr_TRG_x4__SHIFT
#define Sonr_TRG_x4_WIDTH              1u

/* Interrupt constants */
#if defined(Sonr_TRG_x4__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Sonr_TRG_x4_SetInterruptMode() function.
     *  @{
     */
        #define Sonr_TRG_x4_INTR_NONE      (uint16)(0x0000u)
        #define Sonr_TRG_x4_INTR_RISING    (uint16)(0x0001u)
        #define Sonr_TRG_x4_INTR_FALLING   (uint16)(0x0002u)
        #define Sonr_TRG_x4_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Sonr_TRG_x4_INTR_MASK      (0x01u) 
#endif /* (Sonr_TRG_x4__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Sonr_TRG_x4_PS                     (* (reg8 *) Sonr_TRG_x4__PS)
/* Data Register */
#define Sonr_TRG_x4_DR                     (* (reg8 *) Sonr_TRG_x4__DR)
/* Port Number */
#define Sonr_TRG_x4_PRT_NUM                (* (reg8 *) Sonr_TRG_x4__PRT) 
/* Connect to Analog Globals */                                                  
#define Sonr_TRG_x4_AG                     (* (reg8 *) Sonr_TRG_x4__AG)                       
/* Analog MUX bux enable */
#define Sonr_TRG_x4_AMUX                   (* (reg8 *) Sonr_TRG_x4__AMUX) 
/* Bidirectional Enable */                                                        
#define Sonr_TRG_x4_BIE                    (* (reg8 *) Sonr_TRG_x4__BIE)
/* Bit-mask for Aliased Register Access */
#define Sonr_TRG_x4_BIT_MASK               (* (reg8 *) Sonr_TRG_x4__BIT_MASK)
/* Bypass Enable */
#define Sonr_TRG_x4_BYP                    (* (reg8 *) Sonr_TRG_x4__BYP)
/* Port wide control signals */                                                   
#define Sonr_TRG_x4_CTL                    (* (reg8 *) Sonr_TRG_x4__CTL)
/* Drive Modes */
#define Sonr_TRG_x4_DM0                    (* (reg8 *) Sonr_TRG_x4__DM0) 
#define Sonr_TRG_x4_DM1                    (* (reg8 *) Sonr_TRG_x4__DM1)
#define Sonr_TRG_x4_DM2                    (* (reg8 *) Sonr_TRG_x4__DM2) 
/* Input Buffer Disable Override */
#define Sonr_TRG_x4_INP_DIS                (* (reg8 *) Sonr_TRG_x4__INP_DIS)
/* LCD Common or Segment Drive */
#define Sonr_TRG_x4_LCD_COM_SEG            (* (reg8 *) Sonr_TRG_x4__LCD_COM_SEG)
/* Enable Segment LCD */
#define Sonr_TRG_x4_LCD_EN                 (* (reg8 *) Sonr_TRG_x4__LCD_EN)
/* Slew Rate Control */
#define Sonr_TRG_x4_SLW                    (* (reg8 *) Sonr_TRG_x4__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Sonr_TRG_x4_PRTDSI__CAPS_SEL       (* (reg8 *) Sonr_TRG_x4__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Sonr_TRG_x4_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Sonr_TRG_x4__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Sonr_TRG_x4_PRTDSI__OE_SEL0        (* (reg8 *) Sonr_TRG_x4__PRTDSI__OE_SEL0) 
#define Sonr_TRG_x4_PRTDSI__OE_SEL1        (* (reg8 *) Sonr_TRG_x4__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Sonr_TRG_x4_PRTDSI__OUT_SEL0       (* (reg8 *) Sonr_TRG_x4__PRTDSI__OUT_SEL0) 
#define Sonr_TRG_x4_PRTDSI__OUT_SEL1       (* (reg8 *) Sonr_TRG_x4__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Sonr_TRG_x4_PRTDSI__SYNC_OUT       (* (reg8 *) Sonr_TRG_x4__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Sonr_TRG_x4__SIO_CFG)
    #define Sonr_TRG_x4_SIO_HYST_EN        (* (reg8 *) Sonr_TRG_x4__SIO_HYST_EN)
    #define Sonr_TRG_x4_SIO_REG_HIFREQ     (* (reg8 *) Sonr_TRG_x4__SIO_REG_HIFREQ)
    #define Sonr_TRG_x4_SIO_CFG            (* (reg8 *) Sonr_TRG_x4__SIO_CFG)
    #define Sonr_TRG_x4_SIO_DIFF           (* (reg8 *) Sonr_TRG_x4__SIO_DIFF)
#endif /* (Sonr_TRG_x4__SIO_CFG) */

/* Interrupt Registers */
#if defined(Sonr_TRG_x4__INTSTAT)
    #define Sonr_TRG_x4_INTSTAT            (* (reg8 *) Sonr_TRG_x4__INTSTAT)
    #define Sonr_TRG_x4_SNAP               (* (reg8 *) Sonr_TRG_x4__SNAP)
    
	#define Sonr_TRG_x4_0_INTTYPE_REG 		(* (reg8 *) Sonr_TRG_x4__0__INTTYPE)
#endif /* (Sonr_TRG_x4__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Sonr_TRG_x4_H */


/* [] END OF FILE */
