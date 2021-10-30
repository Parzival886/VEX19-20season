/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       vex.h                                                     */
/*    Author:       Vex Robotics                                              */
/*    Created:      1 Feb 2019                                                */
/*    Description:  Default header for V5 projects                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/
//
#ifndef VEX_H
#define VEX_H
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

#include "v5.h"
#include "v5_vcs.h"

#include "robot-config.h"

enum competitionSide{
  BLUELEFT,
  BLUERIGHT,
  REDLEFT,
  REDRIGHT
};

  /**
  * @brief 使用左右速度直接控制底盘
  * @param vl：指定左侧的电机速度
  * @param vr：指定右侧的电机速度
  */
void diPan(int vl,int vr);



  /**
  * @brief  停止底盘，防止往前滑行,自动中使用
  */
void diPanStop();

void myRemoteControl();
void myAuto();

void setSuctionSpeed(float speed);
void setRiseSpeed(float speed);
void setPushSpeed(float speed);



  /**
  * @brief 前进指定度数
  * @param Motor4Encoder：用于计算角度的马达
  * @param speed：速度
  * @param degree: 度数
  */
void forwardDegree(motor Motor4Encoder,float speed,float degree);

  /**
  * @brief 前进指定毫秒数
  * @param speed：速度
  * @param tMsec: 毫秒数
  */
void forwardMilliSecond(float speed,float tMsec);

  /**
  * @brief 惯性传感器校准，使用之前调用
  * @param InertialDefault：惯性传感器（例如 Inertial20）
  */
void inertialInit(inertial InertialDefault);

  /**
  * @brief 陀螺仪传感器校准，使用之前调用
  * @param InertialDefault：陀螺仪传感器（例如 GyroG）
  */
void gyroInit(gyro gyroDefault);

void pidTurn(inertial InertialDefault, double degree, double seconds);

void pidTurn(gyro gyroDefault, double degree, double seconds);

#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)

#endif