#include<stdio.h>
#include<stdlib.h>
int main()
{
    long n,height,sum,max,right,left,start;
    int i,j;
    long *ptr,*ptr2,*ptr3;
    scanf("%ld%ld",&n,&height);
    ptr = (long*)malloc((n+1)*sizeof(long));
    ptr2 = ptr;
    for(i = 0;i<n;i++)
    {
        scanf("%ld",&ptr[i]);
    }
    start = *ptr;
    max = 0;
    for(i = 0;i<n;i++)
    {
        right = *ptr;
        if((right-height)<start)
            left = start;
        else    
            left = right - height;
        while((*ptr2)<left)
            ptr2++;
        sum = ptr - ptr2 + 1;
        if(sum>max)
        {
            ptr3 = ptr;
            max = sum;
        }
        ptr++;
    }
    // if((*ptr3-height)<start)
    // printf("%ld %ld",start,max);
    // else
    printf("%ld %ld",(*ptr3-height),max);
    system("pause");
    return 0;
}
