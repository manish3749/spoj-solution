#include<stdio.h>
#define ll long long int
int main()
{
    ll t;
    scanf("%lld",&t);
    while(t--)
    {
        ll n;
        scanf("%lld",&n);
        ll result=n;
        for(ll p=2;p*p<=n;p++)
        {
            if(n%p==0)
            {
                while(n%p==0)
                    n/=p;
                result-=result/p;
            }
        }
        if(n>1)
            result-=result/n;
        printf("%lld\n",result);

    }
}
