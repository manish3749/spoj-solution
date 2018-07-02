#include<iostream>
using namespace std;
#include<math.h>
int PRIME(long long int);
long long int i,j;
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int m,n;
        cin>>m>>n;
        for(long long int i=m;i<=n;i++)
        {
            if(PRIME(i))
            {
                cout<<i<<endl;
            }
        }
        cout<<endl;
    }
}

int PRIME(long long int n)
{
    int flag=1;
    if(n==1)
        return 0;
    if(n==2)
        return 1;
    if(n%2==0)
        return 0;
    for(long long int i=3;i<=sqrt(n);i+=2)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}
