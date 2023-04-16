/*
 * File: Motor_Contl4_3_data.c
 *
 * Code generated for Simulink model 'Motor_Contl4_3'.
 *
 * Model version                  : 1.11
 * Simulink Coder version         : 8.0 (R2011a) 09-Mar-2011
 * TLC version                    : 8.0 (Feb  3 2011)
 * C/C++ source code generated on : Sun Oct 02 13:47:39 2011
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

//#define IGAIN	4.0		// ORG 5.0
#define PGAIN	1.0		// ORG 3.2
#define IGAIN	3.0		// ORG 5.0
#define SATUR	10.0	// ORG 19.0 
// 20131130 tune for re16 KS PI contl
//#define SATUR	19.0	// ORG 19.0 

#include "Motor_Contl4_3.h"
#include "Motor_Contl4_3_private.h"

/* Block parameters (auto storage) */
Parameters_Motor_Contl4_3 Motor_Contl4_3_P = {
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Integrator1'
                                        */
  IGAIN,                                /* Expression: 18
                                        * Referenced by: '<S1>/Gain2'
                                        */
  PGAIN,                                 /* Expression: 3.2
                                        * Referenced by: '<S1>/Gain'
                                        */
  SATUR,                                /* Expression: 19
                                        * Referenced by: '<S1>/Saturation'
                                        */
  -SATUR,                               /* Expression: -19
                                        * Referenced by: '<S1>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Integrator1'
                                        */
  IGAIN,                                /* Expression: 18
                                        * Referenced by: '<S2>/Gain2'
                                        */
  PGAIN,                                 /* Expression: 3.2
                                        * Referenced by: '<S2>/Gain'
                                        */
  SATUR,                                /* Expression: 19
                                        * Referenced by: '<S2>/Saturation'
                                        */
  -SATUR,                               /* Expression: -19
                                        * Referenced by: '<S2>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Integrator1'
                                        */
  IGAIN,                                /* Expression: 18
                                        * Referenced by: '<S3>/Gain2'
                                        */
  PGAIN,                                 /* Expression: 3.2
                                        * Referenced by: '<S3>/Gain'
                                        */
  SATUR,                                /* Expression: 19
                                        * Referenced by: '<S3>/Saturation'
                                        */
  -SATUR,                               /* Expression: -19
                                        * Referenced by: '<S3>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Integrator1'
                                        */
  IGAIN,                                /* Expression: 18
                                        * Referenced by: '<S4>/Gain2'
                                        */
  PGAIN,                                 /* Expression: 3.2
                                        * Referenced by: '<S4>/Gain'
                                        */
  SATUR,                                /* Expression: 19
                                        * Referenced by: '<S4>/Saturation'
                                        */
  -SATUR                                /* Expression: -19
                                        * Referenced by: '<S4>/Saturation'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
