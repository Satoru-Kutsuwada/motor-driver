/*
 * File: Motor_Contl4_3.c
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

#include "Motor_Contl4_3.h"
#include "Motor_Contl4_3_private.h"
#include "project.h"
//#include <stdlib.h>
//#include <stdio.h>
//#include <math.h>
//#include <string.h>
//#include <device.h>

typedef enum{
    CRLF_NONE,
    CRLF_ON,
    CRLF_ONLY,
} CRLF;

extern void sk_PutString03(char8 *string,uint16 data,CRLF flg,uint8 kata);
extern void sk_pwm_debug(uint8 flg,real_T dt0,real_T dt1,real_T dt2,real_T dt3);
extern void sk_PutString_realT(char8 *string,real_T data,CRLF flg);
extern void sk_mt_ctrl(uint16 flg);

/* Block signals (auto storage) */
BlockIO_Motor_Contl4_3 Motor_Contl4_3_B;

/* Continuous states */
ContinuousStates_Motor_Contl4_3 Motor_Contl4_3_X;

/* External inputs (root inport signals with auto storage) */
ExternalInputs_Motor_Contl4_3 Motor_Contl4_3_U;

/* External outputs (root outports fed by signals with auto storage) */
ExternalOutputs_Motor_Contl4_3 Motor_Contl4_3_Y;

/* Real-time model */
RT_MODEL_Motor_Contl4_3 Motor_Contl4_3_M_;
RT_MODEL_Motor_Contl4_3 *const Motor_Contl4_3_M = &Motor_Contl4_3_M_;


extern float rpm2velo_ratio;



//**********************************************************************
//
// This function updates continuous states using the ODE3 fixed-step
// solver algorithm
//
//**********************************************************************
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
    /* Solver Matrices */
    static const real_T rt_ODE3_A[3] = {
        1.0/2.0, 3.0/4.0, 1.0
    };

    static const real_T rt_ODE3_B[3][3] = {
        { 1.0/2.0,     0.0,     0.0 },

        {     0.0, 3.0/4.0,     0.0 },

        { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
    };

    //  #define rtsiGetT(S)       (*((S)->tPtr))[0]
    //  t= *Motor_Contl4_3_M->solverInfo->tPtr[0];
    time_T t = rtsiGetT(si);        
    
    // #define rtsiGetSolverStopTime(S)    (S)->solverStopTime
    // tnew = *Motor_Contl4_3_M->solverInfo->solverStopTime
    time_T tnew = rtsiGetSolverStopTime(si);  
    
    // #define rtsiGetStepSize(S)        *((S)->stepSizePtr)
    // h = *Motor_Contl4_3_M->solverInfo->stepSizePtr
    time_T h = rtsiGetStepSize(si);     
    
    // #define rtsiGetContStates(S)       *((S)->contStatesPtr)
    // x = *Motor_Contl4_3_M->solverInfo->contStatesPtr
    real_T *x = rtsiGetContStates(si);  
    
    // #define rtsiGetSolverData(S)    (S)->solverData
    // id = *Motor_Contl4_3_M->solverInfo->solverData
    // ODE3 Integration Data 
    //      typedef struct {
    //         real_T *y;                           /* output */
    //         real_T *f[3];                        /* derivatives */
    //     } ODE3_IntgData;


    ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si); 
    
    
    real_T *y = id->y;
    real_T *f0 = id->f[0];
    real_T *f1 = id->f[1];
    real_T *f2 = id->f[2];
    real_T hB[3];
    int_T i;
    int_T nXc = 4;
    
    real_T dt[4];
    
    
    sk_mt_ctrl(10);
    
    // #define rtsiSetSimTimeStep(S,st)     (*((S)->simTimeStepPtr) = (st))
    // *Motor_Contl4_3_M->solverInfo.simTimeStepPtr = MINOR_TIME_STEP;
    rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

    /* Save the state values at time t in y, we'll use x as ynew. */
    (void) memcpy(y, x, nXc*sizeof(real_T));

    /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
    /* f0 = f(t,y) */
    // #define rtsiSetdX(S,dx)     (*((S)->dXPtr) = (dx))
    // Motor_Contl4_3_M->solverInfo->dXPtr) = f0
    
    rtsiSetdX(si, f0);
    Motor_Contl4_3_derivatives();
    

    // f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
    //
    //  hb[0] = 0.03125, h=0.0625, rt_ODE3_B[0][0]=0.5
    
    hB[0] = h * rt_ODE3_B[0][0];
    
    // sk_pwm_debug(4,hB[0], h, rt_ODE3_B[0][0],0);
    
    //=========================================================
    // 偏差の積分を計算1
    // x[0] = Motor_Contl4_3_X.Integrator1_CSTATE;       
    // x[1] = Motor_Contl4_3_X.Integrator1_CSTATE_h;
    // x[2] = Motor_Contl4_3_X.Integrator1_CSTATE_l;
    // x[3] = Motor_Contl4_3_X.Integrator1_CSTATE_g;
    //=========================================================    
    for (i = 0; i < nXc; i++) {
        x[i] = y[i] + (f0[i]*hB[0]);
        sk_pwm_debug(5,x[i], y[i],f0[i],hB[0]);
    }
    
    
    // 
    // dt[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
    
    
    // #define rtsiSetT(S,t)     ((*((S)->tPtr))[0] = (t))
    // Motor_Contl4_3_M->solverInfo->tPtr))[0] =  t + h*rt_ODE3_A[0]
    rtsiSetT(si, t + h*rt_ODE3_A[0]);
    
    // #define rtsiSetdX(S,dx)     (*((S)->dXPtr) = (dx))
    // Motor_Contl4_3_M->solverInfo->dXPtr =  f1;

    rtsiSetdX(si, f1);
    sk_mt_ctrl(11);
    Motor_Contl4_3_step();
    Motor_Contl4_3_derivatives();

    /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
    for (i = 0; i <= 1; i++) {
        hB[i] = h * rt_ODE3_B[1][i];
        
    }
    sk_pwm_debug(7,hB[0],rt_ODE3_B[1][0],hB[1],rt_ODE3_B[1][1]);
    


    
    //=========================================================
    // 偏差の積分を計算2
    // x[0] = Motor_Contl4_3_X.Integrator1_CSTATE;       
    // x[1] = Motor_Contl4_3_X.Integrator1_CSTATE_h;
    // x[2] = Motor_Contl4_3_X.Integrator1_CSTATE_l;
    // x[3] = Motor_Contl4_3_X.Integrator1_CSTATE_g;
    //=========================================================
    
    for (i = 0; i < nXc; i++) {
        x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
        sk_pwm_debug(6,x[i], y[i],f0[i],f1[i]);
    }

        
        
    // #define rtsiSetT(S,t)     ((*((S)->tPtr))[0] = (t))
    // Motor_Contl4_3_M->solverInfo->tPtr[0] = t + h*rt_ODE3_A[1]
    // 
    rtsiSetT(si, t + h*rt_ODE3_A[1]);
    
    // #define rtsiSetdX(S,dx)     (*((S)->dXPtr) = (dx))
    // Motor_Contl4_3_M->solverInfo->dXPtr = f2
    //
    rtsiSetdX(si, f2);
    sk_mt_ctrl(12);
    Motor_Contl4_3_step();
    Motor_Contl4_3_derivatives();

    /* tnew = t + hA(3);
    ynew = y + f*hB(:,3); */
    for (i = 0; i <= 2; i++) {
        hB[i] = h * rt_ODE3_B[2][i];
    }

    //=========================================================
    // 偏差の積分を計算3
    // x[0] = Motor_Contl4_3_X.Integrator1_CSTATE;       
    // x[1] = Motor_Contl4_3_X.Integrator1_CSTATE_h;
    // x[2] = Motor_Contl4_3_X.Integrator1_CSTATE_l;
    // x[3] = Motor_Contl4_3_X.Integrator1_CSTATE_g;
    //=========================================================
    for (i = 0; i < nXc; i++) {
        x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
    }

    rtsiSetT(si, tnew);
    rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
     sk_mt_ctrl(12);
}

//====================================================================
//
//
//
//
//====================================================================
/* Model step function */
void Motor_Contl4_3_step(void)
{
    real_T rtb_Sum2;
    real_T u;

    sk_mt_ctrl(1);
    
    if (rtmIsMajorTimeStep(Motor_Contl4_3_M)) {
        sk_mt_ctrl(2);
        /* set solver stop time */
        
        // #define rtsiSetSolverStopTime(S,st) ((S)->solverStopTime = (st))
        // Motor_Contl4_3_M->solverInfo->solverStopTime = (Motor_Contl4_3_M->Timing.clockTick0+1)*Motor_Contl4_3_M->Timing.stepSize0;
        rtsiSetSolverStopTime(&Motor_Contl4_3_M->solverInfo,
            ((Motor_Contl4_3_M->Timing.clockTick0+1)*Motor_Contl4_3_M->Timing.stepSize0));
    }                                    /* end MajorTimeStep */

    /* Update absolute time of base rate at minor time step */
    if (rtmIsMinorTimeStep(Motor_Contl4_3_M)) {
        // #define rtsiGetT(S)       (*((S)->tPtr))[0]
        // Motor_Contl4_3_M->Timing.t[0] = Motor_Contl4_3_M->solverInfo->tPtr))[0];
        Motor_Contl4_3_M->Timing.t[0] = rtsiGetT(&Motor_Contl4_3_M->solverInfo);
        sk_mt_ctrl(3);
    }

    
    
    //***************************************************/
    // Fcn: '<S1>/Fcn' incorporates:
    // Inport: '<Root>/RPM1'
    //    rpm2velo_ratio = 0.025
    //**************************************************/
    rtb_Sum2 = Motor_Contl4_3_U.RPM1 * rpm2velo_ratio;
    
    // rtb_Sum2 = Motor_Contl4_3_U.RPM1 * 0.00033108163; //GP26A
    //  rtb_Sum2 = Motor_Contl4_3_U.RPM1 * 0.00044679337; //GP26B
    // motorRPM => velosity(Km/h)
    // = 60/gire_ratio/1000*Dwhell*pi 
    // =0.000812456 @gire_ratio = 29, Dwheel = 0.125
    // =0.000280487 @gire_ratio = 84, Dwheel = 0.125 
    // =0.00044679337 @gire_ratio = 3375.0/64(GP26B), Dwheel = 0.125 
    // =0.00033108163 @gire_ratio = 226233/3179(GP26A), Dwheel = 0.125 
    // Sum: '<S1>/Sum' incorporates:
    // Inport: '<Root>/Target speed1'
    //
    
    Motor_Contl4_3_B.Sum = Motor_Contl4_3_U.Targetspeed1 - rtb_Sum2;
    
    

    // Saturate: '<S1>/Saturation' incorporates:
    //  Gain: '<S1>/Gain'
    //  Gain: '<S1>/Gain2'
    //  Integrator: '<S1>/Integrator1'
    //  Sum: '<S1>/Sum2'
    //
    
    u = Motor_Contl4_3_P.Gain2_Gain * Motor_Contl4_3_X.Integrator1_CSTATE + Motor_Contl4_3_P.Gain_Gain * Motor_Contl4_3_B.Sum;



    /* Outport: '<Root>/PWM Duty1' incorporates:
    *  Saturate: '<S1>/Saturation'
    */
    Motor_Contl4_3_Y.PWMDuty1 = u >= Motor_Contl4_3_P.Saturation_UpperSat ?
    Motor_Contl4_3_P.Saturation_UpperSat : u <=Motor_Contl4_3_P.Saturation_LowerSat ? 
    Motor_Contl4_3_P.Saturation_LowerSat : u;

    //
    // debug log
    //  Motor_Contl4_3_P.Gain2_Gain = 6   I
    //  Motor_Contl4_3_P.Gain_Gain  = 3   P
    //
    
    sk_pwm_debug(1,
        rtb_Sum2,
        Motor_Contl4_3_U.RPM1,
        Motor_Contl4_3_B.Sum,
        Motor_Contl4_3_U.Targetspeed1 );
    
    sk_pwm_debug(3,
        u,
        Motor_Contl4_3_X.Integrator1_CSTATE,
        Motor_Contl4_3_Y.PWMDuty1,
        0 );
  


    /* Outport: '<Root>/V(Km//h)1' */
    Motor_Contl4_3_Y.VKmh1 = rtb_Sum2;

    /***************************************************/
    /* Fcn: '<S2>/Fcn' incorporates:
    *  Inport: '<Root>/RPM2'
    */
    /***************************************************/

    rtb_Sum2 = Motor_Contl4_3_U.RPM2 * rpm2velo_ratio;


    /* Sum: '<S2>/Sum' incorporates:
    *  Inport: '<Root>/Target speed2'
    */
    Motor_Contl4_3_B.Sum_n = Motor_Contl4_3_U.Targetspeed2 - rtb_Sum2;

    /* Saturate: '<S2>/Saturation' incorporates:
    *  Gain: '<S2>/Gain'
    *  Gain: '<S2>/Gain2'
    *  Integrator: '<S2>/Integrator1'
    *  Sum: '<S2>/Sum2'
    */
    u = Motor_Contl4_3_P.Gain2_Gain_a * Motor_Contl4_3_X.Integrator1_CSTATE_h +
    Motor_Contl4_3_P.Gain_Gain_a * Motor_Contl4_3_B.Sum_n;

    /* Outport: '<Root>/PWM Duty2' incorporates:
    *  Saturate: '<S2>/Saturation'
    */
    Motor_Contl4_3_Y.PWMDuty2 = u >= Motor_Contl4_3_P.Saturation_UpperSat_o ?
    Motor_Contl4_3_P.Saturation_UpperSat_o : u <= Motor_Contl4_3_P.Saturation_LowerSat_j ?
    Motor_Contl4_3_P.Saturation_LowerSat_j : u;

    /* Outport: '<Root>/V(Km//h)2' */
    Motor_Contl4_3_Y.VKmh2 = rtb_Sum2;

    
    
    /***************************************************/
    /* Fcn: '<S3>/Fcn' incorporates:
    *  Inport: '<Root>/RPM3'
    */
    /***************************************************/
    rtb_Sum2 = Motor_Contl4_3_U.RPM3 * rpm2velo_ratio;


    /* Sum: '<S3>/Sum' incorporates:
    *  Inport: '<Root>/Target speed3'
    */
    Motor_Contl4_3_B.Sum_m = Motor_Contl4_3_U.Targetspeed3 - rtb_Sum2;

    /* Saturate: '<S3>/Saturation' incorporates:
    *  Gain: '<S3>/Gain'
    *  Gain: '<S3>/Gain2'
    *  Integrator: '<S3>/Integrator1'
    *  Sum: '<S3>/Sum2'
    */
    u = Motor_Contl4_3_P.Gain2_Gain_j * Motor_Contl4_3_X.Integrator1_CSTATE_l +
    Motor_Contl4_3_P.Gain_Gain_i * Motor_Contl4_3_B.Sum_m;

    /* Outport: '<Root>/PWM Duty3' incorporates:
    *  Saturate: '<S3>/Saturation'
    */
    Motor_Contl4_3_Y.PWMDuty3 = u >= Motor_Contl4_3_P.Saturation_UpperSat_j ?
    Motor_Contl4_3_P.Saturation_UpperSat_j : u <= Motor_Contl4_3_P.Saturation_LowerSat_a ?
    Motor_Contl4_3_P.Saturation_LowerSat_a : u;

    /* Outport: '<Root>/V(Km//h)3' */
    Motor_Contl4_3_Y.VKmh3 = rtb_Sum2;

    
    

    /***************************************************/
    /* Fcn: '<S4>/Fcn' incorporates:
    *  Inport: '<Root>/RPM4'
    */
    /***************************************************/

    rtb_Sum2 = Motor_Contl4_3_U.RPM4 * rpm2velo_ratio;


    /* Sum: '<S4>/Sum' incorporates:
    *  Inport: '<Root>/Target speed4'
    */
    Motor_Contl4_3_B.Sum_i = Motor_Contl4_3_U.Targetspeed4 - rtb_Sum2;

    /* Saturate: '<S4>/Saturation' incorporates:
    *  Gain: '<S4>/Gain'
    *  Gain: '<S4>/Gain2'
    *  Integrator: '<S4>/Integrator1'
    *  Sum: '<S4>/Sum2'
    */
    u = Motor_Contl4_3_P.Gain2_Gain_e * Motor_Contl4_3_X.Integrator1_CSTATE_g +
    Motor_Contl4_3_P.Gain_Gain_o * Motor_Contl4_3_B.Sum_i;

    /* Outport: '<Root>/PWM Duty4' incorporates:
    *  Saturate: '<S4>/Saturation'
    */
    Motor_Contl4_3_Y.PWMDuty4 = u >= Motor_Contl4_3_P.Saturation_UpperSat_g ?
    Motor_Contl4_3_P.Saturation_UpperSat_g : u <= Motor_Contl4_3_P.Saturation_LowerSat_l ?
    Motor_Contl4_3_P.Saturation_LowerSat_l : u;

    /* Outport: '<Root>/V(Km//h)4' */
    Motor_Contl4_3_Y.VKmh4 = rtb_Sum2;

    
    

    /***************************************************/
sk_mt_ctrl(4);
    if (rtmIsMajorTimeStep(Motor_Contl4_3_M)) {
sk_mt_ctrl(5);
        
        rt_ertODEUpdateContinuousStates(&Motor_Contl4_3_M->solverInfo);
        /* Update absolute time for base rate */
        /* The "clockTick0" counts the number of times the code of this task has
        * been executed. The absolute time is the multiplication of "clockTick0"
        * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
        * overflow during the application lifespan selected.
        */

        ++Motor_Contl4_3_M->Timing.clockTick0;
        
        // #define rtsiGetSolverStopTime(S)    (S)->solverStopTime
        // Motor_Contl4_3_M->Timing.t[0] = Motor_Contl4_3_M->solverInfo->solverStopTime;
        Motor_Contl4_3_M->Timing.t[0] = rtsiGetSolverStopTime(&Motor_Contl4_3_M->solverInfo);


        {
            /* Update absolute timer for sample time: [0.0625s, 0.0s] */
            /* The "clockTick1" counts the number of times the code of this task has
            * been executed. The resolution of this integer timer is 0.0625, which is the step size
            * of the task. Size of "clockTick1" ensures timer will not overflow during the
            * application lifespan selected.
            */
            Motor_Contl4_3_M->Timing.clockTick1++;
        }
    }                                    /* end MajorTimeStep */
}

//====================================================================
//
//
//
//
//====================================================================

/* Derivatives for root system: '<Root>' */
void Motor_Contl4_3_derivatives(void)
{
    
    
  /* Derivatives for Integrator: '<S1>/Integrator1' */
    if( Motor_Contl4_3_Y.PWMDuty1  >= Motor_Contl4_3_P.Saturation_UpperSat){
        ((StateDerivatives_Motor_Contl4_3 *) Motor_Contl4_3_M->ModelData.derivs)
            ->Integrator1_CSTATE = 0;       
    } else if( Motor_Contl4_3_Y.PWMDuty1  <= Motor_Contl4_3_P.Saturation_LowerSat){
        ((StateDerivatives_Motor_Contl4_3 *) Motor_Contl4_3_M->ModelData.derivs)
            ->Integrator1_CSTATE = 0;       
    } else {
        ((StateDerivatives_Motor_Contl4_3 *) Motor_Contl4_3_M->ModelData.derivs)
            ->Integrator1_CSTATE = Motor_Contl4_3_B.Sum;
    }
    
  /* Derivatives for Integrator: '<S2>/Integrator1' */
    if( Motor_Contl4_3_Y.PWMDuty2  >= Motor_Contl4_3_P.Saturation_UpperSat_o){
        ((StateDerivatives_Motor_Contl4_3 *) Motor_Contl4_3_M->ModelData.derivs)
            ->Integrator1_CSTATE_h = 0;       
    } else if( Motor_Contl4_3_Y.PWMDuty2  <= Motor_Contl4_3_P.Saturation_LowerSat_j){
        ((StateDerivatives_Motor_Contl4_3 *) Motor_Contl4_3_M->ModelData.derivs)
            ->Integrator1_CSTATE_h = 0;       
    } else {
        ((StateDerivatives_Motor_Contl4_3 *) Motor_Contl4_3_M->ModelData.derivs)
            ->Integrator1_CSTATE_h = Motor_Contl4_3_B.Sum_n;
    }
    
  sk_pwm_debug(2, 
     ((StateDerivatives_Motor_Contl4_3 *) Motor_Contl4_3_M->ModelData.derivs)->Integrator1_CSTATE,
    Motor_Contl4_3_B.Sum,
    ((StateDerivatives_Motor_Contl4_3 *) Motor_Contl4_3_M->ModelData.derivs)->Integrator1_CSTATE_h,
    Motor_Contl4_3_B.Sum_n);


   
  /* Derivatives for Integrator: '<S3>/Integrator1' */
     if( Motor_Contl4_3_Y.PWMDuty3  >= Motor_Contl4_3_P.Saturation_UpperSat_j){
        ((StateDerivatives_Motor_Contl4_3 *) Motor_Contl4_3_M->ModelData.derivs)
            ->Integrator1_CSTATE_l = 0;       
    } else if( Motor_Contl4_3_Y.PWMDuty3  <= Motor_Contl4_3_P.Saturation_LowerSat_a){
        ((StateDerivatives_Motor_Contl4_3 *) Motor_Contl4_3_M->ModelData.derivs)
            ->Integrator1_CSTATE_l = 0;       
    } else {
        ((StateDerivatives_Motor_Contl4_3 *) Motor_Contl4_3_M->ModelData.derivs)
    		->Integrator1_CSTATE_l = Motor_Contl4_3_B.Sum_m;
    }
  

    
  /* Derivatives for Integrator: '<S2>/Integrator1' */
    if( Motor_Contl4_3_Y.PWMDuty4  >= Motor_Contl4_3_P.Saturation_UpperSat_g){
        ((StateDerivatives_Motor_Contl4_3 *) Motor_Contl4_3_M->ModelData.derivs)
            ->Integrator1_CSTATE_g = 0;       
    } else if( Motor_Contl4_3_Y.PWMDuty4  <= Motor_Contl4_3_P.Saturation_LowerSat_l){
        ((StateDerivatives_Motor_Contl4_3 *) Motor_Contl4_3_M->ModelData.derivs)
            ->Integrator1_CSTATE_g = 0;       
    } else {
          ((StateDerivatives_Motor_Contl4_3 *) Motor_Contl4_3_M->ModelData.derivs)
    		->Integrator1_CSTATE_g = Motor_Contl4_3_B.Sum_i;

    }
  
  /* Derivatives for Integrator: '<S4>/Integrator1' */
}

//====================================================================
//
//
//
//
//====================================================================

/* Model initialize function */
void Motor_Contl4_3_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Motor_Contl4_3_M, 0, sizeof(RT_MODEL_Motor_Contl4_3));

    {
        /* Setup solver object */
        
        // #define rtsiSetSimTimeStepPtr(S,stp) ((S)->simTimeStepPtr = (stp))
        // Motor_Contl4_3_M->solverInfo->simTimeStepPtr = &Motor_Contl4_3_M->Timing.simTimeStep;
        
        rtsiSetSimTimeStepPtr(&Motor_Contl4_3_M->solverInfo,&Motor_Contl4_3_M->Timing.simTimeStep);
      
        // #define rtsiSetStepSizePtr(S,ssp) ((S)->stepSizePtr = (ssp))
        // # define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
        // Motor_Contl4_3_M->solverInfo->stepSizePtr = &Motor_Contl4_3_M->Timing.t;
        rtsiSetTPtr(&Motor_Contl4_3_M->solverInfo, &rtmGetTPtr(Motor_Contl4_3_M));
        
        // #define rtsiSetStepSizePtr(S,ssp) ((S)->stepSizePtr = (ssp))
        // Motor_Contl4_3_M->solverInfo->stepSizePtr = &Motor_Contl4_3_M->Timing.stepSize0;
        rtsiSetStepSizePtr(&Motor_Contl4_3_M->solverInfo, &Motor_Contl4_3_M->Timing.stepSize0);
        
        // #define rtsiSetdXPtr(S,dxp) ((S)->dXPtr = (dxp))
        // Motor_Contl4_3_M->solverInfo->dXPtr = &Motor_Contl4_3_M->ModelData.derivs;
        rtsiSetdXPtr(&Motor_Contl4_3_M->solverInfo, &Motor_Contl4_3_M->ModelData.derivs);
        
        // #define rtsiSetContStatesPtr(S,cp) ((S)->contStatesPtr = (cp))
        // Motor_Contl4_3_M->solverInfo->contStatesPtr = &Motor_Contl4_3_M->ModelData.contStates;
        rtsiSetContStatesPtr(&Motor_Contl4_3_M->solverInfo,&Motor_Contl4_3_M->ModelData.contStates);   // contStates ptr set
        
        // #define rtsiSetNumContStatesPtr(S,cp) ((S)->numContStatesPtr = (cp))
        // Motor_Contl4_3_M->solverInfo->numContStatesPtr = &Motor_Contl4_3_M->Sizes.numContStates;
        
        rtsiSetNumContStatesPtr(&Motor_Contl4_3_M->solverInfo, &Motor_Contl4_3_M->Sizes.numContStates);
        
        // #define rtsiSetErrorStatusPtr(S,esp) ((S)->errStatusPtr = (esp))
        // Motor_Contl4_3_M->solverInfo->errStatusPtr = &Motor_Contl4_3_M->errorStatus;
        
        rtsiSetErrorStatusPtr(&Motor_Contl4_3_M->solverInfo, 
                        ((const char_T **)(&rtmGetErrorStatus(Motor_Contl4_3_M))));
        
        // #define rtsiSetRTModelPtr(S,rtmp) ((S)->rtModelPtr = (rtmp))
        // Motor_Contl4_3_M->solverInfo->rtModelPtr = Motor_Contl4_3_M;
        
        rtsiSetRTModelPtr(&Motor_Contl4_3_M->solverInfo, Motor_Contl4_3_M);
    }

    // #define rtsiSetSimTimeStepPtr(S,stp) ((S)->simTimeStepPtr = (stp))
    // Motor_Contl4_3_M->solverInfo->simTimeStepPtr = MAJOR_TIME_STEP;
    rtsiSetSimTimeStep(&Motor_Contl4_3_M->solverInfo, MAJOR_TIME_STEP);

    Motor_Contl4_3_M->ModelData.intgData.y = Motor_Contl4_3_M->ModelData.odeY;
    Motor_Contl4_3_M->ModelData.intgData.f[0] = Motor_Contl4_3_M->ModelData.odeF[0];
    Motor_Contl4_3_M->ModelData.intgData.f[1] = Motor_Contl4_3_M->ModelData.odeF[1];
    Motor_Contl4_3_M->ModelData.intgData.f[2] = Motor_Contl4_3_M->ModelData.odeF[2];
    Motor_Contl4_3_M->ModelData.contStates = ((real_T *) &Motor_Contl4_3_X);                //  Motor_Contl4_3_X ptr set


    // #define rtsiSetSolverData(S,sd) ((S)->solverData = (sd))
    // Motor_Contl4_3_M->solverInfo->solverData = (void *)&Motor_Contl4_3_M->ModelData.intgData;
    rtsiSetSolverData(&Motor_Contl4_3_M->solverInfo, (void *)&Motor_Contl4_3_M->ModelData.intgData);
    
    // #define rtsiSetSolverName(S,sn) ((S)->solverName = (sn))
    // Motor_Contl4_3_M->solverInfo->solverName = "ode3";
    rtsiSetSolverName(&Motor_Contl4_3_M->solverInfo,"ode3");
    
    // # define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
    // Motor_Contl4_3_M->Timing.t = &Motor_Contl4_3_M->Timing.tArray[0];
    rtmSetTPtr(Motor_Contl4_3_M, &Motor_Contl4_3_M->Timing.tArray[0]);
    Motor_Contl4_3_M->Timing.stepSize0 = 0.0625;

    
    
    /* block I/O */
    (void) memset((void *)&Motor_Contl4_3_B, 0,sizeof(BlockIO_Motor_Contl4_3));

    /* states (continuous) */
    {
        (void) memset((void *)&Motor_Contl4_3_X, 0,sizeof(ContinuousStates_Motor_Contl4_3));
    }

    /* external inputs */
    (void) memset((void *)&Motor_Contl4_3_U, 0,sizeof(ExternalInputs_Motor_Contl4_3));

    /* external outputs */
    (void) memset((void *)&Motor_Contl4_3_Y, 0,sizeof(ExternalOutputs_Motor_Contl4_3));
    
    

    /* InitializeConditions for Integrator: '<S1>/Integrator1' */
    Motor_Contl4_3_X.Integrator1_CSTATE = Motor_Contl4_3_P.Integrator1_IC;


    /* InitializeConditions for Integrator: '<S2>/Integrator1' */
    Motor_Contl4_3_X.Integrator1_CSTATE_h = Motor_Contl4_3_P.Integrator1_IC_i;


    /* InitializeConditions for Integrator: '<S3>/Integrator1' */
    Motor_Contl4_3_X.Integrator1_CSTATE_l = Motor_Contl4_3_P.Integrator1_IC_p;


    /* InitializeConditions for Integrator: '<S4>/Integrator1' */
    Motor_Contl4_3_X.Integrator1_CSTATE_g = Motor_Contl4_3_P.Integrator1_IC_ik;

}

//====================================================================
//
//
//
//
//====================================================================

/* Model terminate function */
void Motor_Contl4_3_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
