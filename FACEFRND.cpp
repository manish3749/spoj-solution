#include<bits/stdc++.h>
using namespace std;
int arr[105][105];
int m=0;

int main()
{
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>arr[i][0]>>arr[i][1];
        for(int j=2;j<=arr[i][1]+1;j++)
        {
            cin>>arr[i][j];
        }
    }

    set<int>s;
    for(int i=0;i<m;i++)
        s.insert(arr[i][0]);

    for(int i=0;i<m;i++)
    {
        for(int j=2;j<=arr[i][1]+1;j++)
        {
            s.insert(arr[i][j]);
        }
    }

    cout<<s.size()-m;
}
