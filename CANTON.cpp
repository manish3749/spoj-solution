#include<iostream>
using namespace std;
#define ll long long int
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        ll nr;
        cin>>n;
        ll ctr=1;
        ll i;
        for(i=1;i<=n;i+=ctr)
        {
            ctr+=4;
        }
        i-=ctr;
        if(i==n)
            nr=1;
        else
        {
            ll var=(ctr+1)/2;
            ll j=1;
            while((i!=n)&&(j<=var))
            {
                i++;
                j++;
            }
            if(i==n)
                nr=j-1;
            else
            {
                while(i!=n)
                {
                    i++;
                    j--;
                }
                nr=j-1;
            }
        }
        ctr=-1;
        ll dr;
        ll k;
        for(k=0;k<=n;k+=ctr)
        {
            ctr+=4;
        }
        k-=ctr;

        if(k==n)
            dr=1;
        else
        {
            ll var=(ctr+1)/2;
            ll j=1;
            while((k!=n)&&(j<=var))
            {
                k++;
                j++;
            }
            if(k==n)
                dr=j-1;
            else
            {
                while(k!=n)
                {
                    k++;
                    j--;
                }
                dr=j-1;
            }
        }
        cout<<"TERM"<<" "<<n<<" "<<"IS"<<" "<<nr<<"/"<<dr<<endl;
    }
}
