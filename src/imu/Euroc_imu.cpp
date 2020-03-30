#include <imu/Euroc_imu.hpp>
#include <fstream>
#include <iostream>

namespace my_vio
{
    Euroc_imu::Euroc_imu(std::string path)
    :path_(path)
    {
        std::string param_path = path_ + "/sensor.yaml";
        std::ifstream param_file;
        param_file.open(param_path.c_str());
        if(!param_file)
        {
            std::cout<<"param file read failed:"<<param_path<<std::endl;
        }

    }
    void Euroc_imu::setAccBias(Eigen::Vector3f bias)
    {
        acc_bias_ = bias;
    }
    void Euroc_imu::setGyroBias(Eigen::Vector3f bias)
    {
        gyro_bias_ = bias;
    }
    Eigen::Vector3f Euroc_imu::getAcc()
    {
        return (acc_ - acc_bias_);
    }
    Eigen::Vector3f Euroc_imu::getGyro()
    {
        return (gyro_ - gyro_bias_);
    }
}
