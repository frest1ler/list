#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "list_function.h"

void dump_print(int* addr, const char* name, FILE * point_to_file);
void dump_print(int i, int* prev, int* data, int* next, FILE * point_to_file);
void dump_align(FILE * point_to_file);
void dump_connection(FILE * point_to_file, Data_list* list);

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

    int index = 1;
    int index_bef = 0;

    while(list->next[index] != 0 && index < INITIAL_SIZE_DATA && list->data[index] != POISON_FREE)
    {
        index_bef = index;

        index = list->next[index];

        fprintf(point_to_file, "%d -> %d [color = blue, weight = 0];\n", index_bef, index);
    }
}
  //1 -> 2 [color = "#0000ff", weight = 0] //blue
  //3 -> 1 [color = "#0000ff", weight = 0]
  //4 -> 5 [color = "#00ff00", weight = 0]//green
  //1 -> 3 [color = "#ff0000", weight = 0]//red
  //2 -> 1 [color = "#ff0000", weight = 0]