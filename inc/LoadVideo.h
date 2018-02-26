//
// Created by robert on 14.02.18.
//

#ifndef UR_POSEESTIMATION_LOADVIDEO_H
#define UR_POSEESTIMATION_LOADVIDEO_H

#include <string>
#include <visp3/core/vpConfig.h>
#include <visp3/mbt/vpMbEdgeTracker.h>
#include <visp3/io/vpVideoReader.h>
#include <visp3/core/vpIoTools.h>
#include <opencv2/core/utility.hpp>

class LoadVideo {

public:
    std::string videoPath;

    vpImage<unsigned char> frame, frameResize;
    vpVideoReader video;

    LoadVideo(std::string path, int w,int h, bool camera, int index);
    void Refresh();

    void Close();

    vpImage<unsigned char>  getFrame();

    int width,height;

private:

    bool camera;
    cv::VideoCapture c;
};

#endif //UR_POSEESTIMATION_LOADVIDEO_H
