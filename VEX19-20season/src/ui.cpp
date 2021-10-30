#include "ui.h"

ui::ui()
{
  sideRectInit();
}

ui::~ui()
{

}

void _rect::show()
{
  Brain.Screen.drawRectangle(x, y, width, height, fillColor);
  Brain.Screen.printAt(x, y+80, false, "%s",getText().c_str());
}

_rect::_rect(color _fillColor,int _x,int _y,int _width,int _height)
{
  fillColor = _fillColor;
  x = _x;
  y = _y;
  width = _width;
  height = _height;
}

_rect::~_rect()
{
  
}

bool _rect::pressed(int32_t _xPosition, int32_t _yPosition)
{
  if(_xPosition>=x && _xPosition<=x+width && _yPosition>=y && _yPosition<=y+height)
    return true;
  else 
    return false;
}

void _rect::setText(string _str)
{
  text = _str;
}

string _rect::getText()
{
  return text;
}

void _rect::pressedFunc(){
  sideFlag = enumSide;
  Brain.Screen.drawCircle(x+width/2, y+height/2, 20,vex::color::yellow);
}

void ui::sideRectInit()
{
  rectBlueLeft = new _rect(vex::color::blue,20,12);
  rectBlueRight = new _rect(vex::color::blue,20,132);
  rectRedLeft = new _rect(vex::color::red,140,132);
  rectRedRight = new _rect(vex::color::red,140,12);
  rectBlueLeft->setText("BlueL");
  rectBlueRight->setText("BlueR");
  rectRedLeft->setText("RedL");
  rectRedRight->setText("RedR");
  rectBlueLeft->enumSide = BLUELEFT;
  rectBlueRight->enumSide = BLUERIGHT;
  rectRedLeft->enumSide = REDLEFT;
  rectRedRight->enumSide = REDRIGHT;
  vectorRect4ScreenDetect.push_back(rectBlueLeft);
  vectorRect4ScreenDetect.push_back(rectBlueRight);
  vectorRect4ScreenDetect.push_back(rectRedLeft);
  vectorRect4ScreenDetect.push_back(rectRedRight);
  show();
}

void ui::show()
{
  rectBlueLeft->show();
  rectBlueRight->show();
  rectRedLeft->show();
  rectRedRight->show();
}

void ui::screenPressed()
{
  int32_t x=Brain.Screen.xPosition();
  int32_t y=Brain.Screen.yPosition();
  for(int i=0;i<vectorRect4ScreenDetect.size();i++)
  {
    if(vectorRect4ScreenDetect[i]->pressed(x,y))
    {
      show();
      vectorRect4ScreenDetect[i]->pressedFunc();
      break;
    }   
  }
}












extern ui _ui;

int _tPressDetect()
{
  while(1){
    if(Brain.Screen.pressing())
      _ui.screenPressed();
    wait(30, msec);
  }
}