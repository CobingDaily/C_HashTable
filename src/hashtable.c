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

void hash_table_put(hash_table *ht, element *e)
{
    unsigned int index = hash(e->key);

    element *current = &ht->entries[index];

    while (current->key && strcmp(current->key, e->key))
    {
        index = (index + 1) % TABLE_SIZE;
        current = &ht->entries[index];
    }

    ht->entries[index].key = e->key;
    ht->entries[index].value = e->value;
    ht->count++;
}

element hash_table_get(hash_table *ht, const char *name)
{
    unsigned int index = hash(name);

    element *current = &ht->entries[index];

    while (current->key && strcmp(current->key, name))
    {
        index = (index + 1) % TABLE_SIZE;
        current = &ht->entries[index];
    }

    return *current;
}

element hash_table_delete(hash_table *ht, const char *name)
{
    unsigned int index = hash(name);

    element *current = &ht->entries[index];

    while (current->key && strcmp(current->key, name))
    {
        index = (index + 1) % TABLE_SIZE;
        current = &ht->entries[index];
    }
    element ret = *current;
    current->key = NULL;
    current->value = NULL;

    ht->count--;
    return ret;
}

// Utilities

void print_entry(element *e)
{
    printf("{Name: %s, Age: %d}\n", e->key, e->value);
}

void print_ht(hash_table *ht)
{
    element *entries = ht->entries;

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        printf("[%d] => ", i);
        print_entry(&entries[i]);
    }
}