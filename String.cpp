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
    int i = 0;
    while(source.array[i] != '\0')
        this->add(source.array[i++]);

}

int String::size() const {
    return n;
}

char String::get(int index){
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


ostream& operator<<(ostream& os, const String& obj){

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

int String::find(const char array[]){
    bool result;
    size_t arraySize = strlen(array);
    for (int i = 0; i < n - arraySize; ++i) {
        if(this->array[i] == array[0]){
            result = true;
            for (int j = 1; j < arraySize; ++j) {
                if(this->array[i+j] != array[j]){
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


String& String::substr(int start, int nOfChars){
    String&& str = String();
    for (int i = start; i < start + nOfChars; ++i) {
        str.add(this->array[i]);
    }
    return str;
}


void String::print(){
    for (int i = 0; i < n; ++i) {
        std::cout << array[i];
    }
    std::cout << std::endl;
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
    return ::atoi(this->array);
}



String& String::operator+(char c){
    String * str = new String();
    for (int i = 0; i < n; ++i) {
        str->add(array[i]);
    }
    str->add(c);
    return *str;
}
String& String::operator+(String arg){
    String * str = new String();
    for (int i = 0; i < n; ++i) {
        str->add(array[i]);
    }
    for (int i = 0; i < arg.size(); ++i) {
        str->add(arg[i]);
    }
    return *str;
}


void String::operator+=(String arg){
    for (int i = 0; i < arg.size(); ++i) {
        this->add(arg[i]);
    }
}

void String::operator+=(const char array[]){
    for (int i = 0; i < strlen(array); ++i) {
        this->add(array[i]);
    }
}
String& String::operator=(const char array[]){
    String str = String(array);
    return str;
}


bool String::operator==(const char array[]){
    return strcmp(this->array, array) == 0;
}
bool String::operator==(String str){
    return strcmp(this->array, str.array) == 0;
}


bool String::operator!=(const char array[]){
    return !(*this == array);
}
bool String::operator!=(String str){
    return !(*this == str);
}