//
//  gestion.h
//  TP_mac
//
//  Created by theo on 17/01/2018.
//  Copyright © 2018 theo. All rights reserved.
//

#ifndef gestion_h
#define gestion_h

#include<map>
#include<string>
#include<memory>
#include<iostream>

#include"base.h"
#include"group.h"
#include"photo.h"
#include"video.h"
#include"film.h"


class Gestion{
private:
    std::map<std::string, BasePtr> objetMap;
    std::map<std::string, GroupPtr> groupMap;
    
public:
    Gestion(){}
    
    //creat files
    PhotoPtr createPhoto(std::string objetName,
                         std::string fileName,
                         float _latitude,
                         float _longitude);
    
    VideoPtr createVideo(std::string objetName,
                         std::string fileName,
                         int _duration);
    
    FilmPtr createFilm(std::string objetName,
                       std::string fileName,
                       int _duration,
                       int * duree,
                       int number);
    
    GroupPtr createGroup(std::string groupname);
    
    //search files
    BasePtr searchFile(std::string fileName);
    
    GroupPtr searchGroup(std::string groupName);
    
    //display files
    void displayFile(std::string fileName, std::ostream s);
    
    void displayGroup(std::string groupName, std::ostream s);
    
    void play(std::string name);
    
};

using GestionPtr = std::shared_ptr<Gestion>;

#endif /* gestion_h */
