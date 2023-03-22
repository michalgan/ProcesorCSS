#include <iostream>
#include <string>
using namespace std;

#include <cstring>

bool is_number(const std::string& s)
{
    return( strspn( s.c_str(), "-.0123456789" ) == s.size() );
}

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

void printAttributeValueForSection(string attribute, int section){
    //TODO
}

void printSummaryNumberOfOccurrencesOfAttribute(string attribute){
    //TODO
}

void printSummaryNumberOfOccurrencesOfSelector(string selector){
    //TODO
}

void printAttributeValueForSelector(string attribute, string selector){
    //TODO
}

void deleteSection(int section){
    //TODO
}


void deleteAttributeFromSection(string attribute, int section){
    //TODO
}


void callSFunction(string arg1, string arg2){
    if(arg2 == "?"){
        if(is_number(arg1)){
            printNumberOfSelectorsForSection(stoi(arg1));
        }
        else{
            printSummaryNumberOfOccurrencesOfSelector(arg1);
        }
    }
    else{
        printSelectorForBlock(stoi(arg2), stoi(arg1));
    }
}

void callAFunction(string arg1, string arg2){
    if(arg2 == "?"){
        if(is_number(arg1)){
            printNumberOfAttributesForSection(stoi(arg1));
        }
        else{
            printSummaryNumberOfOccurrencesOfAttribute(arg1);
        }
    }
    else{
        printAttributeValueForSection(arg2, stoi(arg1));
    }
}

void callEFunction(string arg1, string arg2){
    printAttributeValueForSelector(arg1, arg2);
}

void callDFunction(string arg1, string arg2){;
    int i = stoi(arg1);
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

int main() {
    bool cssMode = true;
    string input;
    while(!feof(stdin)){
        getline(cin, input);
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
            int comma = input.find(",");
            string arg1 = input.substr(0, comma);
            string arg2 = input.substr(comma+3, input.size() - (comma+3));
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
    return 0;
}