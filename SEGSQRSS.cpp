#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 1000000
int arr[MAX];
int tree[MAX];

void build(ll node,ll start,ll endd)
{
    if(start==endd)
        tree[node]=arr[start]*arr[start];
    else
    {
        ll mid=(start+endd)/2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,endd);

        tree[node]=tree[2*node]+tree[2*node+1];
    }
}

void update1(ll node,ll start,ll endd,ll l,ll r,ll val)
{
    if(start>endd || start>r || endd<l)
        return;
    if(start==endd)
    {
        tree[node]=sqrt(tree[node]);
        tree[node]+=val;
        tree[node]=tree[node]*tree[node];
        return;
    }

    ll mid=(start+endd)/2;
    update1(2*node,start,mid,l,r,val);
    update1(2*node+1,mid+1,endd,l,r,val);
    tree[node]=tree[2*node]+tree[2*node+1];
}
void update0(ll node,ll start,ll endd,ll l,ll r,ll val)
{
    if(start>endd || start>r || endd<l)
        return;

    if(start==endd)
    {
        tree[node]=(val*val);
        return;
    }

    ll mid=(start+endd)/2;
    update0(2*node,start,mid,l,r,val);
    update0(2*node+1,mid+1,endd,l,r,val);
    tree[node]=tree[2*node]+tree[2*node+1];

}
ll querry(ll node,ll start,ll endd,ll l,ll r)
{
    if(r<start || endd<l)
        return 0;

    if(start>=l && endd<=r)
        return tree[node];

    ll mid=(start+endd)/2;
    ll p1=querry(2*node,start,mid,l,r);
    ll p2=querry(2*node+1,mid+1,endd,l,r);
    return p1+p2;
}
int main()
{
    ll t;
    cin>>t;
    ll ctr=1;
    while(t--)
    {

        cout<<"Case "<<ctr++<<":"<<endl;
        ll n,q;
        cin>>n>>q;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        build(1,0,n-1);
        while(q--)
        {

            int ch;
            cin>>ch;
            if(ch==2)
            {
                ll l,r;
                cin>>l>>r;
                cout<<querry(1,0,n-1,l-1,r-1)<<endl;
            }
            else if(ch==1)
            {
                ll l,r,val;
                cin>>l>>r>>val;
                update1(1,0,n-1,l-1,r-1,val);
            }
            else
            {
                ll l,r,val;
                cin>>l>>r>>val;
                update0(1,0,n-1,l-1,r-1,val);
            }
        }
    }
}
