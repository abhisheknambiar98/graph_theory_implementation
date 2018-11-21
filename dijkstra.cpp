#include <stdio.h> 
#include <limits.h> 
   
#define N 9 

int minimumDistance(int dist[], bool sptSet[]) 
{ 
   int min = INT_MAX, min_index;  
   for (int v = 0; v < N; v++) 
     if (sptSet[v] == false && dist[v] <= min) 
         min = dist[v], min_index = v; 
   return min_index; 
} 
   
int display(int dist[], int n) 
{ 
   printf("Vertex   Distance from root\n"); 
   for (int i = 0; i < N; i++) 
      printf("%d \t %d\n", i, dist[i]); 
} 

void dijkstra(int graph[N][N], int src) 
{ 
     int dist[N];  
     bool sptSet[N];
 
     for (int i = 0; i < N; i++) 
        dist[i] = INT_MAX, sptSet[i] = false; 

     dist[src] = 0; 
     for (int i = 0;i < N-1; i++) 
     { 
       int u = minimumDistance(dist, sptSet); 
       sptSet[u] = true; 
       for (int v = 0; v < N; v++) 
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX  
                                       && dist[u]+graph[u][v] < dist[v]) 
            dist[v] = dist[u] + graph[u][v]; 
     } 
     display(dist, N); 
} 
   
void main() 
{ 
   int graph[N][N] = {{0, 4, 0, 0, 0, 0, 0, 8, 0}, 
                      {4, 0, 8, 0, 0, 0, 0, 11, 0}, 
                      {0, 8, 0, 7, 0, 4, 0, 0, 2}, 
                      {0, 0, 7, 0, 9, 14, 0, 0, 0}, 
                      {0, 0, 0, 9, 0, 10, 0, 0, 0}, 
                      {0, 0, 4, 14, 10, 0, 2, 0, 0}, 
                      {0, 0, 0, 0, 0, 2, 0, 1, 6}, 
                      {8, 11, 0, 0, 0, 0, 1, 0, 7}, 
                      {0, 0, 2, 0, 0, 0, 6, 7, 0} 
                     }; 
   
    dijkstra(graph, 0); 
   
} 
