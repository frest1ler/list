#include <stdio.h>
#include <stdlib.h>
#include "list_function.h"
#include "dump.h"

int max(int a, int b);

void add_el(int value, Data_list* list)
{ 
    list->data[list->free] = value;

    int next_free = list->next[list->free];
    int prev_free = list->prev[list->free];

    list->prev[list->free] = list->tail;
    list->next[list->free] =          0;

    if (list->tail != 0){
        list->next[list->tail] = list->free;    
    }
    list->prev[next_free] = prev_free;

    list->tail = max(list->tail, list->free);

    list->free = next_free;

}

void take_el(int index, Data_list* list)
{
    if (list->data[index] == POISON_FREE || list->data[index] == POISON){
        return;
    }
    else{
        list->data[index] = POISON_FREE;

        int prev = list->prev[index];
        int next = list->next[index];   

        list->prev[next] = prev;
        list->next[prev] = next;

        list->prev[list->free] = index;
        list->next[index] = list->free;

        (list->tail)--;   
    }
}

int max(int a, int b)
{
    if (a > b){
        return a;
    }
    return b;
}