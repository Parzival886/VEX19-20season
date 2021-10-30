#include "vex.h"
using namespace vex;
extern competitionSide sideFlag;

void blueL();
void blueR();
void redL();
void redR();


void myAuto()
{
  //sideFlag=REDRIGHT;
  switch(sideFlag){
    case BLUELEFT:
      blueL();
      break;
    case BLUERIGHT:
      blueR();
      break;
    case REDLEFT:
      redL();
      break;
    case REDRIGHT:
      redR();
      break;
  }
}

void blueL()
{
  MotorPush.setPosition(0, deg);
  forwardDegree(MotorLB, 100, 320);
  forwardDegree(MotorLB, -100, 70);
  diPan(-60, -60);
  setSuctionSpeed(-100);
  wait(0.4,sec);
  diPan(-10, -10);
  wait(0.5,sec);
  diPanStop();
  setSuctionSpeed(0);
  //前进，后退，展开
  setSuctionSpeed(100);
  forwardDegree(MotorLB, 100, 350);
  forwardDegree(MotorLB, 80, 500);
  wait(0.2,sec);
  forwardDegree(MotorLB, 80, 650);//450
  wait(0.2,sec);
  //前进吸第一列方块
  forwardDegree(MotorLB, -80, 180);
  pidTurn(GyroB, 40, 0.5);
  forwardDegree(MotorLB, -100, 1270);
  pidTurn(GyroB, 0, 0.9);
  //转向瞄准第二列
  forwardDegree(MotorLB, 70, 330);
  wait(0.2,sec);
  forwardDegree(MotorLB, 65, 770);
  wait(0.2,sec);
  //完成第二列吸块
  forwardDegree(MotorLB, -100, 240);
  pidTurn(GyroB, -143, 1.2);
  setSuctionSpeed(0);
  //后退，朝向得分框
  MotorSuctionL.setRotation(0,deg);
  setSuctionSpeed(-70);
  waitUntil(fabs(MotorSuctionL.rotation(deg))>=130);
  setSuctionSpeed(0);
  MotorSuctionL.setBrake(hold);
  MotorSuctionR.setBrake(hold);
  //吐一下
  MotorPush.spin(fwd,80,pct);//
  forwardMilliSecond(80, 950);
  wait(250,msec);
  //MotorPush.spin(fwd,0,pct);
  diPan(5, 5);
  wait(300, msec);
  diPan(0, 0);
  int degree;
  int speed;
  while(MotorPush.rotation(deg)<2200)
  {
    MotorPush.spin(fwd,speed,pct);
    degree = MotorPush.rotation(deg);
    speed = (2200-degree)/15+50;
    setPushSpeed(speed);
  }
  setPushSpeed(0);
  MotorSuctionL.setBrake(coast);
  MotorSuctionR.setBrake(coast);
  wait(250, msec);
  //setSuctionSpeed(-5);
  setPushSpeed(50);
  //进框堆叠
  forwardMilliSecond(30,250);
  
  //forwardMilliSecond(-15,300);

  forwardMilliSecond(-40, 500);
  setPushSpeed(0);
  //退出
 
}

void blueR()
{
  
}

void redL()
{
  
}

void redR()
{
  MotorPush.setPosition(0, deg);
  forwardDegree(MotorLB, 100, 280);
  forwardDegree(MotorLB, -100, 70);
  diPan(-80, -80);
  setSuctionSpeed(-100);
  wait(0.4,sec);
  diPan(-10, -10);
  wait(0.3,sec);
  diPanStop();
  setSuctionSpeed(0);
  //前进，后退，展开
  setSuctionSpeed(100);
  forwardDegree(MotorLB, 100, 350);
  forwardDegree(MotorLB, 80, 400);
  wait(0.2,sec);
  forwardDegree(MotorLB, 70, 500);
  wait(0.2,sec);
  //前进吸第一列方块
  forwardDegree(MotorLB, -80, 130);
  pidTurn(GyroB, -43, 0.5);
  forwardDegree(MotorLB, -100, 1150);
  pidTurn(GyroB, 1.5, 0.7);
  //转向瞄准第二列
  forwardDegree(MotorLB, 70, 450);
  wait(0.2,sec);
  forwardDegree(MotorLB, 45, 800);
  wait(0.2,sec);
  //完成第二列吸块
  forwardDegree(MotorLB, -100, 400);
  pidTurn(GyroB, 142, 1.4);
  setSuctionSpeed(0);
  //后退，朝向得分框
  MotorSuctionL.setRotation(0,deg);
  setSuctionSpeed(-70);
  waitUntil(fabs(MotorSuctionL.rotation(deg))>=130);
  setSuctionSpeed(0);
  MotorSuctionL.setBrake(hold);
  MotorSuctionR.setBrake(hold);
  //吐一下
  MotorPush.spin(fwd,80,pct);//
  forwardMilliSecond(80, 950);
  wait(250,msec);
  //MotorPush.spin(fwd,0,pct);
  diPan(5, 5);
  wait(350, msec);
  diPan(0, 0);
  int degree;
  int speed;
  while(MotorPush.rotation(deg)<2200)
  {
    MotorPush.spin(fwd,speed,pct);
    degree = MotorPush.rotation(deg);
    speed = (2200-degree)/12+50;
    setPushSpeed(speed);
  } 
  setPushSpeed(0);
  MotorSuctionL.setBrake(coast);
  MotorSuctionR.setBrake(coast);
  wait(450, msec);
  //setSuctionSpeed(-5);
  setPushSpeed(50);
  //进框堆叠
  forwardMilliSecond(30,250);
  
  //forwardMilliSecond(-15,300);

  forwardMilliSecond(-40, 500);
  setPushSpeed(0);
  //退出
}