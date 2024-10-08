#include <iostream>
#include <stack>
#include <cctype>
#include <string>
#include <sstream>

using namespace std;

// Function to determine precedence of operators
int precedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    return 0;
}

// Function to perform a mathematical operation
int performOperation(char operation, int operand1, int operand2) {
    switch (operation) {
    case '+': return operand1 + operand2;
    case '-': return operand1 - operand2;
    case '*': return operand1 * operand2;
    case '/':
        if (operand2 == 0) {
            throw invalid_argument("Error: Division by zero.");
        }
        return operand1 / operand2;
    default:
        throw invalid_argument("Invalid operator");
    }
}

// Function to convert an infix expression to postfix
string infixToPostfix(const string& expression) {
    stack<char> operators; // Stack for operators
    stringstream postfix;  // Resulting postfix expression

    for (char c : expression) {
        // If character is a digit, add it to the postfix string
        if (isdigit(c)) {
            postfix << c << ' ';
        }
        // If character is an operator
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            // Pop operators from the stack to the result while they have higher or equal precedence
            while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                postfix << operators.top() << ' ';
                operators.pop();
            }
            operators.push(c);  // Push current operator to stack
        }
        // Ignore spaces or invalid characters
    }

    // Pop all remaining operators from the stack to the result
    while (!operators.empty()) {
        postfix << operators.top() << ' ';
        operators.pop();
    }

    return postfix.str();
}

// Function to evaluate a postfix expression
int evaluatePostfix(const string& expression) {
    stack<int> operands; // Stack for operands
    stringstream stream(expression);
    string token;

    while (stream >> token) {
        if (isdigit(token[0])) {
            // If the token is a number, push it to the operand stack
            operands.push(stoi(token));
        }
        else {
            // If the token is an operator, pop two operands and perform the operation
            if (operands.size() < 2) {
                throw invalid_argument("Invalid expression");
            }
            int operand2 = operands.top(); operands.pop();
            int operand1 = operands.top(); operands.pop();
            int result = performOperation(token[0], operand1, operand2);
            operands.push(result);  // Push the result back to the stack
        }
    }

    // The final result should be the only element in the stack
    if (operands.size() != 1) {
        throw invalid_argument("Invalid postfix expression");
    }

    return operands.top();
}

int main() {
    try {
        string infix;
        cout << "Enter a valid infix expression (e.g., 3+5*2): ";
        getline(cin, infix);

        string postfix = infixToPostfix(infix);
        cout << "Postfix Expression: " << postfix << endl;

        int result = evaluatePostfix(postfix);
        cout << "Result: " << result << endl;

    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
