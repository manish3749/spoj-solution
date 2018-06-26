#include<stdio.h>
#include<math.h>

int main()
{
    while(1)
    {
        float n;
        scanf("%f",&n);
        if(n==0.00)
            break;
        else
        {
            float sum=0;
            float var=2.00;
            int ctr=0;
            while(sum<n)
            {
                sum=sum+(1.00/var);
                var++;
                ctr++;
            }
            printf("%d card(s)\n",ctr);
        }
    }
}
