#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#define MAX 500
int PUSH(char*,char,int);
int POP(char*,char,int);
int symbol(char);
int main()
{
    int t;
    cin>>t;
    t++;
    while(t--)
    {
        char exp[MAX];
        char rps[MAX];
        char str[MAX];
        gets(exp);
        int l=strlen(exp);
        int crnt=-1,k=-1;
        int no;
        int i;
        for(i=0;i<l;i++)
        {
            if(exp[i]=='(')
                crnt=PUSH(str,exp[i],crnt);
            else if(exp[i]==')')
            {
                while(str[crnt]!='(')
                {
                    rps[++k]=str[crnt];
                    crnt=POP(str,exp[i],crnt);
                }
                crnt--;
            }
            else if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/'||exp[i]=='^')
            {
                if(crnt==-1)
                        crnt=PUSH(str,exp[i],crnt);
                else
                {
                    if(symbol(exp[i])>symbol(str[crnt]))
                        crnt=PUSH(str,exp[i],crnt);
                    else
                    {
                        while(symbol(exp[i])<=symbol(str[crnt]))
                        {
                            rps[++k]=str[crnt--];
                        }
                        crnt=PUSH(str,exp[i],crnt);
                    }
                }
            }
            else
                rps[++k]=exp[i];
        }
        for(int j=0;j<=k;j++)
            cout<<rps[j];
        if(i==l)
        {
            while(crnt!=-1)
                cout<<rps[crnt--];
            cout<<endl;
        }
    }
}

int PUSH(char* str,char ch,int crnt)
{
    str[++crnt]=ch;
    return crnt;
}

int POP(char* str,char ch,int crnt)
{
    crnt--;
    return crnt;
}

int symbol(char ch)
{
    if(ch=='+')
        return 1;
    else if(ch=='-')
        return 2;
    else if(ch=='*')
        return 3;
    else if(ch=='/')
        return 4;
    else if(ch=='^')
        return 5;
    else if(ch=='(')
        return 0;
    else
        return 10;
}
