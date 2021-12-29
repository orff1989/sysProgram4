#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

#define NULL 0

typedef struct Node {
    int numOfNode;
    struct Node *next; 
    float w;
}Node;


typedef struct graph
{
    struct Node **head;
    int Vsize; //this var is represent the number of nodes
}graph;




char build_graph_cmd(graph g);
// void insert_node_cmd(struct Node *head);
// void delete_node_cmd(struct Node *head);
// void printGraph_cmd(graph g); //for self debug
// void deleteGraph_cmd(struct Node* head);
// void shortsPath_cmd(struct Node head);
// void TSP_cmd(struct Node head);


