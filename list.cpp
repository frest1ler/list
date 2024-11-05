#include <stdio.h>
#include <stdlib.h>
#include "list_create.h"
#include "list.h"
#include "dump.h"
#include "list_function.h"

void fill_value(Data_list* list);

int main()
{
    Data_list* list = get_pointer_list();

    list_ctor(list);
    
    fill_value(list);

    dump(list);

    list_destroy(list);
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