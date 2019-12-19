#include <iostream>
using namespace std;
int heap[10];
int n=0;
void insert(int v)
{
    int p,c,t;
    if(n+1==10)
    {
        cout<<"\nHeap full!";
        exit(1);
    }
    else
    {
        heap[++n]=v;
        c=n;
        p=n/2;
        while(p>0&&(heap[c]>heap[p]))
        {
            t=heap[c];
            heap[c]=heap[p];
            heap[p]=t;
            c=p;
            p=p/2;
        }
    }
}
int remove()
{
    int r,p,c;
    if(n==0)
    {
        cout<<"\nHeap Underflow!!";
        exit(1);
    }
    else
    {
        int e=heap[n];
        n--;
        r=heap[1];
        c=2;
        p=1;
        while(c<=n)
        {
            if((heap[c+1]>heap[c]))
            {
                c++;
            }
            if (e>=heap[c])
            {
                break;
            }
            heap[p]=heap[c];
            p=c;
            c=c*2;
        }
        heap[p]=e;
        return r;
    }
    
}
void display()
{
    cout<<"\n the heap is: ";
    for(int i=1;i<=n;i++)
    {
        cout<<heap[i]<<"\t";
    }
}
int main()
{
    int ch,r;
    do
    {
        cout<<"\n 1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter your choice: ";
        cin>>ch;
        switch (ch)
        {
        case 1:
            cout<<"\n Enter Element to be inserted: ";
            cin>>r;
            insert(r);
            break;
        case 2:
            r=remove();
            cout<<"\n Succesfully Removed "<<r;
            break;
        case 3:
            display();
            break;
        default:
            exit(0);
        }
    } while (ch!=4);
    
}