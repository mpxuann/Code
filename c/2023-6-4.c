// #include<stdio.h>
// int main(void)
// {
//       int x[5] = { 2, 4, 6, 8, 10 }, *p, **pp;

//       p = x;
//       pp = &p;
//       printf("%d ", *(p++));  /* 数字后有一个空格 */
//       printf("%d\n", **pp);
//     system("pause");
//       return 0;
// }
// #include<stdio.h>
// int main(void)
// {
//       int i, a[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 }, *p[4];

//       for (i = 0; i < 4; i++){
//            p[i] = &a[i*3];
//       }
//       printf("%d\n", p[3][2]);
//     system("pause");
//       return 0;
// }
// #include<stdio.h>
// #include<string.h>
// int main(void)
// {
//    int i;
//    const char *color[2] = {"blue", "green"}; 
   
//    for(i = 0; i < 2; i++) {
//       printf("%s %c\n", color[i], *color[i]);  /* 输出数据之间间隔一个空格 */ 
//    }   
//    for(i = 0; i < 2; i++) {
//       printf("%s %c\n", color[i]+1, *color[i]+1); /* 输出数据之间间隔一个空格 */ 
//    }   
//     system("pause");
//    return 0;
// }
// #include<stdio.h>
// int main(void)
// {
//    int i, flag = 0;
//    char ch;
//    const char *color[2] = {"blue", "green"};
//    const char **pc; 

//    pc = color; 
//    for(i = 0; i < 2; i++) {
//      printf("%s %c\n", *(pc+i), **(pc+i));      /* 输出数据之间间隔一个空格 */
//    }   
       
//    for(i = 0; i < 2; i++) {
//      printf("%s %c\n", *(pc+i)+1, **(pc+i)+1);   /* 输出数据之间间隔一个空格 */
//    }   
//     system("pause");
//    return 0;
// }
// 
// #include <stdio.h>
// #include <string.h>
// char *fun ( char *t );
 
// int main(void) 
// { 
//     char  *str = "abcdefgh"; 
    
//     str = fun ( str ); 
//     puts ( str );     
//     system("pause");
//     return 0; 
// }

// char *fun ( char *t ) 
// { 
//     char *p = t; 
    
//     return ( p + strlen(t)/2 ); 
// } 
// #include <stdio.h>
// int main()
// {
//     static int a[4][4];
// int *p[4], i, j;

// for(i = 0; i < 4; i++){
//     p[i] = &a[i][0];
// }
// for(i = 0 ; i < 4 ; i++) {
//     *(p[i] + i) = 1 ;
//     *(p[i] + 4 - (i + 1)) = 1;
// }
// for(i = 0; i < 4; i++){
//     for(j = 0; j < 4; j++){
//        printf("%d", p[i][j]);
//     }
//     printf("\n");
// }
//     system("pause");
//     return 0;
// }
#include<stdio.h>
int main(void)
{
   int i, flag = 0;
   char ch;
   const char *a[5] = {"red", "blue", "yellow", "green", "black" };    

   ch = getchar();
   for(i = 0; i < 5; i++) {
        if(ch==*a[i]){
           flag = 1;
           puts(a[i]);
        }
   }
   if(flag == 0) 
   {
         printf("Not Found\n"); 
   }
system("pause");
   return 0;
}
