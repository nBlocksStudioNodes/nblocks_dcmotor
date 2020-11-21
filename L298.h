#ifndef __NB_L298
#define __NB_L298

# define ON  1
# define OFF 0

#include "nworkbench.h"

class nBlock_L298: public nBlockSimpleNode<1> {
public:
    nBlock_L298(PinName IN1, PinName IN2, PinName EN);
    void triggerInput(nBlocks_Message message);
	void endFrame();
	void stop(void);
	void turnRight(void);
	void turnLeft(void);
	void brake(void);
	  
private:	
	// Temporary values to store data received from input
	uint32_t received_value;
	uint32_t must_update;

	DigitalOut _in1;
    DigitalOut _in2;
	PwmOut _enable;
};

#endif