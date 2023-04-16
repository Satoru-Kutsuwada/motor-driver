/*******************************************************************************
* File Name: dist8_SW_DET.h  
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

#if !defined(CY_PINS_dist8_SW_DET_H) /* Pins dist8_SW_DET_H */
#define CY_PINS_dist8_SW_DET_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "dist8_SW_DET_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 dist8_SW_DET__PORT == 15 && ((dist8_SW_DET__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    dist8_SW_DET_Write(uint8 value);
void    dist8_SW_DET_SetDriveMode(uint8 mode);
uint8   dist8_SW_DET_ReadDataReg(void);
uint8   dist8_SW_DET_Read(void);
void    dist8_SW_DET_SetInterruptMode(uint16 position, uint16 mode);
uint8   dist8_SW_DET_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the dist8_SW_DET_SetDriveMode() function.
     *  @{
     */
        #define dist8_SW_DET_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define dist8_SW_DET_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define dist8_SW_DET_DM_RES_UP          PIN_DM_RES_UP
        #define dist8_SW_DET_DM_RES_DWN         PIN_DM_RES_DWN
        #define dist8_SW_DET_DM_OD_LO           PIN_DM_OD_LO
        #define dist8_SW_DET_DM_OD_HI           PIN_DM_OD_HI
        #define dist8_SW_DET_DM_STRONG          PIN_DM_STRONG
        #define dist8_SW_DET_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define dist8_SW_DET_MASK               dist8_SW_DET__MASK
#define dist8_SW_DET_SHIFT              dist8_SW_DET__SHIFT
#define dist8_SW_DET_WIDTH              1u

/* Interrupt constants */
#if defined(dist8_SW_DET__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in dist8_SW_DET_SetInterruptMode() function.
     *  @{
     */
        #define dist8_SW_DET_INTR_NONE      (uint16)(0x0000u)
        #define dist8_SW_DET_INTR_RISING    (uint16)(0x0001u)
        #define dist8_SW_DET_INTR_FALLING   (uint16)(0x0002u)
        #define dist8_SW_DET_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define dist8_SW_DET_INTR_MASK      (0x01u) 
#endif /* (dist8_SW_DET__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define dist8_SW_DET_PS                     (* (reg8 *) dist8_SW_DET__PS)
/* Data Register */
#define dist8_SW_DET_DR                     (* (reg8 *) dist8_SW_DET__DR)
/* Port Number */
#define dist8_SW_DET_PRT_NUM                (* (reg8 *) dist8_SW_DET__PRT) 
/* Connect to Analog Globals */                                                  
#define dist8_SW_DET_AG                     (* (reg8 *) dist8_SW_DET__AG)                       
/* Analog MUX bux enable */
#define dist8_SW_DET_AMUX                   (* (reg8 *) dist8_SW_DET__AMUX) 
/* Bidirectional Enable */                                                        
#define dist8_SW_DET_BIE                    (* (reg8 *) dist8_SW_DET__BIE)
/* Bit-mask for Aliased Register Access */
#define dist8_SW_DET_BIT_MASK               (* (reg8 *) dist8_SW_DET__BIT_MASK)
/* Bypass Enable */
#define dist8_SW_DET_BYP                    (* (reg8 *) dist8_SW_DET__BYP)
/* Port wide control signals */                                                   
#define dist8_SW_DET_CTL                    (* (reg8 *) dist8_SW_DET__CTL)
/* Drive Modes */
#define dist8_SW_DET_DM0                    (* (reg8 *) dist8_SW_DET__DM0) 
#define dist8_SW_DET_DM1                    (* (reg8 *) dist8_SW_DET__DM1)
#define dist8_SW_DET_DM2                    (* (reg8 *) dist8_SW_DET__DM2) 
/* Input Buffer Disable Override */
#define dist8_SW_DET_INP_DIS                (* (reg8 *) dist8_SW_DET__INP_DIS)
/* LCD Common or Segment Drive */
#define dist8_SW_DET_LCD_COM_SEG            (* (reg8 *) dist8_SW_DET__LCD_COM_SEG)
/* Enable Segment LCD */
#define dist8_SW_DET_LCD_EN                 (* (reg8 *) dist8_SW_DET__LCD_EN)
/* Slew Rate Control */
#define dist8_SW_DET_SLW                    (* (reg8 *) dist8_SW_DET__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define dist8_SW_DET_PRTDSI__CAPS_SEL       (* (reg8 *) dist8_SW_DET__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define dist8_SW_DET_PRTDSI__DBL_SYNC_IN    (* (reg8 *) dist8_SW_DET__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define dist8_SW_DET_PRTDSI__OE_SEL0        (* (reg8 *) dist8_SW_DET__PRTDSI__OE_SEL0) 
#define dist8_SW_DET_PRTDSI__OE_SEL1        (* (reg8 *) dist8_SW_DET__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define dist8_SW_DET_PRTDSI__OUT_SEL0       (* (reg8 *) dist8_SW_DET__PRTDSI__OUT_SEL0) 
#define dist8_SW_DET_PRTDSI__OUT_SEL1       (* (reg8 *) dist8_SW_DET__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define dist8_SW_DET_PRTDSI__SYNC_OUT       (* (reg8 *) dist8_SW_DET__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(dist8_SW_DET__SIO_CFG)
    #define dist8_SW_DET_SIO_HYST_EN        (* (reg8 *) dist8_SW_DET__SIO_HYST_EN)
    #define dist8_SW_DET_SIO_REG_HIFREQ     (* (reg8 *) dist8_SW_DET__SIO_REG_HIFREQ)
    #define dist8_SW_DET_SIO_CFG            (* (reg8 *) dist8_SW_DET__SIO_CFG)
    #define dist8_SW_DET_SIO_DIFF           (* (reg8 *) dist8_SW_DET__SIO_DIFF)
#endif /* (dist8_SW_DET__SIO_CFG) */

/* Interrupt Registers */
#if defined(dist8_SW_DET__INTSTAT)
    #define dist8_SW_DET_INTSTAT            (* (reg8 *) dist8_SW_DET__INTSTAT)
    #define dist8_SW_DET_SNAP               (* (reg8 *) dist8_SW_DET__SNAP)
    
	#define dist8_SW_DET_0_INTTYPE_REG 		(* (reg8 *) dist8_SW_DET__0__INTTYPE)
#endif /* (dist8_SW_DET__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_dist8_SW_DET_H */


/* [] END OF FILE */
