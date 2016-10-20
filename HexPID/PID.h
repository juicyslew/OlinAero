class PID {

  double target = 0, actual = 0, error = 0, rate = 0, prevError = 0, totalError = 0, output = 0; // state values
  long t, prevTime = -1000, dt = 0; // time values
  double kP = 0, kI = 0, kD = 0; // default constant values

  public:
  
  // Adjusts the PID constants
  void setConstants(double kP, double kI, double kD) {
    this->kP = kP;
    this->kI = kI;
    this->kD = kD;
  }
  
  // Sets the target setpoint
  void setTarget(double target) {
    this->target = target;
  }

  // Updates the PID loop with new sensor data
  void input(double value) {
    t = millis();
    dt = t-prevTime;
    // Handle interruption of data
    if(dt >= 1000) {
      prevError = error;
      dt = 0;
      totalError = 0;
      rate = 0;
    }
    actual = value;
    error = target - actual;
    if(dt!=0) rate = (error-prevError)/dt;
    totalError += error*dt;
    output = kP*error + kI*totalError + kD*rate;
    prevError = error;
    prevTime = t;
  }

  // Returns the current output of the PID loop
  double getOutput() {
    return output;
  }

  // Determines if the PID loop has reached its target within the specified tolerance
  boolean reachedTarget(double maxError, double maxRate) {
    return abs(error) < maxError && abs(rate) < maxRate;
  }

  // Returns data about the loop for debugging
  double *getData() {
    return new double[9]{target, actual, error, rate, prevError, totalError, output, prevTime, dt};
  }
};
