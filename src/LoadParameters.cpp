//
// Created by robert on 21.02.18.
//

#include "../inc/LoadParameters.h"

LoadParameters::LoadParameters(std::string path)
{
    this->name=path;
}

LoadParameters::~LoadParameters()
{

}

void LoadParameters::Load(vpMbEdgeTracker &tracker)
{
    if(vpIoTools::checkFilename(this->name + ".xml")) {
        tracker.loadConfigFile(this->name + ".xml");
        tracker.getCameraParameters(this->cam);
    }
    if(vpIoTools::checkFilename(this->name + ".cao"))
        tracker.loadModel(this->name + ".cao");
    else if(vpIoTools::checkFilename(this->name + ".wrl"))
        tracker.loadModel(this->name + ".wrl");
}