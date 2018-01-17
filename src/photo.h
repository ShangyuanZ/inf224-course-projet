#ifndef PHOTO_H
#define PHOTO_H

#include<string>
#include<iostream>

#include"base.h"

class Photo: public Base{

private:
    float latitude = 0.0f;
    float longitude = 0.0f;

public:
    Photo(){}

    Photo(std::string objetName, std::string fileName, float _latitude, float _longitude):
        Base(objetName, fileName), latitude(_latitude), longitude(_longitude) {}

    float getLatitude() const {return latitude;}

    float getLongitude() const {return longitude;}

    void setLatitude(float _latitude) {latitude=_latitude;}

    void setLongitude(float _longitude) {longitude=_longitude;}

    void display(std::ostream & s) const override {s << "objetName : "<< getObjetName() << "\n"
                                                     << "fileName : " << getFileName()  << "\n"
                                                     << "latitude : " << getLatitude() << "\n"
                                                     << "longitude : " << getLongitude() << std::endl;}

    void objetDisplay() const override {std::string line = "imagej " + getFileName() + " &"; system(line.c_str());}

};
#endif // PHOTO_H
