//
// Created by michal on 08.04.23.
//

#ifndef PROCESORCSS_BLOCKOFCSS_H
#define PROCESORCSS_BLOCKOFCSS_H


#include "Selector.h"

class BlockOfCSS {
public:
    BlockOfCSS();
    void addSelector(const String& name);
    void addAttribute(Attribute* attr);
    int nOfSelectors();
    int nOfAttributes();
    String getSelector(int index);
    Attribute* getAttribute(int index);
    String getAttributeValue(String attribute);
    bool hasSelector(String selector);
    void deleteAttribute(String name);
private:
    List<String> selectors;
    List<Attribute*> attributes;
};


#endif //PROCESORCSS_BLOCKOFCSS_H
