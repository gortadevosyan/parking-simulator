

#ifndef P3_GROUP_H
#define P3_GROUP_H

#include "figure/Figure.h"
#include "figure/Trajectory.h"

enum class GroupType {
    PMS_CAR = 1, PMS_BICYCLE = 2, PMS_MOTORBIKE = 3, PMS_VAN = 4,
    IPA_CAR=5, IPA_SPACECRAFT = 6, IPA_TELEPORTED = 7, IPA_UFO = 8
};

class Group : public Figure {
protected:
    int id;    // group id
    int size;  // group size
    GroupType groupType; // group type
    time_t time; // time to enter
    int duration; // if duration=-1, use real time; else use duration as time simulation

    Vec adjustParam;
    float stepScale;
    int stepAddition;

//    Trajectory trajectory;
public:
    Group();
    std::string getTypeStr();

//    void addTrajectory();
//
//    void addTrajectory(Vec vec);
//
//    void addHistory(Vec vec);

    // virtual functions;

    virtual void draw() override;

    virtual void rotate(float angle) override;

    virtual void moveTo(Vec dir);

    virtual void move(Vec dir) override;

    virtual void zoom(float scale,Vec vec) override;

    virtual void drawTrajectory(int mode,float theta,int size);

    virtual Trajectory *getTrajectory();

    // getter & setter

    GroupType getGroupType() const;

    void setGroupType(GroupType groupType);

    int getId() const;

    void setId(int id);

    time_t getTime() const;

    void setTime(time_t time);

    float getStepScale() const;

    void setStepScale(float stepScale);

    const Vec &getAdjustParam() const;

    void setAdjustParam(const Vec &adjustParam);

    int getSize() const;

    void setSize(int size);

    int getDuration() const;

    void setDuration(int duration);

    int getStepAddition() const;

    void setStepAddition(int stepAddition);

    Group(int id, int size, time_t time);


//
//    void setTrajectory(const Trajectory &trajectory);

};


#endif //P3_GROUP_H
