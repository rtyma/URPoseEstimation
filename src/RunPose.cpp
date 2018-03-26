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

void RunPose::ConfigDisplay()
{
    //lp->Load(p->tracker);
    p->setParameters(lp->cam);

    display.init(lv->frame, 200, 200, "Pose estimator UR");

    lv->Refresh();
}

void RunPose::Config(std::string path,std::string reference)
{
    while (!vpDisplay::getClick(lv->frame, true)) {//change to false if use camera
        lv->Refresh();
        vpDisplay::display(lv->frame);
        vpDisplay::flush(lv->frame);
    }

    std::unique_ptr<Train> t = std::make_unique<Train>(lv->frame);
    t->BuildReference(lv->frame, p->tracker, path, true);

    p->buildReference(lv->frame,reference);
}

void RunPose::GetPose()
{
        lv->Refresh();

        vpDisplay::display(lv->frame);
        p->getPose(lv->frame);
        vpDisplay::flush(lv->frame);

        vpRotationMatrix R;

        vpPoseVector pose(p->getHomogeneous());
        this->pose=pose;

        if (vpDisplay::getClick(lv->frame, false)) {
            lv->Close();
        }
}

void RunPose::UpdateModel(std::string parameters,std::string model)
{
    p->UpdateModel(model);
    lp->Update(parameters,p->tracker);
    lp->Load(p->tracker);
}
