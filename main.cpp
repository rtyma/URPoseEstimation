#include <iostream>
#include <memory>
#include <visp3/gui/vpDisplayX.h>
#include "inc/LoadVideo.h"
#include "inc/Pose.h"
#include "inc/Train.h"
#include "inc/LoadParameters.h"
#include "inc/FourPointsPose.h"

#define W 640
#define H 480

vpDisplayX display;
vpDisplayX display2;

void displayImage(vpImage<unsigned char> image)
{
    vpDisplay::display(image);
    display.flush(image);
}

int main() {

    std::unique_ptr<LoadVideo> lv = std::make_unique<LoadVideo>("./teabox/teabox.mpg",W,H,false,0);
    std::unique_ptr<Pose> p = std::make_unique<Pose>("detection-config.xml");
    std::unique_ptr<LoadParameters> lp = std::make_unique<LoadParameters>("./teabox/teabox");
    lp->Load(p->tracker);
    p->setParameters(lp->cam);

    display.init(lv->frame, 200, 200,"Pose estimator UR");

    lv->Refresh();

    std::unique_ptr<Train> t = std::make_unique<Train>(lv->frame);
    t->BuildReference(lv->frame,p->tracker,"./teabox/teabox.init",true);

    p->buildReference(lv->frame);


    vpImage<unsigned char> I;
    vpImageIo::read(I, "square.pgm");

    std::unique_ptr<FourPointsPose> fp = std::make_unique<FourPointsPose>(p->getCam());
    display2.init(I, 200, 200,"Four point estimator");


    while(1) {

        lv->Refresh();

        vpDisplay::display(lv->frame);
        p->getPose(lv->frame);
        vpDisplay::flush(lv->frame);

        vpDisplay::display(I);
        fp->getPose(I);
        vpDisplay::flush(I);

        //std::cout<<"Rotation: "<<p->getHomogeneous().data[0]<<std::endl;//wydobycie wartości
        //std::cout<<"Rotation2: "<<fp->getHomogeneous()<<std::endl;

        //vpHomogeneousMatrix diff().da=fp->getHomogeneous().data-fp->getHomogeneous().data;
        vpRotationMatrix R;
        fp->getHomogeneous().extract(R);

        vpPoseVector pose(p->getHomogeneous());
        std::cout<<"Pose: "<<pose<<std::endl;
        //std::cout<<"Difference: "<<fp->getHomogeneous()-fp->getHomogeneous()<<std::endl;

        if(vpDisplay::getClick(lv->frame,false))
        {
            break;
        }
    }
    return 0;
}