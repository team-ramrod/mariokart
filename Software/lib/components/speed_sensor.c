#include "speed_sensor.h"
#include <boards/mariokartv1/board.h>
#include <peripherals/pio/pio.h>
#include <peripherals/pio/pio_it.h>
#include <peripherals/tc/tc.h>
#include <aic/aic.h>
#include <utility/trace.h>

//the number of speed readings to average over
#define SPEED_BUFFER_SIZE 10

//the radius of the wheel in mm
#define SPEED_WHEEL_RADIUS 200

//the amount of times the speed sensor is triggered per revolution
#define SPEED_TRIGGER_POINTS 4

//distance travelled in mm since sensor last triggered
#define SPEED_DIST (2 * 3.14159 * SPEED_WHEEL_RADIUS / SPEED_TRIGGER_POINTS)

// Pio pin for speed sensor
const Pin speed_pin = SPEED_PIN;

//buffer holding speed values
float speed_buffer[SPEED_BUFFER_SIZE];

//Time since the speed sensor last triggered in ms
uint speed_time = 0;

//updates speed sensor reading
void SPEED_ISR ( void )
{
    //buffer index variable
    static int i = 0;

    //used so that if process interrupted part way through averging the buffer
    //the speed reading is still correct
    float temp_speed = 0;

    //only updates on change from high to low
    if(!PIO_Get(&speed_pin)){
        if(speed_time == 0){
            //implement error state here
            TRACE_INFO("Error: Kart moving too fast for speed sensors current"
                    "setup, lower SPEED_TIMER_RES\n\r");
        }
        else
        {
            //adds speed to buffer
            speed_buffer[i] = SPEED_DIST/speed_time;
            i++;

            //resets timer
            speed_time = 0;
        }
    }

    //if buffer full go back to start
    if(i >= SPEED_BUFFER_SIZE){
        i = 0;
    }

    //averages the buffer
    for(int j = 0; j < SPEED_BUFFER_SIZE; j++){
        temp_speed += speed_buffer[j];
    }
    temp_speed /= SPEED_BUFFER_SIZE;

    //assigns temp_speed to speed
    speed_output = temp_speed;

}

//updates time since speed sensor last triggered
void speed_update_time(int timer_res)
{
    speed_time += timer_res;

    //if the sensor hasnt sent a pulse in the last second the kart is moving
    //so slow its pretty much stopped
    if(speed_time > 1000){
        speed_output = 0;
    }
}

//Sets up pin and buffer for speed sensor
void speed_init(void){

    //initilize buffer
    for(int i = 0; i < SPEED_BUFFER_SIZE; i++){
        speed_buffer[i] = 0;
    }

    //sets inital speed to 0
    speed_output = 0;

    //sets pins as inputs
    PIO_Configure(&speed_pin, 1);

    // Initialize interrupts
    PIO_ConfigureIt(&speed_pin, (void (*)(const Pin *)) SPEED_ISR);
    PIO_EnableIt(&speed_pin);

    TRACE_INFO("Speed sensor initilazaton complete\n\r");
}
