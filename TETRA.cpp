#include<bits/stdc++.h>
using namespace std;
double area(double ,double ,double );
int main()
{
        int t;
        scanf("%d",&t);
        while(t--)
        {
        double u,v,w,U,V,W;
        scanf("%lf %lf %lf %lf %lf %lf",&u,&v,&w,&W,&V,&U);
        double vol=0;
        double S=0;
        S+=area(u,V,w);
        S+=area(W,u,v);
        S+=area(W,V,U);
        S+=area(U,v,w);
        vol=sqrt(4*u*u*v*v*w*w- u*u*(v*v+w*w - U*U)*(v*v+w*w-U*U) - v*v*(w*w+u*u - V*V)*(w*w+u*u-V*V) - w*w*(u*u + v*v - W*W)*(u*u+v*v-W*W) + (v*v +w*w - U*U)*(w*w+u*u- V*V)*(u*u+v*v - W*W))/12;
        double ansr=vol*3.0/S;
        cout<<fixed<<setprecision(4)<<ansr<<endl;
        }
        return 0;
}
double area(double a1,double a2,double a3)
{
        double s=(a1+a2+a3)/2.0;
        return sqrt(s*(s-a1)*(s-a2)*(s-a3));
}

