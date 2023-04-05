#include <cstdio>
#include <cstdlib>
#include <iostream>
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

int String::size() {
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


void String::print(){
    for (int i = 0; i < n; ++i) {
        std::cout << array[i];
    }
    std::cout << std::endl;
}


String& String::operator+(char c){
    String str = String();
    for (int i = 0; i < n; ++i) {
        str.add(array[i]);
    }
    str.add(c);
    return str;
}
String& String::operator+(String arg){
    String str = String();
    for (int i = 0; i < n; ++i) {
        str.add(array[i]);
    }
    for (int i = 0; i < arg.size(); ++i) {
        str.add(arg[i]);
    }
    return str;
}


String& String::operator+=(const char array[]){
    return *this + String(array);
}
String& String::operator=(const char array[]){
    String str = String(array);
    return str;
}
