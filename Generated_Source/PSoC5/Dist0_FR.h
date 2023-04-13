/*******************************************************************************
* File Name: Dist0_FR.h  
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

#if !defined(CY_PINS_Dist0_FR_H) /* Pins Dist0_FR_H */
#define CY_PINS_Dist0_FR_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Dist0_FR_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Dist0_FR__PORT == 15 && ((Dist0_FR__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Dist0_FR_Write(uint8 value);
void    Dist0_FR_SetDriveMode(uint8 mode);
uint8   Dist0_FR_ReadDataReg(void);
uint8   Dist0_FR_Read(void);
void    Dist0_FR_SetInterruptMode(uint16 position, uint16 mode);
uint8   Dist0_FR_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Dist0_FR_SetDriveMode() function.
     *  @{
     */
        #define Dist0_FR_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Dist0_FR_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Dist0_FR_DM_RES_UP          PIN_DM_RES_UP
        #define Dist0_FR_DM_RES_DWN         PIN_DM_RES_DWN
        #define Dist0_FR_DM_OD_LO           PIN_DM_OD_LO
        #define Dist0_FR_DM_OD_HI           PIN_DM_OD_HI
        #define Dist0_FR_DM_STRONG          PIN_DM_STRONG
        #define Dist0_FR_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Dist0_FR_MASK               Dist0_FR__MASK
#define Dist0_FR_SHIFT              Dist0_FR__SHIFT
#define Dist0_FR_WIDTH              1u

/* Interrupt constants */
#if defined(Dist0_FR__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Dist0_FR_SetInterruptMode() function.
     *  @{
     */
        #define Dist0_FR_INTR_NONE      (uint16)(0x0000u)
        #define Dist0_FR_INTR_RISING    (uint16)(0x0001u)
        #define Dist0_FR_INTR_FALLING   (uint16)(0x0002u)
        #define Dist0_FR_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Dist0_FR_INTR_MASK      (0x01u) 
#endif /* (Dist0_FR__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Dist0_FR_PS                     (* (reg8 *) Dist0_FR__PS)
/* Data Register */
#define Dist0_FR_DR                     (* (reg8 *) Dist0_FR__DR)
/* Port Number */
#define Dist0_FR_PRT_NUM                (* (reg8 *) Dist0_FR__PRT) 
/* Connect to Analog Globals */                                                  
#define Dist0_FR_AG                     (* (reg8 *) Dist0_FR__AG)                       
/* Analog MUX bux enable */
#define Dist0_FR_AMUX                   (* (reg8 *) Dist0_FR__AMUX) 
/* Bidirectional Enable */                                                        
#define Dist0_FR_BIE                    (* (reg8 *) Dist0_FR__BIE)
/* Bit-mask for Aliased Register Access */
#define Dist0_FR_BIT_MASK               (* (reg8 *) Dist0_FR__BIT_MASK)
/* Bypass Enable */
#define Dist0_FR_BYP                    (* (reg8 *) Dist0_FR__BYP)
/* Port wide control signals */                                                   
#define Dist0_FR_CTL                    (* (reg8 *) Dist0_FR__CTL)
/* Drive Modes */
#define Dist0_FR_DM0                    (* (reg8 *) Dist0_FR__DM0) 
#define Dist0_FR_DM1                    (* (reg8 *) Dist0_FR__DM1)
#define Dist0_FR_DM2                    (* (reg8 *) Dist0_FR__DM2) 
/* Input Buffer Disable Override */
#define Dist0_FR_INP_DIS                (* (reg8 *) Dist0_FR__INP_DIS)
/* LCD Common or Segment Drive */
#define Dist0_FR_LCD_COM_SEG            (* (reg8 *) Dist0_FR__LCD_COM_SEG)
/* Enable Segment LCD */
#define Dist0_FR_LCD_EN                 (* (reg8 *) Dist0_FR__LCD_EN)
/* Slew Rate Control */
#define Dist0_FR_SLW                    (* (reg8 *) Dist0_FR__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Dist0_FR_PRTDSI__CAPS_SEL       (* (reg8 *) Dist0_FR__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Dist0_FR_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Dist0_FR__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Dist0_FR_PRTDSI__OE_SEL0        (* (reg8 *) Dist0_FR__PRTDSI__OE_SEL0) 
#define Dist0_FR_PRTDSI__OE_SEL1        (* (reg8 *) Dist0_FR__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Dist0_FR_PRTDSI__OUT_SEL0       (* (reg8 *) Dist0_FR__PRTDSI__OUT_SEL0) 
#define Dist0_FR_PRTDSI__OUT_SEL1       (* (reg8 *) Dist0_FR__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Dist0_FR_PRTDSI__SYNC_OUT       (* (reg8 *) Dist0_FR__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Dist0_FR__SIO_CFG)
    #define Dist0_FR_SIO_HYST_EN        (* (reg8 *) Dist0_FR__SIO_HYST_EN)
    #define Dist0_FR_SIO_REG_HIFREQ     (* (reg8 *) Dist0_FR__SIO_REG_HIFREQ)
    #define Dist0_FR_SIO_CFG            (* (reg8 *) Dist0_FR__SIO_CFG)
    #define Dist0_FR_SIO_DIFF           (* (reg8 *) Dist0_FR__SIO_DIFF)
#endif /* (Dist0_FR__SIO_CFG) */

/* Interrupt Registers */
#if defined(Dist0_FR__INTSTAT)
    #define Dist0_FR_INTSTAT            (* (reg8 *) Dist0_FR__INTSTAT)
    #define Dist0_FR_SNAP               (* (reg8 *) Dist0_FR__SNAP)
    
	#define Dist0_FR_0_INTTYPE_REG 		(* (reg8 *) Dist0_FR__0__INTTYPE)
#endif /* (Dist0_FR__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Dist0_FR_H */


/* [] END OF FILE */
