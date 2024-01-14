add_executable(useSophus useSophus.cpp)
target_link_libraries(useSophus Sophus::Sophus Eigen3::Eigen)

add_subdirectory(example)
