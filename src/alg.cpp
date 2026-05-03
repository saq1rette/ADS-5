// Copyright 2021 NNTU-CS
#include "../include/alg.h"
#include "../include/tstack.h"

#include <cctype>

#include <stdexcept>
#include <string>

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

std::string infx2pstfx(const std::string& inf) {
  TStack<char, 100> operators;
  std::string result;

  for (size_t i = 0; i < inf.length(); ++i) {
    char c = inf[i];

    if (std::isspace(c)) {
      continue;
    }

    if (std::isdigit(c)) {
      while (i < inf.length() && std::isdigit(inf[i])) {
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
      if (!operators.isEmpty()) {
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

int applyOperator(int a, int b, char op) {
  switch (op) {
    case '+':
      return a + b;
    case '-':
      return a - b;
    case '*':
      return a * b;
    case '/':
      if (b == 0) {
        throw std::runtime_error("Division by zero");
      }
      return a / b;
    default:
      throw std::runtime_error("Unknown operator");
  }
}

int eval(const std::string& post) {
  TStack<int, 100> values;

  for (size_t i = 0; i < post.length(); ++i) {
    char c = post[i];

    if (std::isspace(c)) {
      continue;
    }

    if (std::isdigit(c)) {
      int number = 0;
      while (i < post.length() && std::isdigit(post[i])) {
        number = number * 10 + (post[i] - '0');
        ++i;
      }
      values.push(number);
      --i;
    } else if (isOperator(c)) {
      int b = values.pop();
      int a = values.pop();
      int result = applyOperator(a, b, c);
      values.push(result);
    }
  }

  return values.pop();
}
