
#ifndef ENCODER_H
#define	ENCODER_H

#define PULSES_PER_REV 4356  // NOTE PROBABLY WRONG
#define LIM_SW_DOWN    AT91C_PIO_P
#define LIM_SW_UP    AT91C_PIO_P

//wheel distance from center in pulses
int16_t pulse_position;

//Sets up pins and interrupts for encoder
void init_encoder(void);


#endif	/* ENCODER_H */

