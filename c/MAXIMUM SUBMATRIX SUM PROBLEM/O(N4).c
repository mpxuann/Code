#include<time.h>
#include<stdio.h>
#include<stdlib.h>//include header

typedef long ElementType;
typedef ElementType *Arr;
typedef Arr *Matrix;//define elementTypes
long start,stop;
double duration;//set time variations

ElementType maxSubmat(Matrix a,ElementType n);
Matrix input(ElementType n);//function declaration;

ElementType main()
{
    ElementType n,max,k;
    Matrix mat;//define variations
    scanf("%ld",&n);//input N
    mat = input(n);//input matrix
    start = clock();//record the ticks when the function begins
    // for(k = 0;k<1000;k++)
        max = maxSubmat(mat,n);
    stop = clock();//stop when the function stops
    printf("Maximum submatrix = %ld\n",max);//check the max submatrix sum
    printf("Ticks = %ld\n",stop-start);//check the total ticks
    duration = (double)((stop - start))/CLK_TCK;//calculate the running time
    printf("running time = %lf\n",duration);//check duration 
    system("pause");
    return 0;
}


ElementType maxSubmat(Matrix a,ElementType n)
{
    ElementType FirstRow,FirstColum,i,j,sum,max;
    sum = max = 0;
    for(FirstRow = 0;FirstRow<n;FirstRow++)//2n+2
    {   
        for(FirstColum = 0;FirstColum<n;FirstColum++)//2n+2 && FirstRow(Row) and FirstColum(Colum) for mapping the first element
        {
            sum = 0;//1 time unit
            for(i = FirstRow;i<n;i++)//O(2n+2)
            {
                for(j = FirstColum;j<n;j++)//O(2n+2) && i and j for mapping the last element
                {
                    sum += a[i][j];
                }
                if(sum>max)
                    max = sum;//compare sum to max
            }
            sum = 0;
            for(j = FirstColum;j<n;j++)//O(2n+2) && i and j for mapping the last element
            {
                for(i = FirstRow;i<n;i++)//O(2n+2)
                {
                    sum += a[i][j];
                }
                if(sum>max)
                    max = sum;//compare sum to max
            }
        }  
    }
    return max;
}

Matrix input(ElementType n)
{
    ElementType i,j;
    Matrix a = (Matrix)malloc(n*sizeof(Arr));//allocate the space to store the pointer to each row
    for(i=0;i<n;i++)
    {
        a[i] = (Arr)malloc(n*sizeof(ElementType));//allocate the space to store the matrix
    }
    for(i = 0;i<n;i++)
    {
        for(j = 0;j<n;j++)
        {
            scanf("%ld",&a[i][j]);//input the matrix
        }
    }
    return a;
}