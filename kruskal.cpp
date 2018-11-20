#include<iostream>
#include<algorithm>
using namespace std;
struct edge{
    int v1,v2,w;
};
void sort(edge e[],int m){
    int s,pos;
    edge temp;
    for(int i=0;i<m-1;i++){
        s=e[i].w;
        for(int j=i+1;j<m;j++){
            if(e[j].w<s)
            {   
                s=e[j].w;
                pos=j;
            }
        }
        temp=e[i];
        e[i]=e[pos];
        e[pos]=temp;
    }
}
void balance(int a[],int x,int y,int n){
    for(int i=0;i<n;i++){
        if(a[i]==x)
            a[i]=a[y];
    }
}
int main(){
    int n,m;
    cout<<"\nEnter the number of vertices: ";
    cin>>n;
    cout<<"\nEnter the number of edges: ";
    cin>>m;
    edge e[m];
    edge spantree[m-1];
    for(int i=0;i<m;i++){
        cout<<"\nEnter vertex pairs and weight for edge "<<i<<": ";
        cin>>e[i].v1>>e[i].v2>>e[i].w;
        
    }
    cout<<"\nBefore sort";
    for(int i=0;i<m;i++){
        cout<<"\n("<<e[i].v1<<","<<e[i].v2<<","<<e[i].w<<")";
    }   
    sort(e,m);
    cout<<"\nAfter sort";
    for(int i=0;i<m;i++){
        cout<<"\n("<<e[i].v1<<","<<e[i].v2<<","<<e[i].w<<")";
    }    
    int r,vlist[n];
    for(int i=0;i<n;i++)
        vlist[i]=i;
    int k=0,p=0;
    for(int i=0;i<m;i++){
        cout<<"\n";
        if(p==n-1)
            break;
        if(i==0){
            // cout<<"\ni=0";
            spantree[p++]=e[i];
            if(e[i].v1<e[i].v2)
                vlist[e[i].v2]=e[i].v1;
            else
                vlist[e[i].v1]=e[i].v2;
        // for(int j=0;j<n;j++)
        //     cout<<"\t"<<vlist[j];
        }
        else{
            if(vlist[e[i].v1]!=vlist[e[i].v2]){
                spantree[p++]=e[i];
                if(e[i].v1<e[i].v2)
                    {
                        vlist[e[i].v2]=e[i].v1;
                        balance(vlist,e[i].v2,e[i].v1,n);
                    }

                else
                    {
                        vlist[e[i].v1]=e[i].v2;
                        balance(vlist,e[i].v1,e[i].v2,n);

                    }
                // for(int j=0;j<n;j++)
                //     cout<<"\t"<<vlist[j];                
            }
        }
    }
    cout<<"\nShortest spanning tree:\n";
    for(int i=0;i<p;i++){
         cout<<"\n("<<spantree[i].v1<<","<<spantree[i].v2<<","<<spantree[i].w<<")";
    }


}