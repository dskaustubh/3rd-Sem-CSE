#include <iostream>
using namespace std;
struct element
{
    int v;
};
struct node
{
    node *link;
    element data;
};
typedef struct node *nodeptr;
nodeptr front[10];
nodeptr rear[10];
void enq(int i, int v)
{
    nodeptr temp = (nodeptr)malloc(sizeof(node));
    temp->data.v = v;
    temp->link = nullptr;
    if (!front[i])
    {
        front[i] = temp;
        rear[i] = temp;
    }
    else
    {
        rear[i]->link = temp;
        rear[i] = temp;
    }
}
int deq(int i)
{
    int r;
    nodeptr temp = front[i];
    if (!temp)
    {
        cout << "\n Q Underflow Cannot Delete ";
        exit(1);
    }
    front[i] = front[i]->link;
    r = temp->data.v;
    free(temp);
    return r;
}
void display(int i)
{
    nodeptr temp = front[i];
    cout << "The Q " << i << " is: ";
    while (temp)
    {
        cout << temp->data.v << " ";
        temp = temp->link;
    }
}
int main()
{
    int i,ch,v;
    for (i = 0; i < 10; i++)
    {
        front[i] = nullptr;
    }
    do
    {
        cout << "\n 1 To enq \n 2 to deq \n 3 to display \n 4 to exit \n Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\nEnter the Q no : ";
            cin >> i;
            cout << "\n Enter data to be Inserted: ";
            cin >> v;
            enq(i, v);
            break;
        case 2:
            cout << "\nEnter the Q no : ";
            cin >> i;
            v = deq(i);
            cout << "\n Succesfully deqed " << v;
            break;
        case 3:
            cout << "\n Enter THe Q no: ";
            cin >> i;
            display(i);
            break;
        default:
            exit(0);
        }
    } while (ch != 4);
}