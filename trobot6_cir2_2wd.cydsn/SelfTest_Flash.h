/*******************************************************************************
* File Name: SelfTest_Flash.h
* Version 1.0
*
* Description:
* This file provides function prototypes, constants, and parameter values   
* used for ROM self tests for PSoC 3 and PSoC 5LP.
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

#if !defined(SELFTEST_FLASH_H)
    #define SELFTEST_FLASH_H


/*************************************** 
* Function Prototypes 
***************************************/


/* Check if ECC enabled */
#if (CYDEV_ECC_ENABLE)	

    /* This function used for PSoC 3 and PSOC 5LP with ECC enabled */
    uint8 SelfTest_FlashECC(void);
    
 /* Check if ECC disabled */    
#elif (!CYDEV_ECC_ENABLE)    

    /* If PSoC 3 */
    #if defined(__C51__)	
    
        /* Function used for Flash self test using check sum method */
        /* For PSoC 3 needs 16-bits for Flash addressing */
		uint8 SelfTest_FlashCheckSum(uint16 WordsToTest);
        
    /* If PSoC 5LP */    
    #elif defined(__GNUC__) || defined(__CC_ARM) || defined(__ARMCC_VERSION)
    
        /* Function used for Flash self test using check sum method */
        /* For PSoC 5LP needs 32-bits for Flash addressing */    
		uint8 SelfTest_FlashCheckSum(uint32 WordsToTest);
    #endif  
    
#endif  


/***************************************
* Initial Parameter Constants 
***************************************/

/* Set size of one block in Flash test */
#define WORDS_IN_BLOCK_FLASH                   (1024u)

/* Define start address of Flash depending on PSoCs */
#if defined(__C51__)	
    #define PSOC_FLS_BASE   (0x0000u)
#elif defined(__GNUC__) || defined(__CC_ARM) || defined(__ARMCC_VERSION)
    #define PSOC_FLS_BASE   CYDEV_FLS_BASE
#endif    


/* Define size of Flash which used for checksum calculation */
/* Last two bytes used for flash checksum storing, and need to subtract "two" */
#define PSOC_FLASH_SIZE                         (CYDEV_FLS_SIZE - 2u)         
  
/*Status flags to return function results*/
#ifndef ERROR_STATUS
    #define ERROR_STATUS  	           (1u)
#endif	
#ifndef OK_STATUS
    #define OK_STATUS   		       (0u)
#endif	
#ifndef PASS_STILL_TESTING_STATUS
    #define PASS_STILL_TESTING_STATUS  (2u) 
#endif
#ifndef PASS_COMPLETE_STATUS
    #define PASS_COMPLETE_STATUS       (3u) 
#endif


/* One bit error status flag for ECC flash test */
#define ONE_BIT_ERROR              (2u)


#endif /* SELFTEST_FLASH_H */


/* [] END OF FILE */

