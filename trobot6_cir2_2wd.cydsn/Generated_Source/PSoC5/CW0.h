/*******************************************************************************
* File Name: CW0.h  
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

#if !defined(CY_PINS_CW0_H) /* Pins CW0_H */
#define CY_PINS_CW0_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "CW0_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 CW0__PORT == 15 && ((CW0__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    CW0_Write(uint8 value);
void    CW0_SetDriveMode(uint8 mode);
uint8   CW0_ReadDataReg(void);
uint8   CW0_Read(void);
void    CW0_SetInterruptMode(uint16 position, uint16 mode);
uint8   CW0_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the CW0_SetDriveMode() function.
     *  @{
     */
        #define CW0_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define CW0_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define CW0_DM_RES_UP          PIN_DM_RES_UP
        #define CW0_DM_RES_DWN         PIN_DM_RES_DWN
        #define CW0_DM_OD_LO           PIN_DM_OD_LO
        #define CW0_DM_OD_HI           PIN_DM_OD_HI
        #define CW0_DM_STRONG          PIN_DM_STRONG
        #define CW0_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define CW0_MASK               CW0__MASK
#define CW0_SHIFT              CW0__SHIFT
#define CW0_WIDTH              1u

/* Interrupt constants */
#if defined(CW0__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in CW0_SetInterruptMode() function.
     *  @{
     */
        #define CW0_INTR_NONE      (uint16)(0x0000u)
        #define CW0_INTR_RISING    (uint16)(0x0001u)
        #define CW0_INTR_FALLING   (uint16)(0x0002u)
        #define CW0_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define CW0_INTR_MASK      (0x01u) 
#endif /* (CW0__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define CW0_PS                     (* (reg8 *) CW0__PS)
/* Data Register */
#define CW0_DR                     (* (reg8 *) CW0__DR)
/* Port Number */
#define CW0_PRT_NUM                (* (reg8 *) CW0__PRT) 
/* Connect to Analog Globals */                                                  
#define CW0_AG                     (* (reg8 *) CW0__AG)                       
/* Analog MUX bux enable */
#define CW0_AMUX                   (* (reg8 *) CW0__AMUX) 
/* Bidirectional Enable */                                                        
#define CW0_BIE                    (* (reg8 *) CW0__BIE)
/* Bit-mask for Aliased Register Access */
#define CW0_BIT_MASK               (* (reg8 *) CW0__BIT_MASK)
/* Bypass Enable */
#define CW0_BYP                    (* (reg8 *) CW0__BYP)
/* Port wide control signals */                                                   
#define CW0_CTL                    (* (reg8 *) CW0__CTL)
/* Drive Modes */
#define CW0_DM0                    (* (reg8 *) CW0__DM0) 
#define CW0_DM1                    (* (reg8 *) CW0__DM1)
#define CW0_DM2                    (* (reg8 *) CW0__DM2) 
/* Input Buffer Disable Override */
#define CW0_INP_DIS                (* (reg8 *) CW0__INP_DIS)
/* LCD Common or Segment Drive */
#define CW0_LCD_COM_SEG            (* (reg8 *) CW0__LCD_COM_SEG)
/* Enable Segment LCD */
#define CW0_LCD_EN                 (* (reg8 *) CW0__LCD_EN)
/* Slew Rate Control */
#define CW0_SLW                    (* (reg8 *) CW0__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define CW0_PRTDSI__CAPS_SEL       (* (reg8 *) CW0__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define CW0_PRTDSI__DBL_SYNC_IN    (* (reg8 *) CW0__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define CW0_PRTDSI__OE_SEL0        (* (reg8 *) CW0__PRTDSI__OE_SEL0) 
#define CW0_PRTDSI__OE_SEL1        (* (reg8 *) CW0__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define CW0_PRTDSI__OUT_SEL0       (* (reg8 *) CW0__PRTDSI__OUT_SEL0) 
#define CW0_PRTDSI__OUT_SEL1       (* (reg8 *) CW0__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define CW0_PRTDSI__SYNC_OUT       (* (reg8 *) CW0__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(CW0__SIO_CFG)
    #define CW0_SIO_HYST_EN        (* (reg8 *) CW0__SIO_HYST_EN)
    #define CW0_SIO_REG_HIFREQ     (* (reg8 *) CW0__SIO_REG_HIFREQ)
    #define CW0_SIO_CFG            (* (reg8 *) CW0__SIO_CFG)
    #define CW0_SIO_DIFF           (* (reg8 *) CW0__SIO_DIFF)
#endif /* (CW0__SIO_CFG) */

/* Interrupt Registers */
#if defined(CW0__INTSTAT)
    #define CW0_INTSTAT            (* (reg8 *) CW0__INTSTAT)
    #define CW0_SNAP               (* (reg8 *) CW0__SNAP)
    
	#define CW0_0_INTTYPE_REG 		(* (reg8 *) CW0__0__INTTYPE)
#endif /* (CW0__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_CW0_H */


/* [] END OF FILE */
