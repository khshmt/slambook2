include_directories(${Pangolin_INCLUDE_DIRS})

add_executable(visualizeGeometry visualizeGeometry.cpp)
target_link_libraries(visualizeGeometry ${Pangolin_LIBRARIES} Eigen3::Eigen)
