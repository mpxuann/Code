// #include<stdio.h>
// #include<stdlib.h>
// int main()
// {
//     printf("It's been a long time I haven't seen you, vscode\n");
//     system("pause");
//     return 0;
// // }
// #include<stdio.h>
// #include<stdlib.h>

// int main()
// {
//     int i,j;
//     i = 3;
//     j = 5;
//     int sum;
//     sum = i + j;
//     printf("%d",sum);
//     system("pause");
//     return 0;
// }
#include<stdio.h>
#include<stdlib.h>
int main()
{
    char ch;
    int digital, characters, others, blanks;
    digital=characters=others=blanks=0;
    printf("the string:");
    for (;;)
    {
        ch = getchar();
        switch (ch)
        {
            case ' ':
                blanks++;
                break;
            default:
                others++;
                break;
            case '\n':
                goto a;
        }    
    }
a:
    printf("%d  %d",blanks,others);
    system("pause");    
    return 0;
}


