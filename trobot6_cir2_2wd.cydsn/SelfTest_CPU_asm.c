/*******************************************************************************
* File Name: SelfTest_CPU_asm.c 
* Version 1.0
*
* Description:
* This file provides the source code for CPU register self tests for 
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
* significant injury to the user. The inclusion of CypressвЂ™ product in a life*
support systems application implies that the manufacturer assumes all risk of
* such use and in doing so indemnifies Cypress against all charges. Use may be
* limited by and subject to the applicable Cypress software license agreement.
*******************************************************************************/

#include <device.h>
#include <SelfTest_CPU_asm.h>
#include "TestConfiguration.h"


/* Declaration of return variable if PSoC 3 */
 #if defined(__C51__)	
    static uint8 data ret_flag = 0u;            
    
/* Declaration of return variable and defines if PSoC 5 */	
#elif defined(__GNUC__)
#define CPU_REGISTER_TEST(reg)         \
    "MOV   "reg", 0xAAAAAAAA  \n\t"    \
    "CMP   "reg", 0xAAAAAAAA  \n\t"    \
    "BNE   __test_asm_fail    \n\t"    \
    "MOV   "reg", 0x55555555  \n\t"    \
    "CMP   "reg", 0x55555555  \n\t"    \
    "BNE   __test_asm_fail    \n\t"
	
#define CPU_REGISTER_TEST_ERROR(reg)   \
    "MOV   "reg", 0xAAAAAAAA  \n\t"    \
    "ADD   "reg", "reg", 0x01 \n\t"    \
    "CMP   "reg", 0xAAAAAAAA  \n\t"    \
    "BNE   __test_asm_fail    \n\t"    \
    "MOV   "reg", 0x55555555  \n\t"    \
    "CMP   "reg", 0x55555555  \n\t"    \
    "BNE   __test_asm_fail    \n\t"    
    
#endif

/*****************************************************************************
* Function Name: CPU_PSoC_Asm
******************************************************************************
* Summary:
*  This function performs checkerboard test for all CPU registers for PSoC 3 
*  and PSoC 5 except PC register.
*
* Parameters:
*  None.
*
* Return:
*  0 - No error
*  Not 0 - Error detected
*
* Note:
*  This API is C compiler dependent.
*
*****************************************************************************/

#if defined(__C51__)
    uint8 CPU_PSoC_Asm(void)                            /* declaration of function if PSoC 3 */
    {    
#elif defined(__GNUC__)
    __attribute__((naked)) uint8 CPU_PSoC_Asm(void)      /* declaration of function if PSoC 5 GCC compiler */
    {    
#endif  

    /* assembler code for PSoC 3 */
    #if defined(__C51__)	                            
	
		/* Disable global interrupts */
    	CyGlobalIntDisable;    
	
        #pragma asm
        push ACC
        
        /* Pushing R0 into Stack */
        push 00h         
        
        /* Accumulator check */
        mov A, #55h
        
        #if ERROR_IN_CPU_REGISTERS    
            inc A
        #endif  
        
        cjne A, #55h, LABEL_CPU_FAILURE
        
        mov A, #0AAh
        cjne A, #0AAh, LABEL_CPU_FAILURE    
        
        /* Checking the R0 register, which will be used for looping through the Internal RAM locations */
        rl A
        xch A, R0
        xch A, R0
        cjne A, #55h, LABEL_CPU_FAILURE
       
        rl A
        xch A, R0
        xch A, R0
        cjne A, #0AAh, LABEL_CPU_FAILURE
           
        
        /* Moving the IDATA SIZE into R0 for looping through the locations */
        mov R0, #IRAM_SIZE
        
        /* Checking each locations using @R0 addressing */
        IRAM_chk: 
        
        rl A
        xch A, @R0
        xch A, @R0
        cjne A, #55h, LABEL_CPU_FAILURE
        
        rl A
        xch A, @R0
        xch A, @R0
        cjne A, #0AAh, LABEL_CPU_FAILURE
        
        /* Checking for end of IRAM (255 to 1) as 0th location is R0 itself which has been checked already */
        djnz R0, IRAM_chk
        
        /* If control reaches till here then all the CPU registers are fine */
        mov ret_flag, CPU_OK 
        jmp end_of_CPU_test
        
        /* CPU failure  */
        LABEL_CPU_FAILURE:
        mov ret_flag, #CPU_FAILURE
        jmp end_of_CPU_test
        
        end_of_CPU_test:
        
        /* Popping out R0 and Accumulator in the order they were pushed */
        pop 00h
        pop ACC
        
    	#pragma endasm
        
    	/* Enable global interrupts */
    	CyGlobalIntEnable;         
        
        /* Return with the result to the calling function */
        return ret_flag;
    }
    /* enf of assembler code for PSoC 3 */

    /* assembler code for PSoC 5 */
    #elif defined(__GNUC__) 
	
		/* Disable global interrupts */
    	CyGlobalIntDisable;    
		
        __ASM volatile (
            "     PUSH  {R1-R12, LR}          \n\t"
            CPU_REGISTER_TEST("R0")          
            #if (ERROR_IN_CPU_REGISTERS)
                CPU_REGISTER_TEST_ERROR("R1")
            #else    
                CPU_REGISTER_TEST("R1")
            #endif  
            CPU_REGISTER_TEST("R2")
            CPU_REGISTER_TEST("R3")
            CPU_REGISTER_TEST("R4")
            CPU_REGISTER_TEST("R5")
            CPU_REGISTER_TEST("R6")
            CPU_REGISTER_TEST("R7")
            CPU_REGISTER_TEST("R8")
            CPU_REGISTER_TEST("R9")
            CPU_REGISTER_TEST("R10")
            CPU_REGISTER_TEST("R11")
            CPU_REGISTER_TEST("R12")
            CPU_REGISTER_TEST("LR")
            
            /* Test SP register */
            /*   Note: SP ignores writes to the lower two bits, 
                       so they are intentionally set to 0 */
                       
            /* Save SP to R0 */           
            "    MOV   R0, SP              \n\t" 
            
            /* Load SP with 0xAAAAAAA8 */
            "    LDR   R1, =0xAAAAAAA8     \n\t" 
            "    MOV   SP, R1              \n\t" 
            "    CMP   SP, R1              \n\t"
            
            /* Restore SP and return failure */
            "    IT    NE                  \n\t" 
            "        MOVNE SP, R0          \n\t"
            "        BNE   __test_asm_fail \n\t"
            
            /* Load SP with 0x55555554 */
            "    LDR   R1, =0x55555554     \n\t" 
            "    MOV   SP, R1              \n\t"
            "    CMP   SP, R1              \n\t"
            "    IT    NE                  \n\t"
            "        MOVNE SP, R0          \n\t"
            "        BNE   __test_asm_fail \n\t"
            "    MOV   SP, R0              \n\t"
            
            /* Return success */
            "    MOV   R0, #0              \n\t" 
            "    POP   {R1-R12, LR}        \n\t"
            "    BX    LR                  \n\t"
            
            /* Return failure */
            "__test_asm_fail:              \n\t"
            "    MOV   R0, 0x00000001      \n\t"
            "    POP   {R1-R12, LR}        \n\t"
            "    BX    LR                  \n\t");
           
    		/* Enable global interrupts */
    		CyGlobalIntEnable;            
           
    /* end of assembler code for PSoC 5 */  
    }
#endif    


/* [] END OF FILE */

