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

    add_el(25, list);
    dump(list, "bata.dot");
    take_el(1, list);
    dump(list, "bata2.dot");
    add_el(25, list);
    dump(list, "bata3.dot");
    add_el(25, list);
    dump(list, "bata4.dot");
    add_el(25, list);
    dump(list, "bata5.dot");
    add_el(25, list);
    dump(list, "bata6.dot");
    add_el(25, list);
    dump(list, "bata7.dot");
    take_el(3, list);
    dump(list, "bata8.dot");

    list_destroy(list);
    
    return 0;
}

