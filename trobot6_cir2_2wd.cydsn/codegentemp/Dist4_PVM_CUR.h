/*******************************************************************************
* File Name: Dist4_PVM_CUR.h  
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

#if !defined(CY_PINS_Dist4_PVM_CUR_H) /* Pins Dist4_PVM_CUR_H */
#define CY_PINS_Dist4_PVM_CUR_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Dist4_PVM_CUR_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Dist4_PVM_CUR__PORT == 15 && ((Dist4_PVM_CUR__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Dist4_PVM_CUR_Write(uint8 value);
void    Dist4_PVM_CUR_SetDriveMode(uint8 mode);
uint8   Dist4_PVM_CUR_ReadDataReg(void);
uint8   Dist4_PVM_CUR_Read(void);
void    Dist4_PVM_CUR_SetInterruptMode(uint16 position, uint16 mode);
uint8   Dist4_PVM_CUR_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Dist4_PVM_CUR_SetDriveMode() function.
     *  @{
     */
        #define Dist4_PVM_CUR_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Dist4_PVM_CUR_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Dist4_PVM_CUR_DM_RES_UP          PIN_DM_RES_UP
        #define Dist4_PVM_CUR_DM_RES_DWN         PIN_DM_RES_DWN
        #define Dist4_PVM_CUR_DM_OD_LO           PIN_DM_OD_LO
        #define Dist4_PVM_CUR_DM_OD_HI           PIN_DM_OD_HI
        #define Dist4_PVM_CUR_DM_STRONG          PIN_DM_STRONG
        #define Dist4_PVM_CUR_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Dist4_PVM_CUR_MASK               Dist4_PVM_CUR__MASK
#define Dist4_PVM_CUR_SHIFT              Dist4_PVM_CUR__SHIFT
#define Dist4_PVM_CUR_WIDTH              1u

/* Interrupt constants */
#if defined(Dist4_PVM_CUR__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Dist4_PVM_CUR_SetInterruptMode() function.
     *  @{
     */
        #define Dist4_PVM_CUR_INTR_NONE      (uint16)(0x0000u)
        #define Dist4_PVM_CUR_INTR_RISING    (uint16)(0x0001u)
        #define Dist4_PVM_CUR_INTR_FALLING   (uint16)(0x0002u)
        #define Dist4_PVM_CUR_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Dist4_PVM_CUR_INTR_MASK      (0x01u) 
#endif /* (Dist4_PVM_CUR__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Dist4_PVM_CUR_PS                     (* (reg8 *) Dist4_PVM_CUR__PS)
/* Data Register */
#define Dist4_PVM_CUR_DR                     (* (reg8 *) Dist4_PVM_CUR__DR)
/* Port Number */
#define Dist4_PVM_CUR_PRT_NUM                (* (reg8 *) Dist4_PVM_CUR__PRT) 
/* Connect to Analog Globals */                                                  
#define Dist4_PVM_CUR_AG                     (* (reg8 *) Dist4_PVM_CUR__AG)                       
/* Analog MUX bux enable */
#define Dist4_PVM_CUR_AMUX                   (* (reg8 *) Dist4_PVM_CUR__AMUX) 
/* Bidirectional Enable */                                                        
#define Dist4_PVM_CUR_BIE                    (* (reg8 *) Dist4_PVM_CUR__BIE)
/* Bit-mask for Aliased Register Access */
#define Dist4_PVM_CUR_BIT_MASK               (* (reg8 *) Dist4_PVM_CUR__BIT_MASK)
/* Bypass Enable */
#define Dist4_PVM_CUR_BYP                    (* (reg8 *) Dist4_PVM_CUR__BYP)
/* Port wide control signals */                                                   
#define Dist4_PVM_CUR_CTL                    (* (reg8 *) Dist4_PVM_CUR__CTL)
/* Drive Modes */
#define Dist4_PVM_CUR_DM0                    (* (reg8 *) Dist4_PVM_CUR__DM0) 
#define Dist4_PVM_CUR_DM1                    (* (reg8 *) Dist4_PVM_CUR__DM1)
#define Dist4_PVM_CUR_DM2                    (* (reg8 *) Dist4_PVM_CUR__DM2) 
/* Input Buffer Disable Override */
#define Dist4_PVM_CUR_INP_DIS                (* (reg8 *) Dist4_PVM_CUR__INP_DIS)
/* LCD Common or Segment Drive */
#define Dist4_PVM_CUR_LCD_COM_SEG            (* (reg8 *) Dist4_PVM_CUR__LCD_COM_SEG)
/* Enable Segment LCD */
#define Dist4_PVM_CUR_LCD_EN                 (* (reg8 *) Dist4_PVM_CUR__LCD_EN)
/* Slew Rate Control */
#define Dist4_PVM_CUR_SLW                    (* (reg8 *) Dist4_PVM_CUR__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Dist4_PVM_CUR_PRTDSI__CAPS_SEL       (* (reg8 *) Dist4_PVM_CUR__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Dist4_PVM_CUR_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Dist4_PVM_CUR__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Dist4_PVM_CUR_PRTDSI__OE_SEL0        (* (reg8 *) Dist4_PVM_CUR__PRTDSI__OE_SEL0) 
#define Dist4_PVM_CUR_PRTDSI__OE_SEL1        (* (reg8 *) Dist4_PVM_CUR__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Dist4_PVM_CUR_PRTDSI__OUT_SEL0       (* (reg8 *) Dist4_PVM_CUR__PRTDSI__OUT_SEL0) 
#define Dist4_PVM_CUR_PRTDSI__OUT_SEL1       (* (reg8 *) Dist4_PVM_CUR__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Dist4_PVM_CUR_PRTDSI__SYNC_OUT       (* (reg8 *) Dist4_PVM_CUR__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Dist4_PVM_CUR__SIO_CFG)
    #define Dist4_PVM_CUR_SIO_HYST_EN        (* (reg8 *) Dist4_PVM_CUR__SIO_HYST_EN)
    #define Dist4_PVM_CUR_SIO_REG_HIFREQ     (* (reg8 *) Dist4_PVM_CUR__SIO_REG_HIFREQ)
    #define Dist4_PVM_CUR_SIO_CFG            (* (reg8 *) Dist4_PVM_CUR__SIO_CFG)
    #define Dist4_PVM_CUR_SIO_DIFF           (* (reg8 *) Dist4_PVM_CUR__SIO_DIFF)
#endif /* (Dist4_PVM_CUR__SIO_CFG) */

/* Interrupt Registers */
#if defined(Dist4_PVM_CUR__INTSTAT)
    #define Dist4_PVM_CUR_INTSTAT            (* (reg8 *) Dist4_PVM_CUR__INTSTAT)
    #define Dist4_PVM_CUR_SNAP               (* (reg8 *) Dist4_PVM_CUR__SNAP)
    
	#define Dist4_PVM_CUR_0_INTTYPE_REG 		(* (reg8 *) Dist4_PVM_CUR__0__INTTYPE)
#endif /* (Dist4_PVM_CUR__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Dist4_PVM_CUR_H */


/* [] END OF FILE */
