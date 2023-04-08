#include "Selector.h"


Selector::Selector(String& name){
    this->name = name;
    this->attributes = new List<Attribute>();
}

void Selector::addAttribute(Attribute attr){
    attributes->append(attr);
}
