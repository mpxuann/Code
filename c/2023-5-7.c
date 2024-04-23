#include<stdio.h>
#include<stdlib.h>
int main()
{
    struct
    {
        int a; int *b;
    } s[4], *p;
    int i, n = 1;    
    for(i = 0; i < 4; i++)
    {
        s[i].a = n;
        s[i].b = &s[i].a;
        n = n + 2;
    }
    p = &s[0];
    printf("%d\n", ++*p->b);
    p++;
    printf("%d,%d\n", (++p)->a,(p++)->a);  
    system("pause");
    return 0;
}