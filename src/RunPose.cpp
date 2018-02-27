//
// Created by robert on 27.02.18.
//

#include "../inc/RunPose.h"



RunPose::RunPose()
{

}

RunPose::~RunPose()
{

}

void RunPose::Config()
{
    lp->Load(p->tracker);
    p->setParameters(lp->cam);

    display.init(lv->frame, 200, 200, "Pose estimator UR");

    lv->Refresh();

    while (!vpDisplay::getClick(lv->frame, false)) {
        lv->Refresh();
        vpDisplay::display(lv->frame);
        vpDisplay::flush(lv->frame);
    }

    std::unique_ptr<Train> t = std::make_unique<Train>(lv->frame);
    t->BuildReference(lv->frame, p->tracker, "./teabox/teabox.init", true);

    p->buildReference(lv->frame);
}

void RunPose::GetPose()
{
    //while (1) {

        lv->Refresh();

        vpDisplay::display(lv->frame);
        p->getPose(lv->frame);
        vpDisplay::flush(lv->frame);

        vpRotationMatrix R;

        vpPoseVector pose(p->getHomogeneous());
        this->pose=pose;
        //std::cout << "Pose: " << pose << std::endl; //w metrach przesunięcia, w radianach rotacje

        if (vpDisplay::getClick(lv->frame, false)) {
            lv->Close();
            //break;
        }
    //}
}

