#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
int arr[MAX];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        vector<string>acnt;
        int n;
        cin>>n;
        cin.ignore();
        for(int i=0;i<n;i++)
        {
            string str;
            getline(cin,str);
            acnt.push_back(str);
        }
        sort(acnt.begin(),acnt.end());

        vector<string>v;
        for(int i=0;i<acnt.size()-1;i++)
        {
            if(acnt[i]!=acnt[i+1])
                v.push_back(acnt[i]);
        }
        int as=acnt.size();
        int vs=v.size();
        for(int i=0;i<vs;i++)
            arr[i]=0;

            v.push_back(acnt[as-1]);

        int j=0,i=0,k=0;
        while(i<as&&j<as)
        {
            while(acnt[i]==acnt[j])
            {
                arr[k]++;
                j++;
                if(j==as)
                    break;
            }
            i=j;
            k++;
        }
        cout<<endl;
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<" "<<arr[i]<<endl;
        }
    }
}

