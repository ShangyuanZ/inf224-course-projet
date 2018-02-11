//
//  gestion.cpp
//  TP_mac
//
//  Created by theo on 17/01/2018.
//  Copyright © 2018 theo. All rights reserved.
//


#include<map>
#include<string>
#include<memory>
#include<exception>
#include<iostream>

#include "gestion.h"
#include"base.h"
#include"group.h"
#include"photo.h"
#include"video.h"
#include"film.h"
#include"group.h"


//creat files
PhotoPtr Gestion::createPhoto(std::string objetName, std::string fileName, float _latitude, float _longitude){
    objetMap[objetName] = std::make_shared<Photo>(objetName,fileName, _latitude, _longitude);
    return std::dynamic_pointer_cast<Photo>(objetMap[objetName]);
}

VideoPtr Gestion::createVideo(std::string objetName, std::string fileName, int _duration){
    objetMap[objetName] = std::make_shared<Video>(objetName, fileName, _duration);
    return std::dynamic_pointer_cast<Video>(objetMap[objetName]);
}

FilmPtr Gestion::createFilm(std::string objetName, std::string fileName, int _duration, int * duree, int number){
    objetMap[objetName] = std::make_shared<Film>(objetName, fileName, _duration, duree, number);
    return std::dynamic_pointer_cast<Film>(objetMap[objetName]);
}

GroupPtr Gestion::createGroup(std::string groupname){
    groupMap[groupname] = std::make_shared<Group>(groupname);
    return groupMap[groupname];
}

//search files
BasePtr Gestion::searchFile(std::string fileName){
    auto file = objetMap.find(fileName);
    if (file != objetMap.end()){
        return file->second;
    }
    else{
        //throw std::runtime_error("can't find " + fileName);
        PhotoPtr b = std::make_shared<Photo>();
        return b;
    }
}

GroupPtr Gestion::searchGroup(std::string groupName){
    auto group = groupMap.find(groupName);
    if (group != groupMap.end()){
        return group->second;
    }
    else{
        //throw std::runtime_error("can't find " + groupName);
        return std::make_shared<Group>();
    }
}

//display files
void Gestion::displayFile(std::string fileName, std::ostream s ){
    searchFile(fileName)->display(s);
}

void Gestion::displayGroup(std::string groupName, std::ostream s){
    searchGroup(groupName)->dispaly(s);
}

void Gestion::play(std::string fileName){
    searchFile(fileName)->objetDisplay();
}
