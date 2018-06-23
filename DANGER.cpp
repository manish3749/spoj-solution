#include<iostream>
using namespace std;
#include<string>
#include<math.h>
#define MAX 100000
#define ll long long int
int main()
{
    while(1){
    string str;
    string strf="00e0";
    cin>>str;
    if(str==strf)break;
    else
    {
        int arr[3];
        arr[0]=str[0]-48;
        arr[1]=str[1]-48;
        arr[2]=str[3]-48;
        ll n=0;
        n=arr[1]+10*arr[0];
        for(int i=1;i<=arr[2];i++)
            n*=10;

        if(n==1)
            cout<<"1"<<endl;
        else
        {
            ll var=2;
            ll flag=1;
            while(var<=n)
                var=pow(2,++flag);
            if(var==n)
                cout<<"1"<<endl;
            else
            {
                var=pow(2,(flag-1));
                flag=1;
                for(ll i=var;i<n;i++)
                    flag+=2;
                cout<<flag<<endl;
            }
        }
    }
    }

}
