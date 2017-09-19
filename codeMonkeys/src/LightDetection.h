static int LINE_THRESHOLD = 45;
static bool SENSOR_ON = false;

void turn_light_detection_off()
{
	SENSOR_ON = false;
}

void turn_light_detection_on()
{
	SENSOR_ON = true;
}

bool is_over_line()
{
	if((SensorValue(light) < LINE_THRESHOLD) && SENSOR_ON)
	{
		return true;
	} else {
		return false;
	}
}
