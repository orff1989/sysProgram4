#include "graph.c"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>


int main(int argc, char const *argv[])
{
    graph *g=NULL;
    char ch;
    ch = getchar();

    if(ch=='A'){
        if(g) free(g);
        g=(graph*)malloc(sizeof(graph*));
        ch=build_graph_cmd(g);
    }
    printGraph_cmd(g);
    return 0;
}
