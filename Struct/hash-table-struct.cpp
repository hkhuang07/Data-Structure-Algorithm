#include <stdio.h>
#include <stdlib.h> // For malloc, free, exit

// Định nghĩa kích thước mặc định cho bảng băm
#define DEFAULT_TABLE_SIZE 10

// Định nghĩa kiểu dữ liệu cho phần tử (cũng là khóa)
typedef int ElementType;

// Cấu trúc một Node trong danh sách liên kết của mỗi bucket
struct Node
{
    ElementType Key; // Khóa của phần tử
    // Có thể thêm ElementType Value; nếu giá trị khác với khóa
    struct Node *Next; // Con trỏ tới Node tiếp theo trong danh sách
};

// Định nghĩa con trỏ tới Node
typedef struct Node *PtrToNode;
typedef PtrToNode List; // Mỗi bucket là một danh sách liên kết

// Cấu trúc Bảng Băm
typedef struct
{
    List *TheLists; // Mảng các con trỏ đến danh sách liên kết (mỗi phần tử là một bucket)
    int TableSize;  // Kích thước của mảng bảng băm
} HashTable;

// ====================================================================
// KHAI BÁO CÁC HÀM CƠ BẢN CỦA HASH TABLE
// ====================================================================

// Hàm băm: chuyển khóa thành chỉ số trong mảng
int Hash(ElementType Key, int TableSize);

// Khởi tạo một Bảng Băm rỗng với kích thước cho trước
HashTable CreateHashTable(int TableSize);

// Chèn một phần tử (khóa) vào Bảng Băm
void InsertHash(ElementType Key, HashTable H);

// Tìm kiếm một phần tử (khóa) trong Bảng Băm
PtrToNode FindHash(ElementType Key, HashTable H);

// Xóa một phần tử (khóa) khỏi Bảng Băm
void DeleteHash(ElementType Key, HashTable H);

// Giải phóng tất cả bộ nhớ được cấp phát cho Bảng Băm
void DestroyHashTable(HashTable H);

// ====================================================================
// CÁC HÀM HỖ TRỢ CHO VIỆC NHẬP/XUẤT
// ====================================================================

// Nhập giá trị cho một phần tử
void InputElement(ElementType *X);

// Nhập nhiều phần tử vào Bảng Băm (tương tác)
void InputHashTable(HashTable H);

// In ra toàn bộ nội dung của Bảng Băm
void PrintHashTable(HashTable H);

// ====================================================================
// HÀM MAIN VÀ TRIỂN KHAI CÁC HÀM
// ====================================================================

int main()
{
    HashTable MyHashTable;
    int customSize;

    printf("========= HASH TABLE PROGRAM =========\n");
    printf("Enter desired hash table size (e.g., %d): ", DEFAULT_TABLE_SIZE);
    scanf("%d", &customSize);
    if (customSize <= 0) {
        printf("Invalid size. Using default size %d.\n", DEFAULT_TABLE_SIZE);
        customSize = DEFAULT_TABLE_SIZE;
    }
    // Clear input buffer after scanf
    while (getchar() != '\n');

    MyHashTable = CreateHashTable(customSize); // Khởi tạo bảng băm

    printf("\n========= INSERT ELEMENTS =========\n");
    InputHashTable(MyHashTable); // Nhập các phần tử vào bảng băm

    printf("\n========= HASH TABLE CONTENTS =========\n");
    PrintHashTable(MyHashTable); // In nội dung bảng băm

    printf("\n========= SEARCH OPERATIONS =========\n");
    ElementType searchKey;
    printf("Enter key to search: ");
    scanf("%d", &searchKey);
    PtrToNode foundNode = FindHash(searchKey, MyHashTable);
    if (foundNode != NULL)
    {
        printf("Key %d found in the hash table.\n", searchKey);
    }
    else
    {
        printf("Key %d not found in the hash table.\n", searchKey);
    }

    printf("\n========= DELETE OPERATIONS =========\n");
    ElementType deleteKey;
    printf("Enter key to delete: ");
    scanf("%d", &deleteKey);
    DeleteHash(deleteKey, MyHashTable);
    printf("After deleting %d:\n", deleteKey);
    PrintHashTable(MyHashTable);

    // Xóa thêm một phần tử khác
    printf("Enter another key to delete: ");
    scanf("%d", &deleteKey);
    DeleteHash(deleteKey, MyHashTable);
    printf("After deleting %d:\n", deleteKey);
    PrintHashTable(MyHashTable);
    
    // Giải phóng bộ nhớ của Bảng Băm khi kết thúc chương trình
    printf("\n========= FREEING HASH TABLE MEMORY =========\n");
    DestroyHashTable(MyHashTable);
    printf("Hash table memory freed.\n");

    return 0;
}

// ====================================================================
// Định nghĩa các hàm cơ bản của Hash Table
// ====================================================================

// Hàm băm đơn giản cho số nguyên
int Hash(ElementType Key, int TableSize)
{
    return Key % TableSize; // Sử dụng phép chia lấy dư
}

// Khởi tạo Bảng Băm
HashTable CreateHashTable(int TableSize)
{
    HashTable H;
    H.TableSize = TableSize;

    // Cấp phát mảng chứa các con trỏ đến danh sách liên kết (các bucket)
    H.TheLists = (List *)malloc(sizeof(List) * H.TableSize);
    if (H.TheLists == NULL)
    {
        fprintf(stderr, "Memory allocation failed for hash table lists array!\n");
        exit(EXIT_FAILURE);
    }

    // Khởi tạo mỗi danh sách trong bucket bằng cách tạo một node header giả
    for (int i = 0; i < H.TableSize; i++)
    {
        H.TheLists[i] = (List)malloc(sizeof(struct Node)); // Tạo node header giả
        if (H.TheLists[i] == NULL)
        {
            fprintf(stderr, "Memory allocation failed for list header %d in hash table!\n", i);
            exit(EXIT_FAILURE); // Thoát nếu không thể cấp phát
        }
        H.TheLists[i]->Next = NULL; // Node header trỏ NULL khi danh sách rỗng
    }
    return H;
}

// Chèn một phần tử (khóa) vào Bảng Băm
void InsertHash(ElementType Key, HashTable H)
{
    PtrToNode NewNode;
    List L;
    int index = Hash(Key, H.TableSize);

    // Lấy danh sách tại bucket tương ứng (node header giả)
    L = H.TheLists[index];

    // Có thể kiểm tra trùng lặp ở đây nếu không muốn khóa trùng
    // PtrToNode found = FindHash(Key, H);
    // if (found != NULL) {
    //     printf("Key %d already exists. Not inserting duplicate.\n", Key);
    //     return;
    // }

    NewNode = (PtrToNode)malloc(sizeof(struct Node));
    if (NewNode == NULL)
    {
        fprintf(stderr, "Memory allocation failed for new node in hash table!\n");
        exit(EXIT_FAILURE);
    }
    NewNode->Key = Key;

    // Chèn node mới vào đầu danh sách (sau node header giả)
    NewNode->Next = L->Next;
    L->Next = NewNode;
}

// Tìm kiếm một phần tử (khóa) trong Bảng Băm
PtrToNode FindHash(ElementType Key, HashTable H)
{
    PtrToNode Current;
    int index = Hash(Key, H.TableSize);

    // Bắt đầu tìm kiếm từ node thực sự đầu tiên của danh sách
    Current = H.TheLists[index]->Next;
    while (Current != NULL && Current->Key != Key)
    {
        Current = Current->Next;
    }
    return Current; // Trả về NULL nếu không tìm thấy, hoặc con trỏ tới node nếu tìm thấy
}

// Xóa một phần tử (khóa) khỏi Bảng Băm
void DeleteHash(ElementType Key, HashTable H)
{
    PtrToNode Current, Previous;
    int index = Hash(Key, H.TableSize);

    Previous = H.TheLists[index]; // Previous bắt đầu từ node header giả
    Current = Previous->Next;     // Current bắt đầu từ node thực sự đầu tiên

    // Duyệt qua danh sách để tìm Key
    while (Current != NULL && Current->Key != Key)
    {
        Previous = Current;
        Current = Current->Next;
    }

    if (Current != NULL) // Nếu tìm thấy Key
    {
        Previous->Next = Current->Next; // Bỏ qua node Current trong danh sách
        free(Current);                  // Giải phóng bộ nhớ của node đã xóa
        printf("Key %d deleted successfully.\n", Key);
    }
    else
    {
        printf("Key %d not found for deletion.\n", Key);
    }
}

// Giải phóng tất cả bộ nhớ được cấp phát cho Bảng Băm
void DestroyHashTable(HashTable H)
{
    for (int i = 0; i < H.TableSize; i++)
    {
        List L = H.TheLists[i];
        PtrToNode Current = L; // Bắt đầu từ node header giả của mỗi danh sách
        PtrToNode Temp;
        while (Current != NULL)
        {
            Temp = Current;
            Current = Current->Next;
            free(Temp); // Giải phóng từng node
        }
    }
    free(H.TheLists); // Giải phóng mảng chứa các con trỏ đến danh sách
}

// ====================================================================
// Định nghĩa các hàm hỗ trợ
// ====================================================================

void InputElement(ElementType *X)
{
    printf("Enter element value: ");
    scanf("%d", X);
}

void InputHashTable(HashTable H)
{
    int n;
    ElementType X;
    printf("Enter number of elements to insert: ");
    scanf("%d", &n);
    // Clear input buffer after scanf
    while (getchar() != '\n'); 

    for (int i = 0; i < n; i++)
    {
        InputElement(&X);
        InsertHash(X, H); // Gọi hàm InsertHash để thêm vào bảng băm
    }
}

void PrintHashTable(HashTable H)
{
    printf("--- Hash Table Contents ---\n");
    for (int i = 0; i < H.TableSize; i++)
    {
        printf("Bucket %d:", i);
        // Bắt đầu in từ node thực sự đầu tiên (sau node header giả)
        PtrToNode Current = H.TheLists[i]->Next;
        if (Current == NULL)
        {
            printf(" (empty)\n");
        }
        else
        {
            while (Current != NULL)
            {
                printf(" -> %d", Current->Key);
                Current = Current->Next;
            }
            printf("\n");
        }
    }
    printf("---------------------------\n");
}