#include<bits/stdc++.h>
using namespace std;

void printArray (vector<int>&v,int n);
int AreAll9s (vector<int>&v,int n );

void generateNextPalindromeUtil (vector<int>&v,int n )
{
    int mid = n/2;
    bool leftsmaller = false;
    int i = mid - 1;
    int j = (n % 2)? mid + 1 : mid;
    while (i >= 0 && v[i] == v[j])
        i--,j++;
    if ( i < 0 || v[i] < v[j])
        leftsmaller = true;
    while (i >= 0)
    {
        v[j]=v[i];
        j++;
        i--;
    }
    if (leftsmaller == true)
    {
        int carry=1;
        i=mid-1;
        if (n%2 == 1)
        {
            v[mid] += carry;
            carry=v[mid] / 10;
            v[mid] %= 10;
            j=mid+1;
        }
        else
            j=mid;
        while (i >= 0)
        {
            v[i]+=carry;
            carry=v[i] / 10;
            v[i]%=10;
            v[j++]=v[i--];
        }
    }
}
void generateNextPalindrome(vector<int>&v,int n )
{
    int i;

    if( AreAll9s(v,n) )
    {
        cout<<"1";
        for( i = 1; i < n; i++ )
            cout<<"0";
        cout<<"1"<<endl;
    }
    else
    {
        generateNextPalindromeUtil (v, n );
        printArray (v,n);
    }
}

int AreAll9s(vector<int>&v,int n )
{
    int i;
    for( i = 0; i < n; ++i )
        if(v[i] != 9 )
            return 0;
    return 1;
}

void printArray(vector<int>&v,int n)
{
    int i;
    for (i=0; i < n; i++)
        cout<<v[i];
    cout<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        int l=str.length();
        vector<int>v;
        for(int it=0; it<l; it++)
            v.push_back(str[it]-48);
        l=v.size();

        generateNextPalindrome(v,l);

    }
}
