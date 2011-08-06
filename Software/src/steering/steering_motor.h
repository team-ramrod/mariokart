#ifndef STEERING_MOTOR_H
#define	STEERING_MOTOR_H

//Sets up PWM output
void init_driver(void);

//takes in a number between 100 and -100 and uses it
//to set PWM for driving the steering motor where
//100 = full speed clockwise
//50 = half speed clockwise
//0 = stopped
//-100 = full speed anticlockwise etc
void drive_motor(int speed);

#define P_GAIN 1
#define I_GAIN 0.0
#define D_GAIN 0.0

//PID controller with gains defined above
int pid(int desired, int current);

#endif	/* STEERING_MOTOR_H */

