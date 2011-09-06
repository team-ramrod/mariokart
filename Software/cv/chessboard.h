/* 
 * File:   chessboard.h
 * Author: z
 *
 * Created on September 6, 2011, 2:20 PM
 */

#ifndef CHESSBOARD_H
#define	CHESSBOARD_H

#include <cstdlib>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include "location.h"
#include <ctime>

//Specifics of the chessboard. The width and height is the number
//of internal corners of the chessboard
#define CHESSBOARD_WIDTH 8
#define CHESSBOARD_HEIGHT 6
//The square size is the size of each square in centimetres
#define SQUARE_SIZE 2.9f

//initilizes camera to find chessboard
CvCapture * chessboard_init(void);

//finds chessboard in image
bool chessboard_find(CvCapture *capture, Location *board_loc);

//frees memory used to find chessboard
void chessboard_dispose(CvCapture *capture);


#endif	/* CHESSBOARD_H */

