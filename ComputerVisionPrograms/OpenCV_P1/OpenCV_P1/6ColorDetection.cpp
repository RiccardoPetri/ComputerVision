#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

///////////////  Color Detection  //////////////////////

void main() {

	string path = "Resources/shapes.png";
	Mat img = imread(path);
	Mat imgHSV, mask;														
	int hmin = 151, smin = 0, vmin = 1;				//hue = "tinta del colore"  (la tonalità è la porzione di colore del modello di colore, espressa come un numero compreso tra 0 e 360 gradi)
	int hmax = 179, smax = 255, vmax = 255;				//s = "saturazione" (quantità di grigio nel colore, da 0 a 100 percento.Ridurre la saturazione verso zero per introdurre più grigio produce un effetto sbiadito.)
														//v value= "intensità"  (Il valore funziona in combinazione con la saturazione e descrive la luminosità o l'intensità del colore, da 0 a 100 percento, dove 0 è
																			//completamente nero e 100 è il più luminoso e rivela il maggior numero di colori.
	cvtColor(img, imgHSV, COLOR_BGR2HSV);

	namedWindow("Trackbars", (640, 200));
	createTrackbar("Hue Min", "Trackbars", &hmin, 179);
	createTrackbar("Hue Max", "Trackbars", &hmax, 179);
	createTrackbar("Sat Min", "Trackbars", &smin, 255);
	createTrackbar("Sat Max", "Trackbars", &smax, 255);
	createTrackbar("Val Min", "Trackbars", &vmin, 255);
	createTrackbar("Val Max", "Trackbars", &vmax, 255);

	while (true) {
		
		Scalar lower(hmin, smin, vmin); //Scalar used as vector
		Scalar upper(hmax, smax, vmax);
		inRange(imgHSV, lower, upper, mask);	//mask will be the new output image after modifying the range from imhHSV (the white forms will be the chosen!!!)

		imshow("Image", img);
		imshow("Image HSV", imgHSV);
		imshow("Image Mask", mask);
		waitKey(1);
	}
}