#include "vex.h"

int sideVal = 0;
int lfexpected = 0;
int lbexpected = 0;
int rfexpected = 0;
int rbexpected = 0;
int lfspeed = 0;
int lbspeed = 0;
int rfspeed = 0;
int rbspeed = 0;
int rbtrackval = 0;
int rftrackval = 0;
int lbtrackval = 0;
int lftrackval = 0;
int rbmovespeed = 0;
int rfmovespeed = 0;
int lbmovespeed = 0;
int lfmovespeed = 0;
int sleepval = 2;

int intakeval = 0;

int printVals()
{
  while(true)
  {
    Brain.Screen.clearLine(1,black);
    Brain.Screen.setCursor(1,0);
    Brain.Screen.print("value: %d", intakeval);

    Brain.Screen.clearLine(3,black);
    Brain.Screen.setCursor(3,0);
    Brain.Screen.print("leftfront Motor: %d", lfexpected);
    Brain.Screen.clearLine(4,black);
    Brain.Screen.setCursor(4,0);
    Brain.Screen.print("leftback Motor: %d", lbexpected);
    Brain.Screen.clearLine(5,black);
    Brain.Screen.setCursor(5,0);
    Brain.Screen.print("rightfront Motor: %d", rfexpected);
    Brain.Screen.clearLine(6,black);
    Brain.Screen.setCursor(6,0);
    Brain.Screen.print("rightBack Motor: %d", rbexpected);

    Brain.Screen.clearLine(8,black);
    Brain.Screen.setCursor(8,0);
    Brain.Screen.print("leftFront Motor: %d", lftrackval);
    Brain.Screen.clearLine(9,black);
    Brain.Screen.setCursor(9,0);
    Brain.Screen.print("leftBack Motor: %d", lbtrackval);
    Brain.Screen.clearLine(10,black);
    Brain.Screen.setCursor(10,0);
    Brain.Screen.print("rightFront Motor: %d", rftrackval);
    Brain.Screen.clearLine(11,black);
    Brain.Screen.setCursor(11,0);
    Brain.Screen.print("rightBack Motor: %d", rbtrackval);

  }
  return(0);
}