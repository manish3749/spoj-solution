#include<bits/stdc++.h>
using namespace std;
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define pi(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)
#define ll long long int
#define MOD 1000000000+7
int main()
{
    while(1)
    {
        char str[5010];
        cin>>str;
        if(str[0]=='0')
            break;
        ll dp[5010];
        ll l=strlen(str);
        memset(dp,0,5050);
        dp[0]=1;
        ll num=0;
        for(ll i=1;i<l;i++)
        {
            num=(str[i-1]-'0')*10+(str[i]-'0');
            if(str[i]-'0')
                dp[i]=dp[i-1];
            if(num>=10 && num<=26)
                dp[i]+=dp[(i-2)<0?0:i-2];
        }
        pl(dp[l-1]);
    }
}
