#include "opencv2/highgui/highgui.hpp"
#include<iostream>
using namespace cv;
using namespace std;
int main(int argc, char** argv)
{
  Mat img=imread(argv[1]);
  if( img.empty() )
        return -1;
namedWindow( "Example1", cv::WINDOW_NORMAL);
std::cout << "hello" << endl ;
imshow( "Example1", img );
waitKey( 0 );
destroyWindow( "Example1" );
return 0;
}
