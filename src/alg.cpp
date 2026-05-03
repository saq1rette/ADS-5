// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include <cctype>
#include "tstack.h"

int getPriority(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int applyOperation(int a, int b, char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        default:
            throw std::invalid_argument("Invalid operator");
    }
}

std::string infx2pstfx(const std::string& inf) {
    TStack<char, 100> operators;
    std::string result;

    for (size_t i = 0; i < inf.length(); ++i) {
        char c = inf[i];

        if (isspace(c)) {
            continue;
        }

        if (isdigit(c)) {
            while (i < inf.length() && isdigit(inf[i])) {
                result += inf[i];
                ++i;
            }
            result += ' ';
            --i;
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.isEmpty() && operators.top() != '(') {
                result += operators.pop();
                result += ' ';
            }
            if (!operators.isEmpty() && operators.top() == '(') {
                operators.pop();
            }
        } else if (isOperator(c)) {
            while (!operators.isEmpty() && operators.top() != '(' &&
                   getPriority(operators.top()) >= getPriority(c)) {
                result += operators.pop();
                result += ' ';
            }
            operators.push(c);
        }
    }

    while (!operators.isEmpty()) {
        result += operators.pop();
        result += ' ';
    }

    if (!result.empty() && result.back() == ' ') {
        result.pop_back();
    }

    return result;
}

int eval(const std::string& post) {
    TStack<int, 100> values;

    for (size_t i = 0; i < post.length(); ++i) {
        char c = post[i];

        if (isspace(c)) {
            continue;
        }

        if (isdigit(c)) {
            int number = 0;
            while (i < post.length() && isdigit(post[i])) {
                number = number * 10 + (post[i] - '0');
                ++i;
            }
            values.push(number);
            --i;
        } else if (isOperator(c)) {
            if (values.size() < 2) {
                throw std::runtime_error("Invalid postfix expression");
            }
            int b = values.pop();
            int a = values.pop();
            int result = applyOperation(a, b, c);
            values.push(result);
        } else {
            throw std::invalid_argument("Invalid character in expression");
        }
    }

    if (values.size() != 1) {
        throw std::runtime_error("Invalid postfix expression");
    }

    return values.pop();
}
