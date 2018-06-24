#include<iostream>
using namespace std;
#define ll long long int
#define MAX 100
void MULTIPLY(int* arr1,int* arr2,int l1,int l2);
void SUMM(int* arr1,int* arr2,int l1,int l2);

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m=-1;
        cin>>n;
        if(n==1)
            cout<<"192";
        else{
        n--;
        int arr1[3],arr2[MAX];
        arr1[2]=0,arr1[1]=5,arr1[0]=2;
        while(n!=0)
        {
            arr2[++m]=n%10;
            n/=10;
        }
        for(int i=0;i<=m/2;i++)
        {
            int t=arr2[i];
            arr2[i]=arr2[m-i];
            arr2[m-i]=t;
        }
        int l1=3;
        int l2=m+1;
        MULTIPLY(arr1,arr2,l1,l2);}
        cout<<endl;
    }

}

void MULTIPLY(int* arr1,int* arr2,int l1,int l2)
{
    int k=l1+l2;
    int arr[k];
    int str[k][k];
    int row=0;
    int col=l1+l2;
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<k;j++)
            str[i][j]=0;
    }
    int kc=1;
    for(int i=l2-1;i>=0;i--)
    {
        int carry1=0;
        col=l1+l2-kc;
        for(int j=l1-1;j>=0;j--)
        {
            int prod=arr1[j]*arr2[i]+carry1;
            str[row][col]=prod%10;
            carry1=prod/10;
            col--;
        }
        while(carry1)
        {
             str[row][col--]=carry1%10;
             carry1=carry1/10;
        }
        row++;
        kc++;
    }
    long long int carry=0;
    for(int j=k-1;j>=col;j--)
    {
        long long int sum=0;
        for(int i=0;i<row;i++)
        {
            sum+=str[i][j];
        }
        sum+=carry;
        arr[--k]=sum%10;
        carry=sum/10;
    }
    int ctr=0;
    int prod[MAX];
    int p=0;
    for(int i=k+1;i<l1+l2;i++)
        prod[p++]=arr[i];

    int arr4[3];
    arr4[0]=1,arr4[1]=9,arr4[2]=2;
    SUMM(prod,arr4,p,3);
}

void SUMM(int* arr1,int* arr2,int l1,int l2)
{
    int arr3[MAX];
    l1--;
    l2--;
    int sum=0;
    int carry=0,k=-1;
    while((l1>=0)&&(l2>=0))
    {
        sum=arr1[l1]+arr2[l2]+carry;
        arr3[++k]=sum%10;
        carry=sum/10;
        l1--;
        l2--;
    }
    while(l1>=0)
    {
        sum=arr1[l1]+carry;
        arr3[++k]=sum%10;
        carry=sum/10;
        l1--;
    }
    while(l2>=0)
    {
        sum=arr2[l2]+carry;
        arr3[++k]=sum%10;
        carry=sum/10;
        l2--;
    }
    while(carry)
    {
        arr3[++k]=carry%10;
        carry=carry/10;
    }

    for(int j=k;j>=0;j--)
    {
        cout<<arr3[j];
    }
}
