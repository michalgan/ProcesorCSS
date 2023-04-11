#include "Attribute.h"

Attribute::Attribute(const String& name, const String& value) {
    this->name = name;
    this->value = value;
}

String Attribute::getName() const{
    return name;
}
String Attribute::getValue() const{
    return value;
}