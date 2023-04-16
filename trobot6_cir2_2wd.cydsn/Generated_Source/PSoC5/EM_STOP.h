/*******************************************************************************
* File Name: EM_STOP.h  
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

#if !defined(CY_PINS_EM_STOP_H) /* Pins EM_STOP_H */
#define CY_PINS_EM_STOP_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "EM_STOP_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 EM_STOP__PORT == 15 && ((EM_STOP__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    EM_STOP_Write(uint8 value);
void    EM_STOP_SetDriveMode(uint8 mode);
uint8   EM_STOP_ReadDataReg(void);
uint8   EM_STOP_Read(void);
void    EM_STOP_SetInterruptMode(uint16 position, uint16 mode);
uint8   EM_STOP_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the EM_STOP_SetDriveMode() function.
     *  @{
     */
        #define EM_STOP_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define EM_STOP_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define EM_STOP_DM_RES_UP          PIN_DM_RES_UP
        #define EM_STOP_DM_RES_DWN         PIN_DM_RES_DWN
        #define EM_STOP_DM_OD_LO           PIN_DM_OD_LO
        #define EM_STOP_DM_OD_HI           PIN_DM_OD_HI
        #define EM_STOP_DM_STRONG          PIN_DM_STRONG
        #define EM_STOP_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define EM_STOP_MASK               EM_STOP__MASK
#define EM_STOP_SHIFT              EM_STOP__SHIFT
#define EM_STOP_WIDTH              1u

/* Interrupt constants */
#if defined(EM_STOP__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in EM_STOP_SetInterruptMode() function.
     *  @{
     */
        #define EM_STOP_INTR_NONE      (uint16)(0x0000u)
        #define EM_STOP_INTR_RISING    (uint16)(0x0001u)
        #define EM_STOP_INTR_FALLING   (uint16)(0x0002u)
        #define EM_STOP_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define EM_STOP_INTR_MASK      (0x01u) 
#endif /* (EM_STOP__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define EM_STOP_PS                     (* (reg8 *) EM_STOP__PS)
/* Data Register */
#define EM_STOP_DR                     (* (reg8 *) EM_STOP__DR)
/* Port Number */
#define EM_STOP_PRT_NUM                (* (reg8 *) EM_STOP__PRT) 
/* Connect to Analog Globals */                                                  
#define EM_STOP_AG                     (* (reg8 *) EM_STOP__AG)                       
/* Analog MUX bux enable */
#define EM_STOP_AMUX                   (* (reg8 *) EM_STOP__AMUX) 
/* Bidirectional Enable */                                                        
#define EM_STOP_BIE                    (* (reg8 *) EM_STOP__BIE)
/* Bit-mask for Aliased Register Access */
#define EM_STOP_BIT_MASK               (* (reg8 *) EM_STOP__BIT_MASK)
/* Bypass Enable */
#define EM_STOP_BYP                    (* (reg8 *) EM_STOP__BYP)
/* Port wide control signals */                                                   
#define EM_STOP_CTL                    (* (reg8 *) EM_STOP__CTL)
/* Drive Modes */
#define EM_STOP_DM0                    (* (reg8 *) EM_STOP__DM0) 
#define EM_STOP_DM1                    (* (reg8 *) EM_STOP__DM1)
#define EM_STOP_DM2                    (* (reg8 *) EM_STOP__DM2) 
/* Input Buffer Disable Override */
#define EM_STOP_INP_DIS                (* (reg8 *) EM_STOP__INP_DIS)
/* LCD Common or Segment Drive */
#define EM_STOP_LCD_COM_SEG            (* (reg8 *) EM_STOP__LCD_COM_SEG)
/* Enable Segment LCD */
#define EM_STOP_LCD_EN                 (* (reg8 *) EM_STOP__LCD_EN)
/* Slew Rate Control */
#define EM_STOP_SLW                    (* (reg8 *) EM_STOP__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define EM_STOP_PRTDSI__CAPS_SEL       (* (reg8 *) EM_STOP__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define EM_STOP_PRTDSI__DBL_SYNC_IN    (* (reg8 *) EM_STOP__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define EM_STOP_PRTDSI__OE_SEL0        (* (reg8 *) EM_STOP__PRTDSI__OE_SEL0) 
#define EM_STOP_PRTDSI__OE_SEL1        (* (reg8 *) EM_STOP__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define EM_STOP_PRTDSI__OUT_SEL0       (* (reg8 *) EM_STOP__PRTDSI__OUT_SEL0) 
#define EM_STOP_PRTDSI__OUT_SEL1       (* (reg8 *) EM_STOP__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define EM_STOP_PRTDSI__SYNC_OUT       (* (reg8 *) EM_STOP__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(EM_STOP__SIO_CFG)
    #define EM_STOP_SIO_HYST_EN        (* (reg8 *) EM_STOP__SIO_HYST_EN)
    #define EM_STOP_SIO_REG_HIFREQ     (* (reg8 *) EM_STOP__SIO_REG_HIFREQ)
    #define EM_STOP_SIO_CFG            (* (reg8 *) EM_STOP__SIO_CFG)
    #define EM_STOP_SIO_DIFF           (* (reg8 *) EM_STOP__SIO_DIFF)
#endif /* (EM_STOP__SIO_CFG) */

/* Interrupt Registers */
#if defined(EM_STOP__INTSTAT)
    #define EM_STOP_INTSTAT            (* (reg8 *) EM_STOP__INTSTAT)
    #define EM_STOP_SNAP               (* (reg8 *) EM_STOP__SNAP)
    
	#define EM_STOP_0_INTTYPE_REG 		(* (reg8 *) EM_STOP__0__INTTYPE)
#endif /* (EM_STOP__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_EM_STOP_H */


/* [] END OF FILE */
