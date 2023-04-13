#include "Attribute.h"

Attribute::Attribute(const String& name, const String& value) :name(name), value(value){}

String Attribute::getDescription(){
    return name + ": " + value + ";";
}
String Attribute::getName() const{
    return name;
}
String Attribute::getValue() const{
    return value;
}