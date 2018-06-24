#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,t,d;
        cin>>n>>t>>d;
        vector<int>v(n);

        for(int i=0;i<n;i++)
            cin>>v[i];
        sort(v.rbegin(),v.rend());
        int k=0;
        while(t>0 && k<n)
        {
            if(v[k]>d)
            {
                v[k]-=d;
                t--;
            }
            else
                k++;
        }
        if(t==0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
