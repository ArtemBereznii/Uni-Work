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

string infixToPostfix(const string& expression) {
    stack<char> operators;
    stringstream postfix; 
    string number;

    for (size_t i = 0; i < expression.length(); ++i) {
        char c = expression[i];

        if (isdigit(c)) {
            number += c;
        }
        else {
            if (!number.empty()) {
                postfix << number << ' ';
                number.clear();
            }

            if (c == '+' || c == '-' || c == '*' || c == '/') {
                while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                    postfix << operators.top() << ' ';
                    operators.pop();
                }
                operators.push(c);
            }
        }
    }

    if (!number.empty()) {
        postfix << number << ' ';
    }

    while (!operators.empty()) {
        postfix << operators.top() << ' ';
        operators.pop();
    }

    return postfix.str();
}

int evaluatePostfix(const string& expression) {
    stack<int> operands;
    stringstream stream(expression);
    string token;

    while (stream >> token) {
        if (isdigit(token[0])) {
            operands.push(stoi(token));
        }
        else {
            if (operands.size() < 2) {
                throw invalid_argument("Invalid expression");
            }
            int operand2 = operands.top(); operands.pop();
            int operand1 = operands.top(); operands.pop();
            int result = performOperation(token[0], operand1, operand2);
            operands.push(result);
        }
    }

    if (operands.size() != 1) {
        throw invalid_argument("Invalid postfix expression");
    }

    return operands.top();
}

int main() {
    try {
        string infix;
        cout << "Enter a valid infix expression (e.g., 10+15*2): ";
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
