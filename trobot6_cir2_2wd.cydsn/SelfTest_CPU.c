/*******************************************************************************
* File Name: SelfTest_CPU.c 
* Version 1.0
*
* Description:
* This file provides the source code for the CPU register self tests for 
* PSoC 3 and PSoC 5LP.
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
* significant injury to the user. The inclusion of Cypress product in a life*
support systems application implies that the manufacturer assumes all risk of
* such use and in doing so indemnifies Cypress against all charges. Use may be
* limited by and subject to the applicable Cypress software license agreement.
*******************************************************************************/

#include <device.h>
#include "SelfTest_CPU.h"
#include "SelfTest_CPU_asm.h"
#include "SelfTest_Flash.h"
#include "TestConfiguration.h"


static volatile uint8 SelfTestA;
static volatile uint16 SelfTestB;
static volatile uint32 SelfTestC;


/* definition of section for SelfTest_PC5555() and SelfTest_PCAAAA() functions 
   for GCC compiler */
#if defined(__GNUC__) || defined(__ARMCC_VERSION)
    static uint8 SelfTest_PC5555 (void) __attribute__ ((used, section ("PC5555")));
    static uint8 SelfTest_PCAAAA (void) __attribute__ ((used, section ("PCAAAA")));
#endif

static uint8 SelfTest_PC5555(void);
static uint8 SelfTest_PCAAAA(void);

/*******************************************************************************
* Function Name: SelfTest_CPU_RAM
********************************************************************************
*
* Summary: 
*  This function performs checkerboard test for all CPU registers except the PC 
*  register.
*
* Parameters:
*  None.
*                           
* Return:
*  Result of test:  "0" - pass test; "1" - fail test.
* 
**********************************************************************************/
uint8 SelfTest_CPU_Registers(void)
{	   
    #if defined(__C51__) || defined(__GNUC__)
        return CPU_PSoC_Asm();	
    #elif defined(__CC_ARM)
  	    return CPU_PSoC_5_Asm();	
    #else
        return ERROR_STATUS;
    #endif   
}


/*******************************************************************************
* Function Name: SelfTest_PC
********************************************************************************
*
* Summary: 
*  This function performs the test of the PC register. Function calls SelfTest_PC5555() 
*  and SelfTest_PCAAAA() which are placed at 0x5555 and 0xAAAA addresses
*  in flash for PSoC 3. And at 0x15555 and 0x0AAAA addresses in flash for PSoC 5.
*  These functions must return unique values to SelfTestA, SelfTestB and 
*  SelfTestC variables if PC is working correctly.
*
* Parameters:
*  None.
*                           
* Return:
*  Result of test:  "0" - pass test; "1" - fail test.
* 
**********************************************************************************/
uint8 SelfTest_PC(void)
{ 
    uint8 returned_value;

    /* Clear global variables for test */
    SelfTestA = 0x00u;
	SelfTestB = 0x0000u;
	SelfTestC = 0x00000000u;
	
    returned_value = SelfTest_PC5555();
    
	/* Check if SelfTest_PC5555() returned and wrote correct values to global variables*/
	if((SelfTestA == SELF_TEST_A_1) && (SelfTestB == SELF_TEST_B_1) && (SelfTestC == SELF_TEST_C_1) 
	   && (returned_value == CHECKERBOARD_PATTERN_55))
	{
    
        /* Clear global variables for next test */
	    SelfTestA = 0x00u;
	    SelfTestB = 0x0000u;
	    SelfTestC = 0x00000000u;
		
		returned_value = SelfTest_PCAAAA();
        
		/* Check if SelfTest_PCAAAA() returned and wrote correct values to global variables*/
		if((SelfTestA == SELF_TEST_A_2) && (SelfTestB == SELF_TEST_B_2) && (SelfTestC == SELF_TEST_C_2) 
		   && (returned_value == CHECKERBOARD_PATTERN_AA))
        {   
	        returned_value = OK_STATUS;
        }    
		else	
        {
		    returned_value = ERROR_STATUS;	
        }    
	}
	else
    {
	    returned_value = ERROR_STATUS;
	}
	return returned_value;	
}


/*******************************************************************************
* Function Name: SelfTest_PCAAAA
********************************************************************************
*
* Summary: 
*  This function performs a test for the PC register. Function is placed at 0xAAAA address
*  in flash for PSoC 3. And at 0x0AAAA address in flash for PSoC 5. This function
*  must return value 0xAA and write unique value to SelfTestA, SelfTestB and 
*  SelfTestC variables if PC is working correctly. Also this function executes a cycle 
*  loop for additional checking if the PC is working.
*
* Parameters:
*  None.
*                           
* Return:
*  SelfTestA:  write unique value to variable for this function SELF_TEST_A_2.
*  SelfTestB:  write unique value to variable for this function SELF_TEST_B_2.
*  SelfTestC:  write to unique value to variable for this function SELF_TEST_C_2.
*  Return unique value for this function CHECKERBOARD_PATTERN_AA.
*
**********************************************************************************/
static uint8 SelfTest_PCAAAA(void)
{

    SelfTestA = SELF_TEST_A_2;
      
	SelfTestB = SELF_TEST_B_2;
    
	SelfTestC = SELF_TEST_C_2;
	
    #if ERROR_IN_PROGRAM_COUNTER    
    	return (CHECKERBOARD_PATTERN_AA + 1u);
    #else    
        return CHECKERBOARD_PATTERN_AA;
    #endif    
}


/*******************************************************************************
* Function Name: SelfTest_PC5555
********************************************************************************
*
* Summary: 
*  This function performs a test for the PC register. Function is placed at 0x5555 address
*  in flash for PSoC 3. And at 0x15555 address in flash for PSoC 5. This function
*  must return value 0x55 and write unique value to SelfTestA, SelfTestB and 
*  SelfTestC variables if PC is working correctly. Also this function executes a cycle 
*  loop for additional checking if the PC is working.
*
* Parameters:
*  None.
*                           
* Return:
*  SelfTestA:  write unique value to variable for this function SELF_TEST_A_1.
*  SelfTestB:  write unique value to variable for this function SELF_TEST_B_1.
*  SelfTestC:  write unique value to variable for this function SELF_TEST_C_1.
*  Return unique value for this function CHECKERBOARD_PATTERN_55.
*
**********************************************************************************/
static uint8 SelfTest_PC5555(void)
{
	
    SelfTestA = SELF_TEST_A_1;
    	
	SelfTestB = SELF_TEST_B_1;
    
	SelfTestC = SELF_TEST_C_1;

    #if ERROR_IN_PROGRAM_COUNTER    
    	return (CHECKERBOARD_PATTERN_55 + 1u);
    #else    
        return CHECKERBOARD_PATTERN_55;
    #endif      
	
}


/* [] END OF FILE */

