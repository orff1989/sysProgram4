#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

typedef struct node {
    int numOfNode;
    struct node *next; 
    float w;
}Node;


typedef struct Greph{
    Node **head;
    int Vsize; //this var is represent the number of nodes
}graph;



char build_graph_cmd(graph *g){
    
    char isDest,c;
    int srcc, destt, ww,number_of_nodes;
    Node *prevNode=NULL;

    fflush(stdin);
    while (getchar()!=' ');
    number_of_nodes = getchar()-'0';
    
    fflush(stdin);
    while (getchar()!=' ');
    c= getchar();

    g->Vsize=number_of_nodes;

    g->head=(Node**)malloc(number_of_nodes*sizeof(Node*));
    
    for (int i = 0; i < number_of_nodes; i++){
    *((g->head)+i)=NULL;
    }
    
    
    while (c=='n'){ 

       fflush(stdin);
       while (getchar()!=' ');
       srcc = getchar()-'0';

       fflush(stdin);
       while (getchar()!=' ');
       isDest=getchar();

       while (isdigit(isDest)){
           destt= isDest -'0';

           fflush(stdin);
           while (getchar()!=' ');
           ww= getchar()-'0';

           Node *node =(Node*)malloc(sizeof(Node)); //allocating memory for the node
           (*node).next=NULL;
           (*node).numOfNode=destt;
           (*node).w=ww;
            
           node->next=g->head[srcc];
           g->head[srcc]=node;

            fflush(stdin);
            if(scanf("%c",&isDest)<0){
                isDest=NULL;
            }else{
                if (isDest=='\n')
                {
                    isDest=NULL;
                    break;
                }
                
                fflush(stdin);
                isDest=getchar();
            }
       }
       c=isDest;
    }

    return c;
}

void printGraph_cmd(graph *g){
    for (int i = 0; i < g->Vsize; i++)
    {
        
        Node *n = g->head[i];
        while (n!=NULL)
        {
           printf("(%d —> %d)\t", i, n->numOfNode);
           n=n->next;
        }
        printf("\n");

    }
    
}
void freeGraph(graph *g){
    
}