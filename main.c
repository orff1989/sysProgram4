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

    while(ch=='A' || ch == 'B' || ch=='D' || ch == 'S' || ch == 'T'){
    if(ch=='A'){
        if(g) freeGraph(g);
        g=(graph*)malloc(sizeof(graph*));
        ch=build_graph_cmd(g);
    }
    if(ch=='B'){
        ch=createNewNode(g);
    }
    if(ch=='D'){
        fflush(stdin);
        while (getchar()!=' ');
        int num = getchar()-'0';
        freeNodesFrom(g,num);

        while ((ch = getchar()) != '\n' && ch != EOF) { 
            if (ch=='A' || ch == 'B' || ch=='D' || ch == 'S' || ch == 'T')
            {
                break;
            }  
        }
    }
    if(ch=='S'){
        fflush(stdin);
        while (getchar()!=' ');
        int src = getchar()-'0';
        fflush(stdin);
        while (getchar()!=' ');
        int dest = getchar()-'0';

        dijkstra(g,src,dest, g->Vsize);

        while ((ch = getchar()) != '\n' && ch != EOF) { 
            if (ch=='A' || ch == 'B' || ch=='D' || ch == 'S' || ch == 'T')
            {
                break;
            }  
        }

    }
    if(ch=='T'){
        fflush(stdin);
        while (getchar()!=' ');
        int numOfCities = getchar()-'0';
        
        int arr[numOfCities];
        int completed[g->Vsize];
       

         for (int i = 0; i < g->Vsize; i++)
        {
            completed[i]=1;
        }

        for (int i = 0; i < numOfCities; i++)
        {
            fflush(stdin);
            while (getchar()!=' ');
            arr[i]= getchar()-'0';
            completed[arr[i]]=0;
        }
       
        tsp(g,arr,completed,numOfCities);
        
        
        while ((ch = getchar()) != '\n' && ch != EOF) { 
            if (ch=='A' || ch == 'B' || ch=='D' || ch == 'S' || ch == 'T')
            {
                break;
            }  
        }
    }
        
    }
    
    
    return 0;
}
