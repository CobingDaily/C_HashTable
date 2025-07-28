#include <stdio.h>
#include "hashtable.h"
#include "logger.h"

int main(void)
{
    hash_table* ht = new_hash_table(10);
    print_ht(ht);

    return 0;
}
