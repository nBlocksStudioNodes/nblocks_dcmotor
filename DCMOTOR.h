#ifndef __NB_DCMOTOR
#define __NB_DCMOTOR

# define ON  1
# define OFF 0

#include "nworkbench.h"

class nBlock_DCMOTOR: public nBlockSimpleNode<1> {
public:
    nBlock_DCMOTOR(PinName IN1, PinName IN2, PinName EN);
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
	uint32_t state = 0;

	DigitalOut _in1;
    DigitalOut _in2;
	PwmOut _enable;
};

#endif