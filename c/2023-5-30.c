#include<stdio.h>
#include<stdlib.h>
int main(int n,char* a[])
{
    int i;
    for(i = 1;i<n;i++)
    {
        printf("%s",a[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}