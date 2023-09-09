#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/imgcodecs.hpp>

using namespace std;
using namespace cv;
void main() {
    VideoCapture video(0);
    Mat img;
    CascadeClassifier facedetect;
    facedetect.load("C:/opencv/build/etc/haarcascades/haarcascade_frontalface_default.xml");

   
    if(!video.isOpened()){
        std::cout << "Camera is not opened";
       
    }

    while(true){
        video.read(img);
        vector<Rect> faces;
        facedetect.detectMultiScale(img,faces,1.3,5);
       
        for(int i=0;i<faces.size();i++){
            rectangle(img,faces[i].tl(),faces[i].br(),Scalar(50,50,255),3);
            rectangle(img,Point(0,0),Point(250,70),Scalar(50,50,255),FILLED);
            putText(img,to_string(faces.size())+"Face Found",Point(10,40),FONT_HERSHEY_DUPLEX,1,Scalar(255,255,255));
        }
        imshow("Frame",img);
        waitKey(1);
    }


}
