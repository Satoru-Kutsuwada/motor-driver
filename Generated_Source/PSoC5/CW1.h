/*******************************************************************************
* File Name: CW1.h  
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

#if !defined(CY_PINS_CW1_H) /* Pins CW1_H */
#define CY_PINS_CW1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "CW1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 CW1__PORT == 15 && ((CW1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    CW1_Write(uint8 value);
void    CW1_SetDriveMode(uint8 mode);
uint8   CW1_ReadDataReg(void);
uint8   CW1_Read(void);
void    CW1_SetInterruptMode(uint16 position, uint16 mode);
uint8   CW1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the CW1_SetDriveMode() function.
     *  @{
     */
        #define CW1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define CW1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define CW1_DM_RES_UP          PIN_DM_RES_UP
        #define CW1_DM_RES_DWN         PIN_DM_RES_DWN
        #define CW1_DM_OD_LO           PIN_DM_OD_LO
        #define CW1_DM_OD_HI           PIN_DM_OD_HI
        #define CW1_DM_STRONG          PIN_DM_STRONG
        #define CW1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define CW1_MASK               CW1__MASK
#define CW1_SHIFT              CW1__SHIFT
#define CW1_WIDTH              1u

/* Interrupt constants */
#if defined(CW1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in CW1_SetInterruptMode() function.
     *  @{
     */
        #define CW1_INTR_NONE      (uint16)(0x0000u)
        #define CW1_INTR_RISING    (uint16)(0x0001u)
        #define CW1_INTR_FALLING   (uint16)(0x0002u)
        #define CW1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define CW1_INTR_MASK      (0x01u) 
#endif /* (CW1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define CW1_PS                     (* (reg8 *) CW1__PS)
/* Data Register */
#define CW1_DR                     (* (reg8 *) CW1__DR)
/* Port Number */
#define CW1_PRT_NUM                (* (reg8 *) CW1__PRT) 
/* Connect to Analog Globals */                                                  
#define CW1_AG                     (* (reg8 *) CW1__AG)                       
/* Analog MUX bux enable */
#define CW1_AMUX                   (* (reg8 *) CW1__AMUX) 
/* Bidirectional Enable */                                                        
#define CW1_BIE                    (* (reg8 *) CW1__BIE)
/* Bit-mask for Aliased Register Access */
#define CW1_BIT_MASK               (* (reg8 *) CW1__BIT_MASK)
/* Bypass Enable */
#define CW1_BYP                    (* (reg8 *) CW1__BYP)
/* Port wide control signals */                                                   
#define CW1_CTL                    (* (reg8 *) CW1__CTL)
/* Drive Modes */
#define CW1_DM0                    (* (reg8 *) CW1__DM0) 
#define CW1_DM1                    (* (reg8 *) CW1__DM1)
#define CW1_DM2                    (* (reg8 *) CW1__DM2) 
/* Input Buffer Disable Override */
#define CW1_INP_DIS                (* (reg8 *) CW1__INP_DIS)
/* LCD Common or Segment Drive */
#define CW1_LCD_COM_SEG            (* (reg8 *) CW1__LCD_COM_SEG)
/* Enable Segment LCD */
#define CW1_LCD_EN                 (* (reg8 *) CW1__LCD_EN)
/* Slew Rate Control */
#define CW1_SLW                    (* (reg8 *) CW1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define CW1_PRTDSI__CAPS_SEL       (* (reg8 *) CW1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define CW1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) CW1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define CW1_PRTDSI__OE_SEL0        (* (reg8 *) CW1__PRTDSI__OE_SEL0) 
#define CW1_PRTDSI__OE_SEL1        (* (reg8 *) CW1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define CW1_PRTDSI__OUT_SEL0       (* (reg8 *) CW1__PRTDSI__OUT_SEL0) 
#define CW1_PRTDSI__OUT_SEL1       (* (reg8 *) CW1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define CW1_PRTDSI__SYNC_OUT       (* (reg8 *) CW1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(CW1__SIO_CFG)
    #define CW1_SIO_HYST_EN        (* (reg8 *) CW1__SIO_HYST_EN)
    #define CW1_SIO_REG_HIFREQ     (* (reg8 *) CW1__SIO_REG_HIFREQ)
    #define CW1_SIO_CFG            (* (reg8 *) CW1__SIO_CFG)
    #define CW1_SIO_DIFF           (* (reg8 *) CW1__SIO_DIFF)
#endif /* (CW1__SIO_CFG) */

/* Interrupt Registers */
#if defined(CW1__INTSTAT)
    #define CW1_INTSTAT            (* (reg8 *) CW1__INTSTAT)
    #define CW1_SNAP               (* (reg8 *) CW1__SNAP)
    
	#define CW1_0_INTTYPE_REG 		(* (reg8 *) CW1__0__INTTYPE)
#endif /* (CW1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_CW1_H */


/* [] END OF FILE */
