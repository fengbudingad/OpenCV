#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace cv;
bool ROI_AddImage()
{
  Mat srcImag=imread("/home/newdisk/picture_test/star.jpg");
  Mat logoImag=imread("/home/newdisk/picture_test/opencv_logo.jpg");
  if(!srcImag.data)
  {
    printf("读取图片失败\n");
    return false;
  }
  if(!logoImag.data)
  {
    printf("读取图片失败\n");
    return false;
  }

  Mat imageROI=srcImag(Rect(200,300,logoImag.cols,logoImag.rows));
  Mat mask=imread("/home/newdisk/picture_test/opencv_logo.jpg",0);
  logoImag.copyTo(imageROI,mask);

  namedWindow("利用ROI进行图像叠加",WINDOW_NORMAL);
  imshow("利用ROI进行图像叠加",srcImag);
  waitKey(0);
  destroyAllWindows();

  return true;
}
int main(int argv, char** argc)
{
  ROI_AddImage();
  return 0;
}
