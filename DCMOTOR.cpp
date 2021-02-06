#include "DCMOTOR.h"

nBlock_DCMOTOR::nBlock_DCMOTOR(PinName IN1, PinName IN2, PinName EN):
	_in1(IN1), _in2(IN2), _enable(EN) {
	_enable.period(1.0/5000.0);         	// 4Khz period

	// Place the Motor in Stop
	received_value = 0;
	must_update = 1;	
}

void nBlock_DCMOTOR::triggerInput(nBlocks_Message message){
	// input 0 receives a value in range 0-255
	if (message.inputNumber == 0) {
		// Store value
		received_value = message.intValue;
		// Set flag so we update the outputs at the end of frame
		must_update =  1;
	}
}

void nBlock_DCMOTOR::endFrame(void){
	if (must_update) {
		must_update = 0;
		
		// A single byte as value
		char buf[1];
		buf[0] = received_value;

		switch (buf[0]) {
			case 0:					// stop uncoditionally
				state = 0;
				stop();
				break;
			case 0x30:				// stop uncoditionally
				state = 0;
				stop();
				break;				
			case 1:
				if (state == 0){	//move right only if is in stop
					state = 1;
					turnRight();
					}
				break;
			case 0x31:
				if (state == 0){	//move right only if is in stop
					state = 1;
					turnRight();
					}
				break;				
			case 2:
				if (state == 1){	//turn left only if moving right
					state = 2;
					turnLeft();
					}
				break;
			case 0x32:
				if (state == 1){	//turn left only if moving right
					state = 2;
					turnLeft();
					}
				break;				
			case 3:					// brake unconditionally
				brake();
				break;
			case 0x33:				// brake unconditionally
				brake();
				break;				
			default:				// any other input ignore
				break;
		}//switch
	}//if(must_update)
}//endFrame

void nBlock_DCMOTOR::stop(void) {
  	_in1 = OFF; 
  	_in2 = OFF;
}
  
void nBlock_DCMOTOR::turnLeft(void) {
    _enable.write(0.95f);
	_in1 = OFF;
	_in2 = ON;      
}
 
void nBlock_DCMOTOR::turnRight(void) {
    _enable.write(0.95f);
    _in1 = ON;
    _in2 = OFF;   
}

void nBlock_DCMOTOR::brake(void) {
    _enable.write(0.95f);
    _in1 = ON;
    _in2 = ON;   
}
   
