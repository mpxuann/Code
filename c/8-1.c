#include<stdio.h>
#include<string.h>
#include<windows.h>

int main()
{
    char arr1[9999],arr2[9999];
    int i,left,right;
    int a;
    left=0;   
    printf("输入想要跳动的ascii字符串：");
    for (i=0;(a = getchar())!='\n';i++)
    {
        arr1[i] = (char) a;
    }
    i--;
    right = i;
    for (;i>=0;i--)
    {
        arr2[i] = '#';
    }
    system("cls");
    printf("%s",arr2);
    Sleep(1000);
    while(left<=right)
    {
        system("cls");
        arr2[left] = arr1[left];
        arr2[right] = arr1[right];
        printf("%s",arr2);
        Sleep(1000);
        left++;
        right--;
    }
    printf("\n");
    system("pause");
    return 0;
}