// Go Cart
// Karl van Workum

#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "avrlibdefs.h"
#include "avrlibtypes.h"
#include "board.h"
#include "a2d.h"
#include "timer.h"

#define TOP_COUNT 3200 //Generate 2.5kHz PWM from 8MHz counter (=8000000/2500)

#define TARGET_CURRENT 620 //(2.5+0.625*(140)/150)/5*1024 // 140A

#define MAX_CURRENT 768 //(2.5+0.625*(300)/150)/5*1024  // 300A

#define BRAKING_CURRENT 469 // //-50A

s32 MAX_AMP_SECONDS = 0.5e5;//(3800*(100)*0.625/150)/5*1024;

#define SHUTDOWN sbi(SD_DDR, SD_BIT) //Low output on SD line
#define RESTART cbi(SD_DDR, SD_BIT) //Floating output on SD line

s32 ampSeconds = 0;
int pedal_input = 0;

//Control the colour of the RGB LED
enum colours {red, green, blue, purple, orange, aqua, white, off};
void rgb(char c)
{
	//Turn all off
	sbi(RGB_PORT, RED);
	sbi(RGB_PORT, GREEN);
	sbi(RGB_PORT, BLUE);
	
	
	if(c == red || c == purple || c==orange || c == white)
	{
		cbi(RGB_PORT, RED);
	}
	
	if(c == green || c == aqua || c == orange || c == white)
	{
		cbi(RGB_PORT, GREEN);
	}

	if(c == blue || c == aqua || c == purple || c == white)
	{
		cbi(RGB_PORT, BLUE);
	}

} 


void init(void)
{
	//Make outputs low
	cbi(PWM_PORT, PWM_BIT);
	cbi(SD_PORT, PWM_BIT);
	
	//Make outputs outputs
	sbi(PWM_DDR, PWM_BIT);

	//Pull-up swithces
	sbi(ESTOP_PORT, ESTOP_BIT);
	sbi(BRAKE_PORT, BRAKE_BIT);
	
	//RGB Outputs
	sbi(RGB_DDR, RED);
	sbi(RGB_DDR, GREEN);
	sbi(RGB_DDR, BLUE);
	
	//RGB Off
	sbi(RGB_PORT, RED);
	sbi(RGB_PORT, GREEN);
	sbi(RGB_PORT, BLUE);
	
	//Initialise the ADC 
	a2dInit();
	
	//Initialise timer 1
	timer1Init();
	timer1SetPrescaler(TIMER_CLK_DIV1);
	timer1PWMInitICR(TOP_COUNT); //Enable PWM with top count
	timer1PWMAOn(); //Turn PWM on
	
	rgb(green);

	sei(); //Enable interupts
}


int main(void)
{
	init(); //Initialise things
	for(;;)
	{
		//Check the estop
		if(ESTOP_PRESSED)
		{
			//Wait until it is released
			while(ESTOP_PRESSED || BRAKE_PRESSED)
			{
				SHUTDOWN;
				rgb(red);
				//timer1PWMAOff(); //Stop PWM
				delay_us(100); //Wait
			}
			RESTART;
			rgb(green);
			//timer1PWMA(); //Restart PWM
		}
		
		if(BRAKE_PRESSED)
		{
			//Start at the current duty cycle
			s16 braking_duty = pedal_input;
			
			//While the brake pedal is pressed do regenerative braking
			while(BRAKE_PRESSED)
			{
				rgb(purple);
				
				//Read the average current value
				s16 current = a2dConvert10bit(AVG_CURRENT_PIN);
				
				//Calculate the error from the target braking current
				s16 error = BRAKING_CURRENT - current;
				
				//Scale the error and add to braking duty
				braking_duty += error/10;
				
				//Stop the duty from going negative
				if(braking_duty < 0)
				{
					braking_duty = 0;
				}
				
				//Set the PWM duty
				timer1PWMASet(TOP_COUNT - braking_duty); //inverted
			
			}
			rgb(green);
		}
		
		//Check the average current
		int current = a2dConvert10bit(AVG_CURRENT_PIN);
		
		//Accumulate the amp-seconds the current is above the target current
		ampSeconds += (current - TARGET_CURRENT);
		
		//Stop the amp-seconds from going negative
		if(ampSeconds < 0) 
		{
			ampSeconds = 0;
		}
		
		//Shut down the controller if the current exceeds the maximum current
		// or the amp-seconds has exceeded the maximum allowable value
		if(ampSeconds > MAX_AMP_SECONDS || current > MAX_CURRENT)		
		{
			SHUTDOWN;
			rgb(blue);
		}
		else 
		{
			RESTART;
			rgb(green);
		}		
		
		//Get the position of the accelerator pedal
		pedal_input = a2dConvert10bit(ACCEL_PIN);
		
		//Rescale between 0 and TOP_COUNT
		pedal_input *= (TOP_COUNT/1024); 
		
		//Set the PWM Duty
		timer1PWMASet(TOP_COUNT - pedal_input); //inverted
	
	}


}
