/*
    Chương trình quản lý Danh Sách Liên Kết Đơn
    Các hàm chức năng bao gồm:
    1. Tạo danh sách rỗng.
    2. Chèn, cập nhật, xóa phần tử.
    3. Duyệt và in danh sách.
    4. Tìm kiếm phần tử.
    5. Giải phóng bộ nhớ.
*/
#include <stdio.h>      // Thư viện chuẩn cho nhập xuất
#include <stdlib.h>     // Thư viện chuẩn cho cấp phát và giải phóng bộ nhớ (malloc, free)
#include <string.h>     // Thư viện chuẩn cho xử lý chuỗi (string.h)

// Định nghĩa cấu trúc Object để lưu trữ dữ liệu của mỗi phần tử
struct Object
{
    int integerProperty;        // Thuộc tính số nguyên
    float floatProperty;        // Thuộc tính số thực
    char charProperty;          // Thuộc tính ký tự
    char string01[16];          // Thuộc tính chuỗi 1
    char string02[64];          // Thuộc tính chuỗi 2 
};

// Định nghĩa kiểu dữ liệu cho Element của Node
typedef struct Object ElementType;

// Định nghĩa cấu trúc Node của danh sách liên kết
struct Node
{
    ElementType Element;      // Dữ liệu của Node
    struct Node *Next;        // Con trỏ tới Node tiếp theo
};

// Định nghĩa các kiểu dữ liệu mới để dễ dàng sử dụng
typedef struct Node *PtrToNode;
typedef PtrToNode Position;
typedef PtrToNode List;

/* === Khai báo các hàm liên quan đến Danh sách liên kết === */
void MakeEmptyList(List *L);
void InsertList(ElementType X, Position P);
void UpdateList(ElementType X, List L);
void DeleteList(ElementType X, List L);
void FreeList(List L);
int IsEmptyList(List L);
int IsLast(Position P);
ElementType Retrieve(Position P);
Position FindPositionElement(ElementType X, List L);
Position FindPreviousElement(ElementType X, List L);
void clear_input_buffer();

/* === Khai báo các hàm chức năng cho người dùng === */
void InputElement(ElementType *X);
void InputList(List L);
void PrintElement(ElementType X);
void PrintList(List L);

int main()
{
    List L;
    int choice;
    ElementType newElement;
    
    // 1. Khởi tạo danh sách rỗng
    MakeEmptyList(&L);
    printf("<--------- LINK LIST MANAGEMENT PROGRAM --------->\n");

    // 2. Nhập danh sách ban đầu từ người dùng
    InputList(L);
    
    // 3. In danh sách vừa nhập
    printf("\n--- LIST ENTRIES ---\n");
    PrintList(L);

    // 4. Vòng lặp chính để người dùng chọn chức năng
    while(1) {
        printf("\n\n--- MENU CHUC NANG ---\n");
        printf("1. Update an element\n");
        printf("2. Delete an element\n");
        printf("3. Print all list\n");
        printf("4. Exit program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clear_input_buffer();

        switch (choice)
        {
        case 1:
            // Cập nhật phần tử
            printf("\n--- UDATE AN ELEMENT ---\n");
            printf("Enter the information of the element to be updated: \n");
            InputElement(&newElement);
            UpdateList(newElement, L);
            break;
        case 2:
            // Xóa phần tử
            printf("\n--- DELETE AN ELEMENT ---\n");
            printf("Enter the information of the element to be deleted. (just integerProperty): \n");
            printf("Nhap integer property: ");
            scanf("%d", &newElement.integerProperty);
            DeleteList(newElement, L);
            break;
        case 3:
            // In danh sách
            printf("\n--- CURRENT LIST ---\n");
            PrintList(L);
            break;
        case 4:
            // Thoát
            printf("\n<--------- END PROGRAM --------->\n");
            FreeList(L);
            return 0;
        default:
            printf("Invalid choice! Please try again..\n");
            break;
        }
    }
    
    return 0;
}

/* === Các hàm chức năng cho người dùng === */

// Hàm xóa bộ đệm bàn phím sau khi dùng scanf
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Hàm nhập dữ liệu cho một phần tử
void InputElement(ElementType *X)
{
    printf("Enter integer property: "); 
    scanf("%d", &X->integerProperty);
    printf("Enter float property: "); 
    scanf("%f", &X->floatProperty);
    printf("Enter char property: "); 
    clear_input_buffer(); // Xóa bộ đệm trước khi đọc ký tự
    scanf("%c", &X->charProperty);
    printf("Enter string 1 property: "); 
    clear_input_buffer();
    fgets(X->string01, 16, stdin);
    X->string01[strcspn(X->string01, "\n")] = 0; //Delete \n do fgets
    printf("Enter string 2 property: "); 
    fflush(stdin);
    scanf("%s", &X->string02);
    X->string02[strcspn(X->string02, "\n")] = 0;
}

// Hàm nhập danh sách từ người dùng
void InputList(List L)
{
    int n, i;
    ElementType X;
    Position P = L;

    printf("Enter quantity of element: ");
    scanf("%d", &n);
    clear_input_buffer();
    
    for (i = 0; i < n; i++)
    {
        printf("\nEnter the information of element %d:\n", i + 1);
        InputElement(&X);
        InsertList(X, P);
        P = P->Next; // Di chuyển con trỏ P đến vị trí cuối cùng
    }
}

// Hàm in dữ liệu của một phần tử
void PrintElement(ElementType X)
{
    printf("- Integer property: %d\n", X.integerProperty);
    printf("- Float property: %f\n", X.floatProperty);
    printf("- Char property: %c\n", X.charProperty);
    printf("- String 1 property: %s\n", X.string01);
    printf("- String 2 property: %s\n", X.string02);
}

// Hàm in toàn bộ danh sách
void PrintList(List L)
{
    Position P = L->Next; 
    if (IsEmptyList(L))
    {
        printf("Empty List.\n");
        return;
    }
    
    int i = 1;
    while(P != NULL)
    {
        printf("Element %d:\n", i++);
        PrintElement(P->Element);
        printf("\n");
        P = P->Next;
    }
}

/* === Các hàm cơ bản của Danh sách liên kết đơn === */

// Hàm tạo danh sách rỗng (tạo một node đầu rỗng - sentinel node)
void MakeEmptyList(List *L)
{
    *L = (List)malloc(sizeof(struct Node)); // Cấp phát bộ nhớ cho node đầu
    if (*L == NULL) {
        printf("Error, not enough memory to allocate !\n");
        exit(1); // Thoát chương trình nếu không cấp phát được
    }
    (*L)->Next = NULL; // Con trỏ Next của node đầu trỏ về NULL
}

// Hàm chèn một phần tử X vào sau vị trí P
void InsertList(ElementType X, Position P)
{
    Position TmpCell;
    TmpCell = (Position)malloc(sizeof(struct Node));
    if (TmpCell == NULL)
    {
        printf("Error, not enough memory to allocate!\n");
        exit(1);
    }
    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}

// Hàm cập nhật một phần tử có sẵn trong danh sách
void UpdateList(ElementType X, List L)
{
    Position P = FindPositionElement(X, L);
    if (P != NULL)
    {
        // Nếu tìm thấy phần tử, cập nhật giá trị
        P->Element = X;
        printf("Update element successfully!\n");
    }
    else
    {
        printf("Could not find element with integerProperty = %d to update.\n", X.integerProperty);
    }
}

// Hàm xóa một phần tử khỏi danh sách
void DeleteList(ElementType X, List L)
{
    Position P, TmpCell;
    P = FindPreviousElement(X, L);
    if (P != NULL && P->Next != NULL)
    {
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free(TmpCell); // Giải phóng bộ nhớ của node đã xóa
        printf("Delete element successfully!\n");
    }
    else
    {
        printf("Cannot find element to delete.\n");
    }
}

// Hàm giải phóng toàn bộ bộ nhớ của danh sách
void FreeList(List L) 
{
    Position P = L;
    while (P != NULL) 
    {
        Position temp = P;
        P = P->Next;
        free(temp); // Giải phóng từng node một
    }
}

// Hàm kiểm tra xem danh sách có rỗng không
int IsEmptyList(List L)
{
    // Danh sách rỗng nếu node đầu trỏ tới NULL
    return L->Next == NULL;
}

// Hàm kiểm tra xem P có phải là node cuối cùng không
int IsLast(Position P)
{
    // Node cuối cùng là node có con trỏ Next là NULL
    return P->Next == NULL;
}

// Hàm lấy dữ liệu của một node
ElementType Retrieve(Position P)
{
    // Trả về dữ liệu của node P
    return P->Element;
}

// Hàm tìm kiếm vị trí của một phần tử dựa trên thuộc tính integerProperty
Position FindPositionElement(ElementType X, List L)
{
    Position P = L->Next;
    while (P != NULL)
    {
        if (P->Element.integerProperty == X.integerProperty)
        {
            return P; // Trả về con trỏ tới node nếu tìm thấy
        }
        P = P->Next;
    }
    return NULL; // Trả về NULL nếu không tìm thấy
}

// Hàm tìm kiếm vị trí của node đứng trước một phần tử
Position FindPreviousElement(ElementType X, List L)
{
    Position P = L;
    while (P->Next != NULL)
    {
        // So sánh bằng integerProperty để đảm bảo tính duy nhất
        if (P->Next->Element.integerProperty == X.integerProperty)
        {
            return P; // Trả về con trỏ tới node trước đó
        }
        P = P->Next;
    }
    return NULL; // Trả về NULL nếu không tìm thấy
}