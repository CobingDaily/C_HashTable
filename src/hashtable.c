#include <stdio.h>
#include <string.h>
#include "hashtable.h"
#include "logger.h"

unsigned int hash(const char *string)
{
    unsigned int sum = 0;

    int pos = 0;
    while (string[pos] != '\0')
    {
        sum += string[pos] * 31;
        pos++;
    }

    return sum % TABLE_SIZE;
}

void hash_table_put(hash_table* ht, entry* e)
{
    unsigned int index = hash(e->name);

    entry *current = &ht->entries[index];

    while (current->name && strcmp(current->name, e->name))
    {
        info("Strings don't match");
        index = (index + 1) % TABLE_SIZE;
        current = &ht->entries[index];

    }

    ht->entries[index].age = e->age;
    ht->entries[index].name = e->name;
}

// Utilities

void print_entry(entry* e) {
    printf("{Name: %s, Age: %d}\n", e->name, e->age);
}

void print_ht(hash_table* ht)
{
    entry* entries = ht->entries;

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        printf("[%d] => ", i);
        print_entry(&entries[i]);
    }
}