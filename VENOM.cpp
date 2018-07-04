#include<bits/stdc++.h>
using namespace std;
#define ll long long int

double h,p,a;
double func()
{
    double x=-p+2*a;
    double b=(p-2*a);
    double c=2*(a-h);
    double y=b*b-4*p*c;
    double z=x+sqrt(y);
    return z/(2.0*p);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf%lf",&h,&p,&a);
        if(h<=p){
            cout<<"1\n";
            continue;
        }
        ll ans=ceil(func());
        printf("%lld\n",(2*ans-1));
    }
}
