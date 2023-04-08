#include <cstring>
#include "Processor.h"


Processor::Processor() {
    temp = new char[BUFFER];
    blocks = new List<BlockOfCSS*>();
}
void Processor::printNumberOfSections(){
    printf("? == %d\n", blocks->size());
}

void Processor::printNumberOfSelectorsForSection(int section){
    printf("%d,S,? == %d\n", section, blocks->get(section-1)->nOfSelectors());
}

void Processor::printNumberOfAttributesForSection(int section){
    printf("%d,A,? == %d\n", section, blocks->get(section-1)->nOfAttributes());
}

void Processor::printSelectorForBlock(int selectorNumber, int blockNumber){
    printf("%d,S,%d == ", blockNumber, selectorNumber);
    blocks->get(blockNumber-1)->getSelector(selectorNumber-1).print();
    printf("\n");
}

void Processor::printAttributeValueForSection(String& attribute, int section){
    printf("%d,A,", section);
    attribute.print();
    printf(" == ");
    blocks->get(section - 1)->getAttributeValue(attribute).print();
    printf("\n");
}

void Processor::printSummaryNumberOfOccurrencesOfAttribute(String& attribute){
    int counter = 0;
    for (int i = 0; i < blocks->size(); ++i) {
        if(blocks->get(i)->getAttributeValue(attribute) != "")
            counter += 1;
    }
    attribute.print();
    printf(",A,? == %d\n", counter);
}

void Processor::printSummaryNumberOfOccurrencesOfSelector(String& selector){
    int counter = 0;
    for (int i = 0; i < blocks->size(); ++i) {
        if(blocks->get(i)->hasSelector(selector))
            counter += 1;
    }
    selector.print();
    printf(",S,? == %d\n", counter);
}

void Processor::printAttributeValueForSelector(String& selector, String& attribute){
    selector.print();
    printf(",E,");
    attribute.print();
    printf(" == ");
    for (int i = blocks->size() - 1; i >= 0; --i) {
        if(blocks->get(i)->hasSelector(selector) && blocks->get(i)->getAttributeValue(attribute) != "" ){
            blocks->get(i)->getAttributeValue(attribute).print();
            break;
        }
    }
    printf("\n");
}

void Processor::deleteSection(int section){
    printf("%d,D,* == deleted\n", section);
    blocks->pop(section-1);
}


void Processor::deleteAttributeFromSection(String& attribute, int section){
    blocks->get(section - 1)->deleteAttribute(attribute);
    if(blocks->get(section - 1)->nOfAttributes() == 0)
        blocks->pop(section - 1);
    printf("%d,D, ", section);
    attribute.print();
    printf(" == deleted\n");
}


void Processor::callSFunction(String& arg1, String& arg2){
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

void Processor::callAFunction(String& arg1, String& arg2){
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

void Processor::callEFunction(String& arg1, String& arg2){
    printAttributeValueForSelector(arg1, arg2);
}

void Processor::callDFunction(String& arg1, String& arg2){
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
        if(strcmp(temp, "????") == 0){
            break;
        }
        else{
            readSelectors();
        }
    }
}


void Processor::readSelectors(){
    auto * block = new BlockOfCSS();
    List<Selector*> recentlyReadSelectors = List<Selector*>();
    auto name = String(temp);
    if (name.find(',') == name.size() - 1) {
        name = *name.substr(0, name.size() - 1);
    }
    block->addSelector(name);
    String sourceForAttributes = "";
    while(!feof(stdin)) {
        scanf("%s", temp);
        name = String(temp);
        if (name.find('{') == -1) {
            if (name.find(',') == name.size() - 1) {
                name = *name.substr(0, name.size() - 1);
            }
            block->addSelector(name);
        }
        else {
            int index = name.find('{');
            if(index != name.size() - 1){
                sourceForAttributes = *name.substr(index+1, name.size() - index);
            }
            break;
        }
    }
    readAttributes(sourceForAttributes, block);
    blocks->append(block);

}

void Processor::readAttributes(String sourceForAttributes, BlockOfCSS * block){
    while(!feof(stdin)) {
        String name;
        if(sourceForAttributes == ""){
            scanf("%s", temp);
            name = String(temp);
        }
        else{
            name = sourceForAttributes;
        }
        if (name.find('}') == -1) {
            scanf("%s", temp);
            auto value = String(temp);
            while(value.find(';') == -1 && !feof(stdin)){
                scanf("%s", temp);
                value += String(temp);
            }
            name = *name.substr(0, name.size() - 1);
            value = *value.substr(0, value.size() - 1);
            auto * attr = new Attribute(name, value);
            block->addAttribute(attr);
        }
        else {
            break;
        }
    }
}

void Processor::run(){
    readCSS();
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
            String arg1 = *input.substr(0, comma);
            String arg2 = *input.substr(comma+3, input.size() - (comma+3));
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