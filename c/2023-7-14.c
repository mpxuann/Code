#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void windows_cmd_support_utf8(void)
{
#ifdef WIN32
    system("chcp 65001 & cls"); 
#endif
}

struct student
{
    int num;
    char name[20];
    int gradePoint;
    struct student *next;
};

void start()
{
    puts("1.创建链表(以学号0结束)");
    puts("2.插入成绩(输入方式同1)");
    puts("3.修改成绩(输入序号及修改后成绩)");
    puts("4.删除成绩(输入序号)");
    puts("5.打印成绩");
    puts("0.退出");
    printf("你的操作是: ");
}

struct student* insert(struct student* head)
{
    struct student *ptr = head,*p = NULL;
    int num,grade;
    char name[20];
    scanf("%d",&num);
    while(num!=0)
    {
        scanf("%s%d",&name,&grade);
        p = (struct student*)malloc(sizeof(struct student));
        p->num = num;
        strcpy(p->name,name);
        p->gradePoint = grade;
        p->next = NULL;
        if(head == NULL)
        {
            head = p;
            head->next = NULL;
        }
        else
        {
            while(ptr->next!=NULL)
                if(ptr->next->num<p->num)
                    ptr = ptr->next;
                else break;
            if(ptr->next==NULL)
                ptr->next = p;
            else
            {
                p->next = ptr->next;
                ptr->next = p;
            }
            
        }
        ptr = head;
        scanf("%d",&num);
    }
    return head;
}

struct student* revise(struct student* head)
{
    int n,grade;
    printf("请输入序号和成绩：");
    scanf("%d%d",&n,&grade);
    struct student* ptr;
    ptr = head;
    if(ptr == NULL)
        printf("无学生信息");
    else
        while (ptr->num!=n&&ptr->next!=NULL)
            ptr = ptr->next;
    if(ptr->num!=n&&ptr->next==NULL)
        puts("未找到学生信息");
    else
    {
        ptr->gradePoint = grade;
        puts("修改成功：");
        printf("%-4d%-5s%d\n",ptr->num,ptr->name,ptr->gradePoint);
        putchar('\n');
    }
    return head;
} 

void print(struct student* head)
{
    struct student* str;
    str = head;
    if(head == NULL)
        puts("无学生信息");
    else
        while (str->next!=NULL)
        {
            printf("%-4d%s%d\n",str->num,str->name,str->gradePoint);
            str = str->next;
        }
    printf("%-4d%s%d\n",str->num,str->name,str->gradePoint);
    putchar('\n');
}

struct student* _delete__(struct student *head)
{
    int num;
    struct student *ptr,*temp;
    printf("请输入序号：");
    scanf("%d",&num);
    ptr = head;
    if(ptr == NULL)
    {
        puts("无学生信息");
        return NULL;
    }
    else if(ptr->num == num)
    {
        puts("删除成功");
        return ptr->next;
    }
    else
        while (ptr->next!=NULL && ptr->next->num!=num)
            ptr = ptr->next;
    if(ptr->next==NULL)
    {
        printf("未找到学生信息\n");
        return head;
    }
    else 
    {
        temp = ptr->next;
        ptr->next = ptr->next->next;
        free(temp);
        puts("删除成功");
        return head;
    }
}

void main()
{
    windows_cmd_support_utf8();
    struct student *head = NULL;
    start();
    int n;
    scanf("%d",&n);
    while(n!= 0)
    {
        switch (n)
        {
        case 1:
        case 2:
            head = insert(head);
            puts("输入完成");
            break;
        case 3:
            head = revise(head);
            break;
        case 4:
            head = _delete__(head);
            break;
        case 5:
            print(head);
            break;
        }
        putchar('\n');
        start();
        scanf("%d",&n);
    }
    if(!n)
        puts("成功退出");
    system("pause");
}