/*******************************************************************************
* File Name: BMP_SW0_RF.h  
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

#if !defined(CY_PINS_BMP_SW0_RF_H) /* Pins BMP_SW0_RF_H */
#define CY_PINS_BMP_SW0_RF_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "BMP_SW0_RF_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 BMP_SW0_RF__PORT == 15 && ((BMP_SW0_RF__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    BMP_SW0_RF_Write(uint8 value);
void    BMP_SW0_RF_SetDriveMode(uint8 mode);
uint8   BMP_SW0_RF_ReadDataReg(void);
uint8   BMP_SW0_RF_Read(void);
void    BMP_SW0_RF_SetInterruptMode(uint16 position, uint16 mode);
uint8   BMP_SW0_RF_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the BMP_SW0_RF_SetDriveMode() function.
     *  @{
     */
        #define BMP_SW0_RF_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define BMP_SW0_RF_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define BMP_SW0_RF_DM_RES_UP          PIN_DM_RES_UP
        #define BMP_SW0_RF_DM_RES_DWN         PIN_DM_RES_DWN
        #define BMP_SW0_RF_DM_OD_LO           PIN_DM_OD_LO
        #define BMP_SW0_RF_DM_OD_HI           PIN_DM_OD_HI
        #define BMP_SW0_RF_DM_STRONG          PIN_DM_STRONG
        #define BMP_SW0_RF_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define BMP_SW0_RF_MASK               BMP_SW0_RF__MASK
#define BMP_SW0_RF_SHIFT              BMP_SW0_RF__SHIFT
#define BMP_SW0_RF_WIDTH              1u

/* Interrupt constants */
#if defined(BMP_SW0_RF__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in BMP_SW0_RF_SetInterruptMode() function.
     *  @{
     */
        #define BMP_SW0_RF_INTR_NONE      (uint16)(0x0000u)
        #define BMP_SW0_RF_INTR_RISING    (uint16)(0x0001u)
        #define BMP_SW0_RF_INTR_FALLING   (uint16)(0x0002u)
        #define BMP_SW0_RF_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define BMP_SW0_RF_INTR_MASK      (0x01u) 
#endif /* (BMP_SW0_RF__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define BMP_SW0_RF_PS                     (* (reg8 *) BMP_SW0_RF__PS)
/* Data Register */
#define BMP_SW0_RF_DR                     (* (reg8 *) BMP_SW0_RF__DR)
/* Port Number */
#define BMP_SW0_RF_PRT_NUM                (* (reg8 *) BMP_SW0_RF__PRT) 
/* Connect to Analog Globals */                                                  
#define BMP_SW0_RF_AG                     (* (reg8 *) BMP_SW0_RF__AG)                       
/* Analog MUX bux enable */
#define BMP_SW0_RF_AMUX                   (* (reg8 *) BMP_SW0_RF__AMUX) 
/* Bidirectional Enable */                                                        
#define BMP_SW0_RF_BIE                    (* (reg8 *) BMP_SW0_RF__BIE)
/* Bit-mask for Aliased Register Access */
#define BMP_SW0_RF_BIT_MASK               (* (reg8 *) BMP_SW0_RF__BIT_MASK)
/* Bypass Enable */
#define BMP_SW0_RF_BYP                    (* (reg8 *) BMP_SW0_RF__BYP)
/* Port wide control signals */                                                   
#define BMP_SW0_RF_CTL                    (* (reg8 *) BMP_SW0_RF__CTL)
/* Drive Modes */
#define BMP_SW0_RF_DM0                    (* (reg8 *) BMP_SW0_RF__DM0) 
#define BMP_SW0_RF_DM1                    (* (reg8 *) BMP_SW0_RF__DM1)
#define BMP_SW0_RF_DM2                    (* (reg8 *) BMP_SW0_RF__DM2) 
/* Input Buffer Disable Override */
#define BMP_SW0_RF_INP_DIS                (* (reg8 *) BMP_SW0_RF__INP_DIS)
/* LCD Common or Segment Drive */
#define BMP_SW0_RF_LCD_COM_SEG            (* (reg8 *) BMP_SW0_RF__LCD_COM_SEG)
/* Enable Segment LCD */
#define BMP_SW0_RF_LCD_EN                 (* (reg8 *) BMP_SW0_RF__LCD_EN)
/* Slew Rate Control */
#define BMP_SW0_RF_SLW                    (* (reg8 *) BMP_SW0_RF__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define BMP_SW0_RF_PRTDSI__CAPS_SEL       (* (reg8 *) BMP_SW0_RF__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define BMP_SW0_RF_PRTDSI__DBL_SYNC_IN    (* (reg8 *) BMP_SW0_RF__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define BMP_SW0_RF_PRTDSI__OE_SEL0        (* (reg8 *) BMP_SW0_RF__PRTDSI__OE_SEL0) 
#define BMP_SW0_RF_PRTDSI__OE_SEL1        (* (reg8 *) BMP_SW0_RF__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define BMP_SW0_RF_PRTDSI__OUT_SEL0       (* (reg8 *) BMP_SW0_RF__PRTDSI__OUT_SEL0) 
#define BMP_SW0_RF_PRTDSI__OUT_SEL1       (* (reg8 *) BMP_SW0_RF__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define BMP_SW0_RF_PRTDSI__SYNC_OUT       (* (reg8 *) BMP_SW0_RF__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(BMP_SW0_RF__SIO_CFG)
    #define BMP_SW0_RF_SIO_HYST_EN        (* (reg8 *) BMP_SW0_RF__SIO_HYST_EN)
    #define BMP_SW0_RF_SIO_REG_HIFREQ     (* (reg8 *) BMP_SW0_RF__SIO_REG_HIFREQ)
    #define BMP_SW0_RF_SIO_CFG            (* (reg8 *) BMP_SW0_RF__SIO_CFG)
    #define BMP_SW0_RF_SIO_DIFF           (* (reg8 *) BMP_SW0_RF__SIO_DIFF)
#endif /* (BMP_SW0_RF__SIO_CFG) */

/* Interrupt Registers */
#if defined(BMP_SW0_RF__INTSTAT)
    #define BMP_SW0_RF_INTSTAT            (* (reg8 *) BMP_SW0_RF__INTSTAT)
    #define BMP_SW0_RF_SNAP               (* (reg8 *) BMP_SW0_RF__SNAP)
    
	#define BMP_SW0_RF_0_INTTYPE_REG 		(* (reg8 *) BMP_SW0_RF__0__INTTYPE)
#endif /* (BMP_SW0_RF__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_BMP_SW0_RF_H */


/* [] END OF FILE */
