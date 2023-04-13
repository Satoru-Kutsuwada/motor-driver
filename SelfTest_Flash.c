/*******************************************************************************
* File Name: SelfTest_Flash.c 
* Version 1.0
*
* Description:
* This file provides the source code for ROM self tests for PSoC 3 and PSoC 5LP.
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
#include "SelfTest_Flash.h"
#include "SelfTest_CPU.h"
#include "TestConfiguration.h"


/* If ECC is disabled */
#if (CYDEV_ECC_ENABLE == 0)

    /* Include custom "write to Flash" function, because Creator functions don't work with ECC */
    #include "SelfTest_CustomFlash.h"
#endif


/* If ECC is disabled */
#if (CYDEV_ECC_ENABLE == 0)

/* If PSoC 3 */
#if defined(__C51__)

	/* Allocate the last two bytes in Flash for flash checksum for PSoC 3 */
    /* Size of flash is 0x10000, address of byte befor the last one is 0xFFFE */
    #pragma asm 
        CSEG AT 0xFFFE
        DW   0x866D
    #pragma endasm 

/* If PSoC 5LP */
#else

	#if defined(__GNUC__)

		/* Allocate the last two bytes in Flash for flash checksum for PSoC 5LP */
    	/* Section CheckSum set to address 0x0003FFFE in linker file custom_cm3gcc */
    	/* Fragment from the file   */
    	/* NV_CONFIG3 0x0003FFFE :  */
    	/* {                        */
    	/* . = 0x00;                */
    	/* *(CheckSum);             */
    	/* } >rom =0                */
    	const uint16 CheckSum_from_rom __attribute__ ((used, section("CheckSum"))) = 0xBEAF;
	#elif defined(__CC_ARM)
		
		/* Allocate the last 2 bytes in flash for checksum. (ARM MDK and RVDS compilers) */
		const uint32 CheckSum_from_rom __attribute__ ((at(0x0003FFFC))) = 0xBEAF0000;
	#endif
	
#endif   

    /* Variable that stores the running checksum of the ROM */
    /* Variable enabled when PSoC 5LP or PSoC 3 and ECC disabled */
    static uint16 checkSum_rom = 0x0000;   
#endif



/*******************************************************************************
* Function Name: SelfTest_FlashECC()
********************************************************************************
*
* Summary: 
*  This function checks for data corruption in flash memory using hardware ECC.
*  Function works only for PSoC 3. PSoC 5 ES1 doesn't support ECC.
*
* Parameters:
*  None.
*                           
* Return:
*  Result of test:  "0" - no error detected; "1" - 1 bit error detected;
*                   "2" - 2 bit error detected.
* 
**********************************************************************************/

/* ECC enabled */
#if (CYDEV_ECC_ENABLE == 1)	
    uint8 SelfTest_FlashECC(void)
    {

		uint8 ret = OK_STATUS;
        
		/* If PSoC 3 */
        #if defined(__C51__)
		
            uint16 ecc_status;
        
            /* Read the status registers for ECC interrupts. Refer to the Register Reference manual for more details on registers */
            ecc_status = CY_GET_REG16(CYREG_CACHE_INT_LOG3);
        
                /* If bit is set, a 1-bit Error has been detected and corrected */
            if(ecc_status & 0x0001u)
			{
                ret = ONE_BIT_ERROR;
			}
			else
			{
    		
            	/* Read the status registers for ECC interrupts. Refer to the Register Reference manual for more details
                	on registers */		
            	ecc_status = CY_GET_REG16(CYREG_CACHE_INT_LOG4);
        
            	/* If bit is set, a 2-bit Error has been detected but not corrected */
            	if(ecc_status & 0x0001u)
				{
                	ret = ERROR_STATUS;
				}
			}
			
        /* If PSoC 5LP */    
        #elif defined(__GNUC__) || defined(__CC_ARM) || defined(__ARMCC_VERSION)
		
			uint32 ecc_status;
        
            /* Read the status registers for ECC interrupts. Refer to the Register Reference manual for more details on registers */
            ecc_status = CY_GET_REG32(CYREG_CACHE_ECC_CORR);
        
            /* If bit is set, a 1-bit Error has been detected and corrected */
            if(ecc_status & 0x00000001u)
			{
                
				/* Clear ECC correction bit */
				CY_SET_REG32(CYREG_CACHE_ECC_CORR, ~0x00000001u);
				ret = ONE_BIT_ERROR;
			}
			else
			{
    		
            	/* Read the status registers for ECC interrupts. Refer to the Register Reference manual for more details
                	on registers */		
            	ecc_status = CY_GET_REG32(CYREG_CACHE_ECC_ERR);
        
            	/* If bit is set, a 2-bit Error has been detected but not corrected */
            	if(ecc_status & 0x00000001u)
				{
                
					/* Clear ECC error bit */
					CY_SET_REG32(CYREG_CACHE_ECC_ERR, ~0x00000001u);
					ret = ERROR_STATUS;
				}
			}
		
		#endif
           
    	return ret;    
    }
    

/* If ECC disabled */
#elif (CYDEV_ECC_ENABLE == 0)  
    /*******************************************************************************
    * Function Name: SelfTest_FlashCheckSum()
    ********************************************************************************
    *
    * Summary: 
    *  This function checks for data corruption in flash memory using a checksum calculation.
    *  This function is used for PSoC 5 ES1 because it doesn't support ECC.
    *  SelfTest_FlashCheckSum_Init() must be called one time before this function to 
    *  store flash checksum in to EEPROM after first device start.0
    *
    * Parameters:
    *  None.
    *                           
    * Return:
    *  Result of test:   "1" - fail test; "2" - Test in progress; "3" - Test completed OK;
    * 
    **********************************************************************************/
    
	/* If PSoC 3 */
    #if defined(__C51__)	
    
        /* For PSoC 3 needs 16-bits for Flash addressing */
        uint8 SelfTest_FlashCheckSum(uint16 WordsToTest)
        
    /* If PSoC 5LP */    
    #elif defined(__GNUC__) || defined(__CC_ARM) || defined(__ARMCC_VERSION)
    
        /* For PSoC 5LP needs 32-bits for Flash addressing */ 
        uint8 SelfTest_FlashCheckSum(uint32 WordsToTest)
    #endif        
    {

        /* Set pointer to access Flash memory to base address */                
        static uint8 CYCODE *Flash_Pointer = (uint32)CYDEV_FLS_BASE; 
        
        /* End address of current tested block */
        uint32 EndAdressOfTest;
		
		/* return result */
		uint8 ret = ERROR_STATUS;
        
        /* Check if intentional error should be made for testing */  
        #if (ERROR_IN_FLASH)
        
            static uint8 FlashErrorSemaphore = 0u;
            
            #if (CYDEV_ECC_ENABLE == 0u)
                uint8 FlashrowData[SIZEOF_FLASH_ROW + SIZEOF_ECC_ROW];
            #else    
                uint8 FlashrowData[SIZEOF_FLASH_ROW];
            #endif
            
            uint16 i;
            
            /* Number of flash block where artificial error will be made */
            uint8 crashblock = 1u;  
        
            /* Pointer to access Flash  */ 
            uint8 CYCODE *flash = CYDEV_FLS_BASE;;               
            
        #endif
           
               
       /* Check if Flash byte address is in Flash range */
        if( Flash_Pointer < (uint32)CYDEV_FLS_BASE)
        {
            Flash_Pointer = (uint32)CYDEV_FLS_BASE;
        }               
               
        /* Calculate end address of current tested block */
        EndAdressOfTest = (uint32)(PSOC_FLS_BASE + (uint32)Flash_Pointer + (uint32)(2u * (uint32)WordsToTest)); 
        
        /* Check if end address of current tested block is not out of Flash range */
        if( EndAdressOfTest > (uint32)(PSOC_FLS_BASE + PSOC_FLASH_SIZE))
        {
        
            /* If yes - set end address of current block to last permitted byte in Flash */
            EndAdressOfTest = (uint32)(PSOC_FLS_BASE + PSOC_FLASH_SIZE);
        }

      
        /* Disable global interrupts */
        CyGlobalIntDisable;       
        
        /* Calculating checksum for all bytes in Flash block */
        for(Flash_Pointer = Flash_Pointer; (uint32)Flash_Pointer < (uint32)EndAdressOfTest; Flash_Pointer++)
        {        
        
            /* Accumulating the ROM data into the checkSum_rom variable and incrementing the ROM pointer */
            checkSum_rom = checkSum_rom + *Flash_Pointer;    
            
        } 
        
        #if (ERROR_IN_FLASH)
        
            /* Use semaphore to flag flash corruption */
            if(FlashErrorSemaphore == 0u)
            {
            
                /* Change semaphore */
                FlashErrorSemaphore++;
                
                CyFlash_Start();
                (cystatus)CySetTemp(); 
                            
                /* Save configuration registers for one block */
                for(i = 0u; i < SIZEOF_FLASH_ROW; i++)
                {
                
                    /* Store UDB configuration registers to UDBrowData array */
                    FlashrowData[i] = *(flash + (crashblock * SIZEOF_FLASH_ROW) + i);
                }   
                
                /* Set index to last byte in array */
                i--;
                
                /* Make error in last byte of array */
                FlashrowData[i] = FlashrowData[i] + 1u;
                
                /* Write UDBrowData array to flash block number (UDB_REG_FIRST_BLOCK + iblock) */

                #if (CYDEV_ECC_ENABLE == 0)
                    if(CyMyWriteRowData(FIRST_FLASH_ARRAYID, crashblock, FlashrowData))
                #else    
                    if(CyWriteRowData(FIRST_FLASH_ARRAYID, crashblock, FlashrowData))
                #endif
                {
                
                    /* Error detected during write block to flash */
                    return ERROR_STATUS;
                }
            }
        #endif        
        
        /* Enable global interrupts */
        CyGlobalIntEnable; 
       
       /* If PSoC 3 */ 
        #if defined(__C51__)	
        
            /* Check if we are in the last permitted byte of Flash */        
            if(Flash_Pointer != (PSOC_FLS_BASE + PSOC_FLASH_SIZE))
            
        /* If PSoC 5LP */     
        #elif defined(__GNUC__) || defined(__CC_ARM) || defined(__ARMCC_VERSION)
        
            /* Check if we are in the last permitted byte of Flash */          
            if(Flash_Pointer != (uint8 *)(PSOC_FLS_BASE + PSOC_FLASH_SIZE))
        #endif          
            {
                 
                /* If it is not last permitted byte of Flash */ 
                /* End of check sum calculation for current block of flash */
                /* Return status that the test still going */
        	    ret = PASS_STILL_TESTING_STATUS;       
            }
            else
            {              
            
                /* If it is last permitted byte of Flash - Flash check sum is calculated */ 
                /* Need to compare the stored check sum and calculated check sum  */
                
                /* If PSoC 3 */ 
                #if defined(__C51__)	
                
                    /* Compare the stored check sum and calculated check sum */                
                    if(checkSum_rom == (*((uint16 code *)Flash_Pointer)))
                    
                /* If PSoC 5LP */                     
                #else
					#if defined(__GNUC__) 
                
                    /* Compare the stored check sum and calculated check sum */                
                    if (checkSum_rom == CheckSum_from_rom)
					
					#elif defined(__CC_ARM)
					
					/* Compare the stored check sum and calculated check sum */                
                    if (checkSum_rom == (CheckSum_from_rom >> 16))
					
					#endif
                #endif                               
                    {                
                        
                        /* If check sums are the same, need to reset test parameters and return OK status */
                                               
                        /* Set pointer to access Flash memory to base address */  
                        Flash_Pointer = (uint32)CYDEV_FLS_BASE; 
                        
                        /* Reset checkSum_rom variable */
                        checkSum_rom = 0x0000u; 
                        
                        /* Return PASS status */
            	        ret = PASS_COMPLETE_STATUS;       
                    }
                    else
                    {       
                    
                        /* If check sums are not the same, need to reset test parameters and return ERROR status */                    
                    
                        /* Set pointer to access Flash memory to base address */  
                        Flash_Pointer = (uint32)CYDEV_FLS_BASE; 
                        
                        /* Reset checkSum_rom variable */
                        checkSum_rom = 0x0000u; 
                        
                        /* Return ERROR status */
                        ret = ERROR_STATUS;
                    }       
            }               
            
        /* If something in the performance of the code went wrong */    
        /* Return ERROR status */    
        return ret;    
    }


#endif 


/* [] END OF FILE */

