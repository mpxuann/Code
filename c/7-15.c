#include<stdio.h>
#include<stdlib.h>
int main()
{
    long long a;
    int b,c;
    int i = 0;
    int arr[50];
    printf("????????: ");
    scanf("%d",&a);
    printf("?????????????????????????????");
    scanf("%d",&b);
    printf("%d???????: ",b);
    while (a >= b)
    {
        arr[i] = a % b;
        a /= b;
        i++;
    }
    i--;
    printf("%d",a);
    for(;i>=0;i--)
    {
        if(arr[i] <=9)
        {
            printf("%d",arr[i]);
        }
        else 
            putchar(55+arr[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}