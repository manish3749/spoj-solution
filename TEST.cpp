#include<iostream>
using namespace std;

int main()
{
    int flag=1;
    while(flag)
    {
        int n;
        cin>>n;
        if(n==42)
            flag=0;
        else
            cout<<n<<endl;
    }
    return 0;
}

