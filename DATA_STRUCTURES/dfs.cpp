#include <iostream>
using namespace std;
struct node
{
    int vertex;
    node *link;
};
typedef node * nodeptr;
nodeptr g[20];
int visited[20];
int n;
void insert(int vi,int vj)
{
    nodeptr temp,trav;
    temp=(nodeptr)malloc(sizeof(*temp));
    temp->vertex=vj;
    temp->link=nullptr;
    if(!g[vi])
    {
        g[vi]=temp;
    }
    else
    {
        for(trav=g[vi];trav->link;trav=trav->link);
        trav->link=temp;
    }
}
void creategraph()
{
    int i,vi,vj,n;
    cout<<"\n Enter number of vertices: ";
    cin>>n;
    for(i=0;i<n;i++)
    {
        g[i]=nullptr;
    }
    cout<<"\n ENter Number of edges: ";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"\n ENter an edge(a,b): ";
        cin>>vi>>vj;
        insert(vi,vj);
    }
}
void dfs(int v)
{
    nodeptr t;
    cout<<v<<"\t";
    visited[v]=true;
    for(t=g[v];t;t=t->link)
    {
        if(!visited[t->vertex])
        {
            dfs(t->vertex);
        }
    }
}
int main()
{
    int i;
    for(i=0;i<20;i++)
    {
        visited[i]=0;
    }
    creategraph();
    cout<<"Nodes visited in dfs order are: ";
    dfs(0);
    cout<<endl;
}