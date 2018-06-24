#include<bits/stdc++.h>
using namespace std;
#define si(x) scanf("%d",&x)
#define pi(x) printf("%d\n",x)
#define sl(x) scanf("%lld",&x)
#define pl(x) printf("%lld\n",x)
#define ll long long int
ll dp[100010];

int main()
{
    int t;
    si(t);
    while(t--)
    {
        for(ll i=0;i<100010;i++)
            dp[i]=0;
        ll n;
        sl(n);
        ll arr[n];
        for(ll i=0;i<n;i++)
            sl(arr[i]);
        ll k=n-1;
        while(k>=n-3 && k>=0)
        {
            dp[k]=dp[k+1]+arr[k];
            k--;
        }
        for(ll i=n-4;i>=0;i--)
        {
            ll sum1=0,sum2=0,sum3=0;
            sum1=arr[i]+dp[i+2];
            sum2=arr[i]+arr[i+1]+dp[i+4];
            sum3=arr[i]+arr[i+1]+arr[i+2]+dp[i+6];
            dp[i]=max(sum1,max(sum2,sum3));
        }

        pl(dp[0]);
    }
}
