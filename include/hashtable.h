/*
 * This is a header for a <str, int> hashtable implementation
 */
#pragma once
#include <stddef.h>

typedef struct
{
    const char *key;
    int value;
} element;

typedef struct
{
    size_t capacity;
    size_t size;
    element* elements;
} hash_table;

hash_table* new_hash_table(size_t capacity);

void free_hash_table(hash_table* ht);

unsigned int hash(hash_table* ht, const char* key);

void hash_table_put(hash_table* ht, const char* key, int value);

int hash_table_get(hash_table* ht, const char* key);

// element hash_table_delete(hash_table *, const char *key);

// Utilities
void print_element(element *);

void print_ht(hash_table *);