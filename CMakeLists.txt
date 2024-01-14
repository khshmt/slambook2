cmake_minimum_required(VERSION 3.20.0)
project("Visual_SLAM" LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11)

find_package(Eigen3 REQUIRED)
find_package(Pangolin REQUIRED)
find_package(Sophus REQUIRED)
find_package(fmt REQUIRED)

add_subdirectory(ch2)
add_subdirectory(ch3)
add_subdirectory(ch4)
