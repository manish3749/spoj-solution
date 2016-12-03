#include<bits/stdc++.h>
using namespace std;
#define si(x) scanf("%d",&x)
#define pi(x) printf("%d\n",x)

struct node{
    int sum;
    int left;
    int right;
    int best;
};

int arr[50003];
node tree[2000003];

node makenode(int sum,int left,int right,int best)
{
    node temp;
    temp.sum=sum;
    temp.left=left;
    temp.right=right;
    temp.best=best;
    return temp;
}

node combine(node l,node r)
{
    int left=max(l.left,l.sum+r.left);
    int right=max(r.right,r.sum+l.right);
    int best=max(l.right+r.left,max(l.best,r.best));
    return makenode(l.sum+r.sum,left,right,best);
}

node BUILD(int idx,int start,int endd)
{
    if(start==endd)
    {
        tree[idx]=makenode(arr[start],arr[start],arr[start],arr[start]);
        return tree[idx];
    }
    int mid=(start+endd)/2;
    node l=BUILD(2*idx+1,start,mid);
    node r=BUILD(2*idx+2,mid+1,endd);

    tree[idx]=combine(l,r);
    return tree[idx];
}

void UPDATE(int idx,int start,int endd,int p,int val)
{
    if(start==endd && p==start)
    {
        arr[p]=val;
        tree[idx]=makenode(val,val,val,val);
        return;
    }

    int mid=(start+endd)/2;
    if(p<=mid)
        UPDATE(2*idx+1,start,mid,p,val);
    else
        UPDATE(2*idx+2,mid+1,endd,p,val);

    tree[idx]=combine(tree[2*idx+1],tree[2*idx+2]);

}

node QUERRY(int idx,int start,int endd,int l,int r)
{
    if(start==l && endd==r)
        return tree[idx];
    int mid=(start+endd)/2;
    if(r<=mid)
        return QUERRY(2*idx+1,start,mid,l,r);
    if(l>mid)
        return QUERRY(2*idx+2,mid+1,endd,l,r);

    node l1=QUERRY(2*idx+1,start,mid,l,mid);
    node r1=QUERRY(2*idx+2,mid+1,endd,mid+1,r);

    return combine(l1,r1);
}

int main()
{
    int n,q;
    si(n);
    for(int i=0;i<n;i++)
        si(arr[i]);
    BUILD(0,0,n-1);
    si(q);
    int ch,x,y;
    while(q--)
    {
        si(ch);si(x);si(y);
        if(ch==0)
            UPDATE(0,0,n-1,x-1,y);
        else
            pi(QUERRY(0,0,n-1,x-1,y-1).best);
    }
}
