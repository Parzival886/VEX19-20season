/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// MotorLF              motor         16              
// MotorRF              motor         18              
// MotorLB              motor         13              
// MotorRB              motor         15              
// MotorSuctionL        motor         2               
// MotorSuctionR        motor         10              
// MotorRise            motor         12              
// MotorPush            motor         11              
// LimitSwitchA         limit         A               
// Inertial21           inertial      21              
// GyroB                gyro          B               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "ui.h"

using namespace vex;
competitionSide sideFlag;

competition Competition;
ui _ui;
task taskScreenPress = task(_tPressDetect);


void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  MotorPush.setBrake(hold);
  gyroInit(GyroB);
  Controller1.Screen.setCursor(1, 0);
  Controller1.Screen.print("inertial init sucess");
  //创建界面
  _ui = ui();
  //开启屏幕触点检测任务
  taskScreenPress.resume();
}

//使用场控的自动部分程序
void autonomous(void) {
  myAuto();
}

void usercontrol(void) {
  while (1) {
    
    if(LimitSwitchA.pressing()){
    //if(Controller1.ButtonB.pressing()){
      timer t2;
      t2.reset();
      myAuto();
      Controller1.Screen.setCursor(1, 0);
      Controller1.Screen.print("%f",t2.time(sec));
    }
    myRemoteControl();
    wait(20, msec); 
  }
}


int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  pre_auton();
  while (true) {
    wait(100, msec);
    
  }
}
