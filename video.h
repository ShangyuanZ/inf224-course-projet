
#ifndef VIDEO_H
#define VIDEO_H

#include<string>
#include<iostream>

#include"base.h"

class Video: public Base{

private:
    int duration = 0;

public:
    Video(){}
  // cause bug
  //  Video(std::string objetName, std::string fileName, int _duration) {
  //      Base(objetName,fileName); duration=_duration ;}

    Video(std::string objetName, std::string fileName, int _duration) :
        Base(objetName,fileName), duration(_duration) {}


    int getDuration() const {return duration;}

    void setDuration(int _duration) { duration=_duration;}

    void display(std::ostream & s) const override {s << "objetName : "<< getObjetName() << "\n"
                                                     << "fileName : " << getFileName()  << "\n"
                                                     << "duration : " << getDuration() << std::endl;}

    void objetDisplay() const override {std::string line = "mpv " + getFileName() + " &"; system(line.c_str());}

};

#endif // VIDEO_H

