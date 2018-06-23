#include<iostream>
using namespace std;
#define ll long long int
int main()
{
    while(1)
    {
        ll n;
        cin>>n;
        if(n==-1)
            break;
        else
        {
            int arr[2*n];
            int lrgr[2*n];
            ll k=0;
            for(ll i=0;i<n;i++)
                cin>>arr[i];
            ll sum=0;
            for(ll i=0;i<n;i++)
            {
                sum+=arr[i];
            }
            if(sum%n!=0)
                cout<<"-1"<<endl;
            else
            {
                ll avg=sum/n;
                for(ll i=0;i<n;i++)
                {
                    if(arr[i]>avg)
                        lrgr[k++]=arr[i];
                }
                sum=0;
                for(ll i=0;i<k;i++)
                {
                    sum+=(lrgr[i]-avg);
                }
                cout<<sum<<endl;
            }
        }
    }
}
