/*
 * File: Motor_Contl4_3.h
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

#ifndef RTW_HEADER_Motor_Contl4_3_h_
#define RTW_HEADER_Motor_Contl4_3_h_
#ifndef Motor_Contl4_3_COMMON_INCLUDES_
# define Motor_Contl4_3_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* Motor_Contl4_3_COMMON_INCLUDES_ */

#include "Motor_Contl4_3_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T Sum;                          /* '<S1>/Sum' */
  real_T Sum_n;                        /* '<S2>/Sum' */
  real_T Sum_m;                        /* '<S3>/Sum' */
  real_T Sum_i;                        /* '<S4>/Sum' */
} BlockIO_Motor_Contl4_3;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<S1>/Integrator1' */
  real_T Integrator1_CSTATE_h;         /* '<S2>/Integrator1' */
  real_T Integrator1_CSTATE_l;         /* '<S3>/Integrator1' */
  real_T Integrator1_CSTATE_g;         /* '<S4>/Integrator1' */
} ContinuousStates_Motor_Contl4_3;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<S1>/Integrator1' */
  real_T Integrator1_CSTATE_h;         /* '<S2>/Integrator1' */
  real_T Integrator1_CSTATE_l;         /* '<S3>/Integrator1' */
  real_T Integrator1_CSTATE_g;         /* '<S4>/Integrator1' */
} StateDerivatives_Motor_Contl4_3;

/* State disabled  */
typedef struct {
  boolean_T Integrator1_CSTATE;        /* '<S1>/Integrator1' */
  boolean_T Integrator1_CSTATE_h;      /* '<S2>/Integrator1' */
  boolean_T Integrator1_CSTATE_l;      /* '<S3>/Integrator1' */
  boolean_T Integrator1_CSTATE_g;      /* '<S4>/Integrator1' */
} StateDisabled_Motor_Contl4_3;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T Targetspeed1;                 /* '<Root>/Target speed1' */
  real_T RPM1;                         /* '<Root>/RPM1' */
  real_T Targetspeed2;                 /* '<Root>/Target speed2' */
  real_T RPM2;                         /* '<Root>/RPM2' */
  real_T Targetspeed3;                 /* '<Root>/Target speed3' */
  real_T RPM3;                         /* '<Root>/RPM3' */
  real_T Targetspeed4;                 /* '<Root>/Target speed4' */
  real_T RPM4;                         /* '<Root>/RPM4' */
} ExternalInputs_Motor_Contl4_3;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T PWMDuty1;                     /* '<Root>/PWM Duty1' */
  real_T VKmh1;                        /* '<Root>/V(Km//h)1' */
  real_T PWMDuty2;                     /* '<Root>/PWM Duty2' */
  real_T VKmh2;                        /* '<Root>/V(Km//h)2' */
  real_T PWMDuty3;                     /* '<Root>/PWM Duty3' */
  real_T VKmh3;                        /* '<Root>/V(Km//h)3' */
  real_T PWMDuty4;                     /* '<Root>/PWM Duty4' */
  real_T VKmh4;                        /* '<Root>/V(Km//h)4' */
} ExternalOutputs_Motor_Contl4_3;

/* Parameters (auto storage) */
struct Parameters_Motor_Contl4_3_ {
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<S1>/Integrator1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 18
                                        * Referenced by: '<S1>/Gain2'
                                        */
  real_T Gain_Gain;                    /* Expression: 3.2
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 19
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -19
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T Integrator1_IC_i;             /* Expression: 0
                                        * Referenced by: '<S2>/Integrator1'
                                        */
  real_T Gain2_Gain_a;                 /* Expression: 18
                                        * Referenced by: '<S2>/Gain2'
                                        */
  real_T Gain_Gain_a;                  /* Expression: 3.2
                                        * Referenced by: '<S2>/Gain'
                                        */
  real_T Saturation_UpperSat_o;        /* Expression: 19
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T Saturation_LowerSat_j;        /* Expression: -19
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T Integrator1_IC_p;             /* Expression: 0
                                        * Referenced by: '<S3>/Integrator1'
                                        */
  real_T Gain2_Gain_j;                 /* Expression: 18
                                        * Referenced by: '<S3>/Gain2'
                                        */
  real_T Gain_Gain_i;                  /* Expression: 3.2
                                        * Referenced by: '<S3>/Gain'
                                        */
  real_T Saturation_UpperSat_j;        /* Expression: 19
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Saturation_LowerSat_a;        /* Expression: -19
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Integrator1_IC_ik;            /* Expression: 0
                                        * Referenced by: '<S4>/Integrator1'
                                        */
  real_T Gain2_Gain_e;                 /* Expression: 18
                                        * Referenced by: '<S4>/Gain2'
                                        */
  real_T Gain_Gain_o;                  /* Expression: 3.2
                                        * Referenced by: '<S4>/Gain'
                                        */
  real_T Saturation_UpperSat_g;        /* Expression: 19
                                        * Referenced by: '<S4>/Saturation'
                                        */
  real_T Saturation_LowerSat_l;        /* Expression: -19
                                        * Referenced by: '<S4>/Saturation'
                                        */
};

/* Real-time Model Data Structure */
struct RT_MODEL_Motor_Contl4_3 {
  const char_T * volatile errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    real_T *contStates;
    real_T *derivs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeY[4];
    real_T odeF[3][4];
    ODE3_IntgData intgData;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern Parameters_Motor_Contl4_3 Motor_Contl4_3_P;

/* Block signals (auto storage) */
extern BlockIO_Motor_Contl4_3 Motor_Contl4_3_B;

/* Continuous states (auto storage) */
extern ContinuousStates_Motor_Contl4_3 Motor_Contl4_3_X;

/* External inputs (root inport signals with auto storage) */
extern ExternalInputs_Motor_Contl4_3 Motor_Contl4_3_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExternalOutputs_Motor_Contl4_3 Motor_Contl4_3_Y;

/* Model entry point functions */
extern void Motor_Contl4_3_initialize(void);
extern void Motor_Contl4_3_step(void);
extern void Motor_Contl4_3_terminate(void);

/* Real-time Model object */
extern struct RT_MODEL_Motor_Contl4_3 *const Motor_Contl4_3_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : Motor_Contl4_3
 * '<S1>'   : Motor_Contl4_3/motor_contl41
 * '<S2>'   : Motor_Contl4_3/motor_contl42
 * '<S3>'   : Motor_Contl4_3/motor_contl43
 * '<S4>'   : Motor_Contl4_3/motor_contl44
 */
#endif                                 /* RTW_HEADER_Motor_Contl4_3_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
