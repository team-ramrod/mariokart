/* 
 * File:   main.cpp
 * Author: z
 *
 * Created on September 6, 2011, 2:12 PM
 */

#include <cstdlib>
#include "chessboard.h"
#include "location.h"
#include <iostream>
#include <cstdio>
#include <ctime>


using namespace std;

int main(int argc, char** argv) {

    bool running = true;

    //sets up kart and board inital positions
    double wheel_angle = 0;
    double kart_angle = 0;
    double kart_speed = 1;

    std::clock_t loop_time;

    Location kart_loc;
    kart_loc.set_values(0,0,0,0);
    Location chessboard_loc;
    chessboard_loc.set_values(0,0,0,0);

    //setup chessboard
    CvCapture *capture = chessboard_init();

    while(running){

    //locate the chessboard
    if(chessboard_find(capture, &chessboard_loc)){
        chessboard_loc.add_offset(kart_loc, kart_angle);

        printf("x: %g,  y: %g,  z: %g, t: %g\n",chessboard_loc.x,chessboard_loc.y,chessboard_loc.z,chessboard_loc.t);
    }

    //updates karts position
    kart_angle += wheel_angle;

    double timestep = ( std::clock() - loop_time ) / (double) CLOCKS_PER_SEC;
    loop_time = std::clock();
    kart_loc.move_position(kart_angle, kart_speed, timestep);


    //Check for keypresses/allow for other threads to operate
		switch (cvWaitKey(1)) {
			case 27:	//If escape is pushed, terminate the main loop
				running = false; break;
		}
    }

    chessboard_dispose(capture);

    return 0;
}

