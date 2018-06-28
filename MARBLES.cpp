#include<iostream>
using namespace std;
long long int C(long long int n, long long int r);
int main()
{
    int t;
    cin>>t;
    while(t--){
    signed long long  int n,k,fact;
    cin>>n>>k;
    fact=C(n-1,n-k);
    cout<<fact<<endl;}
}
long long int C(long long int n, long long int r)
{
    if(r > n / 2) r = n - r; // because C(n, r) == C(n, n - r)
    long long int ans = 1;
    long long int i;

    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }
    return ans;
}
