#ifndef GROUP_H
#define GROUP_H

#include<list>
#include<iostream>
#include"base.h"

class Group:public std::list<Base *>{
private:
    std::string groupname;

public:
    Group(){}

    Group(std::string groupname): std::list<Base *>(), groupname(groupname){}

    std::string getName() const;

    void dispaly(std::ostream &s);

};

#endif // GROUP_H
