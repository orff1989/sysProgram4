#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

char build_graph_cmd(graph *g){
    int number_of_nodes;   //getting the numbers of nodes
    scanf("%d", &number_of_nodes);
    g->Vsize=number_of_nodes;
    for (int i = 0; i < number_of_nodes; i++){
    g->head[i]=NULL;
    }

    char ch;
    int srcc,destt;
    char isDest;
    float ww;
    
    Node *prevNode=NULL;

    ch = getchar();
    while (ch=='n'){ //while to get the txt
       
       scanf("%d", &srcc);
       scanf("%c", &isDest);
       while (isdigit(isDest)){
           destt= isDest -'0';
           scanf("%f", &ww);

           Node *node =(Node*)malloc(sizeof(Node)); //allocating memory for the node
           (*node).next=NULL;
            (*node).numOfNode=destt;
            (*node).w=ww;
            
           if (!prevNode){
               g->head[srcc]=node;
           } else{
               prevNode->next=node;
           }
           prevNode=node;
       }
     }
}
// void printGraph_cmd(graph *g){
//     for (int i = 0; i < g->Vsize; i++)
//     {
//         Node *n = NULL;
//         n = g->head[i];
//         while (!n)
//         {
//            printf("(%d —> %d)\t", i, n->numOfNode);
//            n=n->next;
//         }
//         printf("\n");

//     }
    
// }