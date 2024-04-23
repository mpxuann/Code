#include<stdio.h>
#include<stdlib.h>
float v1 = 20.0;
float v2 = 15.0;
float v3 = 5.0;
int main()
{
    int i,w,x,line;
    int a1,a2,a3;
    float t0,t1,t2,t3;
    float T1,T2,T3;
    t0 = 0.66;
    printf("canteen serial number:");
    scanf("%d",&i);//input the serial number
    printf("windows number:");
    scanf("%d",&w);//input windows' number
    printf("the distance:");
    scanf("%d",&x);//input distance
    printf("a1=");
    scanf("%d",&a1);
    printf("a2=");
    scanf("%d",&a2);
    printf("a3=");
    scanf("%d",&a3);
    t1 = x / v1;
    t2 = x / v2;
    t3 = x / v3;
    T1 = t1 + (a1*t0)/w;
    if(t2>=T1)
    {
        T2 = t2 + (a2*t0)/w;
        if(t3>=T2)
        {
            T3 = t3 + a3*t0/w;
        }
        else
        {
            T3 = t2 + (a3+a2)*t0/w;
        }
    }
    else 
    {
        T2 = t1 + (a1+a2)*t0/w;
        if(t3>=T2)
        {
            T3 = t3 + a3*t0/w;
        }
        else
        {
            T3 = t1 + (a3+a2+a1)*t0/w;
        }
    }
    printf("the total time is %.2f minutes\n",T3);
    system("pause");
    return 0;
}
