#include<bits/stdc++.h>
using namespace std;
#define MAX 1000005
int arr[MAX];
int main()
{
    int k,l,m;
    cin>>k>>l>>m;
    int arr1[m];
    for(int i=0;i<m;i++)
        cin>>arr1[i];
    arr[0]=0;
    for(int i=1;i<MAX;i++)
    {
        if(i-1>=0 && arr[i-1]==0)
            arr[i]=1;
        if(i-k>=0 && arr[i-k]==0)
            arr[i]=1;
        if(i-l>=0 && arr[i-l]==0)
            arr[i]=1;
    }
    for(int i=0;i<m;i++)
    {
        if(arr[arr1[i]]==1)
            cout<<"A";
        else
            cout<<"B";
    }
}
