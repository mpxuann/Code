#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,n,j;
    n = 3; 
for(i = 1; i <= n; i++){ 
    for(j = 1; j <= i;j++){
        printf("[%d#%d]", i, j); 
    } 
    printf("\n"); 
}
    system("pause");

    return 0;
}