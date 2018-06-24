#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll GCD(ll a,ll b);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;

        ll maxx=max(a,b);
        ll minn=min(a,b);

        ll gcd=GCD(maxx,minn);
        cout<<b/gcd<<" "<<a/gcd<<endl;
    }
}

ll GCD(ll a,ll b)
{
    if(b==0)
        return a;
    else
        return GCD(b,a%b);
}
