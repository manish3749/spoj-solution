#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void MAXFUN(pair<int,int>p[],int cost,int fun);
bool COMPARE(pair<int,int>p1,pair<int,int>p2)
{
    if(p1.first>p2.first)
        return 0;
}

int main()
{
    while(1)
    {
        int cost,fun;
        cin>>cost>>fun;
        if(cost==0 && fun==0)
            break;
        else
        {
            pair<int,int>p[fun+1];
            p[0].first=p[0].second=0;

            for(int i=1;i<=fun;i++)
                cin>>p[i].first>>p[i].second;

            sort(p,p+fun+1,COMPARE);
            MAXFUN(p,cost+1,fun+1);
        }
    }
}

void MAXFUN(pair<int,int>p[],int cost,int fun)
{
    int m=fun;
    int n=cost;

    int DP[m][n];
    for(int j=0;j<n;j++)
        DP[0][j]=0;
    for(int i=0;i<m;i++)
        DP[i][0]=0;


    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(j<p[i].first)
                DP[i][j]=DP[i-1][j];
            else
                DP[i][j]=max((p[i].second+DP[i-1][j-p[i].first]),DP[i-1][j]);
        }
    }
    int k=n-1;
    while((DP[m-1][n-1]==DP[m-1][k]) && k>=0)
            k--;
    cout<<k+1<<" "<<DP[m-1][n-1]<<endl;
}
