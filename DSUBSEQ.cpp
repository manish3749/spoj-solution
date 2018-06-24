#include<bits/stdc++.h>
using namespace std;
#define m 1000000007
#define ll long long int
int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        string s;
        cin>>s;
        int n=s.length();
        int dp[n+1];
        vector<int>last(256,-1);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            dp[i]=(2*dp[i-1])%m;
            if(last[s[i-1]]!=-1){
                dp[i]=(dp[i]-dp[last[s[i-1]]]+m)%m;
            }
            last[s[i-1]]=(i-1);
        }
        cout<<dp[n]<<endl;
    }

}
