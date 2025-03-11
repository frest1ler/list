#include <stdio.h>
#include <stdlib.h>
#include "list_create.h"
#include "list.h"
#include "dump.h"
#include "list_function.h"

int main()
{
    Data_list* list = get_pointer_list();

    list_ctor(list);

    add_end(25, list);
    dump(list, "bata.dot");
    add_end(25, list);
    dump(list, "bata2.dot");
    add_end(25, list);
    dump(list, "bata3.dot");
    add_end(25, list);
    dump(list, "bata4.dot");
    add_end(25, list);
    dump(list, "bata5.dot");
    add_end(25, list);
    dump(list, "bata6.dot");
    add_end(25, list);
    dump(list, "bata7.dot");
    add_end(2, list);
    dump(list, "bata8.dot");
    add_end(25, list);
    dump(list, "bata9.dot");
    take_el(5, list);
    dump(list, "bata10.dot");

    list_destroy(list);
    
    return 0;
}

