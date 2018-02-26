//
// Created by robert on 20.02.18.
//

#ifndef UR_POSEESTIMATION_TRAIN_H
#define UR_POSEESTIMATION_TRAIN_H

#include <visp3/core/vpConfig.h>
#include <visp3/gui/vpDisplayX.h>
#include <visp3/gui/vpDisplayGDI.h>
#include <visp3/gui/vpDisplayOpenCV.h>
#include <visp3/mbt/vpMbEdgeTracker.h>
#include <visp3/io/vpVideoReader.h>
#include <visp3/vision/vpKeyPoint.h>
#include <visp3/core/vpIoTools.h>
#include <opencv2/core/utility.hpp>

class Train {

public:
    Train(vpImage<unsigned char> I);
    virtual ~Train();

    void BuildReference(vpImage<unsigned char> &I,vpMbEdgeTracker &tracker,std::string path,bool train=false);

};


#endif //UR_POSEESTIMATION_TRAIN_H
