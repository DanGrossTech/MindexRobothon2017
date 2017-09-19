static int FULL_SPEED = 100;

void debug_print(char * debug) {
   writeDebugStream(debug);
}
void stop_movement() {
	motor[rightMotor] = 0;
	motor[leftMotor] = 0;
}

void stop_movement(int msec) {
//deprecated
	stop_movement();
}

void turn_right(int degree) {
	int startvalue = SensorValue[S2];

	motor[rightMotor] = 0;		    // Motor on motorB is stopped at 0 power
	motor[leftMotor]  = 30;			// Motor on motorC is run at full (100) power forward
	while(SensorValue[S2] - startvalue < (degree*10))  wait1Msec(1);
	writeDebugStream("\nright rotation, start: %d, end %d, total %d\n",startvalue, SensorValue[S2], SensorValue[S2] - startvalue);
	stop_movement();
}

void turn_left(int degree) {

	int startvalue = SensorValue[S2];
  motor[rightMotor] = 30;		    // Motor on motorB is turned off
  motor[leftMotor]  = 0;					// Motor on motorC is turned off
  while(startvalue - SensorValue[S2]  < (degree*10))  wait1Msec(1);
  	writeDebugStream("left rotation start: %d, end %d, total %d\n",startvalue, SensorValue[S2],startvalue - SensorValue[S2]);
	stop_movement();
}

void go_straight(int speed) {
	motor[rightMotor] = speed;
	motor[leftMotor] = speed;
}
void go_straight(int speed, int msec) {
	go_straight(speed);
	wait1Msec(msec);
	stop_movement();
}
