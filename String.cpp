#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include "String.h"

using namespace std;

String::String() {
    n = 0;
    max = BUFFER;
    array = new char[BUFFER];
}

String::String(const char array[]){
    n = 0;
    max = BUFFER;
    this->array = new char[BUFFER];
    int i = 0;
    while(array[i] != '\0')
        this->add(array[i++]);

}

String::String(const String& source){
    n = 0;
    max = BUFFER;
    this->array = new char[BUFFER];
    for (int i = 0; i < source.size(); ++i) {
        this->add(source.get(i));
    }

}

int String::size() const {
    return n;
}

char String::get(int index) const{
    if(index >= 0 && index < n){
        return array[index];
    }
    else{
        printf("Index out of range");
        exit(0);
    }
}

char& String::operator[](int index)
{
    return array[index];
}

void String::add(char c){
    if(n < max){
        array[n++] = c;
    }
    else{
        char * newArray = new char[max + BUFFER];
        for (int i = 0; i < max; ++i) {
            newArray[i] = array[i];
        }
        delete array;
        array = newArray;
        max += BUFFER;
        add(c);
    }
}
int String::find(char c){
    return find(c, 0, n);
}

int String::find(char c, int start) {
    return find(c, start, n);
}


int String::find(char c, int start, int stop) {
    for (int i = start; i < stop; ++i) {
        if (array[i] == c) {
            return i;
        }
    }
    return -1;
}

int String::find(const char argArray[]){
    bool result;
    size_t arraySize = strlen(argArray);
    for (int i = 0; i < n - arraySize; ++i) {
        if(this->array[i] == argArray[0]){
            result = true;
            for (int j = 1; j < arraySize; ++j) {
                if(this->array[i+j] != argArray[j]){
                    result = false;
                    break;
                }
            }
            if(result)
                return i;
        }
    }
    return -1;
}


int String::find(const String& str){
    return find(str, 0, size());
}

int String::find(const String& str, int start){
    return find(str, start, size());
}
int String::find(String str, int start, int stop){
    bool result;
    for (int i = start; i < stop && i < size() - str.size() + 1; ++i) {
        if(this->array[i] == str[0]){
            result = true;
            for (int j = 1; j < str.size(); ++j) {
                if(this->array[i+j] != str[j]){
                    result = false;
                    break;
                }
            }
            if(result)
                return i;
        }
    }
    return -1;
}


String* String::substr(int start, int nOfChars){
    auto * str = new String();
    for (int i = start; i < start + nOfChars; ++i) {
        str->add(this->array[i]);
    }
    return str;
}


void String::print(){
    for (int i = 0; i < n; ++i) {
        std::cout << array[i];
    }
}

List<String> * String::split(const String& separator){
    auto * list = new List<String>();
    int start = 0;
    if(find(separator, start) == 0)
        start = separator.size();
    while(find(separator, start) != -1){
        list->append(*substr(start, find(separator, start) - start));
        start = find(separator, start) + separator.size();
    }
    if(*substr(start, size() - start) != "")
        list->append(*substr(start, size() - start));
    return list;
}

bool String::is_number(const String &s) {
    for (int i = 0; i < s.size(); ++i) {
        if(s.array[i] < '0' || s.array[i] > '9'){
            return false;
        }
    }
    return true;
}


int String::toInt(){
    return atoi(this->array);
}



String& String::operator+(char c){
    auto * str = new String();
    for (int i = 0; i < n; ++i) {
        str->add(array[i]);
    }
    str->add(c);
    return *str;
}
String& String::operator+(String arg){
    auto * str = new String();
    for (int i = 0; i < n; ++i) {
        str->add(array[i]);
    }
    for (int i = 0; i < arg.size(); ++i) {
        str->add(arg[i]);
    }
    return *str;
}
String& String::operator+(const char arg[]){
    auto * str = new String();
    for (int i = 0; i < n; ++i) {
        str->add(array[i]);
    }
    for (int i = 0; i < strlen(arg); ++i) {
        str->add(arg[i]);
    }
    return *str;
}


void String::operator+=(String arg){
    for (int i = 0; i < arg.size(); ++i) {
        this->add(arg[i]);
    }
}

void String::operator+=(const char argArray[]){
    for (int i = 0; i < strlen(argArray); ++i) {
        this->add(argArray[i]);
    }
}
String& String::operator=(const char argArray[]){
    auto str = String(argArray);
    return str;
}


bool String::operator==(const char argArray[]){
    return strcmp(this->array, argArray) == 0;
}
bool String::operator==(const String& str){
    return strcmp(this->array, str.array) == 0;
}


bool String::operator!=(const char argArray[]){
    return !(*this == argArray);
}
bool String::operator!=(const String& str){
    return !(*this == str);
}