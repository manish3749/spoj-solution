#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    int arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    int l=0,r=0,ans=0,sum=0;
    while(l<n)
    {
        while(r<n && sum+arr[r]<=m)
        {
            sum+=arr[r];
            r++;
        }
        ans=max(sum,ans);
        sum-=arr[l];
        l++;
    }
    cout<<ans;
}
