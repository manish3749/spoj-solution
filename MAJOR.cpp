#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int arr[n];

        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);

        sort(arr,arr+n);

        int ctr=1;
        int i=0;
        for(;i<n-1;i++)
        {
            if(arr[i]==arr[i+1])
                ctr++;
            else
                ctr=1;
            if(ctr>n/2)
                break;
        }
        if(ctr>n/2)
            printf("YES %d\n",arr[i]);
        else
            printf("NO\n");
    }
}
