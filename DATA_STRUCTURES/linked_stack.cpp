#include <iostream>
using namespace std;
struct node
{
    node *link;
    int data;
};
typedef struct node *nodeptr;
nodeptr top[10];
void push(int i, int v)
{
    nodeptr temp = (nodeptr)malloc(sizeof(node));
    temp->data = v;
    if (!top[i])
    {
        temp->link = nullptr;
        top[i] = temp;
    }
    else
    {
        temp->link = top[i];
        top[i] = temp;
    }
    cout << "\n Succesfully pushed: " << v << endl;
}
void display(int i)
{
    nodeptr temp = top[i];
    cout << "The stack " << i << " is: ";
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->link;
    }
}
int pop(int i)
{
    int r; 
    nodeptr temp=top[i];
    if(!top[i])
    {
        cout<<"\n Stack Empty Cannot POP ";
        exit(0);
    }
    r=temp->data;
    top[i]=top[i]->link;
    free(temp);
    return r;
}
int main()
{
    int i,ch,v;
    for (i = 0; i < 10; i++)
    {
        top[i] = nullptr;
    }
    do
    {
        cout<<"\n 1 To push \n 2 to pop \n 3 to display \n 4 to exit \n Enter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                    cout<<"\nEnter the Stack no : ";
                    cin>>i;
                    cout<<"\n Enter data to be Inserted: ";
                    cin>>v;
                    push(i,v);
                    break;
            case 2:
                    cout<<"\nEnter the Stack no : ";
                    cin>>i;
                    v=pop(i);
                    cout<<"\n Succesfully popped "<<v;
                    break;
            case 3:
                    cout<<"\n Enter THe Stack no: ";
                    cin>>i;
                    display(i);
                    break;
            default:exit(0);
        }
    } while (ch!=4);
    
}