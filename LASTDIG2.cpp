#include<iostream>
using namespace std;
#define ll long long int
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        ll a=str.at(str.length()-1)-48;
        ll b;
        cin>>b;
        if(b==0)
            cout<<"1"<<endl;
        else
        {
            ll val=1;
            ll rp=b%4;
            if(rp==0)
                val=a*a*a*a;
            else
            {
                while(rp--)
                    val*=a;
            }
            cout<<val%10<<endl;
        }
    }
}
