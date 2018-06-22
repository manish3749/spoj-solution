#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 100000
bool HIVE(ll n);
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
            bool ch=HIVE(n);
            (ch)?cout<<"Y"<<endl:cout<<"N"<<endl;
        }
    }
}
 
bool HIVE(ll n)
{
    int DP[MAX];
    DP[0]=0;
    DP[1]=1;
    int k=1;
    while(n>DP[k])
    {
        k++;
        DP[k]=DP[k-1]+6*(k-1);
    }
    if(DP[k]==n)
        return true;
    else
        return false;
}
