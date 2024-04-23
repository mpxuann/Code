#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef double ElementType;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
struct Node
{
    ElementType element;
    List Next;
};

List Read(ElementType n);
ElementType STD_n(ElementType n, List L,ElementType *ave);
ElementType uncertaintyB(ElementType n);
ElementType uncertainty(ElementType a,ElementType b);
ElementType averageDeviation(ElementType n,List L,ElementType *ave);
void instruction();
void start();

ElementType main()
{
    start();
    List L;
    ElementType n,U,STD__n,STD__n_1,delta,w,ave,i,aved;
    scanf("%lf",&i);
    while(i)
    {
        instruction();
        scanf("%lf",&n);
        L = Read(n);
        printf("\ndelta=");
        scanf("%lf",&delta); 
        STD__n = STD_n(n,L,&ave);
        STD__n_1 = STD__n*sqrt(n/(n-1));
    
        aved = averageDeviation(n,L,&ave);
        w = U / ave * 100;
        printf("STD(n) = %lf\nSTD(n-1) = %lf\nw = %lf%%\n\n-------------------\nPlease enter your choice here(1.continue 0.quit): ",STD__n,STD__n_1,w);
        scanf("%lf",&i);
    } 
    printf("\nBye! See you next time!\n\n");
    system("pause");
    return 0;
}

List Read(ElementType n)
{
    List L,tmpCell,scanCell;
    tmpCell = (List)malloc(sizeof(struct Node));
    L = tmpCell;
    L->Next = NULL;
    ElementType i,tmp;
    printf("\ndata:\n");
    for(i = 0;i<n;i++)
    {
        scanf("%lf",&tmp);
        scanCell = (List)malloc(sizeof(struct Node));
        scanCell->element = tmp;
        tmpCell->Next = scanCell;
        tmpCell = scanCell;
    }
    tmpCell->Next = NULL;
    return L;
}

ElementType STD_n(ElementType n, List L,ElementType *ave)
{
    List tmpCell;
    ElementType sum,ans;
    sum = 0;
    tmpCell = L;
    while (tmpCell->Next!=NULL)
    {
        sum+=tmpCell->Next->element;
        tmpCell = tmpCell->Next;
    }
    *ave = (double)(sum/n);
    printf("\nave = %lf\n",*ave);
    sum = 0;
    tmpCell = L;
    while (tmpCell->Next!=NULL)
    {
        sum += pow(tmpCell->Next->element-*ave,2);
        tmpCell = tmpCell->Next;
    }
    ans = sqrt((double)(sum/n));
    return ans;
    
}

ElementType uncertaintyB(ElementType n)
{
    return (double)n/sqrt(3);
}

void instruction()
{
    printf("\ninput your data and delta of instruments:\n\nN=");
}

ElementType uncertainty(ElementType a,ElementType b)
{
    return sqrt(pow(a,2)+pow(b,2));
}

void start()
{
    printf("-------------------------------------\nThank you for using this simple data processing program!\nPlease enter your choice here(1.continue 0.quit): ");

}

ElementType averageDeviation(ElementType n,List L,ElementType *ave)
{
    List tempCell;
    ElementType sum,aved;
    tempCell = L;
    sum = 0;
    while(tempCell->Next!=NULL)
    {
        sum+=sqrt(pow(tempCell->Next->element-*ave,2));
        tempCell = tempCell->Next;
    }
    return sum/n;
}