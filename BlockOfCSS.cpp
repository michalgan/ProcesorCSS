#include "BlockOfCSS.h"

BlockOfCSS::BlockOfCSS() {
    selectors = List<String>();
    attributes = List<Attribute*>();
}

void BlockOfCSS::addSelector(const String& name){
    selectors.append(name);
}


void BlockOfCSS::addAttribute(Attribute* attr){
    attributes.append(attr);
}


int BlockOfCSS::nOfSelectors(){
    return this->selectors.size();
}
int BlockOfCSS::nOfAttributes(){
    return this->attributes.size();
}

String BlockOfCSS::getSelector(int index){
    return selectors.get(index);
}


Attribute* BlockOfCSS::getAttribute(int index){
    return attributes.get(index);
}
String BlockOfCSS::getAttributeValue(String attribute){
    for (int i = 0; i < attributes.size(); ++i) {
        if(attributes.get(i)->getName() == attribute){
            return attributes.get(i)->getValue();
        }
    }
    return String("");
}


bool BlockOfCSS::hasSelector(String selector){
    for (int i = 0; i < selectors.size(); ++i) {
        if(selectors.get(i) == selector)
            return true;
    }
    return false;
}


void BlockOfCSS::deleteAttribute(String name){
    for (int i = 0; i < attributes.size(); ++i) {
        if(attributes.get(i)->getName() == name){
            attributes.pop(i);
            break;
        }
    }
}