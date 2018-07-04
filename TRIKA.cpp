#include<bits/stdc++.h>
using namespace std;
#define si(x) scanf("%d",&x)
#define pi(x) printf("%d\n",x)
#define sl(x) scanf("%lld",&x)
#define pl(x) printf("%lld\n",x)
#define ll long long int
int f[25][25];
int main()
{
    int n,m;
    si(n);si(m);
    int x,y;
    si(x);si(y);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            si(f[i][j]);
    }
    int ansr=f[x][y];
    for(int i=y+1;i<=m;i++)
        f[x][i]=max(-1,f[x][i-1]-f[x][i]);
    for(int i=x+1;i<=n;i++)
        f[i][y]=max(-1,f[i-1][y]-f[i][y]);

    for(int i=x+1;i<=n;i++)
    {
        for(int j=y+1;j<=m;j++)
            f[i][j]=max(-1,max(f[i-1][j],f[i][j-1])-f[i][j]);
    }
    if(f[n][m]>=0)
        cout<<"Y "<<f[n][m];
    else
        cout<<"N";
}
