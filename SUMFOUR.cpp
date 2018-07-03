#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define N 10000001
int m1[N],m2[N],k,p;

int bsearch(int val)
{
    int first=0,last=k,mid,cnt=0,t=0;

    while(first<=last){
        mid=(first+last)/2;
        if(m2[mid]==val){
            t=mid-1;
            while(m2[mid]==val && mid<k)
                mid++,cnt++;

            while(m2[t]==val && t>=0)
                t--,cnt++;
            return cnt;
        }
        else if(m2[mid]>val)
            last=mid-1;
        else first=mid+1;
    }
    return 0;
}
int main()
{
    int n;
    cin>>n;
    int a[4000],b[4000],c[4000],d[4000];
    for(int i=0;i<n;i++)
        scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);

    p=0,k=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            m1[p]=a[i]+b[j],p++;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            m2[k]=(c[i]+d[j])*-1,k++;
    }
    sort(m1,m1+p);
    sort(m2,m2+k);
    int ansr=0;
    for(int i=0;i<p;){
        int temp=m1[i],cnt=0;
        while(m1[i]==temp && i<p)
            cnt++,i++;
        int siz=bsearch(temp);
        ansr+=(cnt*siz);
    }
    cout<<ansr;
}
