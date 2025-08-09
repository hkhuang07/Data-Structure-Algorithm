#include <iostream>
#include <vector> // Dùng để lưu vị trí xuất hiện của X
#include <algorithm> // Dùng để sắp xếp

// Định nghĩa cấu trúc của một Node
struct Node {
    int Element;
    Node* Next;
};

// Định nghĩa các kiểu dữ liệu cho dễ đọc
using PtrToNode = Node*;
using Position = PtrToNode;
using List = PtrToNode;

// 1. Lập danh sách: Khởi tạo danh sách rỗng
void MakeNullList(List &L) {
    L = new Node;
    L->Next = nullptr;
}

// Kiểm tra danh sách rỗng
bool IsEmptyList(List L) {
    return L->Next == nullptr;
}

// Thêm một phần tử vào cuối danh sách
void InsertAtEnd(int X, List L) {
    Position P = L;
    while (P->Next != nullptr) {
        P = P->Next;
    }
    Position tmpCell = new Node;
    tmpCell->Element = X;
    tmpCell->Next = nullptr;
    P->Next = tmpCell;
}

// 2. In ra danh sách vừa nhập
void PrintList(List L) {
    if (IsEmptyList(L)) {
        std::cout << "Empty list!." << std::endl;
        return;
    }
    Position P = L->Next;
    while (P != nullptr) {
        std::cout << P->Element << " ";
        P = P->Next;
    }
    std::cout << std::endl;
}

// 3. Tìm giá trị X
void FindValue(List L, int X) {
    if (IsEmptyList(L)) {
        std::cout << "List empty, can't find X." << std::endl;
        return;
    }
    
    int count = 0;
    int position = 0;
    std::vector<int> found_positions;
    Position P = L->Next;
    
    while (P != nullptr) {
        position++;
        if (P->Element == X) {
            count++;
            found_positions.push_back(position);
        }
        P = P->Next;
    }
    
    if (count > 0) {
        std::cout << "The value " << X << " is in the list." << std::endl;
        std::cout << "Display " << count << " spread." << std::endl; 
        std::cout << "Display the values: ";
        for (int pos : found_positions) {
            std::cout << pos << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "The value " << X << " is not in the list." << std::endl;
    }
}

// 4. Sắp xếp danh sách tăng dần
void SortList(List L) {
    if (IsEmptyList(L) || L->Next->Next == nullptr) {
        // Danh sách rỗng hoặc chỉ có một phần tử, không cần sắp xếp
        return;
    }

    Position current = L->Next;
    while (current != nullptr) {
        Position next_node = current->Next;
        while (next_node != nullptr) {
            if (current->Element > next_node->Element) {
                // Hoán đổi giá trị của hai node
                int temp = current->Element;
                current->Element = next_node->Element;
                next_node->Element = temp;
            }
            next_node = next_node->Next;
        }
        current = current->Next;
    }
}

// Giải phóng bộ nhớ của danh sách
void DeleteList(List L) {
    Position P = L;
    while (P != nullptr) {
        Position temp = P;
        P = P->Next;
        delete temp;
    }
    L = nullptr;
}


int main() {
    List L;
    int n, X;

    // 1. Lập danh sách
    MakeNullList(L);
    std::cout << "Enter the number of element: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Quantity is invalid." << std::endl;
        return 1;
    }

    for (int i = 0; i < n; i++) {
        std::cout << "Enter element " << i + 1 << ": ";
        std::cin >> X;
        InsertAtEnd(X, L);
    }

    // 2. In danh sách ban đầu
    std::cout << "\nList of recent entries:";
    PrintList(L);

    // 3. Tìm giá trị X
    std::cout << "\nEnter the value of X you want to find.: ";
    std::cin >> X;
    FindValue(L, X);

    // 4. Sắp xếp danh sách
    SortList(L);
    std::cout << "\nList after sorting in ascending order: ";
    PrintList(L);
    
    // Giải phóng bộ nhớ để tránh rò rỉ
    DeleteList(L);
    
    return 0;
}