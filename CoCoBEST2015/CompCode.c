#pragma config(Motor,  port2,           right,         tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           left,          tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port4,           rotate,        tmotorServoStandard, openLoop)
#pragma config(Motor,  port6,           arm,           tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port7,           lift,          tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port8,           claw,          tmotorServoStandard, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	int maxup = (-127 * 0.8);
	int clawValue = 0;
	while(true)
	{
		motor[right] = vexRT[Ch2];
		motor[left] = vexRT[Ch3];
		if(vexRT[Btn5U])
		{
		motor[lift] = 127;
		}
		else if(vexRT[Btn5D])
		{
		motor[lift] = -127;
		}
		else
		{
		motor[lift] = 0;
		}
		if(vexRT[Btn6U])
		{
			motor[arm] = 60;
		}
		else if(vexRT[Btn6D])
		{
			motor[arm] = -30;
			
		}
		else
		{
			motor[arm] = 30;
		}
		if(vexRT[Btn8D])
		{
			clawValue++;
			delay(2);
			if(clawValue>127) {
				clawValue = 127;		
			}
			motor[port9] = clawValue;
		}
		if(vexRT[Btn7D])
		{
			clawValue--;
			delay(2);
			if(clawValue< maxup) {
				clawValue = maxup;		
			}
			motor[port9] = clawValue;
		}
		if(vexRT[Btn8R])
		{
			motor[rotate] = 127;
		}
		else if(vexRT[Btn7L])
		{
			motor[rotate] = maxup;
		}
	}
}
