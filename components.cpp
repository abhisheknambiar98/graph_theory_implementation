
#include<iostream> 
#include <list> 
using namespace std; 
  

class Graph 
{ 
    int V,c;    
  
    list<int> *adj; 
  

    void DFSUtil(int v, bool visited[]); 
public: 
    Graph(int V);  
    void addEdge(int v, int w); 
    void connectedComponents();
    void noofcomponents(); 
}; 
  

void Graph::connectedComponents() 
{ 
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    for(int v = 0; v < V; v++) 
        visited[v] = false; 
  
    for (int v=0; v<V; v++) 
    { 
        if (visited[v] == false) 
        { 

            c++;
            DFSUtil(v, visited); 
  
            cout << "\n"; 
        } 
    } 
} 
  
void Graph::DFSUtil(int v, bool visited[]) 
{ 
    // Mark the current node as visited and print it 
    visited[v] = true; 
    cout << v << " "; 
  
    // Recur for all the vertices 
    // adjacent to this vertex 
    list<int>::iterator i; 
    for(i = adj[v].begin(); i != adj[v].end(); ++i) 
        if(!visited[*i]) 
            DFSUtil(*i, visited); 
} 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
    c=0;
} 
  
// method to add an undirected edge 
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); 
    adj[w].push_back(v); 
} 

void Graph::noofcomponents(){
    cout<<"\nNumber of Components: "<<c<<"\n";
}
  
// Drive program to test above 
int main() 
{   
    int e,n,v1,v2;
    cout<<"\nEnter the number of vertices: ";
    cin>>n;
    cout<<"\nEnter the number of edges: ";
    cin>>e;
    Graph g(n);
    for(int i=0;i<e;i++){
        cout<<"\nEnter edge "<<i<<":";
        cin>>v1>>v2;
        g.addEdge(v1,v2);
    }
  
    cout << "\nFollowing are connected components \n"; 
    g.connectedComponents(); 
    g.noofcomponents();
    return 0; 
} 