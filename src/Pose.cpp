//
// Created by robert on 14.02.18.
//

#include "../inc/Pose.h"

Pose::Pose(std::string configuration,std::string learningData)
{

#if (defined(VISP_HAVE_OPENCV_NONFREE) || defined(VISP_HAVE_OPENCV_XFEATURES2D))
    this->configurationFile = configuration;
#endif

    this->keypoint_detector.loadConfigFile(configurationFile);
    this->keypoint_detector.loadLearningData(learningData, true);
}

Pose::~Pose()
{

}

void Pose::getPose(vpImage<unsigned char> &I)
{
    double error, elapsedTime;

    if(this->keypoint_detector.matchPoint(I, this->cam, this->cMo, error, elapsedTime)) {
        tracker.setPose(I, cMo);
        tracker.display(I, cMo, cam, vpColor::green, 5);
        vpDisplay::displayFrame(I, cMo, cam, 0.025, vpColor::none, 3);

        cMo.extract(this->R);
    }
}

void Pose::setParameters(vpCameraParameters c)
{
    this->cam=c;
}

void Pose::buildReference(vpImage<unsigned char> &I,std::string reference)
{
    vpKeyPoint keypoint_learning;
    keypoint_learning.loadConfigFile(configurationFile);

    std::vector<cv::KeyPoint> trainKeyPoints;
    double elapsedTime;
    keypoint_learning.detect(I, trainKeyPoints, elapsedTime);
    std::vector<vpPolygon> polygons;
    std::vector<std::vector<vpPoint> > roisPt;
    std::pair<std::vector<vpPolygon>, std::vector<std::vector<vpPoint> > > pair = tracker.getPolygonFaces(false);
    polygons = pair.first;
    roisPt = pair.second;
    std::vector<cv::Point3f> points3f;
    tracker.getPose(cMo);
    vpKeyPoint::compute3DForPointsInPolygons(cMo, cam, trainKeyPoints, polygons, roisPt, points3f);
    keypoint_learning.buildReference(I, trainKeyPoints, points3f);
    keypoint_learning.saveLearningData(reference, true);
    vpDisplay::display(I);
    for(std::vector<cv::KeyPoint>::const_iterator it = trainKeyPoints.begin(); it != trainKeyPoints.end(); ++it) {
        vpDisplay::displayCross(I, (int) it->pt.y, (int) it->pt.x, 4, vpColor::red);
    }
    vpDisplay::displayText(I, 10, 10, "Learning step: keypoints are detected on visible teabox faces", vpColor::red);
    vpDisplay::displayText(I, 30, 10, "Click to continue with detection...", vpColor::red);
    vpDisplay::flush(I);
    vpDisplay::getClick(I, true);
    vpKeyPoint keypoint_detection;

    this->keypoint_detector.loadLearningData(reference, true);
}

vpHomogeneousMatrix Pose::getHomogeneous()
{
    return this->cMo;
}

vpCameraParameters Pose::getCam()
{
    return this->cam;
}

void Pose::UpdateModel(std::string path)
{

    this->keypoint_detector.loadLearningData(path, true);
}
