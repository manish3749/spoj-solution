#include<bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;
#define si(x) scanf("%d",&x)
#define pi(x) printf("%d\n",x)
#define sl(x) scanf("%lld",&x)
#define pl(x) printf("%lld\n",x)
#define ll long long int
#define ld long double
#define MOD 1000000007
int DP[1010][1010];
int main()
{
    int t;
    si(t);
    int var=1;
    while(var<=t)
    {
        int n,k;
        si(n);si(k);
        vector<int>arr(n+1,0);
        for(int i=1;i<=n;i++)
            si(arr[i]);

        for(int i=1;i<=k;i++)
        {
            if(i<arr[1])
                DP[1][i]=0;
            else
                DP[1][i]=arr[1];
        }
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                if(j<arr[i])
                    DP[i][j]=DP[i-1][j];
                else
                    DP[i][j]=max(DP[i-1][j],arr[i]+DP[i-2][j-arr[i]]);
            }
        }
        printf("Scenario #%d: %d\n",var,DP[n][k]);
        var++;
    }
}
