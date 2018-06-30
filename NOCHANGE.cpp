#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int v[k];
    for(int i=0;i<k;i++)
    {
        cin>>v[i];
        if(i>0)
            v[i]+=v[i-1];
    }
    bool coin[n+1];
    for(int i=0;i<=n;i++)
        coin[i]=false;
    coin[0]=true;
    for(int i=0;i<k;i++)
    {
        for(int j=v[i];j<=n;j++)
        {
            coin[j]|=coin[j-v[i]];
        }
    }
    if(coin[n])
        cout<<"YES";
    else
        cout<<"NO";
}
