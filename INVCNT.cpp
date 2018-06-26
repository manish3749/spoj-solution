#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(v) v.begin(),v.end()
ll MERGE(vector<ll>&left,vector<ll>&right,vector<ll>&v);
ll MERGE_SORT(vector<ll>&v);
ll ctr=0;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        cout<<endl;
        ctr=0;
        ll n,x;
        cin>>n;
        vector<ll>v(n);
        for(ll i=0;i<n;i++)
            cin>>v[i];

        cout<<MERGE_SORT(v)<<endl;
    }
}

ll MERGE_SORT(vector<ll>&v)
{
    ll n=v.size(),ctr=0;
    if(n>=2)
    {
        ll mid=n/2;
        ll s=n-mid;
        vector<ll>left(mid);
        vector<ll>right(s);

        for(ll i=0;i<mid;i++)
            left[i]=v[i];

        ll m=0;
        for(ll i=mid;i<n;i++)
            right[m++]=v[i];


        ctr=MERGE_SORT(left);
        ctr+=MERGE_SORT(right);

        ctr+=MERGE(left,right,v);
    }
    return ctr;
}

ll MERGE(vector<ll>&left,vector<ll>&right,vector<ll>&v)
{
    ll nl=left.size();
    ll nr=right.size();
    ctr=0;
    ll i,j,k;
    i=j=k=0;
    ll mid=v.size()/2;
    while((i<nl)&&(j<nr))
    {
        if(left[i]<=right[j])
            v[k]=left[i++];
        else
        {
            v[k]=right[j++];
            ctr+=(mid-i);
        }
        k++;
    }
    while(i<nl)
        v[k++]=left[i++];
    while(j<nr)
        v[k++]=right[j++];

    return ctr;
}
