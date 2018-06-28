#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
int main()
{
    ll t;
    cin>>t;
    ll k=0;
    while(t--)
    {
        ld r;
        cin>>r;
        cout<<"Case "<<++k<<": ";
        ld s=4*r*r+0.25;
        cout<<fixed<<setprecision(2)<<s<<endl;
    }
}
