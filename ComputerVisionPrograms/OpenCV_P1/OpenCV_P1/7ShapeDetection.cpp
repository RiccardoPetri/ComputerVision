#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

///////////////  Shape/contour Detection  //////////////////////

void getContours(Mat imgDil, Mat img) {		//img is the image where i want to draw on

	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;	//vector with 4 integer values

	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	//drawContours(img, contours, -1, Scalar(255, 0, 255), 2);	//-1 for draw all of the contours and 2 is the ticnkness of the contour

	vector<vector<Point>> conPoly(contours.size()); //vector of corners
	vector<Rect> boundRect(contours.size());

	for (int i = 0; i < contours.size(); i++) //loop for eliminate noise(small areas founded)
	{
		int area = contourArea(contours[i]);
		cout << area << endl;
		string objectType;

		if (area > 1000)
		{
			float peri = arcLength(contours[i], true);	//this function calculate the perimeterer... true if the shape is closed
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);	//calculate corner points given the points, and the epsilon(accuracy), conPoly[i] is the output
			cout << conPoly[i].size() << endl;
			boundRect[i] = boundingRect(conPoly[i]);	//create a rectangle from the given points of the shape, and store it in the array boundRect

			int objCor = (int)conPoly[i].size(); //finding what shape is ( 3 points = a triangle)

			if (objCor == 3) { objectType = "Tri"; }
			else if (objCor == 4) //distinguishing square and rectangle
			{
				float aspRatio = (float)boundRect[i].width / (float)boundRect[i].height;
				cout << aspRatio << endl;
				if (aspRatio > 0.95 && aspRatio < 1.05) { objectType = "Square"; }
				else { objectType = "Rect"; }
			}
			else if (objCor > 4) { objectType = "Circle"; }

			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);	//this will be draw not all the contour because conPoly contains only corner point, so this method draw lines joining points
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5); //print the rectangle on img, assigned the values of the top-left and bottom-right points founded earlier
			putText(img, objectType, { boundRect[i].x,boundRect[i].y - 5 }, FONT_HERSHEY_PLAIN, 1, Scalar(0, 69, 255), 2);
		}
	}
}


void main() {

	string path = "Resources/shapes.png";
	Mat img = imread(path);
	Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;

	// Preprocessing
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
	Canny(imgBlur, imgCanny, 25, 75);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDil, kernel);

	getContours(imgDil, img);

	imshow("Image", img);
	//imshow("Image Gray", imgGray);
	//imshow("Image Blur", imgBlur);
	//imshow("Image Canny", imgCanny);
	//imshow("Image Dil", imgDil);

	waitKey(0);

}