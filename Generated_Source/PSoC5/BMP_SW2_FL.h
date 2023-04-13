/*******************************************************************************
* File Name: BMP_SW2_FL.h  
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

#if !defined(CY_PINS_BMP_SW2_FL_H) /* Pins BMP_SW2_FL_H */
#define CY_PINS_BMP_SW2_FL_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "BMP_SW2_FL_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 BMP_SW2_FL__PORT == 15 && ((BMP_SW2_FL__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    BMP_SW2_FL_Write(uint8 value);
void    BMP_SW2_FL_SetDriveMode(uint8 mode);
uint8   BMP_SW2_FL_ReadDataReg(void);
uint8   BMP_SW2_FL_Read(void);
void    BMP_SW2_FL_SetInterruptMode(uint16 position, uint16 mode);
uint8   BMP_SW2_FL_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the BMP_SW2_FL_SetDriveMode() function.
     *  @{
     */
        #define BMP_SW2_FL_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define BMP_SW2_FL_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define BMP_SW2_FL_DM_RES_UP          PIN_DM_RES_UP
        #define BMP_SW2_FL_DM_RES_DWN         PIN_DM_RES_DWN
        #define BMP_SW2_FL_DM_OD_LO           PIN_DM_OD_LO
        #define BMP_SW2_FL_DM_OD_HI           PIN_DM_OD_HI
        #define BMP_SW2_FL_DM_STRONG          PIN_DM_STRONG
        #define BMP_SW2_FL_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define BMP_SW2_FL_MASK               BMP_SW2_FL__MASK
#define BMP_SW2_FL_SHIFT              BMP_SW2_FL__SHIFT
#define BMP_SW2_FL_WIDTH              1u

/* Interrupt constants */
#if defined(BMP_SW2_FL__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in BMP_SW2_FL_SetInterruptMode() function.
     *  @{
     */
        #define BMP_SW2_FL_INTR_NONE      (uint16)(0x0000u)
        #define BMP_SW2_FL_INTR_RISING    (uint16)(0x0001u)
        #define BMP_SW2_FL_INTR_FALLING   (uint16)(0x0002u)
        #define BMP_SW2_FL_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define BMP_SW2_FL_INTR_MASK      (0x01u) 
#endif /* (BMP_SW2_FL__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define BMP_SW2_FL_PS                     (* (reg8 *) BMP_SW2_FL__PS)
/* Data Register */
#define BMP_SW2_FL_DR                     (* (reg8 *) BMP_SW2_FL__DR)
/* Port Number */
#define BMP_SW2_FL_PRT_NUM                (* (reg8 *) BMP_SW2_FL__PRT) 
/* Connect to Analog Globals */                                                  
#define BMP_SW2_FL_AG                     (* (reg8 *) BMP_SW2_FL__AG)                       
/* Analog MUX bux enable */
#define BMP_SW2_FL_AMUX                   (* (reg8 *) BMP_SW2_FL__AMUX) 
/* Bidirectional Enable */                                                        
#define BMP_SW2_FL_BIE                    (* (reg8 *) BMP_SW2_FL__BIE)
/* Bit-mask for Aliased Register Access */
#define BMP_SW2_FL_BIT_MASK               (* (reg8 *) BMP_SW2_FL__BIT_MASK)
/* Bypass Enable */
#define BMP_SW2_FL_BYP                    (* (reg8 *) BMP_SW2_FL__BYP)
/* Port wide control signals */                                                   
#define BMP_SW2_FL_CTL                    (* (reg8 *) BMP_SW2_FL__CTL)
/* Drive Modes */
#define BMP_SW2_FL_DM0                    (* (reg8 *) BMP_SW2_FL__DM0) 
#define BMP_SW2_FL_DM1                    (* (reg8 *) BMP_SW2_FL__DM1)
#define BMP_SW2_FL_DM2                    (* (reg8 *) BMP_SW2_FL__DM2) 
/* Input Buffer Disable Override */
#define BMP_SW2_FL_INP_DIS                (* (reg8 *) BMP_SW2_FL__INP_DIS)
/* LCD Common or Segment Drive */
#define BMP_SW2_FL_LCD_COM_SEG            (* (reg8 *) BMP_SW2_FL__LCD_COM_SEG)
/* Enable Segment LCD */
#define BMP_SW2_FL_LCD_EN                 (* (reg8 *) BMP_SW2_FL__LCD_EN)
/* Slew Rate Control */
#define BMP_SW2_FL_SLW                    (* (reg8 *) BMP_SW2_FL__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define BMP_SW2_FL_PRTDSI__CAPS_SEL       (* (reg8 *) BMP_SW2_FL__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define BMP_SW2_FL_PRTDSI__DBL_SYNC_IN    (* (reg8 *) BMP_SW2_FL__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define BMP_SW2_FL_PRTDSI__OE_SEL0        (* (reg8 *) BMP_SW2_FL__PRTDSI__OE_SEL0) 
#define BMP_SW2_FL_PRTDSI__OE_SEL1        (* (reg8 *) BMP_SW2_FL__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define BMP_SW2_FL_PRTDSI__OUT_SEL0       (* (reg8 *) BMP_SW2_FL__PRTDSI__OUT_SEL0) 
#define BMP_SW2_FL_PRTDSI__OUT_SEL1       (* (reg8 *) BMP_SW2_FL__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define BMP_SW2_FL_PRTDSI__SYNC_OUT       (* (reg8 *) BMP_SW2_FL__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(BMP_SW2_FL__SIO_CFG)
    #define BMP_SW2_FL_SIO_HYST_EN        (* (reg8 *) BMP_SW2_FL__SIO_HYST_EN)
    #define BMP_SW2_FL_SIO_REG_HIFREQ     (* (reg8 *) BMP_SW2_FL__SIO_REG_HIFREQ)
    #define BMP_SW2_FL_SIO_CFG            (* (reg8 *) BMP_SW2_FL__SIO_CFG)
    #define BMP_SW2_FL_SIO_DIFF           (* (reg8 *) BMP_SW2_FL__SIO_DIFF)
#endif /* (BMP_SW2_FL__SIO_CFG) */

/* Interrupt Registers */
#if defined(BMP_SW2_FL__INTSTAT)
    #define BMP_SW2_FL_INTSTAT            (* (reg8 *) BMP_SW2_FL__INTSTAT)
    #define BMP_SW2_FL_SNAP               (* (reg8 *) BMP_SW2_FL__SNAP)
    
	#define BMP_SW2_FL_0_INTTYPE_REG 		(* (reg8 *) BMP_SW2_FL__0__INTTYPE)
#endif /* (BMP_SW2_FL__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_BMP_SW2_FL_H */


/* [] END OF FILE */
