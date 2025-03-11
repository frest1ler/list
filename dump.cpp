#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "list_function.h"

void dump_print(int* addr, const char* name, FILE * point_to_file);
void dump_print(int i, int* prev, int* data, int* next, FILE * point_to_file);
void dump_align(FILE * point_to_file);
void dump_connection(FILE * point_to_file, Data_list* list);
void dump_header(FILE * point_to_file, Data_list* list);

void dump(Data_list* list, char* fname)
{
    FILE * point_to_file = fopen(fname, "w");

    if (!point_to_file)
    {
        printf("The file does not open\n");

        exit(EXIT_FAILURE);
    }
    
    fprintf(point_to_file, "digraph G{\n rankdir = LR;\n bgcolor = grey;\n node[color = blue, fontsize = 10];\n edge[color = blue, fontsize = 15];\n");
    fprintf(point_to_file, "subgraph cluster_list {\n node[style = filled, color = white, fontsize = 10];\n edge[color = blue, fontsize = 15];\n style = dashed;");
    fprintf(point_to_file, "color = black;");

    for(int i = 0; i < INITIAL_SIZE_DATA; i++)
    {
        dump_print(i, list->prev, list->data, list->next, point_to_file);    
    }

    dump_align(point_to_file);

    dump_connection(point_to_file, list);

    dump_header(point_to_file, list);

    fprintf(point_to_file, "\n}\n}");

    fclose(point_to_file);
}

void dump_print(int i, int* prev, int* data, int* next, FILE * point_to_file)
{
    fprintf(point_to_file,"%d [shape = Mrecord, style = filled, fillcolor = white, color = blue, label = \" IP: %d | DATA: %d | NXT: %d | PRV: %d \"];\n", i, i, data[i], next[i], prev[i]);
   
}

void dump_align(FILE * point_to_file)
{
    for(int i = 0; i < INITIAL_SIZE_DATA - 1; i++)
    {
        fprintf(point_to_file, "%d ->", i);
    }

    fprintf(point_to_file, "%d [weight = 10000, color = invis];\n", INITIAL_SIZE_DATA - 1);
}

void dump_connection(FILE * point_to_file, Data_list* list)
{
     if (point_to_file == NULL) {
        perror("Ошибка открытия файла");
        return;
    }

    int index = list->head;
    int index_bef = 0;

    if (index < 0){
        return;
    }

    while(list->next[index] != POISON && index < INITIAL_SIZE_DATA &&
          list->data[index] != POISON_FREE && index != index_bef && index >= 0)
    {
        index_bef = index;

        index = list->next[index];

        if (index_bef != index){
            fprintf(point_to_file, "%d -> %d [color = blue, weight = 0];\n", index_bef, index);
        }
    }
    int free      = list->next[list->free];
    int prev_free =             list->free;

    while(free != list->free)
    {
        fprintf(point_to_file, "%d -> %d [color = red, weight = 0];\n", prev_free, free);

        prev_free =             free;
        free      = list->next[free];
    }
}

void dump_header(FILE * point_to_file, Data_list* list)
{
    fprintf(point_to_file, "All[shape = Mrecord, label = \" HEADER | <f0> Size: %d | <f1> Head: %d | <f2> Tail: %d | <f3> Free: %d \", style = \"filled\", fillcolor = \"#ffe4c4\"];", list->size, list->head, list->tail, list->free);
    fprintf(point_to_file, "All:<f1> -> %d [color = blue];", list->head);
    fprintf(point_to_file, "All:<f2> -> %d [color = green];", list->tail);
    fprintf(point_to_file, "All:<f3> -> %d [color = red];", list->free);
}
  //1 -> 2 [color = "#0000ff", weight = 0] //blue
  //3 -> 1 [color = "#0000ff", weight = 0]
  //4 -> 5 [color = "#00ff00", weight = 0]//green
  //1 -> 3 [color = "#ff0000", weight = 0]//red
  //2 -> 1 [color = "#ff0000", weight = 0]