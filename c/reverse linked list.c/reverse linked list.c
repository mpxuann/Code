#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
struct Node {
    ElementType Element;
    Position Next;
};

static List Read(); /* details omitted */
void Print( List L ); /* details omitted */
List Reverse( List L );

int main()
{
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    system("pause");
    return 0;
}

List Read()
{
    List L,p,q;
    p = (List)malloc(sizeof(struct Node));
    L = p;
    q = L;
    ElementType n,element,i;
    scanf("%d",&n);
    for(i = 0;i<n;i++)
    {
        scanf("%d",&element);
        p = (List)malloc(sizeof(struct Node));
        p->Element=element;
        q->Next = p;
        q = q->Next;
    }
    q->Next = NULL;
    return L;
}

void Print( List L)
{
    List p = L->Next;
    if(p == NULL)
    {
        return;
    }
    while(p!=NULL)
    {
        printf("%d ",p->Element);
        p = p->Next;
    }
}

List Reverse( List L)
{
    List pre,cur;
    cur = L->Next;
    if(cur == NULL)
        return L;
    pre = cur->Next;
    if(pre == NULL)
        return L;
    cur->Next = NULL;
    while(pre)
    {
        List next = pre->Next;
        pre->Next = cur;
        cur = pre;
        pre = next;
    }
    L->Next = cur;
    return L;
}