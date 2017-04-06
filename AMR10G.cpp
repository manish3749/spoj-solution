#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 100000
 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll k,n;
        cin>>n>>k;
        vector<ll>v(n);
        for(ll i=0;i<n;i++)
            cin>>v[i];
        sort(v.begin(),v.end());
        if(k==1)
            cout<<"0"<<endl;
        else
        {
            ll dif=0,i,j=k-1;
            ll MIN=v[j]-v[0];
            for(i=0,j=k-1;j<n;)
            {
                dif=v[j]-v[i];
                MIN=min(dif,MIN);
                i++;
                j=k-1+i;
            }
            cout<<MIN<<endl;
        }
    }
}
