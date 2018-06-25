#include<bits/stdc++.h>
using namespace std;
int main()
{
    while(1)
    {
        int high,low;
        cin>>high>>low;
        if(high==-1&&low==-1)
            break;
        else if(high==0&&low==0)
            cout<<"0"<<endl;
        else
        {
            int maxx=max(high,low);
            int minn=min(high,low);
            if(maxx==minn)
                cout<<"1"<<endl;
            else if((maxx==0)&&(minn!=0))
                cout<<minn<<endl;
            else if((maxx!=0)&&(minn==0))
                cout<<maxx<<endl;
            else if((maxx%(minn+1))==0)
            {
                cout<<maxx/(minn+1)<<endl;
            }
            else
                cout<<(maxx/(minn+1))+1<<endl;
        }
    }
}
