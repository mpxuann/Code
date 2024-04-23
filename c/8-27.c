#include <stdio.h>
#include<stdlib.h>

double hanoi(double i)
{
    if(i>1)
    {
        i--;
        return 2*hanoi(i)+1;
    }
    else
        return 1;
}

int main()
{
    double i,j;
    scanf("%lf",&i);
    j = hanoi(i);
    printf("%lf\n",j);
    system("pause");
    return 0;
}