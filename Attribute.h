//
// Created by michal on 05.04.23.
//

#ifndef PROCESORCSS_ATTRIBUTE_H
#define PROCESORCSS_ATTRIBUTE_H


#include "String.h"

class Attribute {
public:
    Attribute(const String& name, const String& value);
    String getDescription();
    String getName();
    String getValue();
private:
    String name;
    String value;
};


#endif //PROCESORCSS_ATTRIBUTE_H
