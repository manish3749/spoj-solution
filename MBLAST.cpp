#include<bits/stdc++.h>
using namespace std;
#define si(x) scanf("%d",&x)
#define pi(x) printf("%d\n",x)
#define sl(x) scanf("%lld",&x)
#define pl(x) printf("%lld\n",x)
#define ll long long int
#define MIN(a,b,c) min(a,min(a,b))
int k;

int dist(string str1,int m,string str2,int n)
{
     int DP[m+1][n+1];

     for (int i = 1; i <= m; i++)
			DP[i][0] = k * i;
		for (int j = 1; j <= n; j++)
			DP[0][j] = k * j;

		for (int i = 1; i <= m; i++)
        {
			for (int j = 1; j <= n; j++)
			{
				DP[i][j] = min(min(k + DP[i - 1][j], k + DP[i][j - 1]), DP[i - 1][j - 1]
						+ abs(str1[i - 1] - str2[j - 1]));
			}
        }
     return DP[m][n];
}

int main()
{
    string str1,str2;
    cin>>str1;
    cin>>str2;
    si(k);
    int l1=str1.length();
    int l2=str2.length();
    cout<<dist(str1,l1,str2,l2);
}
