/*
    Sử dụng cấu trúc danh sách liên kết thực hiện các yêu cầu sau (Với kiểu các phần tử là kiểu sinh viên có 3 trường mS, hoTen, diem):
    - Nhập danh sách 
    - Xuất danh sách 
    - Sắp xếp danh sách tăng dần theo điểm
*/
#include <stdio.h>

struct Student 
{
    char mS[10];
    char fullName[128];
    float mark;
};
typedef Student ElementType;

struct Node
{
    ElementType Elemement;
    Node *Next;
};
typedef Node *PtrToNode;
typedef PtrToNode Position;
typedef PtrToNode List;

void MakeNullList(List &L);
void InsertList(Position P, ElementType X);
int IsEmptyList(List L);

void InputStu(ElementType &X);
void InputList(List &L);
void PrintSt(ElementType X);
void PrintList(List L);
void SortListASC(List L);
void SortListDESC(List L);



int main()
{
    List L;
    MakeNullList(L);

    printf("\n<====== Program Start ======>\n");
    InputList(L);
    printf("\nStudent List: \n");
    PrintList(L);
    printf("\nSorted List ASCENDING by Mark: \n");
    SortListASC(L);
    PrintList(L);
    printf("\nSorted List DESCENDING by Mark: \n");
    SortListDESC(L);
    PrintList(L);

    return 0;
}

void MakeNullList(List &L){
    L = new Node;
    L->Next = NULL;
}
int IsEmptyList(List L)
{
    return L->Next ==NULL;
}
void InsertList(Position P, ElementType X){
    Position Tmp = new Node;
    if(Tmp == NULL)
    {
        printf("Out of space!!!");\
        return;
    }
    Tmp->Elemement = X;
    Tmp->Next = P->Next;
    P->Next = Tmp;
}


void InputStu(ElementType &X)
{
    printf("Enter Student ID: ");
    fflush(stdin); gets(X.mS);
    printf("Enter Student Fullname: ");
    fflush(stdin); gets(X.fullName);
    printf("Enter Student mark: ");
    scanf("%f",&X.mark);
}
void InputList(List &L)
{
    Position P = L;
    ElementType X;
    int n;

    printf("Enter students quantity: "); scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {
        printf("Enter student %d: \n",i);
        InputStu(X);
        InsertList(P,X);
        P=P->Next;
    }
}
void PrintSt(ElementType X){
    printf("-   Student ID: %s\n",X.mS);
    printf("-   Student Fullname: %s\n",X.fullName);
    printf("-   Student Mark: %.2f\n",X.mark);
}
void PrintList(List L)
{
    Position P=L->Next;
    while(P!=NULL)
    {
        PrintSt(P->Elemement);
        printf("\n");
        P=P->Next;
    }
}
void SortListASC(List L)
{
    if(IsEmptyList(L) || L->Next->Next == NULL ){
        printf("List is Empty!!!");
        return;
    }
    Position P, Q, MinMark;
    ElementType Tmp;
    for(P=L->Next; P->Next!=NULL; P=P->Next){
        MinMark = P;
        for(Q=P->Next; Q!=NULL; Q=Q->Next){
            if(Q->Elemement.mark < MinMark->Elemement.mark)
            {
                MinMark = Q;
            }
        }
        if(MinMark != P)
        {
            Tmp = MinMark->Elemement;
            MinMark->Elemement = P->Elemement;
            P->Elemement = Tmp;
        }
    }
}

void SortListDESC(List L)
{
    Position P, Q;
    ElementType Tmp;
    for(P=L->Next; P->Next !=NULL; P=P->Next)
    {
        for(Q=P->Next; Q!=NULL; Q=Q->Next){
            if(Q->Elemement.mark > P->Elemement.mark){
                Tmp = P->Elemement;
                P->Elemement = Q->Elemement;
                Q->Elemement = Tmp;
            }
        }
    }
}
