/*
    Xây dựng chuogw trình quản lý lương nhân viên. Thông tin nhân vien bao gồm: mã nhân viên, họ tên, lương cơ bản, hệ số lương, số ngày công, lương. Trong đó lương căn bản = 1.150.000đ
    Yêu cầu:
    -   Sử dụng danh sách liên kết đơn
    -   Viết hàm nhập danh sách n nhân viên
    -   Viết hàm tính lương cho các nhân viên
        Lương = Lương cơ bản * Hệ số lương * ngày công /26
        *Chú ý: cần phải lưu trữ lại lương cho mỗi nhân viên sau khi tính.
    -   Viết hàm xuất bảng lương của các nhân viên
    -   Viết hàm tìm kiếm nhân viên theo họ tên
    -   Viết hàm sao chép danh sách 
    -   Sắp xếp danh sách các nhân viên tăng dần theo lương
    -   Viết hàm liệt kê tất cả các nhân viên có số ngày công >24
    -   Xây dựng hàm main minh họa các yêu cầu trên
*/  

#include <iostream>   // For std::cout, std::cin, std::fixed, std::setprecision
#include <string>     // For std::string
#include <iomanip>    // For std::setw, std::left
#include <limits>     // For std::numeric_limits

#define BASE_SALARY 1150000.0 // Sử dụng .0 để đảm bảo là kiểu double

// 1. Định nghĩa cấu trúc Employee như một class hoặc struct trong C++
struct Employee
{
    std::string iD;
    std::string fullName;
    long baseSalary;
    float salaryCoefficient;
    int workingDays;
    double salary;

    // Constructor để khởi tạo đối tượng Employee
    Employee() : baseSalary(BASE_SALARY), salary(0.0) {} // Giá trị mặc định

    // Hàm in thông tin một Employee (có thể là một phương thức)
    void print() const { // const để đảm bảo không thay đổi dữ liệu
        std::cout << "Employee ID: " << iD << std::endl;
        std::cout << "Employee Full name: " << fullName << std::endl;
        std::cout << "Employee Base Salary: " << baseSalary << std::endl;
        std::cout << "Employee Salary Coefficient: " << std::fixed << std::setprecision(2) << salaryCoefficient << std::endl;
        std::cout << "Employee Working Days: " << workingDays << std::endl;
        std::cout << "Employee Salary: " << std::fixed << std::setprecision(2) << salary << std::endl;
    }
};

// 2. Định nghĩa Node cho danh sách liên kết
struct Node
{
    Employee Element; // Thay ElementType bằng Employee
    Node *Next;

    // Constructor cho Node
    Node(const Employee& emp) : Element(emp), Next(nullptr) {}
};

// 3. Class để quản lý danh sách liên kết
class EmployeeList {
private:
    Node *head; // Con trỏ đến dummy header node

    // Hàm để xóa bộ đệm nhập liệu (thay thế fflush(stdin))
    void clearInputBuffer() {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

public:
    // Constructor của EmployeeList: Khởi tạo danh sách rỗng
    EmployeeList() {
        head = new Node(Employee{}); // Tạo dummy header node với Employee mặc định
        head->Next = nullptr;
    }

    // Destructor của EmployeeList: Giải phóng tất cả bộ nhớ khi đối tượng bị hủy
    ~EmployeeList() {
        clear();
        delete head; // Xóa dummy header node
    }

    // Hàm kiểm tra danh sách rỗng
    bool isEmpty() const {
        return head->Next == nullptr;
    }

    // Hàm chèn phần tử vào cuối danh sách
    void insert(const Employee& emp) {
        Node *current = head;
        while (current->Next != nullptr) {
            current = current->Next;
        }
        current->Next = new Node(emp);
    }

    // Hàm nhập danh sách N nhân viên
    void inputList() {
        int n;
        std::cout << "Enter quantity Employees: ";
        std::cin >> n;
        clearInputBuffer(); // Xóa ký tự xuống dòng sau khi đọc số nguyên

        for (int i = 1; i <= n; ++i) {
            Employee emp;
            std::cout << "Enter employee " << i << ":" << std::endl;
            std::cout << "Enter Employee ID: ";
            std::getline(std::cin, emp.iD); // Đọc chuỗi an toàn

            std::cout << "Enter Employee Full name: ";
            std::getline(std::cin, emp.fullName); // Đọc chuỗi an toàn

            std::cout << "Enter Employee Salary Coefficient: ";
            std::cin >> emp.salaryCoefficient;
            std::cout << "Enter Employee Working Days: ";
            std::cin >> emp.workingDays;
            clearInputBuffer(); // Xóa ký tự xuống dòng sau khi đọc số nguyên

            // baseSalary và salary đã được khởi tạo trong constructor của Employee
            insert(emp);
        }
    }

    // Hàm in toàn bộ danh sách nhân viên dưới dạng bảng
    void printList() const {
        if (isEmpty()) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        std::cout << "======================================================================================================" << std::endl;
        std::cout << std::left << std::setw(10) << "ID" << " | "
                  << std::setw(25) << "Full Name" << " | "
                  << std::setw(12) << "Base Salary" << " | "
                  << std::setw(15) << "Coefficient" << " | "
                  << std::setw(12) << "Working Days" << " |" << std::endl;
        std::cout << "======================================================================================================" << std::endl;

        Node *current = head->Next;
        while (current != nullptr) {
            std::cout << std::left << std::setw(10) << current->Element.iD << " | "
                      << std::setw(25) << current->Element.fullName << " | "
                      << std::setw(12) << current->Element.baseSalary << " | "
                      << std::fixed << std::setprecision(2) << std::setw(15) << current->Element.salaryCoefficient << " | "
                      << std::setw(12) << current->Element.workingDays << " |" << std::endl;
            current = current->Next;
        }
        std::cout << "======================================================================================================" << std::endl;
    }

    // Hàm tính lương cho tất cả nhân viên
    void calculateSalaries() {
        Node *current = head->Next;
        while (current != nullptr) {
            current->Element.salary =
                static_cast<double>(current->Element.baseSalary) *
                current->Element.salaryCoefficient *
                (static_cast<double>(current->Element.workingDays) / 26.0);
            current = current->Next;
        }
    }

    // Hàm in bảng lương
    void printSalaryTable() const {
        if (isEmpty()) {
            std::cout << "Salary table is empty." << std::endl;
            return;
        }

        std::cout << "==========================================================" << std::endl;
        std::cout << std::left << std::setw(10) << "ID" << " | "
                  << std::setw(25) << "Full Name" << " | "
                  << std::setw(15) << "Final Salary" << " |" << std::endl;
        std::cout << "==========================================================" << std::endl;

        Node *current = head->Next;
        while (current != nullptr) {
            std::cout << std::left << std::setw(10) << current->Element.iD << " | "
                      << std::setw(25) << current->Element.fullName << " | "
                      << std::fixed << std::setprecision(2) << std::setw(15) << current->Element.salary << " |" << std::endl;
            current = current->Next;
        }
        std::cout << "==========================================================" << std::endl;
    }

    // Hàm tìm kiếm nhân viên theo họ tên
    void findEmployeesByName() const {
        std::string nameToFind;
        std::cout << "Enter the employee full name you want to find: ";
        clearInputBuffer(); // Xóa bộ đệm nếu cần
        std::getline(std::cin, nameToFind);

        Node *current = head->Next;
        bool found = false;
        while (current != nullptr) {
            // strcasecmp cho so sánh không phân biệt hoa/thường (không phải chuẩn C++)
            // Sử dụng std::string::compare hoặc chuyển về cùng một dạng (lower/upper) rồi so sánh
            // Ở đây dùng so sánh trực tiếp, có phân biệt hoa/thường
            if (current->Element.fullName == nameToFind) {
                current->Element.print(); // Gọi phương thức print của Employee
                std::cout << std::endl;
                found = true;
            }
            current = current->Next;
        }
        if (!found) {
            std::cout << "No employee found with name '" << nameToFind << "'." << std::endl;
        }
    }

    // Hàm sắp xếp danh sách tăng dần theo lương (Selection Sort)
    void sortAscBySalary() {
        if (isEmpty() || head->Next->Next == nullptr) {
            std::cout << "List has 0 or 1 element, no need to sort." << std::endl;
            return;
        }

        Node *P, *Q, *MinNode;
        Employee Tmp; // Sử dụng đối tượng Employee để hoán đổi

        for (P = head->Next; P->Next != nullptr; P = P->Next) {
            MinNode = P;
            for (Q = P->Next; Q != nullptr; Q = Q->Next) {
                if (Q->Element.salary < MinNode->Element.salary) {
                    MinNode = Q;
                }
            }
            // Hoán đổi Element (toàn bộ struct Employee)
            if (MinNode != P) {
                Tmp = P->Element;
                P->Element = MinNode->Element;
                MinNode->Element = Tmp;
            }
        }
    }

    // Hàm liệt kê nhân viên có số ngày công > 24
    void listWorkingDaysGreaterThan24() const {
        Node *current = head->Next;
        bool found = false;
        std::cout << "Employees with working days > 24:" << std::endl;
        while (current != nullptr) {
            if (current->Element.workingDays > 24) {
                current->Element.print();
                std::cout << std::endl;
                found = true;
            }
            current = current->Next;
        }
        if (!found) {
            std::cout << "No employees found with working days greater than 24." << std::endl;
        }
    }

    // Hàm giải phóng bộ nhớ của danh sách
    void clear() {
        Node *current = head->Next;
        while (current != nullptr) {
            Node *next_node = current->Next;
            delete current;
            current = next_node;
        }
        head->Next = nullptr; // Đảm bảo danh sách rỗng sau khi xóa
    }
};

int main()
{
    EmployeeList empList; // Tạo đối tượng danh sách nhân viên
    std::cout << "\n<========== PROGRAM START =========>" << std::endl;

    empList.inputList();
    std::cout << "\nEmployees List (Initial): " << std::endl;
    empList.printList();

    empList.calculateSalaries();
    std::cout << "\nEmployees List (Salaries Updated): " << std::endl;
    empList.printList(); // In lại danh sách với lương đã tính

    std::cout << "\nEmployees Salaries Table: " << std::endl;
    empList.printSalaryTable();

    std::cout << "\nFind Employees by Full Name: " << std::endl;
    empList.findEmployeesByName();

    empList.sortAscBySalary();
    std::cout << "\nEmployees List (Sorted by Salary ASC): " << std::endl;
    empList.printList(); // In lại danh sách đã sắp xếp

    std::cout << "\nEmployees Have Working Days Greater Than 24 days: " << std::endl;
    empList.listWorkingDaysGreaterThan24();

    std::cout << "\n<==================================>" << std::endl;

    // Destructor của EmployeeList sẽ tự động gọi để giải phóng bộ nhớ khi empList ra khỏi scope
    return 0;
}