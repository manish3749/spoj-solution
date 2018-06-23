#include<bits/stdc++.h>
using namespace std;
#define ll long long int
map<ll,ll>arr;
ll MAX(ll n);
ll sum=0;
int main()
{
    ll n;
    while(cin>>n)
    {
        cout<<MAX(n)<<endl;
    }
}

ll MAX(ll n)
{
    if(n<=1)
        return n;
    if(arr[n]==0)
        arr[n]=max(n,(MAX(n/2)+MAX(n/3)+MAX(n/4)));
    return arr[n];
}
