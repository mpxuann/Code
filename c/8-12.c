#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char arr[20];
    system("shutdown -s -t 60");
again:    
    printf("��ĵ��Խ���һ���Ӻ�ػ��������롰ë��������մ�����ȡ��\n�����룺");    
    scanf("%s",arr);
    if(strcmp(arr,"ë��������մ�") == 0)
    {
        printf("�ػ���ȡ��");
        system("shutdown -a");
    }
    else 
    {
        printf("�������\n");
        goto again;
    }
    return 0;
}