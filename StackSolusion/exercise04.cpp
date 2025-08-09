/*
    Nhập vào 1 chuỗi biểu thức, kiểm tra xem biểu thức có dấu ngoặc đúng hay không? nếu sai hãy cho biết vị trí đầu tiên phát hiện dấu ngoặc sai
    Theo bạn thì sử dụng Stack hay Queue sẽ phù hợp với bài toán này? Viết chương trình minh họa và các hàm cho bài toán.
 */
#include <stdio.h>
#include <stdlib.h> // Để sử dụng malloc, free, exit
#include <string.h> // Để sử dụng strlen, strcspn

/*
    Stack (Last In, First Out - LIFO): Khi bạn gặp một dấu ngoặc mở (như (, [, {), bạn "đẩy" (push) nó vào Stack. Khi bạn gặp một dấu ngoặc đóng (như ), ], }), bạn cần kiểm tra xem nó có khớp với dấu ngoặc mở GẦN NHẤT đã được mở trước đó hay không. Khái niệm "GẦN NHẤT" này hoàn toàn phù hợp với nguyên tắc LIFO của Stack: dấu ngoặc mở được đẩy vào cuối cùng sẽ là dấu ngoặc được lấy ra đầu tiên để so khớp.

    Queue (First In, First Out - FIFO): Nếu bạn sử dụng Queue, khi gặp dấu ngoặc đóng, bạn sẽ lấy ra dấu ngoặc mở được thêm vào ĐẦU TIÊN, chứ không phải dấu gần nhất. Điều này sẽ không giúp kiểm tra tính đúng đắn của cấu trúc dấu ngoặc lồng nhau (ví dụ: ([{}]) sẽ đúng, nhưng ({[)]} sẽ sai).
*/
// Định nghĩa kiểu dữ liệu cho phần tử Stack (ở đây là ký tự dấu ngoặc)
typedef char ElementType;

// Cấu trúc một nút trong Stack
struct Node
{
    ElementType Element;
    struct Node *Next;
};

// Định nghĩa con trỏ đến nút và Stack (sử dụng nút header giả)
typedef struct Node *PtrToNode;
typedef PtrToNode Stack; // Stack là một con trỏ đến nút header

// ======================================
// Khai báo các hàm xử lý Stack
// ======================================

// Khởi tạo một Stack rỗng
void MakeEmptyStack(Stack *S);

// Thêm một phần tử vào đỉnh Stack
void Push(ElementType X, Stack S);

// Kiểm tra xem Stack có rỗng hay không
int IsEmptyStack(Stack S);

// Lấy và xóa phần tử trên đỉnh Stack
// (Giả định hàm này chỉ được gọi khi Stack không rỗng)
ElementType Pop(Stack S);

// Lấy giá trị phần tử trên đỉnh Stack mà không xóa
// (Giả định hàm này chỉ được gọi khi Stack không rỗng)
ElementType Top(Stack S);

// ======================================
// Khai báo các hàm hỗ trợ
// ======================================

// Kiểm tra xem ký tự có phải là dấu ngoặc mở không
int isOpeningBracket(char c);

// Kiểm tra xem ký tự có phải là dấu ngoặc đóng không
int isClosingBracket(char c);

// Kiểm tra xem cặp dấu ngoặc mở và đóng có khớp nhau không
int doBracketsMatch(char open, char close);

// Hàm chính để kiểm tra tính đúng đắn của dấu ngoặc trong biểu thức
// Trả về 0 nếu cân bằng, 1 nếu lỗi dấu ngoặc đóng không khớp/thừa, 2 nếu thiếu dấu ngoặc đóng
int checkParentheses(const char *expression, int *errorPosition);

// ======================================
// Hàm chính của chương trình (main)
// ======================================
int main()
{
    char expression[256]; // Giả định độ dài biểu thức tối đa 255 ký tự
    int errorPos = -1;    // Biến lưu vị trí lỗi đầu tiên (nếu có)

    printf("Kiem tra dau ngoac trong bieu thuc\n");
    printf("----------------------------------\n");
    printf("Nhap vao bieu thuc: ");
    fgets(expression, sizeof(expression), stdin); // Đọc toàn bộ dòng nhập, bao gồm ký tự xuống dòng

    // Loại bỏ ký tự xuống dòng ('\n') cuối chuỗi nếu có (do fgets thêm vào)
    expression[strcspn(expression, "\n")] = 0;

    printf("\nPhan tich bieu thuc: \"%s\"\n", expression);

    // Gọi hàm kiểm tra dấu ngoặc
    int result = checkParentheses(expression, &errorPos);

    if (result == 0)
    {
        printf("Bieu thuc co cac dau ngoac dung.\n");
    }
    else if (result == 1)
    {
        printf("LOI: Ngoac dong khong khop hoac thua tai vi tri %d (ky tu '%c').\n", errorPos, expression[errorPos]);
    }
    else if (result == 2)
    {
        printf("LOI: Thieu ngoac dong cho cac ngoac mo.\n");
    }
    else
    {
        printf("Loi khong xac dinh.\n");
    }

    printf("\n<=====================================>\n");

    return 0;
}

// ======================================
// Định nghĩa các hàm xử lý Stack
// ======================================

void MakeEmptyStack(Stack *S)
{
    *S = (Stack)malloc(sizeof(struct Node));
    if (*S == NULL)
    {
        // Xử lý lỗi cấp phát bộ nhớ
        fprintf(stderr, "Loi cap phat bo nho cho Stack header!");
        exit(EXIT_FAILURE); // Thoát chương trình nếu lỗi nghiêm trọng
    }
    (*S)->Next = NULL; // Nút header trỏ NULL, báo hiệu Stack rỗng
}

void Push(ElementType X, Stack S)
{
    PtrToNode TmpCell;
    TmpCell = (PtrToNode)malloc(sizeof(struct Node));
    if (TmpCell == NULL)
    {
        // Xử lý lỗi cấp phát bộ nhớ
        fprintf(stderr, "Loi cap phat bo nho cho nut moi trong Stack!");
        exit(EXIT_FAILURE); // Thoát chương trình nếu lỗi nghiêm trọng
    }
    TmpCell->Element = X;
    TmpCell->Next = S->Next; // Nút mới trỏ tới nút đang ở đỉnh Stack
    S->Next = TmpCell;       // Nút header trỏ tới nút mới, làm nút mới thành đỉnh Stack
}

int IsEmptyStack(Stack S)
{
    return S->Next == NULL;
}

ElementType Pop(Stack S)
{
    // Hàm này giả định IsEmptyStack đã được kiểm tra trước khi gọi
    if (IsEmptyStack(S))
    {
        fprintf(stderr, "Loi: Goi Pop tren Stack rong!\n");
        exit(EXIT_FAILURE); // Lỗi nghiêm trọng, thoát
    }
    PtrToNode TmpCell = S->Next;        // TmpCell trỏ tới nút hiện tại ở đỉnh Stack
    ElementType PoppedElement = TmpCell->Element; // Lấy giá trị của phần tử
    S->Next = TmpCell->Next;            // Nút header trỏ tới nút tiếp theo (dưới TmpCell)
    free(TmpCell);                      // Giải phóng bộ nhớ của nút đã được Pop
    return PoppedElement;
}

ElementType Top(Stack S)
{
    // Hàm này giả định IsEmptyStack đã được kiểm tra trước khi gọi
    if (IsEmptyStack(S))
    {
        fprintf(stderr, "Loi: Goi Top tren Stack rong!\n");
        exit(EXIT_FAILURE); // Lỗi nghiêm trọng, thoát
    }
    return S->Next->Element; // Trả về giá trị của phần tử trên đỉnh Stack
}

// ======================================
// Định nghĩa các hàm hỗ trợ
// ======================================

int isOpeningBracket(char c)
{
    return (c == '(' || c == '[' || c == '{');
}

int isClosingBracket(char c)
{
    return (c == ')' || c == ']' || c == '}');
}

int doBracketsMatch(char open, char close)
{
    return ((open == '(' && close == ')') ||
            (open == '[' && close == ']') ||
            (open == '{' && close == '}'));
}

// ======================================
// Định nghĩa hàm chính kiểm tra dấu ngoặc
// ======================================

// Trả về:
// 0: Biểu thức có dấu ngoặc cân bằng và đúng
// 1: Phát hiện lỗi dấu ngoặc đóng (thừa, không khớp) tại 'errorPosition'
// 2: Biểu thức kết thúc nhưng còn dấu ngoặc mở chưa đóng
int checkParentheses(const char *expression, int *errorPosition)
{
    Stack S;
    MakeEmptyStack(&S); // Khởi tạo một Stack rỗng

    int len = strlen(expression);
    for (int i = 0; i < len; i++)
    {
        char currentChar = expression[i];

        if (isOpeningBracket(currentChar))
        {
            Push(currentChar, S); // Nếu là ngoặc mở, đẩy vào Stack
        }
        else if (isClosingBracket(currentChar))
        {
            if (IsEmptyStack(S))
            {
                // Nếu là ngoặc đóng mà Stack rỗng -> lỗi ngoặc đóng thừa
                *errorPosition = i;
                free(S); // Giải phóng nút header của Stack trước khi thoát
                return 1; // Báo lỗi: ngoặc đóng thừa
            }
            else
            {
                char topChar = Pop(S); // Lấy ký tự ngoặc mở gần nhất từ Stack
                if (!doBracketsMatch(topChar, currentChar))
                {
                    // Nếu không khớp -> lỗi ngoặc đóng không khớp
                    *errorPosition = i;
                    free(S); // Giải phóng nút header của Stack trước khi thoát
                    return 1; // Báo lỗi: ngoặc đóng không khớp
                }
            }
        }
        // Bỏ qua các ký tự khác (chữ số, phép toán, khoảng trắng, v.v.)
    }

    // Sau khi duyệt hết biểu thức
    if (IsEmptyStack(S))
    {
        // Nếu Stack rỗng -> tất cả các dấu ngoặc đều đã được khớp
        free(S); // Giải phóng nút header của Stack
        return 0; // Thành công
    }
    else
    {
        // Nếu Stack không rỗng -> còn lại các dấu ngoặc mở chưa đóng
        // Cần giải phóng bộ nhớ của các nút còn lại trong Stack
        while (!IsEmptyStack(S))
        {
            Pop(S); // Pop các phần tử còn lại để giải phóng bộ nhớ
        }
        free(S); // Giải phóng nút header của Stack
        return 2; // Báo lỗi: thiếu ngoặc đóng
    }
}