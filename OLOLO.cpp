#include<bits/stdc++.h>
using namespace std;
int DOUBLE(int*,int);
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("%d\n",DOUBLE(arr,n));
}
int DOUBLE(int arr[],int n)
{
    int XOR=0;
    for(int i=0;i<n;i++)
        XOR^=arr[i];
    return XOR;
}

