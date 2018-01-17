#ifndef GROUP_H
#define GROUP_H

#include<list>
#include<iostream>
#include"base.h"
#include<memory>

class Group:public std::list<BasePtr>{
private:
    std::string groupname;

public:
    Group(){}

    Group(std::string groupname): std::list<BasePtr>(), groupname(groupname){}

    std::string getName() const;

    void dispaly(std::ostream &s);

};

using GroupPtr = std::shared_ptr<Group>;

#endif // GROUP_H
