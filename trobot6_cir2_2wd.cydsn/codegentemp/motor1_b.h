/*******************************************************************************
* File Name: motor1_b.h  
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

#if !defined(CY_PINS_motor1_b_H) /* Pins motor1_b_H */
#define CY_PINS_motor1_b_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "motor1_b_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 motor1_b__PORT == 15 && ((motor1_b__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    motor1_b_Write(uint8 value);
void    motor1_b_SetDriveMode(uint8 mode);
uint8   motor1_b_ReadDataReg(void);
uint8   motor1_b_Read(void);
void    motor1_b_SetInterruptMode(uint16 position, uint16 mode);
uint8   motor1_b_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the motor1_b_SetDriveMode() function.
     *  @{
     */
        #define motor1_b_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define motor1_b_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define motor1_b_DM_RES_UP          PIN_DM_RES_UP
        #define motor1_b_DM_RES_DWN         PIN_DM_RES_DWN
        #define motor1_b_DM_OD_LO           PIN_DM_OD_LO
        #define motor1_b_DM_OD_HI           PIN_DM_OD_HI
        #define motor1_b_DM_STRONG          PIN_DM_STRONG
        #define motor1_b_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define motor1_b_MASK               motor1_b__MASK
#define motor1_b_SHIFT              motor1_b__SHIFT
#define motor1_b_WIDTH              1u

/* Interrupt constants */
#if defined(motor1_b__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in motor1_b_SetInterruptMode() function.
     *  @{
     */
        #define motor1_b_INTR_NONE      (uint16)(0x0000u)
        #define motor1_b_INTR_RISING    (uint16)(0x0001u)
        #define motor1_b_INTR_FALLING   (uint16)(0x0002u)
        #define motor1_b_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define motor1_b_INTR_MASK      (0x01u) 
#endif /* (motor1_b__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define motor1_b_PS                     (* (reg8 *) motor1_b__PS)
/* Data Register */
#define motor1_b_DR                     (* (reg8 *) motor1_b__DR)
/* Port Number */
#define motor1_b_PRT_NUM                (* (reg8 *) motor1_b__PRT) 
/* Connect to Analog Globals */                                                  
#define motor1_b_AG                     (* (reg8 *) motor1_b__AG)                       
/* Analog MUX bux enable */
#define motor1_b_AMUX                   (* (reg8 *) motor1_b__AMUX) 
/* Bidirectional Enable */                                                        
#define motor1_b_BIE                    (* (reg8 *) motor1_b__BIE)
/* Bit-mask for Aliased Register Access */
#define motor1_b_BIT_MASK               (* (reg8 *) motor1_b__BIT_MASK)
/* Bypass Enable */
#define motor1_b_BYP                    (* (reg8 *) motor1_b__BYP)
/* Port wide control signals */                                                   
#define motor1_b_CTL                    (* (reg8 *) motor1_b__CTL)
/* Drive Modes */
#define motor1_b_DM0                    (* (reg8 *) motor1_b__DM0) 
#define motor1_b_DM1                    (* (reg8 *) motor1_b__DM1)
#define motor1_b_DM2                    (* (reg8 *) motor1_b__DM2) 
/* Input Buffer Disable Override */
#define motor1_b_INP_DIS                (* (reg8 *) motor1_b__INP_DIS)
/* LCD Common or Segment Drive */
#define motor1_b_LCD_COM_SEG            (* (reg8 *) motor1_b__LCD_COM_SEG)
/* Enable Segment LCD */
#define motor1_b_LCD_EN                 (* (reg8 *) motor1_b__LCD_EN)
/* Slew Rate Control */
#define motor1_b_SLW                    (* (reg8 *) motor1_b__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define motor1_b_PRTDSI__CAPS_SEL       (* (reg8 *) motor1_b__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define motor1_b_PRTDSI__DBL_SYNC_IN    (* (reg8 *) motor1_b__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define motor1_b_PRTDSI__OE_SEL0        (* (reg8 *) motor1_b__PRTDSI__OE_SEL0) 
#define motor1_b_PRTDSI__OE_SEL1        (* (reg8 *) motor1_b__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define motor1_b_PRTDSI__OUT_SEL0       (* (reg8 *) motor1_b__PRTDSI__OUT_SEL0) 
#define motor1_b_PRTDSI__OUT_SEL1       (* (reg8 *) motor1_b__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define motor1_b_PRTDSI__SYNC_OUT       (* (reg8 *) motor1_b__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(motor1_b__SIO_CFG)
    #define motor1_b_SIO_HYST_EN        (* (reg8 *) motor1_b__SIO_HYST_EN)
    #define motor1_b_SIO_REG_HIFREQ     (* (reg8 *) motor1_b__SIO_REG_HIFREQ)
    #define motor1_b_SIO_CFG            (* (reg8 *) motor1_b__SIO_CFG)
    #define motor1_b_SIO_DIFF           (* (reg8 *) motor1_b__SIO_DIFF)
#endif /* (motor1_b__SIO_CFG) */

/* Interrupt Registers */
#if defined(motor1_b__INTSTAT)
    #define motor1_b_INTSTAT            (* (reg8 *) motor1_b__INTSTAT)
    #define motor1_b_SNAP               (* (reg8 *) motor1_b__SNAP)
    
	#define motor1_b_0_INTTYPE_REG 		(* (reg8 *) motor1_b__0__INTTYPE)
#endif /* (motor1_b__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_motor1_b_H */


/* [] END OF FILE */
