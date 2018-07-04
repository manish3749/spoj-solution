#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back
#define si(x) scanf("%d",&x)
#define pi(x) printf("%d\n",x)
#define sl(x) scanf("%lld",&x)
#define pl(x) printf("%lld\n",x)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pis pair<string,int>
#define F first
#define S second
#define M 1000000007
#define N 1000002
#define ld long double

ll a[2010];
ll cnt[2000][2000];
ll n;
ll func(int f,int l)
{
    if(f>l)
        return 0;
    if(cnt[f][l]!=0)
        return cnt[f][l];

    ll var=f+n-l;
    ll p1=func(f+1,l)+var*a[f];
    ll p2=func(f,l-1)+var*a[l];

    return cnt[f][l]=max(p1,p2);
}


int main()
{
    sl(n);
    for(ll i=0;i<n;i++)
        sl(a[i]);
    cout<<func(0,n-1);

}
