
task main()
{

	SensorType[S1]= sensorEV3_Touch;

	while(true){
		while(!getButtonPress(buttonAny)){}

		if(getButtonPress(buttonEnter)){
			motor[motorC]=-10;
			while (!SensorValue[S1]){}
			motor[motorC]=0;
			wait1Msec(5000);
	//		motor[motorC]=10;
		//	wait1Msec(1000);
			//motor[motorC]=0;
		}

		while(!getButtonPress(buttonAny)){}
		if (getButtonPress(buttonUp)){
			motor[motorA]=10; //slowly move paper (no wrinkles)
			}else if (getButtonPress(buttonDown)){
			motor[motorA]=-10;
		}
		while(getButtonPress(buttonDown)||getButtonPress(buttonUp)){}
		motor[motorA]=0; //stop motor after release

		while(!getButtonPress(buttonAny)){}
		if (getButtonPress(buttonLeft)){
			motor[motorB]=10;
			}else if (getButtonPress(buttonRight)){
			motor[motorB]=-10;
		}
		while(getButtonPress(buttonLeft)||getButtonPress(buttonRight)){}
		motor[motorB]=0;

	}



}
