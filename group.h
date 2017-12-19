#ifndef GROUP_H
#define GROUP_H

#include<list>
#include"base.h"

class Group:public std::list<Base *>{
private:
    std::string groupname;

};

#endif // GROUP_H
