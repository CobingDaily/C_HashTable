#include "hashtable.h"

unsigned int hash(const char* string) {
    unsigned int sum = 0;

    int pos = 0;
    while(string[pos] != '\0') {
        sum += string[pos] * 31;
        pos++;
    }

    return sum % TABLE_SIZE;
}