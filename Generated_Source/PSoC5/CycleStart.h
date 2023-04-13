/*******************************************************************************
* File Name: CycleStart.h  
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

#if !defined(CY_PINS_CycleStart_H) /* Pins CycleStart_H */
#define CY_PINS_CycleStart_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "CycleStart_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 CycleStart__PORT == 15 && ((CycleStart__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    CycleStart_Write(uint8 value);
void    CycleStart_SetDriveMode(uint8 mode);
uint8   CycleStart_ReadDataReg(void);
uint8   CycleStart_Read(void);
void    CycleStart_SetInterruptMode(uint16 position, uint16 mode);
uint8   CycleStart_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the CycleStart_SetDriveMode() function.
     *  @{
     */
        #define CycleStart_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define CycleStart_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define CycleStart_DM_RES_UP          PIN_DM_RES_UP
        #define CycleStart_DM_RES_DWN         PIN_DM_RES_DWN
        #define CycleStart_DM_OD_LO           PIN_DM_OD_LO
        #define CycleStart_DM_OD_HI           PIN_DM_OD_HI
        #define CycleStart_DM_STRONG          PIN_DM_STRONG
        #define CycleStart_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define CycleStart_MASK               CycleStart__MASK
#define CycleStart_SHIFT              CycleStart__SHIFT
#define CycleStart_WIDTH              1u

/* Interrupt constants */
#if defined(CycleStart__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in CycleStart_SetInterruptMode() function.
     *  @{
     */
        #define CycleStart_INTR_NONE      (uint16)(0x0000u)
        #define CycleStart_INTR_RISING    (uint16)(0x0001u)
        #define CycleStart_INTR_FALLING   (uint16)(0x0002u)
        #define CycleStart_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define CycleStart_INTR_MASK      (0x01u) 
#endif /* (CycleStart__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define CycleStart_PS                     (* (reg8 *) CycleStart__PS)
/* Data Register */
#define CycleStart_DR                     (* (reg8 *) CycleStart__DR)
/* Port Number */
#define CycleStart_PRT_NUM                (* (reg8 *) CycleStart__PRT) 
/* Connect to Analog Globals */                                                  
#define CycleStart_AG                     (* (reg8 *) CycleStart__AG)                       
/* Analog MUX bux enable */
#define CycleStart_AMUX                   (* (reg8 *) CycleStart__AMUX) 
/* Bidirectional Enable */                                                        
#define CycleStart_BIE                    (* (reg8 *) CycleStart__BIE)
/* Bit-mask for Aliased Register Access */
#define CycleStart_BIT_MASK               (* (reg8 *) CycleStart__BIT_MASK)
/* Bypass Enable */
#define CycleStart_BYP                    (* (reg8 *) CycleStart__BYP)
/* Port wide control signals */                                                   
#define CycleStart_CTL                    (* (reg8 *) CycleStart__CTL)
/* Drive Modes */
#define CycleStart_DM0                    (* (reg8 *) CycleStart__DM0) 
#define CycleStart_DM1                    (* (reg8 *) CycleStart__DM1)
#define CycleStart_DM2                    (* (reg8 *) CycleStart__DM2) 
/* Input Buffer Disable Override */
#define CycleStart_INP_DIS                (* (reg8 *) CycleStart__INP_DIS)
/* LCD Common or Segment Drive */
#define CycleStart_LCD_COM_SEG            (* (reg8 *) CycleStart__LCD_COM_SEG)
/* Enable Segment LCD */
#define CycleStart_LCD_EN                 (* (reg8 *) CycleStart__LCD_EN)
/* Slew Rate Control */
#define CycleStart_SLW                    (* (reg8 *) CycleStart__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define CycleStart_PRTDSI__CAPS_SEL       (* (reg8 *) CycleStart__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define CycleStart_PRTDSI__DBL_SYNC_IN    (* (reg8 *) CycleStart__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define CycleStart_PRTDSI__OE_SEL0        (* (reg8 *) CycleStart__PRTDSI__OE_SEL0) 
#define CycleStart_PRTDSI__OE_SEL1        (* (reg8 *) CycleStart__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define CycleStart_PRTDSI__OUT_SEL0       (* (reg8 *) CycleStart__PRTDSI__OUT_SEL0) 
#define CycleStart_PRTDSI__OUT_SEL1       (* (reg8 *) CycleStart__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define CycleStart_PRTDSI__SYNC_OUT       (* (reg8 *) CycleStart__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(CycleStart__SIO_CFG)
    #define CycleStart_SIO_HYST_EN        (* (reg8 *) CycleStart__SIO_HYST_EN)
    #define CycleStart_SIO_REG_HIFREQ     (* (reg8 *) CycleStart__SIO_REG_HIFREQ)
    #define CycleStart_SIO_CFG            (* (reg8 *) CycleStart__SIO_CFG)
    #define CycleStart_SIO_DIFF           (* (reg8 *) CycleStart__SIO_DIFF)
#endif /* (CycleStart__SIO_CFG) */

/* Interrupt Registers */
#if defined(CycleStart__INTSTAT)
    #define CycleStart_INTSTAT            (* (reg8 *) CycleStart__INTSTAT)
    #define CycleStart_SNAP               (* (reg8 *) CycleStart__SNAP)
    
	#define CycleStart_0_INTTYPE_REG 		(* (reg8 *) CycleStart__0__INTTYPE)
#endif /* (CycleStart__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_CycleStart_H */


/* [] END OF FILE */
