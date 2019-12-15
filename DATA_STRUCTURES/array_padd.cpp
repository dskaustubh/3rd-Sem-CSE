#include <iostream>
using namespace std;
int compare(int a, int b)
{
    return (a == b) ? 0 : (a > b) ? 1 : -1;
}
struct term
{
    int e;
    float c;
} terms[100];
int avail = 0;
void attach(float c, int e)
{
    terms[avail].c = c;
    terms[avail++].e=e;
}
void padd(int sa, int sb, int ea, int eb)
{
    while ((sa <= ea) && (sb <= eb))
    {
        switch (compare(terms[sa].e, terms[sb].e))
        {
        case 1:
            attach(terms[sa].c, terms[sa].e);
            sa++;
            break;
        case -1:
            attach(terms[sb].c, terms[sb].e);
            sb++;
            break;
        case 0:
            attach(terms[sb].c + terms[sa].c, terms[sb].e);
            sa++;
            sb++;
            break;
        }
    }
    for (; sa <= ea; sa++)
    {
        attach(terms[sa].c, terms[sa].e);
    }
    for (; sb <= eb; sb++)
    {
        attach(terms[sb].c, terms[sb].e);
    }
}
void output(int sd,int ed)
{
    for(;sd<=ed;sd++)
    {
        cout<<"+ "<<terms[sd].c<<" X^ "<<terms[sd].e<<"  ";
    }
}
int main()
{
    int sa, sb, ea, eb, sc, ec, i, n, e;
    float c;
    sa = 0;
    cout << "\n Enter Number of Terms of Polynomial A: ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "\n Enter Exp: ";
        cin >> e;
        cout << "\n Enter Coef: ";
        cin >> c;
        attach(c, e);
    }
    ea = avail - 1;
    sb = avail;
    cout << "\n Enter Number of Terms of Polynomial B: ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "\n Enter Exp: ";
        cin >> e;
        cout << "\n Enter Coef: ";
        cin >> c;
        attach(c, e);
    }
    eb = avail - 1;
    sc = avail;
    padd(sa,sb,ea,eb);
    ec = avail - 1;
    cout << "\n Polynomial A is: ";
    output(sa, ea);
    cout << "\n Polynomial B is: ";
    output(sb, eb);
    cout << "\n Their Sum is: ";
    output(sc, ec);
}