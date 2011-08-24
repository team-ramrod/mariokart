#ifndef POTENTIOMETER_H
#define	POTENTIOMETER_H

//brakes actuator distance extended in mV
int pot_current_value;

/**
 * Sets up pins and interrupts for pot
 */
void pot_init(void);

#endif	/* POTENTIOMETER_H */

