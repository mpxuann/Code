#include<stdio.h>
#include<stdlib.h>
int f(int x,int y)
{
    return x > y;
}
int g(int x,int y)
{
    return x < y;
}
int (*com[])(int,int) ={f,g}; 
int compare(int x,int y,int* pfun(int,int))
{
    return (*pfun)(x,y);//pfun(x,y)也是同样的报错？
}
void Bubble(int* start,int n,int k)
{
    int j,i;
    for(j = 0;j<(n-1);j++)
    {
        for(i = 0;i<(n-1-j);i++)
        {
            if(compare(*(start+i),*(start+i+1),/*(void*)*/com[k-1])) //为什么这里加上void*转换之后就没有报错了？
            {
                *(start+i) = *(start+i)^*(start+i+1);
                *(start+i+1) = *(start+i)^*(start+i+1);
                *(start+i) = *(start+i)^*(start+i+1);

            }
        }
    }
}
int main()
{
    int n,i;
    int* sequence;
    printf("input the number of your sequence: ");
    scanf("%d",&n);
    if((sequence = (int*)malloc((n)*sizeof(int)))==NULL)
    {
        printf("memory allocation failed");
        exit(1);
    }
    printf("input your sequence: ");
    int* origin = sequence;
    for(i  = 0;i<n;i++)
    {
        scanf("%d",sequence);
        sequence++;
    }
    printf("1.Ascending 2.Descending: ");
    int k;
    scanf("%d",&k);
    Bubble(origin,n,k);
    printf("sequence after BUBBLE:\n");
    for(i = 0;i<n;i++)
    {
        if(!i)
            printf("%d",*origin++);
        else 
            printf(" %d",*origin++);

    }
    system("pause");
    return 0;
}
