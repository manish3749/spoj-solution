#include<bits/stdc++.h>
using namespace std;
int DP[101][101];

int MIN(int x,int y,int z)
{
    return min(min(x,y),z);
}
int main()
{
    int n,m;
    cin>>n>>m;
    int arr[n][m];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }

    for(int j=0;j<m;j++)
        DP[0][j]=arr[0][j];

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(j==0)
                DP[i][j]=arr[i][j]+min(DP[i-1][j],DP[i-1][j+1]);
            else if(j==m-1)
                DP[i][j]=arr[i][j]+min(DP[i-1][j-1],DP[i-1][j]);
            else
                DP[i][j]=arr[i][j]+MIN(DP[i-1][j-1],DP[i-1][j],DP[i-1][j+1]);
        }
    }
    int ansr=DP[n-1][0];

    for(int j=1;j<m;j++)
    {
        if(DP[n-1][j]<ansr)
            ansr=DP[n-1][j];
    }
    cout<<ansr<<endl;
}
