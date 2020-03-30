#ifndef __MY_VIO_EUROC_IMU_H
#define __MY_VIO_EUROC_IMU_H

#include <Eigen/Dense>
#include <string>

namespace my_vio
{
    class imu
    {
    public:
        imu() = default;
        ~imu() = default;
        virtual Eigen::Vector3f getGyro();
        virtual Eigen::Vector3f getAcc();
        virtual void setGyroBias(Eigen::Vector3f bias);
        virtual void setAccBias(Eigen::Vector3f bias);
        Eigen::Vector3f acc_;
        Eigen::Vector3f gyro_;
        Eigen::Vector3f acc_bias_;
        Eigen::Vector3f gyro_bias_;
        float rate_;
        float gyro_noise_density_;
        float gyro_random_walk_;
        float acc_noise_density_;
        float acc_random_walk_;
    };
    class Euroc_imu:public imu
    {
    public:
        Euroc_imu(std::string path);
        Eigen::Vector3f getAcc() override;
        Eigen::Vector3f getGyro() override;
        void setAccBias(Eigen::Vector3f bias) override;
        void setGyroBias(Eigen::Vector3f bias) override;
    private:
        std::string path_;
    };
}


#endif //__MY_VIO_EUROC_IMU_H