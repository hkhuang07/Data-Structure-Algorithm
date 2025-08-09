/*
    Xây dựng chuogw trình quản lý lương nhân viên. Thông tin nhân vien bao gồm: mã nhân viên, họ tên, lương cơ bản, hệ số lương, số ngày công, lương. Trong đó lương căn bản = 1.150.000đ
    Yêu cầu:
    -   Sử dụng danh sách liên kết đơn
    -   Viết hàm nhập danh sách n nhân viên
    -   Viết hàm tính lương cho các nhân viên
        Lương = Lương cơ bản * Hệ số lương * ngày công /26
        *Chú ý: cần phải lưu trữ lại lương cho mỗi nhân viên sau khi tính.
    -   Viết hàm xuất bảng lương của các nhân viên
    -   Viết hàm tìm kiếm nhân viên theo họ tên
    -   Viết hàm sao chép danh sách 
    -   Sắp xếp danh sách các nhân viên tăng dần theo lương
    -   Viết hàm liệt kê tất cả các nhân viên có số ngày công >24
    -   Xây dựng hàm main minh họa các yêu cầu trên
*/  

#include <stdio.h>
#include <string.h>
#define BASE_SALARY 1150000
struct Employee
{
    char iD[10];
    char fullName[128];
    long baseSalary;
    float salaryCoefficient;
    int workingDays;
    double salary;
};
typedef Employee ElementType;

struct Node
{
    ElementType Element;
    Node *Next;
};
typedef Node *PtrToNode;
typedef PtrToNode Position; 
typedef PtrToNode List;

//Struct List Function
void MakeNullList(List &L);
void InsertElement(ElementType X, Position P);
int IsEmptyList(List L);
//Users Function
void InputElement(ElementType &X);
void InputList(List &L);
void PrintElement(ElementType X);
void PrintList(List L);
void SalaryCaculate(List L);
void PrintSalaryTable(List L);
void FindEmployeesByName(List L);
void SortListAscBySalary(List L);
void WorkingDaysGreather24(List L);

int main()
{   
    List L;
    MakeNullList(L);
    printf("\n<========== PROGRAM START =========>\n");
    InputList(L);
    printf("\nEmployees List: \n");
    PrintList(L);

    SalaryCaculate(L);
    printf("\nEmployees List Salary Updated: \n");
    PrintList(L);

    printf("\nEmployees Salaries Table: \n");
    PrintSalaryTable(L);

    printf("\nFind Employees by Full Name: \n");
    FindEmployeesByName(L);

    SortListAscBySalary(L);
    printf("\nEmployees List Sorted: \n");
    PrintList(L);

    printf("\nEmployees Have Working Days Greather 24 days: \n");
    WorkingDaysGreather24(L);

    printf("\n<==================================>\n");

    return 0;
}
void MakeNullList(List &L)
{
    L = new Node;
    L->Next = NULL;
}
void InsertElement(ElementType X, Position P)
{
    Position Tmp = new Node;
    if(Tmp == NULL)
    {
        printf("Error, Memory have no enought space for this allocate!\n");
        return;
    }
    Tmp->Element = X;
    Tmp->Next = P->Next;
    P->Next = Tmp;
}
int IsEmptyList(List L)
{
    return L->Next == NULL;
}

void InputElement(ElementType &X)
{
    printf("Enter Employee ID: "); fflush(stdin); gets(X.iD);
    printf("Enter Employee Full name: "); fflush(stdin); gets(X.fullName);
    printf("Enter Employee Salary Coefficient: "); scanf("%f",&X.salaryCoefficient);
    printf("Enter Employee Worrking Days: "); scanf("%d",&X.workingDays);
    X.baseSalary = BASE_SALARY;
    X.salary = 0;
}
void InputList(List &L)
{
    int n; 
    Position P = L; 
    ElementType E;
    printf("Enter quantity Employees: "); scanf("%d",&n);

    for(int i=1; i<=n; i++)
    {
        printf("Enter employee %d: \n",i);
        InputElement(E);
        InsertElement(E,P);
        P=P->Next;
    }
}
void PrintElement(ElementType X)
{
    printf("Employee ID: %s\n",X.iD);
    printf("Employee Full name: %s \n",X.fullName);
    printf("Employee Base Salary: %l \n",X.baseSalary);
    printf("Employee Salary Coefficient: %.2f \n",X.salaryCoefficient);
    printf("Employee Working Days: %d\n",X.workingDays);
    printf("Employee Salary: %.2f\n",X.salary);
}
/*void PrintList(List L)
{
    Position P=L->Next;
    while(P != NULL)
    {
        PrintElement(P->Element);
        printf("\n");
        P=P->Next;
    }
} */
void PrintList(List L)
{
    Position P = L->Next;
    if (IsEmptyList(L)) {
        printf("List is empty.\n");
        return;
    }

    printf("====================================================================================================\n");
    printf("%-10s | %-25s | %-12s | %-15s | %-12s |\n",
           "ID", "Full Name", "Base Salary", "Coefficient", "Working Days");
    printf("====================================================================================================\n");

    while(P != NULL)
    {
        printf("%-10s | %-25s | %-12ld | %-15.2f | %-12d |\n",
               P->Element.iD,
               P->Element.fullName,
               P->Element.baseSalary,
               P->Element.salaryCoefficient,
               P->Element.workingDays);
        P = P->Next;
    }
    printf("====================================================================================================\n");
}

void SalaryCaculate(List L)
{
    Position P=L->Next;
    while(P != NULL)
    {
       P->Element.salary = 
        (
            P->Element.baseSalary * P->Element.salaryCoefficient * ((float)P->Element.workingDays/26)
        );
        P=P->Next;
    }
}

void PrintSalaryTable(List L)
{
    Position P = L->Next;
    if (IsEmptyList(L)) {
        printf("Salary table is empty.\n");
        return;
    }

    printf("=========================================================\n");
    printf("%-10s | %-25s | %-15s |\n",
           "ID", "Full Name", "Final Salary"); 
    printf("=========================================================\n");

    while(P != NULL)
    {
        printf("%-10s | %-25s | %-15.2f |\n",
               P->Element.iD,
               P->Element.fullName,
               P->Element.salary);
        P = P->Next;
    }
    printf("=========================================================\n");
}
void FindEmployeesByName(List L)
{
    char Name[128];
    printf("Enter the employee which you want to find: "); fflush(stdin); gets(Name);
    Position P = L->Next;
    while(P!=NULL)
    {
        if(strcmp(P->Element.fullName,Name) == 0)
        {
            PrintElement(P->Element);
            printf("\n");
        }
        P=P->Next;
    }
}
void SortListAscBySalary(List L)
{
    Position P, Q, MinValue;
    ElementType Tmp;
    for(P=L->Next; P->Next!=NULL; P=P->Next){
        MinValue = P;
        for(Q=P->Next; Q!=NULL; Q=Q->Next){
            if(Q->Element.salary < MinValue->Element.salary)
                MinValue = Q;
        }
        if(MinValue != P)
        {
            Tmp = P->Element;
            P->Element = MinValue->Element;
            MinValue->Element = Tmp;
        }
    }

}
void WorkingDaysGreather24(List L)
{
    Position P = L->Next;
    while(P!=NULL)
    {
        if(P->Element.workingDays > 24)
        {
            PrintElement(P->Element);
            printf("\n");
        }
        P=P->Next;
    }
}