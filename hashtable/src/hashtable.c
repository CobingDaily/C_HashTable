#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "logger.h"

#define TABLE_SIZE 10


typedef struct {
    int key;
    const char* val;
} entry_t;

typedef struct {
    int count;
    entry_t entries[TABLE_SIZE];
} table_t;

int hash(const char* str) {
    int sum = 0;
    int size = 0;
    while(str[size] != '\0')
    {
        size++;
        sum += str[size] * 31;
    }
    
    return sum % TABLE_SIZE;
}

void put(table_t *table, const char* value) {
    int* current = &table->count;
    if (*current == TABLE_SIZE)
    {
        error("Table Overflow");
    }
    
    int index = hash(value);

    while (table->entries[index].val != NULL)
    {
        index = (index + 1) % TABLE_SIZE;
    }
    

    entry_t* current_entry = &table->entries[index];

    current_entry->key = index;
    current_entry->val = value;
    
    table->count++;
}

void print_entry(entry_t *entry) {
    int* key = &entry->key;
    const char* val = entry->val;

    printf("  Key: %d - Val: %s\n", *key, val);
}

void print_table(table_t *table, bool show_empty)
{
    int* count = &table->count;
    printf("count: %d\n", *count);

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        entry_t* entry = &table->entries[i];
        if (!show_empty && entry->val == NULL)
        {
            continue;
        }
        
        print_entry(entry);
    }
    
}

int main(void) {
    table_t table = {0};
    put(&table, "test0");
    put(&table, "test1");
    put(&table, "test2");
    put(&table, "test3");
    put(&table, "test4");
    put(&table, "test5");
    put(&table, "test6");
    put(&table, "test7");
    put(&table, "test8");
    put(&table, "test9");
    // put(&table, "test10");

    print_table(&table, false);

    return 0;
}
