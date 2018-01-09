#ifndef FILM_H
#define FILM_H

#include<iostream>

#include"video.h"

class Film : public Video{
private:
    int * duree = nullptr;
    int number = 0;

public:
    // constructeur
    Film();

    Film(std::string objetName, std::string fileName, int _duration, int * duree, int number);

    //modificateur
    void changeDuree(int * _duree, int _number);

    //accesseur
    int * getTableDuree () const;

    int getChNumber() const;

    //other
    ~Film();
    void displayDuree(std::ostream & s);



};

#endif // FILM_H
