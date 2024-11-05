#ifndef LIST_FUNCTION_H
#define  LIST_FUNCTION_H

#include "list.h"

int  search_index_of_value(int value, int* mass);
int  search_free_index(int * mass);
int  search_index(int value, Data_list* list);
void add_elem(int value, Data_list* list);

#endif /*LIST_FUNCTION_H*/