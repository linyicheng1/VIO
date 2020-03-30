#ifndef __MY_VOI_CAMERA_H
#define __MY_VOI_CAMERA_H
#include <opencv2/opencv.hpp>
#include <string>
namespace my_vio
{
    class cameraParam
    {
    public:
        cameraParam() = default;
        ~cameraParam() = default;

        double fu;
        double fv;
        double cu;
        double cv;
    };
    class camera
    {
    public:
        camera() = default;
        ~camera() = default;
        virtual cv::Mat getFrame() = 0;
        cv::Mat frame_;
    };
}



#endif //__MY_VOI_CAMERA_H