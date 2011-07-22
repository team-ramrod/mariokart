#ifndef BRAKE_ACT_H
#define	BRAKE_ACT_H

//Sets up PWM output
void init_driver(void);

//takes in a number between 100 and -100 and uses it
//to set PWM for driving the linear actuator where
//100 = full speed lenghten (brakes on)
//50 = half speed lengthen (brakes on)
//0 = stopped
//-100 = full speed shorten (brakes off) etc
void drive_motor(int speed);

#define P_GAIN 1
#define I_GAIN 0.1
#define D_GAIN 0.1

//PID controller with gains defined above
int pid(int desired, int current);

#endif	/* BRAKE_ACT_H */

