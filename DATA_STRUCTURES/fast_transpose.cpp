#include <iostream>
using namespace std;
struct sparse
{
    int r;
    int c;
    int v;
};
sparse a[100];
sparse b[100];
void output(sparse c[])
{
    int i;
    for(i=0;i<=c[0].v;i++)
    {
        cout<<endl<<c[i].r<<"\t"<<c[i].c<<"\t"<<c[i].v;
    }
}
void transpose()
{
    int rowterms[100];
    int startingpos[100];
    int i,j;
    b[0].v=a[0].v;
    b[0].c=a[0].r;
    b[0].r=a[0].c;
    for(i=0;i<a[0].c;i++)
    {
        rowterms[i]=0;
    }
    for(i=1;i<=a[0].v;i++)
    {
        rowterms[a[i].c]++;
    }
    startingpos[0]=1;
    for(i=1;i<a[0].c;i++)
    {
        startingpos[i]=startingpos[i-1]+rowterms[i-1];
    }
    for(i=1;i<=a[0].v;i++)
    {
        j=startingpos[a[i].c]++;
        b[j].r=a[i].c;
        b[j].c=a[i].r;
        b[j].v=a[i].v;
    }
}
int main()
{
    int n, r, c,i;
    cout << "\n Enter The Number of Rows Of A: ";
    cin >> r;
    cout << "\n Enter The Number of Columns Of A: ";
    cin >> c;
    cout << "\n Enter The Number of Non Zero Terms Of A: ";
    cin>>n;
    a[0].c=c;
    a[0].r=r;
    a[0].v=n;
    for(i=1;i<=n;i++)
    {
        cout<<"\nEnter Row: ";
        cin>>a[i].r;
        cout<<"\nEnter Column: ";
        cin>>a[i].c;
        cout<<"\n Enter THe Value: ";
        cin>>a[i].v;
    }
    cout<<"\n The Matrix is: "<<endl;
    output(a);
    transpose();
    cout<<"\nThe Transpose is: "<<endl;
    output(b);

}