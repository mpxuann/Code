// #include <stdio.h>
// #include<stdlib.h>

// void bubble (int a[ ], int n);
// int main(void)
// {    
//   int n, a[10];
//     int i;
//     scanf("%d", &n);
//     for (i=0; i<n;i++)
//         scanf("%d",&a[i]);
//     bubble(a,n);
//     for (i=0; i<n; i++)
//         printf("%d ",a[i]);
//   printf("\n");
//   system("pause");
//     return 0;
// }
// void bubble (int a[ ], int n)
// {
//     int i,j,temp;
//     for(i = 1;i<n;i++)
//     {
//         for(j=1;j<=n-i;j++)
//         {
//             if(a[j-1]>a[j])
//             {
//                 temp = a[j-1];a[j-1] = a[j];a[j]=temp;
//             }
//         }
//     }
// }
// /* 请在这里填写答案 */

// # include<stdio.h>

// int Bsearch(int *p, int n, int x);     
// int main(void)   
// {
//     int a[10] = {1,2,3,4,5,6,7,8,9,10};    
//     int x, m;
//     scanf("%d",&x);                
//     m = Bsearch(a, 10, x);
//     if(m >= 0)   
//         printf("Index is %d\n",m);
//     else 
//         printf( "Not Found\n");
//     system("pause");
//     return 0;
// }

// int Bsearch(int *p, int n, int x)
// {
//     int right,left,mid;
//     left = 0;
//     right = n-1;
//     while(left<=right)
//     {
//         mid = (left+right)/2;
//         if(x>p[mid])
//             left = mid+1;
//         else if(x<p[mid])
//             right = mid -1;
//         else
//             return mid;
//     }
//     if(left>right)
//         return -1;
// }
// /* 请在这里填写答案 */
// #include <stdio.h>
// #include<string.h>

// #define MAXS 20

// void zip( char *p );
// /* 由裁判实现，略去不表 */

// int main()
// {
//     char s[MAXS];
    
//     gets(s);
//     zip(s);
//     printf("%s\n", s);
//     system("pause");
//     return 0;
// }
// void zip( char *p)
// {
//     int i,j;
//     int sum = 1;
//     i = j = 0;
    
//     for(i=0;p[i]!='\0';i++)
//     {
//         if(p[i]==p[i+1])
//             sum++;
//         else if(p[i]!=p[i+1]&&sum == 1)
//         {
//             p[j++] = p[i];
//             sum = 1;
//         }
//         else if(p[i]!=p[i+1]&&sum>1&&sum<10)
//         {
//             p[j++] = sum + '0';
//             p[j++] = p[i];
//             sum = 1;
//         }
//         else if(p[i]!=p[i+1]&&sum>9&&sum<30)
//         {
//             p[j++] = sum/10 + '0';
//             sum %= 10;
//             p[j++] = sum + '0';
//             p[j++] = p[i];
//             sum = 1;
//         }
//     }
//     p[j] = '\0';
// }
void zip( char *p )
{
    int i,j=0,g=1;
    for(i=0;p[i]!='\0';i++)
    {
        if(p[i]==p[i+1])
            g++;
        else if(p[i]!=p[i+1]&&g==1)
        {
            p[j++]=p[i];
            g=1;
        }
        else if(p[i]!=p[i+1]&&g>1&&g<10)
        {
            p[j++]=g+'0';
            p[j++]=p[i];
            g=1;
        }
         else if(p[i]!=p[i+1]&&g>10&&g<100)
        {
             p[j++]=g/10+'0';
             g%=10;
              p[j++]=g+'0';
            p[j++]=p[i];
            g=1;
        }
    }
    p[j]='\0';
}
/* 请在这里填写答案 */
// #include <stdio.h>
// #define MAXN 10

// void sort( int a[], int n );

// int main()
// {
//     int i, n;
//     int a[MAXN];
    
//     scanf("%d", &n);
//     for( i=0; i<n; i++ )
//         scanf("%d", &a[i]);

//     sort(a, n);

//     printf("After sorted the array is:");
//     for( i = 0; i < n; i++ )
//         printf(" %d", a[i]);
//     printf("\n");
//     system("pause");
//     return 0;
// }

/* 你的代码将被嵌在这里 */
// void sort( int a[], int n )
// {
//     int i,j,temp;
//     int max = 0;
//     for(i=0;i<n;i++)
//     {
//         max = 0;
//         for(j=0;j<n-i;j++)
//         {
//             if(a[j]>a[max])
//                 max  = j;
//         }
//         temp = a[max];
//         a[max] = a[j-1];
//         a[j-1] = temp;
//     }
// }
#include <stdio.h>
#define MAXN 10

void ArrayShift( int a[], int n, int m );

int main()
{
    int a[MAXN], n, m;
    int i;
    
    scanf("%d %d", &n, &m);
    for ( i = 0; i < n; i++ ) scanf("%d", &a[i]);
    
    ArrayShift(a, n, m);
    
    for ( i = 0; i < n; i++ ) {
        if (i != 0) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}
void ArrayShift(int a[],int n,int m)
{
    int b[MAXN];
    int i,j;
    j = 0;
    int true = m % n;
    for(i = n-true; i<n;i++)
    {
        b[j++]=a[i];
    }
    for(i=n-1;i>=true;i--)
    {
        a[i] = a[i-true];
    }
    for(i = 0;i<true;i++)
    {
        a[i] = b[i];
    }
}

/* 你的代码将被嵌在这里 */