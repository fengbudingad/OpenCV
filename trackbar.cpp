#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace cv;

#define WINDOW_NAME "线性混合实例与滑动条的创建"

//声明全局变量
const int g_nMaxAlphaValue=100;
int g_nAlphaValueSlider;
double g_dAlphaValue;
double g_dBetaValue;

//声明储存图像的变量
Mat g_srcImage1;
Mat g_srcImage2;
Mat g_dstImage;

//相应滑动条的回调函数
void onTrackbar(int,void*)
{
  //此处注意类型转换
  g_dAlphaValue=(double)g_nAlphaValueSlider/g_nMaxAlphaValue;
  g_dBetaValue=1.0-g_dAlphaValue;
  addWeighted(g_srcImage1,g_dAlphaValue,g_srcImage2,g_dBetaValue,0.0,g_dstImage);
  imshow(WINDOW_NAME,g_dstImage);
}

int main(int  argc, char** argv)
{
  g_srcImage1=imread("/home/newdisk/picture_test/sunset.jpg");
  g_srcImage2=imread("/home/newdisk/picture_test/star.jpg");
  if(!g_srcImage1.data)
  {
    printf("读取第一幅图像失败\n");
    return -1;
  }
  if(!g_srcImage2.data)
  {
    printf("读取第二幅图像失败\n");
    return -1;
  }

  g_nAlphaValueSlider=70;
  namedWindow(WINDOW_NAME,WINDOW_NORMAL);

  char TrackbarName[50];
  sprintf(TrackbarName,"透明值 %d",g_nAlphaValueSlider);

  createTrackbar(TrackbarName,WINDOW_NAME,&g_nAlphaValueSlider,g_nMaxAlphaValue,onTrackbar);
  onTrackbar(g_nAlphaValueSlider,0);

  waitKey(0);
  destroyAllWindows();
  return 0;
}
