// #include<stdio.h>
// #include<stdlib.h>
// int main()
// {
//     int i;
//     int sum = 0;
//     scanf("%d",&i);
//     while(i>0)
//     {
//         if(i%2==1)  
//         sum += i;
//         scanf("%d",&i);
//     }
//     printf("%d",sum);
//     system("pause");
//     return 0;
// }
// #include<stdio.h>
// #include<stdlib.h>
// #include<math.h>
// int prime(int i)
// {
//     int m;
//     int j;
//     m = sqrt(i)+1;
//     if(i == 1)
//         return 0;
//     else if(i == 2)
//         return 1;
//     else
//     {
//         for(j = 2;j<=m;j++)
//         {
//             if(i%j == 0)
//             return 0;
//             if(j == (m+1))
//             return 1;
//         }
//     }
// }
// int main()
// {
//     int m,n;
//     int sum,num;
//     int i;
//     sum = num = 0;
//     scanf("%d%d",&m,&n);
//     for(i = m;i<=n;i++)
//     {
//         if(prime(i))
//         {
//             num++;
//             sum += i;
//         }
//     }
//     printf("%d %d",num,sum);
//     system("pause");
//     return 0;
// }
// #include<stdio.h>
// #include<stdlib.h>
// int main()
// {
//     int i = 1;
//     int num, time;
//     int guesstime = 0;
//     int guess;
//     scanf("%d%d",&num,&time);
//     for(;i<=time;i++)
//     {
//         guesstime++;
//         scanf("%d",&guess);
//         if(guess<0)
//         {    
//             printf("Game Over\n");
//             system("pause");
//             return 0;
//         }  
//         if(guesstime==1&&guess == num)
//         {
//             printf("Bingo!\n");
//             system("pause");
//             return 0;
//         }
//         else if((guesstime==2||guesstime==3)&&guess==num)
//         {
//             printf("Lucky You!\n");
//             system("pause");
//             return 0;
//         }
//         else if(guess == num)
//         {
//             printf("Good Guess!\n");
//             system("pause");
//             return 0;
//         }
//         else if(guess>num)
//             printf("Too big\n");
//         else if(guess<num)
//             printf("Too small\n");
          

//     }
//     printf("Game Over\n");
//     system("pause");
//     return 0;
// }
// #include<stdio.h>
// #include<stdlib.h>
// int main()
// {
//     int i,j,k;
//     int n,count = 0;
//     int sum;
//     scanf("%d",&n);
//     int i1,j1,k1;
//     i1 = n/5;
//     j1 = n/2;
//     k1 = n/1;
//     for(i = i1;i>=1;i--)
//     {
//         for(j = j1;j>=1;j--)
//         {
//             for(k = k1;k>=1;k--)
//             {
//                 sum = 5*i + 2*j + k;
//                 if(sum == n)
//                 {
//                    printf("fen5:%d, fen2:%d, fen1:%d, total:%d\n",i,j,k,i+j+k);
//                    count++;
//                 }    
//             }
//         }
//     }
//     printf("count = %d\n",count);
//     system("pause");
//     return 0;
// }
// #include<stdio.h>
// #include<stdlib.h>
// #include<math.h>
// int main()
// {
//     double x;
//     double xn;
//     double sum;
//     int i = 1;

//     double jiecheng;
//     scanf("%lf",&x);
//     jiecheng =1;
//     sum = 1;
//     xn = x;
//     while(xn>=0.00001)
//     {
//         sum += xn;
//         i++;
//         jiecheng = jiecheng * i;
//         xn = pow(x,i) / jiecheng;
//     }
//     sum+=xn;
//     printf("%.4f",sum);
//     system("pause");
//     return 0;
//
// #include<stdio.h>
// #include<stdlib.h>
// int main()
// {
//     int n;
//     int i,j;
//     scanf("%d",&n);
//     for(i=1;i<=n;i++)
//     {
//         if(i<((n+1)/2))
//         {
//             for(j = 1;j<=(n-2*(i-1)-1);j++)
//                 printf(" ");
//             for(j = 1;j<=(2*i-1);j++)
//                 printf("* ");
//             printf("\n");
            
//         }
//         if(i == ((n+1)/2))
//         {
//             for(j = 1;j<=n;j++)
//                 printf("* ");
//             printf("\n");
//         }
//         if(i>((n+1)/2))
//         {
//             for(j = 1;j<=(n-2*(n-i)-1);j++)
//                 printf(" ");
//             for(j = 1;j<=(2*(n-i+1)-1);j++)
//                 printf("* ");
//             printf("\n");

//         }
//     }
//     system("pause");
//     return 0;
// }
// #include<stdio.h>
// #include<stdlib.h>
// int main()
// {
//     int n;
//     int i;
//     scanf("%d",&n);
//     if(n == 3)
//     printf("153\n370\n371\n407\n");
//     if(n==4)
//     printf("1634\n8208\n9474\n");
//     if(n==5)
//     printf("54748\n92727\n93084\n");
//     if(n==6)
//     printf("548834\n");
//     if(n==7)
//     printf("1741725\n4210818\n9800817\n9926315\n");
//     system("pause");
//     return 0;
// }
// #include<stdio.h>
// #include<stdlib.h>
// int main()
// {
//     int n;
//     int a[10];
//     int j;
//     int i,temp;
//     int max = 0;
//     scanf("%d",&n);
//     for(i = 0;i<n;i++)
//         scanf("%d",&a[i]);
//     for(j = 0;j<n;j++)
//     {
//         max = j;
//         for(i = j;i<n;i++)
//         {
//             if(a[i]>a[max])
//             max = i;
//         }
//         temp = a[j];a[j] = a[max];a[max] = temp;
       

//     }
//     printf("%d",a[0]);
//     for(j = 1;j<n;j++)
//     {
//         printf(" %d",a[j]);
//     }
//     system("pause");
//     return 0;
// }
// #include<stdio.h>
// #include<stdlib.h>
// int main()
// {
//     int n,i,j;
//     int a[10];
//     int m;
//     scanf("%d",&n);
//     for(i = 0;i<n;i++)
//     {
//         scanf("%d",&a[i]);
//     }
//     scanf("%d",&m);
//     if(n==0)
//     {
//         printf("%d ",m);
//         return 0;
//     }
//     if(n == 1)
//     {
//          if(m>=a[0])
//         a[1]=m;
//         else
//         {
//             a[1]=a[0];
//             a[0]=m;
//         }
//     }
//     else
//     {
        
    
//     for(i = (n-1);i>=1;i--)
//     {
//         if(m>a[n-1])
//         {
//             a[n]= m;
//             break;
//         }    
//         if(m<=a[i]&&m>=a[i-1])
//         {
//             a[i+1]=a[i];
//             a[i] = m;
//             break;
//         }
//         else
//             a[i+1]= a[i];
//     }
//     if(i ==0)
//         {
//             a[0] = m;
//         }
//     }
//     for(i = 0;i<=n;i++)
//     {
//         printf("%d ",a[i]);
//     }
//     system("pause");
//     return 0;
// }
// #include<stdio.h>
// #include<stdlib.h>
// int main()
// {
//     int a[6][6];
//     int i,j;
//     int sum;
//     int m,n;
//     scanf("%d%d",&m,&n);
//     for(i = 0;i<m;i++)
//     {
//         for(j=0;j<n;j++)
//             scanf("%d",&a[i][j]);
//     }
//     for(i = 0;i<m;i++)
//     {
//         sum = 0;
//         for(j=0;j<n;j++)
//             sum += a[i][j];
//         printf("%d\n",sum);
//     }
//     system("pause");
//     return 0;
// }
// #include<stdio.h>
// #include<stdlib.h>
// void kongge(int i,int n)
// {
//     int j;
//     for(j = 1;j<=(n-i);j++)
//         printf(" ");
// }
// int main()
// {
//     int n,i,j;
//     int a[10][10];
//     a[0][0]=1;
//     for(i =1;i<10;i++)
//     {
//         for(j = 0;j<10;j++)
//         {
//             if(i==j||j==0)
//                 a[i][j]=1;
//             else
//                 a[i][j] = a[i-1][j-1]+a[i-1][j];
//         }
//     }
//     scanf("%d",&n);
//     for(i = 0;i<n;i++)
//     {
//         kongge(i+1,n);
//         if(i == 0)
//             {
//                 printf("%4d",1);
//                 printf("\n");
//             }
//         else 
//         {
//             for(j = 0;j<=i;j++)
//                 printf("%4d",a[i][j]);
//             printf("\n");
//         }

//     }
//     system("pause");
//     return 0;
// }
// #include<stdio.h>
// #include<stdlib.h>
// int main()
// {
//     char a[80];
//     int i = 0;
//     char ch;
//     for(;(ch = getchar())!='\n';i++)
//     {
//         a[i] = ch;
//     }
//     a[i] = '\0';
    
//     for(i--;i>=0;i--)
//     {
//         printf("%c",a[i]);
//     }
//     system("pause");
//     return 0;
// }
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int m;
    m = -28 % 26;
    printf("%d",m);
    system("pause");
    return 0;
}