#include <iostream>
using namespace std;
int compare(int a, int b)
{
    return (a == b) ? 0 : (a > b) ? 1 : -1;
}
struct poly
{
    int e;
    float c;
    poly *link;
};
typedef poly *polyptr;
void attach(int c, int e, polyptr *enda)
{
    polyptr temp = (polyptr)malloc(sizeof(*temp));
    temp->c = c;
    temp->e = e;
    temp->link = (*enda)->link;
    (*enda)->link = temp;
    (*enda) = temp;
}
void display(polyptr sa)
{
    polyptr a;
    a = sa->link;
    while (a != sa)
    {
        cout << " + " << a->c << " X^ " << a->e << " ";
        a = a->link;
    }
}
polyptr padd(polyptr sa,polyptr sb,polyptr *endc)
{
    polyptr c=(polyptr)malloc(sizeof(*c));
    polyptr a=sa->link;
    polyptr b=sb->link;
    int f=1;
    *endc=c;
    c->link=c;
    c->e=-1;
    while(f)
    {
        switch(compare(a->e,b->e))
        {
            case 1:
                attach(a->c,a->e,&(*endc));
                a=a->link;
                break;
            case -1:
                attach(b->c,b->e,&(*endc));
                b=b->link;
                break;
            case 0:
                if(a==sa)
                {
                    f=0;
                    break;
                }
                attach(a->c+b->c,a->e,&(*endc));
                a=a->link;
                b=b->link;
                break;
        }
    }
    return c;
}
int main()
{
    int n, i, co, e;
    polyptr a, b, c, enda, endb, endc;
    a = (polyptr)malloc(sizeof(*a));
    b = (polyptr)malloc(sizeof(*b));
    a->e = -1;
    a->link = a;
    b->e = -1;
    b->link = b;
    enda = a;
    endb = b;
    cout << "\n ENter Number of terms of polynomial A: ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "\n Enter Coef: ";
        cin >> co;
        cout << "\n Enter Exp: ";
        cin >> e;
        attach(co, e, &enda);
    }
    cout << "\n ENter Number of terms of polynomial B: ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "\n Enter Coef: ";
        cin >> co;
        cout << "\n Enter Exp: ";
        cin >> e;
        attach(co, e, &endb);
    }
    c=padd(a,b,&endc);
    cout<<"\n Polynomial A is: ";
    display(a);
    cout<<"\n Polynomial B is: ";
    display(b);
    cout<<"\n Their Sum is: ";
    display(c);

}