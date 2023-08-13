#include <iostream>

int main() {
    double num1, num2;
    char operation;
    std::cout << "Enter the first number: ";
    std::cin >> num1;
    std::cout << "Enter an operation (+, -, *, /): ";
    std::cin >> operation;
    std::cout << "Enter the second number: ";
    std::cin >> num2;

    double result;
    if (operation == '+') {
        result = num1 + num2;
    } else if (operation == '-') {
        result = num1 - num2;
    } else if (operation == '*') {
        result = num1 * num2;
    } else if (operation == '/') {
        result = num1 / num2;
    } else {
        std::cout << "Invalid operation" << std::endl;
        return 0;
    }

    std::cout << "The result of " << num1 << " " << operation << " " << num2 << " is " << result << std::endl;
    return 0;
}
