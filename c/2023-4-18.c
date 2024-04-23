#include<stdio.h>
#include<stdlib.h>

int main()
{
    
    // int m,n;
    // int a[20],b[20],c[40];
    // int new;
    // scanf("%d",&m);
    // int i;
    // for(i = 0;i<m;i++)
    // {
    //     scanf("%d",&a[i]);
    // }
    // scanf("%d",&n);
    // for(i = 0; i < n;i++)
    // {
    //     scanf("%d",&b[i]);

    // }
    // int j,flag = 0 ,x=0;
    // for(i = 0; i < m;i++)
    // {
    //     flag = 0;
    //     for(j = 0; j<n;j++)
    //     {
    //         if(a[i]==b[j])
    //         {
    //             flag = 1;
    //             break;
    //         }
    //     }
    //     if(!flag)
    //     {
    //         c[x] = a[i];
    //         x++;
    //     }        
    // }
    // for(j = 0; j < n;j++)
    // {
    //     flag = 0;
    //     for(i = 0; i<m;i++)
    //     {
    //         if(a[i]==b[j])
    //         {
    //             flag = 1;
    //             break;
    //         }
    //     }
    //     if(!flag)
    //     {
    //         c[x] = b[j];
    //         x++;
    //     }        
    // }
    // m = 0;
    // printf("%d ",c[0]);
    // for(i = 0;i<x;i++)
    // {
        
    //     for(j = 0; j<i;j++)
    //     {
    //         if(c[i] == c[j])
    //             break;
    //         else if(j == i-1)
    //             printf("%d ",c[i]);
    //     }
    // }
//     double x;   
// scanf("%lf", &x);  
// printf("%.2f", x);   
// double grade; 
// scanf ("%lf", &grade); 
// if(grade < 60); {    
//     printf("Fail"); 
// }
// printf("?"); 
    // int cnt[10] = {1};
    // printf("%d",cnt[2]);
    int i, j;
int table[3][2]; 
for(j = 0; j < 2; j++){ 
    for(i = 0; i < 3; i++){
        scanf("%d", &table[i][j]);
}
} 

for(i = 0; i < 3; i++){
    for(j = 0; j < 2; j++){     
        printf("%d#", table[i][j]); 
    }
} 
    system("pause");
    return 0;
}