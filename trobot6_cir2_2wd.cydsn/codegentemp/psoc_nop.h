/*******************************************************************************
* File Name: psoc_nop.h  
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

#if !defined(CY_PINS_psoc_nop_H) /* Pins psoc_nop_H */
#define CY_PINS_psoc_nop_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "psoc_nop_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 psoc_nop__PORT == 15 && ((psoc_nop__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    psoc_nop_Write(uint8 value);
void    psoc_nop_SetDriveMode(uint8 mode);
uint8   psoc_nop_ReadDataReg(void);
uint8   psoc_nop_Read(void);
void    psoc_nop_SetInterruptMode(uint16 position, uint16 mode);
uint8   psoc_nop_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the psoc_nop_SetDriveMode() function.
     *  @{
     */
        #define psoc_nop_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define psoc_nop_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define psoc_nop_DM_RES_UP          PIN_DM_RES_UP
        #define psoc_nop_DM_RES_DWN         PIN_DM_RES_DWN
        #define psoc_nop_DM_OD_LO           PIN_DM_OD_LO
        #define psoc_nop_DM_OD_HI           PIN_DM_OD_HI
        #define psoc_nop_DM_STRONG          PIN_DM_STRONG
        #define psoc_nop_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define psoc_nop_MASK               psoc_nop__MASK
#define psoc_nop_SHIFT              psoc_nop__SHIFT
#define psoc_nop_WIDTH              1u

/* Interrupt constants */
#if defined(psoc_nop__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in psoc_nop_SetInterruptMode() function.
     *  @{
     */
        #define psoc_nop_INTR_NONE      (uint16)(0x0000u)
        #define psoc_nop_INTR_RISING    (uint16)(0x0001u)
        #define psoc_nop_INTR_FALLING   (uint16)(0x0002u)
        #define psoc_nop_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define psoc_nop_INTR_MASK      (0x01u) 
#endif /* (psoc_nop__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define psoc_nop_PS                     (* (reg8 *) psoc_nop__PS)
/* Data Register */
#define psoc_nop_DR                     (* (reg8 *) psoc_nop__DR)
/* Port Number */
#define psoc_nop_PRT_NUM                (* (reg8 *) psoc_nop__PRT) 
/* Connect to Analog Globals */                                                  
#define psoc_nop_AG                     (* (reg8 *) psoc_nop__AG)                       
/* Analog MUX bux enable */
#define psoc_nop_AMUX                   (* (reg8 *) psoc_nop__AMUX) 
/* Bidirectional Enable */                                                        
#define psoc_nop_BIE                    (* (reg8 *) psoc_nop__BIE)
/* Bit-mask for Aliased Register Access */
#define psoc_nop_BIT_MASK               (* (reg8 *) psoc_nop__BIT_MASK)
/* Bypass Enable */
#define psoc_nop_BYP                    (* (reg8 *) psoc_nop__BYP)
/* Port wide control signals */                                                   
#define psoc_nop_CTL                    (* (reg8 *) psoc_nop__CTL)
/* Drive Modes */
#define psoc_nop_DM0                    (* (reg8 *) psoc_nop__DM0) 
#define psoc_nop_DM1                    (* (reg8 *) psoc_nop__DM1)
#define psoc_nop_DM2                    (* (reg8 *) psoc_nop__DM2) 
/* Input Buffer Disable Override */
#define psoc_nop_INP_DIS                (* (reg8 *) psoc_nop__INP_DIS)
/* LCD Common or Segment Drive */
#define psoc_nop_LCD_COM_SEG            (* (reg8 *) psoc_nop__LCD_COM_SEG)
/* Enable Segment LCD */
#define psoc_nop_LCD_EN                 (* (reg8 *) psoc_nop__LCD_EN)
/* Slew Rate Control */
#define psoc_nop_SLW                    (* (reg8 *) psoc_nop__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define psoc_nop_PRTDSI__CAPS_SEL       (* (reg8 *) psoc_nop__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define psoc_nop_PRTDSI__DBL_SYNC_IN    (* (reg8 *) psoc_nop__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define psoc_nop_PRTDSI__OE_SEL0        (* (reg8 *) psoc_nop__PRTDSI__OE_SEL0) 
#define psoc_nop_PRTDSI__OE_SEL1        (* (reg8 *) psoc_nop__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define psoc_nop_PRTDSI__OUT_SEL0       (* (reg8 *) psoc_nop__PRTDSI__OUT_SEL0) 
#define psoc_nop_PRTDSI__OUT_SEL1       (* (reg8 *) psoc_nop__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define psoc_nop_PRTDSI__SYNC_OUT       (* (reg8 *) psoc_nop__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(psoc_nop__SIO_CFG)
    #define psoc_nop_SIO_HYST_EN        (* (reg8 *) psoc_nop__SIO_HYST_EN)
    #define psoc_nop_SIO_REG_HIFREQ     (* (reg8 *) psoc_nop__SIO_REG_HIFREQ)
    #define psoc_nop_SIO_CFG            (* (reg8 *) psoc_nop__SIO_CFG)
    #define psoc_nop_SIO_DIFF           (* (reg8 *) psoc_nop__SIO_DIFF)
#endif /* (psoc_nop__SIO_CFG) */

/* Interrupt Registers */
#if defined(psoc_nop__INTSTAT)
    #define psoc_nop_INTSTAT            (* (reg8 *) psoc_nop__INTSTAT)
    #define psoc_nop_SNAP               (* (reg8 *) psoc_nop__SNAP)
    
	#define psoc_nop_0_INTTYPE_REG 		(* (reg8 *) psoc_nop__0__INTTYPE)
#endif /* (psoc_nop__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_psoc_nop_H */


/* [] END OF FILE */
