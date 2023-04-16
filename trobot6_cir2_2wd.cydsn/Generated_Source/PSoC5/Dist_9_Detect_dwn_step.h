/*******************************************************************************
* File Name: Dist_9_Detect_dwn_step.h  
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

#if !defined(CY_PINS_Dist_9_Detect_dwn_step_H) /* Pins Dist_9_Detect_dwn_step_H */
#define CY_PINS_Dist_9_Detect_dwn_step_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Dist_9_Detect_dwn_step_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Dist_9_Detect_dwn_step__PORT == 15 && ((Dist_9_Detect_dwn_step__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Dist_9_Detect_dwn_step_Write(uint8 value);
void    Dist_9_Detect_dwn_step_SetDriveMode(uint8 mode);
uint8   Dist_9_Detect_dwn_step_ReadDataReg(void);
uint8   Dist_9_Detect_dwn_step_Read(void);
void    Dist_9_Detect_dwn_step_SetInterruptMode(uint16 position, uint16 mode);
uint8   Dist_9_Detect_dwn_step_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Dist_9_Detect_dwn_step_SetDriveMode() function.
     *  @{
     */
        #define Dist_9_Detect_dwn_step_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Dist_9_Detect_dwn_step_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Dist_9_Detect_dwn_step_DM_RES_UP          PIN_DM_RES_UP
        #define Dist_9_Detect_dwn_step_DM_RES_DWN         PIN_DM_RES_DWN
        #define Dist_9_Detect_dwn_step_DM_OD_LO           PIN_DM_OD_LO
        #define Dist_9_Detect_dwn_step_DM_OD_HI           PIN_DM_OD_HI
        #define Dist_9_Detect_dwn_step_DM_STRONG          PIN_DM_STRONG
        #define Dist_9_Detect_dwn_step_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Dist_9_Detect_dwn_step_MASK               Dist_9_Detect_dwn_step__MASK
#define Dist_9_Detect_dwn_step_SHIFT              Dist_9_Detect_dwn_step__SHIFT
#define Dist_9_Detect_dwn_step_WIDTH              1u

/* Interrupt constants */
#if defined(Dist_9_Detect_dwn_step__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Dist_9_Detect_dwn_step_SetInterruptMode() function.
     *  @{
     */
        #define Dist_9_Detect_dwn_step_INTR_NONE      (uint16)(0x0000u)
        #define Dist_9_Detect_dwn_step_INTR_RISING    (uint16)(0x0001u)
        #define Dist_9_Detect_dwn_step_INTR_FALLING   (uint16)(0x0002u)
        #define Dist_9_Detect_dwn_step_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Dist_9_Detect_dwn_step_INTR_MASK      (0x01u) 
#endif /* (Dist_9_Detect_dwn_step__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Dist_9_Detect_dwn_step_PS                     (* (reg8 *) Dist_9_Detect_dwn_step__PS)
/* Data Register */
#define Dist_9_Detect_dwn_step_DR                     (* (reg8 *) Dist_9_Detect_dwn_step__DR)
/* Port Number */
#define Dist_9_Detect_dwn_step_PRT_NUM                (* (reg8 *) Dist_9_Detect_dwn_step__PRT) 
/* Connect to Analog Globals */                                                  
#define Dist_9_Detect_dwn_step_AG                     (* (reg8 *) Dist_9_Detect_dwn_step__AG)                       
/* Analog MUX bux enable */
#define Dist_9_Detect_dwn_step_AMUX                   (* (reg8 *) Dist_9_Detect_dwn_step__AMUX) 
/* Bidirectional Enable */                                                        
#define Dist_9_Detect_dwn_step_BIE                    (* (reg8 *) Dist_9_Detect_dwn_step__BIE)
/* Bit-mask for Aliased Register Access */
#define Dist_9_Detect_dwn_step_BIT_MASK               (* (reg8 *) Dist_9_Detect_dwn_step__BIT_MASK)
/* Bypass Enable */
#define Dist_9_Detect_dwn_step_BYP                    (* (reg8 *) Dist_9_Detect_dwn_step__BYP)
/* Port wide control signals */                                                   
#define Dist_9_Detect_dwn_step_CTL                    (* (reg8 *) Dist_9_Detect_dwn_step__CTL)
/* Drive Modes */
#define Dist_9_Detect_dwn_step_DM0                    (* (reg8 *) Dist_9_Detect_dwn_step__DM0) 
#define Dist_9_Detect_dwn_step_DM1                    (* (reg8 *) Dist_9_Detect_dwn_step__DM1)
#define Dist_9_Detect_dwn_step_DM2                    (* (reg8 *) Dist_9_Detect_dwn_step__DM2) 
/* Input Buffer Disable Override */
#define Dist_9_Detect_dwn_step_INP_DIS                (* (reg8 *) Dist_9_Detect_dwn_step__INP_DIS)
/* LCD Common or Segment Drive */
#define Dist_9_Detect_dwn_step_LCD_COM_SEG            (* (reg8 *) Dist_9_Detect_dwn_step__LCD_COM_SEG)
/* Enable Segment LCD */
#define Dist_9_Detect_dwn_step_LCD_EN                 (* (reg8 *) Dist_9_Detect_dwn_step__LCD_EN)
/* Slew Rate Control */
#define Dist_9_Detect_dwn_step_SLW                    (* (reg8 *) Dist_9_Detect_dwn_step__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Dist_9_Detect_dwn_step_PRTDSI__CAPS_SEL       (* (reg8 *) Dist_9_Detect_dwn_step__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Dist_9_Detect_dwn_step_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Dist_9_Detect_dwn_step__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Dist_9_Detect_dwn_step_PRTDSI__OE_SEL0        (* (reg8 *) Dist_9_Detect_dwn_step__PRTDSI__OE_SEL0) 
#define Dist_9_Detect_dwn_step_PRTDSI__OE_SEL1        (* (reg8 *) Dist_9_Detect_dwn_step__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Dist_9_Detect_dwn_step_PRTDSI__OUT_SEL0       (* (reg8 *) Dist_9_Detect_dwn_step__PRTDSI__OUT_SEL0) 
#define Dist_9_Detect_dwn_step_PRTDSI__OUT_SEL1       (* (reg8 *) Dist_9_Detect_dwn_step__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Dist_9_Detect_dwn_step_PRTDSI__SYNC_OUT       (* (reg8 *) Dist_9_Detect_dwn_step__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Dist_9_Detect_dwn_step__SIO_CFG)
    #define Dist_9_Detect_dwn_step_SIO_HYST_EN        (* (reg8 *) Dist_9_Detect_dwn_step__SIO_HYST_EN)
    #define Dist_9_Detect_dwn_step_SIO_REG_HIFREQ     (* (reg8 *) Dist_9_Detect_dwn_step__SIO_REG_HIFREQ)
    #define Dist_9_Detect_dwn_step_SIO_CFG            (* (reg8 *) Dist_9_Detect_dwn_step__SIO_CFG)
    #define Dist_9_Detect_dwn_step_SIO_DIFF           (* (reg8 *) Dist_9_Detect_dwn_step__SIO_DIFF)
#endif /* (Dist_9_Detect_dwn_step__SIO_CFG) */

/* Interrupt Registers */
#if defined(Dist_9_Detect_dwn_step__INTSTAT)
    #define Dist_9_Detect_dwn_step_INTSTAT            (* (reg8 *) Dist_9_Detect_dwn_step__INTSTAT)
    #define Dist_9_Detect_dwn_step_SNAP               (* (reg8 *) Dist_9_Detect_dwn_step__SNAP)
    
	#define Dist_9_Detect_dwn_step_0_INTTYPE_REG 		(* (reg8 *) Dist_9_Detect_dwn_step__0__INTTYPE)
#endif /* (Dist_9_Detect_dwn_step__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Dist_9_Detect_dwn_step_H */


/* [] END OF FILE */
