#pragma once

#define TABLE_SIZE 10

typedef struct
{
    const char *key;
    unsigned int value;
} element;

typedef struct
{
    element entries[TABLE_SIZE];
    unsigned int count;
} hash_table;

unsigned int hash(const char *);

void hash_table_put(hash_table *, element *);

element hash_table_get(hash_table *, const char *key);

element hash_table_delete(hash_table *, const char *key);

// Utilities
void print_entry(element *);

void print_ht(hash_table *);