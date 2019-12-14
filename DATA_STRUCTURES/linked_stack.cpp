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
int main()
{
    int i;
    for (i = 0; i < 10; i++)
    {
        top[i] = nullptr;
    }
    push(1, 1);
    display(1);
    push(1, 2);
    display(1);
    push(1, 3);
    display(1);
}