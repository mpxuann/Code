#include<stdlib.h>
#include<stdio.h>
#include<time.h>
int flag = 0;
void instruction(int* n, int *x)
{
    printf("number : ");
    scanf("%d",n);
    printf("range : ");
    scanf("%d",x);
}
void start()
{
    printf("Welcome to \"Random Sequence Builder\"\n");
    printf("______________________________________\n");
    printf("\n");
}
void command()
{
    if(!flag)
    {
        flag = 1;
        printf("1.generate random sequence || 2.exit: ");
    }
    else
        printf("1.continue || 2.exit: ");
}
void work(int* j,int* n,int* x)
{
       
    if(*j == 1)
    {
        instruction(n,x);
        for(int i = 0;i<*n;i++)
        {
            if(!i)
                printf("%d",rand()%(*x));
            else
                printf(" %d", rand()%(*x));
        }
        printf("\n\n");
    }
    else
    {
            printf("error\n\n");
    }
}

int main()
{
    start();
    srand(time(NULL));
    int n,x,j;
    while(1)
    {
        command();
        scanf("%d",&j);
        if(j == 2)
        {
            printf("exit successfully\n");
            break;
        }
        else 
            work(&j,&n,&x);
    }
    system("pause");
    return 0;
}