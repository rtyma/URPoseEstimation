//
// Created by robert on 14.02.18.
//

#include "../inc/LoadVideo.h"

LoadVideo::LoadVideo(std::string path, int w,int h,bool c,int index)
{
    this->camera=c;
    if(camera==false) {
        this->width = w;
        this->height = h;

        this->frame.init(w, h);
        this->videoPath = path;

        this->video.setFileName(this->videoPath);

        this->video.open(this->frame);

        vpImage<unsigned char> temp;

        this->video.acquire(temp);

        vpImageTools::resize(temp, this->frame, this->width, this->height);
    }

    else if(camera==true) {
        this->c.open(index); // open the default camera
        cv::Mat img;
        this->c >> img;
        vpImageConvert::convert(img, this->frame);
    }
}

vpImage<unsigned char>  LoadVideo::getFrame()
{

}

void LoadVideo::Refresh()
{
    if(this->camera==false) {
        vpImage<unsigned char> temp(this->width, this->height);
        this->video.acquire(temp);

        vpImageTools::resize(temp, this->frame, this->width, this->height);
    }
    else if(this->camera==true)
    {
        cv::Mat img;
        this->c >> img;
        vpImageConvert::convert(img, this->frame);
    }
}