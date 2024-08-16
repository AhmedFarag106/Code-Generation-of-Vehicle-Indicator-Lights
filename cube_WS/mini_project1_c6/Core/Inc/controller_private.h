/*
 * File: controller_private.h
 *
 * Code generated for Simulink model 'controller'.
 *
 * Model version                  : 1.39
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed May 22 18:59:17 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_controller_private_h_
#define RTW_HEADER_controller_private_h_
#include "rtwtypes.h"
#include "controller.h"
#include "controller_types.h"

extern void controller_Init(boolean_T *rty_led1_B, boolean_T *rty_led2_B);
extern void controller_e(boolean_T rtu_button1_B, boolean_T rtu_button2_B,
  boolean_T *rty_led1_B, boolean_T *rty_led2_B, real_T *rty_leds_state,
  DW_controller *localDW);

#endif                                 /* RTW_HEADER_controller_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
