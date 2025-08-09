#include <stdio.h>
#include <stdlib.h> // Để sử dụng malloc, free, exit

// Định nghĩa kiểu dữ liệu cho phần tử trong cây
typedef int ElementType;

// Cấu trúc một Node trong Cây Nhị Phân
struct Node
{
    ElementType Element;    // Dữ liệu của nút
    struct Node *Left;      // Con trỏ tới cây con bên trái
    struct Node *Right;     // Con trỏ tới cây con bên phải
};

// Định nghĩa kiểu con trỏ tới Node
typedef struct Node *PtrToNode;
typedef PtrToNode BinaryTree; // Cây Nhị Phân được đại diện bởi con trỏ tới nút gốc

// ====================================================================
// KHAI BÁO CÁC HÀM CƠ BẢN CỦA CÂY NHỊ PHÂN TÌM KIẾM
// ====================================================================

// Tạo một cây rỗng (trả về NULL) hoặc giải phóng cây hiện có
BinaryTree MakeEmptyTree(BinaryTree T);

// Tạo một nút mới với giá trị X
PtrToNode CreateNode(ElementType X);

// Chèn một phần tử vào cây nhị phân tìm kiếm
BinaryTree Insert(ElementType X, BinaryTree T);

// Tìm kiếm một phần tử trong cây
PtrToNode Find(ElementType X, BinaryTree T);

// Tìm phần tử nhỏ nhất trong cây
PtrToNode FindMin(BinaryTree T);

// Tìm phần tử lớn nhất trong cây
PtrToNode FindMax(BinaryTree T);

// Xóa một phần tử khỏi cây (đây là một hàm phức tạp hơn)
// Đối với ví dụ này, tôi sẽ bỏ qua hàm xóa để giữ chương trình cơ bản và dễ hiểu hơn.
// BinaryTree Delete(ElementType X, BinaryTree T);

// Duyệt cây theo thứ tự giữa (In-order traversal: Left -> Root -> Right)
void InOrderTraversal(BinaryTree T);

// Duyệt cây theo thứ tự trước (Pre-order traversal: Root -> Left -> Right)
void PreOrderTraversal(BinaryTree T);

// Duyệt cây theo thứ tự sau (Post-order traversal: Left -> Right -> Root)
void PostOrderTraversal(BinaryTree T);

// Giải phóng tất cả bộ nhớ được cấp phát cho cây
void DestroyTree(BinaryTree T);

// ====================================================================
// CÁC HÀM HỖ TRỢ CHO VIỆC NHẬP/XUẤT VÀ HIỂN THỊ CÂY
// ====================================================================

// Nhập giá trị cho một phần tử
void InputElement(ElementType *X);

// Nhập các phần tử vào cây (tương tác)
void InputTree(BinaryTree *T);

// In ra giá trị của một phần tử
void PrintElement(ElementType X);

// In ra cấu trúc cây một cách trực quan (theo chiều ngang)
void PrintTreeStructure(BinaryTree T, int level);


// ====================================================================
// HÀM MAIN VÀ TRIỂN KHAI CÁC HÀM
// ====================================================================

int main()
{
    BinaryTree MyTree = NULL; // Khởi tạo cây rỗng

    printf("========= INPUT BINARY SEARCH TREE =========\n");
    InputTree(&MyTree); // Nhập các phần tử vào cây

    printf("\n========= TREE STRUCTURE =========\n");
    PrintTreeStructure(MyTree, 0); // In cấu trúc cây

    printf("\n========= TRAVERSALS =========\n");
    printf("In-order Traversal (Left-Root-Right): ");
    InOrderTraversal(MyTree);
    printf("\n");

    printf("Pre-order Traversal (Root-Left-Right): ");
    PreOrderTraversal(MyTree);
    printf("\n");

    printf("Post-order Traversal (Left-Right-Root): ");
    PostOrderTraversal(MyTree);
    printf("\n");

    printf("\n========= SEARCH OPERATIONS =========\n");
    ElementType searchVal;
    printf("Enter value to search: ");
    scanf("%d", &searchVal);
    PtrToNode foundNode = Find(searchVal, MyTree);
    if (foundNode != NULL)
    {
        printf("Element %d found in the tree.\n", searchVal);
    }
    else
    {
        printf("Element %d not found in the tree.\n", searchVal);
    }

    PtrToNode minNode = FindMin(MyTree);
    if (minNode != NULL)
    {
        printf("Minimum element in tree: %d\n", minNode->Element);
    }
    else
    {
        printf("Tree is empty. No minimum element.\n");
    }

    PtrToNode maxNode = FindMax(MyTree);
    if (maxNode != NULL)
    {
        printf("Maximum element in tree: %d\n", maxNode->Element);
    }
    else
    {
        printf("Tree is empty. No maximum element.\n");
    }

    // Giải phóng bộ nhớ của cây khi kết thúc chương trình
    printf("\n========= FREEING TREE MEMORY =========\n");
    DestroyTree(MyTree);
    MyTree = NULL; // Đặt con trỏ gốc về NULL sau khi giải phóng
    printf("Tree memory freed.\n");

    return 0;
}

// ====================================================================
// Định nghĩa các hàm cơ bản của Cây Nhị Phân Tìm Kiếm
// ====================================================================

BinaryTree MakeEmptyTree(BinaryTree T)
{
    if (T != NULL)
    {
        DestroyTree(T); // Giải phóng các nút hiện có nếu cây không rỗng
    }
    return NULL; // Trả về NULL để biểu thị cây rỗng
}

PtrToNode CreateNode(ElementType X)
{
    PtrToNode NewNode = (PtrToNode)malloc(sizeof(struct Node));
    if (NewNode == NULL)
    {
        fprintf(stderr, "Memory allocation failed for new node!\n");
        exit(EXIT_FAILURE); // Thoát chương trình nếu không cấp phát được
    }
    NewNode->Element = X;
    NewNode->Left = NULL;
    NewNode->Right = NULL;
    return NewNode;
}

BinaryTree Insert(ElementType X, BinaryTree T)
{
    // Nếu cây rỗng, tạo nút mới và đặt làm gốc
    if (T == NULL)
    {
        T = CreateNode(X);
    }
    // Nếu X nhỏ hơn giá trị nút hiện tại, chèn vào cây con bên trái
    else if (X < T->Element)
    {
        T->Left = Insert(X, T->Left);
    }
    // Nếu X lớn hơn giá trị nút hiện tại, chèn vào cây con bên phải
    else if (X > T->Element) // Bỏ qua nếu X bằng Element (không chèn trùng lặp)
    {
        T->Right = Insert(X, T->Right);
    }
    // Nếu X đã tồn tại, không làm gì (hoặc có thể xử lý lỗi/đếm số lần xuất hiện)
    return T; // Trả về con trỏ tới nút gốc (hoặc nút đã được chèn vào)
}

PtrToNode Find(ElementType X, BinaryTree T)
{
    if (T == NULL)
    {
        return NULL; // Không tìm thấy
    }
    if (X < T->Element)
    {
        return Find(X, T->Left); // Tìm trong cây con bên trái
    }
    else if (X > T->Element)
    {
        return Find(X, T->Right); // Tìm trong cây con bên phải
    }
    else
    {
        return T; // Tìm thấy nút
    }
}

PtrToNode FindMin(BinaryTree T)
{
    if (T == NULL)
    {
        return NULL; // Cây rỗng
    }
    else if (T->Left == NULL)
    {
        return T; // Nút hiện tại là nhỏ nhất (không có con trái)
    }
    else
    {
        return FindMin(T->Left); // Tiếp tục tìm trong cây con bên trái
    }
}

PtrToNode FindMax(BinaryTree T)
{
    if (T == NULL)
    {
        return NULL; // Cây rỗng
    }
    else if (T->Right == NULL)
    {
        return T; // Nút hiện tại là lớn nhất (không có con phải)
    }
    else
    {
        return FindMax(T->Right); // Tiếp tục tìm trong cây con bên phải
    }
}

void InOrderTraversal(BinaryTree T)
{
    if (T != NULL)
    {
        InOrderTraversal(T->Left);      // Duyệt cây con bên trái
        PrintElement(T->Element);       // Xử lý nút gốc (in ra)
        InOrderTraversal(T->Right);     // Duyệt cây con bên phải
    }
}

void PreOrderTraversal(BinaryTree T)
{
    if (T != NULL)
    {
        PrintElement(T->Element);       // Xử lý nút gốc (in ra)
        PreOrderTraversal(T->Left);     // Duyệt cây con bên trái
        PreOrderTraversal(T->Right);    // Duyệt cây con bên phải
    }
}

void PostOrderTraversal(BinaryTree T)
{
    if (T != NULL)
    {
        PostOrderTraversal(T->Left);     // Duyệt cây con bên trái
        PostOrderTraversal(T->Right);    // Duyệt cây con bên phải
        PrintElement(T->Element);        // Xử lý nút gốc (in ra)
    }
}

void DestroyTree(BinaryTree T)
{
    if (T != NULL)
    {
        DestroyTree(T->Left);   // Giải phóng cây con bên trái
        DestroyTree(T->Right);  // Giải phóng cây con bên phải
        free(T);                // Giải phóng chính nút đó
    }
}

// ====================================================================
// Định nghĩa các hàm hỗ trợ
// ====================================================================

void InputElement(ElementType *X)
{
    printf("Enter element value: ");
    scanf("%d", X);
}

void InputTree(BinaryTree *T)
{
    int n;
    ElementType X;
    printf("Enter number of elements to insert: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        InputElement(&X);
        *T = Insert(X, *T); // Gọi hàm Insert để thêm vào cây. Cần gán lại *T vì gốc có thể thay đổi
    }
}

void PrintElement(ElementType X)
{
    printf("%d ", X); // In mỗi phần tử, cách nhau bằng dấu cách
}

void PrintTreeStructure(BinaryTree T, int level)
{
    if (T != NULL)
    {
        PrintTreeStructure(T->Right, level + 1); // Duyệt cây con phải (in từ phải sang trái để hiển thị trực quan)
        for (int i = 0; i < level; i++)
        {
            printf("    "); // Thụt lề dựa trên cấp độ
        }
        printf("%d\n", T->Element); // In giá trị nút hiện tại
        PrintTreeStructure(T->Left, level + 1);  // Duyệt cây con trái
    }
}