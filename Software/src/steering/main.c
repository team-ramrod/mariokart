#include <encoder.h>
#include <actuator_driver.h>
#include <peripherals/pio/pio.h>
#include <peripherals/pio/pio_it.h>
#include <char_display.h>
#include <utility/trace.h>

//angle in degrees that the wheel may come within the end of its travel
//due to some round processes in converting from pulses to degrees this 
//must not be set to 0
#define SAFTEY_MARGIN 10

//minimum angle wheel can be turned to in degrees
int steering_min_angle;

//maximum angle wheel can be turned to in degrees
int steering_max_angle;

//location of wheel measured in pulses from encoder
int steering_loc_in_pulses = 0;

//sets pins of limit switches
const Pin pin_lim_up = LIM_SW_UP;
const Pin pin_lim_down = LIM_SW_DOWN;

//triggers error on limit switches (ISR must not be set till after calibration)

void LIMIT_ISR(void) {
    if (!PIO_Get(&pin_lim_up) || !PIO_Get(&pin_lim_down)) {
        //something wrong with steering so stops motor
        act_driver_drive(0);

        printf("LIMIT SWITCH ACTIVATED ENTERING ERROR STATE\r\n");
        //trigger error state TO DO
        while (1) {
            continue;
        }
    }
}

//sets steering to an angle (in degrees) between min_angle and max_angle

void set_steering(int angle) {

    angle = angle + ((steering_max_angle - steering_min_angle) / 2) + steering_min_angle;

    if (angle > steering_max_angle - SAFTEY_MARGIN) {
        angle = steering_max_angle - SAFTEY_MARGIN;
    } else if (angle < steering_min_angle + SAFTEY_MARGIN) {
        angle = steering_min_angle + SAFTEY_MARGIN;
    }

    //convert angle to pulses and account for any offset
    steering_loc_in_pulses = (angle * ENCODER_PULSES_PER_REV) / 360;

}

//gets the steering wheels current position in degrees

int get_steering_pos(void) {
    return (((encoder_position_output * 360.0) / ENCODER_PULSES_PER_REV)) -
            ((steering_max_angle - steering_min_angle) / 2) - steering_min_angle;
}

//gets where the steering wheel is moving to in degrees

int get_steering_desired_pos(void) {
    return (((steering_loc_in_pulses * 360.0) / ENCODER_PULSES_PER_REV) -
            ((steering_max_angle - steering_min_angle) / 2)) - steering_min_angle;
}

//sets up the limit swiches interrupts

void steering_limit_sw_init(void) {

    // Initialize interrupts
    PIO_ConfigureIt(&pin_lim_up, (void (*)(const Pin *)) LIMIT_ISR);
    PIO_ConfigureIt(&pin_lim_down, (void (*)(const Pin *)) LIMIT_ISR);
    PIO_EnableIt(&pin_lim_up);
    PIO_EnableIt(&pin_lim_down);

    printf("Limit switch ISR activated\n\r");

}

//calibrates steering position by finding locaiton of limit switches and
//assuming straight ahead is halfway between them

void cal_steering(void) {

    printf("Steering calibration started\n\r");

    //drive steering anticlockwise until limit hit
    act_driver_drive(-50);
    while (!PIO_Get(&pin_lim_down)) {
        continue;
    }

    //stop motor
    act_driver_drive(0);

    //record value in degrees
    steering_min_angle = 360 * encoder_position_output / ENCODER_PULSES_PER_REV;
    printf("Anticlockwise limit found at %i degrees\n\r", steering_min_angle);

    //drive steering clockwise until limit hit
    act_driver_drive(50);
    while (!PIO_Get(&pin_lim_up)) {
        continue;
    }

    //stop motor
    act_driver_drive(0);

    //record value in degrees
    steering_max_angle = 360 * encoder_position_output / ENCODER_PULSES_PER_REV;
    printf("Clockwise limit found at %i degrees\n\r", steering_max_angle);

    //set starting position to center position
    set_steering(0);

    //check motor direction and enter error state if required
    if (steering_max_angle < steering_min_angle) {
        printf("ERROR MOTOR SPINNING BACKWARDS\n\r");

        //implement error state TO DO
        while (1) {
            continue;
        }
    }
    printf("Center offset found to be %i degrees\r\n",
            ((steering_max_angle - steering_min_angle) / 2) + steering_min_angle);

    //dont return until motor driven back to center
    printf("desired location %i, current location %i\r\n",get_steering_desired_pos(),get_steering_pos());
    act_driver_drive(-50);

    //cannot have while(get_steering_pos() > get_steering_desired_pos()){};
    //as compiler fucks up its implementation, hence the volatile i
    volatile int i = 0;
    while (get_steering_pos() > get_steering_desired_pos()) {
        i++;
    }

    //stop motor
    act_driver_drive(0);
    printf("Steering centered calibration finished\n\r");
}

int main(int argc, char *argv[]) {

    TRACE_CONFIGURE(DBGU_STANDARD, 115200, BOARD_MCK);
    printf("Starting steering initilization\n\r");
    //enables interrupts (note resets all configured interrupts)
    PIO_InitializeInterrupts(AT91C_AIC_PRIOR_LOWEST);

    //initilize steering
    encoder_init();
    act_driver_init();
    char_display_init();

    //sets pins as inputs
    PIO_Configure(&pin_lim_up, 1);
    PIO_Configure(&pin_lim_down, 1);

    //calibrate steering (commented out till limit switches in place)
    cal_steering();

    //now steering is calibrated active limit switch interrupts
    steering_limit_sw_init();

    //sets positon to turn wheel to in degrees (used until can bus in place)
    set_steering(200);

    printf("Steering initilization completed\n\r");

    //infinite loop running PID controller
    while (1) {
        int speed = act_driver_pid(steering_loc_in_pulses, encoder_position_output);
        act_driver_drive(speed);
    }

    return 0;
}

