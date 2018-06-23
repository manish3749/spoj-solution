#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000007
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll total=n*(3*n+1);
        ll ansr=total/2;
        cout<<ansr%MOD<<endl;
    }
}
