#include<bits/stdc++.h>
using namespace std;
#define MAX 6101
int table[MAX][MAX];
#define ll long long int
int COUNT(char *str,int );
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        char str[MAX];
        cin>>str;
        cout<<COUNT(str,strlen(str))<<endl;
    }
}
int COUNT(char *str,int n)
{
    int l,h,gap;
    memset(table,0,sizeof(table));
    for(gap=1;gap<n;gap++)
    {
        for(l=0,h=gap; h<n; ++l,++h)
        {
            if(str[l]==str[h])
                table[l][h]=table[l+1][h-1];
            else
                table[l][h]=(min(table[l+1][h],table[l][h-1])+1);
        }
    }
    return table[0][n-1];
}
