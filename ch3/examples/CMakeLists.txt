find_package(Eigen3 REQUIRED)
find_package(Pangolin REQUIRED)

include_directories(${Pangolin_INCLUDE_DIRS})

add_executable(coordinateTransform coordinateTransform.cpp)

add_executable(plotTrajectory plotTrajectory.cpp)
target_link_libraries(plotTrajectory ${Pangolin_LIBRARIES} Eigen3::Eigen)
