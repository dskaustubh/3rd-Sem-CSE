#include <iostream>
#include <cstring>
using namespace std;
struct Queue
{
    int key;
};
int capacity = 4;
Queue *q;
int front, rear;
void qfull()
{
    Queue *nq;
    //nq=(Queue*)malloc(sizeof(*nq)*2*capacity);
    if (front < rear)
    {
        //no wrap around
        q = (Queue *)realloc(q, sizeof(*q) * 2 * capacity);
    }
    else
    {
        nq = (Queue *)malloc(sizeof(*nq) * 2 * capacity);
        int i, j = 1;
        for (i = (front + 1) % capacity; 1; i = (i + 1) % capacity, j++)
        {
            nq[j].key = q[i].key;
            if (i == rear)
            {
                break;
            }
        }
        free(q);
        q = nq;
        front = 0;
        rear = j;
    }
    capacity = capacity * 2;
}
void enq(int v)
{
    if (front == ((rear + 1) % capacity))
    {
        qfull();
    }
    rear = (rear + 1) % capacity;
    q[rear].key = v;
}
int deq()
{
    int r;
    if (front == rear)
    {
        cout << "\n CQ Undeflow!!";
        exit(0);
    }
    r = q[(front + 1) % capacity].key;
    front = (front + 1) % capacity;
    return r;
}
void display()
{
    cout << "\n CQ is: ";
    int i = (front + 1) % capacity;
    while (1)
    {
        cout << q[i].key << "\t";
        if (i == rear)
        {
            break;
        }
        i = (i + 1) % capacity;
    }
}
int main()
{
    int ch = 1,v;
    front = rear = 0;
    q = (Queue *)malloc(sizeof(*q) * 4);
    do
    {
        cout << "\n 1 To enq \n 2 to deq \n 3 to display \n 4 to exit \n Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
            case 1:
                cout<<"\n enter element to enq: ";
                cin>>v;
                enq(v);
                break;
            case 2:
                v=deq();
                cout<<"\n Dequed: "<<v;
                break;
            case 3:
                display();
                break;
            default:exit(0);
        }
    } while (ch != 4);
}