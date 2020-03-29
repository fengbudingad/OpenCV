#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
//较低的版本无法使用cv::vector<>,需要使用std::vector<>;
#include<vector>
using namespace cv;
using namespace std;

bool Split_Merge();

int main(int argv,char** argc)
{
  if(Split_Merge())
  printf("success!");
  waitKey(0);
  destroyAllWindows();
  return 0;
}

bool Split_Merge()
{
  Mat srcImage=imread("/home/newdisk/picture_test/opencv_logo.jpg");
  if(!srcImage.data)
  {
    printf("error\n" );
    return false;
  }
  vector<Mat> channels;
  split(srcImage,channels);
  Mat imageBlue=channels.at(0);
  Mat imageGreen=channels.at(1);
  Mat imageRed=channels.at(2);
  Mat mergeImage;
  merge(channels,mergeImage);
  imshow("imageBlue",imageBlue);
  imshow("imageGreen",imageGreen);
  imshow("imageRed",imageRed);
  imshow("mergeImage",mergeImage);
  return true;
}
