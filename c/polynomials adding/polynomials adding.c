#include <stdio.h>
#include <stdlib.h>
typedef struct Node *PtrToNode;
struct Node  {
    int Coefficient;
    int Exponent;
    PtrToNode Next;
};
typedef PtrToNode Polynomial;

// Polynomial Read(); /* details omitted */
// void Print( Polynomial p ); /* details omitted */
Polynomial Add( Polynomial a, Polynomial b );

int main()
{
    Polynomial a, b, s;
    a = Read();
    b = Read();
    s = Add(a, b);
    Print(s);
    return 0;
}

/* Your function will be put here */

    Polynomial Add( Polynomial a, Polynomial b )
    {
        if(a->Next == NULL)
            return b;
        if(b->Next == NULL)
            return a;
        Polynomial tmp,p,q;
        p = a->Next;
        q = b->Next;
        Polynomial c = (Polynomial)malloc(sizeof(struct Node));
        Polynomial head = c;
        head->Next = NULL;
        while(p && q)
        {
            tmp = (Polynomial)malloc(sizeof(struct Node));
            if(p->Exponent>q->Exponent)
            {
                tmp->Coefficient = p->Coefficient;
                tmp->Exponent = p->Exponent;
                c->Next = tmp;
                c = c->Next;
                p = p->Next;
            }
            else if(p->Exponent<q->Exponent)
            {
                tmp->Coefficient = q->Coefficient;
                tmp->Exponent = q->Exponent;
                c->Next = tmp;
                c = c->Next;
                q = q->Next;
            }
            else if(p->Exponent==q->Exponent)
            {
                tmp->Coefficient = p->Coefficient+q->Coefficient;
                tmp->Exponent = q->Exponent;
                if(tmp->Coefficient == 0)
                {
                    p = p->Next;
                    q = q->Next;
                }
                else
                {
                    c->Next = tmp;
                    c = c->Next;
                    p = p->Next;
                    q = q->Next;
                }
            }
    
        }
        if(q)
        {
            c->Next = q;
        }
        if(p)
        {
            c->Next = p;
        }
        return head;
    }