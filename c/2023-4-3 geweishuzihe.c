#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,sum,j = 0;
    long n;
    scanf("%ld",&n);
    do
    {
        i = n % 10;
        n /= 10;
        sum += i;
        j++;

    } while (n != 0);
    printf("%d %d",j,sum);
    system("pause");
    return 0;
}