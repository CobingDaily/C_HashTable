#include <stdio.h>
#include "hashtable.h"
#include "logger.h"

int main(void)
{
    const char *string = "d001";
    unsigned int index = hash(string);

    printf("Hash: %d\n", index);

    hash_table ht = {0};

    entry bob1 = {
        .name = "Bob",
        .age = 18,
    };

    entry bob2 = {
        .name = "Bob",
        .age = 21,
    };

    entry alex = {
        .name = "Alex",
        .age = 25,
    };

    hash_table_put(&ht, &bob1);
    hash_table_put(&ht, &bob2);
    hash_table_put(&ht, &alex);

    print_ht(&ht);

    info("=============");

    entry lookup = hash_table_delete(&ht, "Bob");

    print_entry(&lookup);
    print_ht(&ht);

    return 0;
}
