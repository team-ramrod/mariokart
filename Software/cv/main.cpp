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

/*
 * 
 */
int main(int argc, char** argv) {

    bool running = true;

    //sets up kart and board inital positions
    double wheel_angle = 0;
    double kart_angle = 0;
    double kart_speed = 1;

    std::clock_t loop_time;

    Location kartLoc;
    kartLoc.set_values(0,0,0,0);
    Location chessboardLoc;
    chessboardLoc.set_values(0,0,0,0);

    //setup chessboard
    CvCapture *capture = chessboard_init();

    while(running){
    //locate the chessboard
    chessboard_find(capture);

    //updates karts position
    kart_angle += wheel_angle;

    double timestep = ( std::clock() - loop_time ) / (double) CLOCKS_PER_SEC;
    loop_time = std::clock();
    kartLoc.move_position(kart_angle, kart_speed, timestep);

    //Check for keypresses/allow for other threads to operate
		switch (cvWaitKey(1)) {
			case 27:	//If escape is pushed, terminate the main loop
				running = false; break;
		}
    }

    chessboard_dispose(capture);

    return 0;
}

