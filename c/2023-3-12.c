// #include<stdio.h>
// #include<stdlib.h>
// int main()
// {
   
//     int n,i;
//     char x;
//     int letter,digit,other;
//     letter=digit=other=0;
//     scanf("%d",&n);
//     getchar();
//     for(i=1;i<=n;i++)
//     {
//         x = getchar();
//         if(x<='9'&&x>='0')
//             digit++;
//         else if((x>='a'&&x<='z')||(x>='A'&&x<='Z'))
//             letter++;
//         else
//             other++;

//     }
//     printf("letter = %d, digit = %d, other = %d\n",letter,digit,other);
//     system("pause");
//     return 0;
// }
 // int a[1000];
    // odd = even = 0;
    // scanf("%d",&n);
    // for(i=0;i<n;i++)
    // {
    //     scanf("%d",a+i);
    // }
    // for(i=0;i<n;i++)
    // {
    //     if(a[i]%2 == 0)
    //         even++;
    //     else
    //         odd++;
    // }
    // printf("%d %d",odd,even);
    // float x,y;
    // scanf("%f",&x);
    // if(x<0)
    //     y = 0;
    // else if(0<=x && 15>=x)
    //     y = 4 * x / 3.0;
    // else
    //     y = 2.5 * x - 10.5;
    // printf("f(%.2f) = %.2f",x,y);
    // #include<stdio.h>
    // #include<stdlib.h>
    // int main()
    // {
    //     int x,y,result,flag =0;
    //     char cal;
    //     scanf("%d %c %d",&x,&cal,&y);
    //     switch(cal)
    //     {
    //         case '+':
    //             result = x+y;
    //             flag++;
    //             break;
    //         case '-':
    //             result = x - y;
    //             flag++;
    //             break;
    //         case '*':
    //             result = x*y;
    //             flag++;
    //             break;
    //         case '/':
    //             if(y == 0)
    //                 {
    //                     printf("ERROR");
    //                 }
    //             else
    //             {
    //                 result = x / y;
    //                 flag++;
    //             }
    //             break;
    //         case '%':
    //             if(y == 0)
    //                 {
    //                     printf("ERROR");
    //                 }
    //             else
    //             {
    //                 result = x % y;
    //                 flag++;
                    
    //             }
    //             break;
    //         default:
    //             printf("ERROR");
    //             break;
    //     }
    //     if(flag)
    //         printf("%d\n",result);
    //     system("pause");
    //     return 0;
    // }
// #include<stdio.h>
// #include<stdlib.h>
// int main()
// {
//     char ch1,ch2,ch3;
//     scanf("%c%c%c",&ch1,&ch2,&ch3);
//     printf("%c%c%c",ch1,ch2,ch3);
//     system("pause");
//     return 0;
// }

// #include<stdio.h>
// #include<stdlib.h>
// int main()
// {
//     int score;
//     char grade;
//     int i;
//     for(i=1;i<7;i++)
//     {
//         scanf("%d", &score);
//         score = score/10;
//         switch(score) 
//         {
//             case 10: case 9: case 8: case 7: case 6: 
//                 grade = 'P'; break;        
//             default: 
//                 grade = 'F'; break;
//                 putchar(grade);
//         }
        
//     }
//     printf("thanks");
//     system("pause");
//     return 0;
// }
// #include<stdio.h>
// #include<stdlib.h>
// int main()
// {
//     char gameover;
//     int player;
//     gameover = getchar();
//     scanf("%d", &player);
//     if ( gameover == 'N' ) {
//         if ( player == 1 )  printf("My turn"); 
//     } else
//         printf("GAME OVER");
//     system("pause");
//     return 0;
// }
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int x=3,y = 2;
    double a = 2.5,b = 3.5;
    
    printf("\16");
    system("pause");
    return 0;
}