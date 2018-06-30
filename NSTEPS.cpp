#include<iostream>
using namespace std;
#define ll long long int
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll x,y;
        cin>>x>>y;

        if((x%2==0)&&(y%2==0))
        {
            if((x==y)||((x-y)==2))
                cout<<x+y<<"\n";
            else
                cout<<"No Number"<<"\n";
        }
        else if((x%2!=0)&&(y%2!=0))
        {
            if((x==y)||((x-y)==2))
                cout<<x+y-1<<"\n";
            else
                cout<<"No Number"<<"\n";
        }
        else
            cout<<"No Number"<<"\n";
    }
}
