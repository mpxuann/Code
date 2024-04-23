#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,i;
    double sum,fact;
    scanf("%d",&n);
    sum = 1;
    fact = 1;
    for(i = 1; i <= n; i++)
    {
        fact *= i;
        sum += 1 / fact;
    }
    printf("%.8f",sum);
    system("pause");
    return 0;
}