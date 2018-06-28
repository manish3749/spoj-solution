#include<bits/stdc++.h>
using namespace std;
#define si(x) scanf("%d",&x)
#define pi(x) printf("%d\n",x)
#define sl(x) scanf("%lld",&x)
#define pl(x) printf("%lld\n",x)
#define ll long long int
#define mo 1e9+7
ll f[10001][5001];

int main()
{
    int n;
    si(n);
    vector< pair<int,int> >v(n+1);
    for(int i=1;i<=n;i++)
    {
        si(v[i].first);
        si(v[i].second);
    }
    f[1][0]=v[1].second;
    f[1][1]=INT_MAX;
    f[1][2]=INT_MAX;
    for(int i=2;i<=n;i++)
        f[i][0]=f[i-1][0]+v[i].second;

    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i/2+1;j++)
        {
            if(i<2*j)
                f[i][j]=INT_MAX;
            else
                f[i][j]=min(f[i-1][j-1]+v[i].first,f[i-1][j]+v[i].second);
        }
    }
    int ansr=v[n].first+f[n-1][n/2-1];
    pi(ansr);
}
