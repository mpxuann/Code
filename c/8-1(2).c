#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
int main()        //�������ձȽ��ַ����ķ������������ǻ���������ȽϷ�����QQ����xs
{                 //strcmp(string1,string2)==0 => string1 ��string2���
    int i,j;
    char a;
    char arr[]="mpx20030911",key[50];
    char arrey[50]="";
    printf("���������룺");
    scanf("%s",key);
    for(i=0; i<3; i++)
    {
        system("cls");
        printf("��ȷ������(�㻹��%d�λ���):",3-i);
        scanf("%s",arrey);
        if(strcmp(arrey,key)==0)
            {
                printf("������ȷ\n");
                break;
            }
        else if (i<=1)
            {
                printf("�����������������");
                Sleep(1000);
            }

    }
    if(i==3)
    printf("����������˳�ϵͳ\n");
    system("pause");
    return 0;
}