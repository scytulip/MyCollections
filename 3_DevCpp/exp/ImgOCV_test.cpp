//! [includes]
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>
#include <string>
//! [includes]

//! [namespace]
using namespace cv;

using namespace std;

int main( int argc, char** argv )
{
    //! [load]
    string imageName("logo.png"); // by default
    if( argc > 1)
    {
        imageName = argv[1];
    }

    //! [mat]
    Mat image;

    //! [imread]
    image = imread(imageName.c_str(), IMREAD_COLOR); // Read the file

    if( image.empty() )                      // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }

    //! [window]
    namedWindow( "Display window", WINDOW_AUTOSIZE ); // Create a window for display.

    //! [imshow]
    imshow( "Display window", image );                // Show our image inside it.

    //! [wait]
    waitKey(0); // Wait for a keystroke in the window

    return 0;
}
