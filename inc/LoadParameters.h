//
// Created by robert on 21.02.18.
//

#ifndef UR_POSEESTIMATION_LOADPARAMETERS_H
#define UR_POSEESTIMATION_LOADPARAMETERS_H

#include <string>
#include <visp3/mbt/vpMbEdgeTracker.h>
#include <visp3/core/vpIoTools.h>

class LoadParameters {

public:
    LoadParameters(std::string path);
    virtual ~LoadParameters();

    vpCameraParameters cam;
    vpHomogeneousMatrix cMo;

    void Load(vpMbEdgeTracker &tracker);
    void Update(std::string path,vpMbEdgeTracker &tracker);

private:

    std::string name;
};


#endif //UR_POSEESTIMATION_LOADPARAMETERS_H
