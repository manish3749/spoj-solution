#include<bits/stdc++.h>
using namespace std;
int r,c;
int a[300][300],vis[300][300],cnt[100000],ctr=0;
void dfs(int x,int y)
{
    if(x<0 || y<0 || x>=r || y>=r || vis[x][y]==1 || a[x][y]==0) return;
    else{
        ctr++;
        vis[x][y]=1;
        dfs(x+1,y);
        dfs(x-1,y);
        dfs(x,y+1);
        dfs(x,y-1);
    }
}

int main()
{
    while(true)
    {
    cin>>r>>c;
    if(r==0 && c==0) break;
    else {

    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            cin>>a[i][j];
    int cntr=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(!vis[i][j] && a[i][j]==1){
                cntr++;
                ctr=0;
                dfs(i,j);
                cnt[ctr]++;
            }
        }
    }
    cout<<cntr<<endl;
    for(int i=1;i<=r*c;i++)
        if(cnt[i])
            cout<<i<<" "<<cnt[i]<<endl;

    }
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            a[i][j]=0,vis[i][j]=0;
    for(int i=0;i<=r*c;i++) cnt[i]=0;
    ctr=0;
    }
}
