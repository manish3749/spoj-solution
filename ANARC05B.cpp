#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    while(1)
    {
        int m;
        cin>>m;
        if(m==0)
            break;
        else
        {
            vector<int>v1(m);
            vector<int>v;
            int n;
            for(int i=0;i<m;i++)
                cin>>v1[i];
            cin>>n;
            vector<int>v2(n);
            for(int i=0;i<n;i++)
                cin>>v2[i];
 
            for(int i=0;i<m;i++)
            {
                if(binary_search(v2.begin(),v2.end(),v1[i]))
                    v.push_back(v1[i]);
            }
            ll sum=0,sum1=0,sum2=0;
            int i=0,j=0,k=0;
            while(i<m && j<n && k<v.size())
            {
                sum1=0,sum2=0;
                while(v1[i]!=v[k])
                {
                    sum1+=v1[i];
                    i++;
                }
                while(v2[j]!=v[k])
                {
                    sum2+=v2[j];
                    j++;
                }
                sum+=v[k]+max(sum1,sum2);
                i++;
                j++;
                k++;
            }
            sum1=0,sum2=0;
            while(i<m)
                sum1+=v1[i++];
            while(j<n)
                sum2+=v2[j++];
 
            sum=sum+max(sum1,sum2);
            cout<<sum<<endl;
 
        }
    }
}
