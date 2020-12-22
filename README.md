# nBlocks_L298

n-Blocks Studio node to drive a DC motor with a single bridge of a L298 dual bridge driver IC 

## Parameters

* L298 IN1:       GPO pinName 
* L298 IN2:       GPO pinName   
* L298 Enable     PWM pinName  

## Input Values:

Value: integer 
```
* 0 or 0x30 STOP  IN1=0, IN2=0
* 1 or 0x31 RIGHT IN1=1, IN2=0  STATE MACHINE: ACTIVATED ONLY IF IN STOP
* 2 or 0x32 LEFT  IN1=0, IN2=1  STATE MACHINE: ACTIVATED ONLY IF MOVING RIGHT
* 3 or 0x33 BRAKE IN1=1, IN2=1
```