#include <iostream>
#include "String.h"

using namespace std;

int main() {
    String str = String();
    for (int i = 0; i < 3; ++i) {
        str.add('a');
    }
    str.print();
    std::cout << str.size() << std::endl;

    str = String("abcdefg");
    str.print();
    cout << str.size() << endl;
    str = "abc";
    str.print();
    return 0;
}