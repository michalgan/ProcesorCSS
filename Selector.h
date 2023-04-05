//
// Created by michal on 05.04.23.
//

#ifndef PROCESORCSS_SELECTOR_H
#define PROCESORCSS_SELECTOR_H


#include "String.h"
#include "List.h"
#include "Attribute.h"

class Selector {
public:
    Selector(String name);
    void addAttribute(Attribute attr);
private:
    String name;
    List<Attribute> * attributes;
};


#endif //PROCESORCSS_SELECTOR_H
