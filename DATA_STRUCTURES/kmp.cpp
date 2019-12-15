#include <iostream>
#include <cstring>
using namespace std;
int fail[100];
void failure(char p[])
{
    fail[0] = -1;
    int i, j;
    for (j = 1; j < strlen(p); j++)
    {
        i = fail[j - 1];
        while ((p[i + 1] != p[j]) && (i >= 0))
        {
            i = fail[i];
        }
        if (p[i + 1] == p[j])
        {
            fail[j] = i + 1;
            i++;
        }
        else
        {
            fail[j] = -1;
        }
    }
}
void pmatch(char s[], char p[])
{
    int i = 0, j = 0, lens, lenp;
    lens = strlen(s);
    lenp = strlen(p);
    while ((i < lens) && (j < lenp))
    {
        if (s[i] == p[j])
        {
            i++;
            j++;
        }
        else if (j == 0)
        {
            i++;
        }
        else
        {
            j = fail[j - 1] + 1;
        }
    }
    if (j == lenp)
    {
        cout << "\n Pattern Found in String";
    }
    else
    {
        cout << "\n Pattern not found in String";
    }
}
int main()
{
    char p[100],s[100];
    int i;
    cout << "\n Enter the pattern: ";
    cin >> p;
    failure(p);
    cout << "\n The Failure array is: ";
    for (i = 0; i < strlen(p); i++)
    {
        cout << fail[i] << "\t";
    }
    cout<<"\nEnter the String: ";
    cin>>s;
    pmatch(s,p);
}