#include <iostream>
#include "String.h"
#define BUFFER 50
using namespace std;



void printNumberOfSections(){
    //TODO
}

void printNumberOfSelectorsForSection(int section){
    //TODO
}

void printNumberOfAttributesForSection(int section){
    //TODO
}

void printSelectorForBlock(int selectorNumber, int blockNumber){
    //TODO
}

void printAttributeValueForSection(String attribute, int section){
    //TODO
}

void printSummaryNumberOfOccurrencesOfAttribute(String attribute){
    //TODO
}

void printSummaryNumberOfOccurrencesOfSelector(String selector){
    //TODO
}

void printAttributeValueForSelector(String attribute, String selector){
    //TODO
}

void deleteSection(int section){
    //TODO
}


void deleteAttributeFromSection(String attribute, int section){
    //TODO
}


void callSFunction(String arg1, String arg2){
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

void callAFunction(String arg1, String arg2){
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

void callEFunction(String arg1, String arg2){
    printAttributeValueForSelector(arg1, arg2);
}

void callDFunction(String arg1, String arg2){
    int i = arg1.toInt();
    if(arg2 == "*"){
        deleteSection(i);
    }
    else{
        deleteAttributeFromSection(arg2, i);
    }
}

void readCSS(){
    //TODO
}

void runCSSProcessor(){
    bool cssMode = true;
    char * temp = new char[BUFFER];
    String input;
    while(!feof(stdin)){
        ::scanf("%s", temp);
        if(cssMode){
            if(input == "????"){
                cssMode = false;
            }
            else{
                readCSS();
            }
        }
        else if(input == "****"){
            cssMode = true;
        }

        else if(input == "?"){
            printNumberOfSections();
        }
        else{
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