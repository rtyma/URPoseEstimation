//
// Created by robert on 20.02.18.
//

#include "../inc/Train.h"

Train::Train(vpImage<unsigned char> I)
{

}

Train::~Train()
{

}

void Train::BuildReference(vpImage<unsigned char> &I,vpMbEdgeTracker &tracker,std::string path,bool train)
{
    tracker.initClick(I,path,true);
    tracker.track(I);
}
