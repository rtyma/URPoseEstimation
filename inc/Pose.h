//
// Created by robert on 14.02.18.
//

#ifndef UR_POSEESTIMATION_POSE_H
#define UR_POSEESTIMATION_POSE_H

#include <visp3/core/vpConfig.h>
#include <visp3/gui/vpDisplayX.h>
#include <visp3/gui/vpDisplayGDI.h>
#include <visp3/gui/vpDisplayOpenCV.h>
#include <visp3/mbt/vpMbEdgeTracker.h>
#include <visp3/io/vpVideoReader.h>
#include <visp3/vision/vpKeyPoint.h>
#include <visp3/core/vpIoTools.h>
#include <opencv2/core/utility.hpp>

class Pose {

public:

    Pose(std::string configuration,std::string learningData);
    virtual ~Pose();

    void getPose(vpImage<unsigned char> &I);
    void setParameters(vpCameraParameters c);
    void buildReference(vpImage<unsigned char> &I,std::string reference);
    void UpdateModel(std::string path);


    vpHomogeneousMatrix getHomogeneous();
    vpCameraParameters getCam();

    vpMbEdgeTracker tracker;
    vpRotationMatrix R;

private:
    vpCameraParameters cam;
    vpHomogeneousMatrix cMo;

    vpKeyPoint keypoint_detector;
    std::string configurationFile;
};

#endif //UR_POSEESTIMATION_POSE_H
