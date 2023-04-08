#include "Attribute.h"

Attribute::Attribute(const String& name, const String& value) {
    this->name = name;
    this->value = value;
}



String Attribute::getDescription(){
    return name + ": " + value + ";";
}
String Attribute::getName(){
    return name;
}
String Attribute::getValue(){
    return value;
}