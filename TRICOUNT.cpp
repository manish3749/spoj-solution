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
        if(n==1)
            cout<<"1"<<endl;
        else
        {
            cout<<(n*(n+2)*(2*n+1))/8<<endl;
        }
    }
}
