#include <cstring>
#include "Processor.h"


Processor::Processor() {
    temp = new char[BUFFER];
    blocks = new List<BlockOfCSS*>();
    developerMode = true;
}
void Processor::printNumberOfSections(){
    printf("? == %d\n", blocks->size());
}

void Processor::printNumberOfSelectorsForSection(int section){
    if(section <= blocks->size() && section > 0)
        printf("%d,S,? == %d\n", section, blocks->get(section-1)->nOfSelectors());
}

void Processor::printNumberOfAttributesForSection(int section){
    if(section <= blocks->size() && section > 0)
        printf("%d,A,? == %d\n", section, blocks->get(section-1)->nOfAttributes());
}

void Processor::printSelectorForBlock(int selectorNumber, int blockNumber){
    if(blockNumber <= blocks->size() && blockNumber > 0 && selectorNumber <= blocks->get(blockNumber-1)->nOfSelectors() && selectorNumber > 0){
        printf("%d,S,%d == ", blockNumber, selectorNumber);
        blocks->get(blockNumber-1)->getSelectorName(selectorNumber-1).print();
        printf("\n");
    }
}

void Processor::printAttributeValueForSection(String& attribute, int section){
    if(section > 0 && section <= blocks->size()){
        String value = blocks->get(section - 1)->getAttributeValue(attribute);
        if(value != ""){
            printf("%d,A,", section);
            attribute.print();
            printf(" == ");
            value.print();
            printf("\n");
        }
    }
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
    for (int i = blocks->size() - 1; i >= 0; --i) {
        if(blocks->get(i)->hasSelector(selector) && blocks->get(i)->getAttributeValue(attribute) != "" ){
            selector.print();
            printf(",E,");
            attribute.print();
            printf(" == ");
            blocks->get(i)->getAttributeValue(attribute).print();
            break;
        }
    }
    printf("\n");
}

void Processor::deleteSection(int section){
    if(section > 0 && section <= blocks->size()){
        printf("%d,D,* == deleted\n", section);
        blocks->pop(section-1);
    }
}


void Processor::deleteAttributeFromSection(String& attribute, int section){
    if(section > 0 && section <= blocks->size()){
        blocks->get(section - 1)->deleteAttribute(attribute);
        if(blocks->get(section - 1)->nOfAttributes() == 0)
            blocks->pop(section - 1);
        printf("%d,D,", section);
        attribute.print();
        printf(" == deleted\n");
    }
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
        scanf("%50s", temp);
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
    auto stream = String(temp);
    if(stream.find('{') == -1){
        scanf("%400s{", temp);
        stream += String(temp);
    }
    int sepIndex = stream.find('{');
    List<String> * selectors = stream.substr(0, sepIndex)->split(String(","));
    for (int i = 0; i < selectors->size(); ++i) {
        block->addSelector(selectors->get(i));
    }
    String sourceForAttributes = String("");
    if(stream.find('{') != stream.size() - 1)
        sourceForAttributes = *stream.substr(sepIndex+1, stream.size() - sepIndex-1);
    readAttributes(sourceForAttributes, block);
    blocks->append(block);

}

void Processor::readAttributes(String stream, BlockOfCSS * block){
    if(stream.find('}') == -1){
        scanf("%400}s", temp);
        stream += String(temp);
    }
    int sepIndex = stream.find('}');
    List<String> * attributes = (stream.substr(0, sepIndex))->split(String(";"));
    for (int i = 0; i < attributes->size(); ++i) {
        List<String> * attribute = attributes->get(i).split(String(":"));
        if(attribute->size() > 1)
            block->addAttribute(new Attribute(attribute->get(0), attribute->get(1)));
        else{
            printf("Problem with reading attribute...\n");
            printf("Potential attribute:\n\t");
            attributes->get(i).print();
            printf("\n");
        }
    }
}

void Processor::run(){
    readCSS();
    while(!feof(stdin)){
        scanf("%50s", temp);
        if(strcmp(temp, "****") == 0){
            readCSS();
        }
        else if(strcmp(temp, "?") == 0){
            printNumberOfSections();
        }
        else{
            String input = String(temp);
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

Processor::~Processor(){
    delete temp;
    delete blocks;
}