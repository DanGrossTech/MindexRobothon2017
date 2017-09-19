static int FULL_SPEED = 100;

void turn_right(int msec) {
	motor[rightMotor] = 0;		    // Motor on motorB is stopped at 0 power
	motor[leftMotor]  = 100;			// Motor on motorC is run at full (100) power forward
	wait1Msec(msec);					      // Robot runs previous code for 750 milliseconds before moving on

}

void turn_left(int msec) {
  motor[rightMotor] = 100;		    // Motor on motorB is turned off
	motor[leftMotor]  = 0;			  // Motor on motorC is turned off
	wait1Msec(msec);					    // Robot stops for 1 second
}

void go_straight(int speed, int msec) {
	motor[rightMotor] = speed;
	motor[leftMotor] = speed;
	wait1Msec(msec);
}

void stop_movement(int msec) {
	motor[rightMotor] = 0;
	motor[leftMotor] = 0;
	wait1Msec(msec);
}

void debug_print(char * debug) {
   writeDebugStream(debug);
}
