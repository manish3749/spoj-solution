#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll n;
    cin>>n;
    if(n<=1 || (n&(n-1))==0)
        cout<<"TAK";
    else
        cout<<"NIE";
}
