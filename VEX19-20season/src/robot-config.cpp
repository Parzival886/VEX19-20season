#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor MotorLF = motor(PORT16, ratio18_1, false);
motor MotorRF = motor(PORT18, ratio18_1, true);
motor MotorLB = motor(PORT13, ratio18_1, false);
motor MotorRB = motor(PORT15, ratio6_1, true);
motor MotorSuctionL = motor(PORT2, ratio18_1, false);
motor MotorSuctionR = motor(PORT10, ratio18_1, true);
motor MotorRise = motor(PORT12, ratio18_1, true);
motor MotorPush = motor(PORT11, ratio18_1, true);
limit LimitSwitchA = limit(Brain.ThreeWirePort.A);
inertial Inertial21 = inertial(PORT21);
gyro GyroB = gyro(Brain.ThreeWirePort.B);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}