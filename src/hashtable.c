#include "hashtable.h"
#include "logger.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

hash_table* new_hash_table(size_t capacity)
{
    hash_table* ht = malloc(sizeof(hash_table));
    if (!ht) {
        return NULL;
    }

    element** elements = calloc(capacity, sizeof(element*));
    if (!elements)
    {
        free(ht);
        return NULL;
    }

    ht->size = 0;
    ht->capacity = capacity;
    ht->entries = elements;
    return ht;
}

unsigned int hash(hash_table* ht, const char *string)
{
    unsigned int sum = 0;

    int pos = 0;
    while (string[pos] != '\0')
    {
        sum += string[pos] * 31;
        pos++;
    }

    return sum % ht->size;
}

// void hash_table_put(hash_table *ht, element *e)
// {
//     unsigned int index = hash(e->key);

//     element *current = &ht->entries[index];

//     while (current->key && strcmp(current->key, e->key))
//     {
//         index = (index + 1) % TABLE_SIZE;
//         current = &ht->entries[index];
//     }

//     ht->entries[index].key = e->key;
//     ht->entries[index].value = e->value;
//     ht->count++;
// }

// element hash_table_get(hash_table *ht, const char *name)
// {
//     unsigned int index = hash(name);

//     element *current = &ht->entries[index];

//     while (current->key && strcmp(current->key, name))
//     {
//         index = (index + 1) % TABLE_SIZE;
//         current = &ht->entries[index];
//     }

//     return *current;
// }

// element hash_table_delete(hash_table *ht, const char *name)
// {
//     unsigned int index = hash(name);

//     element *current = &ht->entries[index];

//     while (current->key && strcmp(current->key, name))
//     {
//         index = (index + 1) % TABLE_SIZE;
//         current = &ht->entries[index];
//     }
//     element ret = *current;
//     current->key = NULL;
//     current->value = NULL;

//     ht->count--;
//     return ret;
// }

// // Utilities

// void print_entry(element *e)
// {
//     printf("{Name: %s, Age: %d}\n", e->key, e->value);
// }

// void print_ht(hash_table *ht)
// {
//     element *entries = ht->entries;

//     for (int i = 0; i < TABLE_SIZE; i++)
//     {
//         printf("[%d] => ", i);
//         print_entry(&entries[i]);
//     }
// }