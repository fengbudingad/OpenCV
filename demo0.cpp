#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace cv;

int main()
{
    //图像的载入和显示
    Mat img=imread("/home/newdisk/picture_test/opencv_logo.png",1);
    Mat imgGray=imread("/home/newdisk/picture_test/opencv_logo.png",0);
    namedWindow("the logo of opencv",WINDOW_NORMAL);
    namedWindow("the gray logo of opencv",WINDOW_AUTOSIZE);
    imshow("the logo of opencv",img);
    imshow("the gray logo of opencv",imgGray);
    waitKey(0);
    destroyAllWindows();
    return 0;
}
