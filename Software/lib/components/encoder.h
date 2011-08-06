#ifndef ENCODER_H
#define	ENCODER_H

//Encoder creates 19 pulses per revolution per channel
//Motor geared at 1 to 353
//LS7083 creates 4 pulses for every pulse received
// 19 * 353 * 4 = 26828
#define ENCODER_PULSES_PER_REV 26828

//wheel distance from center in pulses
int encoder_position_output;

//Sets up pins and interrupts for encoder
void encoder_init(void);

#endif	/* ENCODER_H */

