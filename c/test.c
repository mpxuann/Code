// #include<stdlib.h>
// #include<stdio.h>
// typedef int ElementType;
// typedef struct Node* PtrtoNode;
// typedef PtrtoNode List;

// struct Node{
//     ElementType Element;
//     List Next;
// };
// int main()
// {
//     float a = 2.65967596;

//     printf("%.5f",sqrt(a*a));
//     system("pause");
//     return 0;
// }

// void Delete(List L, ElementType n)
// {
//     List p,tmpCell;
//     p = L;
//     while(p->Next)
//     {
//         if(p->Next->Element == n)
//         {
//             tmpCell = p->Next;
//             p->Next = tmpCell->Next;
//             free(tmpCell);
//             return;       
//         }    
//         p = p->Next;
    
//     }
// }

# include <stdio.h>
# include<stdlib.h>

int factorsum( int number );
void PrintPN( int m, int n );
    
int main()
{
    int m, n;

    scanf("%d %d", &m, &n);
    if ( factorsum(m) == m ) printf("%d is a perfect number\n", m);
    if ( factorsum(n) == n ) printf("%d is a perfect number\n", n);
    PrintPN(m, n);
    system("pause");
    return 0;
}

int factorsum( int number )
{
    int s,i;
    s=0;
    for(i=1;i<number;i++)
    {
        if(number%i==0)
        {
            s=s+i;
        }
    }
    return s;
}

void PrintPN( int m, int n )
{
    int i,j,count;
    count=0;
    for(i=m;i<=n;i++)
    {
        if(i==factorsum(i))
        {
            printf("%d = 1",i);
            for(j=2;j<=i/2;j++)
            {
                if(i%j==0)
                {
                    printf(" + %d",j);
                }
            }
            printf("\n");
        }
        
        count++;
    }
    printf("%d,%d",count,i);
    if(count==0)
    {
        printf("No perfect number");
    }
}
/* 你的代码将被嵌在这里 */


