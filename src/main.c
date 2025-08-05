#include <stdio.h>
#include "hashtable.h"
#include "logger.h"

int main(void)
{
    hash_table* ht = new_hash_table(3);

    hash_table_put(ht, "John", 18);
    hash_table_put(ht, "Tom", 20);
    hash_table_put(ht, "Ash", 18);
    hash_table_put(ht, "Ash", 30);

    print_ht(ht);
    // printf("%d\n", hash_table_get(ht, "Ash"));
    printf("---------------------\n");

    // hash_table_delete(ht, "Ash");

    hash_table_resize(ht, 6);
    print_ht(ht);
    // printf("%d\n", hash_table_get(ht, "Ash"));


    
    free_hash_table(ht);

    return 0;
}
