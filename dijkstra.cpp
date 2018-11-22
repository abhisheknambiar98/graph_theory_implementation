#include <stdio.h> 
#include <limits.h> 

  
#define N 9 
  
int minDist(int dist[],   bool visited[]) 
{ 
      
    int min = INT_MAX, min_ind; 
  
    for (int v = 0; v < N; v++) 
        if (visited[v] == false && 
                   dist[v] <= min) 
            min = dist[v], min_ind = v; 
  
    return min_ind; 
} 
  
void displayPath(int path[], int j) 
{ 
    if (path[j] == - 1) 
        return; 
    displayPath(path, path[j]); 
    printf(" S%d ", j); 
} 
  

int displayDistance(int dist[], int n,  
                      int path[],int src ) 
{   
    printf("Systems in Network\t         Cost(Bandwidth)\t     Path"); 
    for (int i = 1; i < N; i++) 
    { 
        printf("\nSystem %d -> System %d \t\t %d\t\tS%d ", 
                      src, i, dist[i], src); 
        displayPath(path, i); 
    } 
} 
  
void dijkstra(int graph[N][N], int src) 
{ 
    int dist[N];  
    bool visited[N]; 
  
    int path[N]; 

    for (int i = 0; i < N; i++) 
    { 
        path[src] = -1; 
        dist[i] = INT_MAX; 
        visited[i] = false; 
    } 
    dist[src] = 0; 

    for (int i = 0;i < N - 1; i++) 
    { 

        int u = minDist(dist, visited); 
        visited[u] = true; 
        for (int v = 0; v < N; v++) 
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) 
            { 
                path[v] = u; 
                dist[v] = dist[u] + graph[u][v]; 
            }  
    } 
  
    displayDistance(dist, N, path,src); 
} 
  
int  main() 
{  int src;
    int graph[N][N] = {{0, 4, 0, 0, 0, 0, 0, 8, 0}, 
                       {4, 0, 8, 0, 0, 0, 0, 11, 0}, 
                        {0, 8, 0, 7, 0, 4, 0, 0, 2}, 
                        {0, 0, 7, 0, 9, 14, 0, 0, 0}, 
                        {0, 0, 0, 9, 0, 10, 0, 0, 0}, 
                        {0, 0, 4, 0, 10, 0, 2, 0, 0}, 
                        {0, 0, 0, 14, 0, 2, 0, 1, 6}, 
                        {8, 11, 0, 0, 0, 0, 1, 0, 7}, 
                        {0, 0, 2, 0, 0, 0, 6, 7, 0} 
                    }; 
    printf("\nEnter the system no. that send the request: ");
    scanf("%d",&src);
    dijkstra(graph, src); 
    return 0;
} 