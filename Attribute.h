//
// Created by michal on 05.04.23.
//

#ifndef PROCESORCSS_ATTRIBUTE_H
#define PROCESORCSS_ATTRIBUTE_H


#include "String.h"

class Attribute {
public:
    Attribute(String name, String value);
private:
    String name;
    String value;
};


#endif //PROCESORCSS_ATTRIBUTE_H
