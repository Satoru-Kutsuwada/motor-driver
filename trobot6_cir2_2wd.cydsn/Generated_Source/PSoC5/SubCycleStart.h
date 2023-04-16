/*******************************************************************************
* File Name: SubCycleStart.h  
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

#if !defined(CY_PINS_SubCycleStart_H) /* Pins SubCycleStart_H */
#define CY_PINS_SubCycleStart_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SubCycleStart_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SubCycleStart__PORT == 15 && ((SubCycleStart__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    SubCycleStart_Write(uint8 value);
void    SubCycleStart_SetDriveMode(uint8 mode);
uint8   SubCycleStart_ReadDataReg(void);
uint8   SubCycleStart_Read(void);
void    SubCycleStart_SetInterruptMode(uint16 position, uint16 mode);
uint8   SubCycleStart_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the SubCycleStart_SetDriveMode() function.
     *  @{
     */
        #define SubCycleStart_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define SubCycleStart_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define SubCycleStart_DM_RES_UP          PIN_DM_RES_UP
        #define SubCycleStart_DM_RES_DWN         PIN_DM_RES_DWN
        #define SubCycleStart_DM_OD_LO           PIN_DM_OD_LO
        #define SubCycleStart_DM_OD_HI           PIN_DM_OD_HI
        #define SubCycleStart_DM_STRONG          PIN_DM_STRONG
        #define SubCycleStart_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define SubCycleStart_MASK               SubCycleStart__MASK
#define SubCycleStart_SHIFT              SubCycleStart__SHIFT
#define SubCycleStart_WIDTH              1u

/* Interrupt constants */
#if defined(SubCycleStart__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in SubCycleStart_SetInterruptMode() function.
     *  @{
     */
        #define SubCycleStart_INTR_NONE      (uint16)(0x0000u)
        #define SubCycleStart_INTR_RISING    (uint16)(0x0001u)
        #define SubCycleStart_INTR_FALLING   (uint16)(0x0002u)
        #define SubCycleStart_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define SubCycleStart_INTR_MASK      (0x01u) 
#endif /* (SubCycleStart__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SubCycleStart_PS                     (* (reg8 *) SubCycleStart__PS)
/* Data Register */
#define SubCycleStart_DR                     (* (reg8 *) SubCycleStart__DR)
/* Port Number */
#define SubCycleStart_PRT_NUM                (* (reg8 *) SubCycleStart__PRT) 
/* Connect to Analog Globals */                                                  
#define SubCycleStart_AG                     (* (reg8 *) SubCycleStart__AG)                       
/* Analog MUX bux enable */
#define SubCycleStart_AMUX                   (* (reg8 *) SubCycleStart__AMUX) 
/* Bidirectional Enable */                                                        
#define SubCycleStart_BIE                    (* (reg8 *) SubCycleStart__BIE)
/* Bit-mask for Aliased Register Access */
#define SubCycleStart_BIT_MASK               (* (reg8 *) SubCycleStart__BIT_MASK)
/* Bypass Enable */
#define SubCycleStart_BYP                    (* (reg8 *) SubCycleStart__BYP)
/* Port wide control signals */                                                   
#define SubCycleStart_CTL                    (* (reg8 *) SubCycleStart__CTL)
/* Drive Modes */
#define SubCycleStart_DM0                    (* (reg8 *) SubCycleStart__DM0) 
#define SubCycleStart_DM1                    (* (reg8 *) SubCycleStart__DM1)
#define SubCycleStart_DM2                    (* (reg8 *) SubCycleStart__DM2) 
/* Input Buffer Disable Override */
#define SubCycleStart_INP_DIS                (* (reg8 *) SubCycleStart__INP_DIS)
/* LCD Common or Segment Drive */
#define SubCycleStart_LCD_COM_SEG            (* (reg8 *) SubCycleStart__LCD_COM_SEG)
/* Enable Segment LCD */
#define SubCycleStart_LCD_EN                 (* (reg8 *) SubCycleStart__LCD_EN)
/* Slew Rate Control */
#define SubCycleStart_SLW                    (* (reg8 *) SubCycleStart__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SubCycleStart_PRTDSI__CAPS_SEL       (* (reg8 *) SubCycleStart__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SubCycleStart_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SubCycleStart__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SubCycleStart_PRTDSI__OE_SEL0        (* (reg8 *) SubCycleStart__PRTDSI__OE_SEL0) 
#define SubCycleStart_PRTDSI__OE_SEL1        (* (reg8 *) SubCycleStart__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SubCycleStart_PRTDSI__OUT_SEL0       (* (reg8 *) SubCycleStart__PRTDSI__OUT_SEL0) 
#define SubCycleStart_PRTDSI__OUT_SEL1       (* (reg8 *) SubCycleStart__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SubCycleStart_PRTDSI__SYNC_OUT       (* (reg8 *) SubCycleStart__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(SubCycleStart__SIO_CFG)
    #define SubCycleStart_SIO_HYST_EN        (* (reg8 *) SubCycleStart__SIO_HYST_EN)
    #define SubCycleStart_SIO_REG_HIFREQ     (* (reg8 *) SubCycleStart__SIO_REG_HIFREQ)
    #define SubCycleStart_SIO_CFG            (* (reg8 *) SubCycleStart__SIO_CFG)
    #define SubCycleStart_SIO_DIFF           (* (reg8 *) SubCycleStart__SIO_DIFF)
#endif /* (SubCycleStart__SIO_CFG) */

/* Interrupt Registers */
#if defined(SubCycleStart__INTSTAT)
    #define SubCycleStart_INTSTAT            (* (reg8 *) SubCycleStart__INTSTAT)
    #define SubCycleStart_SNAP               (* (reg8 *) SubCycleStart__SNAP)
    
	#define SubCycleStart_0_INTTYPE_REG 		(* (reg8 *) SubCycleStart__0__INTTYPE)
#endif /* (SubCycleStart__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SubCycleStart_H */


/* [] END OF FILE */
