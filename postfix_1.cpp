#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cmath>
#include <cctype>

// Function to perform basic arithmetic operations
int applyOperation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) {
                std::cerr << "Error: Division by zero\n";
                exit(EXIT_FAILURE);
            }
            return a / b;
        case '^': return std::pow(a, b);
        default: return 0;
    }
}

// Function to evaluate a space-separated postfix expression
int evaluatePostfix(const std::string& expression) {
    std::stack<int> s;
    std::stringstream ss(expression);
    std::string token;

    while (ss >> token) {
        // If the token is a multi-digit number or single digit operand
        if (isdigit(token[0]) || (token.length() > 1 && token[0] == '-')) {
            s.push(std::stoi(token));
        } 
        // If the token is an operator
        else if (token.length() == 1 && (token[0] == '+' || token[0] == '-' || 
                 token[0] == '*' || token[0] == '/' || token[0] == '^')) {
            
            if (s.size() < 2) {
                std::cerr << "Error: Invalid Postfix Expression\n";
                exit(EXIT_FAILURE);
            }

            int val2 = s.top(); s.pop();
            int val1 = s.top(); s.pop();

            int result = applyOperation(val1, val2, token[0]);
            s.push(result);
        }
    }

    if (s.size() != 1) {
        std::cerr << "Error: Invalid Postfix Expression\n";
        exit(EXIT_FAILURE);
    }

    return s.top();
}

int main() {
    // Example space-separated postfix expressions:
    // "5 3 +" -> 5 + 3 = 8
    // "10 2 8 * + 3 -" -> 10 + (2 * 8) - 3 = 23
    std::string expr = "10 2 8 * + 3 -";

    std::cout << "Postfix Expression: " << expr << std::endl;
    std::cout << "Evaluated Result: " << evaluatePostfix(expr) << std::endl;

    return 0;
}