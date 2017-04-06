#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(v) v.begin(), v.end()
ll n,c;
int FUNC(vector<ll>&v,ll num);
ll B_SEARCH(vector<ll>&v);
int main()
{
    ll t;
    scanf("%lld",&t);
    while (t--)
    {
        scanf("%lld %lld",&n,&c);
        vector<ll>v(n);
        for (int i=0; i<n; i++)
            scanf("%lld",&v[i]);
        sort(all(v));
        ll k=B_SEARCH(v);
        printf("%lld\n",k);
    }
    return 0;
}
 
int FUNC(vector<ll>&v,ll num)
{
    ll cows=1,pos=v[0];
    for (ll i=1; i<n; i++)
    {
        if (v[i]-pos>=num)
        {
            pos=v[i];
            cows++;
            if (cows==c)
                return 1;
        }
    }
    return 0;
}
 
ll B_SEARCH(vector<ll>&v)
{
    ll first=0,last=v[n-1],maxx=-1;
    while (first<last)
    {
        ll mid=first+(last-first)/2;
        if (FUNC(v,mid)==1)
        {
            if (mid>maxx)
                maxx=mid;
            first=mid+1;
        }
        else
            last=mid;
    }
    return maxx;
}
