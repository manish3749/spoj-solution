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
char str[201][201];
int main()
{
    while(1){
        int c,r;
        si(c);
        if(c==0) break;
        else{
                string s;
                cin>>s;
                int l=s.length();
                r=l/c;
                int k=0;
                for(int i=0;i<r+1;i++)
                {
                    for(int j=0;j<c;j++)
                    {
                        if(k<l)
                            str[j][i]=s[k++];
                        else
                            str[j][i]='0';
                    }
                    i++;
                    if(i<r+1){
                        for(int j=c-1;j>=0;j--)
                        {
                            if(k<l)
                                str[j][i]=s[k++];
                            else
                                str[j][i]='0';
                        }
                    }
                }
            }
            for(int i=0;i<c;i++){
                for(int j=0;j<r+1;j++)
                    if(str[i][j]!='0')
                        cout<<str[i][j];
            }
            cout<<endl;
        }
}

