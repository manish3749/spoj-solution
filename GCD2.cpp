#include<bits/stdc++.h>
using namespace std;
#define MAX 255;

int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        int a,b=0;
        cin>>a;
        cin>>str;
        if(a==0)
        {
            cout<<str<<endl;
            continue;
        }
        for(int i=0;i<str.length();i++)
        {
            b=(b*10+(str.at(i)-'0'))%a;
        }
        cout<<gcd(a,b)<<endl;
    }
}
