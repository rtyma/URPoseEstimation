//
// Created by robert on 22.02.18.
//

#ifndef UR_POSEESTIMATION_FOURPOINTSPOSE_H
#define UR_POSEESTIMATION_FOURPOINTSPOSE_H

#include <visp/vpDisplayGDI.h>
#include <visp/vpDisplayX.h>
#include <visp/vpDot2.h>
#include <visp/vpImageIo.h>
#include <visp/vpPixelMeterConversion.h>
#include <visp/vpPose.h>

class FourPointsPose {

public:

    FourPointsPose(vpCameraParameters c);
    virtual ~FourPointsPose();

    void computePose(std::vector<vpPoint> &point, const std::vector<vpDot2> &dot,bool init);

    void getPose(vpImage<unsigned char> &I);

    vpHomogeneousMatrix getHomogeneous();

private:
    vpCameraParameters cam;
    vpHomogeneousMatrix cMo;
};


#endif //UR_POSEESTIMATION_FOURPOINTSPOSE_H
