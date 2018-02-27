//
// Created by robert on 27.02.18.
//

#ifndef UR_POSEESTIMATION_RUNPOSE_H
#define UR_POSEESTIMATION_RUNPOSE_H

#include <iostream>
#include <memory>
#include <visp3/gui/vpDisplayX.h>
#include "LoadVideo.h"
#include "Pose.h"
#include "Train.h"
#include "LoadParameters.h"
#include "FourPointsPose.h"

#define W 640
#define H 480

class RunPose {

public:
    RunPose();
    ~RunPose();
    vpDisplayX display;
    void displayImage(vpImage<unsigned char> image);

    void Config();

    void GetPose();
    vpPoseVector pose;

private:
    int flag=0;

    std::unique_ptr<LoadVideo> lv = std::make_unique<LoadVideo>("./teabox/teabox.mpg", W, H, true, 1);
    std::unique_ptr<Pose> p = std::make_unique<Pose>("detection-config.xml");
    std::unique_ptr<LoadParameters> lp = std::make_unique<LoadParameters>("./teabox/teabox");

};


#endif //UR_POSEESTIMATION_RUNPOSE_H
