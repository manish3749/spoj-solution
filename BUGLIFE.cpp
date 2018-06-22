#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back
#define si(x) scanf("%d",&x)
#define pi(x) printf("%d\n",x)
#define s(x) scanf("%I64d",&x)
#define p(x) printf("%I64d\n",x)
#define sc(x) scanf("%s",x)
#define pc(x) printf("%s",x)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define F first
#define S second
#define M 1000000007
#define N 100005
#define inf 2e9
#define PQG priority_queue< int,std::vector<int>,std::greater<int> >
#define PQL priority_queue< int,std::vector<int>,std::less<int> >
#define PQPL priority_queue<pii ,vector< pii >, less< pii > >
#define PQPG priority_queue<pii ,vector< pii >, greater< pii > >
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
 
 
int main()
{
    int t;
    si(t);
    int cnt=1;
    while(cnt<=t){
        int n,m;
        si(n);si(m);
        int a[n+1][n+1];
        memset(a,0,sizeof(a));
        vector<int>graph[n+1];
        for(int i=0;i<m;++i){
            int u,v;
            si(u),si(v);
            graph[u].pb(v);
            graph[v].pb(u);
            a[u][v]=1;
            a[v][u]=1;
        }
        vector<int>c(n+1,-1);
        vector<int>vis(n+1,false);
        c[1]=1;
        int f=1;
        for(int i=1;i<=n;++i){
            if(vis[i]==1) continue;
            queue<int>q;
            q.push(i);
            while(!q.empty()){
                int v=q.front();
                q.pop();
                if(a[v][v]==1){
                    f=0;
                    break;
                }
                for(auto it:graph[v]){
                    if(!vis[it] && c[it]==-1){
                        vis[it]=1;
                        c[it]=1-c[v];
                        q.push(it);
                    }
                    else if(vis[it] && c[it]==c[v]){
                        f=0;
                        break;
                    }
                }
            }
        }
        cout<<"Scenario #"<<cnt<<":"<<endl;
        if(f==0) cout<<"Suspicious bugs found!\n";
        else cout<<"No suspicious bugs found!\n";
        cnt++;
    }
}
