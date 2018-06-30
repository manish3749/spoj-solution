#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    while(1)
    {

    ll a,b;
    cin>>a>>b;
    if(a==0 && b==0)
        break;
    else
    {
    vector<ll>va(a);
    vector<ll>vb(b);

    for(ll i=0;i<a;i++)
        cin>>va[i];
    for(ll i=0;i<b;i++)
        cin>>vb[i];

    sort(va.begin(),va.end());
    sort(vb.begin(),vb.end());

    if(va[0]>=vb[1])
        cout<<"N"<<endl;
    else
        cout<<"Y"<<endl;
    }
    }
}
