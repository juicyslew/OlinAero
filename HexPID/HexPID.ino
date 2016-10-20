#include "PID.h"

double x = 0, y = 0, z = 0, pitch = 0, yaw = 0, roll = 0;
PID *pidLoops[6]; // all PID loops
// Positions - use right hand rule, +z is up
PID *xLoop; // left/right
PID *yLoop; // forward/back
PID *zLoop; // up/down
// Rotations - use right hand rule
PID *pitchLoop; // around x-axis
PID *yawLoop; // around z-axis
PID *rollLoop; // around y-axis

void setup() {
  for(int i=0; i<6; i++) {
    pidLoops[i] = new PID();
  }
  xLoop = pidLoops[0];
  yLoop = pidLoops[1];
  zLoop = pidLoops[2];
  pitchLoop = pidLoops[3];
  yawLoop = pidLoops[4];
  rollLoop = pidLoops[5];
}

void loop() {
  
}
