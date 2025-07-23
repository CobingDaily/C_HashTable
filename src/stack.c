#include "stack.h"

stack_t* stack_new(size_t capacity)
{
    // Create address for the stack metadata on the heap
    stack_t* stack_ptr = malloc(sizeof(stack_t));
    if (!stack_ptr)
    {
        return NULL;
    }

    // Create the address for the data
    void** data = malloc(sizeof(void*) * capacity);
    if (!data)
    {
        free(stack_ptr);
        return NULL;
    }

    // Initialize and return the stack
    stack_ptr->count = 0;
    stack_ptr->capacity = capacity;
    stack_ptr->data = data;
    
    return stack_ptr;
}