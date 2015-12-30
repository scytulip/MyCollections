#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>
#include <string>

using namespace cv;
using namespace std;

const string body_cascade_name("/usr/local/share/OpenCV/haarcascades/haarcascade_fullbody.xml");

CascadeClassifier body_cascade;

/** @function detectAndDisplay */
int detectBody( Mat& frame )
{
    std::vector<Rect> bodies;
    Mat frame_gray;

    // Convert to grey image
    cvtColor( frame, frame_gray, CV_BGR2GRAY );
    equalizeHist( frame_gray, frame_gray );

    //-- Detect bodies
    body_cascade.detectMultiScale( frame_gray, bodies, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(30, 30) );

    if ( 0 == bodies.size() ) return 0;

    for( size_t i = 0; i < bodies.size(); i++ )
    {
        Point center( bodies[i].x + bodies[i].width*0.5, 
                bodies[i].y + bodies[i].height*0.5 );
        ellipse( frame, center, 
                Size( bodies[i].width*0.5, bodies[i].height*0.5), 0, 0, 360, 
                Scalar( 255, 0, 255 ), 4, 8, 0 );
    }

    return bodies.size();
}

int main( int argc, char** argv )
{

    // Load the cascades
    if( !body_cascade.load( body_cascade_name ) ){ printf("--(!)Error loading\n"); return -1; };

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

    int bodyNum = detectBody(image);
    cout << bodyNum << " body(s) detected" << endl;
    cout << "in file " << imageName << endl;

    namedWindow( "Display window", WINDOW_AUTOSIZE ); // Create a window for display.
    imshow( "Display window", image );                // Show our image inside it.
    waitKey(0); // Wait for a keystroke in the window

    return (bodyNum > 0) ? 0 : 1;
}
