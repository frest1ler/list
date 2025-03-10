#include <stdio.h>
#include <stdlib.h>
#include "list_create.h"

Data_list* get_pointer_list()
{
    Data_list* list = (Data_list*)calloc(1, sizeof(Data_list));

    if (list == NULL)
    {
        printf("Memory allocation failed\n");

        return NULL;
    }

    return list;
}

void list_destroy(Data_list*  list)
{
    if (list->data != NULL)
    {
        free(list->data);
    }
    else
    {
        printf("NULL pointer list->data\n");
    }

    if (list->next != NULL)
    {
        free(list->next);
    }
    else
    {
        printf("NULL pointer list->next\n");
    }

    if (list->prev != NULL)
    {
        free(list->prev);
    }
    else
    {
        printf("NULL pointer list->prev\n");
    }

    if (list != NULL)
    {
        free(list);
    }
    else
    {
        printf("NULL pointer list\n");
    }
}
void list_ctor(Data_list* list)
{
    list->data = (int*)calloc(INITIAL_SIZE_DATA, sizeof(int));
    list->next = (int*)calloc(INITIAL_SIZE_DATA, sizeof(int));
    list->prev = (int*)calloc(INITIAL_SIZE_DATA, sizeof(int));

    list_fill(list);
}

void list_fill(Data_list* list)
{
    for(int i = 0; i < INITIAL_SIZE_DATA; i++)
    {
        list->data[i] = POISON_FREE;
        list->next[i] = i + 1;
        list->prev[i] = i - 1;
    }
    list->prev[0] = INITIAL_SIZE_DATA - 1;
    list->next[INITIAL_SIZE_DATA - 1] = 0;

    list->free = INITIAL_FREE_INDEX      ;
    list->head = HEAD_AND_TAIL_INIT_INDEX;
    list->tail = HEAD_AND_TAIL_INIT_INDEX;
}