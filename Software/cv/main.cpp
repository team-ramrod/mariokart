/* 
 * File:   main.cpp
 * Author: z
 *
 * Created on September 6, 2011, 2:12 PM
 */

#include <cstdlib>
#include "chessboard.h"
#include "location.h"
#include "plot.h"
#include <iostream>
#include <cstdio>
#include <ctime>
#include <list>


using namespace std;

int main(int argc, char** argv) {

    bool running = true;

    //stored board positions
    list<Location *> board_loc_list;

    //stored kart positions
    list<Location *> kart_loc_list;

    Location* kart_init_pos = new Location;
    kart_init_pos->set_values(0,0,0,0);
    kart_loc_list.push_front(kart_init_pos);

    //sets up kart and board inital positions
    double wheel_angle = 0;
    double kart_angle = 0;
    double kart_speed = 1;

    std::clock_t loop_time;

    //setup chessboard
    CvCapture *capture = chessboard_init();

    while (running) {

        Location* kart_loc = new Location();
        kart_loc->set_values(*kart_loc_list.front());

        //locate the chessboard

        Location *chessboard_loc = new Location;
        if (chessboard_find(capture, chessboard_loc)) {
            chessboard_loc->add_offset(*kart_loc, kart_angle);
            board_loc_list.push_front(chessboard_loc);
            printf("x: %g,  y: %g,  z: %g, t: %g\n", chessboard_loc->x, chessboard_loc->y, chessboard_loc->z, chessboard_loc->t);
        } else {
            delete chessboard_loc;
        }

        //updates karts position
        kart_angle += wheel_angle;

        double timestep = (std::clock() - loop_time) / (double) CLOCKS_PER_SEC;
        loop_time = std::clock();

        //printf("hteaodudhooue\n\n");
        
        kart_loc->move_position(kart_angle, kart_speed, timestep);

        kart_loc_list.push_front(kart_loc);

        plot_update();

        //Check for keypresses/allow for other threads to operate
        switch (cvWaitKey(1)) {
            case 27: //If escape is pushed, terminate the main loop
                running = false;
                break;
        }
    }

    chessboard_dispose(capture);

    return 0;
}

