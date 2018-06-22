#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 101
ll stone(int m,int n);
int arr[MAX][MAX];
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                cin>>arr[i][j];
 
        ll sum=stone(m,n);
        cout<<sum<<endl;
    }
}
ll MAXM(int x,int y,int z)
{
    return max(max(x,y),z);
}
ll stone(int m,int n)
{
    ll DP[MAX][MAX];
 
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            DP[i][j]=0;
 
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==0)
                DP[i][j]=arr[i][j];
            else if(i>0 && j==0)
                DP[i][j]=arr[i][j]+max(DP[i-1][j],DP[i-1][j+1]);
            else if(i>0 && j==n-1)
                DP[i][j]=arr[i][j]+max(DP[i-1][j-1],DP[i-1][j]);
            else
                DP[i][j]=arr[i][j]+MAXM(DP[i-1][j-1],DP[i-1][j],DP[i-1][j+1]);
        }
    }
    ll maxx=DP[m-1][0];
    for(int j=1;j<n;j++)
        maxx=max(maxx,DP[m-1][j]);
 
    return maxx;
}
