#include <iostream>
#include "camera/Euroc.h"
using namespace my_vio;
int main()
{
    cv::Mat raw_pic;
    Euroc cam("/home/lyc/my_vins/mav0/cam0");
    while (1)
    {
        raw_pic = cam.getFrame();
        cv::imshow("raw",raw_pic);
        cv::waitKey(10);
    }
}
