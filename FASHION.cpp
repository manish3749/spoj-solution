#include<iostream>
using namespace std;
#include<algorithm>
#define ll long long int
#define MAX 100000

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        int men[MAX];
        int wmen[MAX];
        for(ll i=0;i<n;i++)
            cin>>men[i];

        for(ll i=0;i<n;i++)
            cin>>wmen[i];

        sort(men,(men+n));
        sort(wmen,(wmen+n));
        ll sum=0;
        for(ll i=0;i<n;i++)
        {
            sum+=men[i]*wmen[i];
        }

        cout<<sum<<endl;
    }
}
