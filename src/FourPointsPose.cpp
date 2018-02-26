//
// Created by robert on 22.02.18.
//

#include "../inc/FourPointsPose.h"

FourPointsPose::FourPointsPose(vpCameraParameters c)
{
    this->cam=c;
}

FourPointsPose::~FourPointsPose()
{

}

void FourPointsPose::computePose(std::vector<vpPoint> &point, const std::vector<vpDot2> &dot, bool init)
{
    vpPose pose;
    double x=0, y=0;
    for (unsigned int i=0; i < point.size(); i ++) {
        vpPixelMeterConversion::convertPoint(this->cam, dot[i].getCog(), x, y);
        point[i].set_x(x);
        point[i].set_y(y);
        pose.addPoint(point[i]);
    }
    if (init == true) pose.computePose(vpPose::DEMENTHON_VIRTUAL_VS, this->cMo);
    else              pose.computePose(vpPose::VIRTUAL_VS, this->cMo) ;
}

void FourPointsPose::getPose(vpImage<unsigned char> &I)
{
    try {

        std::vector<vpDot2> dot(4);
        dot[0].initTracking(I, vpImagePoint(192, 157));
        dot[1].initTracking(I, vpImagePoint(203, 366));
        dot[2].initTracking(I, vpImagePoint(313, 402));
        dot[3].initTracking(I, vpImagePoint(304, 133));
        std::vector<vpPoint> point(4);
        point[0].setWorldCoordinates(-0.06, -0.06, 0);
        point[1].setWorldCoordinates( 0.06, -0.06, 0);
        point[2].setWorldCoordinates( 0.06,  0.06, 0);
        point[3].setWorldCoordinates(-0.06,  0.06, 0);
        bool init = true;

            vpDisplay::display(I);
            for (unsigned int i=0; i < dot.size(); i ++) {
                dot[i].setGraphics(true);
                dot[i].track(I);
            }
            computePose(point, dot, init);
            vpDisplay::displayFrame(I, this->cMo, this->cam, 0.05, vpColor::none);

            if (init) init = false; // turn off pose initialisation

    }
    catch(vpException e) {
        std::cout << "Catch an exception: " << e << std::endl;
    }
}

vpHomogeneousMatrix FourPointsPose::getHomogeneous()
{
    return this->cMo;
}