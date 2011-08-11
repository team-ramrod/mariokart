#ifndef ACTUATOR_DRIVER_H
#define	ACTUATOR_DRIVER_H

#define ACT_DRIVER_P_GAIN 1
#define ACT_DRIVER_I_GAIN 0.0
#define ACT_DRIVER_D_GAIN 0.0

/**
 * Sets up PWM output and intterupts for error signals
 */
void act_driver_init(void);

/**
 * Takes in a number between 100 and -100 and uses it
 * to set PWM for driving the actuator where
 * 100 = full speed clockwise
 * 50 = half speed clockwise
 * 0 = stopped
 * -100 = full speed anticlockwise etc
 * @param speed     The desired PWM as specified above
 */
void act_driver_drive(int speed);

/**
 * PID controller with gains defined above
 * @param desired    The location the controller is driving to
 * @param current    The location the actuator is at
 * @return           The pid output value
 */
int act_driver_pid(int desired, int current);

#endif	/* ACTUATOR_DRIVER_H */

