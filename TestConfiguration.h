/*******************************************************************************
* File Name: TestConfiguration.h
* Version 1.0
*
* Description:
* This file provides defines to force artificial errors and to provoke detection   
* of defects by self tests for PSoC 3 and PSoC 5.
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

#if !defined(TESTCONFIGURATION_H)
    #define TESTCONFIGURATION_H


#define ERROR_IN_CPU_REGISTERS               0u
#define ERROR_IN_PROGRAM_COUNTER             0u
#define ERROR_IN_INTERRUPT_HANDLING          0u
#define ERROR_IN_CLOCK_1                     0u 
#define ERROR_IN_CLOCK_2                     0u 
#define ERROR_IN_FLASH                       0u /* ECC test needs special firmware */
#define ERROR_IN_EEPROM                      0u
#define ERROR_IN_SRAM_CHECKERBOARD           0u
#define ERROR_IN_STACK                       0u
#define ERROR_IN_DIGITAL_IO                  0u 
#define ERROR_IN_ADC                         0u
#define ERROR_IN_DAC                         0u 
#define ERROR_IN_COMPARATOR                  0u 
#define ERROR_IN_TIA                         0u 
#define ERROR_IN_PGA                         0u 
#define ERROR_IN_OPAMP                       0u 
#define ERROR_IN_UART                        0u 
#define ERROR_IN_SPI                         0u 
#define ERROR_IN_UDB_CONF_REG                0u
#define ERROR_IN_STARTUP_CONF_REG            1u
#define ERROR_IN_WATCH_DOC                   0u 
#define ERROR_IN_WINDOWED_WATCH_DOC          0u 

/* ERROR_IN_IRAM_MARCH - can be enabled in SelfTest_IRAM_March.a51 */

/* ERROR_IN_SRAM_MARCH - can be enabled in SelfTest_SRAM_March.a51 for PSoC 3 */
/* ERROR_IN_SRAM_MARCH - can be enabled in SelfTest_SRAM_March.s   for PSoC 5 */

#endif /* TESTCONFIGURATION_H */


/* [] END OF FILE */
