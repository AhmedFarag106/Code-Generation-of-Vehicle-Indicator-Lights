/*
 * File: controller_ca.h
 *
 * Abstract: Tests assumptions in the generated code.
 */

#ifndef CONTROLLER_CA_H
#define CONTROLLER_CA_H

/* preprocessor validation checks */
#include "controller_ca_preproc.h"
#include "coder_assumptions_hwimpl.h"

/* variables holding test results */
extern CA_HWImpl_TestResults CA_controller_HWRes;
extern CA_PWS_TestResults CA_controller_PWSRes;

/* variables holding "expected" and "actual" hardware implementation */
extern const CA_HWImpl CA_controller_ExpHW;
extern CA_HWImpl CA_controller_ActHW;

/* entry point function to run tests */
void controller_caRunTests(void);

#endif                                 /* CONTROLLER_CA_H */
