/*
    Sử dụng caaus truc danh sách liên kết thực hiện các yêu cầu sau: (Với kiểu các phần tử có kiểu phần tử là số nguyên)
    -Nhập lần lượt 2 danh sách - In ra từng danh sách vừa nhập
    -Sắp xếp từng danh sách tăng dần 
    -Trộn danh sách đã được sắp xếp tăng dần thành một danh sách cũng tăng dần.
*/
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
struct Node
{
    int Element;
    Node *Next; 
};
typedef Node *PtrToNode;
typedef PtrToNode Position;
typedef PtrToNode List;

//List Function
void MakeEmptyList(List &L);
void InsertList(ElementType X, Position P, List L);
void DeleteList(ElementType X, List L);
void FreeList(List L);
int IsEmptyList(List L);
int IsLast(Position P, List L);
Position FindPrevious(ElementType X, List L);
Position FindPosition(ElementType X, List L);

//User Function
void InputElement(ElementType &X);
void InputList(List &L,int n);
void PrintElemen(ElementType X);
void PrintList(List L);
void SortListASC(List L);
void Merge2List(List L1, List L2);

int main()
{
    List L1, L2;
    int n1, n2;

    MakeEmptyList(L1); 
    MakeEmptyList(L2);

    printf("Enter quantity of List 1: "); 
    scanf("%d",&n1);
    printf("Enter quantity of List 2: "); 
    scanf("%d",&n2);

    printf("Input List 1: \n");
    InputList(L1,n1);
    printf("Input List 2: \n");
    InputList(L2,n2);

    printf("Elements List 1: \n");
    PrintList(L1);
    printf("Elements List 2: \n");
    PrintList(L2);

    SortListASC(L1);
    SortListASC(L2);

    printf("\nList 1 Sorted (Ascending): \n");
    PrintList(L1);
    printf("\nList 2 Sorted (Ascending): \n");
    PrintList(L2);

    printf("\nMerge 2 List (Ascending): \n");
    Merge2List(L1,L2);

    return 0;
}

//User Function
void InputElement(ElementType &X)
{
    printf("-   Enter element: ");
    scanf("%d",&X);
}
void InputList(List &L, int n)
{
    ElementType X;
    Position P = L;
    for(int i=1; i<=n; i++)
    {
        printf("Element %d : \n",i);
        InputElement(X);
        InsertList(X,P,L);
        P=P->Next;
    }
    
}
void PrintElemen(ElementType X)
{
    printf("[Element %d]    ",X);
}
void PrintList(List L)
{
    int col=0;
    Position P=L->Next;
    while(P!=NULL)
    {
        PrintElemen(P->Element);
        col++;
        if(col==5)
        {
            printf("\n");
            col = 0;
        }
        P=P->Next;
    }
}

void SortListASC(List L)
{
    Position P, Q, Min;
    ElementType TmpCell;
    for(P=L->Next; P!=NULL; P=P->Next)
    {
        Min = P;
        for(Q=P->Next; Q!=NULL; Q=Q->Next)
        {
            if(Q->Element < Min->Element)
            {
                Min = Q;
            }
        }
        if(Min != P)
        {
            TmpCell = Min->Element;
            Min->Element = P->Element;
            P->Element = TmpCell;
        }
    }
}

void CopyList(List L, List LC)
{
    Position P = L->Next;
    Position Pc = LC->Next;
    while(P!=NULL)
    {
        Pc->Element = P->Element;
        Pc=Pc->Next;
        P = P->Next;
    }
}

void Merge2List(List L1, List L2)
{

    Position p1 = L1->Next;
    Position p2 = L2->Next;
    
    // Giải phóng bộ nhớ của danh sách đã trộn (nếu cần)
    // Lưu ý: free(mergedList) sẽ không giải phóng các node của L1 và L2
    // vì chúng đã được nối vào mergedList.
    // Để tránh lỗi, bạn có thể tạo các node mới thay vì nối lại.
    // Dưới đây là cách tạo node mới để không làm thay đổi L1 và L2 gốc:

    List mergedList_safe;
    MakeEmptyList(mergedList_safe);
    p1 = L1->Next;
    p2 = L2->Next;
    Position last = mergedList_safe;

    while (p1 != NULL && p2 != NULL)
    {
        Position TmpCell = new Node;
        if(p1->Element <= p2->Element)
        {
            TmpCell->Element = p1->Element;
            p1 = p1->Next;
        }
        else
        {
            TmpCell->Element = p2->Element;
            p2 = p2->Next;
        }
        TmpCell->Next = NULL;
        last->Next = TmpCell;
        last = TmpCell;
    }
    while (p1 != NULL)
    {
        Position TmpCell = new Node;
        TmpCell->Element = p1->Element;
        TmpCell->Next = NULL;
        last->Next = TmpCell;
        last = TmpCell;
        p1 = p1->Next;
    }
    while (p2 != NULL)
    {
        Position TmpCell = new Node;
        TmpCell->Element = p2->Element;
        TmpCell->Next = NULL;
        last->Next = TmpCell;
        last = TmpCell;
        p2 = p2->Next;
    }
    printf("\nMerged List: \n");
    PrintList(mergedList_safe);
    FreeList(mergedList_safe); // Giải phóng danh sách mới an toàn
}


//List Function
void MakeEmptyList(List &L)
{
    L = new Node;
    L->Next = NULL;
}   

void InsertList(ElementType X, Position P, List L)
{
    Position TmpCell;
    TmpCell = new Node;
    if(TmpCell ==  NULL)
    {
        printf("Out of space!!!");
    }
    else{
        TmpCell->Element = X;
        TmpCell->Next = P->Next;
        P->Next = TmpCell;
    }
}

void DeleteList(ElementType X, List L)
{
    Position P, TmpCell;
    P = FindPrevious(X, L);
    if(!IsLast(P,L))
    {
        TmpCell = P->Next;
        P->Next = TmpCell ->Next;
        delete TmpCell;
    }
}

void FreeList(List L)
{
    Position P, TmpCell;
    P = L;
    while (P!=NULL)
    {
        TmpCell = P;
        P = P->Next;
        delete TmpCell;
    }
}

int IsEmptyList(List L)
{
    return L->Next ==NULL;
}

int IsLast(Position P, List L)
{
    return(P->Next == NULL);
}

Position FindPrevious(ElementType X, List L)
{
    if(IsEmptyList(L))
        return NULL;
    
    Position P = L;
    while(P->Next != NULL)
    {
        if(P->Next->Element == X) 
            return P;
        P =  P->Next;
    }
    return NULL;
}
Position FindPosition(ElementType X, List L)
{
    if(IsEmptyList(L))
        return NULL;
    Position P = L->Next;
    while(P != NULL)
    {
        if(P->Element == X)
        {
            return P;
        }
        P= P->Next;
    }
    return NULL;
}
