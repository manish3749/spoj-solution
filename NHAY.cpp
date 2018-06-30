#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 100000
void LPS(string pat,ll m,vector<ll>&lps);
void KMP(string pat,string txt);

int main()
{
    ll t;
    while(cin>>t)
    {
        string txt;
        string pat;
        cin>>pat;
        cin>>txt;
        KMP(pat,txt);
        cout<<endl;
    }
}

void KMP(string pat,string txt)
{
    ll m=pat.length();
    ll n=txt.length();

    vector<ll>lps(m);
    ll j=0;
    LPS(pat,m,lps);

    ll i=0;
    while(i<n)
    {
        if(txt[i]==pat[j])
        {
            i++;
            j++;
        }
        if(j==m)
        {
            cout<<i-j<<endl;
            j=lps[j-1];
        }
        else if(i<n&&txt[i]!=pat[j])
        {
            if(j!=0)
                j=lps[j-1];
            else
                i++;
        }
    }
}

void LPS(string pat,ll m,vector<ll>&lps)
{
    ll len=0;
    ll i;

    lps[0]=0;
    i=1;

    while(i<m)
    {
        if(pat[i]==pat[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len!=0)
                len=lps[len-1];
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }
}
