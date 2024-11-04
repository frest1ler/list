#include <stdio.h>
#include "list.h"

void dump_print(int* addr, const char* name);

void dump(Data_list* list)
{
    dump_print(list->prev, "prev");
    dump_print(list->data, "data");
    dump_print(list->next, "next");
}

void dump_print(int* addr, const char* name)
{
    printf("%s\n", name);

    for(int i = 0; i < INITIAL_SIZE_DATA; i++)
    {
        printf("%d ", addr[i]);
    }

    printf("\n");
}