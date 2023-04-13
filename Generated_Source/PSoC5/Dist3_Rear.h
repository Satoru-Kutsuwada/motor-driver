/*******************************************************************************
* File Name: Dist3_Rear.h  
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

#if !defined(CY_PINS_Dist3_Rear_H) /* Pins Dist3_Rear_H */
#define CY_PINS_Dist3_Rear_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Dist3_Rear_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Dist3_Rear__PORT == 15 && ((Dist3_Rear__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Dist3_Rear_Write(uint8 value);
void    Dist3_Rear_SetDriveMode(uint8 mode);
uint8   Dist3_Rear_ReadDataReg(void);
uint8   Dist3_Rear_Read(void);
void    Dist3_Rear_SetInterruptMode(uint16 position, uint16 mode);
uint8   Dist3_Rear_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Dist3_Rear_SetDriveMode() function.
     *  @{
     */
        #define Dist3_Rear_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Dist3_Rear_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Dist3_Rear_DM_RES_UP          PIN_DM_RES_UP
        #define Dist3_Rear_DM_RES_DWN         PIN_DM_RES_DWN
        #define Dist3_Rear_DM_OD_LO           PIN_DM_OD_LO
        #define Dist3_Rear_DM_OD_HI           PIN_DM_OD_HI
        #define Dist3_Rear_DM_STRONG          PIN_DM_STRONG
        #define Dist3_Rear_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Dist3_Rear_MASK               Dist3_Rear__MASK
#define Dist3_Rear_SHIFT              Dist3_Rear__SHIFT
#define Dist3_Rear_WIDTH              1u

/* Interrupt constants */
#if defined(Dist3_Rear__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Dist3_Rear_SetInterruptMode() function.
     *  @{
     */
        #define Dist3_Rear_INTR_NONE      (uint16)(0x0000u)
        #define Dist3_Rear_INTR_RISING    (uint16)(0x0001u)
        #define Dist3_Rear_INTR_FALLING   (uint16)(0x0002u)
        #define Dist3_Rear_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Dist3_Rear_INTR_MASK      (0x01u) 
#endif /* (Dist3_Rear__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Dist3_Rear_PS                     (* (reg8 *) Dist3_Rear__PS)
/* Data Register */
#define Dist3_Rear_DR                     (* (reg8 *) Dist3_Rear__DR)
/* Port Number */
#define Dist3_Rear_PRT_NUM                (* (reg8 *) Dist3_Rear__PRT) 
/* Connect to Analog Globals */                                                  
#define Dist3_Rear_AG                     (* (reg8 *) Dist3_Rear__AG)                       
/* Analog MUX bux enable */
#define Dist3_Rear_AMUX                   (* (reg8 *) Dist3_Rear__AMUX) 
/* Bidirectional Enable */                                                        
#define Dist3_Rear_BIE                    (* (reg8 *) Dist3_Rear__BIE)
/* Bit-mask for Aliased Register Access */
#define Dist3_Rear_BIT_MASK               (* (reg8 *) Dist3_Rear__BIT_MASK)
/* Bypass Enable */
#define Dist3_Rear_BYP                    (* (reg8 *) Dist3_Rear__BYP)
/* Port wide control signals */                                                   
#define Dist3_Rear_CTL                    (* (reg8 *) Dist3_Rear__CTL)
/* Drive Modes */
#define Dist3_Rear_DM0                    (* (reg8 *) Dist3_Rear__DM0) 
#define Dist3_Rear_DM1                    (* (reg8 *) Dist3_Rear__DM1)
#define Dist3_Rear_DM2                    (* (reg8 *) Dist3_Rear__DM2) 
/* Input Buffer Disable Override */
#define Dist3_Rear_INP_DIS                (* (reg8 *) Dist3_Rear__INP_DIS)
/* LCD Common or Segment Drive */
#define Dist3_Rear_LCD_COM_SEG            (* (reg8 *) Dist3_Rear__LCD_COM_SEG)
/* Enable Segment LCD */
#define Dist3_Rear_LCD_EN                 (* (reg8 *) Dist3_Rear__LCD_EN)
/* Slew Rate Control */
#define Dist3_Rear_SLW                    (* (reg8 *) Dist3_Rear__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Dist3_Rear_PRTDSI__CAPS_SEL       (* (reg8 *) Dist3_Rear__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Dist3_Rear_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Dist3_Rear__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Dist3_Rear_PRTDSI__OE_SEL0        (* (reg8 *) Dist3_Rear__PRTDSI__OE_SEL0) 
#define Dist3_Rear_PRTDSI__OE_SEL1        (* (reg8 *) Dist3_Rear__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Dist3_Rear_PRTDSI__OUT_SEL0       (* (reg8 *) Dist3_Rear__PRTDSI__OUT_SEL0) 
#define Dist3_Rear_PRTDSI__OUT_SEL1       (* (reg8 *) Dist3_Rear__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Dist3_Rear_PRTDSI__SYNC_OUT       (* (reg8 *) Dist3_Rear__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Dist3_Rear__SIO_CFG)
    #define Dist3_Rear_SIO_HYST_EN        (* (reg8 *) Dist3_Rear__SIO_HYST_EN)
    #define Dist3_Rear_SIO_REG_HIFREQ     (* (reg8 *) Dist3_Rear__SIO_REG_HIFREQ)
    #define Dist3_Rear_SIO_CFG            (* (reg8 *) Dist3_Rear__SIO_CFG)
    #define Dist3_Rear_SIO_DIFF           (* (reg8 *) Dist3_Rear__SIO_DIFF)
#endif /* (Dist3_Rear__SIO_CFG) */

/* Interrupt Registers */
#if defined(Dist3_Rear__INTSTAT)
    #define Dist3_Rear_INTSTAT            (* (reg8 *) Dist3_Rear__INTSTAT)
    #define Dist3_Rear_SNAP               (* (reg8 *) Dist3_Rear__SNAP)
    
	#define Dist3_Rear_0_INTTYPE_REG 		(* (reg8 *) Dist3_Rear__0__INTTYPE)
#endif /* (Dist3_Rear__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Dist3_Rear_H */


/* [] END OF FILE */
