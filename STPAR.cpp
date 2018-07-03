#include<bits/stdc++.h>
using namespace std;
#define MAX 10000
int arr[MAX];
int arr_sort[MAX];
int stackk[MAX];
int arr2[MAX];
int k;
int top;
void PUSH(int);
int POP(int);
int main()
{
    while(1)
    {
        k=0,top=-1;
        int n;
        cin>>n;
        if(n==0)
            break;
        else
        {
            for(int i=0;i<n;i++)
                cin>>arr[i];

            for(int i=0;i<n;i++)
                arr_sort[i]=arr[i];

            sort(arr,(arr+n));

            for(int i=0;i<n;i++)
            {
                if(arr_sort[i]==arr[k])
                {
                    arr2[k++]=arr_sort[i];
                }
                else if((top>-1)&&(arr[k]==stackk[top]))
                {
                    while((top>-1)&&(arr[k]==stackk[top]))
                         top=POP(top);

                    PUSH(arr_sort[i]);
                }
                else
                    PUSH(arr_sort[i]);
            }
            while(top!=-1)
            {
                top=POP(top);
            }
            int flag=1;
            for(int i=0;i<n;i++)
            {
                if(arr[i]!=arr2[i])
                {
                    flag=0;
                    break;
                }
            }
            if(flag)
                cout<<"yes"<<endl;
            else
                cout<<"no"<<endl;
        }
    }
}

void PUSH(int x)
{
    stackk[++top]=x;
}
int POP(int top)
{
    arr2[k++]=stackk[top];
    top--;
    return top;
}
