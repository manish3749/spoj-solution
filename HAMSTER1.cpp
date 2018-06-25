#include<bits/stdc++.h>
using namespace std;
double v,k1,k2;
double f(double theta)
{
   double points=((double)v*v)/10.0*(k1*sin(2.0*theta)+k2*sin(theta)*sin(theta)/2.0);
   return points;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>v>>k1>>k2;
        double t1=0,t2=3.14159265/2,mid=(t1+t2)/2.0;
        while(fabs(t1-t2)>=0.00005){
            mid=(t1+t2)/2.0;
            if(f(t1) > f(t2)) t2=mid;
            else t1=mid;
        }
        cout<<fixed<<setprecision(3)<<t1<<" "<<f(t1)<<endl;
    }
}
