#include <iostream>
#include <cstdio>
#include <new>

// Cấu trúc danh sách liên kết
typedef int ElementType;
struct Node {
    ElementType Element;
    Node* Next;
};
typedef Node* PtrToNode;
typedef PtrToNode Position;
typedef PtrToNode List;

// Khai báo hàm
// Các hàm quản lý danh sách
void MakeEmptyList(List& L);
void FreeList(List& L);

// Các hàm nhập/xuất và xử lý dữ liệu
void InputElement(ElementType& X);
void InputList(List& L, int n);
void PrintElement(const ElementType& X);
void PrintList(const List& L);
void SortListASC(List L);
List MergeSortedLists(List L1, List L2);

int main() {
    List L1, L2;
    int n1, n2;

    MakeEmptyList(L1);
    MakeEmptyList(L2);

    std::cout << "Enter quantity of List 1: ";
    std::scanf("%d", &n1);
    std::cout << "Enter quantity of List 2: ";
    std::scanf("%d", &n2);

    std::cout << "Input List 1: \n";
    InputList(L1, n1);
    std::cout << "Input List 2: \n";
    InputList(L2, n2);

    std::cout << "\nElements List 1: \n";
    PrintList(L1);
    std::cout << "\nElements List 2: \n";
    PrintList(L2);

    SortListASC(L1);
    SortListASC(L2);

    std::cout << "\nList 1 Sorted (Ascending): \n";
    PrintList(L1);
    std::cout << "\nList 2 Sorted (Ascending): \n";
    PrintList(L2);

    List mergedList = MergeSortedLists(L1, L2);
    std::cout << "\nMerged List (Ascending): \n";
    PrintList(mergedList);

    // Giải phóng bộ nhớ
    FreeList(L1);
    FreeList(L2);
    FreeList(mergedList);

    return 0;
}

// Định nghĩa hàm

/**
 * @brief Khởi tạo một danh sách rỗng với node đầu (header node).
 * @param L Danh sách cần khởi tạo.
 */
void MakeEmptyList(List& L) {
    L = new (std::nothrow) Node;
    if (L == nullptr) {
        std::cerr << "Out of space!!! Cannot allocate header node." << std::endl;
        exit(1);
    }
    L->Next = nullptr;
}

/**
 * @brief Nhập dữ liệu cho danh sách.
 * @param L Danh sách cần nhập.
 * @param n Số lượng phần tử cần nhập.
 */
void InputList(List& L, int n) {
    ElementType X;
    Position last = L; // Con trỏ theo dõi node cuối cùng để chèn hiệu quả

    for (int i = 0; i < n; ++i) {
        std::printf("Element %d: \n", i + 1);
        InputElement(X);

        Node* newNode = new (std::nothrow) Node;
        if (newNode == nullptr) {
            std::cerr << "Out of space!!! Cannot allocate new node." << std::endl;
            return;
        }
        newNode->Element = X;
        newNode->Next = nullptr;

        last->Next = newNode;
        last = newNode;
    }
}

/**
 * @brief Nhập một phần tử số nguyên.
 * @param X Biến lưu giá trị nhập.
 */
void InputElement(ElementType& X) {
    std::printf("- Enter element: ");
    std::scanf("%d", &X);
}

/**
 * @brief In một phần tử.
 * @param X Phần tử cần in.
 */
void PrintElement(const ElementType& X) {
    std::printf("[Element %d]   ", X);
}

/**
 * @brief In toàn bộ danh sách.
 * @param L Danh sách cần in.
 */
void PrintList(const List& L) {
    int col = 0;
    Position P = L->Next;
    while (P != nullptr) {
        PrintElement(P->Element);
        col++;
        if (col == 5) {
            std::printf("\n");
            col = 0;
        }
        P = P->Next;
    }
    if (col != 0) {
        std::printf("\n");
    }
}

/**
 * @brief Sắp xếp danh sách tăng dần bằng thuật toán Selection Sort.
 * @param L Danh sách cần sắp xếp.
 */
void SortListASC(List L) {
    Position P, Q, Min;
    ElementType temp;
    for (P = L->Next; P != nullptr; P = P->Next) {
        Min = P;
        for (Q = P->Next; Q != nullptr; Q = Q->Next) {
            if (Q->Element < Min->Element) {
                Min = Q;
            }
        }
        if (Min != P) {
            temp = Min->Element;
            Min->Element = P->Element;
            P->Element = temp;
        }
    }
}

/**
 * @brief Trộn hai danh sách đã sắp xếp thành một danh sách mới.
 * @param L1 Danh sách thứ nhất (đã được sắp xếp).
 * @param L2 Danh sách thứ hai (đã được sắp xếp).
 * @return Danh sách mới đã được trộn và sắp xếp.
 */
List MergeSortedLists(List L1, List L2) {
    List mergedList;
    MakeEmptyList(mergedList);

    Position p1 = L1->Next;
    Position p2 = L2->Next;
    Position last = mergedList;

    while (p1 != nullptr && p2 != nullptr) {
        Position newNode = new (std::nothrow) Node;
        if (newNode == nullptr) {
            std::cerr << "Out of space!!! Cannot allocate new node." << std::endl;
            return nullptr;
        }

        if (p1->Element <= p2->Element) {
            newNode->Element = p1->Element;
            p1 = p1->Next;
        } else {
            newNode->Element = p2->Element;
            p2 = p2->Next;
        }
        newNode->Next = nullptr;
        last->Next = newNode;
        last = newNode;
    }

    // Nối các phần tử còn lại (nếu có)
    while (p1 != nullptr) {
        Position newNode = new (std::nothrow) Node;
        if (newNode == nullptr) {
            std::cerr << "Out of space!!! Cannot allocate new node." << std::endl;
            return nullptr;
        }
        newNode->Element = p1->Element;
        newNode->Next = nullptr;
        last->Next = newNode;
        last = newNode;
        p1 = p1->Next;
    }

    while (p2 != nullptr) {
        Position newNode = new (std::nothrow) Node;
        if (newNode == nullptr) {
            std::cerr << "Out of space!!! Cannot allocate new node." << std::endl;
            return nullptr;
        }
        newNode->Element = p2->Element;
        newNode->Next = nullptr;
        last->Next = newNode;
        last = newNode;
        p2 = p2->Next;
    }

    return mergedList;
}

/**
 * @brief Giải phóng bộ nhớ của toàn bộ danh sách.
 * @param L Danh sách cần giải phóng.
 */
void FreeList(List& L) {
    if (L == nullptr) return;

    Position P = L;
    while (P != nullptr) {
        Position TmpCell = P;
        P = P->Next;
        delete TmpCell;
    }
    L = nullptr;
}