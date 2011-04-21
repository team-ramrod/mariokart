
//ADC inputs
#define ACCEL_PIN 4
#define AVG_CURRENT_PIN 1
#define RAW_CURRENT_PIN 2


//Digital inputs
#define ESTOP_PIN PIND 
#define ESTOP_PORT PORTD
#define ESTOP_BIT 3
#define ESTOP_PRESSED bit_is_clear(ESTOP_PIN, ESTOP_BIT)

#define BRAKE_PIN PIND
#define BRAKE_PORT PORTD
#define BRAKE_BIT 2
#define BRAKE_PRESSED bit_is_clear(BRAKE_PIN, BRAKE_BIT)


//Outputs
#define PWM_DDR DDRB
#define PWM_PORT PORTB
#define PWM_BIT 1

#define SD_DDR DDRD
#define SD_PORT PORTD
#define SD_BIT 4


#define RGB_PORT PORTD
#define RGB_DDR DDRD
#define RED 7
#define GREEN 6
#define BLUE 5

