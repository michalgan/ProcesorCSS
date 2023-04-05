#include <cstring>
#include "Processor.h"


Processor::Processor() {
    temp = new char[BUFFER];
    selectors = new List<Selector*>();
}
void Processor::printNumberOfSections(){
    //TODO
}

void Processor::printNumberOfSelectorsForSection(int section){
    //TODO
}

void Processor::printNumberOfAttributesForSection(int section){
    //TODO
}

void Processor::printSelectorForBlock(int selectorNumber, int blockNumber){
    //TODO
}

void Processor::printAttributeValueForSection(String attribute, int section){
    //TODO
}

void Processor::printSummaryNumberOfOccurrencesOfAttribute(String attribute){
    //TODO
}

void Processor::printSummaryNumberOfOccurrencesOfSelector(String selector){
    //TODO
}

void Processor::printAttributeValueForSelector(String attribute, String selector){
    //TODO
}

void Processor::deleteSection(int section){
    //TODO
}


void Processor::deleteAttributeFromSection(String attribute, int section){
    //TODO
}


void Processor::callSFunction(String arg1, String arg2){
    if(arg2 == "?"){
        if(String::is_number(arg1)){
            printNumberOfSelectorsForSection(arg1.toInt());
        }
        else{
            printSummaryNumberOfOccurrencesOfSelector(arg1);
        }
    }
    else{
        printSelectorForBlock(arg2.toInt(), arg1.toInt());
    }
}

void Processor::callAFunction(String arg1, String arg2){
    if(arg2 == "?"){
        if(String::is_number(arg1)){
            printNumberOfAttributesForSection(arg1.toInt());
        }
        else{
            printSummaryNumberOfOccurrencesOfAttribute(arg1);
        }
    }
    else{
        printAttributeValueForSection(arg2, arg1.toInt());
    }
}

void Processor::callEFunction(String arg1, String arg2){
    printAttributeValueForSelector(arg1, arg2);
}

void Processor::callDFunction(String arg1, String arg2){
    int i = arg1.toInt();
    if(arg2 == "*"){
        deleteSection(i);
    }
    else{
        deleteAttributeFromSection(arg2, i);
    }
}

void Processor::readCSS(){
    while(!feof(stdin)) {
        scanf("%s", temp);
        if(strcmp(temp, "????")){
            break;
        }
        else{
            readSelectors();
        }
    }
}


void Processor::readSelectors(){
    List<Selector*> recentlyReadSelectors = List<Selector*>();
    String name = temp;
    Selector * newSelector = new Selector(name);
    selectors->append(newSelector);
    recentlyReadSelectors.append(newSelector);
    while(!feof(stdin)) {
        scanf("%s", temp);
        if (name.find('{') != -1) {
            if (name.find(',') != -1) {
                name = name.substr(0, name.size() - 1);
            }
            Selector * newSelector = new Selector(name);
            selectors->append(newSelector);
            recentlyReadSelectors.append(newSelector);
        } else {
            break;
        }
    }
    readAttributes(recentlyReadSelectors);
}

void Processor::readAttributes(List<Selector*> recentlyReadSelectors){
    //TODO
}

void Processor::run(){
    while(!feof(stdin)){
        scanf("%s", temp);
        if(strcmp(temp, "****") == 0){
            readCSS();
        }

        else if(strcmp(temp, "?") == 0){
            printNumberOfSections();
        }
        else{
            String input = temp;
            int comma = input.find(',');
            String arg1 = input.substr(0, comma);
            String arg2 = input.substr(comma+3, input.size() - (comma+3));
            if(input.find(",S,") != -1){
                callSFunction(arg1, arg2);
            }
            else if(input.find(",A,") != -1){
                callAFunction(arg1, arg2);
            }
            else if(input.find(",E,") != -1){
                callEFunction(arg1, arg2);
            }
            else if(input.find(",D,") != -1){
                callDFunction(arg1, arg2);
            }
        }
    }
}