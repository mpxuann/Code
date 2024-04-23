// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>
// int main()
// {
//     char a[80],b[80],*pa=a,*pb=b;
//     int n,i;
//     scanf("%d",&n);
//     scanf("%s",a);
//     if(n == 1)
//         printf("%s\n",pa);
//     else
//     {
//         for(i = 2;i<=n;i++)
//         {
//             scanf("%s",pb);
            
//             if(strcmp(pb,pa)<0)
//                 strcpy(a,b);
//         }
//     }
//     printf("Min is: %s",pa);
//     system("pause");
//     return 0;
// }
// # include <stdio.h> 
// #include<stdlib.h>
// #include<string.h>

// int main(void)
// {
//     char s[ ]="china"; 
//     char *p; 
//     p = s;
//     printf("%c",*p);
//     printf("%c",s[0]);
//     system("pause");       
//     return 0;
// }
// #include <stdio.h>
// #include<stdlib.h>
// int main(void)
// {
//       int i, j, k = 5, *p;
    
//   p = &k;
//   i = ++(*p);
//   j = (*p)++;
//  printf("%d %d %d", i, j, k) ;
//      system("pause");
//      return 0;
// }
#include <stdio.h>
// #include<stdlib.h>
// int main()
// {
//     char max, str[80], *p, *q;
        
//     p = str; 
//     gets(p); 
//     max = *p;
//     p++;
//     while ( *p != '\0' ){
//         if ( max < *p ){ 
//             max = *p; 
            
// q = p; 
//         }
//         p++;
//     }
//     p = q;
//     while ( 
// *(p-1)
//  ){
//         *p = *(p-1);
        
// p--; 
//     }
//     *p = max;
//     puts(p);
//     system("pause");
//     return 0;
// }
// #include <stdio.h>
// #include <string.h>
// #include<stdlib.h>
// int main()
// {
//     char ch, s[80], *p, *q;
//     int i, j, n;
    
//     gets(s);
//     p =s;
//     while ( *p == ' '){
          
// p++;
//     }
//     n = strlen(s);
//     q = s+n-1;
//     while ( *q == ' '){
          
// q--;
//     }
//     while (p<q && *p ==*q){
//         p++;
        
// q--;
//     }
//     if ( p<q ){
//         printf("NO\n");
//     }else{
//         printf("YES\n");
//     }
//     system("pause");
//         return 0;
// }