#include <iostream>
#include <memory>
#include <visp3/gui/vpDisplayX.h>
#include "inc/RunPose.h"

vpDisplayX display;

int main(int argc, char* argv[]) {

    std::unique_ptr<RunPose> rp = std::make_unique<RunPose>();
    rp->Config();

    while(1) {
        rp->GetPose();
        std::cout << "Pose: " << rp->pose << std::endl; //w metrach przesunięcia, w radianach rotacje
    }
    return 0;
}