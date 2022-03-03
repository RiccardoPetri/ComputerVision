#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp> //for working with models (xml models of a face)
#include <iostream>

using namespace cv;
using namespace std;


///////////////  Images  //////////////////////

void main() {

	string path = "Resources/io.jpg";
	Mat imgResize, img = imread(path);
	

	resize(img, imgResize, Size(), 0.3, 0.3);

	CascadeClassifier faceCascade;

	faceCascade.load("Resources/haarcascade_frontalface_default.xml"); //load a classifier file

	if (faceCascade.empty()) { cout << "XML file not loaded" << endl; }

	vector<Rect> faces;
	faceCascade.detectMultiScale(imgResize, faces, 1.1, 10); //1.1 is the scale factor and 10 is the minimal neighbors  insert in faces the results

	for (int i = 0; i < faces.size(); i++)
	{
		rectangle(imgResize, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 3);
	}					//tl=top left point of rectagles

	imshow("Image", imgResize);
	waitKey(0);
}