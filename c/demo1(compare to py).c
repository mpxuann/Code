#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a,b;
    float c;
    printf("he first num is: ");
    scanf("%d",&a);
    printf("he second num is: ");
    scanf("%d",&b);
    c = a+b;
    printf("The average number is : %.6f\n",c);
    printf("The average number is : %.3f\n",c);
    printf("The average number is : %.1f\n",c);
    system("pause");
    return 0;
}