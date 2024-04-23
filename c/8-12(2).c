#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
void game()
{
    int a;
    int b;
    a = rand()%100 + 1;
   
    printf("数字为1-100之间的整数已生成\n",a);
    while (1)
    {
        printf("你的猜测：");
        scanf("%d",&b);
        if(b < a)
            printf("猜小了\n");
        else if (b > a)
            printf("猜大了\n");
        else
            {
                printf("猜中了，就是%d\n",a);
                break;
            }  
    }
      
   
}
void menu()
{
    printf("欢迎来到猜数字游戏\n");
    printf("请输入数字来选择：1.开始游戏  0.退出游戏\n");
    printf("请选择：");
}
int main()
{
    int choice;
    srand((int)time(NULL));
    do 
    {
        menu();
        scanf("%d",&choice);
        switch (choice)
        {
            case 0:
                printf("quiting...\n");
                Sleep(1000);
                break;
            case 1:
                printf("游戏开始\n");
                game();
                break;
            default:
                printf("输入错误，请重新输入");
        }
    }
    while(choice);
    
    return 0;
}


