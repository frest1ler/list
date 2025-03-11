#include <stdio.h>
#include <stdlib.h>
#include "list_function.h"
#include "dump.h"

int max(int a, int b);
int min(int a, int b);

void add_end(int value, Data_list* list)
{
    printf("add_end value=%d, free=%d\n", value, list->free);

    list->data[list->free] = value;

    int next_free = list->next[list->free];
    int prev_free = list->prev[list->free];

    list->next[prev_free] = next_free;    
    list->prev[next_free] = prev_free;

    list->prev[list->free] = list->tail;
    list->next[list->tail] = list->free;
    list->next[list->free] = POISON;

    list->tail = list->free;

    // if (list->tail != list->head)
    // {
    //     list->prev[list->free] = list->tail;
    //     list->prev[list->head] = list->tail;
    //     list->next[list->tail] = list->free;
    //     list->next[list->free] = list->head;

    //     list->tail = max(list->tail, list->free);
    //     list->head = min(list->head, list->free);
    // }
    // else if (list->tail == 0)
    // {
    //     list->prev[list->free] = list->free;
    //     list->next[list->free] = list->free;

    //     list->tail = list->free;
    //     list->head = list->free;    
    // }
    // else
    // {
    //     list->prev[list->head] = list->free;
    //     list->next[list->head] = list->free;
        
    //     list->next[list->free] = list->head;
    //     list->prev[list->free] = list->head;

    //     list->tail = max(list->tail, list->free);        
    //     list->head = min(list->head, list->free);       
    // }
    list->free = next_free;
}

void add_begin(int value, Data_list* list)
{   
    printf("add_begin value=%d, free=%d\n", value, list->free);

    list->data[list->free] = value;

    int next_free = list->next[list->free];
    int prev_free = list->prev[list->free];

    list->next[prev_free] = next_free;    
    list->prev[next_free] = prev_free;

    list->prev[list->head] = list->free;
    list->next[list->free] = list->head;
    list->prev[list->free] = POISON;

    list->head = list->free;

    list->free = next_free;
}

void take_el(int index, Data_list* list)
{
    if (list->data[index] == POISON_FREE){
        return;
    }
    else if(list->tail != list->head)
    {   
        //int new_tail = search_new(list->tail, list);
        //int new_head = search_new(list->head, list);

        printf("take_el list->tail != list->head\n");
        printf("take_el list->tail == %d\n", list->tail);
        printf("take_el list->head == %d\n", list->head);

        list->data[index] = POISON_FREE;

        int prev = list->prev[index];
        int next = list->next[index];   

        list->prev[next] = prev;
        list->next[prev] = next;

        list->prev[list->free] = index;
        list->next[index] = list->free;

        //list->tail = new_tail;
        //list->head = new_head;   
    }
    else //if(list->tail == list->head)
    {
        printf("take el list->tail == list->head\n");
        printf("add_el list->tail == %d\n", list->tail);

        list->data[index] = POISON_FREE;

        int prev_free = list->prev[list->free];

        list->next[prev_free] = index;
        list->prev[index] = prev_free;

        list->prev[list->free] = index;
        list->next[index] = list->free;

        list->head = 0;
        list->tail = 0;    
    }
}

int max(int a, int b)
{
    if (a > b){
        return a;
    }
    return b;
}

int min(int a, int b)
{
    if (a == max(a, b)){
        return b;
    }
    return a;
}
