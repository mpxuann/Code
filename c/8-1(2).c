#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
int main()        //请我掌握比较字符串的方法，并且这是基本的密码比较方法，QQ不是xs
{                 //strcmp(string1,string2)==0 => string1 和string2相等
    int i,j;
    char a;
    char arr[]="mpx20030911",key[50];
    char arrey[50]="";
    printf("请输入密码：");
    scanf("%s",key);
    for(i=0; i<3; i++)
    {
        system("cls");
        printf("请确认密码(你还有%d次机会):",3-i);
        scanf("%s",arrey);
        if(strcmp(arrey,key)==0)
            {
                printf("密码正确\n");
                break;
            }
        else if (i<=1)
            {
                printf("密码错误，请重新输入");
                Sleep(1000);
            }

    }
    if(i==3)
    printf("密码错误，请退出系统\n");
    system("pause");
    return 0;
}