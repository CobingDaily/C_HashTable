#include <stdio.h>
#include "hashtable.h"
#include "logger.h"

int main(void)
{
    hash_table* ht = new_hash_table(3);

    hash_table_put(ht, "John", 18);
    hash_table_put(ht, "Tom", 20);
    hash_table_put(ht, "Ash", 18);

    print_ht(ht);
    printf("---------------------\n");

    hash_table_put(ht, "Nick", 30);

    // hash_table_put(ht, "John", 18);
    // hash_table_put(ht, "Tom", 20);
    // hash_table_put(ht, "Ash", 18);
    
    print_ht(ht);

    free_hash_table(ht);

    return 0;
}
