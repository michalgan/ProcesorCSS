//
// Created by michal on 08.04.23.
//

#ifndef PROCESORCSS_BLOCKOFCSS_H
#define PROCESORCSS_BLOCKOFCSS_H


#include "String.h"
#include "Attribute.h"

class BlockOfCSS {
public:
    BlockOfCSS();
    void addSelector(const String& name);
    void addAttribute(Attribute* attr);
    int nOfSelectors() const;
    int nOfAttributes() const;
    String getSelectorName(int index);
    Attribute* getAttribute(int index);
    String getAttributeValue(const String& attribute);
    bool hasSelector(const String& selector);
    bool hasAttribute(const String& attribute);
    void deleteAttribute(const String& name);
private:
    List<String> selectors;
    List<Attribute*> attributes;
};


#endif //PROCESORCSS_BLOCKOFCSS_H
