cmake_minimum_required(VERSION 2.8.3)
set(CMAKE_CXX_STANDARD 11)
project(my_vio)

find_package(Eigen3 REQUIRED)
find_package(Ceres REQUIRED)
find_package(Pangolin REQUIRED)
find_package(OpenCV REQUIRED)
find_package(Boost REQUIRED COMPONENTS filesystem program_options system)

message(WARNING "OpenCV_VERSION: ${OpenCV_VERSION}")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
include_directories(
        inc
        ${OpenCV_INCLUDE_DIRS}
        /usr/include/eigen3
)

add_library(
        MY_LIB
        src/camera/Euroc.cpp
        src/imu/Euroc_imu.cpp
)

add_executable(
    my_vio
    src/main.cpp
)
target_link_libraries(
        my_vio
        MY_LIB
        ${OpenCV_LIBS}
)
