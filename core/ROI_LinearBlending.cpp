#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<iostream>
using namespace cv;
using namespace std;
bool ROI_LinearBlending(float Alpha=0.5,float Beta=0.5)
{
  Mat srcImag=imread("/home/newdisk/picture_test/mountain.jpg");
  Mat logoImag=imread("/home/newdisk/picture_test/opencv_logo.jpg");

  if(!srcImag.data)
  {
    printf("error\n" );
    return false;
  }
  if(!logoImag.data)
  {
    printf("error\n" );
    return false;
  }

  Mat imageROI;
  imageROI=srcImag(Rect(200,300,logoImag.cols,logoImag.rows));
  //imageROI=srcImag(Range(300,300+logoImag.rows),Range(200,200+logoImag.rows));
  addWeighted(imageROI,Alpha,logoImag,Beta,0.0,imageROI);

  namedWindow("roi_blending",WINDOW_NORMAL);
  imshow("roi_blending",srcImag);

  return true;
}

int main(int argv,char** argc)
{
  if(ROI_LinearBlending(0.3,0.7))
  cout<<"运行成功"<<endl;
  waitKey(0);
  destroyAllWindows();
  return 0;
}
