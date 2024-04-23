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
ElementType uncertaintyA(ElementType n, List L,ElementType *ave);
ElementType uncertaintyB(ElementType n);
ElementType uncertainty(ElementType a,ElementType b);
void instruction();
void start();

ElementType main()
{
    start();
    List L;
    ElementType n,ans,Ua,Ub,delta,w,ave,i;
    scanf("%lf",&i);
    while(i)
    {
        instruction();
        scanf("%lf",&n);
        L = Read(n);
        printf("\ndelta=");
        scanf("%lf",&delta); 
        Ua = uncertaintyA(n,L,&ave);
        Ub = uncertaintyB(delta);
        ans = uncertainty(Ua,Ub);
        w = ans / ave * 100;
        printf("Ua = %lf\nUb = %lf\nUc = %lf\nw = %lf%%\n\n-------------------\nPlease enter your choice here(1.continue 0.quit): ",Ua,Ub,ans,w);
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

ElementType uncertaintyA(ElementType n, List L,ElementType *ave)
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
    ans = sqrt((double)(sum/(n-1)*n));
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