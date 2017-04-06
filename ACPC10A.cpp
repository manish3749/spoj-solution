#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
int main()
{
    while(1)
    {
        ll x,y,z;
        cin>>x>>y>>z;
        if(x==0 && y==0 && z==0)
            break;
        else
        {
            if(y-x == z-y)
                cout<<"AP "<<z+(y-x)<<endl;
            else
                cout<<"GP "<<z*(y/x)<<endl;
        }
    }
