#include<stdio.h>
#include<stdlib.h>
long long fib(int n)
{
    int xiao=1;
    int da = 1;
    int dsg = 1;
    for(;n>2;n--)
    {
        dsg = da + xiao;
        xiao = da;
        da = dsg;    
    }
    return dsg;
}
int main()
{
    int i;
    long long fn; 
    scanf("%d",&i);
    fn = fib(i);
    printf("%d",fn);
    system("pause");
    return 0;
}