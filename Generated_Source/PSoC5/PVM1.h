/*******************************************************************************
* File Name: PVM1.h  
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

#if !defined(CY_PINS_PVM1_H) /* Pins PVM1_H */
#define CY_PINS_PVM1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PVM1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PVM1__PORT == 15 && ((PVM1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    PVM1_Write(uint8 value);
void    PVM1_SetDriveMode(uint8 mode);
uint8   PVM1_ReadDataReg(void);
uint8   PVM1_Read(void);
void    PVM1_SetInterruptMode(uint16 position, uint16 mode);
uint8   PVM1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the PVM1_SetDriveMode() function.
     *  @{
     */
        #define PVM1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define PVM1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define PVM1_DM_RES_UP          PIN_DM_RES_UP
        #define PVM1_DM_RES_DWN         PIN_DM_RES_DWN
        #define PVM1_DM_OD_LO           PIN_DM_OD_LO
        #define PVM1_DM_OD_HI           PIN_DM_OD_HI
        #define PVM1_DM_STRONG          PIN_DM_STRONG
        #define PVM1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define PVM1_MASK               PVM1__MASK
#define PVM1_SHIFT              PVM1__SHIFT
#define PVM1_WIDTH              1u

/* Interrupt constants */
#if defined(PVM1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PVM1_SetInterruptMode() function.
     *  @{
     */
        #define PVM1_INTR_NONE      (uint16)(0x0000u)
        #define PVM1_INTR_RISING    (uint16)(0x0001u)
        #define PVM1_INTR_FALLING   (uint16)(0x0002u)
        #define PVM1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define PVM1_INTR_MASK      (0x01u) 
#endif /* (PVM1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PVM1_PS                     (* (reg8 *) PVM1__PS)
/* Data Register */
#define PVM1_DR                     (* (reg8 *) PVM1__DR)
/* Port Number */
#define PVM1_PRT_NUM                (* (reg8 *) PVM1__PRT) 
/* Connect to Analog Globals */                                                  
#define PVM1_AG                     (* (reg8 *) PVM1__AG)                       
/* Analog MUX bux enable */
#define PVM1_AMUX                   (* (reg8 *) PVM1__AMUX) 
/* Bidirectional Enable */                                                        
#define PVM1_BIE                    (* (reg8 *) PVM1__BIE)
/* Bit-mask for Aliased Register Access */
#define PVM1_BIT_MASK               (* (reg8 *) PVM1__BIT_MASK)
/* Bypass Enable */
#define PVM1_BYP                    (* (reg8 *) PVM1__BYP)
/* Port wide control signals */                                                   
#define PVM1_CTL                    (* (reg8 *) PVM1__CTL)
/* Drive Modes */
#define PVM1_DM0                    (* (reg8 *) PVM1__DM0) 
#define PVM1_DM1                    (* (reg8 *) PVM1__DM1)
#define PVM1_DM2                    (* (reg8 *) PVM1__DM2) 
/* Input Buffer Disable Override */
#define PVM1_INP_DIS                (* (reg8 *) PVM1__INP_DIS)
/* LCD Common or Segment Drive */
#define PVM1_LCD_COM_SEG            (* (reg8 *) PVM1__LCD_COM_SEG)
/* Enable Segment LCD */
#define PVM1_LCD_EN                 (* (reg8 *) PVM1__LCD_EN)
/* Slew Rate Control */
#define PVM1_SLW                    (* (reg8 *) PVM1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PVM1_PRTDSI__CAPS_SEL       (* (reg8 *) PVM1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PVM1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PVM1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PVM1_PRTDSI__OE_SEL0        (* (reg8 *) PVM1__PRTDSI__OE_SEL0) 
#define PVM1_PRTDSI__OE_SEL1        (* (reg8 *) PVM1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PVM1_PRTDSI__OUT_SEL0       (* (reg8 *) PVM1__PRTDSI__OUT_SEL0) 
#define PVM1_PRTDSI__OUT_SEL1       (* (reg8 *) PVM1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PVM1_PRTDSI__SYNC_OUT       (* (reg8 *) PVM1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(PVM1__SIO_CFG)
    #define PVM1_SIO_HYST_EN        (* (reg8 *) PVM1__SIO_HYST_EN)
    #define PVM1_SIO_REG_HIFREQ     (* (reg8 *) PVM1__SIO_REG_HIFREQ)
    #define PVM1_SIO_CFG            (* (reg8 *) PVM1__SIO_CFG)
    #define PVM1_SIO_DIFF           (* (reg8 *) PVM1__SIO_DIFF)
#endif /* (PVM1__SIO_CFG) */

/* Interrupt Registers */
#if defined(PVM1__INTSTAT)
    #define PVM1_INTSTAT            (* (reg8 *) PVM1__INTSTAT)
    #define PVM1_SNAP               (* (reg8 *) PVM1__SNAP)
    
	#define PVM1_0_INTTYPE_REG 		(* (reg8 *) PVM1__0__INTTYPE)
#endif /* (PVM1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PVM1_H */


/* [] END OF FILE */
