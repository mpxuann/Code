#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int n,i,m,max,j;
    scanf("%d",&n); 
    if(n == 1)
        printf("None");
    else if(n == 2)
        printf("3");
    else
    {    
        for(i = 2; i <= n; i++)
        {
            max = pow(2,i)-1;
            m = (int)sqrt(max)+1;
            for(j = 2;j<m;j++)
            {
                if(max%j==0)
                   break;
            }
            if(j == m)
                printf("%d\n",max);
        }
    }
    system("pause");
    return 0;
}