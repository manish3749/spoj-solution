#include<bits/stdc++.h>
using namespace std;
#define si(x) scanf("%d",&x)
#define pi(x) printf("%d\n",x)
#define sl(x) scanf("%lld",&x)
#define pl(x) printf("%lld\n",x)
#define ll long long int

int mrg(int arr[],int l,int mid,int r)
{
    int i=l,k=l,j=mid+1;
    int b[r];
    int cnt=0;
    while(i<=mid && j<=r)
    {
        if(arr[i]<=arr[j])
            b[k++]=arr[i++];
        else
        {
            b[k++]=arr[j++];
            cnt+=mid-i+1;
        }
    }
    while(i<=mid)
        b[k++]=arr[i++];
    while(j<=r)
        b[k++]=arr[j++];
    for(int i=l;i<=r;i++)
        arr[i]=b[i];
    return cnt;
}

int msort(int arr[],int l,int r)
{
    int ctr=0;
    if(l<r)
    {
        int mid=(l+r)/2;
        ctr=msort(arr,l,mid);
        ctr+=msort(arr,mid+1,r);
        ctr+=mrg(arr,l,mid,r);
    }
    return ctr;
}

int main()
{
    int t;
    si(t);
    while(t--)
    {
        int n;
        si(n);
        map<string,int>mp;
        for(int i=0;i<n;i++)
        {
            string str;
            cin>>str;
            mp[str]=i;
        }
        int arr[n];
        for(int j=0;j<n;j++)
        {
            string str;
            cin>>str;
            arr[j]=mp[str];
        }
        cout<<msort(arr,0,n-1)<<endl;
    }

}
