#ifndef MY_VIO_EUROC_H
#define MY_VIO_EUROC_H

#include "camera.hpp"
#include <fstream>
#include <opencv2/imgproc/imgproc.hpp>
#include <vector>

namespace my_vio
{
    class Euroc:public camera
    {
    public:
        Euroc(std::string path);
        ~Euroc() = default;
        cv::Mat getFrame() override;
    private:
        std::string path_;
        int frame_cnt_;
        std::vector<std::string> time_vec_;
    private:
        void split(const std::string& s,
                   std::vector<std::string>& sv,
                   const char delim);
    };
}


#endif //MY_VIO_EUROC_H
