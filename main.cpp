#include <iostream>
#include <memory>
#include <visp3/gui/vpDisplayX.h>
#include "inc/RunPose.h"

vpDisplayX display;

int main(int argc, char* argv[]) {

    std::string models[3]={"./object_little/elastic","./object_medium/elastic","./object_high/elastic"};
    std::string configs[3]={"./detector_little/object_learning_data.bin","./detector_medium/object_learning_data.bin","./detector_high/object_learning_data.bin"};
    std::string mod[3]={"./object_little/elastic","./object_medium/elastic","./object_high/elastic"};

    int modelNumber=2;

    std::cout<<"sciezka: "<<configs[modelNumber]<<std::endl;

    std::unique_ptr<RunPose> rp = std::make_unique<RunPose>();

    rp->UpdateModel(mod[modelNumber],configs[modelNumber]);

    rp->ConfigDisplay();


    //if(strcmp(argv[1],"t")==0) {
        rp->Config(mod[modelNumber],configs[modelNumber]);
    //}

    //rp->UpdateModel(models[2],configs[2]);

    int i=0;

    while(1) {
        rp->GetPose();
        std::cout << "Pose: " << rp->pose << std::endl;//w metrach przesunięcia, w radianach rotacje
    }
    return 0;
}