#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list_function.h"
#include "dump.h"

void add_end(int value, Data_list* list)
{
    assert(list);
    assert(list->data);
    assert(list->prev);
    assert(list->next);

    if (list->size == INITIAL_SIZE_DATA - 1){
        perror("No more elements will fit");
    }

    list->data[list->free] = value;
    
    int next_free = list->next[list->free];
    int prev_free = list->prev[list->free];

    list->next[prev_free] = next_free;    
    list->prev[next_free] = prev_free;

    if (list->tail != list->head)
    {   
        list->next[list->tail] = list->free;
        list->prev[list->free] = list->tail;
        list->next[list->free] =     POISON;

        list->tail = list->free;
    }
    else if (list->tail == POISON)
    {   
        list->next[list->free] = POISON;
        list->prev[list->free] = POISON;

        list->head = list->free;
    }
    else
    {
        list->next[list->free] =     POISON;
        list->prev[list->free] = list->tail;

        list->next[list->head] = list->free;
        list->prev[list->head] =     POISON;   
    }

    list->tail = list->free;

    list->free = next_free;

    (list->size)++;
}

void add_begin(int value, Data_list* list)
{   
    assert(list);
    assert(list->data);
    assert(list->prev);
    assert(list->next);

    if (list->size == INITIAL_SIZE_DATA - 1){
        perror("No more elements will fit");
    }

    list->data[list->free] = value;

    int next_free = list->next[list->free];
    int prev_free = list->prev[list->free];

    list->next[prev_free] = next_free;    
    list->prev[next_free] = prev_free;

    if (list->tail != list->head)
    {
        list->prev[list->head] = list->free;
        list->next[list->free] = list->head;
        list->prev[list->free] = POISON;

        list->head = list->free;
    }
    else if (list->tail == POISON)
    {
        list->prev[list->free] = POISON;
        list->next[list->free] = POISON;

        list->head = list->free;
        list->tail = list->free;
    }
    else
    {
        list->next[list->free] = list->head;
        list->prev[list->free] =     POISON;

        list->next[list->head] =     POISON;
        list->prev[list->head] = list->free;

        list->head = list->free;
    }
    list->free = next_free;

    (list->size)++;
}

void take_el(int index, Data_list* list)
{
    int prev_free = list->prev[list->free];

    if (list->data[index] == POISON_FREE){
        return;
    }
    else if (index == list->tail && list->head == list->tail)
    {
        list->head = POISON;
        list->tail = POISON;
    }
    else if (index == list->tail)
    {
        int prev_el = list->prev[index];
        list->next[prev_el] = POISON;

        list->tail = prev_el;
    }
    else if (index == list->head)
    {
        int next_el = list->next[index];
        list->prev[next_el] = POISON;

        list->head = next_el;
    }
    else
    {
        int prev_el = list->prev[index];
        int next_el = list->next[index];

        list->next[prev_el] = next_el;
        list->prev[next_el] = prev_el;
    }   
    list->data[index] = POISON_FREE;
    list->next[index] =  list->free;
    list->prev[index] =   prev_free;
    
    list->next[prev_free] =  index;
    list->prev[list->free] = index;

    (list->size)--;
}   
