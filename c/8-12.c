#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char arr[20];
    system("shutdown -s -t 60");
again:    
    printf("你的电脑将在一分钟后关机，请输入“毛沛炫老年痴呆”来取消\n请输入：");    
    scanf("%s",arr);
    if(strcmp(arr,"毛沛炫老年痴呆") == 0)
    {
        printf("关机已取消");
        system("shutdown -a");
    }
    else 
    {
        printf("输入错误\n");
        goto again;
    }
    return 0;
}