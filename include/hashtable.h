#pragma once

#define TABLE_SIZE 10

typedef struct
{
    const char *name;
    unsigned int age;
} entry;

typedef struct
{
    entry entries[TABLE_SIZE];
    unsigned int count;
} hash_table;

unsigned int hash(const char *);

void hash_table_put(hash_table *, entry *);

entry hash_table_get(hash_table *, const char *name);

entry hash_table_delete(hash_table *, const char *name);

// Utilities
void print_entry(entry *);

void print_ht(hash_table *);