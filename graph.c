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
    int helper=0;

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

    helper=0;
    while (c=='n'){ 

       fflush(stdin);
       while (getchar()!=' ');
       srcc = getchar()-'0';
       helper=1;

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
        g->head=(Node**)realloc(g->head,g->Vsize*sizeof(Node*));
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
                isDest=NULL;
            }
            else if(isDest=='\n' || isDest=='A' || isDest=='B' || isDest=='n'|| isDest=='S' || isDest=='T') break;
                
                
            fflush(stdin);
            isDest=getchar();    
       }
       
    return isDest;
}

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

int getMaxNodeNum(graph* g){
    int maxIndex=0;
for (int i = 0; i <= g->Vsize; i++)
    {
        
        Node *n = g->head[i];
        while (n!=NULL)
        {
           if(maxIndex<n->numOfNode) maxIndex=n->numOfNode;
           n=n->next;
        }

    }
}

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

void dijkstra(graph *g, int src, int dest, int maxNodeNumber){
    
    int isInThePath[maxNodeNumber];
    char path[]="";
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
    
// void tsp(graph* g, int* arr, int* completed, int numOfCities){
//     int theCost=0;
//     tspHelper(g, arr, 0, completed, (&theCost), numOfCities);

//     if(theCost<999 && theCost!=0) printf("TSP shortest path: %d\n",theCost);
//     else printf("TSP shortest path: -1\n");
// }

// int tspHelper(graph* g, int* arr, int c, int* completed, int* theCost, int numOfCities){

//  int count, nearest_city = 999;
//  int minimum = 999, temp;

//  for (int i = 0; i < numOfCities; i++)
//  {
//      if(isTherePath(g,c,i)!=0 && completed[c]==0){
//          if(isTherePath(g,c,i)<minimum){
//              minimum= isTherePath(g,i,0)+
//          }
//      }
//  }
 
// }

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

int allvisited(int* arr, int* completed, int numOfCities){
for (int i = 0; i < numOfCities; i++)
{   
    
    if(completed[arr[i]]==0) return 0;
}
return 1;
}

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

 

 
    



