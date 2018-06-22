#include<bits/stdc++.h>
using namespace std;
#define si(x) scanf("%d",&x)
#define pi(x) printf("%d\n",x)
#define sl(x) scanf("%lld",&x)
#define pl(x) printf("%lld\n",x)
#define ll long long int
#define mo 1e9+7
 
int main()
{
    int n,N,a,b,c,x[90],y[90],z[90],dp[90];
    while(1)
    {
        si(n);
        if(n==0)
            break;
        else
        {
            N=3*n;
 
            for(int i=0;i<n;i++)
            {
                si(a);si(b);si(c);
                x[3*i]=a;y[3*i]=b;z[3*i]=c;
                x[3*i+1]=b;y[3*i+1]=c;z[3*i+1]=a;
                x[3*i+2]=c;y[3*i+2]=a;z[3*i+2]=b;
            }
            for(int i=0;i<N;i++)
            {
                for(int j=i+1;j<N;j++)
                {
                    if((x[j]<x[i] && y[j]<y[i]) || (y[j]<x[i] && x[j]<y[i]))
                    {
                        swap(x[i],x[j]);
                        swap(y[i],y[j]);
                        swap(z[i],z[j]);
                    }
                }
            }
            int ans=-1;
 
            for(int i=0;i<N;i++)
            {
                dp[i]=z[i];
                for(int j=0;j<i;j++)
                    if((x[j]<x[i] && y[j]<y[i]) || (y[j]<x[i] && x[j]<y[i]))
                        dp[i]=max(dp[i],dp[j]+z[i]);
 
                ans=max(ans,dp[i]);
            }
            pi(ans);
        }
    }
}
 
