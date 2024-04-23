#include <stdio.h>
#include <stdlib.h>

int narcissistic( int number );
void PrintN( int m, int n );
    
int main()
{
    int m, n;
  
    scanf("%d %d", &m, &n);
    if ( narcissistic(m) ) printf("%d is a narcissistic number\n", m);
    PrintN(m, n);
    if ( narcissistic(n) ) printf("%d is a narcissistic number\n", n);
    system("pause");
    return 0;
}


// int narcissistic( int number )
// {
//     int i,j,sum = 0;
//     j = number;
//     do
//     {
//         i = number % 10;
//         number /= 10;
//         sum += i * i * i;
//     } while (number != 0);
//     if( j == sum)
//         return 1;
//     else 
//         return 0;
    
// }
// void PrintN( int m, int n )
// {
//     int i,j;
//     for(i = m+1; i<n;i++)
//     {
//         if(narcissistic(i))
//             printf("%d\n",i);
//     }
// }
int narcissistic(int number)
{
    int n = 0;
    int num = number;
    int cur = number;
    int sum = 0;
    while (num)
    {
        num = num/10;
        n++;
    }
    for (int i = 0; i < n; i++)
    {
        int a = number % 10;
        number = number / 10;
        int b = 1;
        for (int i = 0; i < n; i++)
        {
            b = b * a;
        }
        sum += b;
    }
    if (cur == sum)
        return 1;
    else
        return 0;
 
 
}
void PrintN(int m, int n)
{
    for (int i = m+1; i < n; i++)
    {
        if(narcissistic(i))
        {
            printf("%d\n", i);
        }
 
    }
}