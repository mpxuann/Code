#include<stdio.h>
#include<stdlib.h>
int main()
{
    // int a[5][5] = {1};
    // int *pa = a;
    // printf("a = %p\n*a = %d\n",pa,*pa);
    // printf("a[0] = %p\n",a[0]);
    
    // char ccolor[][7] = {"red","yellow","blue","green","black"};
    // printf("ccolor[0] = %s\n",ccolor[0]);
    
    // printf("ccolor[0] = %p\n",ccolor[0]);
    // printf("ccolor[0][1] = %c\n",ccolor[0][1]);
    // char *pcolor;
    // pcolor = ccolor;
    // printf("pcolor = %p\n*pcolor = %c\nccolor = %p\n",pcolor,*pcolor,ccolor);
    //  char *pc[7] = {"red","yellow","blue","green","black"};
    // // scanf("%s",ccolor[1]);
    // // printf("%s",ccolor[1]);
    // printf("&pc = %p\n",&pc);
    // printf("pc = %p\n",pc);
    // printf("&(*pc) = %p\n",&(*pc));
    // printf("*pc = %p\n",*pc);
    // printf("pc[0] = %p\n",pc[0]);
    // printf("**pc = %c\n",**pc);
    // printf("**(pc+2) = %c\n",**(pc+2));
    int a[5][5]= {{1,2,3,4,5},{2,3,4,5,6},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
    
    int (*row)[5] = a[1];
    printf("*row = %p;\n",*row);
    printf("&row = %p\n",&row);
    printf("(long)(row+1)-(long)row = %ld\n",(long)(row+1)-(long)row);
    printf("(row+1)-row = %d\n",(row+1)-row);
    printf("row+1 = %p\n",row+1);
    printf("row = %p\n",row);
    printf("a[1] = %p\n",a[1]);
    printf("*a[1] = %d\n",*a[1]);
    // sign()
    // int a=5,b=6;
    // a= a^b;
    // b= a^b;
    // a= a^b;
    // printf("%d %d ",a,b);
    system("pause");

    return 0;

}