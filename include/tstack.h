// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

#include <cstddef>

template <typename T, int N>
class TStack {
 private:
  T data[N];
  int top_idx;

 public:
  TStack() : top_idx(-1) {}

  bool isEmpty() const {
    return top_idx == -1;
  }

  bool isFull() const {
    return top_idx == N - 1;
  }

  void push(const T& item) {
    if (!isFull()) {
      data[++top_idx] = item;
    }
  }

  T pop() {
    if (!isEmpty()) {
      return data[top_idx--];
    }
    return T();
  }

  T top() const {
    if (!isEmpty()) {
      return data[top_idx];
    }
    return T();
  }

  void clear() {
    top_idx = -1;
  }
};

#endif  // INCLUDE_TSTACK_H_
