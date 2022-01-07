#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

//this is a node struct
typedef struct node {
    int numOfNode;
    struct node *next; 
    float w;
}Node;

//this is the graph sturct
typedef struct Greph{
    Node **head;
    int Vsize; //this var is represent the number of nodes
}graph;


//this method builds the graph
char build_graph_cmd(graph *g){
    
    char isDest,c;
    int srcc, destt, ww,number_of_nodes;
    

    fflush(stdin);
    while (getchar()!=' ');
    number_of_nodes = getchar()-'0';
    
    fflush(stdin);
    while (getchar()!=' ');
    c= getchar();

    g->Vsize=number_of_nodes;

    g->head=(Node**)malloc(number_of_nodes*sizeof(Node*));
    
    for (int i = 0; i < number_of_nodes; i++){
    g->head[i]=NULL;
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
            if (!node)
            {
              printf("out of memory");
            }

           (*node).next=NULL;
           (*node).numOfNode=destt;
           (*node).w=ww;
           
            
           node->next=g->head[srcc];
           g->head[srcc]=node;

            fflush(stdin);
            if(scanf("%c",&isDest)<0){
                isDest=-1;
            }else{
                if (isDest=='\n')
                {
                    isDest=-1;
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

//this method free the nodes from the stack
void freeNodesFrom(graph *g , int src){
        Node *prev=NULL;
        Node *n = g->head[src];
        while (n!=NULL )
        {
           prev =n;
           n=n->next;
           free(prev);
        }
        g->head[src]=NULL;
}

//this mehtod creats new node
char createNewNode(graph *g){
    char isDest;
    int srcc, destt, ww;
    
    fflush(stdin);
    while (getchar()!=' ');
    srcc = getchar()-'0';

    
    if (srcc<g->Vsize){
        freeNodesFrom(g,srcc);
        g->head[srcc]=NULL;
    }
    else{
        g->Vsize=g->Vsize+1;
        g->head=(Node**)realloc(g->head, (g->Vsize)*sizeof(Node*));
        if (!g->head)
            {
                printf("out of memory");
            }
        g->head[srcc]=NULL;
     }  
    
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
                isDest=-1;
            }
            else if(isDest=='\n' || isDest=='A' || isDest=='B' || isDest=='n'|| isDest=='S' || isDest=='T') break;
                
                
            fflush(stdin);
            isDest=getchar();    
       }
       
    return isDest;
}

//this method prints the graph
void printGraph_cmd(graph *g){
    for (int i = 0; i <= g->Vsize; i++)
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

//this method free the graph from the stack
void freeGraph(graph *g){

    for (int i = 0; i < g->Vsize; i++)
    {
        Node *prev=NULL;
        Node *n = g->head[i];
        while (n!=NULL)
        {
           prev =n;
           n=n->next;
           free(prev);
        }
    }
    free(g);
}


//this returns the weight of every edge
int isTherePath(graph *g, int i, int j){
    if (i==j)
    {
       return 0;
    }
    
    Node *n = g->head[i];
    while (n!=NULL){
           if(n->numOfNode==j) return n->w;

           n=n->next;
    }
    return 0;
}

//this method returns the lowsest distance
int lowestDistance(int distance[], int isInThePath[],int maxNodeNum){
    int min=__INT_MAX__;
    int minIndex=0;

    for (int i = 0; i < maxNodeNum; i++)
    {
        if(isInThePath[i]==0 && distance[i]<=min){
            min=distance[i];
            minIndex=i;
        }
    }
    
    return minIndex;
}

//thie method finds the shortest path in the graph
void dijkstra(graph *g, int src, int dest, int maxNodeNumber){
    
    int isInThePath[maxNodeNumber];
    int distance[maxNodeNumber];
    int thereIsPath=0;
    for (int i = 0; i < maxNodeNumber; i++){
        distance[i]=__INT_MAX__;
        isInThePath[i]=0;
    }
    
    distance[src]=0;
    
    for (int i = 0; i < maxNodeNumber-1; i++){
        int minDistNode=lowestDistance(distance,isInThePath,maxNodeNumber);
        isInThePath[minDistNode]=1;


        for (int j = 0; j < maxNodeNumber; j++)
        {
            thereIsPath=0;
            thereIsPath=isTherePath(g,minDistNode,j);

            if(!isInThePath[j] && thereIsPath && distance[minDistNode]!=__INT_MAX__ && distance[minDistNode] + thereIsPath <distance[j]){
                distance[j]= distance[minDistNode]+thereIsPath;
            }
        }
        
    }

    
    if(distance[dest]==__INT_MAX__) printf("Dijsktra shortest path: -1\n");
    else printf("Dijsktra shortest path: %d\n",distance[dest]);

}
    
//this method checks if the number is in the array
int isInArr(int* arr,int NodeNum, int arrSize){
    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i]==NodeNum)
        {
           return 1;
        }
    }
    return 0;
}

//this mehtod checks if all the node in the list was visited
int allvisited(int* arr, int* completed, int numOfCities){
for (int i = 0; i < numOfCities; i++)
{   
    
    if(completed[arr[i]]==0) return 0;
}
return 1;
}

//this mehtod returns the number of neighbors of the node
int sizeOfNodeNeighbors(graph* g, int curr){
Node *n= g->head[curr];
int size=0;

while (n!=NULL)
{
    size++;
    n=n->next;
}

return size;
}

//this method returns the lightest next node that not visited
int theLightNextNodeNotVisited(graph* g,int* arr, int curr, int* completed, int numOfCities){
  if(curr==-1) return -1;
  int index= -1;
  if(sizeOfNodeNeighbors(g,curr)==0) return -1;
  int minW=__INT_MAX__;

  Node *n=g->head[curr];  
  while (n!=NULL)
  {
      if(n->w<minW){
          if(isInArr(arr,n->numOfNode,numOfCities)==0 || completed[n->numOfNode]==0){
              minW=n->w;
              index=n->numOfNode;
          }
      }
      n=n->next;
  }

  return index; 
}

//this method returns the lightest next node
int theLightNextNode(graph* g,int* arr, int curr, int numOfCities){
  if(curr==-1) return -1;
  int index= -1;
  if(sizeOfNodeNeighbors(g,curr)==0) return -1;
  int minW=__INT_MAX__;

  Node *n=g->head[curr];  
  while (n!=NULL)
  {
      if(n->w<minW){
        minW=n->w;
        index=n->numOfNode;   
      }
      n=n->next;
  }

  return index; 
}

//this method returns the weight of the shortest path to get all the nodes in the list
void tsp(graph* g, int* arr, int* completed, int numOfCities){
    int srcIndex=0, nextNode=-1;
    int curr = srcIndex;
    int weight=0;
    
    while (allvisited(arr, completed,numOfCities)==0)
    {

       completed[curr]=1;

       if(srcIndex>g->Vsize) break;

       nextNode=theLightNextNodeNotVisited(g, arr, curr,completed, numOfCities);

       if(nextNode==-1) nextNode=theLightNextNode(g, arr, curr, numOfCities);

       if(nextNode==-1){

       if (allvisited(arr, completed,numOfCities)==1) break;

       for (int i = 0; i < numOfCities; i++)
       {
            completed[arr[i]]=0;
       }
       
        srcIndex++;
        curr=srcIndex;
        weight=0;
        }

        if (nextNode!=-1)
        {
        
        weight=weight+isTherePath(g,curr,nextNode);
        curr=nextNode;
        
        }
        
        
    }
    
    if(weight!=0) printf("TSP shortest path: %d\n",weight);
    else printf("TSP shortest path: -1\n");
     
 } 

 

 
    



