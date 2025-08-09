/*
    #Xây dựng chương trình quản lý mặt hàn, thông tin một mặt hàng gồm: mã hàng, tên hàng, số lượng, thành tiền. Thành tiền = đơn giá * số lượng
    #Yêu cầu
    -   Sử dụng danh sách liên kết đơn
    -   Viết hàm nhập danh sách n mặt hàng
    -   Tính tổng doanh thu = Tổng thành tiền các mặt hàng
    -   Viết hàm xuất danh sách các mặt hàng
    -   Viết hàm tìm kiếm hàng hóa theo mã hàng
    -   Sắp xếp danh sách giảm dần theo tên hàng
    -   Viết hàm liệt kê tất cả các mặt hàng có thành tiền > 100000
    -   Viết hàm liệt kê tất cả các mặt hàng có số lượng <10
    #Xây dựng hàm main nhằm sử dụng các hàm đã cài đặt
*/
#include <stdio.h>
#include <string.h>
struct Product
{
    char iD[10];
    char name[64];
    float price;
    int quantity;
    double totalprice;
};
typedef Product ElementType;

struct Node
{
    ElementType Element;
    Node *Next;
};
typedef Node* PtrToNode;
typedef PtrToNode Position;
typedef PtrToNode List;

void MakeNullList(List &L);
void InsertElement(ElementType X, Position P);
int IsEmptyList(List L);

void InputElement(ElementType &X);
void InputList(List &L);
void PrintElement(ElementType X);
void PrintList(List L);
void FindProductbyID(List L);
void DescendingSortListByName(List L);
void ProductsPriceGtt100000(List L);
void ProductsQuantityLss0(List L);
double Revenue(List L);

int main()
{
    List L; 
    double revenue;
    MakeNullList(L);
    printf("\n<========== PROGRAM START ==========>\n");
    
    InputList(L);
    printf("\nProduct List: \n");
    PrintList(L);

    revenue = Revenue(L);
    printf("\nRevenue of all products : %f \n",revenue);

    printf("\nFind product by ID: \n");
    FindProductbyID(L);

    printf("\nSorted Product List by Name: \n");
    DescendingSortListByName(L);
    PrintList(L);

    printf("\nProducts have Total Price > 1000000 \n");
    ProductsPriceGtt100000(L);

    printf("\nProducts Out of Stock: \n");
    ProductsQuantityLss0(L);

    printf("\n<===================================>\n");
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
    printf("Enter Product ID: "); fflush(stdin); gets(X.iD);
    printf("Enter Product Name: "); fflush(stdin); gets(X.name);
    printf("Enter Product  Price: "); scanf("%f",&X.price);
    printf("Enter Product Quantity: "); scanf("%d",&X.quantity);
    X.totalprice = (double)X.quantity * X.price;
}
void InputList(List &L)
{
    int n; 
    Position P = L; 
    ElementType E;
    printf("Enter quantity Products: "); scanf("%d",&n);

    for(int i=1; i<=n; i++)
    {
        printf("Enter Product %d: \n",i);
        InputElement(E);
        InsertElement(E,P);
        P=P->Next;
    }
}
void PrintElement(ElementType X)
{
    printf("Product ID: %s\n",X.iD);
    printf("Product Name: %s \n",X.name);
    printf("Product Price: %.3f \n",X.price);
    printf("Product Quantity: %d \n",X.quantity);
    printf("Product Total price: %.3f\n",X.totalprice);
}

void PrintList(List L)
{
    Position P = L->Next;
    printf("| %-10s | %-25s | %-15s | %-15s | %-15s |\n","ID","Name","Price","Quantity","Total Price");
    while (P!=NULL)
    {
        printf("| %-10s | %-25s | %-15.3f | %-15d | %-15.3f |\n",
            P->Element.iD,
            P->Element.name,
            P->Element.price,
            P->Element.quantity,
            P->Element.totalprice);
        P=P->Next;
    }
}

void FindProductbyID(List L)
{
    char productID[10];
    printf("Enter product ID which you want to find: "); 
    fflush(stdin); gets(productID);
    Position P = L->Next;
    while(P!=NULL)
    {
        if(strcmp(P->Element.iD,productID)==0)
        {
            PrintElement(P->Element);
            printf("\n");
        }
        P=P->Next;
    }
}
void DescendingSortListByName(List L)
{
    Position P, Q, MaxValue;
    ElementType Tmp;
    for(P=L->Next;P!=NULL;P=P->Next)
    {
        MaxValue = P;
        for(Q=P->Next;Q!=NULL;Q=Q->Next)
        {
            if (strcmp(Q->Element.name, MaxValue->Element.name) > 0)
                MaxValue = Q;
        }
        if(MaxValue != P)
        {
            Tmp = P->Element;
            P->Element = MaxValue->Element;
            MaxValue->Element = Tmp;
        }
    }
}
void ProductsPriceGtt100000(List L)
{
    Position P=L->Next;
    while (P!=NULL)
    {
        if(P->Element.price >100000)
        {
            PrintElement(P->Element);
            printf("\n");
        }
        P=P->Next;
    }
}
void ProductsQuantityLss0(List L)
{
    Position P=L->Next;
    while (P!=NULL)
    {
        if(P->Element.quantity <= 0)
        {
            PrintElement(P->Element);
            printf("\n");
        }
        P=P->Next;

    }
}
double Revenue(List L)
{
    double revenue=0;
    Position P=L->Next;
    while (P != NULL)
    {
        revenue = (double) revenue + P->Element.totalprice;
        P=P->Next;
    }
    return revenue;
}


