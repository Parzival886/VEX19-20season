#include "vex.h"
using namespace vex;


void rcDiPan();
void rcSuction();
void rcPush();
void rcRise();
void tuyixia();
int suctionSpeed;

void myRemoteControl()
{
  tuyixia();
  rcDiPan();
  rcSuction();
  rcPush();
  rcRise();
}

void rcDiPan()
{
  int a3,a4;
  a3 = Controller1.Axis3.position(percent);
  a4 = Controller1.Axis4.position(percent);
  if(abs(a3)<10)
    a3 = 0;
  if(abs(a4)<10)
    a4  = 0;
  if(a4>65)
    a4 = 65;
  if(a4<-65)
    a4 = -65;
  diPan(a3+a4, a3-a4);
}

void rcSuction()
{
  int speed;
  if(Controller1.ButtonR1.pressing())
    speed = 100;  
  else if(Controller1.ButtonR2.pressing())
    speed = -100;
  else
    speed = suctionSpeed;
  setSuctionSpeed(speed);
}
void tuyixia(){
  if(Controller1.ButtonDown.pressing()){
    MotorSuctionL.setPosition(0, deg);
    setSuctionSpeed(-80);
    while(fabs(MotorSuctionL.rotation(deg))<150){
      wait(20, msec);
    }
  MotorSuctionL.setBrake(hold);
  MotorSuctionR.setBrake(hold);
  }
}

void rcPush()
{
  int speed;
  int degree;
  if(Controller1.ButtonL1.pressing())
  {
    degree = MotorPush.rotation(deg);
    speed = (2200-degree)/22+10;
    setPushSpeed(speed);
    if(degree<=1800)
      suctionSpeed=2;
    if(degree>1800)
      suctionSpeed=0;
      MotorSuctionL.setBrake(coast);
      MotorSuctionR.setBrake(coast);
  }
  else if(Controller1.ButtonL2.pressing())
  {
    if(MotorPush.rotation(deg)<100)
    {
      setPushSpeed(-5);
      suctionSpeed=0;
    }
    else{
      setPushSpeed(-100);
      suctionSpeed=0;
    }
  }else{
    if(Controller1.Axis2.position(pct)>0 && MotorPush.rotation(deg)<=1000)
    {
      setPushSpeed(100);
      suctionSpeed=0;
    }
    else{
      setPushSpeed(0);
      suctionSpeed=0;
    }
  }
}

void rcRise()
{
  int a2;
  a2 = Controller1.Axis2.position(pct);
  if(a2>5)
    setRiseSpeed(a2);
  else if(a2<-5)
    setRiseSpeed(a2);
  else{
    if(MotorRise.position(deg)<=200)
      MotorRise.stop(coast);
    else 
      MotorRise.stop(hold);
  }
}