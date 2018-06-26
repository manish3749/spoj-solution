#include<iostream>
using namespace std;
#include<stack>
#define MAX 100000
#define ll long long int
ll MAX_AREA(ll arr[],ll n);
int main()
{
    while(1)
    {
        ll arr[MAX];
        ll n;
        cin>>n;
        if(n==0)break;
        else
        {
            for(ll i=0;i<n;i++)
            cin>>arr[i];
            ll area=MAX_AREA(arr,n);
            cout<<area<<endl;
        }
    }
}

ll MAX_AREA(ll arr[],ll n)
{
    stack<ll>s;
    ll area=0;
    ll top_area=0;
    ll top=0;
    ll i=0;
    for(;i<n;)
    {
        if( s.empty() || arr[s.top()]<=arr[i] )
        s.push(i++);

        else
        {
            top=s.top();
            s.pop();
            top_area=arr[top]*(s.empty()?i:i-s.top()-1);

            if(area<top_area)
                area=top_area;
        }
    }
     while(s.empty()==false)
    {
        top=s.top();
        s.pop();
        top_area=arr[top]*(s.empty()?i:i-s.top()-1);

        if(area<top_area)
            area=top_area;
    }
    return area;
}
