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
   
    printf("����Ϊ1-100֮�������������\n",a);
    while (1)
    {
        printf("��Ĳ²⣺");
        scanf("%d",&b);
        if(b < a)
            printf("��С��\n");
        else if (b > a)
            printf("�´���\n");
        else
            {
                printf("�����ˣ�����%d\n",a);
                break;
            }  
    }
      
   
}
void menu()
{
    printf("��ӭ������������Ϸ\n");
    printf("������������ѡ��1.��ʼ��Ϸ  0.�˳���Ϸ\n");
    printf("��ѡ��");
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
                printf("��Ϸ��ʼ\n");
                game();
                break;
            default:
                printf("�����������������");
        }
    }
    while(choice);
    
    return 0;
}


