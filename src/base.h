#ifndef BASE_H
#define BASE_H

#include <string>
#include <iostream>


class Base
{
private:
    std::string objetName;
    std::string fileName;

public:
    Base();
    Base(std::string objetName, std::string fileName);
    virtual ~Base(){}


    std::string getObjetName() const;
    std::string getFileName() const;
    void setObjetName(std::string objetName);
    void setFileName(std::string fileName);

    //virtual void display(std::ostream & s) const ;
    virtual void display(std::ostream & s) const ;

    virtual void objetDisplay() const = 0;
};

#endif // BASE_H
