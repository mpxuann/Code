// #include<stdio.h>
// #include<stdlib.h>
// #include<math.h>
// int _sum(int x)
// {
//     if(x<10)
//         return x;
//     else
//     {
//         return x%10+_sum(x/10);
//     }
// }
// int main()
// {
//     int x;
//     scanf("%d",&x);
//     int b = _sum(fabs(x));
//     printf("%d\n",b);
//     system("pause");
//     return 0;
// }
// #include <stdio.h>
// #include <stdlib.h>
// #define M 4
// #define N 5
// #define MaxSize 15
// int mg[M + 2][N + 2] = {
// 	{1,1,1,1,1,1,1},
// 	{1,0,1,0,1,1,1},
// 	{1,0,0,0,0,0,1},
// 	{1,1,0,1,0,0,1},
// 	{1,1,0,0,0,0,1},
// 	{1,1,1,1,1,1,1}
// };
// typedef struct
// {
// 	int i;//行
// 	int j;//列
// }Box;
// typedef struct
// {
// 	Box data[MaxSize];
// 	int length;
// }PathType;
// int count = 0;
// void mgpath(int xi, int yi, int xe, int ye, PathType path, int minPath) {
// 	int i, j, di, k;
// 	if (xi == xe && yi == ye) {
// 		path.data[path.length].i = xi;
// 		path.data[path.length].j = yi;
// 		path.length++;
// 		printf("the path %d is :\n", ++count);
// 		for (k = 0; k < path.length; k++) {
// 			printf("\t(%d, %d)", path.data[k].i, path.data[k].j);
// 		}
// 		printf("\n");
// 		printf("the path length is %d\n",path.length);
// 		printf("----------------------------------------------------------\n");
// 		if (path.length < minPath) {
// 			minPath = path.length;
// 		}
// 	}
// 	else {
// 		if (mg[xi][yi] == 0) {
// 			di = 0;
// 			while (di < 4) {
// 				path.data[path.length].i = xi;
// 				path.data[path.length].j = yi;
// 				path.length++;
// 				switch (di) {
// 				case 0:i = xi - 1; j = yi; break;//(-1,0)
// 				case 1:i = xi; j = yi + 1; break;//()
// 				case 2:i = xi + 1; j = yi; break;
// 				case 3:i = xi; j = yi - 1; break;
// 				}
// 				mg[xi][yi] = -1;//这一步好6
// 				mgpath(i, j, xe, ye, path, minPath);
// 				mg[xi][yi] = 0;//恢复可走
// 				path.length--;//回退一个方块
// 				di++;//继续寻找下一条可走路径
// 			}
// 		}
// 	}
// }
// int main() {
// 	PathType path;
// 	path.length = 0;
// 	int minPath = MaxSize;
// 	mgpath(1, 1, M, N, path, minPath);
// 	printf("the shortest path is %d", minPath);
//     system("pause");
// 	return 0;
// }
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct 
{
    char a[2];
    
} possibility;
static int x =0;
void explore(possibility* option, int n,char* sofar, char* origin)
{
    if( n == 0)
    {
        *sofar = '\0';
        printf("case %d : %s\n",++x,origin);
    }
    else
    {
        for(int i = 0;i <2;++i)
        {
            *sofar = (*option).a[i];
            
            explore(option, n -1 ,sofar+1,origin);
        }
    }
}
int main()
{
    printf("input the number you throw the coin:");
    int n = 0;
    possibility coin  = {"ZF"};
    
    void* sequence;
    scanf("%d",&n);
    if((sequence = (char*)malloc((n+1)*sizeof(char)))==NULL)
    {
        printf("memory allocation failed");
        exit(1);
    }
    char* sequence2 = sequence;
    explore(&coin,n,sequence,sequence2);
    system("pause");
    return 0 ;
}


