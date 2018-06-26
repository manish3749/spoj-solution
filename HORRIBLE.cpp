#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 1000000
ll tree[MAX];
ll lazy[MAX];
void build(ll node,ll start,ll endd);
void update(ll node,ll start,ll endd,ll l,ll r,ll val);
ll querry(ll node,ll start,ll endd,ll l,ll r);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,c;
        cin>>n>>c;
        for(ll i=0;i<MAX;i++)
        {
            tree[i]=0;
            lazy[i]=0;
        }
        while(c--)
        {
            int ch;
            cin>>ch;
            if(ch==0)
            {
                ll x,y,z;
                cin>>x>>y>>z;
                update(1,1,n,x,y,z);
            }
            else
            {
                ll x,y;
                cin>>x>>y;
                ll sum=querry(1,1,n,x,y);
                cout<<sum<<endl;
            }
        }
    }
}

void update(ll node, ll start, ll endd, ll l, ll r, ll val)
{
    if(lazy[node] != 0)
    {
        tree[node] += (endd- start + 1) * lazy[node];
        if(start != endd)
        {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(start > endd || start > r || endd < l)
        return;
    if(start >= l && endd <= r)
    {
        tree[node] += (endd - start + 1) * val;
        if(start != endd)
        {
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    ll mid = (start + endd) / 2;
    update(node*2, start, mid, l, r, val);
    update(node*2 + 1, mid + 1, endd, l, r, val);
    tree[node] = tree[node*2] + tree[node*2+1];
}

ll querry(ll node, ll start, ll endd, ll l, ll r)
{
    if(start > endd || start > r || endd < l)
        return 0;
    if(lazy[node] != 0)
    {
        tree[node] += (endd - start + 1) * lazy[node];
        if(start != endd)
        {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(start >= l && endd <= r)
            return tree[node];
    ll mid = (start + endd) / 2;
    ll p1 = querry(node*2, start, mid, l, r);
    ll p2 = querry(node*2 + 1, mid + 1, endd, l, r);
    return (p1 + p2);
}









