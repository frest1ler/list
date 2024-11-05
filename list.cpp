#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "dump.h"

Data_list* get_pointer_list();
void       list_ctor(Data_list* list);
void       list_destroy(Data_list* list);
void       fill_value(Data_list* list);

int main()
{
    Data_list* list = get_pointer_list();

    list_ctor(list);
    
    fill_value(list);

    dump(list);

    list_destroy(list);
}

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
}

void fill_value(Data_list* list)
{
    list->data[0]=0;
    list->data[1]=10;
    list->data[2]=20;
    list->data[3]=30;
    list->data[4]=40;
    list->data[5]=50;
    list->data[6]=25;

    list->next[0]=0;
    list->next[1]=2;
    list->next[2]=6;
    list->next[3]=4;
    list->next[4]=5;
    list->next[5]=0;
    list->next[6]=3;

    list->prev[0]=0;
    list->prev[1]=0;
    list->prev[2]=1;
    list->prev[3]=6;
    list->prev[4]=3;
    list->prev[5]=4;
    list->prev[6]=2;
}