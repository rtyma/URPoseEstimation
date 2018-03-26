cmake_minimum_required(VERSION 3.5)
project(UR_PoseEstimation)

find_package(VISP REQUIRED)

set(CMAKE_CXX_STANDARD 14)

include_directories(${VISP_INCLUDE_DIRS})

set(SOURCE_FILES main.cpp src/Pose.cpp inc/Pose.h src/LoadVideo.cpp inc/LoadVideo.h src/Train.cpp inc/Train.h src/LoadParameters.cpp inc/LoadParameters.h src/RunPose.cpp inc/RunPose.h)
add_executable(UR_PoseEstimation ${SOURCE_FILES})
target_link_libraries(UR_PoseEstimation ${VISP_LIBRARIES})
