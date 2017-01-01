#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back
#define si(x) scanf("%d",&x)
#define pi(x) printf("%d\n",x)
#define sl(x) scanf("%lld",&x)
#define pl(x) printf("%lld\n",x)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pis pair<string,int>
#define F first
#define S second
#define M 1000000007
#define N 100002
#define ld long double
#define inf LONG_MAX-100

int n,m;
ll dist[200][200];
int x[]={-1,0,1}, y[]={-1,0,1};

void func(pair<int,int>&p)
{
    queue< pair<int,int> >q;
    q.push(p);
    while(!q.empty())
    {
        int xx=q.front().first,yy=q.front().second;
        q.pop();

        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if( abs(x[i])!=abs(y[j]) && xx+x[i]>=0 && xx+x[i]<n && yy+y[j]>=0 && yy+y[j]<m && dist[xx+x[i]][yy+y[j]]>1+dist[xx][yy] )
                {
                    dist[xx+x[i]][yy+y[j]] = 1+dist[xx][yy];
                    q.push(make_pair(xx+x[i],yy+y[j]));
                }
            }
        }
    }
}

int main()
{
    int t;
    si(t);
    while(t--)
    {
        si(n);si(m);
        int a[n][m];
        string s;
        for(int i=0;i<n;i++){
            cin>>s;
            for(int j=0;j<s.size();j++){
                if(s[j]=='0') a[i][j]=0;
                else  a[i][j]=1;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]==0) dist[i][j]=inf;
                else dist[i][j]=0;
            }
        }

        vector< pair<int,int> >v;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                v.push_back((make_pair(i,j)));
        }
        for(int i=0;i<v.size();i++)
            func(v[i]);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                printf("%d ",dist[i][j]);
            cout<<endl;
        }
    }
}
