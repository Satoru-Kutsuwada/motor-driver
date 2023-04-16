/*******************************************************************************
* File Name: SelfTest_CPU_asm.h
* Version 1.0
*
* Description:
* This file provides constants and parameter values used for CPU register self   
* tests for PSoC 3 and PSoC 5LP.
*
* Note:
*
********************************************************************************
* Copyright (2013), Cypress Semiconductor Corporation.
********************************************************************************
* This software is owned by Cypress Semiconductor Corporation (Cypress) and is
* protected by and subject to worldwide patent protection (United States and
* foreign), United States copyright laws and international treaty provisions.
* Cypress hereby grants to licensee a personal, non-exclusive, non-transferable
* license to copy, use, modify, create derivative works of, and compile the
* Cypress Source Code and derivative works for the sole purpose of creating
* custom software in support of licensee product to be used only in conjunction
* with a Cypress integrated circuit as specified in the applicable agreement.
* Any reproduction, modification, translation, compilation, or representation of
* this software except as specified above is prohibited without the express
* written permission of Cypress.
*
* Disclaimer: CYPRESS MAKES NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, WITH
* REGARD TO THIS MATERIAL, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* Cypress reserves the right to make changes without further notice to the
* materials described herein. Cypress does not assume any liability arising out
* of the application or use of any product or circuit described herein. Cypress
* does not authorize its products for use as critical components in life-support
* systems where a malfunction or failure may reasonably be expected to result in
* significant injury to the user. The inclusion of Cypress' product in a life*
support systems application implies that the manufacturer assumes all risk of
* such use and in doing so indemnifies Cypress against all charges. Use may be
* limited by and subject to the applicable Cypress software license agreement.
*******************************************************************************/

#if !defined(SELFTEST_CPU_ASM_H)
#define SELFTEST_CPU_ASM_H


#include<project.h>

/*************************************** 
* Function Prototypes 
***************************************/


#if defined(__C51__) || defined(__GNUC__)
    uint8 CPU_PSoC_Asm(void);	
#elif defined(__CC_ARM)
    uint8 CPU_PSoC_5_Asm(void);	
#endif 

/***************************************
* Initial Parameter Constants 
***************************************/

#define IRAM_SIZE       0xFF    /* Size of CPU SRAM in PSoC3 */

/*Status flags to return function results*/
#define CPU_OK         	0x00	
#define CPU_FAILURE	    0x01  

#endif /* End SELFTEST_CPU_H */


/* [] END OF FILE */

