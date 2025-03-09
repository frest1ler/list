#ifndef LIST_CREATE_H
#define LIST_CREATE_H

#include "list.h"

Data_list* get_pointer_list();
void       list_ctor(Data_list* list);
void       list_destroy(Data_list* list);
void       list_fill(Data_list* list);
#endif /*LIST_CREATE_H*/