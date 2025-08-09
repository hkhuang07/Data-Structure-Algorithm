#include <stdio.h>
#include <stdlib.h> // Để sử dụng malloc và free

// Định nghĩa kiểu dữ liệu cho phần tử
typedef int ElementType;

// Cấu trúc một Node trong Stack
struct Node
{
    ElementType Element;
    struct Node *Next; // Con trỏ tới Node tiếp theo trong ngăn xếp
};

// Định nghĩa các kiểu con trỏ để dễ sử dụng
typedef struct Node *PtrToNode;
typedef PtrToNode Stack; // Stack sẽ là con trỏ tới Node đầu tiên (dummy header)

// ====================================================================
// KHAI BÁO CÁC HÀM CƠ BẢN CỦA STACK
// ====================================================================

// Khởi tạo một Stack rỗng (tạo node header giả)
void MakeEmptyStack(Stack *S);

// Kiểm tra xem Stack có rỗng không
int IsEmptyStack(Stack S);

// Thêm một phần tử vào đỉnh Stack
void Push(ElementType X, Stack S);

// Xóa và trả về phần tử ở đỉnh Stack
ElementType Pop(Stack S);

// Xem phần tử ở đỉnh Stack mà không xóa
ElementType Top(Stack S);

// ====================================================================
// CÁC HÀM HỖ TRỢ CHO VIỆC NHẬP/XUẤT VÀ BÀI TẬP
// ====================================================================

// Nhập giá trị cho một phần tử
void InputElement(ElementType *X);

// Nhập các phần tử vào Stack
void InputStack(Stack S);

// In ra giá trị của một phần tử
void PrintElement(ElementType X);

// In ra toàn bộ Stack
void PrintStack(Stack S);


// ====================================================================
// HÀM MAIN VÀ TRIỂN KHAI CÁC HÀM
// ====================================================================

int main()
{
    Stack S;
    MakeEmptyStack(&S); // Truyền địa chỉ của S để hàm có thể thay đổi S

    printf("=========Input Stack=========\n");
    InputStack(S);
    printf("========Stack Inputed========\n");
    PrintStack(S);

    printf("\n=========Stack Operations=========\n");
    if (!IsEmptyStack(S))
    {
        printf("Top element: %d\n", Top(S));
    }

    if (!IsEmptyStack(S))
    {
        ElementType poppedVal = Pop(S);
        if (poppedVal != -1) // -1 là giá trị lỗi nếu Pop thất bại
            printf("Popped element: %d\n", poppedVal);
    }
    printf("After Pop, Stack: ");
    PrintStack(S);

    Push(99, S);
    printf("After Push 99, Stack: ");
    PrintStack(S);

    // Giải phóng bộ nhớ của Stack khi kết thúc chương trình
    while (!IsEmptyStack(S))
    {
        Pop(S);
    }
    free(S); // Giải phóng node header giả
    S = NULL; // Tránh con trỏ treo

    return 0;
}

// Khởi tạo một Stack rỗng với node header giả
void MakeEmptyStack(Stack *S)
{
    *S = (Stack)malloc(sizeof(struct Node));
    if (*S == NULL)
    {
        printf("Memory allocation failed for Stack header!\n");
        exit(EXIT_FAILURE); // Thoát chương trình nếu không cấp phát được
    }
    (*S)->Next = NULL; // Node header giả sẽ trỏ tới NULL khi Stack rỗng
}

// Kiểm tra xem Stack có rỗng không
int IsEmptyStack(Stack S)
{
    return S->Next == NULL; // Stack rỗng nếu node header trỏ tới NULL
}

// Thêm một phần tử vào đỉnh Stack
void Push(ElementType X, Stack S)
{
    PtrToNode TmpCell;
    TmpCell = (PtrToNode)malloc(sizeof(struct Node));
    if (TmpCell == NULL)
    {
        printf("Memory allocation failed for new node!\n");
        return;
    }
    TmpCell->Element = X;
    TmpCell->Next = S->Next; // Node mới trỏ tới node mà header đang trỏ
    S->Next = TmpCell;       // Header giờ trỏ tới node mới (đỉnh Stack)
}

// Xóa và trả về phần tử ở đỉnh Stack
ElementType Pop(Stack S)
{
    if (IsEmptyStack(S))
    {
        printf("Stack is empty. Cannot pop.\n");
        return -1; // Trả về giá trị đặc biệt để báo lỗi
    }
    PtrToNode TmpCell;
    ElementType PoppedElement;

    TmpCell = S->Next; // TmpCell trỏ tới node đỉnh hiện tại
    S->Next = TmpCell->Next; // Header giờ trỏ tới node tiếp theo (đỉnh mới)
    PoppedElement = TmpCell->Element; // Lấy giá trị của phần tử bị Pop
    free(TmpCell); // Giải phóng bộ nhớ của node đã Pop

    return PoppedElement;
}

// Xem phần tử ở đỉnh Stack mà không xóa
ElementType Top(Stack S)
{
    if (IsEmptyStack(S))
    {
        printf("Stack is empty. No top element.\n");
        return -1; // Trả về giá trị đặc biệt để báo lỗi
    }
    return S->Next->Element; // Trả về giá trị của phần tử đỉnh
}

// Nhập giá trị cho một phần tử
void InputElement(ElementType *X)
{
    printf("Enter element value: ");
    scanf("%d", X);
}

// Nhập các phần tử vào Stack
void InputStack(Stack S)
{
    int n;
    ElementType X;
    printf("Enter stack elements quantity: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) // Lặp n lần để nhập n phần tử
    {
        InputElement(&X);
        Push(X, S); // Gọi hàm Push để thêm vào Stack
    }
}

// In ra giá trị của một phần tử
void PrintElement(ElementType X)
{
    printf("|  %d  |\n", X); // In mỗi phần tử trên một dòng để dễ nhìn dạng Stack
}

// In ra toàn bộ Stack
void PrintStack(Stack S)
{
    if (IsEmptyStack(S))
    {
        printf("Stack is empty.\n");
        return;
    }
    PtrToNode Current = S->Next; // Bắt đầu từ node thực sự đầu tiên (đỉnh Stack)
    printf("------\n");
    while (Current != NULL)
    {
        PrintElement(Current->Element);
        Current = Current->Next;
    }
    printf("------\n");
}

// Hàm tính số Fibonacci thứ k (iterative, hiệu quả hơn đệ quy cho số lớn)
// Dãy Fibonacci thường được định nghĩa: F(1)=1, F(2)=1, F(n) = F(n-1) + F(n-2)
// (Một số định nghĩa khác có thể là F(0)=0, F(1)=1)
// Theo ví dụ của bạn: n=5 thì in ra 1 2 3 5 8, tức là F(1)=1, F(2)=2, F(3)=3, F(4)=5, F(5)=8
// Đây là một biến thể của Fibonacci. Tôi sẽ tính theo định nghĩa phổ biến F(1)=1, F(2)=1 và F(0)=0.
// Dựa trên VD của bạn: n=5 => 1 2 3 5 8 => có vẻ như là 1,1,2,3,5,8... với F(1)=1, F(2)=1.
// Tôi sẽ giả định F(1)=1, F(2)=1 cho phần tính toán này.
long long Fibonacci(int k)
{
    if (k <= 0)
        return 0; // F(0)
    if (k == 1)
        return 1; // F(1)
    if (k == 2)
        return 1; // F(2)

    long long a = 1, b = 1;
    long long next_fib;
    for (int i = 3; i <= k; i++)
    {
        next_fib = a + b;
        a = b;
        b = next_fib;
    }
    return b;
}