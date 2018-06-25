#include<iostream>
using namespace std;
int MULTIPLY(int*,int,int);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int arr[200];
        arr[0]=1;
        int n,k=0;
        cin>>n;
        for(int i=2;i<=n;i++)
            k=MULTIPLY(arr,i,k);

        for(int j=k;j>=0;j--)
            cout<<arr[j];

        cout<<endl;
    }
}

int MULTIPLY(int *arr,int n,int k)
{
    int carry=0;
    for(int i=0;i<=k;i++)
    {
        int prod=arr[i]*n+carry;
        arr[i]=prod%10;
        carry=prod/10;
    }
    while(carry)
    {
        arr[++k]=carry%10;
        carry = carry/10;
    }
    return k;
}
