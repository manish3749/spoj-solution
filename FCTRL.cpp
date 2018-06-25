#include<iostream>
using namespace std;
#define ll long long int
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll ctr=0;
        for(ll i=5;n/i>=1;i*=5)
        {
            ctr+=n/i;
        }
        cout<<ctr<<endl;
    }
}
