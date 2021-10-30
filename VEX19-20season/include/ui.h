#ifndef UI_H
#define UI_H

  /**
   *480*272
  **/

#include "vex.h"
extern competitionSide sideFlag;
using namespace std;

class _rect{
private:
  int x,y,width,height;
  color fillColor;
  string  text;
  
public:
  _rect(color _fillColor,int _x,int _y,int _width=80,int _height=80);
  ~_rect();
  bool pressed(int32_t _xPosition,int32_t _yPosition);
  void setText(string _str);
  string getText();
  void pressedFunc();
  void show();
  competitionSide enumSide;
};


class ui
{
private:
  std::vector<_rect*> vectorRect4ScreenDetect;
  _rect *rectBlueLeft,*rectBlueRight,*rectRedLeft,*rectRedRight;
  task *taskPressDetect;
  void sideRectInit();
  
public:
  void screenPressed();
  void show();
  ui();
  ~ui();
};







int _tPressDetect();


#endif