#include<iostream>
using namespace std;
#include<cmath>
#define ll long long int
int main()
{
    ll n;
    cin>>n;
    ll ctr=0;
    ll var=n;
    int flag=1;
    for(ll i=1;i<=sqrt(n);i++)
    {
        for(ll j=i;j<=n/flag;j++)
        {
            if(i*j<=n)
                ctr++;
        }
        flag++;
    }
    cout<<ctr;
}
