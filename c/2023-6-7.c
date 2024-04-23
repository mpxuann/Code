// #include <stdio.h>
// #include <stdlib.h>

// void WriteArticle(FILE *f)
// {
//     char ch;
//     ch = getchar();
//     while(ch!=EOF)
//     {
//         fputc(ch,f);
//         ch = getchar();
//     }
// }

// int main()
// {
//     FILE *f;
//     f = fopen("Article.txt", "w");
//     if (!f)
//     {
//         puts("文件无法打开!");
//         exit(1);
//     }

//     WriteArticle(f);

//     if (fclose(f))
//     {
//         puts("文件无法关闭!");
//         exit(1);
//     }
//     puts("文件保存成功!");
//     return 0;
// }

// /* 你提交的代码将被嵌在这里 */
// #include <stdio.h>
// #include <stdlib.h>

// void ReadArticle(FILE *f)
// {
//     char ch;
//     ch = fgetc(f);
//     while(ch!=EOF)
//     {
//         putchar(ch);
//         ch = fgetc(f);
//     }
// }

// int main()
// {
//     FILE *f;
//     f = fopen("Article.txt", "r");
//     if (!f)
//     {
//         puts("文件无法打开!");
//         exit(1);
//     }

//     ReadArticle(f);

//     if (fclose(f))
//     {
//         puts("文件无法关闭!");
//         exit(1);
//     }
//     system("pause");
//     return 0;
// }

// /* 你提交的代码将被嵌在这里 */
// #include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>

// int CountWord(FILE *f)
// {
//     char ch1,ch2;
//     int cnt=0;
//     ch1 = fgetc(f);
//     ch2 = fgetc(f);
//     if(ch1>='a'&&ch1<='z'||ch1>='A'&&ch1<='Z')
//     cnt++;
//     while(ch2!=EOF)
//     {
//         if((ch2>='a'&&ch2<='z'||ch2>='A'&&ch2<='Z')&&!(ch1>='a'&&ch1<='z'||ch1>='A'&&ch1<='Z'))
//         cnt++;
//         ch1 = ch2;
//         ch2 = fgetc(f);
//     }
//     return cnt;
// }

// int main()
// {
//     FILE *f;
//     int n;
//     f = fopen("Story.txt", "r");
//     if (!f)
//     {
//         puts("文件无法打开!");
//         exit(1);
//     }

//     n = CountWord(f);

//     if (fclose(f))
//     {
//         puts("文件无法关闭!");
//         exit(1);
//     }

//     printf("单词数: %d\n", n);
//     system("pause");
//     return 0;
// }

// /* 你提交的代码将被嵌在这里 */
// #include <stdio.h>
// #include <stdlib.h>

// void BatchAdd(FILE *in, FILE *out)
// {
//     double a,b;
//     while(fscanf(in,"%lf %lf",&a,&b)!=EOF)
//     {
//         fprintf(out,"%.2f\n",a+b);
//     }
// }

// int main()
// {
//     FILE *in, *out;

//     in = fopen("Addition.txt", "r");
//     out = fopen("Sum.txt", "w");

//     if (in && out)
//     {
//         BatchAdd(in, out);
//     }
//     else
//     {
//         puts("文件无法打开!");
//     }

//     if (in)
//     {
//         fclose(in);
//     }
//     if (out)
//     {
//         fclose(out);
//         puts("文件保存成功!");
//     }

//     return 0;
// }

/* 你提交的代码将被嵌在这里 */
#include <stdio.h>
void fileRW(FILE *fin,FILE *fout)
{
    char ch;
    int flag = 1;
    char ch0;
    ch = fgetc(fin);
    int cnt = 1;
    fputc(48+cnt,fout);
    fputc(':',fout);
    ch0 = ch;
    
    ch = fgetc(fin);
    while(ch!=EOF)
    {
        if((ch0 == ' ' ||ch0 == '\t')&&flag == 0)
        {

            ch0 = ch;
            ch = fgetc(fin);
            if(ch!=' '&&ch!='\t')
            {
                flag = 1;
                ch0 = ch;
            }
            continue;
        }
        if(ch0 == '\n')
        {
            flag=0;
            fputc(ch0,fout);
            cnt++;
            fputc(48+cnt,fout);
            fputc(':',fout);
            ch0 = ch;
        ch = fgetc(fin);

        continue;
        }
        fputc(ch0,fout);

            ch0 = ch;
        ch = fgetc(fin);
    }
}
int main(){
    char fname[20];
    gets(fname);
    FILE *fpr=fopen(fname,"r");
    FILE *fpw=fopen("file2.txt","w");  
    fileRW(fpr,fpw);
    fclose(fpr);fclose(fpw);
    return 0;
}
/* 请在这里填写答案 */