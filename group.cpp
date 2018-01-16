#include<list>
#include<iostream>
#include"base.h"
#include"group.h"

std::string Group::getName() const {
    return groupname;
}

void Group::dispaly(std::ostream & s) {
    s << "groupname :" << getName() << std::endl;
    //for (std::list<Base *>::iterator it = groupname.begin(); it != groupname.end(); ++it){
    for (auto it : *this) it->display(s);
    //}
}
