#include<bits/stdc++.h>
using namespace std;
#define MAX 10000

struct node {
    int sum;
    int left;
    int right;
    int best;
};

node tree[MAX];
int arr[MAX];
int n;

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
    int left=l.left;
    if(l.sum+r.left>left)
        left=l.sum+r.left;
    int right =r.right;
    if(r.sum+l.right>right)
        right=r.sum+l.right;
    int best=max(l.right+r.left, max(l.best,r.best));
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


node QUERRY(int idx,int start,int endd,int l,int r)
{
    if(start==l && endd==r)
        return tree[idx];

    int mid=(start+endd)/2;
    if(r<=mid)
        return QUERRY(2*idx+1,start,mid,l,r);
    if(l>mid)
        return QUERRY(2*idx+2,mid+1,endd,l,r);

    node li=QUERRY(2*idx+1,start,mid,l,mid);
    node ri=QUERRY(2*idx+2,mid+1,endd,mid+1,r);
    return combine(li,ri);
}


int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    BUILD(0,0,n-1);
    int q,a,b;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",QUERRY(0,0,n-1,a-1,b-1).best);
    }
}
