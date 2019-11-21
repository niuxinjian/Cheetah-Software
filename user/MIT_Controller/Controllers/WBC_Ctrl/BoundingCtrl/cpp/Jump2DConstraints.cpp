//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: Jump2DConstraints.cpp
//
// MATLAB Coder version            : 3.2
// C/C++ source code generated on  : 26-Aug-2019 18:20:14
//

// Include Files
#include "rt_nonfinite.h"
#include "Jump2DBounds.h"
#include "Jump2DConstraintJacobian.h"
#include "Jump2DConstraintJacobianFinal.h"
#include "Jump2DConstraintJacobianFinalSP.h"
#include "Jump2DConstraintJacobianInitial.h"
#include "Jump2DConstraintJacobianInitialSP.h"
#include "Jump2DConstraintJacobianSP.h"
#include "Jump2DConstraints.h"
#include "Jump2DConstraintsFinal.h"
#include "Jump2DConstraintsInitial.h"
#include "Jump2DCost.h"
#include "Jump2DCostGradient.h"
#include "Jump2DInitialize.h"
#include "Jump2DLagrangianHessian.h"
#include "Jump2DLagrangianHessianFinal.h"
#include "Jump2DLagrangianHessianFinalSP.h"
#include "Jump2DLagrangianHessianInitial.h"
#include "Jump2DLagrangianHessianInitialSP.h"
#include "Jump2DLagrangianHessianSP.h"

// Function Definitions

//
// JUMP2DCONSTRAINTS
//     CONSTRAINTS = JUMP2DCONSTRAINTS(IN1,IN2,IN3,IN4,DT,IN6,M,IYY,G,MU_G)
// Arguments    : const double in1[6]
//                const double in2[4]
//                const double in3[6]
//                const double in4[2]
//                double dt
//                const double in6[4]
//                double m
//                double Iyy
//                double g
//                double mu_g
//                double constraints[10]
// Return Type  : void
//
void Jump2DConstraints(const double in1[6], const double in2[4], const double
  in3[6], const double in4[2], double dt, const double in6[4], double m, double
  Iyy, double g, double mu_g, double constraints[10])
{
  double t2;
  double t3;
  double t6;
  double t9;
  double t10;
  double t17;

  //     This function was generated by the Symbolic Math Toolbox version 7.1.
  //     26-Aug-2019 18:15:40
  t2 = dt * dt;
  t3 = 1.0 / m;
  t6 = in2[2] * in4[1] + in2[0] * in4[0];
  t9 = in2[3] * in4[1] + in2[1] * in4[0];
  t10 = 1.0 / Iyy;
  t17 = in4[1] * (in2[2] * in6[3] - in2[3] * in6[2]) + in4[0] * (in2[0] * in6[1]
    - in2[1] * in6[0]);
  constraints[0] = ((in1[0] - in3[0]) - dt * in3[3]) - t2 * t3 * t6 * 0.5;
  constraints[1] = (((in1[1] - in3[1]) - dt * in3[4]) - g * t2 * 0.5) - t2 * t3 *
    t9 * 0.5;
  constraints[2] = ((in1[2] - in3[2]) - in3[5] * dt) - t2 * t10 * t17 * 0.5;
  constraints[3] = (in1[3] - in3[3]) - dt * t3 * t6;
  constraints[4] = ((in1[4] - in3[4]) - dt * g) - dt * t3 * t9;
  constraints[5] = (in1[5] - in3[5]) - dt * t10 * t17;
  constraints[6] = -in2[1] * in4[0] * (mu_g - 1.0);
  constraints[7] = -in2[1] * in4[0] * (mu_g + 1.0);
  constraints[8] = -in2[3] * in4[1] * (mu_g - 1.0);
  constraints[9] = -in2[3] * in4[1] * (mu_g + 1.0);
}

//
// File trailer for Jump2DConstraints.cpp
//
// [EOF]
//
