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

    element* elements = calloc(capacity, sizeof(element));
    if (!elements)
    {
        free(ht);
        return NULL;
    }

    ht->size = 0;
    ht->capacity = capacity;
    ht->elements = elements;
    return ht;
}

void hash_table_resize(hash_table* ht, size_t new_capacity)
{   
    if (!ht)
    {
        return;
    }

    element* elements = realloc(ht->elements, new_capacity * sizeof(element));
    if (!elements)
    {
        return;
    }
    ht->capacity = new_capacity;
    ht->elements = elements;
}

void free_hash_table(hash_table* ht)
{
    if (!ht) return;
    
    if (ht->elements)
    {
        free(ht->elements);
    }
    
    free(ht);
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

    return sum % ht->capacity;
}

void hash_table_put(hash_table* ht, const char* key, int value)
{
    if (ht->size == ht->capacity)
    {
        hash_table_resize(ht, ht->capacity * 2);
    }

    unsigned int index = hash(ht, key);

    element* current = &ht->elements[index];

    while (current->key && strcmp(current->key, key))
    {
        index = (index + 1) % ht->capacity;
        current = &ht->elements[index];
    }

    ht->elements[index].key = key;
    ht->elements[index].value = value;
    ht->size++;
}

int hash_table_get(hash_table* ht, const char* key)
{
    unsigned int index = hash(ht, key);

    element* current = &ht->elements[index];

    while (current->key && strcmp(current->key, key))
    {
        index = (index + 1) % ht->capacity;
        current = &ht->elements[index];
    }

    return current->value;
}

int hash_table_delete(hash_table* ht, const char* key)
{
    unsigned int index = hash(ht, key);

    element *current = &ht->elements[index];

    while (current->key && strcmp(current->key, key))
    {
        index = (index + 1) % ht->capacity;
        current = &ht->elements[index];
    }
    int ret = current->value;
    current->key = NULL;
    current->value = 0;

    ht->size--;
    return ret;
}

// // Utilities

void print_element(element *e)
{
    if (e == NULL)
    {
        printf("{Key: NULL, Value: NULL}\n");
        return;
    }
    
    printf("{Key: %s, Value: %d}\n", e->key, e->value);
}

void print_ht(hash_table *ht)
{
    element* elements = ht->elements;

    for (size_t i = 0; i < ht->capacity; i++)
    {
        printf("[%ld] => ", i);
        print_element(&elements[i]);
    }
}