#include <stdio.h>
#include <stdlib.h> // Thư viện cho malloc và free

#define MAX 32

// Định nghĩa cấu trúc của một Node
typedef struct Node {
    int Element;
    struct Node *Next;
} Node;

// Định nghĩa các kiểu dữ liệu
typedef Node *PtrToNode;
typedef PtrToNode Position;
typedef PtrToNode List;

// Khai báo các hàm
void MakeNullList(List *L);
int IsEmptyList(List L);
void InsertAtEnd(int X, List L);
void InputList(List L, int *n);
void PrintList(List L);
void FindX(List L);
void SortList(List L);
void Swap(int *a, int *b);
void DeleteList(List L);

int main() {
    List L;
    int n;

    MakeNullList(&L);

    InputList(L, &n);
    printf("Original List:\n");
    PrintList(L);

    FindX(L);

    SortList(L);
    printf("\nList after sorting (ascending):\n");
    PrintList(L);

    // Giải phóng bộ nhớ
    DeleteList(L);

    return 0;
}

// 1. Lập danh sách: Khởi tạo danh sách rỗng (với một sentinel node)
void MakeNullList(List *L) {
    *L = (List)malloc(sizeof(Node)); 
    //Node* L = New Node
    if (*L == NULL) {
        printf("Out of memory!\n");
        return;
    }
    (*L)->Next = NULL;
}

// Kiểm tra danh sách rỗng
int IsEmptyList(List L) {
    return L->Next == NULL;
}

// Hàm hỗ trợ: Thêm một phần tử vào cuối danh sách
void InsertAtEnd(int X, List L) {
    Position P = L;
    while (P->Next != NULL) {
        P = P->Next;
    }

    Position tmpCell = (Position)malloc(sizeof(Node));
    if (tmpCell == NULL) {
        printf("Out of memory!\n");
        return;
    }
    tmpCell->Element = X;
    tmpCell->Next = NULL;
    P->Next = tmpCell;
}

// Hàm nhập dữ liệu cho danh sách
void InputList(List L, int *n) {
    printf("Enter number of elements: ");
    scanf("%d", n);

    if (*n <= 0) {
        printf("Invalid number of elements. The list will be empty.\n");
        return;
    }

    for (int i = 0; i < *n; i++) {
        int X;
        printf("Enter element %d: ", i + 1);
        scanf("%d", &X);
        InsertAtEnd(X, L);
    }
}

// 2. In ra danh sách vừa nhập
void PrintList(List L) {
    if (IsEmptyList(L)) {
        printf("List is empty.\n");
        return;
    }

    Position P = L->Next;
    while (P != NULL) {
        printf("%d ", P->Element);
        P = P->Next;
    }
    printf("\n");
}

// 3. Tìm giá trị X và in ra vị trí
void FindX(List L) {
    if (IsEmptyList(L)) {
        printf("\nList is empty. Cannot find X.\n");
        return;
    }

    int X, count = 0;
    printf("\nEnter number which you want to find: ");
    scanf("%d", &X);

    // Sử dụng mảng cố định để lưu vị trí (hạn chế của C cơ bản)
    int found_positions[MAX]; 
    int current_found_count = 0;

    Position P = L->Next;
    int pos = 1;

    while (P != NULL) {
        if (P->Element == X) {
            count++;
            if (current_found_count < MAX) {
                found_positions[current_found_count] = pos;
                current_found_count++;
            }
        }
        pos++;
        P = P->Next;
    }

    if (count > 0) {
        printf("Found %d in the list.\n", X);
        printf("It appears %d time(s).\n", count);
        printf("Appears at position(s): ");
        for (int i = 0; i < current_found_count; i++) {
            printf("%d ", found_positions[i]);
        }
        printf("\n");
    } else {
        printf("Value %d not found in the list.\n", X);
    }
}

// Hàm hỗ trợ: hoán đổi giá trị bằng con trỏ
void Swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// 4. Sắp xếp danh sách tăng dần (Selection Sort)
void SortList(List L) {
    if (IsEmptyList(L) || L->Next->Next == NULL) {
        return;
    }
    
    Position P, min_node, Q;
    for (P = L->Next; P->Next != NULL; P = P->Next) {
        min_node = P;
        for (Q = P->Next; Q != NULL; Q = Q->Next) {
            if (Q->Element < min_node->Element) {
                min_node = Q; 
            }
        }
        if (min_node != P) {
            Swap(&P->Element, &min_node->Element);
        }
    }
}

// Hàm giải phóng bộ nhớ
void DeleteList(List L) {
    Position P = L;
    while (P != NULL) {
        Position temp = P;
        P = P->Next;
        free(temp);
    }
}