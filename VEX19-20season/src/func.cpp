#include "vex.h"
timer t1;


  /**
  * @brief  使用左右速度直接控制底盘，需要根据各自的机器修改控制左右侧所有的电机(例如MotorLeft.spin(forward,vl,percent);)四电机底盘若名称一致，则直接去掉斜杠即可
  * @param vl：指定左侧的电机速度
  * @param vr：指定右侧的电机速度
  */
void diPan(int vl,int vr)
{
  MotorLB.spin(forward,vl,percent);
  MotorLF.spin(forward,vl,percent);
  MotorRB.spin(forward,vr,percent);
  MotorRF.spin(forward,vr,percent);
}

  /**
  * @brief  停止底盘，防止往前滑行,自动中使用,四电机底盘若名称一致，则直接去掉斜杠即可
  */
void diPanStop()
{
  MotorLB.stop(hold);
  MotorLF.stop(hold);
  MotorRB.stop(hold);
  MotorRF.stop(hold);
  wait(50,msec);
  MotorLB.stop(coast);
  MotorLF.stop(coast);
  MotorRB.stop(coast);
  MotorRF.stop(coast);
}

void setSuctionSpeed(float speed)
{
  MotorSuctionL.spin(forward,speed,pct);
  MotorSuctionR.spin(forward,speed,pct);
}

void setRiseSpeed(float speed)
{
  MotorRise.spin(forward,speed,pct);
}

void setPushSpeed(float speed)
{
  MotorPush.spin(forward,speed,pct);
}



void inertialInit(inertial InertialDefault)
{
  InertialDefault.calibrate();
  waitUntil(!InertialDefault.isCalibrating());
}

  /**
  * @brief 陀螺仪传感器校准，使用之前调用
  * @param InertialDefault：陀螺仪传感器（例如 GyroG）
  */
void gyroInit(gyro gyroDefault)
{
  gyroDefault.calibrate();
  waitUntil(!gyroDefault.isCalibrating());
}


  /**
  * @brief 前进指定度数
  * @param Motor4Encoder：用于计算角度的马达
  * @param speed：速度
  * @param degree: 度数
  */
void forwardDegree(motor Motor4Encoder,float speed,float degree)
{
  Motor4Encoder.resetPosition();
  while(fabs(degree)>fabs(Motor4Encoder.position(degrees)))
    diPan(speed, speed);
  diPanStop();
}

  /**
  * @brief 前进指定毫秒数
  * @param speed：速度
  * @param tMsec: 毫秒数
  */
void forwardMilliSecond(float speed,float tMsec)
{
  diPan(speed, speed);
  wait(tMsec, msec);
  diPanStop();
}




static double kp=1.0,ki=0.0000000000,kd=0.0;
static double error=0.0,i=0.0,d=0.0,lastError=0.0;
static double targetDegree;
static double delta;



int pidTurnCalc()
{
  while(1)
  {
    error =targetDegree- GyroB.rotation();
    i = i + error;
    d = error - lastError;
  }
}


void pidTurn(gyro gyroDefault, double degree, double seconds)
{
  double speedDefault = 120;
  t1.reset();
  targetDegree = degree;
  double degreeBegin = gyroDefault.rotation();
  delta = targetDegree - degreeBegin;
  float _kp = 0.9;
  if(fabs(degree)>100)
    _kp = 0.8;
  kp = _kp+(delta-90)/90.0*_kp;
  kd = 0.5 + delta/10.0;
  error=delta,i=0.0,d=0.0,lastError=0.0;
  double k;
  double speed;  
  task taskPidCalc=task(pidTurnCalc);
  taskPidCalc.resume();
  while(t1.time(sec)< seconds )
  {
    k = (kp*error + ki*i + kd*d)/delta;
    speed= speedDefault*k;
    diPan(speed, -speed);
    lastError = error;
  }
  taskPidCalc.suspend();
  diPanStop();
}


void pidTurn(inertial InertialDefault, double degree, double seconds)
{
  double speedDefault = 120;
  t1.reset();
  targetDegree = degree;
  double degreeBegin = InertialDefault.rotation();
  delta = targetDegree - degreeBegin;
  float _kp = 0.9;
  if(fabs(degree)>100)
    _kp = 0.8;
  kp = _kp+(delta-90)/90.0*_kp;
  kd = 0.5 + delta/10.0;
  error=delta,i=0.0,d=0.0,lastError=0.0;
  double k;
  double speed;  
  task taskPidCalc=task(pidTurnCalc);
  taskPidCalc.resume();
  while(t1.time(sec)< seconds )
  {
    k = (kp*error + ki*i + kd*d)/delta;
    speed= speedDefault*k;
    diPan(speed, -speed);
    lastError = error;
  }
  taskPidCalc.suspend();
  diPanStop();
}

