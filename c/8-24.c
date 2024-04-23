#include<stdio.h>
#include<stdlib.h>

int stringlength(char* arr)
{
    if (*arr != '\0')
    
        return 1+stringlength(1+arr);
    else
        return 0;
}

int main()
{
    char arr[50];
    int len;
    scanf("%s",arr);
    len = stringlength(arr);
    printf("%d\n",len);
    system("pause");
    return 0;
}