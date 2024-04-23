#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
    char poem[4][21];
    char mean[20];
    int i;
    for(i = 0;i<4;i++)
    scanf("%s",poem[i]);
    for( i= 0; i< 4; i++ )
    {
        mean[3*i] = (poem[i][0]);
        mean[3*i+ 1] = (poem[i] + 1);
        mean[3*i+2] = (poem[i]+2);
    }
        mean[3*i] = '\0';
        printf("%s", mean);
        printf("\n");
        system("pause");
}
// // #include<stdio.h>
// // #include<stdlib.h>
// // int main()
// // {
// //     int a[4][5] = {0};
// //     a[2][3]= 5;
// //     printf("%d",*(a+2));
// //     system("pause");
// //     return 0;
// // }
// #include <stdio.h>
// #include<stdlib.h>
// char *getmonth( int n )
// {
//     if(n<1||n>13)
//     return NULL;
//     else
//     {
//         switch (n)
//         {
//         case 1:return "January";
//         case 2: return "Febrary";
//         case 3: return "March";
//         case 4:return "April";
//         case 5:return "May";
//         case 6:return "June";
//         case 7:return "July";
//         case 8: return "August";
//         case 9:return "September";
//         case 10:return "October";
//         case 11:return "November";
//         case 12:return "December";
        
        
//         }
//     }
// }
// int main()
// {
//     int n;
//     char *s;
    
//     scanf("%d", &n);
//     s = getmonth(n);
//     if ( s==NULL ) printf("wrong input!\n");
//     else printf("%s\n", s);
//     system("pause");
//     return 0;
// }

// /* 你的代码将被嵌在这里 */
#include<stdlib.h>
// #include <stdio.h>
// #include <string.h>

// #define MAXS 10

// char *str_cat( char *s, char *t )
// {
//     char *s1 = s;
//     while(*s)s++;
//     while(*t)*(s++) = *(t++);
//     return s1;
// }

// int main()
// {
//     char *p;
//     char str1[MAXS+MAXS] = {'\0'}, str2[MAXS] = {'\0'};
    
//     scanf("%s%s", str1, str2);
//     p = str_cat(str1, str2);
//     printf("%s\n%s\n", p, str1);
//     system("pause");
//     return 0;
// }

// /* 你的代码将被嵌在这里 */
// #include <stdio.h>

// #define MAXS 10

// char *match( char *s, char ch1, char ch2 )
// {
    
//     while(*s!=ch1&&*s) s++;
//     char* s1=s;
//     while(*s!=ch2&&*s)
//     printf("%c",*s++);
//     if(*s)
//     printf("%c\n",ch2);
//     else printf("\n");
//     return s1;

// }

// int main()
// {
//     char str[MAXS], ch_start, ch_end, *p;
    
//     scanf("%s\n", str);
//     scanf("%c %c", &ch_start, &ch_end);
//     p = match(str, ch_start, ch_end);
//     printf("%s\n", p);
// //     system("pause");
// //     return 0;
// // }

// // /* 你的代码将被嵌在这里 */
// // #include <stdio.h>
// // #include<string.h>
// // #define MAXS 30

// // char *search(char *s, char *t)
// // {
// //     char* t1 = t;
// //     char* t2;
// //     while(*s)
// //     {
// //         t = t1;
// //     while (*s!=*t&&*s&&*t)
// //     s++;
// //     t2 = s;
// //     if(!(*s)) return NULL;
// //     else
// //     {
// //         while (*s&&*t)
// //         {
// //             if(*s==*t)
// //             {
// //                 s++;
// //                 t++;
// //             }
// //             else 
// //                 break;
// //         }
// //         if(!(*t)) return t2;
        
// //     }
// //     }
// //     return NULL;
// // }
// // // void ReadString( char s[] ); /* 裁判提供，细节不表 */

// // int main()
// // {
// //     char s[MAXS], t[MAXS], *pos;
    
// //     gets(s);
// //     gets(t);
// //     pos = search(s, t);
// //     if ( pos != NULL )
// //         printf("%d\n", pos - s);
// //     else
// //         printf("-1\n");
// //     system("pause");
// //     return 0;
// // }

// // /* 你的代码将被嵌在这里 */
// // #include <stdio.h>
// // #include <string.h>
// // #include <stdlib.h>

// // #define MAXN 10
// // #define MAXS 20

// // int max_len( char *s[], int n )
// // {
// //     int max;
// //     int i;
// //     max = strlen(s[0]);
// //     for(i = 0;i<n;i++)
// //     {
// //         if(strlen(s[i])>max)
// //         max = strlen(s[i]);

// //     }
// //     return max;
// // }
// // int main()
// // {
// //     int i, n;
// //     char *string[MAXN] = {NULL};
    
// //     scanf("%d", &n);
// //     for(i = 0; i < n; i++) {
// //         string[i] = (char *)malloc(sizeof(char)*MAXS);
// //         scanf("%s", string[i]);
// //     }
// //     printf("%d\n", max_len(string, n));
// //     system("pause");
// //     return 0;
// // }

// /* 你的代码将被嵌在这里 */
// #include <stdio.h>
// #define N 4

// int main()
// {
//     char a[4][21];
//     int i;

//     for (i = 0; i < N; i++)
//         scanf("%s", a[i]);
//     for (i = 0; i < N; i++)
//         printf("%c%c%c", a[i][0], a[i][1],a[i][2]);   //一个char是一个字节，而一个汉字占两个字节，所以要输出每一行数组的前两个才是一个汉字。
//     printf("\n");
//     system("pause");
//     return 0;
// }