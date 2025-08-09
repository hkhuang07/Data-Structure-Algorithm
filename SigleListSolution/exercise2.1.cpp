#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

struct Node
{
    ElementType Element;
    struct Node *Next;
};

typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

//Stack Function
void MakeEmptyStack(Stack *S);
void Push(ElementType X, Stack S);
int IsEmptyStack(Stack S);
ElementType Pop (Stack S);
ElementType Top(Stack S);

//User Function
void InputElement(ElementType &X);
void InputStack(Stack &S);
void PrintElement(ElementType X);
void PrintStack(Stack S);
int Factories(int n);

int main()
{
    int n,f;
    printf("\n<======== PROGRAM ========>\n");
    Stack S;
    MakeEmptyStack(&S);

    printf("\n<====== Input Stack ======>\n");
    InputStack(S);
    printf("\n<===== Stack Inputed =====>\n");
    PrintStack(S);

    ElementType popped = Pop(S);
    printf("\n<=== Stack Pop 1 Element==>\n");
    PrintStack(S);
    printf("The popped element: %d \n", popped);

    ElementType pushelement;
    InputElement(pushelement);
    Push(pushelement,S);
    printf("\n<== Stack Push 1 Element ==>\n");
    PrintStack(S);

    printf("\n<===== Factories of N ====>\n");
    do{
        printf("Enter integer N (0<N<20): ");
        scanf("%d",&n);
    }while(n<=0 || n>=20);
    f = Factories(n);
    printf("Factories of n is: %d", f);
    printf("\n<=========================>\n");

    return 0;
}

//Stack Function
void MakeEmptyStack(Stack *S)
{
    *S = (Stack)malloc(sizeof(struct Node));
    if(*S == NULL)
    {
        printf("Menory allocation failed for Stack header!");
        exit(EXIT_FAILURE);
    }
    (*S)->Next = NULL;

}
void Push(ElementType X, Stack S)
{
    PtrToNode TmpCell;
    TmpCell = (PtrToNode)malloc(sizeof(struct Node));
    if (TmpCell == NULL)
    {
        printf("Memory allocation failed for new Node!");
        return;
    }
    TmpCell->Element = X;
    TmpCell->Next = S->Next;
    S->Next = TmpCell;
}

int IsEmptyStack(Stack S)
{
    return S->Next == NULL;
}

ElementType Pop (Stack S)
{
    if(IsEmptyStack(S))
    {
        printf("Stac is empty cannot pop!");
        return -1;
    }
    PtrToNode TmpCell=S->Next;
    ElementType PoppedElement;

    TmpCell = S->Next;
    S->Next = TmpCell->Next;
    PoppedElement = TmpCell->Element;
    free(TmpCell);

    return PoppedElement;
}
ElementType Top(Stack S)
{
    if(IsEmptyStack(S))
    {
        printf("Stack is empty, no top element");
        return -1;
    }
    return S->Next->Element;
}

//User Function
void InputElement(ElementType &X)
{
    printf("Enter element value: ");
    scanf("%d",&X);
}
void InputStack(Stack &S)
{
    int n;
    ElementType X;
    printf("Enter element quantity of Stack: ");
    scanf("%d",&n);
    
    for(int i=1; i<=n; i++)
    {
        printf("Element %d",i);
        InputElement(X);
        Push(X,S);
    }
}
void PrintElement(ElementType X)
{
    printf("|   %d  |\n",X);
}
void PrintStack(Stack S)
{
    if(IsEmptyStack(S))
    {
        printf("Stack is Empty!");
        return;
    }
    PtrToNode Current = S->Next;
    printf("---------\n");
    while(Current != NULL)
    {
        PrintElement(Current->Element);
        Current=Current->Next;
    }
    printf("---------\n");
}
int Factories(int n)
{
     /*
        n=5  (n > 0)
        -> n!= 5 * 4 * 3 * 2 * 1
        -> n! = n * (n-1)!
    */
    if(n<0)
        return -1;
    if(n==1)
        return n;
    else
        return n * (Factories(n-1));
    
}
