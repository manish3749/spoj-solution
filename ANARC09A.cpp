#include<bits/stdc++.h>
using namespace std;
#define MAX 5000
char stackk[MAX];
char arr[MAX];
int PUSH(char);
int POP(int);
int k=-1;
int top=-1;
int ctr1=0,ctr2=0,var=0;
int main()
{
    while(1)
    {
        char str[MAX];
        cin>>str;
        int l=strlen(str);
        if(str[0]=='-')
            break;
        else if(l==0)
            cout<<++var<<endl;
        else
        {
            int l=strlen(str);
            int j=0;
            k=-1,top=-1,ctr1=0,ctr2=0;
            for(int i=0;i<l;i++)
            {
                if(str[i]=='{')
                    top=PUSH(str[i]);
                else
                {
                    if(top>-1)
                        top=POP(top);
                    else
                        arr[++k]=str[i];
                }
            }
            if(top>-1)
            {
                while(top>-1)
                {
                    ctr1++;
                    top--;
                }
                ctr1=ctr1/2+ctr1%2;
            }
            if(k>-1)
            {
                while(k>-1)
                {
                    ctr2++;
                    k--;
                }
                ctr2=ctr2/2+ctr2%2;
            }
            cout<<++var<<". "<<ctr1+ctr2<<endl;
        }
    }
}
 
int PUSH(char ch)
{
    stackk[++top]=ch;
    return top;
}
int POP(int top)
{
    top--;
    return top;
 
}
