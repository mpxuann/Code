#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// int f(int x,int y)
// {
//     return x+y;
// }
// int g(int x,int y)
// {
//     return x - y;
// }


#include <stdlib.h>
#include<stdio.h>

/* windows 控制台支持显示 utf8 编码的中文字符 */
void windows_cmd_support_utf8(void)
{
#ifdef WIN32
    system("chcp 936"); //cls 用来清除 chcp 的输出
#endif
}


int main()
{
    windows_cmd_support_utf8();
    // int (*arr[])(int,int) = {f,g};
    // int x = 3,y = 5,result;
    // result = (*(arr[1]))(x,y);
    // printf("%d\n",result);
    // printf("%p\n",arr[0]);
    // printf("%p\n",arr);
    char subject[40];
    gets(subject);
    puts("Z哦那个文化");
    // scanf("%s",subject);
    puts(subject);
    printf("%s",subject);
    system("pause");
    return 0;
}


