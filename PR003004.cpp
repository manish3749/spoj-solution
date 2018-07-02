#include<bits/stdc++.h>
using namespace std;
long long int sumOfDigitsFrom1ToN(long long int n)
{
    if (n<10)
      return n*(n+1)/2;

    long long int d = log10(n);
     long long int *a = new long long int[d+1];
    a[0] = 0, a[1] = 45;
    for (long long int i=2; i<=d; i++)
        a[i] = a[i-1]*10 + 45*ceil(pow(10,i-1));

    long long int p = ceil(pow(10, d));

    long long int msd = n/p;

    return msd*a[d] + (msd*(msd-1)/2)*p +
           msd*(1+n%p) + sumOfDigitsFrom1ToN(n%p);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n1,n2;
        cin>>n1>>n2;
        long long int sum1,sum2;
        sum2=sumOfDigitsFrom1ToN(n2);
        sum1=sumOfDigitsFrom1ToN(n1-1);
        cout<<sum2-sum1<<endl;
    }
}
