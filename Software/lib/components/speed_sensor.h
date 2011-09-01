#ifndef SPEED_SENSOR_H
#define	SPEED_SENSOR_H

//the timer the speed sensor should use
#define SPEED_TIMER AT91C_ID_TC0

//speed in m/s
float speed_output;

/**
 * Sets up pin, timer and buffer for speed sensor
 */
void speed_init(void);

/**
 *updates time since speed sensor last triggered
 * called inside a interrupt triggered by a timer
 * @param timer_res the resolution in ms of the timer calling this function
 */
void speed_update_time(int timer_res);

#endif	/* SPEED_SENSOR_H */