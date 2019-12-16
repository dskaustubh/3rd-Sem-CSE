#include <iostream>
using namespace std;
struct node
{
    int v;
    node *link;
};
typedef node *nodeptr;
nodeptr g[20];
int visited[20];
nodeptr front, rear;
void enq(int v)
{
    nodeptr temp = (nodeptr)malloc(sizeof(*temp));
    nodeptr trav;
    temp->v = v;
    temp->link=nullptr;
    if (!front)
    {
        front=temp;
        rear=temp;
    }
    else
    {
        rear->link=temp;
        rear=temp;
    }
}
int deq()
{
    int r;
    if(!front)
    {
        cout<<"Q undeflow!!";
        exit(1);
    }
    else
    {
        r=front->v;
        front=front->link;
    }
    return r;
}
void insert(int vi, int vj)
{
    nodeptr t, nn;
    nn = (nodeptr)malloc(sizeof(*nn));
    nn->link = nullptr;
    nn->v = vj;
    if (!g[vi])
    {
        g[vi] = nn;
    }
    else
    {
        for (t = g[vi]; t->link; t = t->link)
            ;
        t->link = nn;
    }
}
void creategraph()
{
    int i, vi, vj, n;
    cout << "\n Enter number of vertices: ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        g[i] = nullptr;
    }
    cout << "\n ENter number of edges: ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "\nEnter an edge(a,b): ";
        cin >> vi >> vj;
        insert(vi, vj);
    }
}
void bfs(int v)
{
    nodeptr t;
    cout << v<<"\t";
    visited[v] = 1;
    enq(v);
    while(front)
    {
        v=deq();
        for(t=g[v];t;t=t->link)
        {
            if(!visited[t->v])
            {
                cout<<t->v<<"\t";
                visited[t->v]=true;
                enq(t->v);
            }
        }
    }
}
int main()
{
    front = rear = nullptr;
    int i;
    for (i = 0; i < 20; i++)
    {
        visited[i] = 0;
    }
    creategraph();
    bfs(0);
    cout<<endl;
}