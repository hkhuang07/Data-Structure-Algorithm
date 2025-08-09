#include <iostream>
#include <string>
#include <stack>

// Function to check if a string of parentheses is balanced
bool isBalanced(const std::string& str) {
    std::stack<char> s;
    
    // S? d?ng vòng l?p for truy?n th?ng v?i ch? s?
    for (size_t i = 0; i < str.length(); ++i) {
        char c = str[i];
        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (s.empty()) {
                return false; // Closing bracket without a matching opening bracket
            }
            char topChar = s.top();
            s.pop();

            if ((c == ')' && topChar != '(') ||
                (c == '}' && topChar != '{') ||
                (c == ']' && topChar != '[')) {
                return false; // Mismatched brackets
            }
        }
    }
    return s.empty(); // Stack must be empty for a balanced string
}

// Main function to test the isBalanced function
int main() {
    std::string testString1 = "({[]})";
    std::string testString2 = "({[}])";
    std::string testString3 = "({[)}";
    std::string testString4 = "([])";

    std::cout << "Checking string: " << testString1 << std::endl;
    if (isBalanced(testString1)) {
        std::cout << "The string is balanced." << std::endl;
    } else {
        std::cout << "The string is not balanced." << std::endl;
    }
    std::cout << "---" << std::endl;

    std::cout << "Checking string: " << testString2 << std::endl;
    if (isBalanced(testString2)) {
        std::cout << "The string is balanced." << std::endl;
    } else {
        std::cout << "The string is not balanced." << std::endl;
    }
    std::cout << "---" << std::endl;

    std::cout << "Checking string: " << testString3 << std::endl;
    if (isBalanced(testString3)) {
        std::cout << "The string is balanced." << std::endl;
    } else {
        std::cout << "The string is not balanced." << std::endl;
    }
    std::cout << "---" << std::endl;

    std::cout << "Checking string: " << testString4 << std::endl;
    if (isBalanced(testString4)) {
        std::cout << "The string is balanced." << std::endl;
    } else {
        std::cout << "The string is not balanced." << std::endl;
    }
    std::cout << "---" << std::endl;

    return 0;
}
