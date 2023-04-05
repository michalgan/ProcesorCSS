#include <iostream>
#include "String.h"
#include "Selector.h"

#define BUFFER 50
using namespace std;

#ifndef PROCESORCSS_PROCESSOR_H
#define PROCESORCSS_PROCESSOR_H


class Processor {
public:
    Processor();
    void printNumberOfSections();
    void printNumberOfSelectorsForSection(int section);
    void printNumberOfAttributesForSection(int section);
    void printSelectorForBlock(int selectorNumber, int blockNumber);
    void printAttributeValueForSection(String attribute, int section);
    void printSummaryNumberOfOccurrencesOfAttribute(String attribute);
    void printSummaryNumberOfOccurrencesOfSelector(String selector);
    void printAttributeValueForSelector(String attribute, String selector);
    void deleteSection(int section);
    void deleteAttributeFromSection(String attribute, int section);
    void callSFunction(String arg1, String arg2);
    void callAFunction(String arg1, String arg2);
    void callEFunction(String arg1, String arg2);
    void callDFunction(String arg1, String arg2);
    void readCSS();
    void readSelectors();
    void readAttributes(List<Selector*> recentlyReadSelectors);
    void run();
private:
    char * temp;
    List<Selector*> * selectors;
};


#endif //PROCESORCSS_PROCESSOR_H
