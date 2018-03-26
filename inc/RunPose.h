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

#define W 640
#define H 480

class RunPose {

public:
    RunPose();
    ~RunPose();
    vpDisplayX display;
    void displayImage(vpImage<unsigned char> image);

    void ConfigDisplay();
    void Config(std::string path,std::string reference);

    void GetPose();
    void UpdateModel(std::string parameters,std::string model);
    vpPoseVector pose;

private:
    int flag=0;

    std::unique_ptr<LoadVideo> lv=std::make_unique<LoadVideo>("./teabox.mpg", W, H, true, 1);
    std::unique_ptr<Pose> p= std::make_unique<Pose>("./detector_little/detection-config-SIFT.xml","./detector_little/object_learning_data.bin");
    std::unique_ptr<LoadParameters> lp= std::make_unique<LoadParameters>("./object_little/elastic");
};


#endif //UR_POSEESTIMATION_RUNPOSE_H
