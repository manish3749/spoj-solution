#include<stdio.h>
#define f float
int main()
{
    while(1)
    {
        f l;
        scanf("%f",&l);
        if(l==0)
            break;
        else
        {
            f p=2.0*3.1415926;
            f a=l*l;
            f area=a/p;
            printf("%0.2f\n",area);
        }
    }
}

