#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll T[31],F[31];
    T[0]=1;F[0]=0;
    T[1]=0;F[1]=1;
    T[2]=3;F[2]=0;
    for(int i=3;i<=30;i++)
    {
        T[i]=3*T[i-2]+2*F[i-3];
        F[i]=T[i-1]+F[i-2];
    }
    while(1)
    {
        int n;
        cin>>n;
        if(n==-1)
            break;
        else
            cout<<T[n]<<endl;
    }
}
