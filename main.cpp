#include <cstring>
#include "Processor.h"

int main() {
    // Processor processor = Processor();
    // processor.run();
    char * text = new char[50];
    scanf("%50s{", text);
    printf("|%s|", text);

    return 0;
}