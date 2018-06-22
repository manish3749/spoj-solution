#include<iostream>
using namespace std;
#include<string>
#define MAX 1000
void MULTIPLY(int arr1[],int l);
int main()
{
    int t=1024;
    while(t--)
    {
        string str;
        cin>>str;
        int l=str.length();
        int arr[l];
 
        for(int i=0;i<l;i++)
            arr[i]=str[i]-48;
 
        if((l==1)&&(arr[0]==0))
            cout<<"0"<<endl;
        else if((l==1)&&(arr[0]==1))
            cout<<"1"<<endl;
        else
        {
            if(arr[l-1]==0)
            {
                int flag=0;
                for(int i=1;i<l;i++)
                {
                    if((arr[0]==1)&&(arr[i]==0))
                        flag=1;
                    else
                    {
                        flag=0;
                        break;
                    }
                }
                if(flag==1)
                {
                    arr[0]=0;
                    for(int i=1;i<l;i++)
                        arr[i]=9;
                }
                else
                {
                    int endd=l-1;
                    while(arr[endd]==0)
                    {
                        arr[endd--]=9;
                    }
                    arr[endd--]-=1;
                }
            }
            else
                arr[l-1]-=1;
            int j=0;
            while(arr[j]==0)
                j++;
            int m=0;
            int arr1[l];
            for(int i=j;i<l;i++)
                arr1[m++]=arr[i];
 
            MULTIPLY(arr1,m);
        }
    }
}
 
void MULTIPLY(int arr1[],int l)
{
    int k=0;
    int carry=0;
    int ansr[MAX];
    int prod=1;
 
    for(int i=l-1;i>=0;i--)
    {
        prod=arr1[i]*2+carry;
        ansr[k++]=prod%10;
        carry=prod/10;
    }
    while(carry)
    {
        ansr[k++]=carry%10;
        carry=carry/10;
    }
    for(int i=k-1;i>=0;i--)
    {
        cout<<ansr[i];
    }
    cout<<endl;
}
