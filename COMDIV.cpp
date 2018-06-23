#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll GCD(ll a,ll b);
void FACTORS(ll n);
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ll a,b;
        scanf("%lld%lld",&a,&b);
       ll gcd=GCD(max(a,b),min(a,b));
        FACTORS(gcd);
    }
}

ll GCD(ll a,ll b)
{
    if(b==0)
        return a;
    else
        GCD(b,a%b);
}

void FACTORS(ll n)
{
    ll ctr=0;
    ll sum=1;
    while(n%2==0)
    {
        n/=2;
        ctr++;
    }
    sum*=(ctr+1);
    for(int i=3;i<=sqrt(n);i+=2)
    {
        ctr=0;
        while(n%i==0)
        {
            n=n/i;
            ctr++;
        }
        sum*=(ctr+1);
    }
    if(n>2)
        sum*=2;

    printf("%lld\n",sum);
}
