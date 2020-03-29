#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace cv;

void ContrastAndBright(int,void*);
int g_nContrastValue;
int g_nBrightValue;
Mat g_srcImage,g_dstImage;

int main(int argc,char** argv)
{
  g_srcImage=imread("/home/newdisk/picture_test/mountain.jpg");
  if(!g_srcImage.data)
  {
    printf("input image error\n" );
    return -1;
  }
  g_dstImage=Mat::zeros(g_srcImage.size(),g_srcImage.type());
//全局变量初始化；
  g_nContrastValue=80;
  g_nBrightValue=80;

  namedWindow("window",WINDOW_NORMAL);
//创建两个滑动条；
  createTrackbar("contrast:","window",&g_nContrastValue,300,ContrastAndBright);
  createTrackbar("bright:","window",&g_nBrightValue,200,ContrastAndBright);
//回调函数初始化；
  ContrastAndBright(g_nContrastValue,0);
  ContrastAndBright(g_nBrightValue,0);
  while(char(waitKey(10)!='q')){}
  destroyAllWindows();
  return 0;
}

void ContrastAndBright(int,void*)
{
  namedWindow("original image",WINDOW_NORMAL);
  for(int y=0;y<g_srcImage.rows;y++)
  {
    for(int x=0;x<g_srcImage.cols;x++)
    {
      for(int c=0;c<3;c++)
      {
          g_dstImage.at<Vec3b>(y,x)[c]=saturate_cast<uchar>((g_nContrastValue*0.01)*(g_srcImage.at<Vec3b>(y,x)[c])
          +g_nBrightValue);
          //saturate_cast对数值进行标准化，保证数值为【0,255】的整数型；滑动条一次只能调整整数值，为方便乘上0.01；
      }
    }
  }
  imshow("original image",g_srcImage);
  imshow("window",g_dstImage);
}
