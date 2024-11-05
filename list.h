#ifndef LIST_H
#define LIST_H

const int INITIAL_SIZE_DATA = 10;

struct Data_list
{
    int  tail;
    int  head;
    int  free;
    int* data;
    int* next;
    int* prev;
};

#endif /*LIST_H*/