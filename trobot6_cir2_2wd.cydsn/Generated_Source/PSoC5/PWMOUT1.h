/*******************************************************************************
* File Name: PWMOUT1.h  
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

#if !defined(CY_PINS_PWMOUT1_H) /* Pins PWMOUT1_H */
#define CY_PINS_PWMOUT1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PWMOUT1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PWMOUT1__PORT == 15 && ((PWMOUT1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    PWMOUT1_Write(uint8 value);
void    PWMOUT1_SetDriveMode(uint8 mode);
uint8   PWMOUT1_ReadDataReg(void);
uint8   PWMOUT1_Read(void);
void    PWMOUT1_SetInterruptMode(uint16 position, uint16 mode);
uint8   PWMOUT1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the PWMOUT1_SetDriveMode() function.
     *  @{
     */
        #define PWMOUT1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define PWMOUT1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define PWMOUT1_DM_RES_UP          PIN_DM_RES_UP
        #define PWMOUT1_DM_RES_DWN         PIN_DM_RES_DWN
        #define PWMOUT1_DM_OD_LO           PIN_DM_OD_LO
        #define PWMOUT1_DM_OD_HI           PIN_DM_OD_HI
        #define PWMOUT1_DM_STRONG          PIN_DM_STRONG
        #define PWMOUT1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define PWMOUT1_MASK               PWMOUT1__MASK
#define PWMOUT1_SHIFT              PWMOUT1__SHIFT
#define PWMOUT1_WIDTH              1u

/* Interrupt constants */
#if defined(PWMOUT1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PWMOUT1_SetInterruptMode() function.
     *  @{
     */
        #define PWMOUT1_INTR_NONE      (uint16)(0x0000u)
        #define PWMOUT1_INTR_RISING    (uint16)(0x0001u)
        #define PWMOUT1_INTR_FALLING   (uint16)(0x0002u)
        #define PWMOUT1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define PWMOUT1_INTR_MASK      (0x01u) 
#endif /* (PWMOUT1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PWMOUT1_PS                     (* (reg8 *) PWMOUT1__PS)
/* Data Register */
#define PWMOUT1_DR                     (* (reg8 *) PWMOUT1__DR)
/* Port Number */
#define PWMOUT1_PRT_NUM                (* (reg8 *) PWMOUT1__PRT) 
/* Connect to Analog Globals */                                                  
#define PWMOUT1_AG                     (* (reg8 *) PWMOUT1__AG)                       
/* Analog MUX bux enable */
#define PWMOUT1_AMUX                   (* (reg8 *) PWMOUT1__AMUX) 
/* Bidirectional Enable */                                                        
#define PWMOUT1_BIE                    (* (reg8 *) PWMOUT1__BIE)
/* Bit-mask for Aliased Register Access */
#define PWMOUT1_BIT_MASK               (* (reg8 *) PWMOUT1__BIT_MASK)
/* Bypass Enable */
#define PWMOUT1_BYP                    (* (reg8 *) PWMOUT1__BYP)
/* Port wide control signals */                                                   
#define PWMOUT1_CTL                    (* (reg8 *) PWMOUT1__CTL)
/* Drive Modes */
#define PWMOUT1_DM0                    (* (reg8 *) PWMOUT1__DM0) 
#define PWMOUT1_DM1                    (* (reg8 *) PWMOUT1__DM1)
#define PWMOUT1_DM2                    (* (reg8 *) PWMOUT1__DM2) 
/* Input Buffer Disable Override */
#define PWMOUT1_INP_DIS                (* (reg8 *) PWMOUT1__INP_DIS)
/* LCD Common or Segment Drive */
#define PWMOUT1_LCD_COM_SEG            (* (reg8 *) PWMOUT1__LCD_COM_SEG)
/* Enable Segment LCD */
#define PWMOUT1_LCD_EN                 (* (reg8 *) PWMOUT1__LCD_EN)
/* Slew Rate Control */
#define PWMOUT1_SLW                    (* (reg8 *) PWMOUT1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PWMOUT1_PRTDSI__CAPS_SEL       (* (reg8 *) PWMOUT1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PWMOUT1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PWMOUT1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PWMOUT1_PRTDSI__OE_SEL0        (* (reg8 *) PWMOUT1__PRTDSI__OE_SEL0) 
#define PWMOUT1_PRTDSI__OE_SEL1        (* (reg8 *) PWMOUT1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PWMOUT1_PRTDSI__OUT_SEL0       (* (reg8 *) PWMOUT1__PRTDSI__OUT_SEL0) 
#define PWMOUT1_PRTDSI__OUT_SEL1       (* (reg8 *) PWMOUT1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PWMOUT1_PRTDSI__SYNC_OUT       (* (reg8 *) PWMOUT1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(PWMOUT1__SIO_CFG)
    #define PWMOUT1_SIO_HYST_EN        (* (reg8 *) PWMOUT1__SIO_HYST_EN)
    #define PWMOUT1_SIO_REG_HIFREQ     (* (reg8 *) PWMOUT1__SIO_REG_HIFREQ)
    #define PWMOUT1_SIO_CFG            (* (reg8 *) PWMOUT1__SIO_CFG)
    #define PWMOUT1_SIO_DIFF           (* (reg8 *) PWMOUT1__SIO_DIFF)
#endif /* (PWMOUT1__SIO_CFG) */

/* Interrupt Registers */
#if defined(PWMOUT1__INTSTAT)
    #define PWMOUT1_INTSTAT            (* (reg8 *) PWMOUT1__INTSTAT)
    #define PWMOUT1_SNAP               (* (reg8 *) PWMOUT1__SNAP)
    
	#define PWMOUT1_0_INTTYPE_REG 		(* (reg8 *) PWMOUT1__0__INTTYPE)
#endif /* (PWMOUT1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PWMOUT1_H */


/* [] END OF FILE */
