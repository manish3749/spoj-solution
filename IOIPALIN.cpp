#include<bits/stdc++.h>
using namespace std;
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define pi(x) printf("%d",x)
#define pl(x) printf("%lld",x)

int main()
{
    int n;
    si(n);
    string str;
    cin>>str;
    int dp[n][n];
    memset(dp,0,sizeof(dp));

    for(int i=1;i<n;i++)
    {
        for(int j=0,h=i;h<n;j++,h++)
        {
            if(str[j]==str[h])
                dp[j][h]=dp[j+1][h-1];
            else
                dp[j][h]=1+min(dp[j][h-1],dp[j+1][h]);
        }
    }
    pi(dp[0][n-1]);
}
