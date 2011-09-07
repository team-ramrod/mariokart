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

#define FOLLOW_LAG 10
#define MIN_DIST 20
#define TURN_FACTOR 0.5

using namespace std;

//stored board positions
    list<Location *> board_loc_list;

    //stored kart positions
    list<Location *> kart_loc_list;

    list<Location *>::iterator current_des = board_loc_list.begin();

void follow_boards_path(double *wheel_angle, double *kart_speed, double *kart_angle){

while(kart_loc_list.front()->dist_to(**current_des) < MIN_DIST) {

            if (current_des != board_loc_list.begin()) {
               *kart_speed = 0.1;
               current_des--;
            } else {
                *kart_speed = 0;
                break;
            }
        }
        //timeout to forget point and go after next one
        while (((clock() / (double) CLOCKS_PER_SEC) - (*current_des)->t) > FOLLOW_LAG) {
            if (current_des != board_loc_list.begin()) {
               *kart_speed = 0.1;
               current_des--;
            } else {
                *kart_speed = 0;
                break;
            }
        }

        //printf("a %g   %g\n",wheel_angle, kart_angle);
        *wheel_angle = kart_loc_list.front()->relative_angle(**current_des, *kart_angle);
        }

int main(int argc, char** argv) {

    bool running = true;

    

    Location* kart_init_pos = new Location;
    Location* board_init_pos = new Location;

    kart_init_pos->set_values(0, 0, 0, 0);
    kart_loc_list.push_front(kart_init_pos);

    board_init_pos->set_values(0, 0, 0, 0);
    board_loc_list.push_front(board_init_pos);

    //sets up kart and board inital positions
    double wheel_angle = 0;
    double kart_angle = 0.0;
    double kart_speed = 0.1;

    std::clock_t loop_time;

    //setup chessboard
    CvCapture *capture = chessboard_init();

    plot_init();

    while (running) {
        Location* kart_loc = new Location();
        kart_loc->set_values(*kart_loc_list.front());

        //locate the chessboard
        Location *chessboard_loc = new Location;
        if (chessboard_find(capture, chessboard_loc)) {

            chessboard_loc->add_offset(*kart_loc, kart_angle);

            //printf("kart : %g, %g,    board : %g , %g        %g\n",chessboard_loc->x,chessboard_loc->z, kart_loc->x, kart_loc->z, kart_angle);
            board_loc_list.push_front(chessboard_loc);
            //printf("x: %g,  y: %g,  z: %g, t: %g\n", chessboard_loc->x, chessboard_loc->y, chessboard_loc->z, chessboard_loc->t);
        } else {
            delete chessboard_loc;
        }

        //perform tracking
follow_boards_path(&wheel_angle, &kart_speed, &kart_angle);
        

        double timestep = (std::clock() - loop_time) / (double) CLOCKS_PER_SEC;

        //updates karts position
        kart_angle += TURN_FACTOR * (wheel_angle * timestep);

        while (kart_angle > 2 * M_PI) {
            kart_angle -= 2 * M_PI;
        }
        while (kart_angle < 0) {
            kart_angle += 2 * M_PI;
        }

        loop_time = std::clock();

        kart_loc->move_position(kart_angle, kart_speed, timestep);

        kart_loc_list.push_front(kart_loc);

        plot_update(&kart_loc_list, &board_loc_list, current_des);

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

