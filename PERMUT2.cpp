#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    while(1)
    {
        int n;
        cin>>n;
        if(n==0)
            break;
        else
        {
            int arr[n+1];
            for(int i=1;i<n+1;i++)
                cin>>arr[i];
            int rvr[n];
            arr[0]=rvr[0]=0;
            for(int i=1;i<n+1;i++)
                rvr[arr[i]]=i;

            int flag=1;
            for(int i=1;i<n+1;i++)
            {
                if(arr[i]!=rvr[i])
                {
                    flag=0;
                    break;
                }
            }
            (flag)?cout<<"ambiguous":cout<<"not ambiguous";
            cout<<endl;
        }
    }
}
