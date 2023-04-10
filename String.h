#ifndef PROCESORCSS_STRING_H
#define PROCESORCSS_STRING_H

#include <iostream>
#include "List.h"

using namespace std;
class String {
public:
    String();
    explicit String(const char array[]);
    String(const String& source);
    int size() const;
    char get(int index) const;
    void add(char c);
    int find(char c);
    int find(char c, int start);
    int find(char c, int start, int stop);
    int find(const char array[]);
    int find(const String& str);
    int find(const String& str, int start);
    int find(String str, int start, int stop);
    String* substr(int start, int nOfChars);
    void print();
    List<String> * split(const String& separator);
    char& operator[](int index);
    String& operator+(char c);
    String& operator+(String arg);
    String& operator+(const char arg[]);
    void operator+=(String arg);
    void operator+=(const char argArray[]);
    String& operator=(const char argArray[]);
    bool operator==(const char argArray[]);
    bool operator==(const String& str);
    bool operator!=(const char argArray[]);
    bool operator!=(const String& str);
    static bool is_number(const String& s);
    int toInt();
private:
    int n;
    int max;
    char * array;
    const static int BUFFER=10;
};



#endif //PROCESORCSS_STRING_H
