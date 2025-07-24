#include "stack.h"
#include <stdlib.h>


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


void stack_push(stack_t* stack, void* object)
{
    // Resize if capacity is exceeded
    if (stack->count == stack->capacity)
    {
        void** reallocated = realloc(stack->data, 2 * stack->capacity * sizeof(void*));
        if (!reallocated)
        {
            return;
        }

        stack->capacity *= 2;
        stack->data = reallocated;
    }

    // Add new object
    stack->data[stack->count] = object;
    stack->count++;
    return;
}


void* stack_pop(stack_t* stack)
{
    if (stack->count == 0)
    {
        return NULL;
    }

    stack->count--;
    return stack->data[stack->count];
}


void stack_free(stack_t* stack)
{
    if (stack == NULL)
    {
        return;
    }

    if (stack->data != NULL)
    {
        free(stack->data);
    }
    
    free(stack);
}