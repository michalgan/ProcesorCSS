#include "BlockOfCSS.h"

BlockOfCSS::BlockOfCSS() :selectors(List<String>()), attributes(List<Attribute*>()) {}

void BlockOfCSS::addSelector(const String& name){
    selectors.append(name);
}


void BlockOfCSS::addAttribute(Attribute* attr){
    attributes.append(attr);
}


int BlockOfCSS::nOfSelectors() const{
    return this->selectors.size();
}
int BlockOfCSS::nOfAttributes() const{
    return this->attributes.size();
}

String BlockOfCSS::getSelectorName(int index){
    return selectors.get(index);
}


Attribute* BlockOfCSS::getAttribute(int index){
    return attributes.get(index);
}
String BlockOfCSS::getAttributeValue(const String& attribute){
    for (int i = 0; i < attributes.size(); ++i) {
        if(attributes.get(i)->getName() == attribute){
            return attributes.get(i)->getValue();
        }
    }
    return String("");
}


bool BlockOfCSS::hasSelector(const String& selector){
    for (int i = 0; i < selectors.size(); ++i) {
        if(selectors.get(i) == selector)
            return true;
    }
    return false;
}


bool BlockOfCSS::hasAttribute(const String& attribute){
    for (int i = 0; i < attributes.size(); ++i) {
        if(attributes.get(i)->getName() == attribute)
            return true;
    }
    return false;
}


void BlockOfCSS::deleteAttribute(const String& name){
    for (int i = 0; i < attributes.size(); ++i) {
        if(attributes.get(i)->getName() == name){
            attributes.pop(i);
            break;
        }
    }
}