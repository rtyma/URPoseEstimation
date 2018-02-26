//
// Created by robert on 22.02.18.
//

#ifndef UR_POSEESTIMATION_CONTROL_H
#define UR_POSEESTIMATION_CONTROL_H


class Control {

public:

    Control(int socket);
    virtual ~Control();

    void SetRobotPos(vpHomogeneousMatrix cMu);

private:

};


#endif //UR_POSEESTIMATION_CONTROL_H
