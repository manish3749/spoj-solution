#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#define MAX 100000
void REVERSE(int*,int);
void SUMM(int*,int*,int*,int,int);
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        char str1[MAX];
        char str2[MAX];
        cin>>str1>>str2;
        int l1=strlen(str1);
        int l2=strlen(str2);
        int arr1[MAX];
        int arr2[MAX];
        for(int i=0;i<l1;i++)
            arr1[i]=str1[i]-48;
        for(int i=0;i<l2;i++)
            arr2[i]=str2[i]-48;
 
        if(arr1[l1-1]==0)
        {
            while(arr1[l1-1]==0)
                l1--;
        }
        if(arr2[l2-1]==0)
        {
            while(arr2[l2-1]==0)
                l2--;
        }
        REVERSE(arr1,l1);
        REVERSE(arr2,l2);
        int arr3[MAX];
        SUMM(arr3,arr1,arr2,l1,l2);
        cout<<endl;
    }
}
 
void REVERSE(int *arr,int l)
{
    for(int i=0;i<l/2;i++)
    {
        int t=arr[i];
        arr[i]=arr[l-1-i];
        arr[l-1-i]=t;
    }
}
 
void SUMM(int* arr3,int* arr1,int* arr2,int l1,int l2)
{
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
    while(l1>=0)
    {
        sum=arr1[l1]+carry;
        arr3[++k]=sum%10;
        carry=sum/10;
        l1--;
    }
    while(l2>=0)
    {
        sum=arr2[l2]+carry;
        arr3[++k]=sum%10;
        carry=sum/10;
        l2--;
    }
    while(carry)
    {
        arr3[++k]=carry%10;
        carry=carry/10;
    }
    int i=0;
    if(arr3[i]==0)
    {
        while(arr3[i]==0)
            i++;
    }
    for(int j=i;j<=k;j++)
    {
        cout<<arr3[j];
    }
}
 
