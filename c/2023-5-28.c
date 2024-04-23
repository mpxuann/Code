// #include<stdlib.h>
// #include<stdio.h>
// #define MAXN 1000
// int Count = 0;        /* 用全局变量Count表示数组a中待处理的元素个数 */
// void select(int a[], int option, int value); /* 决定对有序数组a进行何种操作的控制函数 */
// int input_array(int a[ ]);    /* 输入有序数组a的函数 */
// void print_array(int a[ ]);    /* 输出有序数组a的函数  */
// void insert(int a[ ], int value);    
// void delete(int a[ ], int value);
// void query(int a[ ], int value);    

// int main(void) 
// {
//     int option, value, a[MAXN];
    
//     if(input_array(a) == -1){ 
//        return 0;
//     }
//     printf("[1] Insert\n");
//     printf("[2] Delete\n");
//     printf("[3] Query\n");
//     printf("[Other option] End\n");
//     while (1) {
//         scanf("%d", &option); 
//         if (option < 1 || option > 3) {
//             break;
//         }
//         scanf("%d", &value);
//         select(a, option, value); 
//         printf("\n");
//     }
//     printf("Thanks.");
//     system("pause");
//     return 0;
// }
// /* 控制函数 */
// void select(int a[ ], int option, int value) 
// {
//     switch (option) {
//         case 1:
//           insert(a, value); 
//             break;
//         case 2:
//             delete(a, value);  
//             break;
//         case 3:
//             query(a, value);  
//             break;
//     }
// }
// /* 有序表输入函数 */
// int input_array(int a[ ]) 
// {
//     scanf("%d", &Count);
//     for (int i = 0; i < Count; i ++) {
//         scanf("%d", &a[i]);
//         if(i > 0 && a[i] <= a[i-1]){
//             printf("Error");
//             return -1;
//         }
//     }
//     return 0;
// }
// /* 有序表输出函数 */
// void print_array(int a[ ]) 
// {
//     for (int i = 0; i < Count; i ++) { 
//         if(i == 0){     
//            printf("%d", a[i]);
//         }else{
//            printf(" %d", a[i]);
//         }
//     }
// }

// /* 请在这里填写答案 */
// void insert(int a[ ], int value)
// {
//     int i = Count-1;
//     for(;i>=0;i--)
//     {
//         if(a[i]<=value)
//             {
//                 a[i+1] = value;
//                 break;
//             }
//         else
//         {
//             a[i+1] = a[i];
//         }
//     }
//     if(i==-1)
//     {
//         a[0]=value;
//     }
//     Count++;
//     print_array(a);    /* 输出有序数组a的函数  */
// }
// void delete(int a[ ], int value)
// {
//     int i;
//     int m = Count;
//     for(i = 0;i<Count;i++)
//     {
//         if(a[i] == value)
//         {
//             for(int j = i;j<=(Count-1);j++)
//             {
//                 a[j] = a[j+1];
//             }
//             Count--;
//             print_array(a);    /* 输出有序数组a的函数  */
//             break;
//         }

//     }
//     if(i == m)
//         printf("Deletion failed.");
// }
// void query(int a[ ], int value)
// {
//     int right = Count-1;
//     int left = 0;
//     int mid;
//     while (right>=left)
//     {
//         mid = (right+left)/2;
//         if(a[mid]>value)
//         {
//             right = mid-1;
//         }
//         else if(a[mid]<value)
//         {
//             left = mid+1;
//         }
//         else
//             {
//                 printf("%d",mid);
//                 break;
//             }
//     }
//     if(right<left)
//     printf("Not found.");
    
// }
// #include <stdio.h>
// #include <stdlib.h>
// #define MAXN 101

// int max(int a[ ], int m, int n); 
// int min(int a[ ], int m, int n);

// int main(void)
// {
//     int i, n; 
//     int a[MAXN]; 
    
//     scanf ("%d", &n); 
//     if(n >= 2 && n <= MAXN-1 ){
//         for(i = 0; i < n; i++){ 
//             scanf ("%d", &a[i]); 
//         }
//         printf("max = %d\n", max(a, 0, n-1));
//         printf("min = %d\n", min(a, 0, n-1));
//     }else{
//         printf("Invalid Value.\n");    
//     }
//     system("pause");
//     return 0;
// }

// int max(int a[ ], int m, int n)
// {
//     int i;
//     int Max = m;
//     for(i = m;i<=n;i++)
//     {
//         if(a[i]>a[Max] )
//         Max = i;

//     }
//     return a[Max];
// }
// int min(int a[ ], int m, int n)
// {
//     int i;
//     int Min = m;
//     for(i = m;i<=n;i++)
//     {
//         if(a[i]<a[Min] )
//         Min = i;

//     }
//     return a[Min];
// }
/* 请在这里填写答案 */
// #include<stdio.h>
// #include<stdlib.h>
// #define pi 3.1415926535
// void Ball();
// void Cylinder();
// void Cone();
// void printcommand()
// {
//     printf("1-Ball\n");
// printf("2-Cylinder\n");
// printf("3-Cone\n");
// printf("other-Exit\n");
// printf("Please enter your command:\n");
// }

// int main()
// {
//     int n;
//     while(1)
//     {
//         printcommand();
//         scanf("%d",&n);
//         if(n<1||n>3)
//         {
//             break;
//         }
//         else
//         {
            
//             switch(n)
//             {
//                 case 1:Ball();break;
//                 case 2:Cylinder();break;
//                 case 3:Cone();break;
//             }
//         }
//     }
//     return 0;
// }
// void Ball()
// {
//     printf("Please enter the radius:\n");
//     double r;
//     scanf("%lf",&r);
//     printf("%.2f\n",(4.0*pi*r*r*r)/3);
// }
// void Cylinder()
// {
//     printf("Please enter the radius and the height:\n");
//     double r,h;
//     scanf("%lf%lf",&r,&h);
//     printf("%.2f\n",pi*r*r*h);
// }
// void Cone()
// {
//     printf("Please enter the radius and the height:\n");
//     double r,h;
//     scanf("%lf%lf",&r,&h);
//     printf("%.2f\n",pi*r*r*h/3);
// }

#include<stdio.h>
#include<stdlib.h>

void hanoi(int n,char a, char b,char c)
{
    if(n==1)
        printf("%c-->%c\n",a,b);
    else 
    {
        hanoi(n-1,a,c,b);
        printf("%c-->%c\n",a,b);
        hanoi(n-1,c,b,a);
    }
}
int main()
{
    int n;
    char a,b,c;
    a = 'a';
    b = 'b';
    c = 'c';
    scanf("%d",&n);
    hanoi(n,a,b,c);
    system("pause");
    return 0;
}
