#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace cv;

bool LinearBlending(float Alpha=0.5,float Beta=0.5)
{
  Mat srcImag1=imread("/home/newdisk/picture_test/star.jpg");
  Mat srcImag2=imread("/home/newdisk/picture_test/mountain.jpg");
  if(!srcImag1.data)
  {
    printf("error!");
    return false;
  }
  if(!srcImag2.data)
  {
    printf("error\n" );
    return false;
  }
  Mat dst;
addWeighted(srcImag1,Alpha,srcImag2,Beta,0.0,dst);

namedWindow("blending",WINDOW_NORMAL);
imshow("blending",dst);
waitKey(0);
destroyAllWindows();
}

int main(int argv,char** argc)
{
  LinearBlending(0.3,0.7);
  return 0;
}
