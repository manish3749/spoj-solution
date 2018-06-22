#include<iostream>
using namespace std;
#include<utility>
#include<algorithm>
#define ll long long int
#define MAX 100000
 
bool compare(pair<int, int> p1, pair<int, int> p2);
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        pair<int, int> arr[MAX];
        for(ll i=0;i<n;i++)
            cin>>arr[i].first>>arr[i].second;
 
        sort(arr,(arr+n),compare);
 
        ll ctr=1,endtime;
         endtime= arr[0].second;
        for(ll i=0;i<n;i++)
        {
            if(endtime<=arr[i].first)
            {
                ctr++;
                endtime=arr[i].second;
            }
        }
        cout<<ctr<<endl;
    }
}
 
bool compare(pair<int, int> p1, pair<int, int> p2)
{
       if(p1.second < p2.second)return 1;
       return 0 ;
}
