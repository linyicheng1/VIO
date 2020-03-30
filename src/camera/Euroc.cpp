#include "camera/Euroc.hpp"

namespace my_vio
{
    Euroc::Euroc(std::string path)
    :path_(path),frame_cnt_(0)
    {
        std::string csv_path = path_ + "/data.csv";
        std::ifstream data_csv;
        data_csv.open(csv_path.c_str());
        if(!data_csv)
        {
            std::cout<<"CSV read failed:"<<csv_path<<std::endl;
        }
        else
        {
            std::string raw;
            getline(data_csv,raw);
            while(getline(data_csv,raw))
            {
                std::vector<std::string> sv;
                split(raw,sv,',');
                time_vec_.push_back(sv.at(0));
            }
        }
    }
    cv::Mat Euroc::getFrame()
    {
        if(frame_cnt_>=time_vec_.size())
        {
            return  frame_;
        }
        std::stringstream ss;
        ss<<path_<<"/data/"<<time_vec_.at(frame_cnt_)<<".png";
        frame_ = cv::imread(ss.str());
        if(frame_.empty())
        {
            std::cout<<"can not get pic"<<ss.str()<<std::endl;
        }
        else
        {
            frame_cnt_ ++;
            return frame_;
        }
    }
    void Euroc::split(const std::string& s,
               std::vector<std::string>& sv,
               const char delim = ' ')
    {
        sv.clear();
        std::istringstream iss(s);
        std::string temp;

        while (std::getline(iss, temp, delim)) {
            sv.emplace_back(std::move(temp));
        }
    }
}

