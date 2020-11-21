#include "L298.h"

nBlock_L298::nBlock_L298(PinName IN1, PinName IN2, PinName EN):
	_out(IN1), _out(IN2), _pwm(EN) {
	_pwm.period(1.0/5000.0);         	// 4Khz period

	// Place the Motor in Stop
	received_value = 0;
	must_update = 1;	
}

void nBlock_L298::triggerInput(nBlocks_Message message){
	// input 0 receives a value in range 0-255
	if (message.inputNumber == 0) {
		// Store value
		received_value = message.intValue;
		// Set flag so we update the outputs at the end of frame
		must_update =  1;
	}
}

void nBlock_L298::endFrame(void){
	if (must_update) {
		must_update = 0;
		
		// A single byte as value
		char buf[1];
		buf[0] = received_value;

		switch (buf[0])
		{
		case 0:
			stop();
			break;
		case 1:
			turnRight();
			break;
		case 2:
			turnLeft();
			break;
		case 3:
			brake();
			break;
		default:
			stop();
			break;
		}//switch
	}//if(must_update)
}//endFrame

void stop(void) {
  	IN1 = OFF; 
  	IN2 = OFF;
}
  
void turnLeft(void) {
	IN1 = OFF;
	IN2 = ON;      
}
 
void turnRight(void) {
    IN1 = ON;
    IN2 = OFF;   
}

void brake(void) {
    IN1 = ON;
    IN2 = ON;   
}
   
