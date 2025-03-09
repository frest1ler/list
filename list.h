#ifndef LIST_H
#define LIST_H

const int INITIAL_SIZE_DATA        =   10;
const int INITIAL_FREE_INDEX       =    1;
const int POISON_FREE              = -333;
const int POISON                   = -666;
const int HEAD_AND_TAIL_INIT_INDEX =    0;

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