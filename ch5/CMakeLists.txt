cmake_minimum_required(VERSION 3.19.0)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-O2")

# Eigen
find_package(Eigen3 REQUIRED)
# 寻找OpenCV库
find_package(OpenCV REQUIRED)
# 添加头文件
include_directories(${OpenCV_INCLUDE_DIRS})

add_subdirectory(imageBasics)
add_subdirectory(stereo)
add_subdirectory(rgbd)
