#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back
#define si(x) scanf("%d",&x)
#define pi(x) printf("%d\n",x)
#define sl(x) scanf("%lld",&x)
#define pl(x) printf("%lld\n",x)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pis pair<string,int>
#define F first
#define S second
#define M 1000000007
#define N 100002

int main()
{
    int t;
    si(t);
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int a[40],cnt[8];;
        for(int i=0;i<40;i++){
            if(s[i]=='T') a[i]=0;
            else a[i]=1;
        }
        for(int i=0;i<8;i++) cnt[i]=0;
        int b1=a[0],b2=a[1],b3=a[2];
        int var=b1*4+b2*2+b3*1;
        cnt[var]++;
        for(int i=3;i<40;i++){
            b1=b2,b2=b3,b3=a[i];
            var=b1*4+b2*2+b3*1;
            cnt[var]++;
        }
        cout<<n<<" ";
        for(int i=0;i<=7;i++) cout<<cnt[i]<<" ";
        cout<<endl;

    }
}
