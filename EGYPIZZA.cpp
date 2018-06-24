#include<bits/stdc++.h>
using namespace std;
#define ld long double

int main()
{
    int n;
    cin>>n;
    float arr[n];
    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;
        if(str=="1/4")
            arr[i]=0.25;
        else if(str=="1/2")
            arr[i]=0.5;
        else
            arr[i]=0.75;
    }

    float ctr1=0,ctr2=0,ctr3=0;

    for(int i=0;i<n;i++)
    {
        if(arr[i]==0.25)
            ctr1++;
        else if(arr[i]==0.5)
            ctr2++;
        else if(arr[i]==0.75)
            ctr3++;
    }
    float ctr=0;

    if(ctr1<ctr3)
        ctr=ceil(ctr2/2)+ctr3;
    else if(ctr1>ctr3)
        ctr=ctr3+ceil((ctr1-ctr3)/4+(ctr2/2));
    else
        ctr=ceil(ctr2/2)+ctr1;
    ctr++;
    cout<<ctr;


}
