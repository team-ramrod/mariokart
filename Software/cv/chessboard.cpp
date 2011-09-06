/* 
 * File:   Registration.cpp
 * Author: z
 *
 * Created on September 6, 2011, 1:55 PM
 */

#include "chessboard.h"

//Use the c++ std namespace
using namespace std;

//The boolean which controls our main loop
bool running = true;

//Function to load the Camera Parameters
bool loadCaptureParams(char *filename);

//Function to find the chessboard
vector<CvPoint2D32f> findChessboard(IplImage *frame);

//Function to perform registration of the chessboard
void registerChessboard(vector<CvPoint2D32f> corners, CvMat *capParams, CvMat *capDistortion, Location *board_loc);

//Camera Parameters
int captureWidth, captureHeight;
CvMat* captureParams, *captureDistortion;
CvMat* camRemapX, *camRemapY;

CvCapture * chessboard_init() {

	//Load the capture parameters
	if (!loadCaptureParams((char *)"camera.yml")) {
		printf("Failed to load capture parameters\n");
		return 0;
	}

        //Create a new Camera Capture object
	return cvCreateCameraCapture(-1);
}

bool chessboard_find(CvCapture *capture, Location *board_loc){

                bool found_board = false;
		
                //Grab a new frame
		IplImage *newFrame = cvCloneImage(cvQueryFrame(capture));

		//Create a new undistorted image
		IplImage *undistortedFrame = cvCreateImage(cvSize(newFrame->width, newFrame->height), IPL_DEPTH_8U, 3);
		//Unwarp the original into the undistorted image
		cvRemap(newFrame, undistortedFrame, camRemapX, camRemapY);

		//After remapping, the principal point is now in the center of the marker, update accordingly
		CvMat *capParams = cvCloneMat(captureParams);
		capParams->data.db[2]= newFrame->width/2.0; capParams->data.db[5]= newFrame->height/2.0;

		//Search for the chessboard pattern
		vector<CvPoint2D32f> chessboardPoints = findChessboard(undistortedFrame);

		//Perform Registration
		if (chessboardPoints.size() == CHESSBOARD_WIDTH*CHESSBOARD_HEIGHT) {
			registerChessboard(chessboardPoints, capParams, 0, board_loc);

                        found_board = true;
		}

		//Clean up
		cvReleaseImage(&undistortedFrame);
		cvReleaseImage(&newFrame);
		cvReleaseMat(&capParams);

                return found_board;
}

void chessboard_dispose(CvCapture *capture){

	//Clean up the capture object
	cvReleaseCapture(&capture);

	//Clean up the Camera Parameters
	cvReleaseMat(&captureParams); cvReleaseMat(&captureDistortion);
	cvReleaseMat(&camRemapX); cvReleaseMat(&camRemapY);

}

/* Load the Camera Parameters */
bool loadCaptureParams(char *filename) {
    CvFileStorage* fs = cvOpenFileStorage(filename, 0, CV_STORAGE_READ);
    if (fs == 0) return false;

    CvFileNode* fileparams;
    //Read the Image Width
    fileparams = cvGetFileNodeByName(fs, NULL, "image_width");
    captureWidth = cvReadInt(fileparams, 320);
    //Read the Image Height
    fileparams = cvGetFileNodeByName(fs, NULL, "image_height");
    captureHeight = cvReadInt(fileparams, 240);
    //Read the Camera Parameters
    fileparams = cvGetFileNodeByName(fs, NULL, "camera_matrix");
    captureParams = (CvMat*) cvRead(fs, fileparams);
    //Read the Camera Distortion
    fileparams = cvGetFileNodeByName(fs, NULL, "distortion_coefficients");
    captureDistortion = (CvMat*) cvRead(fs, fileparams);
    cvReleaseFileStorage(&fs);

    //Initialize Undistortion Maps
    camRemapX = cvCreateMat(captureHeight, captureWidth, CV_32F);
    camRemapY = cvCreateMat(captureHeight, captureWidth, CV_32F);
    cvInitUndistortMap(captureParams, captureDistortion, camRemapX, camRemapY);

    return true;
}

/* Function to find the chessboard pattern in an image */
vector<CvPoint2D32f> findChessboard(IplImage *frame) {
    //Allocate some space to contain the found chessboard corners.
    //They are represented as a two dimensional floating point position (CvPoint2D32f)
    vector<CvPoint2D32f> chessboardCorners;
    chessboardCorners.resize(CHESSBOARD_WIDTH * CHESSBOARD_HEIGHT);

    //Keep a count of how many corners we've found
    int foundCornerCount;

    //Find the chessboard
    int found = cvFindChessboardCorners(frame, cvSize(CHESSBOARD_WIDTH, CHESSBOARD_HEIGHT), &chessboardCorners[0], &foundCornerCount);

    //Clone the image
    IplImage *clonedFrame = cvCloneImage(frame);
    //If found has returned 1, draw the chessboard
    cvDrawChessboardCorners(clonedFrame, cvSize(CHESSBOARD_WIDTH, CHESSBOARD_HEIGHT), &chessboardCorners[0], foundCornerCount, found);
    //Show the image
    cvShowImage("Chessboard", clonedFrame);

    //Clean up
    cvReleaseImage(&clonedFrame);

    //If we found the pattern
    if (found) {
        //return the corners
        return chessboardCorners;
    } else {
        //otherwise return a blank vector
        return vector<CvPoint2D32f > ();
    }
}

void registerChessboard(vector<CvPoint2D32f> corners, CvMat *capParams, CvMat *capDistortion, Location *board_loc) {
    //Initialise a vector the size of the chessboard
    vector<CvPoint2D32f> chessboardPoints;
    chessboardPoints.resize(CHESSBOARD_WIDTH * CHESSBOARD_HEIGHT);
    //Loop through each corner and add it to the vecot of points
    for (int i = 0; i < CHESSBOARD_HEIGHT; i++)
        for (int j = 0; j < CHESSBOARD_WIDTH; j++)
            chessboardPoints[i * CHESSBOARD_WIDTH + j] = cvPoint2D32f(j * SQUARE_SIZE, i * SQUARE_SIZE);

    //Create a matrix for the chessboard corners
    CvMat objectPoints = cvMat(CHESSBOARD_HEIGHT*CHESSBOARD_WIDTH, 1, CV_32FC2, &chessboardPoints[0]);

    //Create a matrix for the chessboard corners found in the image
    CvMat imagePoints = cvMat(CHESSBOARD_HEIGHT*CHESSBOARD_WIDTH, 1, CV_32FC2, &corners[0]);

    //Create matrices for the rotation vector and the translation vector
    float rotVect[3];
    CvMat rotationVector = cvMat(1, 3, CV_32FC1, rotVect);
    float transVect[3];
    CvMat translationVector = cvMat(1, 3, CV_32FC1, transVect);

    //Find the extrinsic camera parameters
    cvFindExtrinsicCameraParams2(&objectPoints, &imagePoints, capParams, capDistortion, &rotationVector, &translationVector);

    //Create a rotation matrix
    float rotMatrix[9];
    CvMat rotationMatrix = cvMat(3, 3, CV_32FC1, rotMatrix);

    //Convert the rotation vector to a matrix
    cvRodrigues2(&rotationVector, &rotationMatrix);

    //Print out the rotation matrix and translation vector
    //printf("%f\t%f\t%f\n%f\t%f\t%f\n%f\t%f\t%f\n\n",
    //        rotMatrix[0], rotMatrix[1], rotMatrix[2],
    //        rotMatrix[3], rotMatrix[4], rotMatrix[5],
    //        rotMatrix[6], rotMatrix[7], rotMatrix[8]);

    //printf("%f\t%f\t%f\n\n", transVect[0], transVect[1], transVect[2]);

    board_loc->set_values(transVect[0],transVect[1],transVect[2],clock() / (double) CLOCKS_PER_SEC);
}

