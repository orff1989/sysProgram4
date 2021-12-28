#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

graph build_graph_cmd(){
    graph *g=(graph*)malloc(sizeof(graph)); //allocating memory for the graph

    int number_of_nodes;   //getting the numbers of nodes
    scanf("%d", &number_of_nodes);
    g->Vsize=number_of_nodes;
    for (int i = 0; i < number_of_nodes; i++){
    g->head[i]=NULL;
    }

    char ch;
    int srcc,destt;
    float ww;
    ch = getchar();
    Node *prevNode=NULL;
    while (ch!='n'){ //while to get the txt
       
       scanf("%d", &srcc);
       while (scanf("%d", &destt)!=EOF){
           scanf("%f", &ww);
           Node *node =(Node*)malloc(sizeof(Node)); //allocating memory for the node
           (*node).next=NULL;
            (*node).numOfNode=destt;
            (*node).w=ww;
            
           if (!prevNode){
               g->head=node;
           }
           prevNode=node;
            
       }
       
       
       
     }

    

    for (size_t i = 0; i < count; i++)
    {
    /* code */
    }



}