using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor leftFront;
extern motor leftBack;
extern motor rightIntake;
extern motor topSpin;
extern controller Controller1;
extern motor leftIntake;
extern motor bottomSpin;
extern motor rightBack;
extern motor rightFront;
extern optical color;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );