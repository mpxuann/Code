
// // # include <stdio.h>
// // #include<stdlib.h>

// // void month_day ( int year, int yearday, int * pmonth, int * pday);

// // int main (void)
// // {
// //     int day, month, year, yearday; /*  定义代表日、月、年和天数的变量*/
// //     scanf ("%d%d", &year, &yearday );        
// //     month_day (year, yearday, &month, &day );/* 调用计算月、日函数  */ 
// //     printf ("%d %d %d\n", year, month, day );    
// //     system("pause");
// // return 0;
// // }
// // void month_day(int year,int yearday,int *pmonth,int *pday)
// // {
// //     int arr1[12]={31,28,31,30,31,30,31,31,30,31,30,31};
// //     int arr2[12]={31,29,31,30,31,30,31,31,30,31,30,31};
// //     int mark = 0,i,_day;
// //     _day = yearday;
// //     if(year%4==0&&year%100!=0||year%400==0)
// //         mark = 2;
// //     else 
// //         mark = 1;
// //     if(mark == 1)
// //     {
// //         for(i=0;i<12&&_day>0;i++)
// //         {
// //             _day-=arr1[i];
// //         }
// //         *pmonth = i;
// //         *pday = arr1[i-1]+_day;
// //     }
// //     else
// //     {
// //         for(i=0;i<12&&_day>0;i++)
// //         {
// //             _day-=arr2[i];
// //         }
// //         *pmonth = i;
// //         *pday = arr2[i-1]+_day;
// //     }
// // }
// #include<stdio.h>
// #include<stdlib.h>
// int main()
// {
//     char a[81];
//     char ch,temp;
//     int i,j;
//     int min;
//     min = 0;
//     for(i = 0;(ch=getchar())!='\n';i++)
//     {
//         a[i]=ch;
//     }
//     a[i] = '\0';
//     for(i = 0;a[i]!='\0';i++)
//     {
//         min = i;
//         for(j = i+1;a[j]!='\0';j++)
//         {
//             if(a[j]<=a[min])
//             {
//                 min = j;
//             }
//         }
//         temp = a[i];
//         a[i] = a[min];
//         a[min] = temp;
//     }
//     for(i = 0;a[i]!='\0';i++)
//     {
//         printf("%c",a[i]);
//     }
//     system("pause");
//     return 0;
// }
// #include<stdio.h>
// #include<stdlib.h>
// int main()
// {
//     int n;
//     int a[10];
//     int b[10];
//     int i;
//     scanf("%d",&n);
//     for(i = 0;i<n;i++)
//     {
//         scanf("%d",&a[i]);
//         b[n-1-i]=a[i];
//     }
//     for(i = 0;i<n;i++)
//     {
//         if(!i)
//         printf("%d",b[i]);
//         else
//         printf(" %d",b[i]);
//     }
//     system("pause");
//     return 0;
// }
// #include<stdio.h>
// #include<stdlib.h>
// int main()
// {
//     int n;
//     int a[10][10];
//     int i,j;
//     int sum = 0;
//     scanf("%d",&n);
//     for(i = 0;i<n;i++)
//     {
//         for(j = 0;j<n;j++)
//         {
//             scanf("%d",&a[i][j]);
//         }
//     }
//     for(i = 0;i<n;i++)
//     {
//         for(j = 0;j<n;j++)
//         {
//             if((i+j)!=(n-1)&&i!=(n-1)&&j!=(n-1))
//             {
//                 sum += a[i][j];
//             }
//         }
//     }
//     printf("%d",sum);
//     system("pause");

//     return 0;
// }

// #include<stdio.h>
// #include<stdlib.h>
// int main()
// {
//     int m2,n,i,j,temp;
//     int a[6][6];
//     int b[6][6];
//     int m;
//     scanf("%d%d",&m2,&n);
//     for(i = 0;i<n;i++)
//     {
//         for(j=0;j<n;j++)
//             scanf("%d",&a[i][j]);

//     }
//     m = m2 % n;
//     for(j = 0;j<n;j++)
//     {
//         for(i = 0;i<n;i++)
//         {
//             if((m+j)<n)
//                 b[i][m+j]=a[i][j];
//             else
//                 b[i][m+j-n]=a[i][j];
//         }
//     }
//     for(i = 0;i<n;i++)
//     {
//         for(j=0;j<n;j++)
//             printf("%d ",b[i][j]);
//         printf("\n");

//     }
//     system("pause");
//     return 0;
// }
#include<stdio.h>
#include<stdlib.h>
int main()
{
    char a[81];
    int i;
    int sum;
    sum = i = 0;
    while((a[i]=getchar())!= '\n')
        i++;
    for(i = 0;a[i]!='\n';i++)
    {
        if(a[i]>='B'&&a[i]<='Z'&&a[i]!='E'&&a[i]!='I'&&a[i]!='O'&&a[i]!='U')
            sum++;
    }
    printf("%d",sum);
    system("pause");
    return 0;
}