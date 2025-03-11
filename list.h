#ifndef LIST_H
#define LIST_H

const int INITIAL_SIZE_DATA        =   10;
const int INITIAL_FREE_INDEX       =    1;
const int POISON_FREE              = -333;
const int POISON                   =   -1;

struct Data_list
{   
    int  size;
    int  tail;
    int  head;
    int  free;
    int* data;
    int* next;
    int* prev;
};

#endif /*LIST_H*/