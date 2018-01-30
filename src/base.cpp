#include <string>
#include <iostream>

#include "base.h"


/** constructer
 */
Base::Base(){}

Base::Base(std::string objetName, std::string fileName):objetName(objetName), fileName(fileName){}


/** getter
 */
std::string Base::getObjetName() const {
    return objetName;
}

std::string Base::getFileName() const {
    return fileName;
}

/** setter
 */
void Base::setFileName(std::string _fileName) {
    fileName = _fileName;
}

void Base::setObjetName(std::string _objetName) {
    objetName = _objetName;
}

/** other methode
 */
void Base::display(std::ostream &s) const {
    s << "objetName : "<< getObjetName() << "\n"
        << "fileName : " << getFileName() << std::endl;
}
