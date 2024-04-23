#include<stdio.h>
#include<stdlib.h>


int main()
{
    int a,b,c;
    scanf("%d%d",&a,&b);
    while(a % b)
    {
        c = a % b;
        a = b;
        b = c;
    }
    printf("gcd(a,b) = %d",b);
    system("pause");
    return 0;
}                