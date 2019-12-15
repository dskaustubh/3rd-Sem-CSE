#include <iostream>
using namespace std;
struct node
{
    node *lc;
    node *rc;
    int v;
};
typedef node *treeptr;
void insert(treeptr *head, int v)
{
    if (*head)
    {
        if(v>(*head)->v)
        {
            insert(&(*head)->rc,v);
        }
        else
        {
            insert(&(*head)->lc,v);
        }
        
    }
    else
    {
        treeptr temp = (treeptr)malloc(sizeof(*temp));
        temp ->v=v;
        temp->lc=nullptr;
        temp->rc=nullptr;
        *head=temp;
    }
}
void inorder(treeptr head)
{
    if(!head)
    {
        return;
    }
    inorder(head->lc);
    cout<<head->v<<"\t";
    inorder(head->rc);
}
int search(treeptr root,int k)
{
    if(!root)
    {
        return 0;
    }
    if(k==root->v)
    {
        return 1;
    }
    else if(k>(root->v))
    {
        return(search(root->rc,k));
    }
    else
    {
        return(search(root->lc,k));
    }
    
}
int main()
{
    treeptr root=nullptr;
    int ch=1,t,r;
    do
    {
        cout<<"\n1.insert\n 2.display\n3.search\n4.exit\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:cout<<"\n Enter The element to be inserted: ";
                    cin>>t;
                    insert(&root,t);
                    cout<<"\n Insertion Succesfull";
                    break;
            case 2:cout<<"\n THe tree is: ";
                    inorder(root);
                    break;
            case 3:cout<<"\n EnTer the item to key for: ";
                    cin>>t;
                    r=search(root,t);
                    if(r)
                    {
                        cout<<"\n"<<t<<" Found in the tree!";
                    }
                    else
                    {
                        cout<<"\n "<<t<<" not found in the tree";
                    }
                    
                    break;
            default:exit(0);
        }
    } while (ch!=4);
    

}