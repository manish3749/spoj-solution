#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll n,k=0;
    cin>>n;
    while(n--)
    {
        ll coins,n;
        cin>>coins>>n;
        int arr[n];

        for(int i=0;i<n;i++)
            cin>>arr[i];

        sort(arr,arr+n);

        ll sum=0;
        int ctr=0;
        int i=n-1;
        while(sum<coins && i>=0)
        {
            sum+=arr[i];
            i--;
            ctr++;
        }
        cout<<"Scenario #"<<++k<<":"<<endl;
        if(sum<coins)
            cout<<"impossible"<<endl;
        else
            cout<<ctr<<endl<<endl;
    }
}
