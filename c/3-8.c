// #include<stdio.h>
// #include<stdlib.h>

// int main()
// {
//     int n,i,y;
//     double result;
//     result = 1;
//     scanf("%d",&n);
//     if (n==0)
//         printf("%d\n",0);
//     else
//         {
//             for(i = 1;i <= n;i++)
//         {
//             result = result * i;
//         }
//         printf("%.0f\n",result);
//         }
//     system("pause");
//     return 0;
// }
// #include <stdio.h>
// #include <stdlib.h>

// double fact( int n );

// int main()
// {    
//     int i, n;
//     double result; 

//     scanf("%d", &n);
//     for(i = 0; i <= n; i++){
//         result = fact(i); 
//         printf("%d! = %.0f\n", i, result);
//      }
//     system("pause");
//     return 0;
// }

// /* 你的代码将被嵌在这里 */
// double fact(int n)
// {
//     double result = 1;
//     int i;
//     if(n==0)
//         return 0;
//     else{
//         for(i=1;i<=n;i++)
//         {
//             result = result * i;
//         }
//         return result;
//     }
// }   
// #include<stdio.h>

// int main()
// {
//     long n;
//     int i=1;
//     scanf("%ld",&n);
//     for(;n>=10||n<=-10;)
//     {
//         n = n / 10;
//         i++;
//     }
//     printf("%d",i);
    
    
//     return 0;
// }
// #include<stdio.h>
// #include<stdlib.h>
// #include<math.h>

// int main()
// {
//     printf("%d",(int)sqrt(3)+1);
//     system("pause");
//     return 0;
// }
// #include<stdio.h>
// #include<stdlib.h>
// int main()
// {
//     int n,max;
//     do{
//         scanf("%d",&n);
//         if(n<0)
//             break;
//         else if(n>max)
//             max = n;
//     }while(getchar()!='\n');
//     printf("%d",max);
//     system("pause");
//     return 0;
// }
#include<stdio.h>
#include<stdlib.h>
fun(int a, int b, int c)
{   c = a * b;  }
int main(void)
{
      int c;

      fun(2, 3, c);
      printf("%d\n", c);
      system("pause");
      return 0;
}





