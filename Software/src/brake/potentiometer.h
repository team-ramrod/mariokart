
#ifndef ENCODER_H
#define	ENCODER_H

#define PULSES_PER_REV 4356  // NOTE PROBABLY WRONG

//wheel distance from center in pulses
int current_adc_value;

//Sets up pins and interrupts for pot
void init_pot(void);


#endif	/* ENCODER_H */

