#include<bits/stdc++.h>
using namespace std;
#define si(x) scanf("%d",&x)
#define pi(x) printf("%d\n",x)
#define sl(x) scanf("%lld",&x)
#define pl(x) printf("%lld\n",x)
#define ll long long int
int dp[2001][2001];
int main()
{
    int t;
    si(t);
    while(t--)
    {
        int mx=0;
        vector<int>v1;
        while(1)
        {
            int x;
            si(x);
            v1.push_back(x);
            if(x==0)
                break;
        }
        while(1)
        {
            vector<int>v2;
            while(1)
            {
                int x;
                si(x);
                v2.push_back(x);
                if(x==0)
                    break;
            }
            if(v2[0]==0)
                break;
            int m=v1.size()-1;
            int n=v2.size()-1;

            for(int i=0;i<=m;i++)
            {
                for(int j=0;j<=n;j++)
                {
                    dp[i][j]=0;
                    if(i==0 || j==0)
                        dp[i][j]=0;
                    else if(v1[i-1]==v2[j-1])
                        dp[i][j]=1+dp[i-1][j-1];
                    else
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
            mx=max(mx,dp[m][n]);
        }
        pi(mx);
    }
}
