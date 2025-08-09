#include <stdio.h>
#include <stdlib.h> // Để sử dụng malloc, free, exit

// Định nghĩa kiểu dữ liệu cho phần tử
typedef int ElementType;

// Cấu trúc một Node trong Queue
struct Node
{
    ElementType Element;
    struct Node *Next; // Con trỏ tới Node tiếp theo
};

// Định nghĩa con trỏ tới Node
typedef struct Node *PtrToNode;

// Cấu trúc Queue sẽ chứa hai con trỏ:
// - Front: Trỏ tới nút header giả (đầu của hàng đợi logic)
// - Rear: Trỏ tới nút cuối cùng trong hàng đợi
typedef struct
{
    PtrToNode Front;
    PtrToNode Rear;
} Queue;

// ====================================================================
// KHAI BÁO CÁC HÀM CƠ BẢN CỦA QUEUE
// ====================================================================

// Khởi tạo một Queue rỗng (tạo node header giả và thiết lập Front, Rear)
void MakeEmptyQueue(Queue *Q);

// Kiểm tra xem Queue có rỗng không
int IsEmptyQueue(Queue Q);

// Thêm một phần tử vào cuối Queue (Enqueue)
void Enqueue(ElementType X, Queue *Q);

// Xóa và trả về phần tử ở đầu Queue (Dequeue)
ElementType Dequeue(Queue *Q);

// Xem phần tử ở đầu Queue mà không xóa
ElementType Front(Queue Q);

// ====================================================================
// CÁC HÀM HỖ TRỢ CHO VIỆC NHẬP/XUẤT
// ====================================================================

// Nhập giá trị cho một phần tử
void InputElement(ElementType *X);

// Nhập các phần tử vào Queue
void InputQueue(Queue *Q); // Cần truyền địa chỉ của Queue để thay đổi Front/Rear

// In ra giá trị của một phần tử
void PrintElement(ElementType X);

// In ra toàn bộ Queue
void PrintQueue(Queue Q);

// ====================================================================
// HÀM MAIN VÀ TRIỂN KHAI CÁC HÀM
// ====================================================================

int main()
{
    Queue Q;
    MakeEmptyQueue(&Q); // Truyền địa chỉ của Q để hàm có thể thay đổi Q.Front và Q.Rear

    printf("=========Input Queue=========\n");
    InputQueue(&Q); // Truyền địa chỉ của Q để hàm thêm phần tử vào đúng Queue
    printf("========Queue Inputed========\n");
    PrintQueue(Q);

    printf("\n=========Queue Operations=========\n");
    if (!IsEmptyQueue(Q))
    {
        printf("Front element: %d\n", Front(Q));
    }

    if (!IsEmptyQueue(Q))
    {
        ElementType dequeuedVal = Dequeue(&Q); // Dequeue cần địa chỉ của Q
        if (dequeuedVal != -1) // -1 là giá trị lỗi nếu Dequeue thất bại
            printf("Dequeued element: %d\n", dequeuedVal);
    }
    printf("After Dequeue, Queue: ");
    PrintQueue(Q);

    Enqueue(99, &Q); // Enqueue cần địa chỉ của Q
    printf("After Enqueue 99, Queue: ");
    PrintQueue(Q);

    // Giải phóng bộ nhớ của Queue khi kết thúc chương trình
    while (!IsEmptyQueue(Q))
    {
        Dequeue(&Q); // Dequeue từng phần tử để giải phóng bộ nhớ
    }
    free(Q.Front); // Giải phóng node header giả
    Q.Front = NULL; // Tránh con trỏ treo
    Q.Rear = NULL;  // Tránh con trỏ treo

    return 0;
}

// ====================================================================
// Định nghĩa các hàm cơ bản của Queue
// ====================================================================

void MakeEmptyQueue(Queue *Q)
{
    Q->Front = (PtrToNode)malloc(sizeof(struct Node));
    if (Q->Front == NULL)
    {
        printf("Memory allocation failed for Queue header!\n");
        exit(EXIT_FAILURE); // Thoát chương trình nếu không cấp phát được
    }
    Q->Front->Next = NULL;
    Q->Rear = Q->Front; // Ban đầu, Front và Rear cùng trỏ tới node header giả
}

int IsEmptyQueue(Queue Q)
{
    return Q.Front->Next == NULL; // Queue rỗng nếu node header không trỏ tới bất kỳ node nào
}

void Enqueue(ElementType X, Queue *Q)
{
    PtrToNode TmpCell;
    TmpCell = (PtrToNode)malloc(sizeof(struct Node));
    if (TmpCell == NULL)
    {
        printf("Memory allocation failed for new node!\n");
        exit(EXIT_FAILURE); // Thoát chương trình nếu lỗi nghiêm trọng
    }
    TmpCell->Element = X;
    TmpCell->Next = NULL; // Node mới luôn là node cuối cùng, nên Next của nó là NULL

    Q->Rear->Next = TmpCell; // Node cuối cùng hiện tại sẽ trỏ tới node mới
    Q->Rear = TmpCell;       // Cập nhật Rear để trỏ tới node mới (node cuối cùng)
}

ElementType Dequeue(Queue *Q)
{
    if (IsEmptyQueue(*Q)) // Sử dụng *Q để truyền Queue struct vào hàm IsEmptyQueue
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Trả về giá trị đặc biệt để báo lỗi
    }
    PtrToNode TmpCell = Q->Front->Next; // TmpCell trỏ tới node đầu tiên thực sự của Queue
    ElementType DequeuedElement = TmpCell->Element;

    Q->Front->Next = TmpCell->Next; // Node header giả sẽ trỏ tới node tiếp theo (đầu Queue mới)

    // Nếu node bị Dequeue là node cuối cùng, thì Queue trở nên rỗng
    // Cần cập nhật Rear để nó cũng trỏ về node header giả
    if (TmpCell == Q->Rear)
    {
        Q->Rear = Q->Front;
    }

    free(TmpCell); // Giải phóng bộ nhớ của node đã Dequeue
    return DequeuedElement;
}

ElementType Front(Queue Q)
{
    if (IsEmptyQueue(Q))
    {
        printf("Queue is empty. No front element.\n");
        return -1; // Trả về giá trị đặc biệt để báo lỗi
    }
    return Q.Front->Next->Element; // Trả về giá trị của phần tử ở đầu Queue
}

// ====================================================================
// Định nghĩa các hàm hỗ trợ cho việc nhập/xuất
// ====================================================================

void InputElement(ElementType *X)
{
    printf("Enter element value: ");
    scanf("%d", X);
}

void InputQueue(Queue *Q)
{
    int n;
    ElementType X;
    printf("Enter queue elements quantity: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        InputElement(&X);
        Enqueue(X, Q); // Gọi hàm Enqueue để thêm vào Queue
    }
}

void PrintElement(ElementType X)
{
    printf("|  %d  |\n", X); // In mỗi phần tử trên một dòng để dễ nhìn dạng Queue
}

void PrintQueue(Queue Q)
{
    if (IsEmptyQueue(Q))
    {
        printf("Queue is empty.\n");
        return;
    }
    PtrToNode Current = Q.Front->Next; // Bắt đầu từ node thực sự đầu tiên của Queue
    printf("------\n");
    while (Current != NULL)
    {
        PrintElement(Current->Element);
        Current = Current->Next;
    }
    printf("------\n");
}