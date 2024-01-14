include_directories(${Pangolin_INCLUDE_DIRS})
add_executable(trajectoryError trajectoryError.cpp)
target_link_libraries(trajectoryError ${Pangolin_LIBRARIES} fmt::fmt Sophus::Sophus Eigen3::Eigen)
