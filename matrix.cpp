#include<iostream>

using namespace std;
struct edge{
    int v1,v2,eno;
};
int c=0;
int main(){
    int n,m,ch;
    cout<<"\nEnter the number of vertices: ";
    cin>>n;
    cout<<"\nEnter the number of edges: ";
    cin>>m;
    edge e[m];
    int adj_mat[n][n];
    int inc_mat[n][m];
    for(int i=0;i<m;i++){
        e[i].eno=c;
        c++;
        cout<<"\nEnter vertex pairs for edge "<<e[i].eno<<": ";
        cin>>e[i].v1>>e[i].v2;
        
    }
    cout<<"\nEnter your choice: ";
    cout<<"\n1.Adjacency Matrix \t 2.Incidence Matrix \n";
    cin>>ch;

    if(ch==1){

        for(int i = 0;i<n;i++)
            for(int j=0;j<n;j++)
                adj_mat[i][j]=0;
        for(int i=0;i<m;i++){
            adj_mat[(e[i].v1-1)][(e[i].v2-1)]=1;
            adj_mat[(e[i].v2-1)][(e[i].v1-1)]=1;

        }
        for(int i = 0;i<n;i++){
            cout<<"\n";
            for(int j=0;j<n;j++){
                cout<<adj_mat[i][j]<<" ";
            }
        }
    }

    else if(ch==2){

        for(int i = 0;i<n;i++)
            for(int j=0;j<m;j++)
                inc_mat[i][j]=0;
        
        for(int i=0;i<m;i++){
            inc_mat[(e[i].v1-1)][e[i].eno]=1;
            inc_mat[(e[i].v2-1)][e[i].eno]=1;
         }  
        for(int i = 0;i<n;i++){
            cout<<"\n";
            for(int j=0;j<m;j++){
                cout<<inc_mat[i][j]<<" ";
            }
        }      

    }

}