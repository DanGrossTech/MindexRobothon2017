static int FULL_SPEED = 100;

void stop_movement(int msec) {
	motor[rightMotor] = 0;
	motor[leftMotor] = 0;
	wait1Msec(msec);
}

void turn_right(int degree) {
	nMotorEncoderTarget[leftMotor] = degree*4;
	motor[rightMotor] = 0;		    // Motor on motorB is stopped at 0 power
	motor[leftMotor]  = 40;			// Motor on motorC is run at full (100) power forward
	while(nMotorRunState[leftMotor] != runStateIdle)  wait1Msec(1);
	stop_movement(0);
}

void turn_left(int degree) {
	nMotorEncoderTarget[rightMotor] = degree*4;
  motor[rightMotor] = 40;		    // Motor on motorB is turned off
  motor[leftMotor]  = 0;					// Motor on motorC is turned off
	while(nMotorRunState[rightMotor] != runStateIdle)  wait1Msec(1);
	stop_movement(0);
}

void go_straight(int speed, int msec) {
	motor[rightMotor] = speed;
	motor[leftMotor] = speed;
	wait1Msec(msec);
}

void debug_print(char * debug) {
   writeDebugStream(debug);
}
