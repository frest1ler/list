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
    dump(list, "data.dot");
    add_el(25, list);
    dump(list, "data2.dot");
    add_el(25, list);
    add_el(25, list);

    list_destroy(list);
    
    return 0;
}

