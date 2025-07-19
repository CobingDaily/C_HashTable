#include <stdio.h>
#include "hashtable.h"
#include "logger.h"

int main(void)
{    
    const char* string = "Hello!";
    unsigned int index = hash(string);

    printf("Hash: %d\n", index);

    return 0;
}