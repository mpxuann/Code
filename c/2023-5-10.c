// #include <stdio.h>
// #define MAXN 20

// void delchar( char *str, char c );
// // void ReadString( char s[] ); /* 由裁判实现，略去不表 */

// int main()
// {
//     char str[MAXN], c;

//     scanf("%c\n", &c);
//     gets(str);
//     delchar(str, c);
//     printf("%s\n", str);
//     system("pause");
//     return 0;
// }
// void delchar( char *str, char c )
// {
//     char b[MAXN];
//     char *p1,*p2;
//     p1 = str;
//     p2 = b;
//     int j = 0;
//     while(*str)
//     {
//         if(*str != c)
//         {
//             b[j++] = *str;
//         }
//         str++;
//     }
//     while(*p1++ = *p2++);
// }
/* 你的代码将被嵌在这里 */


// #include <stdio.h>
// #include <string.h>

// #define MAXS 10

// char *str_cat( char *s, char *t );

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
// char *str_cat( char *s, char *t )
// {
//     char * s0;
//     s0 = s;
//     while(*s)s++;
//     while(*t)*s++ = *t++;
//     return s0;
// }
// /* 你的代码将被嵌在这里 */
// #include <stdio.h>
// #define MAXS 15

// void StringCount( char *s );
// // void ReadString( char *s ); /* 由裁判实现，略去不表 */

// int main()
// {
//     char s[MAXS];

//     gets(s);
//     StringCount(s);
//     system("pause");
//     return 0;
// }
// void StringCount( char *s )
// {
//     int daxie,xiaoxie,kongge,shuzi,other;
//     daxie = xiaoxie = kongge = shuzi = other = 0;
//     while(*s)
//     {
//         if(*s>='A'&&*s<='Z')
//         daxie++;
//         else if(*s>='a'&&*s<='z')
//         xiaoxie++;
//         else if(*s>='0'&&*s<='9')
//         shuzi++;
//         else if(*s==' ')
//         kongge++;
//         else other++;
//         s++;

//     }
//     printf("%d %d %d %d %d",daxie,xiaoxie,kongge,shuzi,other);
// }
// /* Your function will be put here */
// #include <stdio.h>
// #define MAXS 20

// void f( char *p );
// // void ReadString( char *s ); /* 由裁判实现，略去不表 */

// int main()
// {
//     char s[MAXS];
    
//     gets(s);
//     f(s);
//     printf("%s\n", s);
//     system("pause");
//     return 0;
// }
// void f( char *p )
// {
//     int i = 0;
//     char *p0;
//     p0 = p;
//     char temp;
//     int j;
//     while(*p0!='\0')
//     {
//         p0++;
//         i++;    
//     }
//     if(i%2 == 0)
//     {
//         for(j = 0;j<i/2;j++)
//         {
//             temp = p[j];
//             p[j] = p[i-1-j];
//             p[i-1-j] = temp;
//         }
//     }
//     else
//     {
//         for(j = 0;j<=(i/2-1);j++)
//         {
//             temp = p[j];
//             p[j] = p[i-1-j];
//             p[i-1-j] = temp;
//         }
//     }
// }

/* 你的代码将被嵌在这里 */
// // #include<stdio.h>

// // #include<string.h>
// // void zip( char *p )
// // {
// // int i,j=0,g=1;
// // for(i=0;p[i]!='\0';i++)
// // {
// // if(p[i]==p[i+1])
// // g++;
// // else if(p[i]!=p[i+1]&&g==1)
// // {
// // p[j++]=p[i];
// // g=1;
// // }
// // else if(p[i]!=p[i+1]&&g>1&&g<10)
// // {
// // p[j++]=g+'0';
// // p[j++]=p[i];
// // g=1;
// // }
// // else if(p[i]!=p[i+1]&&g>10&&g<100)
// // {
// // p[j++]=g/10+'0';
// // g%=10;
// // p[j++]=g+'0';
// // p[j++]=p[i];
// // g=1;
// // }
// // }
// // p[j]='\0';
// // }
// // int main()

// // {
// // char a[80];
// // gets(a);
// // zip(a);
// // printf("Min·is:·%s",a);


// // return 0;

// // }
// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>
// int·main()
// {
// ····char·a[80],b[80],*pa=a,*pb=b;
// ····int·n,i;
// ····scanf("%d",&n);
// ····scanf("%s",a);
// if(n·==·1)
// printf("%s\n",pa);
// else
// {
// for(i·=·2;i<=n;i++){scanf("%s",pb);

// if(strcmp(pb,pa)<0)
// strcpy(a,b);
// }
// }
// printf("Min·is:·%s",pa);
// system("pause");
// return·0;
// }
// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>
// int main()
// {
//     char a[80],b[80],*pa=a,*pb=b;
//     int n,i;
//     scanf("%d",&n);
//     scanf("%s",a);
//     if(n == 1)
//         printf("%s\n",pa);
//     else
//     {
//         for(i = 2;i<=n;i++)
//         {
//             scanf("%s",pb);
            
//             if(strlen(pb)>strlen(pa))
//                 strcpy(a,b);
//         }
//     }
//     printf("The longest is: %s",pa);
//     system("pause");
//     return 0;
// }
#include <stdio.h>
#define MAXN 20

void delchar( char *str, char c );
// void ReadString( char s[] ); /* 由裁判实现，略去不表 */

int main()
{
    char str[MAXN], c;

    scanf("%c\n", &c);
    gets(str);
    delchar(str, c);
    printf("%s\n", str);
    system("pause");
    return 0;
}
void delchar( char *str, char c )
{
    int j= 0;
    int i = 0;
    char *p;
    p = str;
    while(*(p))
    {
        if(*p!=c)
            str[j++] = *p++;
        else 
         {
            p++;


         }
         
         
    }
    str[j]='\0';
}
/* 你的代码将被嵌在这里 */