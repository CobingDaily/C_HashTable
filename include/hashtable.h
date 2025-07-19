#pragma once

#define TABLE_SIZE 10

typedef struct {
    const char* name;
    unsigned int age;
} person;

typedef struct {
    unsigned int key;
    person value;
} entry;

typedef struct {
    entry entriers[TABLE_SIZE];
    unsigned int count;
} hash_table;

unsigned int hash(const char*);

void hash_table_put(hash_table*, person*);

person hash_table_get(hash_table*, const char* name);

person hash_table_delete(hash_table*, const char* name);
