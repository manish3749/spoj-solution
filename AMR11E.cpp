#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<int>v;
void PRIME();
int main()
{
    ll t;
    cin>>t;
    PRIME();
    while(t--)
    {
        ll n;
        cin>>n;
        ll ctr=0;
        ll i=30;
 
        while(ctr<n)
        {
            int flag=0;
            for(ll j=0;j<v.size();j++)
            {
                if(i%v[j]==0)
                    flag++;
 
                if(flag==3)
                {
                    ctr++;
                    break;
                }
            }
            i++;
        }
        cout<<i-1<<endl;
    }
}
 
void PRIME()
{
    ll n=2;
    while(v.size()<=500)
    {
        int flag=1;
        for(ll i=2;i<=sqrt(n);i++)
        {
            if(n%i==0)
                flag=0;
        }
        if(flag)
            v.push_back(n);
 
        n++;
    }
}
