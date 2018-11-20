#include<iostream>
using namespace std;
struct node{
    int val;
    node *next;
};
struct list{
    int v;
    int flag;
    node *h;
};
int main(){
    int n,m,v1,v2;
    cout<<"\nEnter the number of vertices: ";
    cin>>n;
    cout<<"\nEnter the number of edges: ";
    cin>>m;
    list l[n];
    for(int i=0;i<n;i++){
        l[i].h=NULL;
        l[i].flag=0;
        l[i].v=i+1;
    }

    for(int i=0;i<m;i++){
        cout<<"\nEnter vertex pairs for edge "<<i<<": ";
        cin>>v1>>v2;
        // l[v1-1].v=v1;
        node *t=new node;
        node *t1=new node;
        t->val=v2;
        t->next=NULL;
        if(l[v1-1].flag==0)
        // {   cout<<"\nFirst time";
            l[v1-1].flag=1;
            l[v1-1].h=t;
        }
        else{
            // cout<<"\nRemaining";
            t->next=l[v1-1].h;
            l[v1-1].h=t;
        }

        t1->val=v1;
        t1->next=NULL;
        if(l[v2-1].flag==0)
        {   
            l[v2-1].flag=1;
            l[v2-1].h=t1;
        }
        else{
            t1->next=l[v2-1].h;
            l[v2-1].h=t1;
        }
    
    }
    for(int i = 0;i<n;i++){
        node *temp=l[i].h;
        cout<<"\nVertex"<<l[i].v;
        while(temp!=NULL){
            cout<<"->"<<temp->val;
            temp=temp->next;

        }
    }
    cout<<"\n";
}