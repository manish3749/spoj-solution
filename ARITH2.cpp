#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back
#define si(x) scanf("%d",&x)
#define pi(x) printf("%d\n",x)
#define s(x) scanf("%I64d",&x)
#define p(x) printf("%I64d\n",x)
#define sc(x) scanf("%s",x)
#define pc(x) printf("%s",x)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define F first
#define S second
#define M 1000000007
#define N 100005
#define inf 2e9
#define PQG priority_queue< int,std::vector<int>,std::greater<int> >
#define PQL priority_queue< int,std::vector<int>,std::less<int> >
#define PQPL priority_queue<pii ,vector< pii >, less< pii > >
#define PQPG priority_queue<pii ,vector< pii >, greater< pii > >
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
 
bool check(char s)
{
    return (s=='+' || s=='-' || s=='*' || s=='/' || s=='=');
}
int main()
{
    int t;
    si(t);
    cin.ignore();
    while(t--){
        ll ans=0;
        string s;
        char ch;
        while(true){
            cin>>ch;
            s.pb(ch);
            if(ch=='=') break;
        }
        //cout<<s<<endl;
        string s1;
        int i=0;
        while(i<s.length() && s[i]==' ') ++i;
        while(i<s.length() && s[i]!=' '){
                if(check(s[i])) break;
                s1.pb(s[i]);
                ++i;
            }
        if(s1!="=") ans=stoll(s1);
        //cout<<ans<<" "<<i<<endl;
        while(i<s.length()){
            //cout<<"i = "<<i<<endl;
            while(i<s.length() && s[i]==' ') ++i;
            char ch;
            if(check(s[i])) ch=s[i],++i;
            //cout<<ch<<" ";
            if(ch=='=' || i==s.length()) break;
            string str;
            while(i<s.length() && s[i]==' ') ++i;
            while(i<s.length() && s[i]!=' '){
                if(check(s[i])) break;
                str.pb(s[i]);
                ++i;
            }
            ll a=stoll(str);
            //cout<<a<<endl;
            if(ch=='+') ans+=a;
            if(ch=='-') ans-=a;
            if(ch=='*') ans*=a;
            if(ch=='/') ans/=a;
        }
        cout<<ans<<endl;
    }
} 
