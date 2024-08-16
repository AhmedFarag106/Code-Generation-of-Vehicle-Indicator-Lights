/*
 * File: controller.h
 *
 * Code generated for Simulink model 'controller'.
 *
 * Model version                  : 1.85
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Aug 14 17:31:37 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_controller_h_
#define RTW_HEADER_controller_h_
#ifndef controller_COMMON_INCLUDES_
#define controller_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* controller_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<Root>/controller' */
typedef struct {
  int32_T clockTickCounter;            /* '<S4>/Pulse Generator' */
  int32_T clockTickCounter_b;          /* '<S3>/Pulse Generator' */
} DW_controller;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  DW_controller controller_ek;         /* '<Root>/controller' */
  boolean_T Merge;                     /* '<S1>/Merge' */
  boolean_T Merge1;                    /* '<S1>/Merge1' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  boolean_T button1_B;                 /* '<Root>/button1_B' */
  boolean_T button2_B;                 /* '<Root>/button2_B' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  boolean_T led1_B;                    /* '<Root>/led1_B' */
  boolean_T led2_B;                    /* '<Root>/led2_B' */
  int8_T leds_state;                   /* '<Root>/leds_state' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void controller_initialize(void);
extern void controller_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S3>/Constant1' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('model/controller')    - opens subsystem model/controller
 * hilite_system('model/controller/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'model'
 * '<S1>'   : 'model/controller'
 * '<S2>'   : 'model/controller/Hold both leds'
 * '<S3>'   : 'model/controller/Toggle led1'
 * '<S4>'   : 'model/controller/Toggle led2'
 * '<S5>'   : 'model/controller/Truth Table'
 * '<S6>'   : 'model/controller/Turn off both leds'
 */
#endif                                 /* RTW_HEADER_controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
