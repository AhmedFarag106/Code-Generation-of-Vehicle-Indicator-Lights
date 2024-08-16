/*
 * File: controller.c
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

#include "controller.h"
#include "rtwtypes.h"
#include "controller_private.h"
#include "main.h"

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* System initialize for atomic system: '<Root>/controller' */
void controller_Init(boolean_T *rty_led1_B, boolean_T *rty_led2_B)
{
  /* SystemInitialize for Merge: '<S1>/Merge' */
  *rty_led1_B = false;

  /* SystemInitialize for Merge: '<S1>/Merge1' */
  *rty_led2_B = false;
}

/* Output and update for atomic system: '<Root>/controller' */
void controller_e(boolean_T rtu_button1_B, boolean_T rtu_button2_B, boolean_T
                  *rty_led1_B, boolean_T *rty_led2_B, real_T *rty_leds_state,
                  DW_controller *localDW)
{
  boolean_T b;
  boolean_T b_tmp;
  boolean_T c;
  boolean_T c_tmp;
  boolean_T d;
  boolean_T tmp;
  boolean_T tmp_0;

  /* Truth Table: '<S1>/Truth Table' */
  /*  Button1 is pressed */
  b_tmp = !rtu_button2_B;
  b = (rtu_button1_B && b_tmp);

  /*  Button2 is pressed */
  c_tmp = !rtu_button1_B;
  c = (rtu_button2_B && c_tmp);

  /*  Both buttons are pressed */
  d = (rtu_button2_B && rtu_button1_B);

  /*  No pressed buttons */
  b_tmp = (b_tmp && c_tmp);
  c_tmp = !d;
  tmp = !b_tmp;
  tmp_0 = !c;
  if (b && tmp_0 && c_tmp && tmp) {
    /*  Toggle led1 */
    *rty_leds_state = 1.0;
  } else {
    b = !b;
    if (b && c && c_tmp && tmp) {
      /*  Toggle led2 */
      *rty_leds_state = 2.0;
    } else {
      tmp_0 = (b && tmp_0);
      if (tmp_0 && d && tmp) {
        /*  Hold both led */
        *rty_leds_state = 3.0;
      } else if (tmp_0 && c_tmp && b_tmp) {
        /*  Turn both leds off */
        *rty_leds_state = 4.0;
      } else {
        /*  Default */
        /*  Turn both leds off */
        *rty_leds_state = 4.0;
      }
    }
  }

  /* End of Truth Table: '<S1>/Truth Table' */

  /* SwitchCase: '<S1>/Switch Case' */
  switch ((int32_T)*rty_leds_state) {
   case 1:
    {
      int32_T rtb_PulseGenerator_k;

      /* Outputs for IfAction SubSystem: '<S1>/Toggle led1' incorporates:
       *  ActionPort: '<S3>/Action Port'
       */
      /* DiscretePulseGenerator: '<S3>/Pulse Generator' */
      rtb_PulseGenerator_k = ((localDW->clockTickCounter_b < 25) &&
        (localDW->clockTickCounter_b >= 0));
      if (localDW->clockTickCounter_b >= 49) {
        localDW->clockTickCounter_b = 0;
      } else {
        localDW->clockTickCounter_b++;
      }

      /* End of DiscretePulseGenerator: '<S3>/Pulse Generator' */

      /* DataTypeConversion: '<S3>/Data Type Conversion' */
      *rty_led1_B = (rtb_PulseGenerator_k != 0);

      /* SignalConversion generated from: '<S3>/led2_B' incorporates:
       *  Constant: '<S3>/Constant'
       */
      *rty_led2_B = false;

      /* End of Outputs for SubSystem: '<S1>/Toggle led1' */
    }
    break;

   case 2:
    {
      int32_T rtb_PulseGenerator_k;

      /* Outputs for IfAction SubSystem: '<S1>/Toggle led2' incorporates:
       *  ActionPort: '<S4>/Action Port'
       */
      /* SignalConversion generated from: '<S4>/led1_B' incorporates:
       *  Constant: '<S4>/Constant'
       */
      *rty_led1_B = false;

      /* DiscretePulseGenerator: '<S4>/Pulse Generator' */
      rtb_PulseGenerator_k = ((localDW->clockTickCounter < 25) &&
        (localDW->clockTickCounter >= 0));
      if (localDW->clockTickCounter >= 49) {
        localDW->clockTickCounter = 0;
      } else {
        localDW->clockTickCounter++;
      }

      /* End of DiscretePulseGenerator: '<S4>/Pulse Generator' */

      /* DataTypeConversion: '<S4>/Data Type Conversion' */
      *rty_led2_B = (rtb_PulseGenerator_k != 0);

      /* End of Outputs for SubSystem: '<S1>/Toggle led2' */
    }
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S1>/Hold both leds' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* SignalConversion generated from: '<S2>/led1_B' incorporates:
     *  Constant: '<S2>/Constant1'
     */
    *rty_led1_B = true;

    /* SignalConversion generated from: '<S2>/led2_B' incorporates:
     *  Constant: '<S2>/Constant'
     */
    *rty_led2_B = true;

    /* End of Outputs for SubSystem: '<S1>/Hold both leds' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S1>/turn of both leds' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    /* SignalConversion generated from: '<S6>/led1_B' incorporates:
     *  Constant: '<S6>/Constant'
     */
    *rty_led1_B = false;

    /* SignalConversion generated from: '<S6>/led2_B' incorporates:
     *  Constant: '<S6>/Constant1'
     */
    *rty_led2_B = false;

    /* End of Outputs for SubSystem: '<S1>/turn of both leds' */
    break;
  }

  /* End of SwitchCase: '<S1>/Switch Case' */
}

/* Model step function */
void controller_step(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/controller' */

  /* Inport: '<Root>/button1_B' incorporates:
   *  Inport: '<Root>/button2_B'
   *  Outport: '<Root>/leds_state'
   */

	if (HAL_GPIO_ReadPin(button1_GPIO_Port, button1_Pin) == 0)
	{
		rtU.button1_B = false;
	}
	else rtU.button1_B = true;

	if (HAL_GPIO_ReadPin(button2_GPIO_Port, button2_Pin) == 0)
	{
		rtU.button2_B = false;
	}
	else rtU.button2_B = true;

	controller_e(rtU.button1_B, rtU.button2_B, &rtDW.Merge, &rtDW.Merge1,
               &rtY.leds_state, &rtDW.controller_ek);

  /* End of Outputs for SubSystem: '<Root>/controller' */

  /* Outport: '<Root>/led1_B' */
  rtY.led1_B = rtDW.Merge;

  /* Outport: '<Root>/led2_B' */
  rtY.led2_B = rtDW.Merge1;
  if (rtY.led1_B == true) HAL_GPIO_WritePin(led1_GPIO_Port, led1_Pin, GPIO_PIN_SET);
  else  HAL_GPIO_WritePin(led1_GPIO_Port, led1_Pin, GPIO_PIN_RESET);

  if (rtY.led2_B == true) HAL_GPIO_WritePin(led2_GPIO_Port, led2_Pin, GPIO_PIN_SET);
  else  HAL_GPIO_WritePin(led2_GPIO_Port, led2_Pin, GPIO_PIN_RESET);

}

/* Model initialize function */
void controller_initialize(void)
{
  /* SystemInitialize for Atomic SubSystem: '<Root>/controller' */
  controller_Init(&rtDW.Merge, &rtDW.Merge1);

  /* End of SystemInitialize for SubSystem: '<Root>/controller' */

  /* SystemInitialize for Outport: '<Root>/led1_B' incorporates:
   *  Merge: '<S1>/Merge'
   */
  rtY.led1_B = rtDW.Merge;

  /* SystemInitialize for Outport: '<Root>/led2_B' incorporates:
   *  Merge: '<S1>/Merge1'
   */
  rtY.led2_B = rtDW.Merge1;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
