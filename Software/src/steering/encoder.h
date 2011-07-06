
#ifndef ENCODER_H
#define	ENCODER_H

#define PULSES_PER_REV 4356  // NOTE PROBABLY WRONG

//wheel distance from center in pulses
int pulse_position;

//Sets up pins and interrupts for encoder
void init_encoder(void);


#endif	/* ENCODER_H */

