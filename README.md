# DCMOTOR

n-BlocksStudio node to drive a DC motor with an H-Bridge
 
  *  Category: Motor
  *  HAL: mbed
  *  Tested: LPC1768, L298
  *  Author: N. Chalikias

## Inputs
 *  (Schematic pin 1) integer: Value
    *  0 or 0x30 STOP  IN1=0, IN2=0
    *  1 or 0x31 RIGHT IN1=1, IN2=0  STATE MACHINE: ACTIVATED ONLY IF IN STOP
    *  2 or 0x32 LEFT  IN1=0, IN2=1  STATE MACHINE: ACTIVATED ONLY IF MOVING RIGHT
    *  3 or 0x33 BRAKE IN1=1, IN2=1

## Parameters
 *  PinName:  Bridge IN1: GPO pin
 *  PinName:  Bridge IN2: GPO pin
 *  PinPwm:   Bridge Enable PWM pin


## Examples:

[GPIN]-->[ValueTrig]-->[DCMOTOR]

[Ticker]-->[Counter]-->[DCMOTOR]

