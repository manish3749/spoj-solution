#include<bits/stdc++.h>
using namespace std;
#define si(x) scanf("%d",&x)
#define pi(x) printf("%d\n",x)
#define sl(x) scanf("%lld",&x)
#define pl(x) printf("%lld\n",x)
#define ll long long int

int DP[2010][2010];
int edit(string str1,string str2)
{
    int l1=str1.length();
    int l2=str2.length();

    for(int i=0;i<=l1;i++)
    {
        for(int j=0;j<=l2;j++)
        {
            if(i==0)
                DP[i][j]=j;
            else if(j==0)
                DP[i][j]=i;
            else if(str1[i-1]==str2[j-1])
                DP[i][j]=DP[i-1][j-1];
            else
                DP[i][j]=1+min(DP[i-1][j-1],min(DP[i-1][j],DP[i][j-1]));
        }
    }
    return DP[l1][l2];
}

int main()
{
    int t;
    si(t);
    while(t--)
    {
        string str1,str2;
        cin>>str1>>str2;
        cout<<edit(str1,str2)<<endl;
    }
}

