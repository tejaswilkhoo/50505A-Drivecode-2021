#include "vex.h"
#include "printvals.h"

int min(double a, double b)
{
  if(a<b)
  {
    return(a);
  }
  else 
  {
    return(b);
  }
}

int max(double a, double b)
{
  if(a>b)
  {
    return(a);
  }
  else 
  {
    return(b);
  }
}

int testValsTank()
{
  if (Controller1.ButtonR1.pressing())
  {
    sideVal = 127;
  }
  else if (Controller1.ButtonL1.pressing())
  {
    sideVal = -127;
  }
  else
  {
    sideVal = 0;
  }

  lfexpected = (Controller1.Axis3.value()+sideVal > 0 ? min((Controller1.Axis3.value()+sideVal)/1.27,100) : max((Controller1.Axis3.value()+sideVal)/1.27,-100));
  lbexpected = (Controller1.Axis3.value()-sideVal > 0 ? min((Controller1.Axis3.value()-sideVal)/1.27,100) : max((Controller1.Axis3.value()-sideVal)/1.27,-100));
  rfexpected = (Controller1.Axis2.value()-sideVal > 0 ? min((Controller1.Axis2.value()-sideVal)/1.27,100) : max((Controller1.Axis2.value()-sideVal)/1.27,-100));
  rbexpected = (Controller1.Axis2.value()+sideVal > 0 ? min((Controller1.Axis2.value()+sideVal)/1.27,100) : max((Controller1.Axis2.value()+sideVal)/1.27,-100));
  return(0);
}

int testValsArcade()
{

  if (Controller1.ButtonR1.pressing())
  {
    sideVal = 127;
  }
  else if (Controller1.ButtonL1.pressing())
  {
    sideVal = -127;
  }
  else
  {
    sideVal = 0;
  }

  lfexpected = ((Controller1.Axis3.value()+Controller1.Axis1.value()+sideVal) > 0 ? min((Controller1.Axis3.value()+Controller1.Axis1.value()+sideVal)/1.27,100) : max((Controller1.Axis3.value()+Controller1.Axis1.value()+sideVal)/1.27,-100));
  lbexpected = ((Controller1.Axis3.value()+Controller1.Axis1.value()-sideVal) > 0 ? min((Controller1.Axis3.value()+Controller1.Axis1.value()-sideVal)/1.27,100) : max((Controller1.Axis3.value()+Controller1.Axis1.value()-sideVal)/1.27,-100));
  rfexpected = ((Controller1.Axis3.value()-Controller1.Axis1.value()-sideVal) > 0 ? min((Controller1.Axis3.value()-Controller1.Axis1.value()-sideVal)/1.27,100) : max((Controller1.Axis3.value()-Controller1.Axis1.value()-sideVal)/1.27,-100));
  rbexpected = ((Controller1.Axis3.value()-Controller1.Axis1.value()+sideVal) > 0 ? min((Controller1.Axis3.value()-Controller1.Axis1.value()+sideVal)/1.27,100) : max((Controller1.Axis3.value()-Controller1.Axis1.value()+sideVal)/1.27,-100));

  return(0);
}