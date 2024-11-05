#include "list_functions.h"

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

    return 0;
}

int search_free_index(int * mass)
{
    for(int i = 1; i < INITIAL_SIZE_DATA; i++)
    {
        if (0 == mass[i])
        {
            return i;
        }
    }
}

int look_for_membership_interval(int value, Data_list)
{

}

int add_elem(int value, Data_list* list)
{
    data[free] = value;

    look_for_membership_interval();

    search_free_index(list->data);

}