#include <stdio.h>
#include <math.h>
#include<stdlib.h>
int search( int n );

int main()
{
    int number;

    scanf("%d",&number);
    printf("count=%d\n",search(number));
    system("pause");
    return 0;
}
int search( int n )
{
    int i;
    int cnt =0;
    int a[21] = {121,144,169,196,225,256,289,324,361,400,441,484,529,576,625,676,729,784,841,900,961};
    for(i=0;a[i]<n;i++)
    {
        if(a[i]==121||a[i]==144||a[i]==225||a[i]==400||a[i]==441||a[i]==484||a[i]==676||a[i]==900)
        cnt++;
    }
    return cnt;
}


/* 你的代码将被嵌在这里 */