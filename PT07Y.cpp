#include<bits/stdc++.h>
using namespace std;

#define N 100000
int arr[N];
int siz[N];
int n,x,y,m;

int root(int i)
{
    while(arr[i]!=i)
        i=arr[i];
    return i;
}

bool findd(int x,int y)
{
    if(root(x)==root(y)) return true;
    else return false;
}

void unionn(int x,int y)
{
    arr[root(x)]=root(y);
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<=n;i++) arr[i]=i,siz[i]=i;
    int flag=1;
    vector< pair<int,int> >v;
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }
    if(m=n-1)
    {
        for(int i=0;i<v.size();i++){
            x=v[i].first,y=v[i].second;
            if(findd(x,y)){ flag=0;break; }
            else unionn(x,y);
        }
    }
    if(m==n-1 && flag==1) cout<<"YES";
    else cout<<"NO";
}
