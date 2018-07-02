#include<bits/stdc++.h>
using namespace std;
#define si(x) scanf("%d",&x)
#define pi(x) printf("%d\n",x)
#define sl(x) scanf("%lld",&x)
#define pl(x) printf("%lld\n",x)
#define ll long long int
#define ld long double
#define MAX 1000000000+7

int main()
{
    int t;
    si(t);
    while(t--)
    {
        ll m1,m2,n;
        sl(m1);sl(m2);sl(n);
        ll mx=m2-m1;
        ll DP[mx+10];
        for(int i=0;i<=mx+5;i++)
            DP[i]=MAX;
        DP[0]=0;
        while(n--)
        {
            ll p,w;
            sl(p);sl(w);
            for(int i=w;i<=mx;i++)
                DP[i]=min(DP[i],DP[i-w]+p);
        }

        if(DP[mx]==MAX)
            printf("This is impossible.\n");
        else
            printf("The minimum amount of money in the piggy-bank is %d.\n",DP[mx]);
    }
}
