#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 100000
struct node
{
    ll sum;
    ll minsum;
}tree[MAX];
int arr[MAX];
char str[MAX];
void build(ll node,ll start,ll endd);
void update(ll node,ll start,ll endd,ll index);
 
int main()
{
    int t=1;
    while(t<=10)
    {
        ll n;
        cin>>n;
        for(ll i=0;i<n;i++)
        {
            cin>>str[i];
            arr[i]=0;
        }
        cout<<"Test "<<t<<":"<<endl;
 
        build(1,0,n-1);
 
        ll noq;
        cin>>noq;
        while(noq--)
        {
            ll index;
            cin>>index;
            if(index)
            {
                update(1,0,n-1,index-1);
            }
            else
            {
                if(!tree[1].sum && !tree[1].minsum)
                    cout<<"YES"<<endl;
                else
                    cout<<"NO"<<endl;
            }
        }
        t++;
    }
}
 
void build(ll node,ll start,ll endd)
{
    if(start==endd)
        tree[node].sum=tree[node].minsum=(str[start]=='(' ? 1 : -1);
 
    else
    {
        ll mid=(start+endd)/2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,endd);
 
        tree[node].sum=tree[2*node].sum+tree[2*node+1].sum;
        tree[node].minsum=min(tree[2*node].minsum,tree[2*node].sum+tree[2*node+1].minsum);
    }
}
 
void update(ll node,ll start,ll endd,ll index)
{
    if(start==endd)
    {
        tree[node].sum=tree[node].minsum=-tree[node].sum;
        return;
    }
 
        ll mid=(start+endd)/2;
 
        if(index<=mid)
            update(2*node,start,mid,index);
        else
            update(2*node+1,mid+1,endd,index);
 
        tree[node].sum=tree[2*node].sum+tree[2*node+1].sum;
        tree[node].minsum=min(tree[2*node].minsum,tree[2*node].sum+tree[2*node+1].minsum);
}
