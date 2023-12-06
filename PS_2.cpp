#include <iostream>
#include <cstring>

class StringOperations {
private:
    char str[100];

public:
    // Function to input a string
    void inputString() {
        std::cout << "Enter a string: ";
        std::cin.getline(str, sizeof(str));
    }

    // i. Equality
    bool operator==(const StringOperations& other) const {
        return strcmp(str, other.str) == 0;
    }

    // ii. String Copy
    void operator=(const StringOperations& other) {
        strcpy(str, other.str);
    }

    // iii. Concatenation
    StringOperations operator+(const StringOperations& other) const {
        StringOperations result;
        strcpy(result.str, str);
        strcat(result.str, other.str);
        return result;
    }

    // iv. To display a string
    void displayString() const {
        std::cout << "String: " << str << std::endl;
    }

    // v. To reverse a string
    void reverseString() {
        int len = strlen(str);
        for (int i = 0, j = len - 1; i < j; ++i, --j) {
            char temp = str[i];
            str[i] = str[j];
            str[j] = temp;
        }
    }

    // vi. Function to determine whether a string is a palindrome
    bool isPalindrome() const {
        int len = strlen(str);
        for (int i = 0, j = len - 1; i < j; ++i, --j) {
            if (str[i] != str[j]) {
                return false;
            }
        }
        return true;
    }

    // vii. To find the occurrence of a sub-string
    int operator>>(const char* substring) const {
        const char* found = strstr(str, substring);
        if (found != nullptr) {
            return found - str;
        } else {
            return -1; // Substring not found
        }
    }
};

int main() {
    StringOperations str1, str2, result;

    // i. Equality
    str1.inputString();
    str2.inputString();
    if (str1 == str2) {
        std::cout << "Strings are equal.\n";
    } else {
        std::cout << "Strings are not equal.\n";
    }

    // ii. String Copy
    result = str1;
    result.displayString();

    // iii. Concatenation
    result = str1 + str2;
    result.displayString();

    // iv. Display a string
    str1.displayString();

    // v. Reverse a string
    str1.reverseString();
    std::cout << "Reversed string: ";
    str1.displayString();

    // vi. Check if a string is a palindrome
    if (str1.isPalindrome()) {
        std::cout << "The string is a palindrome.\n";
    } else {
        std::cout << "The string is not a palindrome.\n";
    }

    // vii. Find occurrence of a sub-string
    const char* substring = "world";
    int occurrence = str1 >> substring;
    if (occurrence != -1) {
        std::cout << "Substring found at index " << occurrence << ".\n";
    } else {
        std::cout << "Substring not found.\n";
    }

    return 0;
}
