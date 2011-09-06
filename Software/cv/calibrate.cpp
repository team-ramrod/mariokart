/* 
 * File:   main.cpp
 * Author: z
 *
 * Created on September 6, 2011, 12:20 PM
 */
//test
#include <cstdlib>
#include <opencv/cv.h>
#include <opencv/highgui.h>

using namespace std;

//The boolean which controls our main loop
bool running = true;

/* Function to find the chessboard pattern in an image */
vector<CvPoint2D32f> findChessboard(IplImage *frame);

//Function to capture chessboard corners
void captureFrame(IplImage *frame, vector<CvPoint2D32f> corners);

//Function to calibrate the camera
void calibrateCamera(int width, int height);

//Function to evaluate the error of the calibration
void computeError(const CvMat* object_points, const CvMat* rot_vects, const CvMat* trans_vects,
	const CvMat* camera_matrix, const CvMat* dist_coeffs, const CvMat* image_points, const CvMat* point_counts);

//Specifics of the chessboard. The width and height is the number
//of internal corners of the chessboard
int chessboardWidth = 8;
int chessboardHeight = 6;
//The square size is the size of each square in centimetres
float squareSize = 2.9f;

//All the corners found, and number of frames captured
vector<CvPoint2D32f> allCorners;
int numberFrames = 0;

int main () {
	//Create a new Camera Capture object
	CvCapture *capture = cvCreateCameraCapture(-1);

	//The Main Loop
	while (running) {

		//Grab a new frame
		IplImage *newFrame = cvCloneImage(cvQueryFrame(capture));

		//Find our chessboard corners
		vector<CvPoint2D32f> chessboardCorners = findChessboard(newFrame);


		//Check for keypresses/allow for other threads to operate
		switch (cvWaitKey(1)) {
			case ' ':	//If space is pushed, capture a frame
				if (chessboardCorners.size() == chessboardWidth*chessboardHeight) {
					captureFrame(newFrame, chessboardCorners); printf("Captured Frame\n");
				}
				break;
			case 'a':	//If enter is pushed, begin the calibration
				calibrateCamera(newFrame->width, newFrame->height); break;
			case 'q':	//If escape is pushed, terminate the main loop
				running = false; break;
		}

		//Show it in a window
		cvShowImage("New Frame", newFrame);
		//Clean up
		cvReleaseImage(&newFrame);

	}

	//Clean up the capture object
	cvReleaseCapture(&capture);

        return 1;
}

/* Function to find the chessboard pattern in an image */
vector<CvPoint2D32f> findChessboard(IplImage *frame) {
	//Allocate some space to contain the found chessboard corners.
	//They are represented as a two dimensional floating point position (CvPoint2D32f)
	vector<CvPoint2D32f> chessboardCorners; chessboardCorners.resize(chessboardWidth*chessboardHeight);

	//Keep a count of how many corners we've found
	int foundCornerCount;

	//Find the chessboard
	int found = cvFindChessboardCorners(frame, cvSize(chessboardWidth, chessboardHeight), &chessboardCorners[0], &foundCornerCount);

	//Clone the image
	IplImage *clonedFrame = cvCloneImage(frame);
	//If found has returned 1, draw the chessboard
	cvDrawChessboardCorners(clonedFrame, cvSize(chessboardWidth, chessboardHeight), &chessboardCorners[0], foundCornerCount, found);
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
		return vector<CvPoint2D32f>();
	}
}

/* Function to capture chessboard corners */
void captureFrame(IplImage *frame, vector<CvPoint2D32f> corners) {
	//Create a new frame the same size and depth, but with only 1 channel (instead of the 3 for Red, Green, Blue)
	IplImage *frameBlackWhite = cvCreateImage(cvGetSize(frame), frame->depth, 1);
	//Convert the image from RGB to Grayscale
	cvConvertImage(frame, frameBlackWhite);

	//Find the Subpixel corners of the chessboard for increased accuracy
	cvFindCornerSubPix(frameBlackWhite, &corners[0], corners.size(), cvSize(11,11), cvSize(-1,-1), cvTermCriteria(CV_TERMCRIT_ITER+CV_TERMCRIT_EPS, 30, 0.01));

	//Add the corners to the list of all corners, and increment the number of frames
	allCorners.insert(allCorners.end(), corners.begin(), corners.end());
	numberFrames++;
}

/* Calibrate the Camera using the found corners */
void calibrateCamera(int width, int height) {
	//Initialise a vector the size of the chessboard
	vector<CvPoint3D32f> chessboardPoints; chessboardPoints.resize(chessboardWidth * chessboardHeight);
	//Loop through each corner and add it to the vecot of points
	for (int i=0; i<chessboardHeight; i++)
		for (int j=0; j<chessboardWidth; j++)
			chessboardPoints[i*chessboardWidth+j] = cvPoint3D32f(i*squareSize, j*squareSize, 0);

	//Copy the vector we just created into a new vector for each frame we created
	vector<CvPoint3D32f> allChessboardPoints;
	for (int i=0; i<numberFrames; i++)
		allChessboardPoints.insert(allChessboardPoints.end(), chessboardPoints.begin(), chessboardPoints.end());

	//Calculate the total number of points we have
	int totalPointCount = chessboardWidth * chessboardHeight * numberFrames;

	//Create two Matrices, one for the points on the chessboard, and one for the points we've found in the images
	CvMat mChessboardPoints = cvMat(1, totalPointCount, CV_32FC3, &allChessboardPoints[0] );
	CvMat mImagePoints = cvMat(1, totalPointCount, CV_32FC2, &allCorners[0] );

	//Create a new vector and encapsulating matrix for the point counts
	vector<int> pointCount; pointCount.resize(numberFrames, chessboardWidth * chessboardHeight);
	CvMat mpointCount = cvMat(1, pointCount.size(), CV_32S, &pointCount[0] );

	//Create some new matrices for the camera intrinsic parameters and distortion coefficents
    double cameraIntrinsic[9], distortionCoeffs[4];
    CvMat mCamMatrix = cvMat( 3, 3, CV_64F, cameraIntrinsic );
    CvMat mDistCoeffs = cvMat( 1, 4, CV_64F, distortionCoeffs );

	//Create a new matrix for the extrinsic parameters of the camera
	CvMat *extr_params = cvCreateMat( numberFrames, 6, CV_32FC1 );
	//Create two new matrices for the rotation vector and the translation vector
	CvMat rot_vects, trans_vects;
    cvGetCols( extr_params, &rot_vects, 0, 3 );
    cvGetCols( extr_params, &trans_vects, 3, 6 );

	//Perform calibration of the camera
    printf("Running stereo calibration ...\n");
	cvCalibrateCamera2(&mChessboardPoints, &mImagePoints, &mpointCount, cvSize(width, height), &mCamMatrix, &mDistCoeffs, &rot_vects, &trans_vects);
    printf("Done.\n");

	//Compute the error of the calibration
	computeError(&mChessboardPoints, &rot_vects, &trans_vects, &mCamMatrix, &mDistCoeffs, &mImagePoints, &mpointCount);

    // save intrinsic parameters
    CvFileStorage* fstorage = cvOpenFileStorage("camera.yml", NULL, CV_STORAGE_WRITE);
    cvWriteInt( fstorage, "image_width", width );
    cvWriteInt( fstorage, "image_height", height );
    cvWrite( fstorage, "camera_matrix", &mCamMatrix );
    cvWrite( fstorage, "distortion_coefficients", &mDistCoeffs );
    cvReleaseFileStorage(&fstorage);
}

/* Function to evaluate the error of the calibration */
void computeError(const CvMat* object_points, const CvMat* rot_vects, const CvMat* trans_vects,
        const CvMat* camera_matrix, const CvMat* dist_coeffs, const CvMat* image_points, const CvMat* point_counts)
{
	//Create a new matrix for the image points
	CvMat* image_points2 = cvCreateMat( image_points->rows, image_points->cols, image_points->type );
	//Variables to store the total error, and number of points we've seen so far
	double total_err = 0; int points_so_far = 0;

	//Loop through each frame
    for(int i = 0; i < numberFrames; i++ )
    {
        //Create some variables
		CvMat object_points_i, image_points_i, image_points2_i;
        int point_count = point_counts->data.i[i];
        CvMat rot_vect, trans_vect;

		//Grab the points from the chessboard, the points found in the current image, and the output
        cvGetCols( object_points, &object_points_i, points_so_far, points_so_far + point_count );
        cvGetCols( image_points,  &image_points_i,  points_so_far, points_so_far + point_count );
        cvGetCols( image_points2, &image_points2_i, points_so_far, points_so_far + point_count );

		//Increment the number of points we've seen so far
		points_so_far += point_count;

		//Get the current rotation and translation vectors
        cvGetRow( rot_vects, &rot_vect, i );
        cvGetRow( trans_vects, &trans_vect, i );

		//Project the object points based on the rotation and translation vector
        cvProjectPoints2( &object_points_i, &rot_vect, &trans_vect, camera_matrix, dist_coeffs, &image_points2_i);

		//Calculate the error of the estimated image points and the actual image points using L1 Norm
		total_err += cvNorm( &image_points_i, &image_points2_i, CV_L1 );
    }

	//Clean up
    cvReleaseMat( &image_points2 );

	//Print the total error
    printf( "avg err = %g\n", total_err/points_so_far );
}
