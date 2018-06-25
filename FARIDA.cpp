#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll MAX(ll arr[],ll n);
int main()
{
    int t;
    cin>>t;
    int  k=1;
    while(t--)
    {
        ll n;
        cin>>n;
        if(n==0)
            cout<<"Case "<<k++<<": "<<"0"<<endl;
        else
        {
            ll arr[n+1];
            for(int i=0;i<n;i++)
                cin>>arr[i];
            ll sum=MAX(arr,n);
            cout<<"Case "<<k++<<": "<<sum<<endl;
        }
    }
}

ll MAX(ll arr[],ll n)
{
    ll inc=arr[0];
    ll exc=0;

    for(int i=1;i<n;i++)
    {
        ll new_exc=max(inc,exc);
        inc=(exc+arr[i]);
        exc=new_exc;
    }
    return max(exc,inc);
}
