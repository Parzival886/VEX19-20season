using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor MotorLF;
extern motor MotorRF;
extern motor MotorLB;
extern motor MotorRB;
extern motor MotorSuctionL;
extern motor MotorSuctionR;
extern motor MotorRise;
extern motor MotorPush;
extern limit LimitSwitchA;
extern inertial Inertial21;
extern gyro GyroB;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );