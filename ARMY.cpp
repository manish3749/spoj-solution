#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 10000
 
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        cout<<endl;
        ll g,m;
        cin>>g>>m;
        vector<int>gv(g);
        vector<int>mv(m);
        for(int i=0;i<g;i++)
            cin>>gv[i];
        for(int i=0;i<m;i++)
            cin>>mv[i];
        ll x=0,y=0;
        while(x<g&&y<m)
        {
            if(gv[x]>=mv[y])
                y++;
            else
                x++;
        }
        if(x==g)
            cout<<"MechaGodzilla"<<endl;
        else
            cout<<"Godzilla"<<endl;
    }
}
