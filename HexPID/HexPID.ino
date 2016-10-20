#include "PID.h"

double x = 0, y = 0, z = 0, pitch = 0, yaw = 0, roll = 0;
PID *pidLoops[6]; // all PID loops
// Positions - use right hand rule, +z is up
PID *xLoop; // left/right
PID *yLoop; // forward/back
PID *zLoop; // up/down
// Rotations - use right hand rule
PID *pitchLoop; // around x-axis
PID *rollLoop; // around y-axis
PID *yawLoop; // around z-axis

void setup() {
  for(int i=0; i<6; i++) {
    pidLoops[i] = new PID();
  }
  xLoop = pidLoops[0];
  yLoop = pidLoops[1];
  zLoop = pidLoops[2];
  yawLoop = pidLoops[3];
}

void loop() {
  // Check for Operator Inputs and set setpoints
  // Check for new sensor data
  // TODO Later
}

void MotorUpdate() {
  //Uses the Pid Loops, does math to find individual motor values.
  
}

void SetMotor(int index, double value){
  //Set motors based on the PidLoopers
  //TODO Later
}

void NewValues(boolean Accel, double xpitch, double yroll, double zyaw) {
  //Updates PID loops with new data, and updates motor outputs.

//  x = 
//  y = 
//  z = 

  //TODO Calculate current position and rotation based on new sensor data
  if (Accel){
    pidLoops[0].input(x);
    pidLoops[1].input(y);
    pidLoops[2].input(z);
  } else {
    pitch = xpitch
    roll = yroll
    yaw = zyaw
    pidLoops[3].input(yaw);
  }
  MotorUpdate();
}



