#include <iostream>
using namespace std;
typedef enum
{
    lparen,
    rparen,
    sum,
    minu,
    times,
    divi,
    mod,
    eos,
    operand
} precedence;
char expr[100];
precedence stack[100];
int top = -1;
int icp[] = {20, 19, 12, 12, 13, 13, 13, 0};
int isp[] = {0, 19, 12, 12, 13, 13, 13, 0};
precedence gettoken(char *sym, int *n)
{
    *sym = expr[*n];
    *n = *n + 1;
    switch (*sym)
    {
    case '+':
        return sum;
    case '-':
        return minu;
    case '*':
        return times;
    case '/':
        return divi;
    case '%':
        return mod;
    case '\0':
        return eos;
    case '(':
        return lparen;
    case ')':
        return rparen;
    default:
        return operand;
    }
}
void push(precedence val)
{
    if ((top + 1) == 100)
    {
        cout << "\n Stack Overflow!!  ";
    }
    else
    {
        stack[++top] = val;
    }
}
precedence pop()
{
    if (top == -1)
    {
        cout << "\n Stack Underflow!! ";
        exit(1);
    }
    else
    {
        return stack[top--];
    }
}
void printtoken(precedence token)
{
    switch (token)
    {
    case sum:
        cout << '+';
        return;
    case minu:
        cout << '-';
        return;
    case times:
        cout << '*';
        return;
    case divi:
        cout << '/';
        return;
    case mod:
        cout << '%';
        return;
    default:
        return;
    }
}
void infix2postfix()
{
    precedence token;
    char sym;
    int n = 0;
    push(eos);
    for (token = gettoken(&sym, &n); token != eos; token = gettoken(&sym, &n))
    {
        if (token == operand)
        {
            cout << sym;
        }
        else if (token == rparen)
        {
            while(token!=lparen)
            {
                printtoken(pop());
            }
            pop();
        }
        else
        {
            while(isp[stack[top]]>=icp[token])
            {
                printtoken(pop());
            }
            push(token);
        }
    }
    for (token = pop(); token != eos; token =pop())
    {
        printtoken(token);
    }
    
}
int main()
{
    cout << "\n Enter The infix Expression: ";
    cin >> expr;
    cout << "\n The Postfix Expression is :  ";
    infix2postfix();
}