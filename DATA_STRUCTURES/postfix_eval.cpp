#include<iostream>
using namespace std;
typedef enum{lparen,rparen,sum,minu,times,divi,mod,eos,operand}precedence;
char expr[100];
int top=-1;
int stack[50];
precedence gettoken(char *sym,int *n)
{
    *sym=expr[*n];
    *n=*n+1;
    switch(*sym)
    {
        case '+':return sum;
        case '-':return minu;
        case '*':return times;
        case '/':return divi;
        case '%':return mod;
        case '\0':return eos;
        case '(':return lparen;
        case ')':return rparen;
        default:return operand;
    }
}

void push(int val)
{
    if((top+1)==100)
    {
        cout<<"\n Stack Overflow!!  ";
    }
    else
    {
        stack[++top]=val;
    }
}
int pop()
{
    if(top==-1)
    {
        cout<<"\n Stack Underflow!! ";
        exit(1);
    }
    else 
    {
        return stack[top--];
    }
}
int eval()
{
    char sym;
    int n=0,op1,op2;
    precedence token;
    for(token=gettoken(&sym,&n);token!=eos;token=gettoken(&sym,&n))
    {
        if(token==operand)
        {
            push(sym-'0');
        }
        else
        {
            op2=pop();
            op1=pop();
            switch(token)
            {
                case sum:
                        push(op1+op2);
                        break;
                case minu:
                        push(op1-op2);
                        break;
                case times:
                        push(op1*op2);
                        break;
                case divi:
                        push(op1/op2);
                        break;
                case mod:
                        push(op1%op2);
                        break;
                default:
                        break;
            }
        }
        

    }
    return pop();
}
int main()
{
    int e;
    cout<<"\n Enter The Postfix Expression: ";
    cin>>expr;
    e=eval();
    cout<<"\n The Postfix Expression Evaluates to: "<<e<<endl;
}