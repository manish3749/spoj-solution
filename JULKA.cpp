#include<iostream>
using namespace std;
#include<string.h>
#define MAX 200
int arr1[MAX];
int arr2[MAX];
int arr3[MAX];
int arr4[MAX];
int arr5[MAX];
int flag;
int s,s1;
void ADD(int*,int*,int*,int,int);
void SUBTRACT(int*,int*,int,int);
void DIVIDE(int*,int);
int main()
{
    int t=10;
    while(t--)
    {
        char str[MAX];
        char str1[MAX];
        cin>>str;
        cin>>str1;
        s=strlen(str);
        s1=strlen(str1);
        for(int i=0;i<s;i++)
            arr1[i]=str[i]-48;

        for(int i=0;i<s1;i++)
            arr2[i]=str1[i]-48;
        int l1=s;
        int l2=s1;
        flag=0;
        if(s==s1)
        {
            for(int i=0;i<s;i++)
            {
                if(arr1[i]!=arr2[i])
                {
                    flag=1;
                    break;
                }
            }
        }
        else
            flag=1;
        ADD(arr3,arr1,arr2,l1,l2);
        cout<<endl;
    }
}

void ADD(int* arr3,int* arr1,int* arr2,int l1,int l2)
{
    int t=l1;
    l1--;
    l2--;
    int sum=0;
    int carry=0,k=-1;
    while((l1>=0)&&(l2>=0))
    {
        sum=arr1[l1]+arr2[l2]+carry;
        arr3[++k]=sum%10;
        carry=sum/10;
        l1--;
        l2--;
    }
    while(carry)
    {
        sum=arr1[l1]+carry;
        arr3[++k]=sum%10;
        carry=sum/10;
        l1--;
    }
    while(l1>=0)
        arr3[++k]=arr1[l1--];

    int arr4[MAX];
    int m=-1;
    for(int j=k;j>=0;j--)
    {
        arr4[++m]=arr3[j];
    }
    if(flag==0)
    {
        for(int i=0;i<t;i++)
            cout<<arr1[i];
        cout<<endl<<"0";
    }
    else
    {
        DIVIDE(arr4,m);
    }
}

void DIVIDE(int arr[],int l)
{
    int k=-1;
    int carry=0;
    int i=0;
    for(i=0;i<=l;i++)
    {
        arr5[++k]=arr[i]/2;
        carry=arr[i]%2;
        arr[i+1]=carry*10+arr[i+1];
    }
    if(arr5[0]==0)
    {
        for(int i=0;i<k;i++)
            arr5[i]=arr5[i+1];
        k--;
    }
    for(int i=0;i<=k;i++)
            cout<<arr5[i];
    cout<<endl;
    SUBTRACT(arr5,arr2,k+1,s1);
}

void SUBTRACT(int arr1[],int arr2[],int l1,int l2)
{
    int result[MAX];
    int k=-1;
    l1--;
    l2--;
    while(l2>=0)
    {
        if(arr1[l1]>=arr2[l2])
        {
            result[++k]=arr1[l1--]-arr2[l2--];
        }
        else
        {
            result[++k]=arr1[l1--]-arr2[l2--]+10;
            arr1[l1]-=1;
        }
    }
    while((arr1[l1]==-1)&&(l1>=0))
    {
        result[++k]=arr1[l1--]+10;
        arr1[l1]-=1;
    }
    while(l1>=0)
    {
        result[++k]=arr1[l1--];
    }

    for(int i=k;i>=0;i--)
    {
        if((result[i]==0)&&(i==k--))
            continue;
        else
            cout<<result[i];
    }
}
