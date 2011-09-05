/* ----------------------------------------------------------------------------
 *          Mariokart project
 * ----------------------------------------------------------------------------
 *  Copyright (c) 2011, University of Canterbury
 */

//------------------------------------------------------------------------------
//         Headers
//------------------------------------------------------------------------------
#include <actuator_driver.h>
#include <components/char_display.h>
#include <components/debug.h>
#include <components/switches.h>
#include <encoder.h>
#include <protocol/protocol.h>
#include <pio/pio.h>
#include <pio/pio_it.h>

//------------------------------------------------------------------------------
//         Local defines
//------------------------------------------------------------------------------
#define SOFTWARE_NAME "Steering"

//angle in degrees that the wheel may come within the end of its travel
//due to some round processes in converting from pulses to degrees this 
//must not be set to 0
#define SAFETY_MARGIN 10

//------------------------------------------------------------------------------
//         Local variables
//------------------------------------------------------------------------------
//minimum angle wheel can be turned to in degrees
int steering_min_angle;

//maximum angle wheel can be turned to in degrees
int steering_max_angle;

//location of wheel measured in pulses from encoder
int steering_loc_in_pulses = 0;

//sets pins of limit switches
const Pin pin_lim_up = LIM_SW_UP;
const Pin pin_lim_down = LIM_SW_DOWN;

typedef enum {
    UNCALIBRATED,
    FINDING_ANTICLOCK,
    FINDING_CLOCK,
    CENTERING,
    SETTING_SWITCHES,
    CALIBRATED
} cal_state;

//------------------------------------------------------------------------------
//         Interrupt Handlers
//------------------------------------------------------------------------------
//triggers error on limit switches (ISR must not be set till after calibration)

void LIMIT_ISR(const Pin *pin) {
    if (!PIO_Get(&pin_lim_up) || !PIO_Get(&pin_lim_down)) {
        //something wrong with steering so stops motor
        act_driver_drive(0);

        TRACE_ERROR("LIMIT SWITCH ACTIVATED ENTERING ERROR STATE\r\n");
        //TODO: trigger error state
    }
}

//------------------------------------------------------------------------------
//         Local Functions
//------------------------------------------------------------------------------
//sets steering to an angle (in degrees) between min_angle and max_angle

void set_steering(int angle) {

    angle = angle + ((steering_max_angle - steering_min_angle) / 2) + steering_min_angle;

    if (angle > steering_max_angle - SAFETY_MARGIN) {
        angle = steering_max_angle - SAFETY_MARGIN;
    } else if (angle < steering_min_angle + SAFETY_MARGIN) {
        angle = steering_min_angle + SAFETY_MARGIN;
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
            ((steering_max_angle - steering_min_angle) / 2)) -steering_min_angle;
}

//sets up the limit swiches interrupts

void steering_limit_sw_init(void) {

    // Initialize interrupts
    PIO_ConfigureIt(&pin_lim_up, LIMIT_ISR);
    PIO_ConfigureIt(&pin_lim_down, LIMIT_ISR);
    PIO_EnableIt(&pin_lim_up);
    PIO_EnableIt(&pin_lim_down);

    printf("Limit switch ISR activated\n\r");

}

//calibrates steering position by finding locaiton of limit switches and
//assuming straight ahead is halfway between them

void cal_steering(cal_state* cal) {

    switch (*cal) {
        case UNCALIBRATED:

            printf("Steering calibration started\n\r");
            *cal = FINDING_ANTICLOCK;
            break;

        case FINDING_ANTICLOCK:
            //drive steering anticlockwise until limit hit
            act_driver_drive(-50);
            if (PIO_Get(&pin_lim_down)) {
                //stop motor
                act_driver_drive(0);

                //record value in degrees
                steering_min_angle = 360 * encoder_position_output / ENCODER_PULSES_PER_REV;
                printf("Anticlockwise limit found at %i degrees\n\r", steering_min_angle);
                *cal = FINDING_CLOCK;
            }

        case FINDING_CLOCK:
            //drive steering clockwise until limit hit
            act_driver_drive(50);
            if (PIO_Get(&pin_lim_up)) {
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

                    //implement error state
                    proto_state_error();
                }
                printf("Center offset found to be %i degrees\r\n",
                        ((steering_max_angle - steering_min_angle) / 2) + steering_min_angle);

                //dont return until motor driven back to center
                printf("desired location %i, current location %i\r\n", get_steering_desired_pos(), get_steering_pos());
                act_driver_drive(-50);

                *cal = CENTERING;
            }
            break;

        case CENTERING:
            if (get_steering_pos() <= get_steering_desired_pos()) {
                //stop motor
                act_driver_drive(0);
                printf("Steering centered calibration finished\n\r");
                *cal = SETTING_SWITCHES;
            }
            break;

        case SETTING_SWITCHES:
            steering_limit_sw_init();
            *cal = CALIBRATED;
        default:
            proto_state_error();
            break;
    }

}

//------------------------------------------------------------------------------
//         Main Function
//------------------------------------------------------------------------------

int main(int argc, char *argv[]) {
    debug_init(SOFTWARE_NAME);

    TRACE_INFO("Start steering board initialization\n\r");
    //enables interrupts (note resets all configured interrupts)
    PIO_InitializeInterrupts(AT91C_AIC_PRIOR_LOWEST);

    //Main initialisations
    char_display_init();
    switches_init();
    encoder_init();
    act_driver_init();

    //sets pins as inputs
    PIO_Configure(&pin_lim_up, 1);
    PIO_Configure(&pin_lim_down, 1);

    //sets positon to turn wheel to in degrees (used until can bus in place)
    set_steering(200);

    proto_init(ADDR_STEERING);

    int speed;
    message_t msg;
    cal_state cal = UNCALIBRATED;

    TRACE_INFO("Steering board initialization completed\n\r");

    char_display_number(11);
    char_display_tick();

    while (1) {
        switch (proto_state()) {
            case STARTUP:
                break;
            case CALIBRATING:
                //ideally this would run one iteration and return
                //however that isn't a necessity
                if (cal == CALIBRATED) {
                    proto_calibration_complete();
                }
                else
                {
                    cal_steering(&cal);
                }
                break;
            case RUNNING:
                msg = proto_read();
                switch (msg.command) {
                    case CMD_SET:
                        set_steering(msg.data[0]);
                        proto_refresh();
                    case CMD_NONE:
                        break;
                    default:
                        break; //ERROR?
                }
                speed = act_driver_pid(steering_loc_in_pulses, encoder_position_output);
                act_driver_drive(speed);
                break;
            default: // ERROR
                // do error stuff
                break;
        }
    }
    return 0;
}

