#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll k1,k2,k3;
        cin>>k1>>k2>>k3;
        ll n1=2*k3;
        ll n2=(k1+k2);
        ll n=n1/n2;
        ll d1=(k2-k1);
        ll d2=(n-5);
        ll d=d1/d2;
        ll a1=(2*k3);
        ll a2=a1/n;
        ll a3=(k2+2*d);
        ll a=(a2)-a3;
        ll arr[n];
        arr[0]=a;
        for(int i=1;i<n;i++)
            arr[i]=arr[i-1]+d;
        cout<<n<<endl;
         for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
}
 
