#include <stdio.h>
#include <stdlib.h>
#include "list_function.h"
#include "dump.h"

void add_el(int value, Data_list* list)
{ 
    list->data[list->free] = value;

    int next_free = list->next[list->free];

    list->prev[list->free] = list->tail;
    list->next[list->free] = 0;
    if (list->tail != 0){
        list->next[list->tail] = list->free;    
    }
    
    list->free = next_free;

    (list->tail)++;
}

//void take_el()