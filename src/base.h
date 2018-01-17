#ifndef BASE_H
#define BASE_H

#include <string>
#include <iostream>
#include <memory>



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

using BasePtr = std::shared_ptr<Base>;

#endif // BASE_H
