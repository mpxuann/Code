#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i=0,j=0;
    int a,c=0;
    int b = 1;
    scanf("%d",&a);
    if (a==0)
        printf("1\n");

    else
    {
        for ( i = 0; i < a; i++)
        {
            b = 1;
            for (j = 0;j < i+1;j++)
            {
                b = b * (j+1);
            }
            c = c + b;
        }
    }
    printf("%d\n",c);
    system("pause");
    return 0;
}