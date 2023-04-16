/*******************************************************************************
* File Name: PWMOUT0.h  
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

#if !defined(CY_PINS_PWMOUT0_H) /* Pins PWMOUT0_H */
#define CY_PINS_PWMOUT0_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PWMOUT0_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PWMOUT0__PORT == 15 && ((PWMOUT0__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    PWMOUT0_Write(uint8 value);
void    PWMOUT0_SetDriveMode(uint8 mode);
uint8   PWMOUT0_ReadDataReg(void);
uint8   PWMOUT0_Read(void);
void    PWMOUT0_SetInterruptMode(uint16 position, uint16 mode);
uint8   PWMOUT0_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the PWMOUT0_SetDriveMode() function.
     *  @{
     */
        #define PWMOUT0_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define PWMOUT0_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define PWMOUT0_DM_RES_UP          PIN_DM_RES_UP
        #define PWMOUT0_DM_RES_DWN         PIN_DM_RES_DWN
        #define PWMOUT0_DM_OD_LO           PIN_DM_OD_LO
        #define PWMOUT0_DM_OD_HI           PIN_DM_OD_HI
        #define PWMOUT0_DM_STRONG          PIN_DM_STRONG
        #define PWMOUT0_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define PWMOUT0_MASK               PWMOUT0__MASK
#define PWMOUT0_SHIFT              PWMOUT0__SHIFT
#define PWMOUT0_WIDTH              1u

/* Interrupt constants */
#if defined(PWMOUT0__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PWMOUT0_SetInterruptMode() function.
     *  @{
     */
        #define PWMOUT0_INTR_NONE      (uint16)(0x0000u)
        #define PWMOUT0_INTR_RISING    (uint16)(0x0001u)
        #define PWMOUT0_INTR_FALLING   (uint16)(0x0002u)
        #define PWMOUT0_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define PWMOUT0_INTR_MASK      (0x01u) 
#endif /* (PWMOUT0__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PWMOUT0_PS                     (* (reg8 *) PWMOUT0__PS)
/* Data Register */
#define PWMOUT0_DR                     (* (reg8 *) PWMOUT0__DR)
/* Port Number */
#define PWMOUT0_PRT_NUM                (* (reg8 *) PWMOUT0__PRT) 
/* Connect to Analog Globals */                                                  
#define PWMOUT0_AG                     (* (reg8 *) PWMOUT0__AG)                       
/* Analog MUX bux enable */
#define PWMOUT0_AMUX                   (* (reg8 *) PWMOUT0__AMUX) 
/* Bidirectional Enable */                                                        
#define PWMOUT0_BIE                    (* (reg8 *) PWMOUT0__BIE)
/* Bit-mask for Aliased Register Access */
#define PWMOUT0_BIT_MASK               (* (reg8 *) PWMOUT0__BIT_MASK)
/* Bypass Enable */
#define PWMOUT0_BYP                    (* (reg8 *) PWMOUT0__BYP)
/* Port wide control signals */                                                   
#define PWMOUT0_CTL                    (* (reg8 *) PWMOUT0__CTL)
/* Drive Modes */
#define PWMOUT0_DM0                    (* (reg8 *) PWMOUT0__DM0) 
#define PWMOUT0_DM1                    (* (reg8 *) PWMOUT0__DM1)
#define PWMOUT0_DM2                    (* (reg8 *) PWMOUT0__DM2) 
/* Input Buffer Disable Override */
#define PWMOUT0_INP_DIS                (* (reg8 *) PWMOUT0__INP_DIS)
/* LCD Common or Segment Drive */
#define PWMOUT0_LCD_COM_SEG            (* (reg8 *) PWMOUT0__LCD_COM_SEG)
/* Enable Segment LCD */
#define PWMOUT0_LCD_EN                 (* (reg8 *) PWMOUT0__LCD_EN)
/* Slew Rate Control */
#define PWMOUT0_SLW                    (* (reg8 *) PWMOUT0__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PWMOUT0_PRTDSI__CAPS_SEL       (* (reg8 *) PWMOUT0__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PWMOUT0_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PWMOUT0__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PWMOUT0_PRTDSI__OE_SEL0        (* (reg8 *) PWMOUT0__PRTDSI__OE_SEL0) 
#define PWMOUT0_PRTDSI__OE_SEL1        (* (reg8 *) PWMOUT0__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PWMOUT0_PRTDSI__OUT_SEL0       (* (reg8 *) PWMOUT0__PRTDSI__OUT_SEL0) 
#define PWMOUT0_PRTDSI__OUT_SEL1       (* (reg8 *) PWMOUT0__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PWMOUT0_PRTDSI__SYNC_OUT       (* (reg8 *) PWMOUT0__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(PWMOUT0__SIO_CFG)
    #define PWMOUT0_SIO_HYST_EN        (* (reg8 *) PWMOUT0__SIO_HYST_EN)
    #define PWMOUT0_SIO_REG_HIFREQ     (* (reg8 *) PWMOUT0__SIO_REG_HIFREQ)
    #define PWMOUT0_SIO_CFG            (* (reg8 *) PWMOUT0__SIO_CFG)
    #define PWMOUT0_SIO_DIFF           (* (reg8 *) PWMOUT0__SIO_DIFF)
#endif /* (PWMOUT0__SIO_CFG) */

/* Interrupt Registers */
#if defined(PWMOUT0__INTSTAT)
    #define PWMOUT0_INTSTAT            (* (reg8 *) PWMOUT0__INTSTAT)
    #define PWMOUT0_SNAP               (* (reg8 *) PWMOUT0__SNAP)
    
	#define PWMOUT0_0_INTTYPE_REG 		(* (reg8 *) PWMOUT0__0__INTTYPE)
#endif /* (PWMOUT0__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PWMOUT0_H */


/* [] END OF FILE */
