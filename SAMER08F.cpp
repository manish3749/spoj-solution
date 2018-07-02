#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll arr[101];
int main()
{
    arr[0]=0;
    arr[1]=1;
    for(int i=2;i<101;i++)
        arr[i]=i*i+arr[i-1];
    while(1)
    {
        int n;
        cin>>n;
        if(n==0)
            break;
        else
            cout<<arr[n]<<endl;
    }
}
