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

void put(hash_table*, person*);

person get(hash_table*, const char* name);