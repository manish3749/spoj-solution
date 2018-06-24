#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 10000
#define mod 1000000007
ll FACTORS();
ll PRIME(ll n);
ll arr[MAX];
ll c=-1;
int main()
{
    FACTORS();
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll arr1[MAX];
        ll i=0,j=0;
        while(arr[i]<=n)
        {
            arr1[j++]=arr[i++];
        }
        ll arr2[MAX];
        ll k=0;

        for(ll i=0;i<j;i++)
        {
            ll var1=0;
            ll p=arr1[i];
            while(n/p>0)
            {
                var1+=n/p;
                p*=arr1[i];
            }
            arr2[k++]=var1+1;
        }
        int ansr=0;
        ll ctr=1;
        for(ll i=0;i<k;i++)
        {
            ctr=(ctr*arr2[i])%mod;
        }
        cout<<ctr<<endl;
    }
}
ll FACTORS()
{
    for(ll i=2;i<=100000;i++)
    {
        if(PRIME(i))
            arr[++c]=i;
    }
}
ll PRIME(ll n)
{
    ll flag=1;
    for(ll i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            flag=0;
            break;
        }
    }
    if(flag)return 1;
    else return 0;
}
