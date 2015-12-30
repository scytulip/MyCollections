#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>
#include <string>

using namespace cv;
using namespace std;

const string face_cascade_name("/usr/local/share/OpenCV/haarcascades/haarcascade_frontalface_alt.xml");
const string eyes_cascade_name("/usr/local/share/OpenCV/haarcascades/haarcascade_eye_tree_eyeglasses.xml");

CascadeClassifier face_cascade;
CascadeClassifier eyes_cascade;

/** @function detectAndDisplay */
int detectFace( Mat& frame )
{
    std::vector<Rect> faces;
    Mat frame_gray;

    // Convert to grey image
    cvtColor( frame, frame_gray, CV_BGR2GRAY );
    equalizeHist( frame_gray, frame_gray );

    //-- Detect faces
    face_cascade.detectMultiScale( frame_gray, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(30, 30) );

    if ( 0 == faces.size() ) return 0;

    for( size_t i = 0; i < faces.size(); i++ )
    {
        Point center( faces[i].x + faces[i].width*0.5, 
                faces[i].y + faces[i].height*0.5 );
        ellipse( frame, center, 
                Size( faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, 
                Scalar( 255, 0, 255 ), 4, 8, 0 );

        Mat faceROI = frame_gray( faces[i] );
        std::vector<Rect> eyes;

        //-- In each face, detect eyes
        eyes_cascade.detectMultiScale( faceROI, eyes, 1.1, 2, 0 |CV_HAAR_SCALE_IMAGE, Size(30, 30) );

        for( size_t j = 0; j < eyes.size(); j++ )
        {
            Point center( faces[i].x + eyes[j].x + eyes[j].width*0.5, 
                    faces[i].y + eyes[j].y + eyes[j].height*0.5 );
            int radius = cvRound( (eyes[j].width + eyes[j].height)*0.25 );
            circle( frame, center, radius, Scalar( 255, 0, 0 ), 4, 8, 0 );
        }
    }

    return faces.size();
}

int main( int argc, char** argv )
{

    // Load the cascades
    if( !face_cascade.load( face_cascade_name ) ){ printf("--(!)Error loading\n"); return -1; };
    if( !eyes_cascade.load( eyes_cascade_name ) ){ printf("--(!)Error loading\n"); return -1; };

    string imageName;
    if( argc > 1)
    {
        imageName = argv[1];
    }

    Mat image;
    image = imread(imageName.c_str(), IMREAD_COLOR); // Read the file

    if( image.empty() )                      // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }

    int faceNum = detectFace(image);
    cout << faceNum << " face(s) detected" << endl;
    cout << "in file " << imageName << endl;

    namedWindow( "Display window", WINDOW_AUTOSIZE ); // Create a window for display.
    imshow( "Display window", image );                // Show our image inside it.
    waitKey(0); // Wait for a keystroke in the window

    return (faceNum > 0) ? 0 : 1;
}
