#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll arr[1000000];
ll ctr=0;
ll FIND(ll n);
int main()
{
    ll n;
    cin>>n;
    ll ch=FIND(n);
    if(ch==1)
        cout<<ctr;
    else
        cout<<"-1";
}

ll FIND(ll n)
{
    ll sum=0;
    while(n)
    {
        ll r=n%10;
        sum+=(r*r);
        n=n/10;
    }
    ctr++;
    if(sum==1)
        return 1;
    n=sum;
    while(arr[n]!=2 && sum!=1)
    {
        sum=0;
        while(n)
        {
            ll r=n%10;
            sum+=(r*r);
            n=n/10;
        }
        ctr++;
        if(sum==1)
            break;
        n=sum;
        arr[n]++;
    }
    if(sum==1)
        return 1;
    else
        return 0;
}
