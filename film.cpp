#include<iostream>
#include<string>

#include"film.h"

Film::Film(){}

Film::Film(std::string objetName, std::string fileName, int _duration, int * duree, int number):
    Video(objetName,fileName,_duration),duree(duree),number(number){}

//modificateur
void Film::changeDuree(int * _duree, int _number){
    for(int i = 0; i < _number; i++){
        duree[i] = _duree[i];
    }
}

//accesseur
int * Film::getTableDuree () const{
    return duree;
}

int Film::getChNumber() const{
    return number;
}

//other
void Film::displayDuree(std::ostream & s){
    for (int i = 0; i< number; i++){
        s << duree[i] << " ";
    }
    s << std::endl;
}

