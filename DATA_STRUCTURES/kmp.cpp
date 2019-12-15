#include <iostream>
#include <cstring>
using namespace std;
int fail[100];
void failure(char p[])
{
    fail[0]=-1;
    int i,j;
    for(j=1;j<strlen(p);j++)
    {
        i=fail[j-1];
        while((p[i+1]!=p[j])&&(i>=0))
        {
            i=fail[i];
        }
        if(p[i+1]==p[j])
        {
            fail[j]=i+1;
            i++;
        }
        else
        {
            fail[j]=-1;
        }
        
    }
}
int main()
{
    char *p;
    int i;
    char *s;
    cout<<"\n Enter the pattern: ";
    cin>>p;
    //cout<<"Enter the String: ";
    //cin>>s;
    cout<<"\nThe pattern is: "<<p<<"\n";
    failure(p);
    for(i=0;i<strlen(p);i++)
    {
        cout<<fail[i]<<"\t";
    }
    
}