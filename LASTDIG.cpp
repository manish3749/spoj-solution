#include<iostream>
using namespace std;
#define ll long long int

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        if(b==0)
            cout<<"1"<<endl;
        else{
        int arr[]={0,0,0,0,1,1,1,1,6,2,4,8,1,3,9,7,6,4,6,4,5,5,5,5,6,6,6,6,1,7,9,3,6,8,4,2,1,9,1,9};
        int i=a%10;
        int j=4*i;
        int k=b%4;
        cout<<arr[j+k]<<endl;
        }

    }
}
