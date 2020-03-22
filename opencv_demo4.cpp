#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace cv;

int main()
{
  //选取感兴趣区域；
  Mat img1=imread("/home/newdisk/picture_test/mountain.jpg");
  Mat imgBlended,imgROI;
  imgROI=img1(Rect(1/2*img1.cols,3/4*img1.rows,img1.cols,img1.rows));
  namedWindow("ROI",WINDOW_NORMAL);
  imshow("ROI",imgROI);
  waitKey(0);
  destroyWindow("ROI");
  imwrite("ROI.jpg",imgROI);
  return 0;
}
