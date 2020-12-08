#include "vex.h"
#include "math.h"
#include "printvals.h"
#include "drivemodes.h"
using namespace vex;

int intake() 
{

  if (Controller1.ButtonR2.pressing())
  {
    leftIntake.spin(fwd, 100, pct);
    rightIntake.spin(fwd, -100, pct);
  }
    if (Controller1.ButtonY.pressing())
  {
    leftIntake.spin(fwd, 0, pct);
    rightIntake.spin(fwd, 0, pct);
  }

   else if (Controller1.ButtonX.pressing())
  {
    leftIntake.spinFor(-50,deg, 100, velocityUnits::pct,false);
    rightIntake.spinFor(50,deg, 100, velocityUnits::pct,true);
  }


  // else
  // {
  //   if (intakeval == 0)
  //   {
  //     leftIntake.stop(coast);
  //     rightIntake.stop(coast);
  //   }
  //   else
  //   {
  //     leftIntake.stop(hold);
  //     rightIntake.stop(hold);
  //   }

  // }
  

  return(0);
}

int lift() 
{

  if (Controller1.ButtonL2.pressing())
  {
    topSpin.spin(fwd, 100, pct);
    bottomSpin.spin(fwd, 100, pct);
  }
  else if (Controller1.ButtonUp.pressing())
  {
    topSpin.spin(fwd, -100, pct);
    bottomSpin.spin(fwd, 100, pct);
  }
  else
  {
    topSpin.stop(coast);
    bottomSpin.stop(coast);
  }
  
  return(0);
}

int driving() 
{
  while(true)
  {
 //   vex::task testssss(testValsTank);
    vex::task testsArcade(testValsArcade);
    vex::task printVals;
    vex::task intakes(intake);
    vex::task lifts(lift);
    // lfspeed = leftFront.velocity(pct);
    // lbspeed = leftBack.velocity(pct);
    // rfspeed = rightFront.velocity(pct);
    // rbspeed = rightBack.velocity(pct);

    leftFront.spin(fwd, abs(lfexpected) > 10 ?    lfexpected          : 0, pct);
    leftBack.spin(fwd, abs(lbexpected) > 10 ?        lbexpected       : 0, pct);
    rightFront.spin(fwd, abs(rfexpected) > 10 ?    rfexpected         : 0, pct);
    rightBack.spin(fwd, abs(rbexpected) > 10 ?         rbexpected            : 0, pct);


  }
    return(0);
}


int slew()
{
  while(true)
  {
    vex::task testvals(testValsTank);
    vex::task printVals;
    vex::task intakes(intake);
    vex::task lifts(lift);
    lfspeed = leftFront.velocity(pct);
    lbspeed = leftBack.velocity(pct);
    rfspeed = rightFront.velocity(pct);
    rbspeed = rightBack.velocity(pct);

    if (abs(rbspeed) <=10 && abs(rbexpected)<=10)
    {
      rbtrackval = 0;
    }
    else if (abs(rbspeed) >= 0.75*abs(rbexpected))
    {
      rbtrackval = 1;
    }

    if (abs(rfspeed) <=10 && abs(rfexpected)<=10)
    {
      rftrackval = 0;
    }
    else if (abs(rfspeed) >= 0.75*abs(rfexpected))
    {
      rftrackval = 1;
    }

    if (abs(lbspeed) <=10 && abs(lbexpected)<=10)
    {
      lbtrackval = 0;
    }
    else if (abs(lbspeed) >= 0.75*abs(lbexpected))
    {
      lbtrackval = 1;
    }

    if (abs(lfspeed) <=10 && abs(lfexpected)<=10)
    {
      lftrackval = 0;
    }
    else if (abs(lfspeed) >= 0.75*abs(lfexpected))
    {
      lftrackval = 1;
    }

    if (rbtrackval == 0)
    {
      if(rbmovespeed<(rbexpected))
      {
        rbmovespeed+=1;
        task::sleep(sleepval);
      }  
      if(rbmovespeed>(rbexpected))
      {
        rbmovespeed-=1;
        task::sleep(sleepval);
      }
    }
    else if (rbtrackval == 1)
    {
      rbmovespeed = rbexpected;
    }

   
    if (rftrackval == 0)
    {
      if(rfmovespeed<(rfexpected))
      {
        rfmovespeed+=1;
        task::sleep(sleepval);
      }  
      if(rfmovespeed>(rfexpected))
      {
        rfmovespeed-=1;
        task::sleep(sleepval);
      }
    }
    else if (rftrackval == 1)
    {
      rfmovespeed = rfexpected;
    }

    if (lbtrackval == 0)
    {
      if(lbmovespeed<(lbexpected))
      {
        lbmovespeed+=1;
        task::sleep(sleepval);
      }  
      if(lbmovespeed>(lbexpected))
      {
        lbmovespeed-=1;
        task::sleep(sleepval);
      }
    }
    else if (lbtrackval == 1)
    {
      lbmovespeed = lbexpected;
    }


    if (lftrackval == 0)
    {
      if(lfmovespeed<(lfexpected))
      {
        lfmovespeed+=1;
        task::sleep(sleepval);
      }  
      if(lfmovespeed>(lfexpected))
      {
        lfmovespeed-=1;
        task::sleep(sleepval);
      }
    }
    else if (lftrackval == 1)
    {
      lfmovespeed = lfexpected;
    }

    rightBack.spin(fwd,rbmovespeed,pct);
    rightFront.spin(fwd,rfmovespeed,pct);
    leftBack.spin(fwd,lbmovespeed,pct);
    leftFront.spin(fwd,lfmovespeed,pct);

  }

  return(0);
}


int main() 
{
  vexcodeInit();
  //vex::task slews(slew);
  vex::task drives(driving);
}
