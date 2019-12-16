#include <iostream>
using namespace std;
struct node
{
    node *llink;
    node *rlink;
    int v;
};
typedef node * nodeptr;
void insert(int v,nodeptr *head)
{
    nodeptr temp=(nodeptr)malloc(sizeof(*temp));
    temp->v=v;
    temp->rlink=(*head)->rlink;
    (*head)->rlink=temp;
    temp->llink=*(head);
    temp->rlink->llink=temp;
}
void displayf(nodeptr head)
{
    nodeptr trav=head->llink;
    while(trav!=head)
    {
        cout<<trav->v<<"\t";
        trav=trav->llink;
    }
}
void displayr(nodeptr head)
{
    nodeptr trav=head->rlink;
    while(trav!=head)
    {
        cout<<trav->v<<"\t";
        trav=trav->rlink;
    }
}
void delet(int v,nodeptr *head)
{
    nodeptr trav=(*head)->rlink;
    if(trav==*head)
    {
        cout<<"\n Empty List!! Cannot delete";
        return ;
    }
    else
    {
        for(;trav!=*head;trav=trav->rlink)
        {
            if(trav->v==v)
            {
                trav->llink->rlink=trav->rlink;
                trav->rlink->llink=trav->llink;
                free(trav);
                cout<<"\n Successfully deleted "<<v;
                return;
            }
        }
    }
    cout<<"\n Element not found!!";
}
int main()
{
    int ch,r;
    nodeptr head;
    head=(nodeptr)malloc(sizeof(*head));
    head->v=-1;
    head->llink=head;
    head->rlink=head;
    do
    {
        cout<<"\n1.Insert\n2.Delete\n3.Display Forawrd\n4.Display Backward\nEnter Your Choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"\n Enter element to be inserted: ";
                cin>>r;
                insert(r,&head);
                cout<<"\n Successfully Inserted "<<r;
                break;
            case 2:
                cout<<"\n enter element to be deleted: ";
                cin>>r;
                delet(r,&head);
                break;
            case 3:
                cout<<"\n The list in forward direction is: ";
                displayf(head);
                break;
            case 4:
                cout<<"\n The list in Backward direction is: ";
                displayr(head);
                break;
            default:exit(0);
        }
    } while (ch!=5);
    
}