#include <stdio.h>
#include <stdlib.h>
#include "list_function.h"
#include "dump.h"

int search_index_of_value(int value, int* mass)
{
    for(int i = 0; i < INITIAL_SIZE_DATA; i++)
    {
        if (value == mass[i])
        {
            return i;
        }
    }

    printf("value not found\n");

    exit(EXIT_FAILURE);
}

int search_free_index(int * mass)
{
    for(int i = 1; i < INITIAL_SIZE_DATA; i++)
    {
        if (-1 == mass[i])
        {
            return i;
        }
    }
    return 0;
}

void add_elem(int value, Data_list* list)
{ 
    int free = search_free_index(list->data);
    
    list->data[free] = value;

    int index = search_index(value, list);

    int prev_el_copy = list->prev[index];

    list->prev[index] = free;
    list->prev[free] = prev_el_copy;

    int next_el_copy = list->next[list->prev[index]];

    list->next[list->prev[index]] = free;
    list->next[free] = next_el_copy;

    dump(list);
}

int search_index(int value, Data_list* list)
{
    int i = 0;
    int index = search_index_of_value(0, list->prev);

    while(value > list->data[index])
    {
        i++;
        index = search_index_of_value(i, list->prev);
    }

    return index;    
}