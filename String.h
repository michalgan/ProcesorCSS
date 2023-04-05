//
// Created by Michał on 23.03.2023.
//

#ifndef PROCESORCSS_STRING_H
#define PROCESORCSS_STRING_H


class String {
public:
    String();
    String(const char array[]);
    int size();
    char get(int index);
    void add(char c);
    int find(char c);
    int find(char c, int start);
    int find(char c, int start, int stop);
    void print();
    char& operator[](int index);
    String& operator+(char c);
    String& operator+(String arg);
    String& operator+=(String arg);
    String& operator+=(const char array[]);
    String& operator=(const char array[]);

private:
    int n;
    int max;
    char * array;
    const static int BUFFER=10;
};



#endif //PROCESORCSS_STRING_H
